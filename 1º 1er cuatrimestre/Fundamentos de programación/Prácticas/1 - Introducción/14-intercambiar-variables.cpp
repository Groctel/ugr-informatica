#include <iostream>

int main ()
{
	int caja_izda, caja_dcha;

	std::cout << "Introduzca el valor de sus dos cajas: ";
	std::cin  >> caja_izda >> caja_dcha;
	std::cout
		<< "La caja de la izquierda vale " << caja_izda << "." << std::endl
		<< "La caja de la derecha vale " << caja_dcha << "." << std::endl
		<< "Cambiamos los valores y..." << std::endl << std::endl;

	int cambio_var = caja_izda;
	caja_izda  = caja_dcha;
	caja_dcha  = cambio_var;

	std::cout
		<< "La caja de la izquierda vale " << caja_izda << "." << std::endl
		<< "La caja de la derecha vale " << caja_dcha << "." << std::endl;

	return 0;
}
