#include <iostream>
#include <list>
#include <string>
#include "diccionario.hpp"


/*Recorre la lista de información asociada a una clave y la imprime*/
void imprime_def (const std::list<std::string> & l) {
	std::list<std::string>::const_iterator it;

	for (it=l.begin(); it!=l.end(); ++it)
		std::cout << *it << std::endl;
}


/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main () {
	Diccionario<std::string,std::string> dic;
	std::string palabra;
	std::list<std::string>definiciones;

	std::cin  >> dic;
	std::cout << dic;


	std::cout << "Introduzca una palabra: ";
	std::cin  >> palabra;

	definiciones = dic.definiciones(palabra);

	if (definiciones.size() > 0)
		imprime_def (definiciones);
}

