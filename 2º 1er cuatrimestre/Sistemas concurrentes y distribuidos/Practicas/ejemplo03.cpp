#include <iostream>
#include <future>

// variables globales donde se escriben los resultados
long resultado1,
     resultado2;

// declaración de la función {\bf factorial} (parámetro {\bf int}, resultado {\bf long})
long Factorial (int n) {
	return n > 0 ? n * Factorial(n-1) : 1;
}

// funciones que ejecutan las hebras
void FuncionHebra1 (int n) {
	resultado1 = Factorial(n);
}

void FuncionHebra2 (int n) {
	resultado2 = Factorial(n);
}

int main () {
	// iniciar las hebras
	std::thread hebra1(FuncionHebra1, 5),  // calcula Factorial(5) en resultado1
	            hebra2(FuncionHebra2, 10); // calcula Factorial(10) en resultado2

	// esperar a que terminen las hebras,
	hebra1.join();
	hebra2.join();

	// imprimir los resultads:
	std::cout << "factorial(5)  == " << resultado1 << std::endl
	          << "factorial(10) == " << resultado2 << std::endl;
}
