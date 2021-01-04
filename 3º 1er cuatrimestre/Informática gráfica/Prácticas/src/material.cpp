#include "material.hpp"

Material :: Material ()
{ }

Material :: Material (
	const Tupla3f & amb,
	const Tupla3f & dif,
	const Tupla3f & esp,
	const float bri
) noexcept
:
	ambiente  ({amb[X], amb[Y], amb[Z], 1.0f}),
	difuso    ({dif[X], dif[Y], dif[Z], 1.0f}),
	especular ({esp[X], esp[Y], esp[Z], 1.0f}),
	brillo    (bri)
{ }

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
