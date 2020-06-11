/*
 * Suma de dos vectores: v3 = v1 + v2
 *
 * Para compilar usar:
 *    gcc  -O2  SumaVectores.c -o SumaVectores -lrt
 *    gcc  -O2 -S SumaVectores.c -lrt
 * (-lrt: real time library. Es posible que no sea necesario usarlo)
 *
 * Para ejecutar use:
 *    SumaVectoresC longitud
 */

#include <limits.h>
#include <stdlib.h>	// biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h>	// biblioteca donde se encuentra la función printf()
#include <time.h>	   // biblioteca donde se encuentra la función clock_gettime()

// Sólo uno de los tres defines siguientes puede estar descomentado:

/*
 * Descomentar para que los vectores sean variables locales.
 * Si se supera el tamaño de la pila se generará un violación de segmento
 */

#define VECTOR_LOCAL

/*
 * Descomentar para que los vectores sean variables globales.
 * Su longitud no estará limitada por el tamaño de la pila del programa.
 */

// #define VECTOR_GLOBAL

/*
 * Descomentar para que los vectores sean variables dinámicas almacenadas en
 * memoria reutilizable durante la ejecución.
 */

// #define VECTOR_DYNAMIC

#ifdef VECTOR_GLOBAL
	#define MAX 33554432	// 2^25
	double v1[MAX],
	       v2[MAX],
	       v3[MAX];
#endif

int main(int argc, char ** argv) {
	int i;
	unsigned N = UINT_MAX;

	double ncgt;
	struct timespec cgt1,
	                cgt2;

/*
 *	Leer argumento de entrada (nº de componentes del vector)
 */
	if (argc < 2) {
		printf("Falta el nº de componentes del vector\n");
		exit(-1);
	}

	printf("Tamaño Vectores: %u (%luB)\n", N, sizeof(unsigned int));

	#ifdef VECTOR_LOCAL
   /*
	 *	Tamaño variable local en tiempo de ejecución.
	 *	Disponible en C a partir de C99.
	 */
		double v1[N],
		       v2[N],
		       v3[N];
	#endif

	#ifdef VECTOR_GLOBAL
		if (N>MAX)
			N=MAX;
	#endif

	#ifdef VECTOR_DYNAMIC
		double * v1,
		       * v2,
		       * v3;

		v1 = (double *) malloc(N * sizeof(double));
		v2 = (double *) malloc(N * sizeof(double));
		v3 = (double *) malloc(N * sizeof(double));

		if ((v1 == NULL) || (v2 == NULL) || (v2 == NULL)) {
			printf("No hay suficiente espacio para los vectores.\n");
			exit(-2);
		}
	#endif
/*
 *	Inicialización de los vectores
 */
	for (i=0; i<N; i++) {
		v1[i] = N*0.1 + i*0.1;
		v2[i] = N*0.1 - i*0.1;
	}

	clock_gettime(CLOCK_REALTIME,&cgt1);
/*
 *	Cálculo de la suma de vectores
 */
	for (i=0; i<N; i++)
		v3[i] = v1[i] + v2[i];

	clock_gettime(CLOCK_REALTIME,&cgt2);

	ncgt = (double) (cgt2.tv_sec   - cgt1.tv_sec)
	     + (double) ((cgt2.tv_nsec - cgt1.tv_nsec) / 1.e9);
/*
 * Impresión del resultado de la suma y el tiempo de ejecución
 */
	if (N<10) {
		printf("Tiempo: %11.9f --- Tamaño Vectores: %u\n", ncgt, N);

		for (i=0; i<N; i++)
			printf(" - V1[%d]+V2[%d] = V3[%d] (%8.6f+%8.6f = %8.6f)\n",
			              i,     i,       i,   v1[i],v2[i],  v3[i]);
	}
	else {
		printf("Tiempo: %11.9f --- Tamaño Vectores: %u\n"
		       "V1[0]+V2[0] = V3[0] (%8.6f+%8.6f = %8.6f)\n"
		       "V1[%d]+V2[%d] = V3[%d] (%8.6f+%8.6f = %8.6f)\n",
		                ncgt,                       N,
		                             v1[0],v2[0],  v3[0],
		           N-1,   N-1,     N-1, v1[N-1],v2[N-1],v3[N-1]);
	}

	#ifdef VECTOR_DYNAMIC
		free(v1);
		free(v2);
		free(v3);
	#endif

	return 0;
}
