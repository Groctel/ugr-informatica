#include "modelo-jerarquico/tronco_superior.hpp"

TroncoSuperiorJirafa :: TroncoSuperiorJirafa ()
:
	cabeza      (new CabezaJirafa()),
	base_cuello (new Cubo()),
	cuello      (new Cubo())
{ }

TroncoSuperiorJirafa :: ~TroncoSuperiorJirafa ()
{
	delete cabeza;
	delete cuello;
}

void TroncoSuperiorJirafa :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color
) noexcept
{
	glPushMatrix();
	{
		glTranslatef(0.0f, 37.0f, 0.0f);
		glScalef(6.0f, 34.0f, 6.0f);
		cuello->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0f, 23.0f, 0.0f);
		glScalef(9.0f, 9.0f, 9.0f);
		base_cuello->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0f, 75.0f, 2.0f);
		cabeza->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();
}
