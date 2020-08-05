#include <cmath>
#include <iostream>

int main () {
	double numero_inicial,
	       numero_final;
	int desplazador,
	    posicion_decimal,
	    truncador;

	std::cout << "Introduzca un número real: ";
	std::cin  >> numero_inicial;
	std::cout << "Introduzca el número de decimales a los que desea truncarlo: ";
	std::cin  >> posicion_decimal;

	desplazador  = pow(10, posicion_decimal);
	truncador    = numero_inicial / desplazador;
	numero_final = truncador * desplazador;

	std::cout << "\nEl número " << numero_inicial
	          << " truncado a " << posicion_decimal
	          << " decimales vale " << numero_final << "." << std::endl;

	return 0;
}
