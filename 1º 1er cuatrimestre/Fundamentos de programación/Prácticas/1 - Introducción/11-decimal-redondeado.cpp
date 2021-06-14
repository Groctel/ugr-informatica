#include <cmath>
#include <iostream>

int main ()
{
	double real;
	int decimales;

	std::cout << "Introduzca un número real con decimales: ";
	std::cin  >> real;
	std::cout << "Introduzca a cuántos decimales desea redondearlo: ";
	std::cin  >> decimales;

	int truncador  = pow(10, decimales);
	double redondeado = round(real * truncador) / truncador;

	std::cout
		<< "El número " << real << " redondeado a " << decimales
		<< " cifras decimales vale " << redondeado << "." << std::endl;

	return 0;
}
