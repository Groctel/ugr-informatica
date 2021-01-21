#include "modelo-jerarquico/cabeza.hpp"

CabezaJirafa :: CabezaJirafa ()
:
	craneo      (new Cubo()),
	cuerno_izdo (new Cubo()),
	cuerno_dcho (new Cubo()),
	mandibula   (new Cubo()),
	oreja_izda  (new Cubo()),
	oreja_dcha  (new Cubo())
{ }

CabezaJirafa :: ~CabezaJirafa ()
{
	delete craneo;
	delete cuerno_izdo;
	delete cuerno_dcho;
	delete mandibula;
	delete oreja_izda;
	delete oreja_dcha;
}

void CabezaJirafa :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color
) noexcept
{
	glPushMatrix();
	{
		glScalef(8.0f, 6.0f, 10.0f);
		craneo->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(4.0f, 3.0f, 5.0f);
		glScalef(4.0f, 3.0f, 5.0f);
		mandibula->Dibujar(dibujado, ajedrez, color);
	}
	glPopMatrix();
}

