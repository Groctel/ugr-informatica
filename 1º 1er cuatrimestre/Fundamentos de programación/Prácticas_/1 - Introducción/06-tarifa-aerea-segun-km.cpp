#include <iostream>

int main () {
	double kilometros,
	       precio,
	       precio_km   = 0.10,
	       tarifa_base = 150.00;

	std::cout << "Introduzca el número de kilómetros de su viaje: ";
	std::cin  >> kilometros;

	precio = tarifa_base + kilometros * precio_km;

	std::cout << "Su viaje le costará " << precio << "€." << std::endl;

	return 0;
}
