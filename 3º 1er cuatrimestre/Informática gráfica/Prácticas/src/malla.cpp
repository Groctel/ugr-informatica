#include "malla.hpp"

inline void Malla3D :: GenerarVBOs () noexcept
{
	if (vbo_caras == 0)
		vbo_caras = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			caras.size()*3*sizeof(int),
			caras.data()
		);

	if (vbo_caras_ajedrez0 == 0)
		vbo_caras_ajedrez0 = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			caras_ajedrez0.size()*3*sizeof(int),
			caras_ajedrez0.data()
		);

	if (vbo_caras_ajedrez1 == 0)
		vbo_caras_ajedrez1 = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			caras_ajedrez1.size()*3*sizeof(int),
			caras_ajedrez1.data()
		);

	if (vbo_colores_ajedrez0 == 0)
		vbo_colores_ajedrez0 = VBO(
			GL_ARRAY_BUFFER,
			colores_ajedrez0.size()*3*sizeof(float),
			colores_ajedrez0.data()
		);

	if (vbo_colores_ajedrez1 == 0)
		vbo_colores_ajedrez1 = VBO(
			GL_ARRAY_BUFFER,
			colores_ajedrez1.size()*3*sizeof(float),
			colores_ajedrez1.data()
		);

	if (vbo_colores_lineas == 0)
		vbo_colores_lineas = VBO(
			GL_ARRAY_BUFFER,
			colores_lineas.size()*3*sizeof(float),
			colores_lineas.data()
		);

	if (vbo_colores_puntos == 0)
		vbo_colores_puntos = VBO(
			GL_ARRAY_BUFFER,
			colores_puntos.size()*3*sizeof(float),
			colores_puntos.data()
		);

	if (vbo_colores_solido == 0)
		vbo_colores_solido = VBO(
			GL_ARRAY_BUFFER,
			colores_solido.size()*3*sizeof(float),
			colores_solido.data()
		);

	if (vbo_vertices == 0)
		vbo_vertices = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			vertices.data()
		);
}

inline void Malla3D :: DibujarDiferido () noexcept
{
	GenerarVBOs();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	if (visualizacion.test(Visualizacion::Ajedrez) && !caras_ajedrez0.empty())
		EnviarAjedrezInmediato();
	else
	{
		if (visualizacion.test(Visualizacion::Lineas))
		{
			glLineWidth(2);
			EnviarDibujoDiferido(GL_LINE, vbo_colores_lineas);
			glLineWidth(1);
		}

		if (visualizacion.test(Visualizacion::Puntos))
			EnviarDibujoDiferido(GL_POINT, vbo_colores_puntos);

		if (visualizacion.test(Visualizacion::Solido))
			EnviarDibujoDiferido(GL_FILL, vbo_colores_solido);
	}

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

inline void Malla3D :: DibujarInmediato () const noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices.data());

	if (visualizacion.test(Visualizacion::Ajedrez) && !caras_ajedrez0.empty())
		EnviarAjedrezInmediato();
	else
	{
		if (visualizacion.test(Visualizacion::Lineas))
		{
			glLineWidth(2);
			EnviarDibujoInmediato(GL_LINE, colores_lineas);
			glLineWidth(1);
		}

		if (visualizacion.test(Visualizacion::Puntos))
			EnviarDibujoInmediato(GL_POINT, colores_puntos);

		if (visualizacion.test(Visualizacion::Solido))
			EnviarDibujoInmediato(GL_FILL, colores_solido);
	}

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

inline GLuint Malla3D :: VBO (GLuint tipo, GLuint bytes, GLvoid * datos) const noexcept
{
	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(tipo, vbo);
	glBufferData(tipo, bytes, datos, GL_STATIC_DRAW);
	glBindBuffer(tipo, 0);

	return vbo;
}

inline void Malla3D :: EnviarAjedrezInmediato () const noexcept
{
	glPolygonMode(GL_FRONT, GL_FILL);

	glColorPointer(3, GL_FLOAT, 0, colores_ajedrez0.data());
	glDrawElements(
		GL_TRIANGLES, caras_ajedrez0.size()*3,
		GL_UNSIGNED_INT, caras_ajedrez0.data()
	);

	glColorPointer(3, GL_FLOAT, 0, colores_ajedrez1.data());
	glDrawElements(
		GL_TRIANGLES, caras_ajedrez1.size()*3,
		GL_UNSIGNED_INT, caras_ajedrez1.data()
	);
}

inline void Malla3D :: EnviarDibujoDiferido (GLenum modo, GLuint color) const noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, color);
	glColorPointer(3, GL_FLOAT, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glPolygonMode(GL_FRONT, modo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras);
	glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

inline void Malla3D :: EnviarDibujoInmediato (
	GLenum modo, std::vector<tuplas::Tupla3f> color) const noexcept
{
	glColorPointer(3, GL_FLOAT, 0, color.data());
	glPolygonMode(GL_FRONT, modo);
	glDrawElements(
		GL_TRIANGLES, caras.size()*3,
		GL_UNSIGNED_INT, caras.data()
	);
}

void Malla3D :: GenerarAjedrez () noexcept
{
	caras_ajedrez0.resize(caras.size()/2);
	caras_ajedrez1.resize(caras.size()/2);

	colores_ajedrez0.resize(vertices.size());
	colores_ajedrez1.resize(vertices.size());

	for (size_t i = 0; i < caras_ajedrez0.size(); i++)
		caras_ajedrez0[i] = caras[2*i];

	for (size_t i = 0; i < caras_ajedrez1.size(); i++)
		caras_ajedrez1[i] = caras[2*i+1];

	for (size_t i = 0; i < colores_ajedrez0.size(); i++)
		colores_ajedrez0[i] = coloresgl::NEGRO;

	for (size_t i = 0; i < colores_ajedrez0.size(); i++)
		colores_ajedrez0[i] = coloresgl::MAGENTA;
}

void Malla3D :: Dibujar (Dibujo modo) noexcept
{
	switch (modo)
	{
		case Dibujo::Diferido:
			DibujarDiferido();
		break;

		case Dibujo::Inmediato:
			DibujarInmediato();
		break;
	}
}

bool Malla3D :: Visualizar (Visualizacion vis) const noexcept
{
	return visualizacion.test(vis);
}

void Malla3D :: Visualizar (Visualizacion vis, Bitset operacion) noexcept
{
	switch (operacion)
	{
		case Bitset::Flip:
			visualizacion.flip(vis);
		break;

		case Bitset::Reset:
			visualizacion.reset(vis);
		break;

		case Bitset::Set:
			visualizacion.set(vis);
		break;
	}
}

tuplas::Tupla3i Malla3D :: Cara (const size_t indice) const
{
	if (indice >= caras.size())
		throw std::out_of_range("Intento de acceso a cara sobre el máximo.");
	return caras[indice];
}

std::vector<tuplas::Tupla3i> Malla3D :: Caras () const noexcept
{
	return caras;
}

tuplas::Tupla3f Malla3D :: Vertice (const size_t indice) const
{
	if (indice >= vertices.size())
		throw std::out_of_range("Intento de acceso a vértice sobre el máximo.");
	return vertices[indice];
}

std::vector<tuplas::Tupla3f> Malla3D :: Vertices () const noexcept
{
	return vertices;
}
