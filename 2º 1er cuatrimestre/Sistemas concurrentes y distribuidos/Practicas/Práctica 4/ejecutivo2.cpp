// Atanasio José Rubio Gil
// 44599757C
// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 4. Implementación de sistemas de tiempo real.
//
// Archivo: ejecutivo2.cpp
// Implementación del segundo ejercicio de ejecutivo cíclico:
//
//   Datos de las tareas:
//   ------------
//   Ta.    T           C
//   ------------
//   A      500     100
//   B      500     150
//   C      1000   200
//   D      2000  240
//  -------------
//
//  Planificación (con Ts == 500 ms)
//  *---------*----------*---------*--------*
//  | A B  D | A B C  | A B C   | A B   |
//  *---------*----------*---------*--------*
//
//
// Historial:
// Creado en Diciembre de 2017
//
//¿Cual es el mínimo tiempo de espera que queda al final de las
//iteraciones del ciclo secundario con tu solución?
//  El minimo tiempo de espera es de 10ms.
//
//¿Sería planificable si la tarea D tuviese un tiempo cómputo de
// 250 ms ?
// Si, con Ts == 500ms si.
// -----------------------------------------------------------------------------

#include <string>
#include <cstdio>
#include <thread>
#include <chrono>
#include <ratio>

typedef std::chrono::duration<float, std::ratio<1,1> > seconds_f;
typedef std::chrono::duration<float, std::ratio<1,1000> > milliseconds_f;

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
	Tarea("B", std::chrono::milliseconds(150));
}

void TareaC () {
	Tarea("C", std::chrono::milliseconds(200));
}

void TareaD () {
	Tarea("D", std::chrono::milliseconds(240));
}

int main(int argc, char *argv[]) {
	const std::chrono::milliseconds Ts(250);

	int tiempo;

	std::chrono::time_point<std::chrono::steady_clock> ini_sec = std::chrono::steady_clock::now();
	std::chrono::time_point<std::chrono::steady_clock> inicio;
	std::chrono::time_point<std::chrono::steady_clock> fin;

	while (true) {
		printf(":: %s\n", "VUELTA DEL BUCLE PRINCIPAL");

		for (int i=1; i<=4; i++) {
			inicio = std::chrono::steady_clock::now();

			printf("-> Iteración %d del bucle secundario\n", i);

			switch (i) {
				case 1 :
					TareaA(); TareaB(); TareaD();
				break;

				case 2 :
					TareaA(); TareaB(); TareaC();
				break;

				case 3 :
					TareaA(); TareaB(); TareaC();
				break;

				case 4 :
					TareaA(); TareaB();
				break;
			}

			fin = std::chrono::steady_clock::now();
			std::chrono::steady_clock::duration duracion = fin - inicio;

			switch (i) {
				case 1 :
					tiempo = 490;
				break;

				case 2 :
					tiempo = 450;
				break;

				case 3 :
					tiempo = 450;
				break;

				case 4 :
					tiempo = 250;
				break;
			}

			printf("> Retraso total: %fms.\n",
			       milliseconds_f(duracion).count() - tiempo);

			if (milliseconds_f(duracion).count() - tiempo > 20) {
				printf("%s\n", "Retraso mayor del permitido (20ms). Abortando...");
				exit(1);
			}

			ini_sec += Ts;
			std::this_thread::sleep_until(ini_sec);
		}
	}
}
