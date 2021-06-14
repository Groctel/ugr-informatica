#include <cmath>
#include <iostream>

int main ()
{
	double pi = 6 * asin(0.5);
	double radio;

	std::cout << "Introduzca el radio de la circunferencia: ";
	std::cin  >> radio;

	double area     = pi * pow(radio,2);
	double longitud = 2 * pi * radio;

	std::cout
		<< "La circunferencia tiene una longitud de " << longitud
		<< " unidades métricas y el círculo que forma, un área de " << area
		<< "unidades métricas." << std::endl;

	return 0;
}
