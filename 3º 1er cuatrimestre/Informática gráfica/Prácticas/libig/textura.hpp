/** @file libig/objply.hpp
 */

#include <string>
#include <vector>
#include "libjpg/jpg_imagen.hpp"
#include "motor.hpp"

#define nulltxr ~0

/** @enum ModoTextura
 * @brief Algoritmo a seguir a la hora de aplicar la textura a un objeto.
 */

enum ModoTextura
{
	Cilindrica,
	Esferica,
	Plana
};

/** @class Textura
 *
 * @brief Imagen fija colocada sobre una Malla3D para darle realismo.
 */

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
