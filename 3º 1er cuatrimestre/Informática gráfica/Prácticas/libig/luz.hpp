/** @file luz.hpp
 */

#ifndef PRACTICAS_LUZ
#define PRACTICAS_LUZ

#include "global/tuplasg.hpp"
#include "motor.hpp"

/** @class Luz
 *
 * @brief Fuente de iluminación arrojable sobre los objetos de la escena.
 */

class Luz
{
protected:
	GLenum  id;
	Tupla4f color_ambiente;
	Tupla4f color_difuso;
	Tupla4f color_especular;
	Tupla4f posicion;

public:
	Luz () noexcept;
	Luz (
		const GLenum  id_nuevo,
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp,
		const Tupla4f & pos
	) noexcept;

	bool Activada () const noexcept;

	void Aplicar () noexcept;
	void Pulsar  () noexcept;
};

#endif
