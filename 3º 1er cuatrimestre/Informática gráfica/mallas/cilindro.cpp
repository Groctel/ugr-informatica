/** @file mallas/cilindro.cpp
 */

#include "cilindro.hpp"

/**
 * @brief Constructor con argumentos.
 * @param radio Radio del cilindro.
 * @param altura Altura del cilindro.
 * @param divisiones Factor de definición del perfil del cilindro.
 * @param iteraciones Factor de definición del cilindro al revolucionarse.
 */

Cilindro :: Cilindro (
	const float radio,
	const float altura,
	const size_t divisiones,
	const size_t iteraciones
) noexcept
{
	const float despl = altura/divisiones;
	const float base  = -(despl * (divisiones / 2.0));

	perfil.resize(divisiones);

	for (size_t i = 0; i < divisiones; i++)
		perfil[i] = {radio, base + despl * i, 0};

	Revolucionar(iteraciones);
}
