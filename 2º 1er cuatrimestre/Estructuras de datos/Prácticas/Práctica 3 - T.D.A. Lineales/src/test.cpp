#include <cstdio>
#include <random>
#include <string>
#include <time.h>
#include "pila_max.tpp"

int main () {
/*
 *	Declaración e inicialización de variables.
 */

	int random,    // Generador aleatorio de enteros
	    minimo,    // Valor mínimo a introducir en la pila (inclusive)
	    maximo,    // Valor máximo a introducir en la pila (no inclusive)
	    digitos;   // Número de dígitos a tener en cuenta para imprimir
	size_t elementos; // Elementos a introducir en la pila

	std::string separador = ""; // Separador horizontal (a rellenar)
	PilaMax<int> pila(1);       // Pila de trabajo

	// INICIACIÓN DEL GENERADOR ALEATORIO DE ENTEROS

	printf ("\033[1;34m==> \033[0m%s\n\n",
	        "Inicializando generador aleatorio de enteros...");

	srand(time(NULL));

	/* LECTURA DEL NÚMERO DE ELEMENTOS
	 *
	 * El número de elementos a introducir en una pila debe ser mayor que 0 y
	 * menor que el máximo permitido por la misma.
	 */

	do {
		printf ("\033[1;34m::\033[0m %s ",
		        "Indique el número de elementos que desea introducir:");

		scanf ("%ld", &elementos);
	} while (elementos > pila.max_size() || elementos == 0);

	/* LECTURA DEL VALOR MÍNIMO
	 *
	 * Al tratarse de números enteros, no imponemos restrucciones sobre el valor
	 * del mínimo.
	 */

	printf ("\033[1;34m::\033[0m %s ",
	        "Indique el valor mínimo de la pila (inclusive):");

	scanf ("%d", &minimo);

	/* LECTURA DEL VALOR MÁXIMO
	 *
	 * Debe ser siempre mayor o igual que el valor mínimo.
	 */

	do {
		printf ("\033[1;34m::\033[0m %s ",
		        "Indique el valor máximo de la pila (no inclusive):");

		scanf ("%d", &maximo);
	} while (maximo < minimo);

	/* INTRODUCCIÓN DE ELEMENTOS EN LA PILA
	 *
	 * Primero se calcula el número de cifras del número de elementos para
	 * imprimirlas en pantalla con formato. Después se van introduciendo los
	 * elementos mientras se muestra el progreso.
	 */

	// Cálculo del número de dígitos
	digitos = 0;
	for (size_t i=elementos; i>0; i/=10, digitos++);

	printf ("\n\n");
	for (size_t i=0; i<elementos; i++) {
		// Muestra del progreso
		printf ("\r\033[A\033[1;34m==> "
		        "\033[1;36m[\033[0m %*ld \033[1;36m/\033[0m %ld \033[1;36m]"
		        "\033[0m %s\n",
		        digitos, i+1, elementos,
		        "Introduciendo valores en la pila...");

		// Introducción del valor en la pila
		random = rand() %(maximo - minimo) + minimo; // [minimo - maximo)
		pila.push(random);
	}

	/* CREACIÓN DEL SEPARADOR
	 *
	 * Si hay elementos en la pila, se crea un separador con tantos caracteres
	 * como cifras tenga el número más elevado de la misma más uno a cada lado.
	 */

	if (!pila.empty()) {
		digitos = 0;

		for (int i=pila.top().second(); i>0; i/=10, digitos++);
		for (int i=0; i<digitos+2; i++, separador.append("─"));
	}

	// INFORMACIÓN SOBRE EL ESTADO DEL PROGRAMA

	printf ("\033[1;34m==>\033[0m %s\n",
	        "Mostrando el tope de la pila y eliminando en bucle...");

	// DIBUJO DEL INICIO DE LA PILA USANDO EL SEPARADOR

	printf ("\n\033[1;33m ┌%s┬%s┐\033[0m\n",
	        separador.c_str(), separador.c_str());

	/* MUESTRA DE LOS ELEMENTOS DE LA PILA
	 *
	 * Cada elemento de la pila se muestra encapsulado de forma que el valor de
	 * la izquierda es el valor actual y el de la derecha, el máximo. Cada cinco
	 * elementos se dibuja un separador para facilitar la lectura.
	 *
	 * Cada vez que se muestra un elemento de la pila, se elimina para poder
	 * mostrar el siguiente.
	 */

	for (size_t i=1; !pila.empty(); i++) {
		// Muestra del elemento
		printf ("\033[1;33m │\033[0m %*d "                     // Actual
		        "\033[1;33m│\033[0m %*d \033[1;33m│\033[0m\n", // Maximo
		        digitos, pila.top().first(),
				  digitos, pila.top().second());

		pila.pop();

		// Introducción de un separador cada cinco elementos
		if (i == 5 && !pila.empty()) {
			printf ("\033[1;33m ├%s┼%s┤\033[0m\n",
			        separador.c_str(), separador.c_str());
			i = 0;
		}
	}

	// DIBUJO DEL FINAL DE LA PILA USANDO EL SEPARADOR

	printf ("\033[1;33m └%s┴%s┘\033[0m\n",
	        separador.c_str(), separador.c_str());
}
