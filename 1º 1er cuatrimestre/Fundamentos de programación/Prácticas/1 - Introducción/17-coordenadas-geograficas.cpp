#include <cmath>
#include <iostream>

int main () {
	const double PI                = 6 * asin(0.5);
	const double GRADOS_A_RADIANES = PI / 180;

	double grados_lon1,
	       grados_lat1,
	       grados_lon2,
	       grados_lat2,
	       rad_lon1,
	       rad_lat1,
	       rad_lon2,
	       rad_lat2,
	       a;

	std::cout << "Introduzca la longitud y latitud de un punto en grados: ";
	std::cin  >> grados_lon1 >> grados_lat1;
	std::cout << "Introduzca la longitud y latitud de otro punto en grados: ";
	std::cin  >> grados_lon2 >> grados_lat2;

	rad_lon1 = grados_lon1 * GRADOS_A_RADIANES;
	rad_lat1 = grados_lat1 * GRADOS_A_RADIANES;
	rad_lon2 = grados_lon2 * GRADOS_A_RADIANES;
	rad_lat2 = grados_lat2 * GRADOS_A_RADIANES;

	a = pow(sin((rad_lat2 - rad_lat1) / 2), 2)
	  + cos(rad_lat1) * cos(rad_lat2)
	  * pow(sin((rad_lon2 - rad_lon1) / 2), 2);

	std::cout << "La variable 'a' vale " << a << "." << std::endl;

	return 0;
}
