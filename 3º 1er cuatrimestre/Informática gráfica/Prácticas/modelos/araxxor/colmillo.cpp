#include "modelos/araxxor/colmillo.hpp"

ColmilloAraxxor :: ColmilloAraxxor (const std::string ruta) noexcept
:
	colmillo (new ObjPLY(ruta))
{ }

ColmilloAraxxor :: ~ColmilloAraxxor () noexcept
{
	delete colmillo;
}

void ColmilloAraxxor :: AplicarMaterial (Material * m) noexcept
{
	colmillo->AplicarMaterial(m);
}

void ColmilloAraxxor :: AplicarTextura  (Textura * nueva, const bool calcular) noexcept
{
	colmillo->AplicarTextura(nueva, calcular);
}

void ColmilloAraxxor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion
) noexcept
{
	colmillo->Dibujar(dibujado, ajedrez, color, seleccion);
}

void ColmilloAraxxor :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	colmillo->NuevoColorSeleccion(color);
}

