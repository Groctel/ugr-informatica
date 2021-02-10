#include "modelos/araxxor/abdomen.hpp"

AbdomenAraxxor :: AbdomenAraxxor () noexcept
:
	abdomen (new ObjPLY("plys/Araxxor/abdomen.ply"))
{ }

AbdomenAraxxor :: ~AbdomenAraxxor () noexcept
{
	delete abdomen;
}

Malla3D * AbdomenAraxxor :: Cuerpo () const noexcept
{
	return abdomen;
}

void AbdomenAraxxor :: AplicarMaterial (Material * m) noexcept
{
	abdomen->AplicarMaterial(m);
}

void AbdomenAraxxor :: AplicarTextura  (Textura * nueva, const bool calcular) noexcept
{
	abdomen->AplicarTextura(nueva, calcular);
}

void AbdomenAraxxor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion
) noexcept
{
	glPushMatrix();
	{
		glTranslatef(5.8f, -18.3f, -52.7f);
		glRotatef(cos(-rotacion) * 5 -5, 1, 0, 0);

		abdomen->Dibujar(dibujado, ajedrez, color, seleccion);
	}
	glPopMatrix();
}

void AbdomenAraxxor :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	abdomen->NuevoColorSeleccion(color);
}

void AbdomenAraxxor :: Mover (const float grados) noexcept
{
	rotacion += grados;
}
