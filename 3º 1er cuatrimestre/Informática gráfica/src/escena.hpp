/** @file escena.hpp
 */

#ifndef PRACTICAS_ESCENA
#define PRACTICAS_ESCENA

#include <bitset>
#include <random>
#include <utility>
#include "camara.hpp"
#include "ejes.hpp"
#include "enum.hpp"
#include "luces/luz_direccional.hpp"
#include "luces/luz_posicional.hpp"
#include "mallas/cilindro.hpp"
#include "mallas/cono.hpp"
#include "mallas/cuadro.hpp"
#include "mallas/cubo.hpp"
#include "mallas/esfera.hpp"
#include "mallas/tetraedro.hpp"
#include "malla.hpp"
#include "material.hpp"
#include "modelos/araxxor.hpp"
#include "modelos/flor.hpp"
#include "motor.hpp"
#include "obj_revolucion.hpp"
#include "objply.hpp"

/*
 * OBJETOS VISIBLES EN LA ESCENA:
 * Cada objeto visible en la escena se almacena como una flag en el std::bitset
 * visibles. Estas macros definen el nombre de cada una de estas flags.
 */

#define obj_araxxor   0
#define obj_cielo     1
#define obj_cilindro  2
#define obj_cono      3
#define obj_cubo      4
#define obj_ejes      5
#define obj_flores    6
#define obj_peon      7
#define obj_suelo     8
#define obj_tetraedro 9

/*
 * ÁNGULOS DE LAS LUCES DIRECCIONALES:
 * El ángulo a editar en las luces direccionales se almacena en el std::pair
 * angulo. Estas macros ofrecen una ayuda para referenciarlas.
 */

#define rotx first
#define roty second

// Total de cámaras utilizadas en la escena

#define CAMARAS 3

/*
 * PULSACIONES SOBRE EL RATÓN:
 * Dado que GLUT no registra algunos movimientos del ratón con nombres propios,
 * los definimos aquí para facilitar la lectura.
 */

#define WHEEL_UP   3
#define WHEEL_DOWN 4

#define TAM_SUELO  20
#define CUADRANTES 4

#define FLORES 200

#define seleccion_araxxor   {0, 0, 0}
#define seleccion_cilindro  {0, 0, 1}
#define seleccion_cono      {0, 1, 0}
#define seleccion_cubo      {0, 1, 1}
#define seleccion_peon      {1, 0, 0}
#define seleccion_tetraedro {1, 0, 1}

/** @class Escena
 * @brief Gestor principal de la muestra de todos los objetos en la ventana.
 */

class Escena
{
private:
	static Escena * instance;

	bool activa    = true;
	bool animacion = false;

	float velocidad_animacion = 0.05f;

	GLfloat altura;
	GLfloat anchura;
	GLfloat matriz_vista[16];

	Menu menu         = Menu::Inactivo;
	Dibujo dibujo     = Dibujo::Diferido;
	EstadoRaton raton = Reposo;

	int x_previa = 0;
	int y_previa = 0;

	Araxxor       * araxxor   = nullptr;
	Cilindro      * cilindro  = nullptr;
	Cono          * cono      = nullptr;
	Cubo          * cubo      = nullptr;
	Ejes          * ejes      = nullptr;
	Esfera        * cielo     = nullptr;
	Tetraedro     * tetraedro = nullptr;
	ObjRevolucion * peon      = nullptr;

	float rot_araxxor_y = 180.0f;

	Flor   * flores[FLORES];
	Cuadro * suelo[TAM_SUELO][TAM_SUELO][CUADRANTES];

	LuzDireccional * luz0 = nullptr;
	LuzPosicional  * luz1 = nullptr;
	LuzPosicional  * luz2 = nullptr;

	float rot_luz2 = 0;

	Material * bronce         = nullptr;
	Material * cromo          = nullptr;
	Material * goma_negra     = nullptr;
	Material * estanio        = nullptr;
	Material * laton          = nullptr;
	Material * obsidiana      = nullptr;
	Material * plastico_verde = nullptr;
	Material * turquesa       = nullptr;

	Textura * t_araxxor = nullptr;
	Textura * cesped    = nullptr;
	Textura * lata      = nullptr;
	Textura * tierra    = nullptr;

	Camara * camaras[CAMARAS];
	Camara * camara_activa = camaras[0];

	std::bitset<10> visibles;
	std::bitset<6> visualizacion;
	std::pair<bool, bool> angulos = {false, false};

	Escena () noexcept;
	Escena (const Escena & otra) = delete;

	void AplicarLuces      () noexcept;
	void CambiarProyeccion () const noexcept;
	void CambiarObservador () noexcept;
	void DibujarMallas (
		const unsigned char color,
		const bool ajedrez=false,
		const bool seleccion=false
	) const noexcept;
	Tupla3f TrasladarPerspectiva (const Tupla3f & punto) const noexcept;

	void SeleccionAnimacion     (unsigned char tecla) noexcept;
	void SeleccionCamara        (unsigned char tecla) noexcept;
	void SeleccionDibujado      (unsigned char tecla) noexcept;
	void SeleccionLuces         (unsigned char tecla) noexcept;
	void SeleccionMenu          (unsigned char tecla) noexcept;
	void SeleccionMovimiento    (unsigned char tecla) noexcept;
	void SeleccionObjeto        (unsigned char tecla) noexcept;
	void SeleccionVisualizacion (unsigned char tecla) noexcept;
	void TeclasComunes          (unsigned char tecla) noexcept;

	void MsgSeleccionAnimacion     (bool reescribir=false) const noexcept;
	void MsgSeleccionCamara        (bool reescribir=false) const noexcept;
	void MsgSeleccionDibujado      (bool reescribir=false) const noexcept;
	void MsgSeleccionLuces         (bool reescribir=false) const noexcept;
	void MsgSeleccionMenu          () const noexcept;
	void MsgSeleccionMovimiento    (bool reescribir=false) const noexcept;
	void MsgSeleccionObjeto        (bool reescribir=false) noexcept;
	void MsgSeleccionVisualizacion (bool reescribir=false) const noexcept;
	void MsgTeclasComunes          () const noexcept;

	void SeleccionarMalla (const int x, const int y) noexcept;

public:
	static Escena * Instance () noexcept;
	~Escena () noexcept;

	void Inicializar (int anchura_ventana, int altura_ventana) noexcept;

	void Dibujar             () noexcept;
	void DibujarSeleccion    () noexcept;
	void Redimensionar       (int nueva_anchura, int nueva_altura) noexcept;
	void ReproducirAnimacion () noexcept;

	bool GestionTeclado         (unsigned char Tecla1, int x, int y) noexcept;
	void GestionTecladoEspecial (int Tecla1, int x, int y) noexcept;

	void ClickRaton      (int boton, int estado, int x, int y) noexcept;
	void MovimientoRaton (int x, int y) noexcept;

	bool EstadoVisualizacion    (Visualizacion vis) const noexcept;
	void ModificarVisualizacion (Visualizacion vis) noexcept;
};

#endif
