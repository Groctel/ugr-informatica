/** @file mallas/esfera.cpp
 */

#include "esfera.hpp"

/**
 * @brief Constructor con argumentos.
 * @param radio Radio de la esfera.
 * @param iteraciones Factor de definición de la esfera al revolucionarse.
 */

Esfera :: Esfera (const float radio, const size_t iteraciones) noexcept
{
	perfil.resize(iteraciones);

	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (M_PI * i) / iteraciones - (M_PI / 2);

		perfil[i] = {
			(float) cos(angulo) * radio,
			(float) sin(angulo) * radio,
			(float) 0
		};
	}

	Revolucionar(iteraciones);
}
