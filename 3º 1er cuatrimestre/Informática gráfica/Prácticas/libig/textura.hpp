#include <string>
#include <vector>
#include "motor.hpp"

class Textura
{
private:
	GLuint textura_id = 0;
	int altura;
	int anchura;
	std::vector<unsigned char> datos;

public:
	Textura (std::string ruta);

	void Activar ();
};
