// ATANASIO JOSÉ RUBIO GIL - 44599757C

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

const int ESTANQUEROS = 2;
const int FUMADORES = 3;

vector<Semaphore> estanqueros;
vector<Semaphore> ingredientes;

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(int indice ) {
	while (true) {
		sem_wait(estanqueros[indice]);
		
		int ingrediente = aleatorio<0, FUMADORES-1>();

		chrono::milliseconds duracion_producir(aleatorio<10,50>());

		cout << "Estanquero " << indice << " ofrece ingrediente " << ingrediente << endl << flush;

		sem_signal(ingredientes[ingrediente]);
	}
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   while(true) {
		sem_wait(ingredientes[num_fumador]);

		cout << "Fumador " << num_fumador << " recoge su ingrediente" << endl << flush;

		int estanquero = aleatorio<0, ESTANQUEROS-1>();
		sem_signal(estanqueros[estanquero]);

		fumar(num_fumador);
   }
}

//----------------------------------------------------------------------

int main() {
	estanqueros.push_back(1);

	for (int i=1; i<ESTANQUEROS; i++)
		estanqueros.push_back(0);

	for (int i=0; i<FUMADORES; i++)
		ingredientes.push_back(0);

	thread estanqueros[ESTANQUEROS];
	thread fumadores[FUMADORES];

	for (int i=0; i<ESTANQUEROS; i++)
		estanqueros[i] = thread(funcion_hebra_estanquero, i);

	for (int i=0; i<FUMADORES; i++)
		fumadores[i] = thread(funcion_hebra_fumador, i);

	for (int i=0; i<ESTANQUEROS; i++)
		estanqueros[i].join();

	for (int i=0; i<FUMADORES; i++)
		fumadores[i].join();

}
