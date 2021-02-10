/** @file libig/camara.hpp
 */

#include <string>
#include <vector>
#include "enum.hpp"
#include "global/tuplasg.hpp"
#include "malla.hpp"
#include "motor.hpp"

/** @class Camara
 *
 * @brief Interfaz de proyección de la escena sobre la ventana.
 */

class Camara
{
private:
	TipoCamara tipo;

	Tupla3f eye;
	Tupla3f at;
	Tupla3f up;

	float near;
	float far;
	float left;
	float right;
	float top;
	float bottom;

	Malla3D * objeto_fijo;

public:
	Camara (
		const TipoCamara nuevo_tipo,
		const Tupla3f & nuevo_eye,
		const Tupla3f & nuevo_at,
		const Tupla3f & nuevo_up,
		const float nuevo_near,
		const float nuevo_far
	);

	TipoCamara Tipo () const noexcept;

	float Near   () const noexcept;
	float Far    () const noexcept;
	float Left   () const noexcept;
	float Right  () const noexcept;
	float Top    () const noexcept;
	float Bottom () const noexcept;

	Tupla3f Eye () const noexcept;
	Tupla3f At  () const noexcept;
	Tupla3f Up  () const noexcept;

	Malla3D * ObjetoFijo () const noexcept;

	void NuevoNear   (const float nuevo_near)   noexcept;
	void NuevoFar    (const float nuevo_far)    noexcept;
	void NuevoLeft   (const float nuevo_left)   noexcept;
	void NuevoRight  (const float nuevo_right)  noexcept;
	void NuevoTop    (const float nuevo_top)    noexcept;
	void NuevoBottom (const float nuevo_bottom) noexcept;

	void NuevoAt  (const Tupla3f nuevo_at)  noexcept;
	void NuevoEye (const Tupla3f nuevo_eye) noexcept;
	void NuevoUp  (const Tupla3f nuevo_up)  noexcept;

	void Fijar (Malla3D * malla) noexcept;

	void Mover     (const float x, const float y, const float z) noexcept;
	void Observar  () const noexcept;
	void Proyectar () const noexcept;
	void Zoom      (const float factor) noexcept;

	void GirarExaminar   (const int x, const int y) noexcept;
	void Girar1raPersona (const int x, const int y) noexcept;

	void RotarExaminarX (const float angulo) noexcept;
	void RotarExaminarY (const float angulo) noexcept;
	void RotarExaminarZ (const float angulo) noexcept;

	void Rotar1raPersonaX (const float angulo) noexcept;
	void Rotar1raPersonaY (const float angulo) noexcept;
	void Rotar1raPersonaZ (const float angulo) noexcept;
};
