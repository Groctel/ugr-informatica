#include <iostream>

int main ()
{
	int cota_inf, cota_sup, desplz, num_inicial;

	std::cout << "Introduzca las cotas inferior y superior de un intervalo: ";
	std::cin  >> cota_inf >> cota_sup;
	std::cout << "Introduzca un valor de desplazamiento: ";
	std::cin  >> desplz;
	std::cout << "Introduzca un número a desplazar que esté en su intervalo: ";
	std::cin  >> num_inicial;

	int intervalo = cota_sup - cota_inf + 1;
	int num_final = ((num_inicial + desplz - cota_inf) % intervalo) + cota_inf;

	std::cout
		<< "El número " << num_inicial << " desplazado " << desplz
		<< " posiciones en el intervalo [" << cota_inf << "," << cota_sup
		<< "] vale " << num_final << "." << std::endl;

	return 0;
}
