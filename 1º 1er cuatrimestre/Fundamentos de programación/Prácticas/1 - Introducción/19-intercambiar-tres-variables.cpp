#include <iostream>

int main ()
{
	int x, y, z;

	std::cout << "Introduzca tres números enteros separados por espacios: ";
	std::cin  >> x >> y >> z;
	std::cout << "Sus números son:" << std::endl
		<< " - x: " << x << std::endl
		<< " - y: " << y << std::endl
		<< " - z: " << z << std::endl << std::endl;

	int intercambia = z;
	z = y;
	y = x;
	x = intercambia;

	std::cout << "Tras el cambio, sus números son:" << std::endl
		<< " - x: " << x << std::endl
		<< " - y: " << y << std::endl
		<< " - z: " << z << std::endl;

	return 0;
}
