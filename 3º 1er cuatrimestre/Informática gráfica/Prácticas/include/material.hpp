#ifndef PRACTICAS_MATERIAL
#define PRACTICAS_MATERIAL

#include "motor.hpp"
#include "tuplasg.hpp"

class Material
{
private:
	float   brillo;
	Tupla4f ambiente;
	Tupla4f difuso;
	Tupla4f especular;

public:
	Material ();
	Material (
		const float bri,
		const Tupla4f & amb,
		const Tupla4f & dif,
		const Tupla4f & esp
	) noexcept;

	void Aplicar () noexcept;
};

#endif
