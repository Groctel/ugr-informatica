#include <iostream>

int main () {
	double intensidad,
	       resistencia,
	       voltaje;

	std::cout << "Introduzca la intensidad: ";
	std::cin  >> intensidad;
	std::cout << "Introduzca la resistencia: ";
	std::cin  >> resistencia;

	voltaje = intensidad * resistencia;

	std::cout << "El voltaje vale " << voltaje << "." << std::endl;

	return 0;
}
