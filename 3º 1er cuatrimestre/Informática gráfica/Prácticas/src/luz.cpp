#include "luz.hpp"

Luz :: Luz () noexcept
:
	activada (false)
{ }

Luz :: Luz (
	const GLenum  id_nuevo,
	const Tupla4f & amb,
	const Tupla4f & dif,
	const Tupla4f & esp,
	const Tupla4f & pos
) noexcept
:
	activada        (false),
	id              (id_nuevo),
	color_ambiente  (amb),
	color_difuso    (dif),
	color_especular (esp),
	posicion        (pos)
{ }

bool Luz :: Activada () const noexcept
{
	return activada;
}

void Luz :: Aplicar () noexcept
{
	if (activada)
	{
		glLightfv(id, GL_AMBIENT,  color_ambiente);
		glLightfv(id, GL_DIFFUSE,  color_difuso);
		glLightfv(id, GL_SPECULAR, color_especular);
		glLightfv(id, GL_POSITION, posicion);
	}
}

void Luz :: Pulsar () noexcept
{
	activada = !activada;

	if (activada)
		glEnable(id);
	else
		glDisable(id);
}
