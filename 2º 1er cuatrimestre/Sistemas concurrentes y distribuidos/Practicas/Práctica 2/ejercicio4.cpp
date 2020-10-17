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

const int MULTIPLICIDAD = 5;
const int PRODUCTOS     = 2;
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


/* TIENDA
 *
 * La tienda es una clase que hereda de HoareMonitor para poder acceder a sus
 * métodos públicos y privados.
 */

class Tienda : public HoareMonitor {
private:
	// Vector para el número de productos disponibles de cada tipo
	int productos[PRODUCTOS];
	// Vector para el número de productos en los pedidos de los clientes
	int pedidos[PRODUCTOS*MULTIPLICIDAD];
	// Vector de colas de clientes
	CondVar clientes[PRODUCTOS*MULTIPLICIDAD];

public:
	Tienda();         // Constructor

	// Recogida de un ingrediente por un fumador
	void Comprar  (int indice, int producto, int cantidad);
	// Coloca el ingrediente en el mostrador
	void Entregar (int producto, int cantidad); 
};


/* CONSTRUCTOR DE LA TIENDA
 *
 * Inicializa todas las colas.
 */

Tienda :: Tienda () {
	for (int i=0; i<PRODUCTOS*MULTIPLICIDAD; i++) {
		pedidos[i]     = 0;
		clientes[i]    = newCondVar();
	}

	for (int i=0; i<PRODUCTOS; i++)
		productos[i] = 0;
}


/* COMPRAR UN PRODUCTO EN LA TIENDA
 *
 * Cada cliente que busca recoger su ingrediente se espera a que el que se
 * ofrece en el estanco sea de su mismo índice. Tras recogerlo, indica al
 * estanquero que puede volver a producir.
 */

void Tienda :: Comprar (int indice, int producto, int cantidad) {
	chrono::milliseconds tiempo_espera(aleatorio<50,100>());

	if (cantidad > productos[producto])
		pedidos[indice] = cantidad;
		clientes[indice].wait();

	mtx.lock();
		productos[producto] -= cantidad;
		std::cout << " :: CLIENTE [" << indice << "] compra producto "
		          << producto << " en " << cantidad << " unidades, "
		          << "quedando " << productos[producto] << std::endl;
	mtx.unlock();

	this_thread::sleep_for(tiempo_espera);
}


/* ENTREGAR EN LA TIENDA
 *
 * Si se está ofreciendo un ingrediente, el estanquero espera a que se retire.
 * Una vez retirado, éste ofrece el ingrediente y llama al fumador
 * correspondiente para que lo recoja.
 */

void Tienda :: Entregar (int producto, int cantidad) {
	chrono::milliseconds tiempo_espera(aleatorio<50,100>());

	mtx.lock();
		productos[producto] += cantidad;
		std::cout << " :: PROVEEDORA entrega producto " << producto
		          << " en " << cantidad << " unidades, dejando un total de "
		          << productos[producto] << std::endl;
	mtx.unlock();

	bool encontrado = false;

	for (int i=producto; i<PRODUCTOS*MULTIPLICIDAD && !encontrado; i+=MULTIPLICIDAD) {
		encontrado = pedidos[i] >= productos[producto];
		
		if (encontrado)
			clientes[i].signal();
	}

	this_thread::sleep_for(tiempo_espera);
}


/* HEBRA DE LAS PROVEEDORAS
 *
 * Cada proveedora entrega en bucle infinito.
 */

void HebraProveedora (MRef<Tienda> tienda, int indice) {
	for (;;) {
		int producto = indice/PRODUCTOS;
		int cantidad = aleatorio<1,8>();
		tienda->Entregar(producto, cantidad);
	}
}


/* HEBRA DE LOS CLIENTES
 *
 * Cada cliente compra en bucle infinito.
 */

void HebraCliente (MRef<Tienda> tienda, int indice) {
	for (;;) {
		int producto = indice % PRODUCTOS;
		int cantidad = aleatorio<3,7>();
		tienda->Comprar(indice, producto, cantidad);
	}
}


/* MAIN
 *
 * Inicializa y finaliza las hebras de las proovedoras y los
 * clientes
 */

int main () {
	// Inicialización del estanco

	MRef<Tienda> tienda = Create<Tienda> ();

	// Declaración de las hebras

	thread proveedoras[PRODUCTOS * MULTIPLICIDAD];
	thread clientes[PRODUCTOS * MULTIPLICIDAD];

	// Inicialización de las hebras

	for (int i=0; i<PRODUCTOS*MULTIPLICIDAD; i++) {
		proveedoras[i] = thread (HebraProveedora, tienda, i);
		clientes[i]    = thread (HebraCliente, tienda, i);
	}

	// Finalización de las hebras

	for (int i=0; i<PRODUCTOS*MULTIPLICIDAD; i++) {
		proveedoras[i].join();
		clientes[i].join();
	}
}

