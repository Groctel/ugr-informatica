#ifndef PRACTICAS_TETRAEDRO
#define PRACTICAS_TETRAEDRO

#include "malla.hpp"
#include "motor.hpp"

class Tetraedro : public Malla3D {
private:
	inline void InicializarCaras    () noexcept;
	inline void InicializarColores  () noexcept;
	inline void InicializarVertices (const float escala) noexcept;

public:
	Tetraedro (const float escala=1);
};

#endif
