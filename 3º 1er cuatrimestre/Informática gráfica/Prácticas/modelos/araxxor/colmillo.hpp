#ifndef PRACTICAS_ARAXXOR_COLMILLO
#define PRACTICAS_ARAXXOR_COLMILLO

#include <string>
#include "objply.hpp"

class ColmilloAraxxor
{
private:
	ObjPLY * colmillo;

public:
	 ColmilloAraxxor (const std::string ruta) noexcept;
	~ColmilloAraxxor () noexcept;

	void AplicarMaterial (Material * m) noexcept;
	void AplicarTextura  (Textura * nueva, const bool calcular) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false
	) noexcept;

	void NuevoColorSeleccion (const Tupla3f & color) noexcept;
};

#endif



