/** @file libig/material.hpp
 */

#ifndef PRACTICAS_MATERIAL
#define PRACTICAS_MATERIAL

#include "motor.hpp"
#include "global/tuplasg.hpp"

/** @class Material
 *
 * @brief Reflejador de la Luz sobre la Malla3D.
 */

class Material
{
private:
	Tupla4f ambiente  = {0, 0, 0, 1.0f};
	Tupla4f difuso    = {0, 0, 0, 1.0f};
	Tupla4f especular = {0, 0, 0, 1.0f};
	float   brillo    = 0;

public:
	Material (
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp,
		const float bri
	) noexcept;

	void Aplicar () noexcept;
};

#endif
