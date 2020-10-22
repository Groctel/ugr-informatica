/** @file malla.hpp
 */

#ifndef PRACTICAS_MALLA3D
#define PRACTICAS_MALLA3D

#include <bitset>
#include <stdexcept>
#include <utility>
#include "colores.hpp"
#include "motor.hpp"

/** @enum Bitset
 *
 * @brief Operaciones realizable sobre un `std::bitset`.
 */

enum Bitset {
	Flip,
	Reset,
	Set
};

/** @enum Dibujo
 *
 * @brief Modos de envío de las órdenes de dibujo a la GPU.
 */

enum Dibujo {
	Diferido,
	Inmediato
};

enum VBOColores {
	Azul    = 0,
	Magenta = 1,
	Negro   = 2,
	Rojo    = 3,
	Verde   = 4
};

enum VBOFormas {
	Caras    = 0,
	Vertices = 1
};

/** @enum Visualizacion
 *
 * @brief Modos de visualización de los modelos.
 */

enum Visualizacion {
	Ajedrez = 0,
	Lineas  = 1,
	Puntos  = 2,
	Solido  = 3
};

/** @class Malla3D
 *
 * @brief Malla de caras triangulares de la que heredan el resto de modelos.
 */

class Malla3D {
private:
	std::bitset<4> visualizacion;

	inline GLuint VBO (const GLuint & tipo, const GLuint & bytes,
		const GLvoid * datos) const noexcept;

	inline void InicializarColor (
		std::vector<tuplas::Tupla3f> & tabla,
		const coloresgl::color & color
	) noexcept;

	inline void InicializarVBOColor (const VBOColores & color) noexcept;

protected:
	static std::vector<tuplas::Tupla3f> tablas_colores[5];

	std::vector<tuplas::Tupla3i> caras;
	std::vector<tuplas::Tupla3f> vertices;

	GLuint vbo_colores[5];
	GLuint vbo_caras    = 0;
	GLuint vbo_vertices = 0;
	std::pair<GLuint, GLuint> vbo_caras_ajedrez = {0,0};
	//
	//void CalcularNormales ();

	inline void DibujarDiferido  () noexcept;
	inline void DibujarInmediato () const noexcept;

	inline void EnviarAjedrezDiferido  () noexcept;
	inline void EnviarAjedrezInmediato () const noexcept;
	inline void EnviarDibujoDiferido (GLenum modo, VBOColores color) noexcept;
	inline void EnviarDibujoInmediato
		(GLenum modo, std::vector<tuplas::Tupla3f> color) const noexcept;

	void InicializarColores () noexcept;

public:
	void Dibujar (Dibujo modo) noexcept;

	bool EstadoVisualizacion (Visualizacion vis) const noexcept;
	void ModificarVisualizacion
		(Visualizacion vis, Bitset operacion=Bitset::Flip) noexcept;

	tuplas::Tupla3i              Cara  (const size_t indice) const;
	std::vector<tuplas::Tupla3i> Caras () const noexcept;

	tuplas::Tupla3f              Vertice  (const size_t indice) const;
	std::vector<tuplas::Tupla3f> Vertices () const noexcept;
};

#endif
