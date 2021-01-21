/** @file luz_posicional.hpp
 */

#ifndef PRACTICAS_LUZPOSICIONAL
#define PRACTICAS_LUZPOSICIONAL

#include "global/tuplasg.hpp"
#include "luz.hpp"

/** @class LuzPosicional
 *
 * @brief Luz situada en un punto de la escena.
 */

class LuzPosicional : public Luz
{
private:

public:
	LuzPosicional (
		const GLenum  id_nuevo,
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp,
		const Tupla3f & posicion
	) noexcept;
};

#endif
