/** @file mallas/cuadro.cpp
 */

#include "cuadro.hpp"

/**
 * @brief Crea las doce caras del cuadro.
 *
 * Las caras se crean de forma que la primera mitad parte de un vértice y la
 * otra del opuesto para crear el efecto ajedrez perfecto del cuadro.
 */

inline void Cuadro :: InicializarCaras () noexcept
{
	caras.resize(2);

	caras[0]  = {0, 1, 3};
	caras[1]  = {0, 3, 2};
}

/**
 * @brief Crea la tabla de vértices del cuadro.
 * @param escala Factor de escalado de los lados del cuadro.
 */

inline void Cuadro :: InicializarVertices (const float escala) noexcept
{
	vertices.resize(4);

	vertices[0] = {0,      0,      0};
	vertices[1] = {escala, 0,      0};
	vertices[2] = {0,      escala, 0};
	vertices[3] = {escala, escala, 0};
}

/**
 * @brief Constructor con argumento.
 * @param escala Factor de escalado de los lados del cuadro.
 *
 * Llama a las funciones de inicialización propias y heredadas para crear el
 * cuadro.
 */

Cuadro :: Cuadro (const float escala) noexcept
{
	InicializarVertices(escala);
	InicializarCaras();
	InicializarMalla();
}


