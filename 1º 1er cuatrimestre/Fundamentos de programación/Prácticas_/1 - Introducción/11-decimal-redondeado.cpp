#include <cmath>
#include <iostream>

int main () {
	double real,
	       redondeado;
	int decimales,
	    truncador;

	std::cout << "Introduzca un número real con decimales: ";
	std::cin  >> real;
	std::cout << "Introduzca a cuántos decimales desea redondearlo: ";
	std::cin  >> decimales;

	truncador  = pow(10, decimales);
	redondeado = round(real * truncador) / truncador;

	std::cout << "El número " << real << " redondeado a " << decimales
	          << " cifras decimales vale " << redondeado << "." << std::endl;

	return 0;
}
