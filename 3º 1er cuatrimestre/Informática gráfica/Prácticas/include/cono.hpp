#ifndef PRACTICAS_CONO
#define PRACTICAS_CONO

#include "objrevolucion.hpp"

class Cono : public ObjRevolucion
{
public:
	Cono (
		const float radio,
		const float altura,
		const size_t divisiones,
		const size_t iteraciones
	) noexcept;
};

#endif
