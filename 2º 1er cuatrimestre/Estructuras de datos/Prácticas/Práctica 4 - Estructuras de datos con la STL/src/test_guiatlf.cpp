#include "guiatlf.hpp"
#include <fstream>
#include <limits>

int main (int argc , char** argv) {
	if (argc!=2) {
		std::cout << "Dime el nombre del fichero con la guia" << std::endl;
		return 1;
	}

	std::ifstream fi(argv[1]);

	if (!fi) {
		std::cout << "No puedo abrir el fichero " << argv[1] << std::endl;
		return 1;
	}

	GuiaTlf guia, otra_guia, union_guias, diferencia_guias, guia_previos;
	std::string nombre, tlf;
	GuiaTlf::iterator it;

	fi >> guia;

	std::cout << "Se ha insertado la siguiente guía: " << std::endl << std::endl
	          << guia << std::endl;

	std::cout << "Dime un nombre sobre el que quieres obtener el telefono: ";

	getline(std::cin, nombre);

	std::cout << std::endl << "Buscando \"" << nombre <<"\"..." << std::endl;
	tlf = guia.get_tlf(nombre);

	if (tlf == "")
		std::cout << "No existe ningún contacto llamado \"" << nombre
		          << "\" en esta guía." << std::endl;
	else
		std::cout << "El teléfono de " << nombre << " es el " << tlf
		          << "." << std::endl;

	std::cout << "Dime un nombre que quieras eliminar de la guía: ";

	getline(std::cin, nombre);
	guia.borrar(nombre);

	std::cout << "Ahora la guía es: " << std::endl
	          << guia << std::endl
	          << "[^D para saltar] "
	          << "Introduce los datos de una segunda guía:" << std::endl;

	std::cin >> otra_guia;
	std::cin.clear();

	union_guias = guia + otra_guia;
	diferencia_guias = guia - otra_guia;

	std::cout << "La unión de las dos guías es la siguiente:" << std::endl
	          << union_guias << std::endl
	          << "La diferencia de las dos guías es la siguiente:" << std::endl
	          << diferencia_guias << std::endl << std::endl
	          << "Dime un nombre para establecer los previos";
	std::cin >> nombre;

	tlf = guia.get_tlf(nombre);
	guia_previos = guia.previos(nombre, tlf);

	std::cout << "Los nombre previos son los siguientes:" << std::endl
	          << guia_previos << std::endl
	          << "Listando la guía con iteradores:" << std::endl;

	/*for (it=guia.begin(); it!=guia.end(); ++it)
		std::cout << *it << std::endl;*/
}

