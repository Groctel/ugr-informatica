/** @file malla.hpp
 */

#ifndef PRACTICAS_MALLA3D
#define PRACTICAS_MALLA3D

#include <bitset>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <utility>
#include "colores.hpp"
#include "motor.hpp"

/** @enum Bitset
 *
 * @brief Operaciones realizable sobre un `std::bitset`.
 */

enum Bitset
{
	Flip,
	Reset,
	Set
};

/** @enum Dibujo
 *
 * @brief Modos de envío de las órdenes de dibujo a la GPU.
 */

enum Dibujo
{
	Diferido,
	Inmediato
};

enum VBOColores
{
	Azul    = 0,
	Magenta = 1,
	Negro   = 2,
	Rojo    = 3,
	Verde   = 4
};

enum VBOFormas
{
	Caras    = 0,
	Vertices = 1
};

/** @enum Visualizacion
 *
 * @brief Modos de visualización de los modelos.
 */

enum Visualizacion
{
	Ajedrez = 0,
	Lineas  = 1,
	Puntos  = 2,
	Solido  = 3
};

/** @class Malla3D
 *
 * @brief Malla de caras triangulares de la que heredan el resto de modelos.
 */

class Malla3D
{
private:
	std::bitset<4> visualizacion;

	inline GLuint VBO (const GLuint & tipo, const GLuint & bytes,
		const GLvoid * datos) const noexcept;

	inline void InicializarColor (
		std::vector<tuplas::Tupla3f> & tabla,
		const coloresgl::color & color
	) noexcept;

	inline void InicializarVBOColor (const VBOColores & color) noexcept;

	std::ifstream AbrirFicheroPLY (const std::string & ruta);
	void InterpretarCabeceraPLY   (std::ifstream & fi);
	void InterpretarVerticesPLY   (std::ifstream & fi) noexcept;
	void InterpretarCarasPLY      (std::ifstream & fi) noexcept;

	template <class T>
	inline void RedimensionarDesdePLY (
		const std::string & linea,
		std::vector<T> & tabla
	) noexcept;

protected:
	std::string nombre = "Malla3D";
	static std::vector<tuplas::Tupla3f> tablas_colores[5];

	std::vector<tuplas::Tupla3u> caras;
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
	void GenerarAjedrez     () noexcept;

public:
	Malla3D ();
	Malla3D (const std::string & ruta);

	void Dibujar (Dibujo modo) noexcept;

	bool EstadoVisualizacion (Visualizacion vis) const noexcept;
	void ModificarVisualizacion
		(Visualizacion vis, Bitset operacion=Bitset::Flip) noexcept;

	tuplas::Tupla3u              Cara  (const size_t indice) const;
	std::vector<tuplas::Tupla3u> Caras () const noexcept;

	std::string Nombre () const noexcept;

	tuplas::Tupla3f              Vertice  (const size_t indice) const;
	std::vector<tuplas::Tupla3f> Vertices () const noexcept;
};

#endif
