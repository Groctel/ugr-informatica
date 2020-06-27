#include <iostream>

int main () {
	double descuento1 = 0.04,
	       descuento2 = 0.02,
	       precio_desc1,
	       precio_desc2,
	       precio_inicial;

	std::cout << "Introduzca el precio de su billete: ";
	std::cin  >> precio_inicial;

	precio_desc1 = precio_inicial - (precio_inicial * descuento1);
	precio_desc2 = precio_inicial - (precio_inicial * descuento2);

	std::cout << "Su billete pasaría a costarle " << precio_desc1
	          << "€ con un descuento del " << descuento1 / 100 << "% y "
	          << precio_desc2 << "€ con un descuento del " << descuento2 / 100
	          << "%." << std::endl;

	return 0;
}
