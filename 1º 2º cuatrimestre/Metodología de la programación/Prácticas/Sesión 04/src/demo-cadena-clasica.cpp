#include <iostream>
#include "mi-cadena-clasica.hpp"

const unsigned LONG_CADENA = 10000;

int main () {
	int  lon, pos;
	char cadena1[LONG_CADENA],
	     cadena2[LONG_CADENA];

	std::cout << "Introduzca una cadena de caracteres:" << std::endl
	          << ">";

	std::cin.getline(cadena1, LONG_CADENA);

	std::cout << std::endl << "Su cadena contiene " << LongitudCadena(cadena1)
	          << " caracteres y " << (Palindromo(cadena1) ? "" : "no ")
	          << "es un palíndromo." << std::endl << std::endl
	          << "Introduzca otra cadena de caracteres:" << std::endl << ">";

	std::cin.getline(cadena2, LONG_CADENA);

	std::cout << "La diferencia entre ambas cadenas es de "
	          << CompararCadenas(cadena1, cadena2) << std::endl

	          << "Primera cadena encadenada con la segunda: \""
	          << EncadenarCadena(cadena2, cadena1) << "\"" <<  std::endl

	          << "Copia de la primera cadena: \""
	          << CopiarCadena(cadena2, cadena1) << "\"" << std::endl

	          << "Primera cadena sin los espacios inciales: \""
	          << EliminaBlancosIniciales(cadena2, cadena1) << "\"" <<  std::endl

	          << "Primera cadena sin los espacios finales: \""
	          << EliminaBlancosFinales(cadena2, cadena1) << "\"" <<  std::endl

	          << "Primera cadena sin los espacios extremos: \""
	          << EliminaBlancosExtremos(cadena2, cadena1) << "\"" <<  std::endl

	          << "Primera cadena sin los espacios intermedios: \""
	          << EliminaBlancosIntermedios(cadena2, cadena1) << "\"" << std::endl

	          << "Primera cadena sin ninguno de los espacios: \""
	          << EliminaTodosBlancos(cadena2, cadena1) << "\"" <<  std::endl

	          << "Primera cadena encadenada invertida: \""
	          << Invertir(cadena2, cadena1) << "\"" <<  std::endl;

	std::cout << "Introduzca una posición de la primera cadena: ";
	std::cin  >> pos;
	std::cout << "Introduzca una longitud para la subcadena: ";
	std::cin  >> lon;

	std::cout << "Subcadena de la primera cadena: \""
	          << Subcadena(cadena2, cadena1, pos, lon) << "\"" << std::endl;

	return 0;
}
