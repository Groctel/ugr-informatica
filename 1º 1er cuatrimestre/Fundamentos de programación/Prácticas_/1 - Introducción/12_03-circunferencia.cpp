#include <cmath>
#include <iostream>

int main () {
	const double PI = 6 * asin(0.5);

	double area,
	       radio,
	       longitud;

	std::cout << "Introduzca el radio de la circunferencia: ";
	std::cin  >> radio;

	area     = PI * pow(radio,2);
	longitud = 2 * PI * radio;

	std::cout << "La circunferencia tiene una longitud de " << longitud
	          << "unidades métricas y el cí­rculo que forma, un área de "
	          << area << "unidades métricas." << std::endl;

	return 0;
}
