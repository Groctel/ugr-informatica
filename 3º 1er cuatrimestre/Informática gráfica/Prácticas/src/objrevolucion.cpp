/** @file objrevolucion.cpp
 */

#include "objrevolucion.hpp"

void ObjRevolucion :: GenerarCaras (
	const std::vector<Tupla3f> & perfil,
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

void ObjRevolucion :: GenerarVertices (
	std::vector<Tupla3f> & perfil,
	const size_t iteraciones,
	Tapas tapas
) noexcept
{
	Tupla3f tapa_inf = *perfil.cbegin();
	Tupla3f tapa_sup = *perfil.crbegin();

	if (FloatZ(tapa_inf[0]) && FloatZ(tapa_inf[2]))
		perfil.erase(perfil.cbegin());
	else
		tapa_inf[0] = tapa_inf[2] = 0;

	if (FloatZ(tapa_sup[0]) && FloatZ(tapa_sup[2]))
		perfil.pop_back();
	else
		tapa_sup[0] = tapa_sup[2] = 0;

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

	if (tapas == Tapas::Inferior || tapas == Tapas::Ambas)
		vertices[vertices.size()-tapas] = tapa_inf;

	if (tapas == Tapas::Superior || tapas == Tapas::Ambas)
		vertices[vertices.size()-1] = tapa_sup;
}

void ObjRevolucion :: Revolucionar (
	std::vector<Tupla3f> & perfil,
	size_t iteraciones,
	Tapas tapas
) noexcept
{
	GenerarVertices(perfil, iteraciones, tapas);
	GenerarCaras(perfil, iteraciones, tapas);
	InicializarColores();
	GenerarAjedrez();
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
	const std::string & ruta,
	size_t iteraciones,
	Tapas tapas
) noexcept
{
	std::ifstream fi                    = PLY::Abrir(ruta);
	std::pair<size_t, size_t> tamanios  = PLY::LeerCabecera(fi);
	std::vector<Tupla3f> perfil = PLY::LeerVertices(fi, tamanios.first);
	fi.close();

	Revolucionar(perfil, iteraciones, tapas);
}

ObjRevolucion :: ObjRevolucion (
	const std::vector<Tupla3f> & nuevo_perfil,
	size_t iteraciones,
	Tapas tapas
) noexcept
{
	std::vector<Tupla3f> perfil = nuevo_perfil;

	Revolucionar(perfil, iteraciones, tapas);
}

bool ObjRevolucion :: MuestraTapas () const noexcept
{
	return mostrar_tapas;
}

void ObjRevolucion :: MostrarTapas (const bool estado) noexcept
{
	mostrar_tapas = estado;
}
