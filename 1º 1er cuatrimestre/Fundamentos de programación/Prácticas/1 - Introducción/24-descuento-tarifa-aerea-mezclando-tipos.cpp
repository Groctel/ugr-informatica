#include <iostream>

int main ()
{
	const double DESCUENTO1 = 0.04;
	const double DESCUENTO2 = 0.02;
	const double DESC1_PORCENTAJE = DESCUENTO1 * 100;
	const double DESC2_PORCENTAJE = DESCUENTO2 * 100;

	double precio_inicial;

	std::cout << "Introduzca el precio de su billete: ";
	std::cin  >> precio_inicial;

	double precio_desc1 = precio_inicial - (precio_inicial * DESCUENTO1);
	double precio_desc2 = precio_inicial - (precio_inicial * DESCUENTO2);

	std::cout
		<< "Su billete pasaría a costarle " << precio_desc1
		<< "€ con un descuento del " << DESC1_PORCENTAJE << "% y "
		<< precio_desc2 << "€ con un descuento del " << DESC2_PORCENTAJE
		<< "%." << std::endl;

	return 0;
}
