#include <iostream>
#include <future>

long Factorial (int n) {
	return n > 0 ? n * Factorial(n-1) : 1;
}

// función que ejecutan las hebras
void FuncionHebra (int n, long & resultado) {
	resultado = Factorial(n);
}

int main () {
	long resultado1,
	     resultado2; // variables (locales) con los resultados

	// iniciar las hebras (los parámetros por referencia se ponen con 'ref')
	std::thread hebra1(FuncionHebra, 5,  std::ref(resultado1)),
	            hebra2(FuncionHebra, 10, std::ref(resultado2));

	// esperar a que terminen las hebras, y escriban en resultado1 y resultado2
	hebra1.join();
	hebra2.join();

	// imprimir los resultads:
	std::cout << "Factorial(5)  = " << resultado1 << std::endl
	          << "Factorial(10) = " << resultado2 << std::endl;
}
