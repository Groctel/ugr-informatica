// Atanasio José Rubio Gil
// 44599757C
// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 4. Implementación de sistemas de tiempo real.
//
// Archivo: ejecutivo1-compr.cpp
// Implementación del primer ejercicio de ejecutivo cíclico:
//
//   Datos de las tareas:
//   ------------
//   Ta.  T    C
//   ------------
//   A  250  100
//   B  250   80
//   C  500   50
//   D  500   40
//   E 1000   20
//  -------------
//
//  Planificación (con Ts == 250 ms)
//  *---------*----------*---------*--------*
//  | A B C   | A B D E  | A B C   | A B D  |
//  *---------*----------*---------*--------*
//
//
// Historial:
// Creado en Diciembre de 2017
// -----------------------------------------------------------------------------

#include <string>
#include <cstdio>
#include <thread>
#include <chrono>
#include <ratio>

typedef std::chrono::duration<float,std::ratio<1,1> >    seconds_f ;
typedef std::chrono::duration<float,std::ratio<1,1000> > milliseconds_f ;

void Tarea (const std::string & nombre, std::chrono::milliseconds tcomputo) {
	printf("Ejecutivo %s inicia tarea [%ldms]...\n",
	       nombre.c_str(), tcomputo.count());

	std::this_thread::sleep_for(tcomputo);

	printf("Ejecutivo %s finaliza tarea.\n",
	       nombre.c_str());
}

void TareaA () {
	Tarea("A", std::chrono::milliseconds(100));
}

void TareaB () {
	Tarea("B", std::chrono::milliseconds(80));
}

void TareaC () {
	Tarea("C", std::chrono::milliseconds(50));
}

void TareaD () {
	Tarea("D", std::chrono::milliseconds(40));
}

void TareaE () {
	Tarea("E", std::chrono::milliseconds(20));
}

int main (int argc, char** argv) {
	const std::chrono::milliseconds Ts(250);

	int tiempo;

	std::chrono::time_point<std::chrono::steady_clock> ini_sec = std::chrono::steady_clock::now();
	std::chrono::time_point<std::chrono::steady_clock> inicio ;
	std::chrono::time_point<std::chrono::steady_clock> fin ;

	while (true) {
		printf(":: %s\n", "VUELTA DEL BUCLE PRINCIPAL");

		for (int i=1; i<=4; i++) {
			inicio = std::chrono::steady_clock::now();

			printf("-> Iteración %d del bucle secundario\n", i);

			switch (i) {
				case 1 :
					TareaA(); TareaB(); TareaC();
				break ;

				case 2 :
					TareaA(); TareaB(); TareaD(); TareaE();
				break ;

				case 3 :
					TareaA(); TareaB(); TareaC();
				break ;

				case 4 :
					TareaA(); TareaB(); TareaD();
				break ;
			}

			fin = std::chrono::steady_clock::now();
			std::chrono::steady_clock::duration duracion = fin - inicio;

			switch (i) {
				case 1 :
					tiempo = 230;
				break;

				case 2 :
					tiempo = 240;
				break;

				case 3 :
					tiempo = 230;
				break;

				case 4 :
					tiempo = 220;
				break;
			}

			printf("> Retraso total: %fms.\n",
			       milliseconds_f(duracion).count() - tiempo);

			if (milliseconds_f(duracion).count() - tiempo > 20) {
				printf("%s\n", "Retraso mayor del permitido (20ms). Abortando...");
				exit(1);
			}

			ini_sec += Ts ;
			std::this_thread::sleep_until( ini_sec );
		}
	}
}
