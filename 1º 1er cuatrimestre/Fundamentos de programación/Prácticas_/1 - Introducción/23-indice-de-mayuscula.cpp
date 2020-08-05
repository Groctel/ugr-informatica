#include <iostream>

int main () {
	const char INICIO_MAYUSCULAS = 'A';

	char mayuscula;
	int indice;

	std::cout << "Introduzca una mayúscula: ";
	std::cin  >> mayuscula;

	indice = mayuscula - INICIO_MAYUSCULAS;

	std::cout << "Su carácter tiene índice " << indice << "." << std::endl;

	return 0;
}
