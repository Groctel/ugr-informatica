#include <iostream>

int main ()
{
	double precio_km   = 0.10;
	double tarifa_base = 150.00;
	double kilometros;

	std::cout << "Introduzca el número de kilómetros de su viaje: ";
	std::cin  >> kilometros;

	double precio = tarifa_base + kilometros * precio_km;

	std::cout << "Su viaje le costará " << precio << "€." << std::endl;

	return 0;
}
