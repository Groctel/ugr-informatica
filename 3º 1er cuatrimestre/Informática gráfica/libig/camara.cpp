/** @file libig/camara.cpp
 */

#include "camara.hpp"

Camara :: Camara (
	const TipoCamara nuevo_tipo,
	const Tupla3f & nuevo_eye,
	const Tupla3f & nuevo_at,
	const Tupla3f & nuevo_up,
	const float nuevo_near,
	const float nuevo_far
) :
	tipo (nuevo_tipo),
	eye  (nuevo_eye),
	at   (nuevo_at),
	up   (nuevo_up),
	near (nuevo_near),
	far  (nuevo_far)
{ }

float Camara :: Near () const noexcept
{
	return near;
}

float Camara :: Far () const noexcept
{
	return far;
}

float Camara :: Left () const noexcept
{
	return left;
}

float Camara :: Right () const noexcept
{
	return right;
}

float Camara :: Top () const noexcept
{
	return top;
}

float Camara :: Bottom () const noexcept
{
	return bottom;
}

TipoCamara Camara :: Tipo () const noexcept
{
	return tipo;
}

Tupla3f Camara :: Eye () const noexcept
{
	return eye;
}

Tupla3f Camara :: At () const noexcept
{
	return at;
}

Tupla3f Camara :: Up () const noexcept
{
	return up;
}

Malla3D * Camara :: ObjetoFijo () const noexcept
{
	return objeto_fijo;
}

void Camara :: NuevoNear (const float nuevo_near) noexcept
{
	near = nuevo_near;
}

void Camara :: NuevoFar (const float nuevo_far) noexcept
{
	far = nuevo_far;
}

void Camara :: NuevoLeft (const float nuevo_left) noexcept
{
	left = nuevo_left;
}

void Camara :: NuevoRight (const float nuevo_right) noexcept
{
	right = nuevo_right;
}

void Camara :: NuevoTop (const float nuevo_top) noexcept
{
	top = nuevo_top;
}

void Camara :: NuevoBottom (const float nuevo_bottom) noexcept
{
	bottom = nuevo_bottom;
}

void Camara :: NuevoEye (const Tupla3f nuevo_eye) noexcept
{
	eye = nuevo_eye;
}

void Camara :: NuevoAt (const Tupla3f nuevo_at) noexcept
{
	at = nuevo_at;
}

void Camara :: NuevoUp (const Tupla3f nuevo_up) noexcept
{
	up = nuevo_up;
}

void Camara :: Fijar (Malla3D * malla) noexcept
{
	objeto_fijo = malla;
}

void Camara :: Mover (const float x, const float y, const float z) noexcept
{
	at[X] += x;
	at[Y] += y;
	at[Z] += z;

	eye[X] += x;
	eye[Y] += y;
	eye[Z] += z;
}

void Camara :: Observar () const noexcept
{
	gluLookAt(
		eye[X], eye[Y], eye[Z],
		at[X],  at[Y],  at[Z],
		up[X],  up[Y],  up[Z]
	);
}

void Camara :: Proyectar () const noexcept
{
	if (tipo == Perspectiva)
		glFrustum(left, right, bottom, top, near, far);
	else
		glOrtho(left, right, bottom, top, near, far);
}

void Camara :: Zoom (const float factor) noexcept
{
	left   *= factor;
	right  *= factor;
	bottom *= factor;
	top    *= factor;
}

void Camara :: GirarExaminar (const int x, const int y) noexcept
{
	RotarExaminarX(abs(y) * DEG_TO_RAD);
	RotarExaminarY(    x  * DEG_TO_RAD);
}

void Camara :: Girar1raPersona (const int x, const int y) noexcept
{
	Rotar1raPersonaX(-y * DEG_TO_RAD);
	Rotar1raPersonaY(-x * DEG_TO_RAD);
}

void Camara :: RotarExaminarX (const float angulo) noexcept
{
	Tupla3f eye_centro = eye - at;
	float   modulo     = sqrt(eye_centro | eye_centro);

	eye_centro[Y] = cos(angulo) * eye_centro[Y] - sin(angulo) * eye_centro[Z];
	eye_centro[Z] = sin(angulo) * eye_centro[Y] + cos(angulo) * eye_centro[Z];

	eye = eye_centro.Normalizar() * modulo + at;
}

void Camara :: RotarExaminarY (const float angulo) noexcept
{
	Tupla3f eye_centro = eye - at;
	float   modulo     = sqrt(eye_centro | eye_centro);

	eye_centro[X] =  cos(angulo) * eye_centro[X] + sin(angulo) * eye_centro[Z];
	eye_centro[Z] = -sin(angulo) * eye_centro[X] + cos(angulo) * eye_centro[Z];

	eye = eye_centro.Normalizar() * modulo + at;
}

void Camara :: RotarExaminarZ (const float angulo) noexcept
{
	Tupla3f eye_centro = eye - at;
	float   modulo     = sqrt(eye_centro | eye_centro);

	eye_centro[X] = cos(angulo) * eye_centro[X] - sin(angulo) * eye_centro[Y];
	eye_centro[Y] = sin(angulo) * eye_centro[X] + cos(angulo) * eye_centro[Y];

	eye = eye_centro.Normalizar() * modulo + at;
}

void Camara :: Rotar1raPersonaX (const float angulo) noexcept
{
	Tupla3f at_centro = at - eye;
	float   modulo    = sqrt(at_centro | at_centro);

	at_centro[Y] = cos(angulo) * at_centro[Y] - sin(angulo) * at_centro[Z];
	at_centro[Z] = sin(angulo) * at_centro[Y] + cos(angulo) * at_centro[Z];

	at = at_centro.Normalizar() * modulo + eye;
}

void Camara :: Rotar1raPersonaY (const float angulo) noexcept
{
	Tupla3f at_centro = at - eye;
	float   modulo    = sqrt(at_centro | at_centro);

	at_centro[X] =  cos(angulo) * at_centro[X] + sin(angulo) * at_centro[Z];
	at_centro[Z] = -sin(angulo) * at_centro[X] + cos(angulo) * at_centro[Z];

	at = at_centro.Normalizar() * modulo + eye;
}

void Camara :: Rotar1raPersonaZ (const float angulo) noexcept
{
	Tupla3f at_centro = at - eye;
	float   modulo    = sqrt(at_centro | at_centro);

	at_centro[X] = cos(angulo) * at_centro[X] - sin(angulo) * at_centro[Y];
	at_centro[Y] = sin(angulo) * at_centro[X] + cos(angulo) * at_centro[Y];

	at = at_centro.Normalizar() * modulo + eye;
}
