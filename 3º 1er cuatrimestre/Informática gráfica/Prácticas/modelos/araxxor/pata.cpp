#include "modelos/araxxor/pata.hpp"

PataAraxxor :: PataAraxxor (
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
) noexcept
:
	femur             (new ObjPLY(ruta_femur)),
	tibia             (new ObjPLY(ruta_tibia)),
	metatarso         (new ObjPLY(ruta_metatarso)),
	tarso             (new ObjPLY(ruta_tarso)),
	pos_femur         (nueva_pos_femur),
	vec_rot_femur     (nuevo_vec_rot_femur),
	pos_tibia         (nueva_pos_tibia),
	vec_rot_tibia     (nuevo_vec_rot_tibia),
	pos_metatarso     (nueva_pos_metatarso),
	vec_rot_metatarso (nuevo_vec_rot_metatarso),
	pos_tarso         (nueva_pos_tarso),
	vec_rot_tarso     (nuevo_vec_rot_tarso),
	rotacion_femur    (rot_femur),
	rotacion_tibia    (rot_tibia)
{ }

PataAraxxor :: ~PataAraxxor () noexcept
{
	delete femur;
	delete tibia;
	delete metatarso;
	delete tarso;
}

void PataAraxxor :: AplicarMaterial (Material * m) noexcept
{
	femur->AplicarMaterial(m);
	tibia->AplicarMaterial(m);
	metatarso->AplicarMaterial(m);
	tarso->AplicarMaterial(m);
}

void PataAraxxor :: AplicarTextura  (Textura * nueva, const bool calcular) noexcept
{
	femur->AplicarTextura(nueva, calcular);
	tibia->AplicarTextura(nueva, calcular);
	metatarso->AplicarTextura(nueva, calcular);
	tarso->AplicarTextura(nueva, calcular);
}

void PataAraxxor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion
) noexcept
{
	glPushMatrix();
	{
		glTranslatef(pos_femur[X], pos_femur[Y], pos_femur[Z]);
		glRotatef(sin(rotacion_femur) * 6, 0.3f, 1, 0.25f);

		femur->Dibujar(dibujado, ajedrez, color, seleccion);

		glTranslatef(pos_tibia[X], pos_tibia[Y], pos_tibia[Z]);
		glRotatef(sin(rotacion_tibia) * 10,
			vec_rot_tibia[X],
			vec_rot_tibia[Y],
			vec_rot_tibia[Z]
		);

		tibia->Dibujar(dibujado, ajedrez, color, seleccion);

		glTranslatef(pos_metatarso[X], pos_metatarso[Y], pos_metatarso[Z]);
		glRotatef(
			sin(rotacion_metatarso) * 8,
			vec_rot_metatarso[X],
			vec_rot_metatarso[Y],
			vec_rot_metatarso[Z]
		);

		metatarso->Dibujar(dibujado, ajedrez, color, seleccion);

		glTranslatef(pos_tarso[X], pos_tarso[Y], pos_tarso[Z]);
		glRotatef(
			sin(-rotacion_tarso) * 8,
			vec_rot_tarso[X],
			vec_rot_tarso[Y],
			vec_rot_tarso[Z]
		);

		tarso->Dibujar(dibujado, ajedrez, color, seleccion);
	}
	glPopMatrix();
}

void PataAraxxor :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	femur->NuevoColorSeleccion(color);
	tibia->NuevoColorSeleccion(color);
	metatarso->NuevoColorSeleccion(color);
	tarso->NuevoColorSeleccion(color);
}

void PataAraxxor :: RotarFemur (const float grados) noexcept
{
	rotacion_femur += grados;
}

void PataAraxxor :: RotarTibia (const float grados) noexcept
{
	rotacion_tibia += grados;
}

void PataAraxxor :: RotarMetatarso (const float grados) noexcept
{
	rotacion_metatarso += grados;
}

void PataAraxxor :: RotarTarso (const float grados) noexcept
{
	rotacion_tarso += grados;
}
