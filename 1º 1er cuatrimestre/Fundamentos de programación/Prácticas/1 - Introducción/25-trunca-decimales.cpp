#include <cmath>
#include <iostream>

int main ()
{
	double numero_inicial;
	int posicion_decimal;

	std::cout << "Introduzca un número real: ";
	std::cin  >> numero_inicial;
	std::cout << "Introduzca el número de decimales a los que desea truncarlo: ";
	std::cin  >> posicion_decimal;

	int desplazador     = pow(10, posicion_decimal);
	int truncador       = numero_inicial / desplazador;
	double numero_final = truncador * desplazador;

	std::cout << std::endl
		<< "El número " << numero_inicial
		<< " truncado a " << posicion_decimal
		<< " decimales vale " << numero_final << "." << std::endl;

	return 0;
}
