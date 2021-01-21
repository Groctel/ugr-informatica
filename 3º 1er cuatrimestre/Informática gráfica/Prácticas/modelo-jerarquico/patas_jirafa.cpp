#include "modelo-jerarquico/patas_jirafa.hpp"

PatasJirafa :: PatasJirafa () noexcept
:
	delantera_izda (new Cubo()),
	delantera_dcha (new Cubo()),
	trasera_izda   (new Cubo()),
	trasera_dcha   (new Cubo())
{ }

void PatasJirafa :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color
) noexcept
{
	glPushMatrix();
	{
		glTranslatef(0, 0, -5);

		glPushMatrix();
		{
			glTranslatef(-1.5, 0, 0);
			delantera_izda->Dibujar(dibujado, ajedrez, color);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(1.5, 0, 0);
			delantera_dcha->Dibujar(dibujado, ajedrez, color);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0, 0, 5);

		glPushMatrix();
		{
			glTranslatef(-1.5, 0, 0);
			trasera_izda->Dibujar(dibujado, ajedrez, color);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(1.5, 0, 0);
			trasera_dcha->Dibujar(dibujado, ajedrez, color);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

PatasJirafa :: ~PatasJirafa () noexcept
{
	delete delantera_izda;
	delete delantera_dcha;
	delete trasera_izda;
	delete trasera_dcha;
}
