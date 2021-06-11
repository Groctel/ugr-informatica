#include "modelos/flor/petalos.hpp"

ObjPLY * PetalosFlor :: petalos_frontales = nullptr;
ObjPLY * PetalosFlor :: petalos_traseros = nullptr;

PetalosFlor :: PetalosFlor () noexcept
{
	if (petalos_frontales == nullptr)
		petalos_frontales = new ObjPLY("plys/flor/petalos_frontales.ply");

	if (petalos_traseros == nullptr)
		petalos_traseros = new ObjPLY("plys/flor/petalos_traseros.ply");
}

PetalosFlor :: ~PetalosFlor () noexcept
{
	if (petalos_frontales != nullptr)
	{
		delete petalos_frontales;
		petalos_frontales = nullptr;
	}

	if (petalos_traseros != nullptr)
	{
		delete petalos_traseros;
		petalos_traseros = nullptr;
	}
}

void PetalosFlor :: AplicarMaterial (Material * nuevo) noexcept
{
	petalos_frontales->AplicarMaterial(nuevo);
	petalos_traseros->AplicarMaterial(nuevo);
}

void PetalosFlor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion,
	const int espejo
) noexcept
{
	glPushMatrix();
	{
		glRotatef(espejo * 45.0f, 0.0f, 1.0f, 0.0f);
		petalos_frontales->Dibujar(dibujado, ajedrez, color, seleccion);
		glRotatef(180.0f, 0, 1.0f, 0);
		petalos_traseros->Dibujar(dibujado, ajedrez, color, seleccion);
	}
	glPopMatrix();
}
