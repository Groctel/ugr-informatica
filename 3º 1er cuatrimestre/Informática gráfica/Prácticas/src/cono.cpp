#include "cono.hpp"

Cono :: Cono (
	const float radio,
	const float altura,
	const size_t divisiones,
	const size_t iteraciones
) noexcept
{
	nombre = "Cono";

	const float despl = altura/divisiones;
	const float base  = -despl * (divisiones / 2.0);

	perfil.resize(divisiones);

	for (size_t i = 0; i < divisiones; i++)
		perfil[i] = {(radio / divisiones) * (divisiones-i-1), base + despl * i, 0};

	EliminarTapas();
	Revolucionar(iteraciones, Tapas::Ambas, true);
}
