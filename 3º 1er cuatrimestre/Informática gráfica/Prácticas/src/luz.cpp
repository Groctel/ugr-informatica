#include "luz.hpp"

Luz :: Luz () noexcept
{ }

Luz :: Luz (
	const GLenum  id_nuevo,
	const Tupla4f & amb,
	const Tupla4f & dif,
	const Tupla4f & esp,
	const Tupla4f & pos
) noexcept
:
	id              (id_nuevo),
	color_ambiente  (amb),
	color_difuso    (dif),
	color_especular (esp),
	posicion        (pos)
{ }

bool Luz :: Activada () const noexcept
{
	return glIsEnabled(id);
}

void Luz :: Aplicar () noexcept
{
	if (glIsEnabled(id))
	{
		glLightfv(id, GL_AMBIENT,  color_ambiente);
		glLightfv(id, GL_DIFFUSE,  color_difuso);
		glLightfv(id, GL_SPECULAR, color_especular);
		glLightfv(id, GL_POSITION, posicion);
	}
}

void Luz :: Pulsar () noexcept
{
	if (glIsEnabled(id))
		glDisable(id);
	else
		glEnable(id);
}
