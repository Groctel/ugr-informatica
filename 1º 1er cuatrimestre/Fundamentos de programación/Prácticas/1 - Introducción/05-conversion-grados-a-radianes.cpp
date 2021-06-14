#include <cmath>
#include <iostream>

int main ()
{
	double pi = 6 * asin(0.5);
	double grados_a_radianes = pi / 180;
	double grados1, grados2;

	std::cout << "Introduzca dos ángulos en grados separados por espacios: ";
	std::cin  >> grados1 >> grados2;

	double radianes1 = grados1 * grados_a_radianes;
	double radianes2 = grados2 * grados_a_radianes;

	std::cout
		<< "Su primer ángulo mide " << radianes1 << " radianes." << std::endl
		<< "Su segundo ángulo mide " << radianes2 << " radianes." << std::endl;

	return 0;
}
