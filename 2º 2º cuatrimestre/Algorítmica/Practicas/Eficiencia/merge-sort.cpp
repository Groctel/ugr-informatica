#include <chrono>
#include <cstdlib>
#include <random>
#include <time.h>

void combina (int * v, int ini, int med, int fin) {
	int vtam = fin - ini + 1,
	    i    = ini,
	    j    = med + 1,
	    k    = 0;
	int* aux = new int[vtam];

	while (i<=med && j<=fin) {
		if (v[i] < v[j]) {
			aux[k] = v[i];
			i++;
		}
		else {
			aux[k] = v[j];
			j++;
		}

		k++;
	}

	while (i <= med) {
		aux[k] = v[i];
		i++;
		k++;
	}

	while (j <= fin) {
		aux[k] = v[j];
		j++;
		k++;
	}

	for (int n=0; n<vtam; n++)
		v[ini+n] = aux[n];

	delete [] aux;
}

void MergeSort (int * v, int ini, int fin) {
	if (ini < fin) {
		int med = (ini + fin) / 2;
		MergeSort(v, ini, med);
		MergeSort(v, med+1, fin);
		combina(v, ini, med, fin);
	}
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

	MergeSort(v, 0, tam-1);

	t_fin = std::chrono::high_resolution_clock::now();

	tiempo_ejecucion = std::chrono::duration_cast<std::chrono::microseconds>
	                   (t_fin - t_ini).count();

	printf("%d %ld\n", tam, tiempo_ejecucion);

	return 0;
}
