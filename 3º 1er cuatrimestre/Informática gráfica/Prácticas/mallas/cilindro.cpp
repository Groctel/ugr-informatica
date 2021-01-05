#include "cilindro.hpp"

Cilindro :: Cilindro (
	const float radio,
	const float altura,
	const size_t divisiones,
	const size_t iteraciones
) noexcept
{
	const float despl = altura/divisiones;
	const float base  = -(despl * (divisiones / 2.0));

	std::vector<Tupla3f> perfil(divisiones);

	for (size_t i = 0; i < divisiones; i++)
		perfil[i] = {radio, base + despl * i, 0};

	Revolucionar(perfil, iteraciones);
}
