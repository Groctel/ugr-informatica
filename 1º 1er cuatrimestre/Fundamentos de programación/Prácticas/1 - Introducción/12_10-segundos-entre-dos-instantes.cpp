#include <iostream>

int main () {
	const int HOR_A_MIN = 60;
	const int MIN_A_SEG = 60;

	int hora1, minuto1, segundo1,
	    hora2, minuto2, segundo2,
	    instante1, instante2,
	    segundos_entre_instantes;

	std::cout << "Introduzca un instante siguiendo el formato HH MM SS:";
	std::cin  >> hora1 >> minuto1 >> segundo1;
	std::cout << "Introduzca otro instante siguiendo el mismo formato: ";
	std::cin  >> hora2 >> minuto2 >> segundo2;

	instante1 = (hora1 * HOR_A_MIN + minuto1) * MIN_A_SEG + segundo1;
	instante2 = (hora2 * HOR_A_MIN + minuto2) * MIN_A_SEG + segundo2;
	segundos_entre_instantes = instante2 - instante1;

	std::cout << "Han pasado " << segundos_entre_instantes << " segundos."
	          << std::endl;

	return 0;
}
