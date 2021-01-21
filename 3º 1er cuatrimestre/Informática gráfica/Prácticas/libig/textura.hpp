#include <string>
#include <vector>
#include "libjpg/jpg_imagen.hpp"
#include "motor.hpp"

class Textura
{
private:
	GLuint id;
	unsigned long altura;
	unsigned long anchura;
	std::vector<jpg::pixel> datos;

public:
	Textura (const std::string  & ruta) noexcept;

	void Activar () noexcept;
};
