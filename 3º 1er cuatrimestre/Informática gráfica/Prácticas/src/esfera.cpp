#include "esfera.hpp"

Esfera :: Esfera (const float radio, const size_t iteraciones) noexcept
{
	std::vector<Tupla3f> perfil(iteraciones);

	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (M_PI * i) / iteraciones - (M_PI / 2);

		perfil[i] = {
			(float) cos(angulo) * radio,
			(float) sin(angulo) * radio,
			(float) 0
		};
	}

	Revolucionar(perfil, iteraciones);
}
