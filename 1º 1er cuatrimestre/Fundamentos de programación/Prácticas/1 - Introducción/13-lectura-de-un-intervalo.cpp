#include <iostream>

int main ()
{
	char coma, extremo_inf, extremo_sup;
	double cota_inf, cota_sup;

	std::cout
		<< "Introduzca un intervalo siguendo el siguiente formato:" << std::endl
		<< " - Extremos cerrados -> []" << std::endl
		<< " - Extremos abiertos -> ][ ó ()" << std::endl
		<< " - Introduzca una coma entre ambas cotas" << std::endl
		<< " - Su intervalo debería ser similar a [3,4) o ]8,12[" << std::endl
		<< "> ";
	std::cin  >> extremo_inf >> cota_inf >> coma >> cota_sup >> extremo_sup;

	std::cout
		<< "Su intervalo es el " << extremo_inf << cota_inf << coma << cota_sup
		<< extremo_sup << "." << std::endl;

	return 0;
}
