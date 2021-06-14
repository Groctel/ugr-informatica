#include <iostream>

int main ()
{
	const double METROS_A_PULGADAS   = 1000 / 25.4;
	const double METROS_A_PIES       =  100 / 30.48;
	const double METROS_A_YARDAS     =    1 / 0.9144;
	const double METROS_A_MILLAS     =    1 / 1609.344;
	const double METROS_A_MILLAS_MAR =    1 / 1852.0;

	double metros;

	std::cout << "Introduzca una medida en metros: ";
	std::cin  >> metros;

	double pulgadas   = metros * METROS_A_PULGADAS;
	double pies       = metros * METROS_A_PIES;
	double yardas     = metros * METROS_A_YARDAS;
	double millas     = metros * METROS_A_MILLAS;
	double millas_mar = metros * METROS_A_MILLAS_MAR;

	std::cout
		<< std::endl << metros << " metros equivalen a:" << std::endl
		<< " - " << millas << " millas" << std::endl
		<< " - " << millas_mar << " millas marítimas." << std::endl
		<< " - " << pies << " pies" << std::endl
		<< " - " << pulgadas << " pulgadas" << std::endl
		<< " - " << yardas << " yardas" << std::endl;

	return 0;
}
