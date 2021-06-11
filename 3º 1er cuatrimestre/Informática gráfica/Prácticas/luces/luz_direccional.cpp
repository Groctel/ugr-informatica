/** @file luz_direccional.cpp
 */

#include "luz_direccional.hpp"

/**
 * @brief Constructor con argumentos.
 * @param id_nuevo Identificador de luz reconocible por OpenGL.
 * @param amb Color ambiente de la luz.
 * @param dif Color difusa de la luz.
 * @param esp Color especular de la luz.
 * @param pos Posición de la luz en la escena.
 *
 * Llama a `Luz::Luz()` de forma que el cuarto elemento de `direccion` valga
 * siempre 0.
 */

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
	rotacion_x = fabs(atan2f(direccion[X], direccion[Z]));
	rotacion_y = asin(direccion[Y] / sqrt(direccion | direccion));

	if (direccion[X] < 0)
		rotacion_x += M_PI;
}

/**
 * @brief Modifica la rotación alrededor del eje x (ángulo alfa).
 * @param incremento Factor de rotación.
 */

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

/**
 * @brief Modifica la rotación alrededor del eje y (ángulo beta).
 * @param incremento Factor de rotación.
 */

void LuzDireccional :: VariarRotY (const float incremento) noexcept
{
	rotacion_y += incremento;

	if (rotacion_y > M_PI / 2.0f)
	{
		rotacion_y = M_PI / 2.0f;
	}
	else if (rotacion_y < -(M_PI / 2.0f))
	{
		rotacion_y = -(M_PI / 2.0f);
	}

	posicion[X] = sin(rotacion_x) * cos(rotacion_y)
		* sqrt(posicion_original | posicion_original);

	posicion[Y] = sin(rotacion_y)
		* sqrt(posicion_original | posicion_original);

	posicion[Z] = cos(rotacion_y) * cos(rotacion_x)
		* sqrt(posicion_original | posicion_original);
}
