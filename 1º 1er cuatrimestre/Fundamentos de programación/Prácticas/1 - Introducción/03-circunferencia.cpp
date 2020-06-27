#include <cmath>
#include <iostream>

int main () {

	double area,
	       longitud,
	       pi = 6 * asin(0.5),
	       radio;

	std::cout << "Introduzca el radio de la circunferencia: ";
	std::cin  >> radio;

	area     = pi * pow(radio,2);
	longitud = 2 * pi * radio;

	std::cout << "La circunferencia tiene una longitud de " << longitud
	          << "unidades métricas y el cí­rculo que forma, un área de "
	          << area << "unidades métricas." << std::endl;

	return 0;
}
