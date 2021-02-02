/** @file escena.hpp
 */

#ifndef PRACTICAS_ESCENA
#define PRACTICAS_ESCENA

#include <bitset>
#include <utility>
#include "ejes.hpp"
#include "luces/luz_direccional.hpp"
#include "luces/luz_posicional.hpp"
#include "mallas/cilindro.hpp"
#include "mallas/cono.hpp"
#include "mallas/cubo.hpp"
#include "mallas/esfera.hpp"
#include "mallas/tetraedro.hpp"
#include "malla.hpp"
#include "material.hpp"
#include "modelo-jerarquico/jirafa.hpp"
#include "motor.hpp"
#include "obj_revolucion.hpp"

/*
 * OBJETOS VISIBLES EN LA ESCENA:
 * Cada objeto visible en la escena se almacena como una flag en el std::bitset
 * visibles. Estas macros definen el nombre de cada una de estas flags.
 */

#define obj_cilindro  0
#define obj_cono      1
#define obj_cubo      2
#define obj_esfera    3
#define obj_jirafa    4
#define obj_tetraedro 5
#define obj_peon      6

/*
 * ÁNGULOS DE LAS LUCES DIRECCIONALES:
 * El ángulo a editar en las luces direccionales se almacena en el std::pair
 * angulo. Estas macros ofrecen una ayuda para referenciarlas.
 */

#define rotx first
#define roty second

/** @enum Menu
 * @brief Estado actual del menú de control de la escena.
 */

enum Menu
{
	Inactivo,
	SeleccionDibujado,
	SeleccionLuces,
	SeleccionObjeto,
	SeleccionVisualizacion,
};

/** @enum Visualizacion
 * @brief Modos de visualización de los modelos.
 */

enum Visualizacion
{
	Ajedrez     = 0,
	Lineas      = 1,
	Puntos      = 2,
	Solido      = 3,
	Iluminacion = 4,
	Texturas    = 5,
};

/** @class Escena
 * @brief Gestor principal de la muestra de todos los objetos en la ventana.
 */

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
	Dibujo dibujo = Dibujo::Diferido;

	Ejes          * ejes      = nullptr;
	Cilindro      * cilindro  = nullptr;
	Cono          * cono      = nullptr;
	Cubo          * cubo      = nullptr;
	Esfera        * esfera    = nullptr;
	Jirafa        * jirafa    = nullptr;
	Tetraedro     * tetraedro = nullptr;
	ObjRevolucion * peon      = nullptr;

	LuzDireccional * luz0 = nullptr;
	LuzPosicional  * luz1 = nullptr;

	Material * cromo      = nullptr;
	Material * goma_negra = nullptr;
	Material * estanio    = nullptr;
	Material * laton      = nullptr;
	Material * obsidiana  = nullptr;
	Material * turquesa   = nullptr;

	Textura * madera = nullptr;

	std::bitset<7> visibles;
	std::bitset<6> visualizacion;
	std::pair<bool, bool> angulos = {false, false};

	Escena () noexcept;
	Escena (const Escena & otra) = delete;

	void AplicarLuces      () noexcept;
	void CambiarProyeccion (const float ratio_xy) noexcept;
	void CambiarObservador () noexcept;
	void DibujarMallas (
		const unsigned char color,
		const bool ajedrez=false
	) const noexcept;

	void SeleccionDibujado      (unsigned char tecla) noexcept;
	void SeleccionLuces         (unsigned char tecla) noexcept;
	void SeleccionMenu          (unsigned char tecla) noexcept;
	void SeleccionObjeto        (unsigned char tecla) noexcept;
	void SeleccionVisualizacion (unsigned char tecla) noexcept;
	void TeclasComunes          (unsigned char tecla) noexcept;

	void MsgSeleccionDibujado      (bool reescribir=false) const noexcept;
	void MsgSeleccionLuces         (bool reescribir=false) const noexcept;
	void MsgSeleccionMenu          () const noexcept;
	void MsgSeleccionObjeto        (bool reescribir=false) noexcept;
	void MsgSeleccionVisualizacion (bool reescribir=false) const noexcept;
	void MsgTeclasComunes          () const noexcept;

public:
	static Escena * Instance () noexcept;
	~Escena () noexcept;

	void Inicializar (int anchura_ventana, int altura_ventana) noexcept;

	void Dibujar       () noexcept;
	void Redimensionar (int nueva_anchura, int nueva_altura) noexcept;

	bool GestionTeclado         (unsigned char Tecla1, int x, int y) noexcept;
	void GestionTecladoEspecial (int Tecla1, int x, int y) noexcept;

	bool EstadoVisualizacion    (Visualizacion vis) const noexcept;
	void ModificarVisualizacion (Visualizacion vis) noexcept;
};

#endif
