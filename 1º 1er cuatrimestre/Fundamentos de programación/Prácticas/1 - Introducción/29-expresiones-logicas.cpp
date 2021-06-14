#include <iostream>

int main ()
{
	char letra;
	int adivine, anio, edad;

	std::cout << "Introduzca una letra, una edad, un número y un año: ";
	std::cin  >> letra >> edad >> adivine >> anio;

	bool es_minuscula  = 'a' <= letra && letra <= 'z';
	bool es_inactivo   = edad < 18 || 65 < edad;
	bool es_de_1_a_100 = 1 <= adivine && adivine <= 100;
	bool es_bisiesto   = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

	std::cout
		<< "Es minúscula:  " << es_minuscula  << std::endl
		<< "Es inavtivo:   " << es_inactivo   << std::endl
		<< "Es de 1 a 100: " << es_de_1_a_100 << std::endl
		<< "Es bisiesto:   " << es_bisiesto   << std::endl;

	return 0;
}
