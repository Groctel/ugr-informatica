#include <iostream>

int main () {
	const int INICIO_NUMEROS = '0';

	char caracter;
	int entero;

	std::cout << "Introduzca un número del 0 al 9: ";
	std::cin  >> caracter;

	entero = caracter - INICIO_NUMEROS;

	std::cout << "Se ha introducido el número " << entero << "." << std::endl;

	return 0;
}
