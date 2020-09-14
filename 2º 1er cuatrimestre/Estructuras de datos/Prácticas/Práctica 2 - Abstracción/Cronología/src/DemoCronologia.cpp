#include "Cronologia.h"
#include <fstream>
#include <iostream>

int main(int argc, char * argv[]){
	if (argc!=2){
		std::cout << "Incluya un fichero \"Cronología\" como primer argumento."
		          << std::endl;
		return 2;
	}

	std::ifstream f (argv[1]);

	if (!f){
		std::cout << "No se pudo abrir el fichero " << argv[1] << std::endl;
		return 2;
	}

   Cronologia mi_cronologia;

   f >> mi_cronologia;

	std::cout << "Cronología leida del fichero \"" << std::endl << mi_cronologia
	          << "\":" << std::endl << std::endl;
}

