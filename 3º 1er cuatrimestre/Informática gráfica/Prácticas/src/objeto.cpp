#include "objeto.hpp"

Objeto :: Objeto () noexcept
{ }

Objeto :: Objeto (Malla3D * nuevo_modelo, std::string nuevo_nombre) noexcept
:
	modelo (nuevo_modelo),
	nombre (nuevo_nombre)
{ }

Objeto :: Objeto (const Objeto & otro) noexcept
{
	*this = otro;
}

Objeto :: ~Objeto () noexcept
{ }

Malla3D * Objeto :: Modelo () const noexcept
{
	return modelo;
}

std::string Objeto :: Nombre () const noexcept
{
	return nombre;
}

const float * Objeto :: Escalado () const noexcept
{
	return escalado;
}

const float * Objeto :: Rotacion () const noexcept
{
	return rotacion;
}

const float * Objeto :: Traslacion () const noexcept
{
	return traslacion;
}


bool Objeto :: operator < (const Objeto & otro) const noexcept
{
	return modelo < otro.modelo;
}

Objeto * Objeto :: operator = (const Objeto & otro) noexcept
{
	modelo = otro.modelo;
	nombre = otro.nombre;

	for (unsigned char i = 0; i < 3; i++)
		escalado[i] = otro.escalado[i];

	for (unsigned char i = 0; i < 4; i++)
		rotacion[i] = otro.rotacion[i];

	for (unsigned char i = 0; i < 3; i++)
		traslacion[i] = otro.traslacion[i];

	return this;
}

void Objeto :: Escalar (
	const float x, const float y, const float z
) noexcept
{
	escalado[0] = x;
	escalado[1] = y;
	escalado[2] = z;
}

void Objeto :: Rotar (
	const float angulo, const float x, const float y, const float z
) noexcept
{
	rotacion [0] = angulo;
	rotacion [1] = x;
	rotacion [2] = y;
	rotacion [3] = z;
}

void Objeto :: Trasladar (
	const float x, const float y, const float z
) noexcept
{
	traslacion[0] = x;
	traslacion[1] = y;
	traslacion[2] = z;
}

void Objeto :: LiberarMalla () noexcept
{
	delete modelo;
}
