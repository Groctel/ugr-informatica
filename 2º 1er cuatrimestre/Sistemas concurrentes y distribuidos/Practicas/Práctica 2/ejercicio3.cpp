/* DATOS DEL ESTUDIANTE
 * -> NOMBRE:    Atanasio José
 * -> APELLIDOS: Rubio Gil
 * -> DNI:       44599757C
 */

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

#include "HoareMonitor.h"

using namespace HM;

const int FUMADORES = 3;
int   cuenta_cigarros = 0;
mutex mtx;


/*
* GENERADOR DE NÚMEROS ALEATORIO
*
* Genera un número aleatorio entre min y max.
* Ambos son conocidos en tiempo de compilación.
*/

template <int min, int max> int aleatorio () {
	static default_random_engine generador((random_device())());
	static uniform_int_distribution<int> distribucion_uniforme(min, max);
	return distribucion_uniforme(generador);
}


/* ESTANCO
 *
 * El estanco es una clase que hereda de HoareMonitor para poder acceder a sus
 * métodos públicos y privados.
 */

class Estanco : public HoareMonitor {
private:
	int     ingrediente_ofrecido; // Índice del ingrediente en el mostrador
	CondVar controladora;         // Cola de la hebra controladora
	CondVar estanquero;           // Cola del estanquero
	CondVar fumadores[FUMADORES]; // Vector de colas de fumadores

public:
	Estanco();                       // Constructor

	int  Recoger  (int fumador);     // Recogida de un ingrediente por un fumador
	void Esperar  ();                // Espera a que se recoja el ingrediente
	void Ofrecer  (int ingrediente); // Coloca el ingrediente en el mostrador
	void Resetear ();                // Resetea cuenta_cigarros
};


/* CONSTRUCTOR DEL ESTANCO
 *
 * Inicializa todas las colas.
 */

Estanco :: Estanco () {
	ingrediente_ofrecido = -1;
	controladora = newCondVar();
	estanquero   = newCondVar();

	for (int i=0; i<FUMADORES; i++)
		fumadores[i] = newCondVar();
}


/* RECOGER UN INGREDIENTE DEL ESTANCO
 *
 * Cada cliente que busca recoger su ingrediente se espera a que el que se
 * ofrece en el estanco sea de su mismo índice. Tras recogerlo, indica al
 * estanquero que puede volver a producir.
 */

int Estanco :: Recoger (int indice) {
	int ingrediente;

	if (ingrediente_ofrecido != indice)
		fumadores[indice].wait();

	ingrediente = ingrediente_ofrecido;
	ingrediente_ofrecido = -1;

	std::cout << " :: FUMADOR [" << indice << "] recoge su ingrediente ("
	          << ingrediente << "), la cuenta es " << ++cuenta_cigarros
	          << std::endl;

	if (cuenta_cigarros >= 10)
		controladora.signal();

	estanquero.signal();

	return ingrediente;
}


/* ESPERAR EN EL ESTANCO
 *
 * Si hay un ingrediente en ofrecido en el estanco, el estanquero espera hasta
 * que no lo haya.
 */

void Estanco :: Esperar () {
	if (ingrediente_ofrecido != -1)
		estanquero.wait();
}


/* OFRECER EN EL ESTANCO
 *
 * Si se está ofreciendo un ingrediente, el estanquero espera a que se retire.
 * Una vez retirado, éste ofrece el ingrediente y llama al fumador
 * correspondiente para que lo recoja.
 */

void Estanco :: Ofrecer (int ingrediente) {
	Esperar();

	mtx.lock();
		std::cout << " :: ESTANQUERO ofrece ingrediente [" << ingrediente << "]"
		          << std::endl;
	mtx.unlock();

	ingrediente_ofrecido = ingrediente;
	fumadores[ingrediente].signal();
}


/* RESETEAR EN EL ESTANCO
 *
 * Si se han servido menos de 10 cigarros, se espera. Cuando se han servido, recibe
 * una señal del fumador que lo ha hecho y, de forma atómica,  imprime un mensaje
 * indicando este hecho y resetea el número de cigarros servidos a 0.
 */

void Estanco :: Resetear () {
	if (cuenta_cigarros < 10) {
		controladora.wait();
	}

	mtx.lock();
		std::cout << "\nSe han servido, al menos, 10 ingredientes\n"
		          << std::endl;
		cuenta_cigarros = 0;
	mtx.unlock();
}


/* PRODUCIR INGREDIENTE
 *
 * Produce un ingrediente aleatorio basado en el número de fumadores.
 */

int producirIngrediente () {
	return aleatorio<0,FUMADORES-1>();
}


/* FUMAR (FUMADORES)
 *
 * Cuando un fumador ha obtenido su ingrediente, se retira a fumarlo durante un
 * número aleatorio de milisegundos. Se informa, de forma atómica, tanto de que
 * el fumador comienza a fumar como que termina de hacerlo.
 */

void fumar (int indice) {
	chrono::milliseconds tiempo_fumar(aleatorio<20,200>());

	 mtx.lock();
	 	std::cout << " :: FUMADOR [" << indice << "] comienza a fumar ("
		          << tiempo_fumar.count() << "ms)" << std::endl;
	 mtx.unlock();

	this_thread::sleep_for(tiempo_fumar);

	 mtx.lock();
	 	std::cout << " :: FUMADOR [" << indice << "] termina de fumar"
		          << std::endl;
	 mtx.unlock();
}


/* HEBRA CONTROLADORA
 *
 * La hebra controladora llama infinitamente a la función resetear del estanco
 */

void HebraControladora (MRef<Estanco> estanco) {
	for (;;) {
		estanco->Resetear();
	}
}


/* HEBRA DEL ESTANQUERO
 *
 * El estanquero realiza tres acciones en bucle infinitamente:
 * -> Recoger un ingrediente
 * -> Colocar el ingrediente producido en el mostrador
 * -> Esperar a que el fumador correspondiente tome su ingrediente
 */

void HebraEstanquero (MRef<Estanco> estanco) {
	for (;;) {
		int ingrediente = producirIngrediente();

		estanco->Ofrecer(ingrediente);
		estanco->Esperar();
	}
}


/* HEBRA DE LOS FUMADORES
 *
 * Cada fumador realiza dos acciones en bucle infinitamente:
 * -> Coger un ingediente del mostrador
 * -> Fumarse el cigarro completo con el ingrediente
 */

void  HebraFumador( MRef<Estanco> estanco, int indice) {
	for (;;) {
		estanco->Recoger(indice);
		fumar(indice);
	}
}


/* MAIN
 *
 * Inicializa y finaliza las hebras del estanquero y de los fumadores
 */

int main () {
	// Inicialización del estanco

	MRef<Estanco> estanco = Create<Estanco> ();

	// Declaración de las hebras

	thread controladora;
	thread estanquero;
	thread fumadores[FUMADORES];

	// Inicialización de las hebras

	controladora = thread (HebraControladora, estanco);
	estanquero   = thread (HebraEstanquero, estanco);

	for (int i=0; i<FUMADORES; i++)
		fumadores[i] = thread (HebraFumador, estanco, i);

	// Finalización de las hebras

	estanquero.join();

	for (int i=0; i<FUMADORES; i++)
		fumadores[i].join();

}

