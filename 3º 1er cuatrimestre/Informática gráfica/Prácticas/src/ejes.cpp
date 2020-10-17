#include "ejes.hpp"

void Ejes :: InicializarColores ()
{
	colores.resize(6);

	colores[0] = {1, 0, 0};
	colores[1] = {1, 0, 0};
	colores[2] = {0, 1, 0};
	colores[3] = {0, 1, 0};
	colores[4] = {0, 0, 1};
	colores[5] = {0, 0, 1};
}

void Ejes :: InicializarVertices ()
{
	vertices.resize(6);

	vertices[0] = {-tamanio, 0,        0       };
	vertices[1] = {tamanio,  0,        0       };
	vertices[2] = {0,        -tamanio, 0       };
	vertices[3] = {0,        tamanio,  0       };
	vertices[4] = {0,        0,        -tamanio};
	vertices[5] = {0,        0,        tamanio };
}

Ejes :: Ejes (float tam)
	:tamanio(tam)
{
	InicializarColores();
	InicializarVertices();
}

void Ejes :: Dibujar ()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices.data());
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colores.data());
	glDrawArrays(GL_LINES, 0, 6);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Ejes :: NuevoTamanio (float nuevo)
{
	tamanio = nuevo;
	InicializarColores();
	InicializarVertices();
}
