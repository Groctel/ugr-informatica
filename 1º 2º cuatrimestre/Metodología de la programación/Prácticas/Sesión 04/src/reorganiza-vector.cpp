#include <iostream>
#include <random>

int main () {
	const int TOPE = 20;

	float v [TOPE],
	      * p_v  = v,
	      * pr_v = p_v + 1,
	      intercambia;

/*
 * Inicializamos el generador de números aleatorios y rellenamos el vector con
 * números aletorios del 0 al 99, ambos inclusive.
 */

	srand(time(NULL));

	for (int i = 0; i < TOPE; i++)
		*(v + i) = random () % 100;

	std::cout << "Vector original:" << std::endl
	          << *v;

	for (int i = 1; i < TOPE; i++)
		std::cout << ", " << *(v + i);

	std::cout << std::endl << std::endl;

/*
 * Ejecutamos el algoritmo de ordenación mientras el vector no esté ordenado, es
 * decir, mientras `p_v` apunte a un elemento de índice inferior que `pr_v`.
 */

	while (p_v < pr_v) {
	// Adelantamos el primer puntero
		for (p_v = v; *p_v <= *v; p_v++);
	// Retrasamos el segundo puntero
		for (pr_v = v + (TOPE-1); *pr_v > *v; pr_v--);

	 // Si los punteros no se han cruzado, sus elementos están desordenados
		if (p_v < pr_v) {
			intercambia = *p_v;
			*p_v        = *pr_v;
			*pr_v       = intercambia;
		}
	}

	std::cout << "Vector final:" << std::endl
	          << *v;

	for (int i = 1; i < TOPE; i++)
		std::cout << ", " << *(v + i);

	std::cout << std::endl;

	return 0;
}
