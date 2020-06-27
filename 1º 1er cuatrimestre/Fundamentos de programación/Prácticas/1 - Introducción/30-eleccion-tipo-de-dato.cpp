#include <iostream>

enum class EstadoCivil {
	casado,
	separado,
	soltero,
	viudo
};

int main () {
	const int EDAD = 20;
	const double PIB  = 1166.3;
	const bool ES_PRIMO  = true,
	           ES_HOMBRE = false;

	std::cout << "Para la edad hemos usado un 'int': " << EDAD << std::endl
	          << "Para el pib hemos usado un 'double': " << PIB << std::endl
	          << "Para la primalidad hemos usado un 'bool': " << ES_PRIMO
	          << std::endl
	          << "Para el sexo también hemos usado un 'bool': " << ES_HOMBRE
	          << std::endl
	          << "Para el estado civil hemos usado un 'enum', pero no podemos "
	          << "mostrarlo porque C++ no permite extraer el texto que compone "
	          << "cada uno de sus elementos por la salida estándar" << std::endl;

	return 0;
}
