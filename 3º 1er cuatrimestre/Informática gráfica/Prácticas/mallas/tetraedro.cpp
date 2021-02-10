/** @file tetraedro.cpp
 */

#include "tetraedro.hpp"

/**
 * @brief Crea las cuatro caras del tetraedro.
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

/**
 * @brief Crea la tabla de vértices del tetraedro.
 */

inline void Tetraedro :: InicializarVertices () noexcept
{
	vertices.resize(4);

	float mediana = sqrt(1 - 1/4.0f);
	float altura  = sqrt(1 - pow(mediana/3.0f, 2));

	vertices[0] = {-1, -altura, -mediana};
	vertices[1] = {1,  -altura, -mediana};
	vertices[2] = {0,  -altura, mediana };
	vertices[3] = {0,  altura,  0       };
}

/**
 * @brief Constructor con argumento.
 *
 * Llama a las funciones de inicialización propias y heredadas para crear el
 * tetraedro.
 */

Tetraedro :: Tetraedro () noexcept
{
	InicializarVertices();
	InicializarCaras();
	InicializarMalla();
}

