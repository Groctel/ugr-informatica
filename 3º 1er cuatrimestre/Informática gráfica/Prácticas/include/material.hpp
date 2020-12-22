#ifndef PRACTICAS_MATERIAL
#define PRACTICAS_MATERIAL

#include "motor.hpp"
#include "tuplasg.hpp"

class Material
{
private:
	Tupla4f ambiente;
	Tupla4f difuso;
	Tupla4f especular;
	float   brillo;

public:
	Material ();
	Material (
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp,
		const float bri
	) noexcept;

	void Aplicar () noexcept;
};

#endif
