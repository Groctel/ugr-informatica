#ifndef PRACTICAS_FLOR_TALLO
#define PRACTICAS_FLOR_TALLO

#include "objply.hpp"

class TalloFlor
{
private:
	static ObjPLY * tallo;

public:
	 TalloFlor () noexcept;
	~TalloFlor () noexcept;

	void AplicarMaterial (Material * nuevo) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez,
		const unsigned char color,
		const bool seleccion,
		const int espejo
	) noexcept;
};

#endif
