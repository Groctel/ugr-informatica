/** @file test.cpp
  */

#include <cstdio>
#include "cola.tpp"

/** @brief Impresor de elementos
  *
  * Imprime el número de elementos de la cola.
  */

template <typename T>
void MuestraElementos (Cola<T> cola) {
	printf ("\n\033[1;31m%s\033[0m%s\033[1;32m%ld\033[0m%s\n\n",
	        ":: ",
	        "La cola tiene ",
	        cola.size(),
	        " elementos");
}

/** @brief Test principal
  *
  * El programa de test de este reto simplemente inserta `TAM` elementos y
  * elimina la mitad de ellos. También implementa una pequeña función llamada
  * MuestraElementos que imprime en pantalla el número de
  * elementos que contiene la cola.
  */

int main () {
/*
 *	Declaración de constantes y variables.
 */
	const unsigned TAM = 20;
	Cola<unsigned> cola;
	unsigned numeros[TAM];
/*
 *	Rellenamos el vector de números.
 */
	for (unsigned i=0; i<TAM; i++)
		numeros[i] = i;
/*
 *	Mostramos que la cola está vacía.
 */
	MuestraElementos(cola);
/*
 *	Introducimos todos los números del vector en la cola.
 */
	printf ("\033[1;34m%s\033[0m%s\033[1;32m[0..%d)\033[0m\n",
	        "==> ",
	        "Introduciendo números en la cola ",
	        TAM);

	for (size_t i=0; i<TAM; i++) {
		cola.push(numeros[i]);
		printf ("\033[1;33m%s\033[0m%s\033[32m%2d\n\033[0m",
		        " -> ",
		        "Se ha introducido el número ",
		        cola.back());
	}
/*
 *	Mostramos que la cola contiene TAM elementos.
 */
	MuestraElementos(cola);

	printf ("\033[1;34m%s\033[0m%s\033[1;32m[0..%d)\033[0m\n",
	        "==> ",
	        "Extrayendo números de la cola ",
	        TAM/2);
/*
 *	Extraemos la mitad de los elementos de la cola.
 */
	for (size_t i=0; i<TAM/2; i++) {
		printf ("\033[1;33m%s\033[0m%s\033[32m%2d\n\033[0m",
		        " -> ",
		        "Se va a extraer el número",
		        cola.front());
		cola.pop();
	}
/*
 *	Mostramos el elemento más antiguo de la cola (numeros[TAM/2]).
 */
	printf ("\033[1;33m%s\033[0m%s\033[32m%d\033[0m%s\n\033[0m",
		    " -> ",
		    "El número ",
		    cola.front(),
			 " está a la cabeza de la cola");
/*
 *	Mostramos por última vez el número de elementos de la cola.
 */
	MuestraElementos(cola);
}

/** @mainpage
  *
  * @section Enunciado
  *
  * El reto 3 tiene un planteamiento muy sencillo. Se trata de implementar la
  * clase `Cola` a partir de la clase `Pila`. La idea es que disponéis de la
  * clase `Pila` con toda la implementación ya hecha y tenéis que construir la
  * clase `Cola` a partir de esa implementación sin tener que implementar nuevo
  * código, es decir que la implementación de las funciones se hará simplemente
  * llamando a funciones ya implementadas de las pilas.
  *
  * P.ej. la función `quitar` de la cola se podría construir a partir de la
  * función `quitar` de las pilas. Para la función `poner` de las colas,
  * probablemente uséis alguna pila auxiliar.
  *
  * Hay dos niveles en la solución:
  *
  * **a)** Solución simple, en que solo habríais de indicar cómo y con qué
  * llamadas a las funciones de las pilas se construirían las funciones de las
  * colas.
  *
  * **b)** Solución compleja, en que habreis de construir la clase `cola`,
  * compilarla y que funcione.
  *
  * Podéis optar por resolver el reto usando la STL, de forma que el reto se
  * convierte en hacer funcionar el tipo `queue` a partir del tipo `stack`.
  */
