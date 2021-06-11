#ifndef PRACTICAS_COLORES
#define PRACTICAS_COLORES

#include "tuplasg.hpp"

typedef Tupla3f RGB;

#define RGBAmarillo Tupla3f(1, 1, 0)
#define RGBAzul     Tupla3f(0, 0, 1)
#define RGBCian     Tupla3f(0, 1, 1)
#define RGBBlanco   Tupla3f(1, 1, 1)
#define RGBMagenta  Tupla3f(1, 0, 1)
#define RGBNegro    Tupla3f(0, 0, 0)
#define RGBRojo     Tupla3f(1, 0, 0)
#define RGBVerde    Tupla3f(0, 1, 0)

#define TermNormal   "\x1B[0m"
#define TermRojo     "\x1B[31m"
#define TermVerde    "\x1B[32m"
#define TermMarillo  "\x1B[33m"
#define TermAzul     "\x1B[34m"
#define TermMagenta  "\x1B[35m"
#define TermCian     "\x1B[36m"
#define TermBlanco   "\x1B[37m"

#define TermNormalB   "\x1B[0;1m"
#define TermRojoB     "\x1B[31;1m"
#define TermVerdeB    "\x1B[32;1m"
#define TermAmarilloB "\x1B[33;1m"
#define TermAzulB     "\x1B[34;1m"
#define TermMagentaB  "\x1B[35;1m"
#define TermCianB     "\x1B[36;1m"
#define TermBlancoB   "\x1B[37;1m"

#endif
