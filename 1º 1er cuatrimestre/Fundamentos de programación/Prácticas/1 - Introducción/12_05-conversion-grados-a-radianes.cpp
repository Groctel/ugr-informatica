#include <cmath>
#include <iostream>

int main () {
	const double PI = 6 * asin(0.5);
	const double GRADOS_A_RADIANES = PI / 180;

	double grados1,
	       grados2,
	       radianes1,
	       radianes2;

	std::cout << "Introduzca dos ángulos en grados separados por espacios: ";
	std::cin  >> grados1 >> grados2;

	radianes1 = grados1 * GRADOS_A_RADIANES;
	radianes2 = grados2 * GRADOS_A_RADIANES;

	std::cout << "Su primer ángulo mide " << radianes1 << " radianes."
	          << std::endl << "Su segundo ángulo mide " << radianes2
	          << " radianes." << std::endl;

	return 0;
}
