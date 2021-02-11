/** @file luz.cpp
 */

#include "luz.hpp"

/**
 * @brief Constructor con argumentos.
 * @param id_nuevo Identificador de luz reconocible por OpenGL.
 * @param amb Color ambiente de la luz.
 * @param dif Color difusa de la luz.
 * @param esp Color especular de la luz.
 * @param pos Posición de la luz en la escena.
 */

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

/**
 * @brief Constructor por defecto necesario para las clases descendientes.
 */

Luz :: Luz () noexcept
{ }

/**
 * @brief Consultor del estado de activación de la luz.
 */

bool Luz :: Activada () const noexcept
{
	return glIsEnabled(id);
}

/**
 * @brief Hace incidir la luz sobre los objetos de la escena.
 *
 * Para que la luz se aplique sobre los objetos, se debe activar previamente
 * mediante la función `Pulsar()`.
 */

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

/**
 * @brief Modificador del estado de activación de la luz.
 *
 * Cada llamada invierte el bit de estado de la luz de OpenGL, de forma que
 * llamar a esta función es análogo a utilizar un interruptor de encendido y
 * apagado.
 */

void Luz :: Pulsar () noexcept
{
	if (glIsEnabled(id))
		glDisable(id);
	else
		glEnable(id);
}
