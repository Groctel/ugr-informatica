#ifndef PRACTICAS_ARAXXOR_PATA
#define PRACTICAS_ARAXXOR_PATA

#include <string>
#include "objply.hpp"

class PataAraxxor
{
private:
	ObjPLY * femur     = nullptr;
	ObjPLY * tibia     = nullptr;
	ObjPLY * metatarso = nullptr;
	ObjPLY * tarso     = nullptr;

	Tupla3f pos_femur     = {0, 0, 0};
	Tupla3f vec_rot_femur = {0, 0, 0};

	Tupla3f pos_tibia     = {0, 0, 0};
	Tupla3f vec_rot_tibia = {0, 0, 0};

	Tupla3f pos_metatarso     = {0, 0, 0};
	Tupla3f vec_rot_metatarso = {0, 0, 0};

	Tupla3f pos_tarso     = {0, 0, 0};
	Tupla3f vec_rot_tarso = {0, 0, 0};

	float rotacion_femur     = 0;
	float rotacion_tibia     = 0;
	float rotacion_metatarso = 0;
	float rotacion_tarso     = 0;

public:
	 PataAraxxor (
		std::string ruta_femur,
		std::string ruta_tibia,
		std::string ruta_metatarso,
		std::string ruta_tarso,
		Tupla3f nueva_pos_femur,
		Tupla3f nuevo_vec_rot_femur,
		Tupla3f nueva_pos_tibia,
		Tupla3f nuevo_vec_rot_tibia,
		Tupla3f nueva_pos_metatarso,
		Tupla3f nuevo_vec_rot_metatarso,
		Tupla3f nueva_pos_tarso,
		Tupla3f nuevo_vec_rot_tarso,
		float rot_femur,
		float rot_tibia
	) noexcept;
	~PataAraxxor () noexcept;

	void AplicarMaterial (Material * m) noexcept;
	void AplicarTextura  (Textura * nueva, const bool calcular) noexcept;
	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez=false,
		const unsigned char color=incoloro,
		const bool seleccion=false
	) noexcept;

	void NuevoColorSeleccion (const Tupla3f & color) noexcept;

	void RotarFemur     (const float grados) noexcept;
	void RotarTibia     (const float grados) noexcept;
	void RotarMetatarso (const float grados) noexcept;
	void RotarTarso     (const float grados) noexcept;
};

#endif

