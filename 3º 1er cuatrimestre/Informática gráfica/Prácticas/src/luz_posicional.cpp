#include "luz_posicional.hpp"

LuzPosicional :: LuzPosicional (
	const GLenum id_nuevo,
	const Tupla4f & amb,
	const Tupla4f & dif,
	const Tupla4f & esp,
	const Tupla3f & posicion
) noexcept
:
	Luz(id_nuevo, amb, dif, esp, {posicion[X], posicion[Y], posicion[Z], 1})
{ }
