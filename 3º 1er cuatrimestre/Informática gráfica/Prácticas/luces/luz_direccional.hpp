/** @file luz_direccional.hpp
 */

#ifndef PRACTICAS_LUZDIRECCIONAL
#define PRACTICAS_LUZDIRECCIONAL

#include "luces/luz.hpp"
#include "tuplasg.hpp"

/** @class LuzDireccional
 *
 * @brief Luz situada en el infinito que incide en una dirección sobre los
 * objetos de la escena.
 */

class LuzDireccional : public Luz
{
private:
	float rotacion_x;
	float rotacion_y;
	Tupla4f posicion_original;

public:
	LuzDireccional (
		const GLenum  id_nuevo,
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp,
		const Tupla3f & direccion
	) noexcept;

	void VariarRotX (const float incremento) noexcept;
	void VariarRotY (const float incremento) noexcept;
};

#endif
