#ifndef PRACTICAS_MATERIAL
#define PRACTICAS_MATERIAL

#include "motor.hpp"
#include "tuplasg.hpp"

class Material
{
private:
	Tupla4f ambiente  = {0, 0, 0, 1.0f};
	Tupla4f difuso    = {0, 0, 0, 1.0f};
	Tupla4f especular = {0, 0, 0, 1.0f};
	float   brillo    = 0;

public:
	Material ();
	Material (
		const Tupla3f & amb,
		const Tupla3f & dif,
		const Tupla3f & esp,
		const float bri
	) noexcept;

	void Aplicar () noexcept;
};

#endif
