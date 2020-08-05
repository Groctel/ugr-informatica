#include <cmath>
#include <iostream>

int main () {
	double pi = 6 * asin(0.5),
	       grados_a_radianes = pi / 180,
	       grados1,
	       grados2,
	       radianes1,
	       radianes2;

	std::cout << "Introduzca dos ángulos en grados separados por espacios: ";
	std::cin >> grados1 >> grados2;

	radianes1 = grados1 * grados_a_radianes;
	radianes2 = grados2 * grados_a_radianes;

	std::cout << "Su primer ángulo mide " << radianes1 << " radianes."
	          << std::endl << "Su segundo ángulo mide " << radianes2
	          << " radianes." << std::endl;

	return 0;
}
