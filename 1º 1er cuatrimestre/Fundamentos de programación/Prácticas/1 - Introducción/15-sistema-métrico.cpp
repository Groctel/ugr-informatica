#include <iostream>

int main () {
	const double METROS_A_PULGADAS   = 1000 / 25.4;
	const double METROS_A_PIES       =  100 / 30.48;
	const double METROS_A_YARDAS     =    1 / 0.9144;
	const double METROS_A_MILLAS     =    1 / 1609.344;
	const double METROS_A_MILLAS_MAR =    1 / 1852.0;

	double metros,
	       millas,
	       millas_mar,
	       pies,
	       pulgadas,
	       yardas;

	std::cout << "Introduzca una medida en metros: ";
	std::cin  >> metros;

	pulgadas   = metros * METROS_A_PULGADAS;
	pies       = metros * METROS_A_PIES;
	yardas     = metros * METROS_A_YARDAS;
	millas     = metros * METROS_A_MILLAS;
	millas_mar = metros * METROS_A_MILLAS_MAR;

	std::cout << std::endl << metros << " metros equivalen a:" << std::endl
	          << " - " << millas << " millas" << std::endl
	          << " - " << millas_mar << " millas marítimas." << std::endl
	          << " - " << pies << " pies" << std::endl
	          << " - " << pulgadas << " pulgadas" << std::endl
	          << " - " << yardas << " yardas" << std::endl;

	return 0;
}
