#include <stdio.h>
#include <time.h>

void fusionaMS (double* v, int posIni, int centro, int posFin, double* vaux) {
	int i = posIni,
	    j = centro,
	    k = 0;

	while (i<centro && j<=posFin) {
		if (v[i]<=v[j]) {
			vaux[k] = v[i];
			i++;
		}
		else {
			vaux[k] = v[j];
			j++;
		}

		k++;
	}

	while (i<centro) {
		vaux[k] = v[i];
		i++, k++;
	}

	while (j<=posFin) {
		vaux[k] = v[j];
		j++, k++;
	}

	memcpy(v+posIni, vaux, k*sizeof(double));
}


void MergeSort (double* v, int posIni, int posFin, double* vaux) {
	if (posIni>=posFin)
		return;

	int centro = (posIni + posFin) / 2;

	MergeSort(v, posIni,   centro, vaux);
	MergeSort(v, centro+1, posFin, vaux);

	fusionaMS(v, posIni, centro+1, posFin, vaux);
}



int main () {
	const int SIZE = 10000;

	double vect[SIZE],
	       vaux[SIZE];
	unsigned long tini, tfin;

	for (int tam=SIZE/10; tam<=SIZE; tam+=SIZE/10) {
		// Ejemplo: Vector al revés
		for (int i= 0; i<tam; i++)
			vect[i]= tam-i;

		tini= clock(); // Tiempo inicial
		MergeSort(vect, 0, tam-1, vaux);
		tfin= clock(); // Tiempo final

		printf("N: %d T: %f ms.", tam, 1000.0*(tfin-tini)/(double)CLOCKS_PER_SEC);
	}

	return 0;
}
