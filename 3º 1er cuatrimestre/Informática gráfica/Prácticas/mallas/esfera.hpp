#ifndef PRACTICAS_ESFERA
#define PRACTICAS_ESFERA

#include "obj_revolucion.hpp"

class Esfera : public ObjRevolucion {
public:
	Esfera (const float radio, const size_t iteraciones) noexcept;
};

#endif
