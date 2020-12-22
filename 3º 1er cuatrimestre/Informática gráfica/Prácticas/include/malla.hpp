/** @file malla.hpp
 */

#ifndef PRACTICAS_MALLA3D
#define PRACTICAS_MALLA3D

#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <utility>
#include "colores.hpp"
#include "material.hpp"
#include "motor.hpp"
#include "ply.hpp"

/*
 * COLORES PARA PINTAR LA MALLA:
 * Cada color corresponde con un elemento del vector de colores. El color
 * incoloro provoca un segfault al acceder a él, por lo que hay que comprobar
 * que no se esté usando.
 */

#define incoloro -1
#define azul     0
#define magenta  1
#define negro    2
#define rojo     3
#define verde    4

/** @enum Dibujo
 *
 * @brief Modos de envío de las órdenes de dibujo a la GPU.
 */

enum Dibujo
{
	Diferido,
	Inmediato
};

/** @class Malla3D
 *
 * @brief Malla de caras triangulares de la que heredan el resto de modelos.
 */

class Malla3D
{
private:
	Material material;

	GLuint VBO (const GLuint & tipo, const GLuint & bytes,
		const GLvoid * datos) const noexcept;

	void InicializarColor (
		std::vector<Tupla3f> & tabla,
		const coloresgl::color & color
	) noexcept;

	void CalcularNormales    () noexcept;
	void GenerarAjedrez      () noexcept;
	void InicializarColores  () noexcept;
	void InicializarVBOColor (const unsigned char color) noexcept;

protected:
	static std::vector<Tupla3f> tablas_colores[5];

	std::vector<Tupla3u> caras;
	std::vector<Tupla3f> vertices;
	std::vector<Tupla3f> normales;

	GLuint vbo_colores[5] = {0};
	GLuint vbo_caras      = 0;
	GLuint vbo_vertices   = 0;
	GLuint vbo_normales   = 0;
	std::pair<GLuint, GLuint> vbo_caras_ajedrez = {0,0};

	void DibujarDiferido         (const unsigned char color) noexcept;
	void DibujarInmediato        (const unsigned char color) noexcept;
	void DibujarAjedrezDiferido  () noexcept;
	void DibujarAjedrezInmediato () const noexcept;

	void InicializarMalla () noexcept;

public:
	Malla3D ();
	Malla3D (const std::string & ruta);

	void AplicarMaterial (Material nuevo) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez,
		const unsigned char color) noexcept;

	Tupla3u              Cara  (const size_t indice) const;
	std::vector<Tupla3u> Caras () const noexcept;

	Tupla3f              Vertice  (const size_t indice) const;
	std::vector<Tupla3f> Vertices () const noexcept;
};

#endif
