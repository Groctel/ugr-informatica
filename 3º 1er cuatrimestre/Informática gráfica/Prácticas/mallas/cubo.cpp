/** @file mallas/cubo.cpp
 */

#include "cubo.hpp"

/**
 * @brief Crea las doce caras del cubo.
 *
 * Las caras se crean de forma que la primera mitad parte de un vértice y la
 * otra del opuesto para crear el efecto ajedrez perfecto del cubo.
 */

inline void Cubo :: InicializarCaras () noexcept
{
	caras.resize(12);

	caras[0]  = {6, 0, 2};
	caras[1]  = {6, 2, 3};
	caras[2]  = {6, 3, 7};
	caras[3]  = {6, 7, 5};
	caras[4]  = {6, 5, 4};
	caras[5]  = {6, 4, 0};

	caras[6]  = {1, 3, 2};
	caras[7]  = {1, 2, 0};
	caras[8]  = {1, 0, 4};
	caras[9]  = {1, 4, 5};
	caras[10] = {1, 5, 7};
	caras[11] = {1, 7, 3};
}

/**
 * @brief Crea la tabla de vértices del cubo.
 */

inline void Cubo :: InicializarVertices () noexcept
{
	vertices.resize(8);

	vertices[0] = {-1, -1, -1};
	vertices[1] = {-1, -1,  1};
	vertices[2] = {-1,  1, -1};
	vertices[3] = {-1,  1,  1};
	vertices[4] = { 1, -1, -1};
	vertices[5] = { 1, -1,  1};
	vertices[6] = { 1,  1, -1};
	vertices[7] = { 1,  1,  1};
}

/**
 * @brief Constructor con argumento.
 *
 * Llama a las funciones de inicialización propias y heredadas para crear el
 * cubo.
 */

Cubo :: Cubo () noexcept
{
	InicializarVertices();
	InicializarCaras();
	InicializarMalla();
}

