#include <iostream>

int main () {
	const double TARIFA_BASE = 150.00;
	const double PRECIO_KM   = 0.10;

	double kilometros,
	       precio;

	std::cout << "Introduzca el número de kilómetros de su viaje: ";
	std::cin  >> kilometros;

	precio = TARIFA_BASE + kilometros * PRECIO_KM;

	std::cout << "Su viaje le costará " << precio << "€." << std::endl;

	return 0;
}
