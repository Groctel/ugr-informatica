#include "modelo-jerarquico/jirafa.hpp"

Jirafa :: Jirafa () noexcept
:
	tronco_inferior (new Cubo()),
	patas           (new PatasJirafa()),
	tronco_superior (new TroncoSuperiorJirafa())
{ }

void Jirafa :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color
) noexcept
{
	glPushMatrix();
	{
		glScalef(12.0f, 16.0f, 26.0f);
		tronco_inferior->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(4.0f, 27.0f, 4.0f);
		glTranslatef(0.0f, -1.4f, 0.0f);
		patas->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0f, 0.0f, 14.0f);
		tronco_superior->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();
}

Jirafa :: ~Jirafa () noexcept
{
	delete patas;
	delete tronco_inferior;
	delete tronco_superior;
}
