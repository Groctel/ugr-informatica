#include <cmath>
#include <iostream>

int main () {
	const int NUMERO_VALORES = 3;

	double desv_tipica,
	       media,
	       valor1,
	       valor2,
	       valor3;

	std::cout << "Introduzca tres valores reales separados por espacios: ";
	std::cin  >> valor1 >> valor2 >> valor3;

	media       = (valor1 + valor2 + valor3) / NUMERO_VALORES;
	desv_tipica = pow(valor1 - media, 2)
	            + pow(valor2 - media, 2)
	            + pow(valor3 - media, 2);

	std::cout << "\nLa media de sus valores vale " << media << ".\n"
	          << "\nLa desviación típica de sus valores vale "
	          << desv_tipica << std::endl;

	return 0;
}
