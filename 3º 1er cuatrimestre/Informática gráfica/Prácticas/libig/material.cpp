/** @file libig/material.cpp
 */

#include "material.hpp"

/**
 * @brief Constructor con argumentos.
 * @param amb Color del reflejo para la luz ambiente.
 * @param dif Color del reflejo para la luz difusa.
 * @param esp Color del reflejo para la luz especular.
 * @param bri Factor de brillo del material.
 */

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
{ }

/**
 * @brief Aplicador del material sobre la Malla3D en la que se encuentra.
 */

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
