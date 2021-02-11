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

void ColmilloAraxxor :: AplicarTextura  (Textura * nueva) noexcept
{
	colmillo->AplicarTextura(nueva);
}

void ColmilloAraxxor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion,
	const bool marcado
) noexcept
{
	colmillo->Dibujar(dibujado, ajedrez, color, seleccion, marcado);
}

void ColmilloAraxxor :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	colmillo->NuevoColorSeleccion(color);
}

