#include "algoritmos.hpp"

/** @brief Bubble sort
  *
  * Ordena un subvector de un vector de enteros, especificado por sus posiciones
  * de inicio y fin, mediante el algoritmo bubble sort.
  *
  * @param vector  Vector de enteros a ordenar
  * @param primero Posición de inicio del subvector a ordenar
  * @param ultimo  Posición de fin del subvector a ordenar
  */

void BubbleSort(int* v, const unsigned primero, const unsigned ultimo) {
	bool ordenado = false;
/*
 *	En el bucle externo recorremos el vector desde la primera posición hacia
 *	posiciones superiores hasta que esté ordenado.
 */
	for (int i=primero; !ordenado; i++) {
	/*
	 *	Comenzamos cada iteración presuponiendo que el vector está ordenado. Si un
	 *	vector está ordenada, no se hará ningún cambio entre dos elementos en la
	 *	iteración actual. Si se hace un cambio, lo consideramos desordenado, ya
	 *	que debemos hacer una comprobación final.
	 */
		ordenado = true;
	/*
	 *	En el bucle interno recorremos el vector desde la última posición hasta la
	 *	posición del bucle externo. Se garantiza que todas las posiciones
	 *	inferiores a la del bucle externo están ordenadas.
	 */
		for (int j=ultimo; j>i; j--) {
		/*
		 *	Si encontramos dos elementos consecutivos mal ordenados, los
		 *	intercambiamos.
		 */
			if (v[j-1] > v[j]) {
				int aux = v[j];
				v[j]    = v[j-1];
				v[j-1]  = aux;
			/*
			 *	Como hemos intercambiado dos elementos, consideramos desordenado
			 *	el vector.
			 */
				ordenado = false;
			}
		}
	}
}

/** @brief Número factorial
  *
  * Calcula el factorial de n-ésimo orden.
  *
  * @param n Orden del factorial a calcular
  *
  * @return Valor del n-ésimo factorial
  */

unsigned long Factorial (unsigned n) {
	unsigned long resultado = n;

	if (n>1)
		resultado = n * Factorial(n-1);

	return resultado;
}

/** @brief Secuencia de Fibonacci
  *
  * Busca el n-ésimo término de la secuencia Fibonacci de forma recursiva.
  *
  * @param n Orden del término a buscar
  *
  * @return Valor del n-ésimo término de la secuencia
  */

unsigned long Fibonacci (unsigned n) {
	unsigned long resultado = n;

	if (n > 1)
		resultado = Fibonacci(n-1) + Fibonacci(n-2);

	return resultado;
}

