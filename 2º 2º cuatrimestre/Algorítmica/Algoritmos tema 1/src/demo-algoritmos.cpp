#include <cstdio>
#include <cstring>
#include <ctime>
#include "algoritmos.hpp"

void Titulo (const char* texto) {
	printf("\n\033[1;32m%s\033[0m\n\n", texto);
}

int main (int argc, char** argv) {
/*
 *	Declaración de los booleanos que definen qué algoritmos han de ejecutarse.
 */
	bool todos       = argc == 1,
	     bubble      = false,
	     factorial   = false,
	     fibonacci   = false,
	     repetitivas = false;
/*
 *	Comprobación de qué algoritmos específicos han de ejecutarse.
 *	El orden de ejecución no varía.
 */
	if (argc > 1) {
		for (int i=1; i<argc; i++)	{
			if (!bubble)
				bubble = !strcmp(argv[i], "bubble");
			if (!factorial)
				factorial = !strcmp(argv[i], "factorial");
			if (!fibonacci)
				fibonacci = !strcmp(argv[i], "fibonacci");
			if (!repetitivas)
				repetitivas = !strcmp(argv[i], "repetitivas");
		}
	}
/*
 *	Bubble sort.
 */
	if (todos || bubble) {
	/*
	 *	Declaración de variables.
	 */
		const unsigned BS_TAM = 10000;

		int bs_vector[BS_TAM];
		unsigned long bs_inicio,
		              bs_fin;
	/*
	 *	Mostramos el nombre del algoritmo por salida estándar.
	 */
		Titulo("BUBBLE SORT");
	/*
	 *	Ejecutamos el algoritmo aumentando el tamaño útil del vector
	 *	en mil unidades por cada iteración hasta sobrepasar el máximo.
	 */
		for (unsigned tam=1000; tam<=BS_TAM; tam+=1000) {
		/*
		 *	Introducimos en el vector los valores en orden descendente, generando
		 *	el caso peor.
		 */
			for (unsigned i=0; i<tam; i++)
				bs_vector[i]= tam-i;
		/*
		 *	Ordenamos el vector y calculamos el tiempo que tarda en ordenarlo.
		 */
			bs_inicio = clock(); // Tiempo inicial
			BubbleSort(bs_vector, 0, tam-1);
			bs_fin = clock(); // Tiempo final
		/*
		 *	Mostramos el resultado del algoritmo por salida estándar.
		 */
			printf("N: %5d │ T: %-11fms.\n",
		          tam,
		          1000.0 * (bs_fin-bs_inicio) / (double)CLOCKS_PER_SEC);
		}
	}
/*
 *	Factorial
 */
	if (todos || factorial) {
	/*
	 *	Declaración de variables.
	 */
		unsigned fact_num;
	/*
	 *	Mostramos el nombre del algoritmo por salida estándar.
	 */
		Titulo("NÚMERO FACTORIAL");
	/*
	 *	Pedimos el número con el que va a trabajar el algoritmo.
	 */
		printf("%s", "Dime un número natural: ");
		scanf("%d", &fact_num);
	/*
	 *	Mostramos el resultado del algoritmo por salida estándar.
	 */
		printf("%d! = %ld\n", fact_num, Factorial(fact_num));
	}
/*
 *	Fibonacci.
 */
	if (todos || fibonacci) {
	/*
	 *	Declaración de variables.
	 */
		unsigned fib_num;
	/*
	 *	Mostramos el nombre del algoritmo por salida estándar.
	 */
		Titulo("SECUENCIA DE FIBONACCI");
	/*
	 *	Pedimos el número con el que va a trabajar el algoritmo.
	 */
		printf("%s", "Dime un número natural: ");
		scanf("%d", &fib_num);
	/*
	 *	Mostramos el resultado del algoritmo por salida estándar.
	 */
		printf("El %d-ésimo término de la sucesión de Fibonacci es: %ld\n",
		       fib_num, Fibonacci(fib_num));
	}
/*
 *	Sentencias repetitivas
 */
	if (todos || repetitivas) {
	/*
	 *	Declaración de variables.
	 */
		unsigned rep_num1,
		         rep_num2;
	/*
	 *	Mostramos el nombre del algoritmo por salida estándar.
	 */
		Titulo("SENTENCIAS REPETITIVAS");
	/*
	 *	Pedimos el número con el que va a trabajar el algoritmo.
	 */
		printf("%s", "Dime un número natural: ");
		scanf("%d", &rep_num1);
		rep_num2 = rep_num1;
	/*
	 *	Mostramos el primer resultado por salida estándar.
	 */
		printf("%s\n", "Bucle while:");
		while (rep_num1 > 0) {
			printf("%d, ", rep_num1);
			rep_num1--;
		}
		printf("\n");
	/*
	 *	Mostramos el segundo resultado por salida estándar.
	 */
		printf("%s\n", "Bucle for anidado:");

		while (rep_num2 > 0) {
			for (unsigned i=1; i<rep_num2; i*=2)
				printf("%d, ", rep_num2);
			rep_num2--;
			printf("\n");
		}
	}
/*
 *	Fin del programa.
 */
	return 0;
}
