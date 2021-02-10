/** @file libig/textura.hpp
 */

#include <string>
#include <vector>
#include "enum.hpp"
#include "libjpg/jpg_imagen.hpp"
#include "motor.hpp"

#define nulltxr ~0

/** @class Textura
 *
 * @brief Imagen fija colocada sobre una Malla3D para darle realismo.
 */

class Textura
{
private:
	GLuint id         = nulltxr;
	GLenum filtro_min = GL_NEAREST;
	GLenum filtro_max = GL_NEAREST;
	unsigned long altura;
	unsigned long anchura;
	std::vector<jpg::color_pixel> pixeles;

public:
	Textura (
		const std::string & ruta,
		GLenum min=GL_NEAREST,
		GLenum max=GL_NEAREST
	) noexcept;

	void Activar () noexcept;
};
