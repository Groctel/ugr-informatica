#include <iostream>
#include "utils.hpp"

int main () {
	int dividendo,
	    divisor;

	std::cout << "Finalice este programa introduciendo un n�mero negativo."
	          << std::endl;

	std::cout << "Introduzca un dividendo: ";
	std::cin  >> dividendo;

	if (dividendo >= 0) {
		std::cout << "Introduzca un divisor: ";
		std::cin  >> divisor;
	}

	while ((dividendo >= 0) && (divisor >= 0)) {
		std::cout << "La divisi�n entera vale "
		          << DivisionEntera(dividendo, divisor) << std::endl
		          << "El resto de la divisi�n vale "
		          << RestoDivision(dividendo, divisor) << std::endl;

		std::cout << "Introduzca un dividendo: ";
		std::cin  >> dividendo;

		if (dividendo >= 0) {
			std::cout << "Introduzca un divisor: ";
			std::cin  >> divisor;
		}
	}

	return 0;
}
