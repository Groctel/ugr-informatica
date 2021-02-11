#ifndef PRACTICAS_FLOR
#define PRACTICAS_FLOR

#include "modelos/flor/petalos.hpp"
#include "modelos/flor/tallo.hpp"

class Flor
{
private:
	int pos_x;
	int pos_y;

	PetalosFlor * petalos;
	TalloFlor   * tallo;

public:
	 Flor (const int x, const int y) noexcept;
	~Flor () noexcept;

	void AplicarMaterial (Material * m_petalos, Material * m_tallo) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false
	) noexcept;

	int PosX () const noexcept;
	int PosY () const noexcept;
};

#endif
