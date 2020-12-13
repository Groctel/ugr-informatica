#include "cilindro.hpp"

Cilindro :: Cilindro (
	const float radio,
	const float altura,
	const size_t divisiones,
	const size_t iteraciones
) {
	nombre            = "Cilindro";
	const float despl = altura/divisiones;
	const float base  = -(despl * (divisiones / 2.0));

	perfil.resize(divisiones);

	for (size_t i = 0; i < divisiones; i++)
		perfil[i] = {radio, base + despl * i, 0};

	EliminarTapas();
	Revolucionar(iteraciones, Tapas::Ambas, true);
}
