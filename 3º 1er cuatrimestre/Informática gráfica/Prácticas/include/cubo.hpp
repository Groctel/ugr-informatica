/** @file cubo.hpp
 */

#ifndef PRACTICAS_CUBO
#define PRACTICAS_CUBO

#include "malla.hpp"
#include "motor.hpp"

/** @class Cubo
 *
 * @brief Modelo tridimensional de un cubo centrado en el origen.
 */

class Cubo : public Malla3D
{
private:
	inline void InicializarCaras    () noexcept;
	inline void InicializarVertices (const float escala) noexcept;

public:
	Cubo (const float escala=1) noexcept;
};

#endif
