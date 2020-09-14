#include <iostream>
#include <thread>

// función que va a ejecutar la hebra primera
void FuncionHebra1 () {
	for (unsigned i=0; i<5000; i++)
		std::cout << "Hebra 1, i = " << i << std::endl << std::flush;
}

// función que va a ejecutar la hebra segunda
void FuncionHebra2 () {
	for (unsigned i=0; i<5000; i++)
		std::cout << "Hebra 2, i = " << i << std::endl << std::flush;
}

int main () {
	std::thread hebra1(FuncionHebra1),
	            hebra2(FuncionHebra2);

  // finalización errónea: se destruyen los objetos hebra y acaba
  // la hebra principal, posiblemente antes de que acaben las hebras en ejecución
}
