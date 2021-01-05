#include "modelo-jerarquico/jirafa.hpp"

Jirafa :: Jirafa () noexcept
:
	tronco_inferior (new Cubo()),
	patas           (new PatasJirafa())
{ }

void Jirafa :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color
) noexcept
{
	glPushMatrix();
	{
		glScalef(0.75f, 1.0f, 1.625f);
		tronco_inferior->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(0.25f, 1.75f, .25f);
		glTranslatef(0.0f, -1.5f, 0.0f);
		patas->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();
}

Jirafa :: ~Jirafa () noexcept
{
	delete tronco_inferior;
	delete patas;
}
