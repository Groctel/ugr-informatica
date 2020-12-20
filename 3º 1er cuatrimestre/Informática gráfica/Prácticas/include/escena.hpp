/** @file escena.hpp
 */

#ifndef PRACTICAS_ESCENA
#define PRACTICAS_ESCENA

#include <bitset>
#include "cilindro.hpp"
#include "cono.hpp"
#include "cubo.hpp"
#include "ejes.hpp"
#include "esfera.hpp"
#include "malla.hpp"
#include "motor.hpp"
#include "obj_revolucion.hpp"
#include "tetraedro.hpp"

/*
 * OBJETOS VISIBLES EN LA ESCENA:
 * Cada objeto visible en la escena se almacena como una flag en el std::bitset
 * visibles. Estas macros definen el nombre de cada una de estas flags.
 */

#define obj_cilindro  0
#define obj_cono      1
#define obj_cubo      2
#define obj_esfera    3
#define obj_tetraedro 4
#define obj_peon      5

enum Menu
{
	Inactivo,
	SeleccionDibujado,
	SeleccionObjeto,
	SeleccionVisualizacion,
};

class Escena
{
private:
	static Escena * instance;

	bool activa = true;

	GLfloat altura;
	GLfloat anchura;
	GLfloat plano_delantero;
	GLfloat plano_trasero;

	GLfloat angulo_observador_x;
	GLfloat angulo_observador_y;
	GLfloat distancia_observador;

	Menu menu     = Menu::Inactivo;
	Dibujo dibujo = Dibujo::Inmediato;

	Ejes          * ejes      = nullptr;
	Cilindro      * cilindro  = nullptr;
	Cono          * cono      = nullptr;
	Cubo          * cubo      = nullptr;
	Esfera        * esfera    = nullptr;
	Tetraedro     * tetraedro = nullptr;
	ObjRevolucion * peon      = nullptr;

	std::bitset<6> visibles;

	Escena () noexcept;
	Escena (const Escena & otra) = delete;

	void CambiarProyeccion (const float ratio_xy) noexcept;
	void CambiarObservador () noexcept;

	inline void SeleccionDibujado      (unsigned char tecla) noexcept;
	inline void SeleccionMenu          (unsigned char tecla) noexcept;
	inline void SeleccionObjeto        (unsigned char tecla) noexcept;
	inline void SeleccionVisualizacion (unsigned char tecla) noexcept;
	inline void TeclasComunes          (unsigned char tecla) noexcept;

	inline void MsgSeleccionDibujado      (bool reescribir=false) const noexcept;
	inline void MsgSeleccionMenu          () const noexcept;
	inline void MsgSeleccionObjeto        (bool reescribir=false) noexcept;
	inline void MsgSeleccionVisualizacion (bool reescribir=false) const noexcept;
	inline void MsgTeclasComunes          () const noexcept;

	inline void Visualizar (Visualizacion visualizacion) noexcept;

public:
	static Escena * Instance () noexcept;
	~Escena() noexcept;

	void Inicializar (int anchura_ventana, int altura_ventana) noexcept;

	void Dibujar       () noexcept;
	void Redimensionar (int nueva_anchura, int nueva_altura) noexcept;

	bool GestionTeclado         (unsigned char Tecla1, int x, int y) noexcept;
	void GestionTecladoEspecial (int Tecla1, int x, int y) noexcept;
};

#endif
