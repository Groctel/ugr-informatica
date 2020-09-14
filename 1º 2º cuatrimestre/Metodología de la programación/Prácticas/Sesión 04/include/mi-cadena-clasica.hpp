/** @file mi_cadena_clasica.hpp
  */

#pragma once

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool Palindromo (const char * cadena);

int CompararCadenas (const char * una, const char * otra);
int LongitudCadena  (const char * cadena);

char * CopiarCadena              (char * destino, const char * origen);
char * EncadenarCadena           (char * destino, const char * origen);
char * EliminaBlancosIniciales   (char * destino, const char * origen);
char * EliminaBlancosFinales     (char * destino, const char * origen);
char * EliminaBlancosExtremos    (char * destino, const char * origen);
char * EliminaBlancosIntermedios (char * destino, const char * origen);
char * EliminaTodosBlancos       (char * destino, const char * origen);
char * Invertir                  (char * destino, const char * origen);
char * Subcadena                 (char * destino, const char * origen,
                                  int pos, int lon);
