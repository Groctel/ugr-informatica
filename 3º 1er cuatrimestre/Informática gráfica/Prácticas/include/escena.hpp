/** @file escena.hpp
 */

#ifndef PRACTICAS_ESCENA
#define PRACTICAS_ESCENA

#include <set>
#include <typeinfo>
#include "cilindro.hpp"
#include "cono.hpp"
#include "cubo.hpp"
#include "ejes.hpp"
#include "esfera.hpp"
#include "malla.hpp"
#include "motor.hpp"
#include "objrevolucion.hpp"
#include "tetraedro.hpp"

enum Menu
{
	Inactivo,
	SeleccionDibujado,
	SeleccionObjeto,
	SeleccionVisualizacion,
};

struct Objeto
{
	Malla3D * modelo;
	bool operator  < (const Objeto & otro) const;
	bool operator == (const Objeto & otro) const;
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

	Ejes ejes;

	std::set<Objeto> modelos;
	std::set<Objeto> visibles;
	std::vector<Objeto> seleccionables;

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
