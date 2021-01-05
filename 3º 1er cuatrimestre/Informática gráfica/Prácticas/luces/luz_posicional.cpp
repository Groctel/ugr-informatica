/** @file luz_posicional.cpp
 */

#include "luz_posicional.hpp"

/** @fn LuzPosicional :: LuzPosicional (
 * 	const GLenum  id_nuevo,
 * 	const Tupla4f & amb,
 * 	const Tupla4f & dif,
 * 	const Tupla4f & esp,
 * 	const Tupla4f & pos
 * ) noexcept
 *
 * @brief Constructor con argumentos.
 * @param id_nuevo Identificador de luz reconocible por OpenGL.
 * @param amb Color ambiente de la luz.
 * @param dif Color difusa de la luz.
 * @param esp Color especular de la luz.
 * @param pos Posición de la luz en la escena.
 *
 * Llama a `Luz::Luz()` de forma que el cuarto elemento de `direccion` valga
 * siempre 1.
 */

LuzPosicional :: LuzPosicional (
	const GLenum id_nuevo,
	const Tupla4f & amb,
	const Tupla4f & dif,
	const Tupla4f & esp,
	const Tupla3f & posicion
) noexcept
:
	Luz(id_nuevo, amb, dif, esp, {posicion[X], posicion[Y], posicion[Z], 1})
{ }
