#ifndef PRACTICAS_LUZPOSICIONAL
#define PRACTICAS_LUZPOSICIONAL

#include "luz.hpp"
#include "tuplasg.hpp"

class LuzPosicional : public Luz
{
private:

public:
	LuzPosicional (
		const GLenum id_nuevo,
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp,
		const Tupla3f & posicion
	) noexcept;
};

#endif
