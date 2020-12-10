/** @file tetraedro.cpp
 */

#include "tetraedro.hpp"

/** @fn inline void Tetraedro :: InicializarCaras () noexcept
 *
 * @brief Crea las cuatro caras del tetraedro
 *
 * La tupla de cada cara comienza con el vértice del mismo índice de la tabla
 * para verificar su corrección.
 */

inline void Tetraedro :: InicializarCaras () noexcept
{
	caras.resize(4);

	caras[0]  = {0, 1, 2};
	caras[1]  = {1, 3, 2};
	caras[2]  = {2, 3, 0};
	caras[3]  = {3, 1, 0};
}

/** @fn inline void Tetraedro :: InicializarVertices (const float escala) noexcept
 *
 * @brief Crea la tabla de vértices del tetraedro
 * @param escala Factor de escalado de los lados del cubo
 */

inline void Tetraedro :: InicializarVertices (const float escala) noexcept
{
	vertices.resize(4);

	float mediana = sqrt(pow(escala, 2) - pow(escala/2, 2));
	float altura  = sqrt(pow(escala, 2) - pow(mediana/3, 2));

	vertices[0] = {-escala, -altura, -mediana};
	vertices[1] = {escala,  -altura, -mediana};
	vertices[2] = {0,       -altura, mediana };
	vertices[3] = {0,       altura,  0       };
}

/** @fn Tetraedro :: Tetraedro (const float escala) noexcept
 *
 * @brief Constructor con argumento
 * @param escala Factor de escalado de los lados del tetraedro
 *
 * Llama a las funciones de inicialización propias y heredadas para crear el
 * tetraedro.
 */

Tetraedro :: Tetraedro (const float escala) noexcept
{
	nombre = "Tetraedro";

	InicializarVertices(escala);
	InicializarCaras();
	InicializarColores();
}

