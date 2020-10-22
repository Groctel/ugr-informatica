#ifndef PRACTICAS_COLORES
#define PRACTICAS_COLORES

#include "tuplasg.hpp"

namespace coloresgl {

typedef tuplas::Tupla3f color;

const tuplas::Tupla3f AMARILLO = tuplas::Tupla3f(1, 1, 0);
const tuplas::Tupla3f AZUL     = tuplas::Tupla3f(0, 0, 1);
const tuplas::Tupla3f CIAN     = tuplas::Tupla3f(0, 1, 1);
const tuplas::Tupla3f BLANCO   = tuplas::Tupla3f(1, 1, 1);
const tuplas::Tupla3f MAGENTA  = tuplas::Tupla3f(1, 0, 1);
const tuplas::Tupla3f NEGRO    = tuplas::Tupla3f(0, 0, 0);
const tuplas::Tupla3f ROJO     = tuplas::Tupla3f(1, 0, 0);
const tuplas::Tupla3f VERDE    = tuplas::Tupla3f(0, 1, 0);

} // namespace coloresgl

namespace coloresterm {

const char * const NORMAL   = "\x1B[0m";
const char * const ROJO     = "\x1B[31m";
const char * const VERDE    = "\x1B[32m";
const char * const AMARILLO = "\x1B[33m";
const char * const AZUL     = "\x1B[34m";
const char * const MAGENTA  = "\x1B[35m";
const char * const CIAN     = "\x1B[36m";
const char * const BLANCO   = "\x1B[37m";

const char * const NORMAL_B   = "\x1B[0;1m";
const char * const ROJO_B     = "\x1B[31;1m";
const char * const VERDE_B    = "\x1B[32;1m";
const char * const AMARILLO_B = "\x1B[33;1m";
const char * const AZUL_B     = "\x1B[34;1m";
const char * const MAGENTA_B  = "\x1B[35;1m";
const char * const CIAN_B     = "\x1B[36;1m";
const char * const BLANCO_B   = "\x1B[37;1m";

} // namespace coloresterm

#endif
