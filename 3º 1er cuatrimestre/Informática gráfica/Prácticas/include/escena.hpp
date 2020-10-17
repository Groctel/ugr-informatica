#ifndef PRACTICAS_ESCENA
#define PRACTICAS_ESCENA

#include "cubo.hpp"
#include "ejes.hpp"
#include "malla.hpp"
#include "motor.hpp"
#include "tetraedro.hpp"

enum Menu {
	Inactivo,
	SeleccionDibujado,
	SeleccionObjeto,
	SeleccionVisualizacion,
};

class Escena {
private:
	static Escena * instance;

	bool activa = true;

	GLfloat Observer_distance;
	GLfloat Observer_angle_x;
	GLfloat Observer_angle_y;
	GLfloat Width;
	GLfloat Height;
	GLfloat Front_plane;
	GLfloat Back_plane;

	Menu menu = Menu::Inactivo;
	Dibujo dibujo = Dibujo::Inmediato;
	Ejes ejes;

	/*
	 * TODO: ESTA SOLUCIÓN DE MUESTRA DE OBJETOS ES EFECTIVA PERO POCO ESCALABLE.
	 * BUSCAR UNA FORMA DE ENCONTRAR OBJETOS DE UNA SUBCLASE EN UN VECTOR DE
	 * SU SUPERCLASE USANDO TYPEID Y FIND.
	 */

	Cubo * cubo           = nullptr;
	Tetraedro * tetraedro = nullptr;

	bool mostrar_cubo      = false;
	bool mostrar_tetraedro = false;

	Escena ();
	Escena (const Escena & otra) = delete;

	void CambiarProyeccion (const float ratio_xy);
	void change_observer ();

	inline void SeleccionDibujado      (unsigned char tecla) noexcept;
	inline void SeleccionMenu          (unsigned char tecla) noexcept;
	inline void SeleccionObjeto        (unsigned char tecla) noexcept;
	inline void SeleccionVisualizacion (unsigned char tecla) noexcept;
	inline void TeclasComunes          (unsigned char tecla) noexcept;

	inline void MsgSeleccionDibujado      (bool reescribir=false) const noexcept;
	inline void MsgSeleccionMenu          (bool reescribir=false) const noexcept;
	inline void MsgSeleccionObjeto        (bool reescribir=false) const noexcept;
	inline void MsgSeleccionVisualizacion (bool reescribir=false) const noexcept;
	inline void MsgTeclasComunes          () const noexcept;

	inline void Visualizar (Visualizacion visualizacion) noexcept;

public:
	static Escena * Instance ();
	~Escena();

	void Inicializar (int UI_window_width, int UI_window_height);

	void Dibujar       ();
	void Redimensionar (int newWidth, int newHeight);

	bool GestionTeclado         (unsigned char Tecla1, int x, int y);
	void GestionTecladoEspecial (int Tecla1, int x, int y);
};

#endif
