#include <iostream>

int main () {
	const int TOPE = 100;

	float v1 [TOPE] = {2, 3, 8, 22, 44, 88, 99, 100, 101, 255, 665},
	      v2 [TOPE] = {1, 3, 4, 5, 6, 25, 87, 89, 99, 100, 500, 1000},
	      res [2*TOPE];

	int tam_v1  = 11,
	    tam_v2  = 12,
	    tam_res = tam_v1 + tam_v2;

	float * p_v1 = v1,
	      * p_v2 = v2;

/*
 * Para cada elemento de `res` (`i < tam_res`), se busca insertar un elemento de
 * `v1` o `v2`. El puntero `p_res` no modifica su posición, sino que apunta más
 * o menos lejos en función de la variable i (`p_res + i`), mientras que los
 * punteros `p_v1` y `p_v2` sí varían su posición en un elemento tras ser
 * evaluados.
 *
 * Para evitar evaluaciones indefinidas o violaciones de segmento, se establece
 * como requisito comparativo que ninguno de los dos punteros a los vectores
 * originales apunten a posiciones más allá de su tamaño.
 */

	for (int i = 0; i < tam_res; i++) {
		if (p_v1 >= v1 + tam_v1) {
			*(res + i) = *(p_v2++);
		}
		else if (p_v2 >= v2 + tam_v2) {
			*(res + i) = *(p_v1++);
		}
		else {
			if (*p_v1 < *p_v2)
				*(res + i) = *(p_v1++);
			else
				*(res + i) = *(p_v2++);
		}
	}

/*
 * Para mostrar el vector resultado, no es necesario usar uno de los punteros,
 * nos basta con desreferenciarlo sumándole el índice del elemento que queremos
 * mostrar
 */

	std::cout << *res;

	for (int i = 1; i < tam_res; i++)
		std::cout << ", " << *(res + i);

	std::cout << std::endl;

	return 0;
}
