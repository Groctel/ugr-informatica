/** @file objrevolucion.cpp
 */

#include "objrevolucion.hpp"

inline void ObjRevolucion :: GenerarCaras (
	const size_t iteraciones,
	Tapas tapas
) noexcept
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
				(uint32_t) ((vertice % iteraciones) + (i + 1) * iteraciones)
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

inline void ObjRevolucion :: GenerarVertices (
	const size_t iteraciones,
	Tapas tapas,
	bool generar_tapas
) noexcept
{
	vertices.resize(perfil.size() * iteraciones + tapas);

	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (2 * M_PI * i) / iteraciones;

		for (size_t j = 0; j < perfil.size(); j++)
		{
			vertices[iteraciones * j + i] = {
				(float) (perfil[j][0] * cos(angulo) + perfil[j][2] * sin(angulo)),
				(float) (perfil[j][1]),
				(float) (perfil[j][0] * -sin(angulo) + perfil[j][2] * cos(angulo))
			};
		}
	}

	InsertarTapas(tapas, generar_tapas);
}

inline void ObjRevolucion :: EliminarTapas () noexcept
{
	puntos_tapas.fill({
		std::numeric_limits<float>::max(),
		std::numeric_limits<float>::max(),
		std::numeric_limits<float>::max()
	});

	if (FloatEq(*perfil.cbegin()[0]))
	{
		puntos_tapas[0] = *perfil.cbegin();
		perfil.erase(perfil.begin());
	}

	if (FloatEq(*perfil.crbegin()[0]))
	{
		puntos_tapas[1] = *perfil.crbegin();
		perfil.pop_back();
	}
}

inline void ObjRevolucion :: InsertarTapas (
	Tapas tapas,
	bool generar_tapas
) noexcept
{
	tuplas::Tupla3f invalida = {
		std::numeric_limits<float>::max(),
		std::numeric_limits<float>::max(),
		std::numeric_limits<float>::max()
	};

	if (tapas == Tapas::Inferior || tapas == Tapas::Ambas)
	{
		if (generar_tapas && puntos_tapas[0] == invalida)
			vertices[vertices.size()-tapas] = {0, perfil[0][1], 0};
		else
			vertices[vertices.size()-tapas] = puntos_tapas[0];
	}

	if (tapas == Tapas::Superior || tapas == Tapas::Ambas)
	{
		if (generar_tapas && puntos_tapas[1] == invalida)
			vertices[vertices.size()-1] = {0, perfil[perfil.size()-1][1], 0};
		else
			vertices[vertices.size()-1] = puntos_tapas[1];
	}
}

/** @fn ObjRevolucion :: ObjRevolucion ()
 *
 *  @brief Constructor sin argumentos.
 */

ObjRevolucion :: ObjRevolucion () noexcept
{ }

/** @fn ObjRevolucion :: ObjRevolucion (
 * 	const std::string & ruta,
 * 	size_t iteraciones,
 * 	Tapas tapas
 * ) noexcept
 *
 * @brief Constructor completo desde PLY.
 * @param ruta Ruta al fichero PLY de construcción.
 * @param iteraciones Factor de definición del objeto al revolucionarse.
 * @param tapas Especificación de la construcción de las tapas en la revolución.
 */

ObjRevolucion :: ObjRevolucion (
	const std::string & nuevo_nombre,
	const std::string & ruta
) noexcept
:
	Malla3D (ruta)
{
	nombre = nuevo_nombre;
	perfil.swap(vertices);
	EliminarTapas();
}

ObjRevolucion :: ObjRevolucion (
	const std::string & nuevo_nombre,
	const std::vector<tuplas::Tupla3f> & nuevo_perfil
) noexcept
{
	nombre = nuevo_nombre;
	perfil = nuevo_perfil;
	EliminarTapas();
}

std::vector<tuplas::Tupla3f> ObjRevolucion :: Perfil () const noexcept
{
	return perfil;
}

tuplas::Tupla3f ObjRevolucion :: PuntoPerfil (const size_t indice) const
{
	if (indice >= perfil.size())
	{
		throw std::out_of_range(
			"Intento de acceso a punto del perfil sobre el máximo."
		);
	}
	return perfil[indice];
}

void ObjRevolucion :: Revolucionar (
	size_t iteraciones,
	Tapas tapas,
	bool generar_tapas
) noexcept
{
	GenerarVertices(iteraciones, tapas, generar_tapas);
	GenerarCaras(iteraciones, tapas);
	InicializarColores();
	GenerarAjedrez();
}

