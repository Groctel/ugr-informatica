#include <cmath>
#include <iostream>

int main () {
	double valor_inicial,
	       valor_final,
	       var_porcentual;

	std::cout << "Introduzca el valor inicial y final separados por espacios: ";
	std::cin  >> valor_inicial >> valor_final;

	var_porcentual = abs(100 * ((valor_final - valor_inicial) / valor_inicial));

	std::cout << "Entre sus dos valores hay una variación porcentual del "
	          << var_porcentual << "%." << std::endl;

	return 0;
}
