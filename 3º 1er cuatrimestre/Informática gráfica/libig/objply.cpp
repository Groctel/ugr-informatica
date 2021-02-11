/** @file libig/objply.cpp
 */

#include "objply.hpp"

/**
 * @brief Constructor a partir de PLY.
 * @param ruta Ruta del fichero PLY.
 */

ObjPLY :: ObjPLY (const std::string & ruta)
{
	std::ifstream fi     = PLY::Abrir(ruta);
	CabeceraPLY cabecera = PLY::LeerCabecera(fi);
	vertices             = PLY::LeerVertices(fi, cabecera);
	caras                = PLY::LeerCaras(fi, cabecera);
	normales             = PLY::LeerNormales(fi, cabecera);
	coord_textura        = PLY::LeerCoordTextura(fi, cabecera);

	InicializarMalla();
}
