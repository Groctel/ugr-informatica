#include "material.hpp"

Material :: Material ()
:
	ambiente  ({0.2f, 0.2f, 0.2f, 1.0f}),
	difuso    ({0.8f, 0.8f, 0.8f, 1.0f}),
	especular ({0.0f, 0.0f, 0.0f, 1.0f}),
	brillo    (0.5f)
{ }

Material :: Material (
	const Tupla4f & amb,
	const Tupla4f & dif,
	const Tupla4f & esp,
	const float bri
) noexcept
:
	ambiente  (amb),
	difuso    (dif),
	especular (esp),
	brillo    (bri)
{
	ambiente[3] = difuso[3] = especular[3] = 1.0f;
}

void Material :: Aplicar () noexcept
{
	glMaterialfv(GL_FRONT, GL_AMBIENT,   ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   difuso);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  especular);
	glMaterialf (GL_FRONT, GL_SHININESS, brillo);

	glColorMaterial(GL_FRONT, GL_EMISSION);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glColorMaterial(GL_FRONT, GL_SPECULAR);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}
