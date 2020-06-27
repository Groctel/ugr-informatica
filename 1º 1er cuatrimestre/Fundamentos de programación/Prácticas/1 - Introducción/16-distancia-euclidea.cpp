#include <cmath>
#include <iostream>

int main () {
	double x1,
	       x2,
	       y1,
	       y2,
	       modulo_x,
	       modulo_y,
	       distancia;

	std::cout << "Introduzca el primer punto (x,y separados por espacios): ";
	std::cin  >> x1 >> y1;
	std::cout << "Introduzca el segundo punto (x,y separados por espacios): ";
	std::cin  >> x2 >> y2;

	modulo_x  = x1 - x2;
	modulo_y  = y1 - y2;
	distancia = sqrt(modulo_x * modulo_x + modulo_y * modulo_y);

	std::cout << "La distancia entre los puntos [" << x1 << "," << y1 << "] y ["
	          << x2 << "," << y2 << "] vale " << distancia
	          << " unidades métricas." << std::endl;

	return 0;
}
