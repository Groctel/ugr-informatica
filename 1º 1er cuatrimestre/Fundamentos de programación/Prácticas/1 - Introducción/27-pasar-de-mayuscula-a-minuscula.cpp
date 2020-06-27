#include <iostream>

int main () {
	const int MAYUS_A_MINUS = 'a' - 'A';

	char mayuscula,
	     minuscula;

	std::cout << "Introduzca una mayúscula: ";
	std::cin  >> mayuscula;

	minuscula = mayuscula + MAYUS_A_MINUS;

	std::cout << "Su letra tiene la minúscula complementaria '"
	          << minuscula << "'." << std::endl;

	return 0;
}
