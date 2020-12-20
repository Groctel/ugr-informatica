#include "luz_direccional.hpp"

LuzDireccional :: LuzDireccional (
	const GLenum id_nuevo,
	const Tupla4f & amb,
	const Tupla4f & dif,
	const Tupla4f & esp,
	const Tupla3f & direccion
) noexcept
:
	Luz(id_nuevo, amb, dif, esp, {direccion[X], direccion[Y], direccion[Z], 0}),
	posicion_original({direccion[X], direccion[Y], direccion[Z], 0})
{
	rotacion_x = atanf(
		(sqrt(direccion[X] * direccion[X] + direccion[Y] * direccion[Y]))
		/ direccion[Y]
	);
	rotacion_y = atanf(direccion[X] / direccion[Y]);
}

void LuzDireccional :: VariarRotX (const float incremento) noexcept
{
	rotacion_x = std::fmod(rotacion_x + incremento, 2.0f * M_PI);

	posicion[X] = sin(rotacion_x) * cos(rotacion_y)
		* sqrt(posicion_original | posicion_original);

	posicion[Y] = sin(rotacion_y)
		* sqrt(posicion_original | posicion_original);

	posicion[Z] = cos(rotacion_x) * cos(rotacion_y)
		* sqrt(posicion_original | posicion_original);
}

void LuzDireccional :: VariarRotY (const float incremento) noexcept
{
	rotacion_y += incremento;

	if (rotacion_y > M_PI / 4.0f)
	{
		rotacion_y = M_PI / 4.0f;
	}
	else if (rotacion_y < -(M_PI / 4.0f))
	{
		rotacion_y = -(M_PI / 4.0f);
	}

	posicion[X] = sin(rotacion_x) * cos(rotacion_y)
		* sqrt(posicion_original | posicion_original);

	posicion[Y] = sin(rotacion_y)
		* sqrt(posicion_original | posicion_original);

	posicion[Z] = cos(rotacion_y) * cos(rotacion_x)
		* sqrt(posicion_original | posicion_original);
}
