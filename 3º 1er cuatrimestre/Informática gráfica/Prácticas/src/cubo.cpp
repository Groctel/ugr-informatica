/** @file cubo.cpp
 */

#include "cubo.hpp"

/** @fn inline void Cubo :: InicializarCaras () noexcept
 *
 * @brief Crea las doce caras del cubo
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

/** @fn inline void Cubo :: InicializarVertices (const float escala) noexcept
 *
 * @brief Crea la tabla de vértices del cubo
 * @param escala Factor de escalado de los lados del cubo
 */

inline void Cubo :: InicializarVertices (const float escala) noexcept
{
	vertices.resize(8);

	vertices[0] = {-escala, -escala, -escala};
	vertices[1] = {-escala, -escala,  escala};
	vertices[2] = {-escala,  escala, -escala};
	vertices[3] = {-escala,  escala,  escala};
	vertices[4] = { escala, -escala, -escala};
	vertices[5] = { escala, -escala,  escala};
	vertices[6] = { escala,  escala, -escala};
	vertices[7] = { escala,  escala,  escala};
}

/** @fn Cubo :: Cubo (const float escala) noexcept
 *
 * @brief Constructor con argumento
 * @param escala Factor de escalado de los lados del cubo
 *
 * Llama a las funciones de inicialización propias y heredadas para crear el
 * cubo.
 */

Cubo :: Cubo (const float escala) noexcept
{
	InicializarVertices(escala);
	InicializarCaras();
	InicializarMalla();
}

