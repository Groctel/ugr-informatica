#include <iostream>

int main () {
	const double DESCUENTO1 = 0.04;
	const double DESCUENTO2 = 0.02;

	double desc1_porcentaje = DESCUENTO1 * 100,
	       desc2_porcentaje = DESCUENTO2 * 100,
	       precio_desc1,
	       precio_desc2,
	       precio_inicial;

	std::cout << "Introduzca el precio de su billete: ";
	std::cin  >> precio_inicial;

	precio_desc1 = precio_inicial - (precio_inicial * DESCUENTO1);
	precio_desc2 = precio_inicial - (precio_inicial * DESCUENTO2);

	std::cout << "Su billete pasaría a costarle " << precio_desc1
	          << "€ con un descuento del " << desc1_porcentaje << "% y "
	          << precio_desc2 << "€ con un descuento del " << desc2_porcentaje
	          << "%." << std::endl;

	return 0;
}
