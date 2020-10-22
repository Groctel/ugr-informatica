/** @file tetraedro.hpp
 */

#ifndef PRACTICAS_TETRAEDRO
#define PRACTICAS_TETRAEDRO

#include "malla.hpp"
#include "motor.hpp"

/** @class Tetraedro
 *
 * @brief Modelo tridimensional de un tetraedro centrado en el origen.
 */

class Tetraedro : public Malla3D {
private:
	inline void InicializarCaras    () noexcept;
	inline void InicializarVertices (const float escala) noexcept;

public:
	Tetraedro (const float escala=1);
};

#endif
