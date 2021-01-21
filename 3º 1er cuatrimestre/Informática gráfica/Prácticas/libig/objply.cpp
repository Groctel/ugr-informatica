#include "objply.hpp"

ObjPLY :: ObjPLY (const std::string & ruta)
{
	std::ifstream fi                      = PLY::Abrir(ruta);
	std::pair<size_t, size_t> dimensiones = PLY::LeerCabecera(fi);
	vertices                              = PLY::LeerVertices(fi, dimensiones.first);
	caras                                 = PLY::LeerCaras(fi, dimensiones.second);

	InicializarMalla();
}

