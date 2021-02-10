#include "modelos/flor/petalos.hpp"

ObjPLY * PetalosFlor :: petalos = nullptr;

PetalosFlor :: PetalosFlor () noexcept
{
	if (petalos == nullptr)
		petalos = new ObjPLY("plys/flor/petalos.ply");
}

PetalosFlor :: ~PetalosFlor () noexcept
{
	if (petalos != nullptr)
	{
		delete petalos;
		petalos = nullptr;
	}
}

void PetalosFlor :: AplicarMaterial (Material * nuevo) noexcept
{
	petalos->AplicarMaterial(nuevo);
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
		/* glScalef(4, 2, 0.001); */
		petalos->Dibujar(dibujado, ajedrez, color, seleccion);
	}
	glPopMatrix();
}
