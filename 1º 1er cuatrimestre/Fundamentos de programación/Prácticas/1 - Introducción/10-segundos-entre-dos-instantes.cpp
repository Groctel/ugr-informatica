#include <iostream>

int main ()
{
	int hor_a_min = 60;
	int min_a_seg = 60;
	int hora1, minuto1, segundo1;
	int hora2, minuto2, segundo2;

	std::cout << "Introduzca un instante siguiendo el formato HH MM SS:";
	std::cin  >> hora1 >> minuto1 >> segundo1;
	std::cout << "Introduzca otro instante siguiendo el mismo formato: ";
	std::cin  >> hora2 >> minuto2 >> segundo2;

	int instante1 = (hora1 * hor_a_min + minuto1) * min_a_seg + segundo1;
	int instante2 = (hora2 * hor_a_min + minuto2) * min_a_seg + segundo2;
	int segundos_entre_instantes = instante2 - instante1;

	std::cout << "Han pasado " << segundos_entre_instantes << " segundos."
		<< std::endl;

	return 0;
}
