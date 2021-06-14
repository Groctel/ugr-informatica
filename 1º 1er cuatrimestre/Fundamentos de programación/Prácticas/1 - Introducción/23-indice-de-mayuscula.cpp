#include <iostream>

int main ()
{
	const char INICIO_MAYUSCULAS = 'A';

	char mayuscula;

	std::cout << "Introduzca una mayúscula: ";
	std::cin  >> mayuscula;

	int indice = mayuscula - INICIO_MAYUSCULAS;

	std::cout << "Su carácter tiene índice " << indice << "." << std::endl;

	return 0;
}
