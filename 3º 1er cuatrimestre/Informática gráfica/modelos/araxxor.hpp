#ifndef PRACTICAS_ARAXXOR
#define PRACTICAS_ARAXXOR

#include "modelos/araxxor/cabeza.hpp"
#include "modelos/araxxor/abdomen.hpp"
#include "modelos/araxxor/pata.hpp"

#define PATAS     4
#define derecha   0
#define izquierda 1

enum MovimientosAraxxor
{
	Estatico,
	Abdomen,
	Cabeza,
	Femur,
	Tibia,
	Metatarso,
	Tarso
};

class Araxxor
{
private:
	AbdomenAraxxor * abdomen;
	CabezaAraxxor  * cabeza;
	PataAraxxor    * patas[2][PATAS];

	MovimientosAraxxor movimiento = Tarso;

public:
	 Araxxor () noexcept;
	~Araxxor () noexcept;

	Malla3D * Cuerpo () const noexcept;
	MovimientosAraxxor Movimiento () const noexcept;
	Tupla3f ColorSeleccion () const noexcept;

	void AplicarMaterial (Material * m) noexcept;
	void AplicarTextura  (Textura * nueva) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false,
		const bool marcado=false
	) noexcept;

	void Mover               (const float factor) noexcept;
	void NuevoColorSeleccion (const Tupla3f & color) noexcept;
	void NuevoMovmiento      (const MovimientosAraxxor m) noexcept;
};

#endif
