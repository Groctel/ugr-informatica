#include <iostream>

int main ()
{
	int salario_base;
	int salario_final;
	int incremento;

	salario_base = 1000;
	incremento   = 200;

	salario_final = salario_base;
	salario_final = salario_final + incremento;

	salario_base = 3500;

	std::cout << "Salario base: "  << salario_base  << std::endl;
	std::cout << "Salario final: " << salario_final << std::endl;

	return 0;
}
