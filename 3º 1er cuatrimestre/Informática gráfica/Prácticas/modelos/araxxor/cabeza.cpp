#include "modelos/araxxor/cabeza.hpp"

CabezaAraxxor :: CabezaAraxxor () noexcept
:
	cabeza             (new ObjPLY("plys/Araxxor/cabeza.ply")),
	colmillo_derecho   (new ColmilloAraxxor("plys/Araxxor/colmillo_derecho.ply")),
	colmillo_izquierdo (new ColmilloAraxxor("plys/Araxxor/colmillo_izquierdo.ply"))
{ }

CabezaAraxxor :: ~CabezaAraxxor () noexcept
{
	delete cabeza;
	delete colmillo_derecho;
	delete colmillo_izquierdo;
}

void CabezaAraxxor :: AplicarMaterial (Material * m) noexcept
{
	cabeza->AplicarMaterial(m);
	colmillo_derecho->AplicarMaterial(m);
	colmillo_izquierdo->AplicarMaterial(m);
}

void CabezaAraxxor :: AplicarTextura  (Textura * nueva) noexcept
{
	cabeza->AplicarTextura(nueva);
	colmillo_derecho->AplicarTextura(nueva);
	colmillo_izquierdo->AplicarTextura(nueva);
}

void CabezaAraxxor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion,
	const bool marcado
) noexcept
{
	glPushMatrix();
	{
		glTranslatef(
			5.2f   + cos(0.05 * pos_x),
			-86.0f + sin(1.5f * pos_y),
			-52.8f + sin(0.75f * pos_z)
		);
		cabeza->Dibujar(dibujado, ajedrez, color, seleccion, marcado);

		glPushMatrix();
		{
			glTranslatef(21.6f, 54.8f, -10.3f);
			glRotatef(cos(pos_y) * 15, 1, 0, 0);
			colmillo_derecho->Dibujar(dibujado, ajedrez, color, seleccion, marcado);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-17.1f, 52.9f, -9.7f);
			glRotatef(sin(pos_y) * 15, 1, 0, 0);
			colmillo_izquierdo->Dibujar(dibujado, ajedrez, color, seleccion, marcado);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void CabezaAraxxor :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	cabeza->NuevoColorSeleccion(color);
	colmillo_derecho->NuevoColorSeleccion(color);
	colmillo_izquierdo->NuevoColorSeleccion(color);
}

void CabezaAraxxor :: Mover (const float despl) noexcept
{
	pos_x += despl;
	pos_y += despl;
	pos_z += despl;
}
