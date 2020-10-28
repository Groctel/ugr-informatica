/** @file ejes.cpp
 */

#include "ejes.hpp"

/** @fn inline void Ejes :: InicializarColores ()
 *
 * @brief Crea las tablas de colores
 *
 * Crea los ejes con los siguientes colores:
 * - **X:** Rojo.
 * - **Y:** Verde.
 * - **Z:** Azul.
 */

inline void Ejes :: InicializarColores () noexcept
{
	colores.resize(6);

	colores[0] = colores[1] = coloresgl::ROJO;
	colores[2] = colores[3] = coloresgl::VERDE;
	colores[4] = colores[5] = coloresgl::AZUL;
}

/** @fn inline void Ejes :: InicializarVertices () noexcept
 *
 * @brief Crea la tabla de vértices de los ejes
 */

inline void Ejes :: InicializarVertices () noexcept
{
	vertices.resize(6);

	vertices[0] = {-tamanio, 0,        0       };
	vertices[1] = {tamanio,  0,        0       };
	vertices[2] = {0,        -tamanio, 0       };
	vertices[3] = {0,        tamanio,  0       };
	vertices[4] = {0,        0,        -tamanio};
	vertices[5] = {0,        0,        tamanio };
}

/** @fn Ejes :: Ejes (float tam)
 *
 * @brief Constructor con argumento
 * @param tam tamaño de los ejes
 *
 * Llama a las funciones de inicialización pertinentes para crear los ejes.
 */

Ejes :: Ejes (float tam)
:
	tamanio (tam)
{
	if (tam < 0)
		throw std::invalid_argument("Intento de uso de tamaño negativo en ejes.");

	InicializarVertices();
	InicializarColores();
}

/** @fn void Ejes :: Dibujar ()
 *
 * @brief Envía a la GPU los datos de dibujo de las visualizaciones de los ejes.
 */

void Ejes :: Dibujar () const noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices.data());
	glColorPointer(3, GL_FLOAT, 0, colores.data());

	glDrawArrays(GL_LINES, 0, 6);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/** @fn float Ejes :: Tamanio () const noexcept
 *
 * @brief Consultor del tamaño de los ejes
 * @return Tamaño de los ejes
 */

float Ejes :: Tamanio () const noexcept
{
	return tamanio;
}

/** @fn void Ejes :: NuevoTamanio (float nuevo)
 *
 * @brief Modificador del tamaño de los ejes.
 */

void Ejes :: NuevoTamanio (float tam)
{
	if (tam < 0)
		throw std::invalid_argument("Intento de uso de tamaño negativo en ejes.");

	tamanio = tam;
	InicializarVertices();
}
