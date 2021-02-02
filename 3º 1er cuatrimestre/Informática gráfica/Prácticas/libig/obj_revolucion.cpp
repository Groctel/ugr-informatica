/** @file obj_revolucion.cpp
 */

#include "obj_revolucion.hpp"

/**
 * @brief Genera la tabla de caras de la Malla3D ascendente.
 * @param tapas Especificación de la construcción de las tapas en la revolución.
 */

void ObjRevolucion :: GenerarCaras (Tapas tapas) noexcept
{
	caras.resize(2 * (vertices.size() - tapas - 1) + iteraciones * tapas);

	size_t indice_cara = 0;

	for (size_t i = 0; i < perfil.size() - 1; i++)
	{
		for (size_t j = 0; j < iteraciones; j++)
		{
			uint32_t vertice = iteraciones * i + j;

			caras[indice_cara++] = {
				vertice,
				(uint32_t) (((vertice + 1) % iteraciones) + i * iteraciones),
				(uint32_t) (((vertice + 1) % iteraciones) + (i + 1) * iteraciones)
			};

			caras[indice_cara++] = {
				vertice,
				(uint32_t) (((vertice + 1) % iteraciones) + (i + 1) * iteraciones),
				(uint32_t) ((vertice % iteraciones)       + (i + 1) * iteraciones)
			};
		}
	}

	if (tapas == Tapas::Inferior || tapas == Tapas::Ambas)
	{
		for (size_t i = 0; i < iteraciones; i++)
			caras[indice_cara++] = {
				(uint32_t) i,
				(uint32_t) vertices.size()-tapas,
				(uint32_t) ((i + 1) % iteraciones)
			};
	}

	if (tapas == Tapas::Superior || tapas == Tapas::Ambas)
	{
		for (size_t i = 0; i < iteraciones; i++)
			caras[indice_cara++] = {
				(uint32_t) (i + iteraciones * (perfil.size() - 1)),
				(uint32_t) (((i + 1) % iteraciones) + iteraciones * (perfil.size() - 1)),
				(uint32_t) (vertices.size()-1)
			};
	}
}

/**
 * @brief Genera la tabla de vértices de la Malla3D ascendente.
 * @param tapas Especificación de la construcción de las tapas en la revolución.
 * @param eje Eje alrededor del cual ha de rotarse el objeto en su construcción.
 */

void ObjRevolucion :: GenerarVertices (Tapas tapas, EjeRotacion eje) noexcept
{
	std::pair<Tupla3f, Tupla3f> puntos_tapas = DetectarTapas(eje);

	vertices.resize(perfil.size() * iteraciones + tapas);

	switch (eje)
	{
		case EjeX: RotarVerticesX(); break;
		case EjeY: RotarVerticesY(); break;
		case EjeZ: RotarVerticesZ(); break;
	}

	if (tapas == Tapas::Inferior || tapas == Tapas::Ambas)
		vertices[vertices.size()-tapas] = puntos_tapas.tapa_inf;

	if (tapas == Tapas::Superior || tapas == Tapas::Ambas)
		vertices[vertices.size()-1] = puntos_tapas.tapa_sup;
}

std::pair<Tupla3f, Tupla3f> ObjRevolucion :: DetectarTapas (
	const EjeRotacion eje
) noexcept
{
	std::pair<Tupla3f, Tupla3f> puntos_tapas = {
		*perfil.cbegin(),
		*perfil.crbegin()
	};

	unsigned char eje1, eje2;

	switch (eje)
	{
		case EjeX:
			eje1 = Y;
			eje2 = Z;
		break;

		case EjeY:
			eje1 = X;
			eje2 = Z;
		break;

		case EjeZ:
			eje1 = X;
			eje2 = Y;
		break;
	}

	if (FloatZ(puntos_tapas.tapa_inf[eje1]) && FloatZ(puntos_tapas.tapa_inf[eje2]))
		perfil.erase(perfil.cbegin());
	else
		puntos_tapas.tapa_inf[eje1] = puntos_tapas.tapa_inf[eje2] = 0;

	if (FloatZ(puntos_tapas.tapa_sup[eje1]) && FloatZ(puntos_tapas.tapa_sup[eje2]))
		perfil.pop_back();
	else
		puntos_tapas.tapa_sup[eje1] = puntos_tapas.tapa_sup[eje2] = 0;

	return puntos_tapas;
}

/**
 * @brief Genera los vértices del objeto rotando el perfil alrededor del eje X.
 */

void ObjRevolucion :: RotarVerticesX () noexcept
{
	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (2 * M_PI * i) / iteraciones;

		for (size_t j = 0; j < perfil.size(); j++)
		{
			vertices[iteraciones * j + i] = {
				(float) (perfil[j][X]),
				(float) (perfil[j][Y] * cos(angulo) - perfil[j][Z] * sin(angulo)),
				(float) (perfil[j][Y] * sin(angulo) + perfil[j][Z] * cos(angulo))
			};
		}
	}
}

/**
 * @brief Genera los vértices del objeto rotando el perfil alrededor del eje Y.
 */

void ObjRevolucion :: RotarVerticesY () noexcept
{
	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (2 * M_PI * i) / iteraciones;

		for (size_t j = 0; j < perfil.size(); j++)
		{
			vertices[iteraciones * j + i] = {
				(float) (perfil[j][X] *  cos(angulo) + perfil[j][Z] * sin(angulo)),
				(float) (perfil[j][Y]),
				(float) (perfil[j][X] * -sin(angulo) + perfil[j][Z] * cos(angulo))
			};
		}
	}
}

/**
 * @brief Genera los vértices del objeto rotando el perfil alrededor del eje Z.
 */

void ObjRevolucion :: RotarVerticesZ () noexcept
{
	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (2 * M_PI * i) / iteraciones;

		for (size_t j = 0; j < perfil.size(); j++)
		{
			vertices[iteraciones * j + i] = {
				(float) (perfil[j][X] * cos(angulo) - perfil[j][Y] * sin(angulo)),
				(float) (perfil[j][X] * sin(angulo) + perfil[j][Y] * cos(angulo)),
				(float) (perfil[j][Z])
			};
		}
	}
}

/**
 * @brief Gestor de la revolución del objeto.
 * @param nuevas_iteraciones Factor de definición del objeto al revolucionarse.
 * @param tapas Especificación de la construcción de las tapas en la revolución.
 * @param eje Eje alrededor del cual ha de rotarse el objeto en su construcción.
 *
 * Llama a GenerarVertices, GenerarCaras y InicializarMalla, actuando como
 * interfaz de estas tres funciones para las clases heredadas.
 */

void ObjRevolucion :: Revolucionar (
	size_t nuevas_iteraciones,
	Tapas tapas,
	EjeRotacion eje
) noexcept
{
	if (iteraciones == 0)
		iteraciones = nuevas_iteraciones;

	GenerarVertices(tapas, eje);
	GenerarCaras(tapas);
	InicializarMalla();
}

/**
 * @brief Constructor sin argumentos necesario para las clases descendientes.
 */

ObjRevolucion :: ObjRevolucion () noexcept
{ }

/**
 * @brief Constructor completo desde PLY.
 * @param ruta Ruta al fichero PLY de construcción.
 * @param nuevas_iteraciones Factor de definición del objeto al revolucionarse.
 * @param tapas Especificación de la construcción de las tapas en la revolución.
 * @param eje Eje alrededor del cual ha de rotarse el objeto en su construcción.
 */

ObjRevolucion :: ObjRevolucion (
	const std::string & ruta,
	size_t nuevas_iteraciones,
	Tapas tapas,
	EjeRotacion eje
) noexcept
:
	iteraciones(nuevas_iteraciones)
{
	std::ifstream fi                    = PLY::Abrir(ruta);
	std::pair<size_t, size_t> tamanios  = PLY::LeerCabecera(fi);

	perfil = PLY::LeerVertices(fi, tamanios.first);
	fi.close();

	Revolucionar(iteraciones, tapas, eje);
}

/**
 * @brief Constructor completo desde vector de perfil.
 * @param nuevo_perfil Perfil sobre el que construir el objeto.
 * @param nuevas_iteraciones Factor de definición del objeto al revolucionarse.
 * @param tapas Especificación de la construcción de las tapas en la revolución.
 * @param eje Eje alrededor del cual ha de rotarse el objeto en su construcción.
 */

ObjRevolucion :: ObjRevolucion (
	const std::vector<Tupla3f> & nuevo_perfil,
	size_t nuevas_iteraciones,
	Tapas tapas,
	EjeRotacion eje
) noexcept
:
	iteraciones (nuevas_iteraciones),
	perfil      (nuevo_perfil)
{
	Revolucionar(iteraciones, tapas, eje);
}

bool ObjRevolucion :: MuestraTapas () const noexcept
{
	return mostrar_tapas;
}

void ObjRevolucion :: EnviarDibujoDiferido () noexcept
{
	if (vbo_vertices == 0)
		vbo_vertices = VBO(
			GL_ARRAY_BUFFER,
			vertices.size() * 3 *sizeof(float) -
				(mostrar_tapas ? 0 : (vertices.size() - perfil.size() * iteraciones)),
			vertices.data()
		);

	if (vbo_caras == 0)
		vbo_caras = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			caras.size() * 3 * sizeof(uint32_t) -
				(mostrar_tapas ? 0 : (caras.size() - 2 * perfil.size() * iteraciones)),
			caras.data()
		);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	{
		glVertexPointer(3, GL_FLOAT, 0, 0);
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras);
	{
		glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, 0);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ObjRevolucion :: MostrarTapas (const bool nuevo_estado) noexcept
{
	mostrar_tapas = nuevo_estado;
	vbo_vertices = vbo_caras = 0;
}
