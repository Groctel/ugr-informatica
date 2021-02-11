/** @file malla.hpp
 */

#ifndef PRACTICAS_MALLA3D
#define PRACTICAS_MALLA3D

#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <utility>
#include "enum.hpp"
#include "global/colores.hpp"
#include "global/globals.hpp"
#include "global/tuplasg.hpp"
#include "material.hpp"
#include "motor.hpp"
#include "textura.hpp"

/*
 * COLORES PARA PINTAR LA MALLA:
 * Cada color corresponde con un elemento del vector de colores. El color
 * incoloro provoca un segfault al acceder a él, por lo que hay que comprobar
 * que no se esté usando.
 */

#define COLORES 6

#define incoloro ~0
#define amarillo  0
#define azul      1
#define magenta   2
#define negro     3
#define rojo      4
#define verde     5

/** @class Malla3D
 * @brief Malla de caras triangulares de la que heredan el resto de modelos.
 */

class Malla3D
{
private:
	Tupla3f centro             = {0, 0, 0};
	Tupla3f centro_perspectiva = {0, 0, 0};

	static Material * material_pdef;
	Material * material = nullptr;

	void InicializarColor (
		std::vector<Tupla3f> & tabla,
		const RGB & color
	) noexcept;

	void CalcularCentro     () noexcept;
	void CalcularNormales   () noexcept;
	void InicializarColores () noexcept;

	virtual void GenerarAjedrez () noexcept;

protected:
	static std::vector<Tupla3f> tablas_colores[COLORES];
	       std::vector<Tupla3f> color_seleccion;

	std::vector<Tupla3u> caras;
	std::vector<Tupla3f> vertices;
	std::vector<Tupla3f> normales;

	Textura * textura = nullptr;
	std::vector<Tupla2f> coord_textura;

	GLuint vbo_colores[COLORES]                 = {0};
	GLuint vbo_color_seleccion                  = 0;
	GLuint vbo_caras                            = 0;
	GLuint vbo_vertices                         = 0;
	GLuint vbo_normales                         = 0;
	std::pair<GLuint, GLuint> vbo_caras_ajedrez = {0,0};

	void DibujarDiferido  (const unsigned char color) noexcept;
	void DibujarInmediato (const unsigned char color) noexcept;
	void DibujarSeleccion (const Dibujo dibujado) noexcept;

	virtual void DibujarAjedrezDiferido  () noexcept;
	virtual void DibujarAjedrezInmediato () const noexcept;
	virtual void EnviarDibujoDiferido    () noexcept;
	virtual void EnviarDibujoInmediato   () const noexcept;

	void InicializarMalla    () noexcept;
	void InicializarVBOColor (const unsigned char color) noexcept;

	GLuint VBO (const GLuint & tipo, const GLuint & bytes,
		const GLvoid * datos) const noexcept;

public:
	         Malla3D () noexcept;
	virtual ~Malla3D () noexcept;

	void AplicarMaterial (Material * nuevo) noexcept;
	void AplicarTextura  (Textura * nueva) noexcept;
	void Invertir        () noexcept;

	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false,
		const bool marcado=false
	) noexcept;

	void NuevoColorSeleccion (const Tupla3f & color) noexcept;

	Tupla3u              Cara     (const size_t indice) const;
	std::vector<Tupla3u> Caras    () const noexcept;

	Tupla3f Centro         () const noexcept;
	Tupla3f ColorSeleccion () const noexcept;

	Tupla3f              Vertice  (const size_t indice) const;
	std::vector<Tupla3f> Vertices () const noexcept;

	Tupla3f              Normal   (const size_t indice) const;
	std::vector<Tupla3f> Normales () const noexcept;
};

#endif
