#ifndef PRACTICAS_MALLA3D
#define PRACTICAS_MALLA3D

#include <bitset>
#include <stdexcept>
#include "colores.hpp"
#include "motor.hpp"

enum Bitset {
	Flip,
	Reset,
	Set
};

enum Dibujo {
	Diferido,
	Inmediato
};

enum Visualizacion {
	Ajedrez = 0,
	Lineas  = 1,
	Puntos  = 2,
	Solido  = 3
};

class Malla3D {
private:
	std::bitset<4> visualizacion;

	inline void GenerarVBOs () noexcept;

protected:
	std::vector<tuplas::Tupla3i> caras;
	std::vector<tuplas::Tupla3i> caras_ajedrez0;
	std::vector<tuplas::Tupla3i> caras_ajedrez1;
	std::vector<tuplas::Tupla3f> colores_ajedrez0;
	std::vector<tuplas::Tupla3f> colores_ajedrez1;
	std::vector<tuplas::Tupla3f> colores_lineas;
	std::vector<tuplas::Tupla3f> colores_puntos;
	std::vector<tuplas::Tupla3f> colores_solido;
	std::vector<tuplas::Tupla3f> vertices;
	//void CalcularNormales ();

	GLuint vbo_caras            = 0;
	GLuint vbo_caras_ajedrez0   = 0;
	GLuint vbo_caras_ajedrez1   = 0;
	GLuint vbo_colores_ajedrez0 = 0;
	GLuint vbo_colores_ajedrez1 = 0;
	GLuint vbo_colores_lineas   = 0;
	GLuint vbo_colores_puntos   = 0;
	GLuint vbo_colores_solido   = 0;
	GLuint vbo_vertices         = 0;

	inline GLuint VBO (GLuint tipo, GLuint bytes, GLvoid * datos) const noexcept;

	inline void DibujarDiferido  () noexcept;
	inline void DibujarInmediato () const noexcept;

	inline void EnviarAjedrezDiferido  () const noexcept;
	inline void EnviarAjedrezInmediato () const noexcept;
	inline void EnviarDibujoDiferido (GLenum modo, GLuint color) const noexcept;
	inline void EnviarDibujoInmediato
		(GLenum modo, std::vector<tuplas::Tupla3f> color) const noexcept;

	void GenerarAjedrez () noexcept;

public:
	void Dibujar (Dibujo modo) noexcept;

	bool Visualizar (Visualizacion vis) const noexcept;
	void Visualizar (Visualizacion vis, Bitset operacion=Bitset::Flip) noexcept;

	tuplas::Tupla3i              Cara  (const size_t indice) const;
	std::vector<tuplas::Tupla3i> Caras () const noexcept;

	tuplas::Tupla3f              Vertice  (const size_t indice) const;
	std::vector<tuplas::Tupla3f> Vertices () const noexcept;
};

#endif
