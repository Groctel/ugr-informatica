/** @file mallas/cono.hpp
 */

#ifndef PRACTICAS_CONO
#define PRACTICAS_CONO

#include "obj_revolucion.hpp"

/** @class Cono
 *
 * @brief Cono construido a partir de un ObjRevolucion.
 */

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
