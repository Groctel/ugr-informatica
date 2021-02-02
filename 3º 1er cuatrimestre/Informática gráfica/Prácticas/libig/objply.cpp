/** @file libig/objply.cpp
 */

#include "objply.hpp"

/**
 * @brief Constructor a partir de PLY.
 * @param ruta Ruta del fichero PLY.
 */

ObjPLY :: ObjPLY (const std::string & ruta)
{
	std::ifstream fi                      = PLY::Abrir(ruta);
	std::pair<size_t, size_t> dimensiones = PLY::LeerCabecera(fi);
	vertices                              = PLY::LeerVertices(fi, dimensiones.first);
	caras                                 = PLY::LeerCaras(fi, dimensiones.second);

	InicializarMalla();
}

