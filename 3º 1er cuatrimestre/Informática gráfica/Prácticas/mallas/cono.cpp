/** @file mallas/cono.cpp
 */

#include "cono.hpp"

/**
 * @brief Constructor con argumentos.
 * @param radio Radio del cono.
 * @param altura Altura del cono.
 * @param divisiones Factor de definición del perfil del cono.
 * @param iteraciones Factor de definición del cono al revolucionarse.
 */

Cono :: Cono (
	const float radio,
	const float altura,
	const size_t divisiones,
	const size_t iteraciones
) noexcept
{
	const float despl = altura/divisiones;
	const float base  = -despl * (divisiones / 2.0);

	perfil.resize(divisiones);

	for (size_t i = 0; i < divisiones; i++)
		perfil[i] = {(radio / divisiones) * (divisiones-i-1), base + despl * i, 0};

	Revolucionar(iteraciones);
}
