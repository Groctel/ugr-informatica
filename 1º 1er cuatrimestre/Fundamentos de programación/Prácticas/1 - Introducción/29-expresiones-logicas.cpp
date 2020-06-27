#include <iostream>

int main () {
	bool es_bisiesto = false,
	     es_de_1_a_100 = false,
	     es_inactivo = false,
	     es_minuscula = false;
	char letra;
	int adivine,
	    anio,
	    edad;

	std::cout << "Introduzca una letra, una edad, un número y un año: ";
	std::cin >> letra >> edad >> adivine >> anio;

	es_minuscula  = 'a' <= letra && letra <= 'z';
	es_inactivo   = edad < 18 || 65 < edad;
	es_de_1_a_100 = 1 <= adivine && adivine <= 100;
	es_bisiesto   = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

	std::cout << "Es minúscula:  " << es_minuscula << std::endl
	          << "Es inavtivo:   " << es_inactivo << std::endl
	          << "Es de 1 a 100: " << es_de_1_a_100 << std::endl
	          << "Es bisiesto:   " << es_bisiesto << std::endl;

	return 0;
}
