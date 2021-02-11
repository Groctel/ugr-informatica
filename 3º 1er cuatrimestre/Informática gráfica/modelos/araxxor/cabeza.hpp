#ifndef PRACTICAS_ARAXXOR_CABEZA
#define PRACTICAS_ARAXXOR_CABEZA

#include "modelos/araxxor/colmillo.hpp"
#include "objply.hpp"

class CabezaAraxxor
{
private:
	ObjPLY * cabeza;
	float pos_x = 0;
	float pos_y = 0;
	float pos_z = 0;

	ColmilloAraxxor * colmillo_derecho;
	ColmilloAraxxor * colmillo_izquierdo;

public:
	 CabezaAraxxor () noexcept;
	~CabezaAraxxor () noexcept;

	void AplicarMaterial (Material * m) noexcept;
	void AplicarTextura  (Textura * nueva) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false,
		const bool marcado=false
	) noexcept;

	void NuevoColorSeleccion (const Tupla3f & color) noexcept;

	void Mover (const float despl) noexcept;
};

#endif


