#ifndef PRACTICAS_FLOR_PETALOS
#define PRACTICAS_FLOR_PETALOS

#include "objply.hpp"

class PetalosFlor
{
private:
	static ObjPLY * petalos_frontales;
	static ObjPLY * petalos_traseros;

public:
	 PetalosFlor () noexcept;
	~PetalosFlor () noexcept;

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

