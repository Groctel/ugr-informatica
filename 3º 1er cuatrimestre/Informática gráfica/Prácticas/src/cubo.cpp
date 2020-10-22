/** @file cubo.cpp
 */

#include "cubo.hpp"

/** @fn inline void Cubo :: InicializarCaras () noexcept
 *
 * @brief Crea las doce caras del cubo
 *
 * Empareja las caras de forma que cada cara `2n` se corresponda con la cara
 * `2n+1`. Esta relación se verifica porque para cada par de caras `c` y `d`, se
 * tiene que `c[2] = d[3]` y `c[3] = d[2]`.
 */

inline void Cubo :: InicializarCaras () noexcept
{
	caras.resize(12);

	caras[0]  = {6, 0, 2};
	caras[1]  = {6, 5, 4};
	caras[2]  = {6, 3, 7};
	caras[3]  = {1, 3, 2};
	caras[4]  = {1, 5, 7};
	caras[5]  = {1, 0, 4};

	caras[6]  = {6, 2, 3};
	caras[7]  = {6, 7, 5};
	caras[8]  = {6, 4, 0};
	caras[9]  = {1, 2, 0};
	caras[10] = {1, 7, 3};
	caras[11] = {1, 4, 5};
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

/** @fn Cubo :: Cubo (const float escala)
 *
 * @brief Constructor con argumento
 * @param escala Factor de escalado de los lados del cubo
 *
 * Llama a las funciones de inicialización propias y heredadas para crear el
 * cubo.
 */

Cubo :: Cubo (const float escala)
{
	InicializarVertices(escala);
	InicializarCaras();
	InicializarColores();
}

