#include <algorithm>
#include <cmath>
#include <iostream>

int main ()
{
	const double PI = 6 * asin(0.5);
	const double GRADOS_A_RADIANES = PI / 180;
	const double RADIO_TERRESTRE = 6372797.560856;

	double altura1, altura2, grados_lon1, grados_lat1, grados_lon2, grados_lat2;

	std::cout << "Introduzca la longitud, latitud de un punto en grados: ";
	std::cin  >> grados_lon1 >> grados_lat1;
	std::cout << "Introduzca la altura de dicho punto en metros: ";
	std::cin  >> altura1;
	std::cout << "Introduzca la longitud y latitud de otro punto en grados: ";
	std::cin  >> grados_lon2 >> grados_lat2;
	std::cout << "Introduzca la altura de dicho punto en metros: ";
	std::cin  >> altura2;

	double rad_lon1 = grados_lon1 * GRADOS_A_RADIANES;
	double rad_lat1 = grados_lat1 * GRADOS_A_RADIANES;
	double rad_lon2 = grados_lon2 * GRADOS_A_RADIANES;
	double rad_lat2 = grados_lat2 * GRADOS_A_RADIANES;

	double delta_lon = rad_lon2 - rad_lon1;
	double delta_lat = rad_lat1 - rad_lat1;

	double a = pow(sin(0.5 * delta_lat), 2)
		+ cos(rad_lat1) * cos(rad_lat2) * pow(sin(0.5 * delta_lon), 2);

	double c = 2 * asin(std::min(1.0, sqrt(a)));

	double distancia_plana = RADIO_TERRESTRE * c;
	double distancia_3d = sqrt(pow(altura1 - altura2, 2) + pow(distancia_plana, 2));

	std::cout
		<< "La distancia plana entre ambos puntos vale "
		<< distancia_plana << "unidades, siendo la distancia real entre"
		<< "ambos de " << distancia_3d << " metros." << std::endl;

	return 0;
}
