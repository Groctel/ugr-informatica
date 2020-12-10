/** @file objrevolucion.cpp
 */

#include "objrevolucion.hpp"

void ObjRevolucion :: GenerarCaras (const size_t iteraciones, Tapas tapas) noexcept
{
	caras.resize((2 * (perfil.size() - (3 - tapas)) + 2 - tapas) * iteraciones);

	size_t indice_cara = 0;

	size_t vertice_inicial = (
		(tapas == Tapas::Ambas || tapas == Tapas::Inferior) ? 1 : 0
	);

	size_t vertice_final = (
		perfil.size() - (
			(tapas == Tapas::Ambas || tapas == Tapas::Superior) ? 1 : 0
		)
	);

	/*
	 * TODO: Probablemente esto se pueda hacer arreglando el bucle y
	 * simplemente usando la operación módulo. El pseudocódigo de las
	 * prácticas no me funciona y esto es un poco farragoso pero hace su
	 * trabajo, aunque no sea eficiente.
	 */

	for (size_t i = 0; i < perfil.size()-1; i++)
	{
		for (size_t j = 0; j < iteraciones; j++)
		{
			uint32_t vertice = i * iteraciones + j;

			if (j == iteraciones - 1)
			{
				caras[indice_cara++] = {
					vertice,
					vertice - (uint32_t) iteraciones + 1,
					vertice + 1
				};

				caras[indice_cara++] = {
					vertice,
					vertice + 1,
					vertice + (uint32_t) iteraciones
				};
			}
			else
			{
				caras[indice_cara++] = {
					vertice,
					vertice + 1,
					vertice + (uint32_t) iteraciones + 1
				};

				caras[indice_cara++] = {
					vertice,
					vertice + (uint32_t) iteraciones + 1,
					vertice + (uint32_t) iteraciones
				};
			}
		}
	}
}

void ObjRevolucion :: GenerarVertices (const size_t iteraciones, Tapas tapas) noexcept
{
	size_t vertice_final = (perfil.size() - tapas);

	vertices.resize((perfil.size() - 2) * iteraciones + (2 - tapas));

	for (size_t i = 0; i < iteraciones; i++)
	{
		float angulo = (2 * M_PI * i) / iteraciones;

		for (size_t j = 0; j < vertice_final; j++)
		{
			vertices[iteraciones * i + j] = {
				(float) (perfil[j][0] * cos(angulo) + perfil[j][2] * sin(angulo)),
				(float) (perfil[j][1]),
				(float) (perfil[j][0] * -sin(angulo) + perfil[j][2] * cos(angulo))
			};
		}
	}
}

void ObjRevolucion :: GenerarTapas () noexcept
{
	if (perfil[0][0] > std::numeric_limits<double>::epsilon())
		perfil.push_back({0, perfil[0][1], 0});

	if (perfil[perfil.size()-1][0] > std::numeric_limits<double>::epsilon())
		perfil.push_back({0, perfil[perfil.size()-1][1], 0});

	if (fabs(perfil[perfil.size()-1][1] - perfil[perfil.size()-2][1]) > std::numeric_limits<double>::epsilon())
		std::swap(perfil[perfil.size()-1], perfil[perfil.size()-2]);
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
	GenerarTapas();
}

ObjRevolucion :: ObjRevolucion (
	const std::string & nuevo_nombre,
	const std::vector<tuplas::Tupla3f> & nuevo_perfil
) noexcept
{
	nombre = nuevo_nombre;
	perfil = nuevo_perfil;
	GenerarTapas();
}

std::vector<tuplas::Tupla3f> ObjRevolucion :: Perfil () const noexcept
{
	return perfil;
}

tuplas::Tupla3f ObjRevolucion :: PuntoPerfil (const size_t indice) const
{
	if (indice >= perfil.size())
		throw std::out_of_range(
			"Intento de acceso a punto del perfil sobre el máximo."
		);
	return perfil[indice];
}

void ObjRevolucion :: Revolucionar (size_t iteraciones, Tapas tapas) noexcept
{
	GenerarVertices(iteraciones, tapas);
	GenerarCaras(iteraciones);
	InicializarColores();
	GenerarAjedrez();
}

