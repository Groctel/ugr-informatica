#ifndef PRACTICAS_ARAXXOR_ABDOMEN
#define PRACTICAS_ARAXXOR_ABDOMEN

#include "objply.hpp"

class AbdomenAraxxor
{
private:
	ObjPLY * abdomen;

	float rotacion = 0;

public:
	 AbdomenAraxxor () noexcept;
	~AbdomenAraxxor () noexcept;

	Malla3D * Cuerpo () const noexcept;

	void AplicarMaterial (Material * m) noexcept;
	void AplicarTextura  (Textura * nueva, const bool calcular) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false
	) noexcept;

	void NuevoColorSeleccion (const Tupla3f & color) noexcept;

	void Mover (const float grados) noexcept;
};

#endif
