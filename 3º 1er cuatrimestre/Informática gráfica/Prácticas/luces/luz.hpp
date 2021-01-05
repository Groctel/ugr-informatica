#ifndef PRACTICAS_LUZ
#define PRACTICAS_LUZ

#include "motor.hpp"
#include "tuplasg.hpp"

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
