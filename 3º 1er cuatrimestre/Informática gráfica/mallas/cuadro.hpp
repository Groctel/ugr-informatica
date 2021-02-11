/** @file mallas/cuadro.hpp
 */

#ifndef PRACTICAS_CUADRO
#define PRACTICAS_CUADRO

#include "malla.hpp"
#include "motor.hpp"

/** @class Cuadro
 *
 * @brief Modelo tridimensional de un cuadro centrado en el origen.
 */

class Cuadro : public Malla3D
{
private:
	inline void InicializarCaras    () noexcept;
	inline void InicializarVertices () noexcept;

public:
	Cuadro () noexcept;
};

#endif

