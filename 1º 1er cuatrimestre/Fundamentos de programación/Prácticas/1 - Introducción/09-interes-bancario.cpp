#include <iostream>

int main ()
{
	double capital, interes;

	std::cout << "Introduzca su capital en euros: ";
	std::cin  >> capital;
	std::cout << "Introduzca su tipo de interés (de 0% a 100%): ";
	std::cin  >> interes;

	capital += capital * interes / 100;

	std::cout << "Su capital al cabo de un año valdrá " << capital << "€."
		<< std::endl;

	return 0;
}
