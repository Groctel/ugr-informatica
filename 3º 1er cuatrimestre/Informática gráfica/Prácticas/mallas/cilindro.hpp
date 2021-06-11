/** @file mallas/cilindro.hpp
 */

#ifndef PRACTICAS_CILINDRO
#define PRACTICAS_CILINDRO

#include "obj_revolucion.hpp"

/** @class Cilindro
 *
 * @brief Cilindro construido a partir de un ObjRevolucion.
 */

class Cilindro : public ObjRevolucion {
public:
	Cilindro (
		const float radio,
		const float altura,
		const size_t divisiones,
		const size_t iteraciones
	) noexcept;
};

#endif
