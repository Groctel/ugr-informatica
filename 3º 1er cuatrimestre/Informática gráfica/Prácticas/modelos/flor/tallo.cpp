#include "modelos/flor/tallo.hpp"

ObjPLY * TalloFlor :: tallo_frontal = nullptr;
ObjPLY * TalloFlor :: tallo_trasero = nullptr;

TalloFlor :: TalloFlor () noexcept
{
	if (tallo_frontal == nullptr)
		tallo_frontal = new ObjPLY("plys/flor/tallo_frontal.ply");

	if (tallo_trasero == nullptr)
		tallo_trasero = new ObjPLY("plys/flor/tallo_trasero.ply");
}

TalloFlor :: ~TalloFlor () noexcept
{
	if (tallo_frontal != nullptr)
	{
		delete tallo_frontal;
		tallo_frontal = nullptr;
	}

	if (tallo_trasero != nullptr)
	{
		delete tallo_trasero;
		tallo_trasero = nullptr;
	}
}

void TalloFlor :: AplicarMaterial (Material * nuevo) noexcept
{
	tallo_frontal->AplicarMaterial(nuevo);
	tallo_trasero->AplicarMaterial(nuevo);
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
		tallo_frontal->Dibujar(dibujado, ajedrez, color, seleccion);
		glRotatef(180.0f, 0, 1.0f, 0);
		tallo_trasero->Dibujar(dibujado, ajedrez, color, seleccion);
	}
	glPopMatrix();
}
