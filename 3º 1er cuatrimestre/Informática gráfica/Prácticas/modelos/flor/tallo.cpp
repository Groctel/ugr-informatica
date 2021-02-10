#include "modelos/flor/tallo.hpp"

ObjPLY * TalloFlor :: tallo = nullptr;

TalloFlor :: TalloFlor () noexcept
{
	if (tallo == nullptr)
		tallo = new ObjPLY("plys/flor/tallo.ply");
}

TalloFlor :: ~TalloFlor () noexcept
{
	if (tallo != nullptr)
	{
		delete tallo;
		tallo = nullptr;
	}
}

void TalloFlor :: AplicarMaterial (Material * nuevo) noexcept
{
	tallo->AplicarMaterial(nuevo);
}

void TalloFlor :: Dibujar (
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
		/* glScalef(1, 5, 0.001); */
		tallo->Dibujar(dibujado, ajedrez, color, seleccion);
	}
	glPopMatrix();
}
