/** @file libig/objply.hpp
 */

#ifndef PRACTICAS_OBJPLY
#define PRACTICAS_OBJPLY

/** @class ObjPLY
 *
 * @brief Malla3D creada a partir de un fichero PLY.
 */

#include <string>
#include "malla.hpp"
#include "ply.hpp"

class ObjPLY : public Malla3D
{
public:
	ObjPLY (const std::string & ruta);
};

#endif
