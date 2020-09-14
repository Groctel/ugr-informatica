#include <iostream>
#include <future>

long Factorial (int n) {
	return n > 0 ? n * Factorial(n-1) : 1;
}

int main () {
	// iniciar las hebras y obtener los objetos {\bf future} (conteniendo un {\bf long})
	// (el valor {\bf launch:async} indica que se debe usar una hebra concurrente
	// para evaluar la función):
	std::future<long> futuro1 = std::async(std::launch::async, Factorial, 5),
	                  futuro2 = std::async(std::launch::async, Factorial, 10);

	// esperar a que terminen las hebras, obtener resultado e imprimirlos
	std::cout << "factorial(5)  = " << futuro1.get() << std::endl
	          << "factorial(10) = " << futuro2.get() << std::endl;
}
