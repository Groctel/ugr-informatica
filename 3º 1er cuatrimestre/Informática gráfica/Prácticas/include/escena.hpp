/** @file escena.hpp
 */

#ifndef PRACTICAS_ESCENA
#define PRACTICAS_ESCENA

#include <set>
#include "cilindro.hpp"
#include "cono.hpp"
#include "cubo.hpp"
#include "ejes.hpp"
#include "esfera.hpp"
#include "malla.hpp"
#include "motor.hpp"
#include "objrevolucion.hpp"
#include "tetraedro.hpp"

#define objeto  first
#define visible second

enum Objetos
{
	_Cilindro  = 1,
	_Cono      = 2,
	_Cubo      = 3,
	_Esfera    = 4,
	_Tetraedro = 5,
	_Peon      = 6
};

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

	Ejes          ejes;

	std::pair<Cilindro,      bool> cilindro;
	std::pair<Cono,          bool> cono;
	std::pair<Cubo,          bool> cubo;
	std::pair<Esfera,        bool> esfera;
	std::pair<Tetraedro,     bool> tetraedro;
	std::pair<ObjRevolucion, bool> peon;

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
