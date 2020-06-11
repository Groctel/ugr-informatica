#include <iostream>
#include <chrono>
#include <cstdlib>
#include <time.h>

void reestructurarRaiz (double * apo, int pos, int tamapo) {
	int minhijo;

	if (2*pos+1 < tamapo) {
		minhijo = 2 * pos + 1;

		if (minhijo+1 < tamapo && apo[minhijo] > apo[minhijo+1])
			minhijo++;

		if (apo[pos] > apo[minhijo]) {
			double tmp   = apo[pos];
			apo[pos]     = apo[minhijo];
			apo[minhijo] = tmp;
			reestructurarRaiz(apo, minhijo, tamapo);
		}
	}
}

void insertarEnPos (double * apo, int pos) {
	int idx = pos - 1,
	    padre;

	if (idx > 0) {
		if (idx % 2 == 0)
			padre = (idx - 2) / 2;
		else
			padre = (idx - 1) / 2;

		if (apo[padre] > apo[idx]) {
			double tmp = apo[idx];
			apo[idx]   = apo[padre];
			apo[padre] = tmp;
			insertarEnPos(apo, padre+1);
		}
	}
}

void HeapSort(int * v, int n) {
	double* apo = new double[n];
	int tamapo  = 0;

	for (int i=0; i<n; i++) {
		apo[tamapo] = v[i];
		tamapo++;
		insertarEnPos(apo, tamapo);
	}

	for (int i=0; i<n; i++) {
		v[i] = apo[0];
		tamapo--;
		apo[0] = apo[tamapo];
		reestructurarRaiz(apo, 0, tamapo);
	}

	delete [] apo;
}

int main (int argc, char ** argv) {
	int tam = atoi(argv[1]),
	    random;
	int* v = new int[tam];
	std::chrono::time_point<std::chrono::high_resolution_clock> t_ini, t_fin;
	unsigned long tiempo_ejecucion;

	srand(time(NULL));

	for (int i=0; i<tam; i++) {
		random = rand() %(9999999999 - 0);
		v[i] = random;
	}

	t_ini = std::chrono::high_resolution_clock::now();

	HeapSort(v, tam-1);

	t_fin = std::chrono::high_resolution_clock::now();

	tiempo_ejecucion = std::chrono::duration_cast<std::chrono::microseconds>
	                   (t_fin - t_ini).count();

	printf("%d %ld\n", tam, tiempo_ejecucion);

	return 0;
}
