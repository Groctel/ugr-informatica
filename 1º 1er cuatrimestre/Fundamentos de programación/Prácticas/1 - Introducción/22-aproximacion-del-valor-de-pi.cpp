#include <iostream>

int main ()
{
	const double PI_1800AC      = 256 / 81.0;
	const double PI_MESOPOTAMIA = (3 + 1) / 8.0;
	const double PI_CPTOLOMEO   = 377 / 120.0;

	std::cout
		<< "Tres aproximaciones históricoas de PI son:" << std::endl
		<< " - " << PI_1800AC << " del 1800 antes de Cristo." << std::endl
		<< " - " << PI_MESOPOTAMIA << " por los matemáticos mesopotámicos." << std::endl
		<< " - " << PI_CPTOLOMEO << " por Claudio Ptolomeo en el siglo II." << std::endl;

	return 0;
}
