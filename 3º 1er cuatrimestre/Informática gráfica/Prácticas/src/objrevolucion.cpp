/** @file objrevolucion.cpp
 */

#include "objrevolucion.hpp"

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
	const std::string & ruta,
	size_t iteraciones,
	const float escala,
	Tapas tapas
) noexcept
:
	Malla3D (ruta, escala)
{
	perfil.swap(vertices);

	Revolucionar(iteraciones, tapas);
	InicializarColores();
	GenerarAjedrez();
}

ObjRevolucion :: ObjRevolucion (
	const std::vector<tuplas::Tupla3f> & nuevo_perfil,
	size_t iteraciones,
	Tapas tapas
) noexcept
{
	perfil = nuevo_perfil;
	Revolucionar(iteraciones, tapas);
	InicializarColores();
	GenerarAjedrez();
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
	vertices.resize(perfil.size() * iteraciones);
	caras.resize(2 * (perfil.size() - 1) * iteraciones);

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

	size_t indice_cara = 0;

	for (size_t i = 0; i < perfil.size()-1; i++)
	{
		for (size_t j = 0; j < iteraciones; j++)
		{
			uint32_t vertice = i * iteraciones + j;

			caras[indice_cara++] = {
				vertice,
				vertice + 1,
				vertice + (uint32_t) iteraciones
			};

			caras[indice_cara++] = {
				vertice,
				vertice + (uint32_t) iteraciones,
				vertice + (uint32_t) iteraciones - 1
			};
		}
	}
}

