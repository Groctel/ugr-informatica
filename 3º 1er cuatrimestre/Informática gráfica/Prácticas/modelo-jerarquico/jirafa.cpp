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
		glScalef(0.75, 1, 1.625);
		tronco_inferior->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(0.25, 1.75, .25);
		patas->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();
}

Jirafa :: ~Jirafa () noexcept
{
	delete tronco_inferior;
	delete patas;
}
