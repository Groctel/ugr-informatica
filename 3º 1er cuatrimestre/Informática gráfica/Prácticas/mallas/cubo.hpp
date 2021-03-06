/** @file mallas/cubo.hpp
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
	void InicializarCaras        () noexcept;
	void InicializarCoordTextura () noexcept;
	void InicializarVertices     () noexcept;

public:
	Cubo () noexcept;
};

#endif
