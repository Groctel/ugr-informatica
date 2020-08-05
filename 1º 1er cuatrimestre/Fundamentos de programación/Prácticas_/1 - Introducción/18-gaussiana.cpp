#include <cmath>
#include <iostream>

int main () {
	const double PI = 6 * asin(0.5);

	double abscisa,
	       desv_tipica,
	       gaussiana,
	       media;

	std::cout << "Introduzca la abscisa, la desviación típica y la media:";
	std::cin  >> abscisa >> desv_tipica >> media;

	gaussiana = (1 / (desv_tipica * sqrt(2 * PI)))
	          * exp(-0.5 * (pow((abscisa - media) / desv_tipica, 2)));

	std::cout << "La gaussiana de su función vale " << gaussiana << "."
	          << std::endl;

	return 0;
}
