#include "modelos/flor.hpp"

Flor :: Flor (const int x, const int y) noexcept
:
	pos_x   (x),
	pos_y   (y),
	petalos (new PetalosFlor()),
	tallo   (new TalloFlor())
{ }

Flor :: ~Flor () noexcept
{
	delete petalos;
	delete tallo;
}

void Flor :: AplicarMaterial (Material * m_petalos, Material * m_tallo) noexcept
{
	petalos->AplicarMaterial(m_petalos);
	tallo->AplicarMaterial(m_tallo);
}

void Flor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion
) noexcept
{
	glPushMatrix();
	{
		tallo->Dibujar(dibujado, ajedrez, color, seleccion,  1);
		tallo->Dibujar(dibujado, ajedrez, color, seleccion, -1);
		glTranslatef(0, 5.0f, 0);

		petalos->Dibujar(dibujado, ajedrez, color, seleccion,  1);
		petalos->Dibujar(dibujado, ajedrez, color, seleccion, -1);
	}
	glPopMatrix();

}

int Flor :: PosX () const noexcept
{
	return pos_x;
}

int Flor :: PosY () const noexcept
{
	return pos_y;
}
