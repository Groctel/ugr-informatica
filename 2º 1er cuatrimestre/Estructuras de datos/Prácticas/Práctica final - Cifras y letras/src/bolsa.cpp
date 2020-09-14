/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file src/bolsa.cpp
  */

#include "bolsa.hpp"

/** @brief Constructor por defecto
  *
  * Crea una bolsa vacía sin espacio.
  */

Bolsa :: Bolsa ()
	:max (0),
	 tam (0)
{ }

/** @brief Constructor con argumento
  *
  * Crea uan bolsa vacía con un máximo de caracteres determinado.
  *
  * @param m Máximo de caracteres
  */

Bolsa :: Bolsa (const unsigned m)
	:max (m),
	 tam (0)
{ }

/** @brief Constructor de copia
  *
  * Crea una bolsa con los valores de la bolsa pasada como argumento.
  *
  * @param otra Referencia constante a la bolsa que se va a copiar
  */

Bolsa :: Bolsa (const Bolsa & otra)
	:max        (otra.max),
	 tam        (otra.tam),
	 letras     (otra.letras)
{ }

/** @brief Consultor del tamaño total de la bolsa
  *
  * @return Tamaño total de la bolsa
  */

unsigned Bolsa :: Max () const {
	return max;
}

/** @brief Consultor del tamaño actual de la bolsa
  *
  * @return Tamaño actual de la bolsa
  */

unsigned Bolsa :: Tam () const {
	return tam;
}

/** @brief Consultor del contenedor subyacente
  *
  * @return Vector de letras de la bolsa
  */

std::vector<char> Bolsa :: Letras () const {
	return letras;
}

/** @brief Asignador de nuevo carácter a la bolsa
  *
  * Añade un carácter a la bolsa.
  *
  * @param c Carácter que se va a añadir
  */

void Bolsa :: Aniade (const char c) {
	letras.push_back(c);
	tam++;
}

/** @brief Asignador de valor máximo de la bolsa
  *
  * Asigna un nuevo calor máximo a la bolsa. Si existen valores por encima de
  * este nuevo máximo, se eliminan.
  *
  * @param m Valor máximo que se va a asignar
  */

void Bolsa :: NuevoMax (const unsigned m) {
	max = m;

	if (tam > max)
		letras.erase(letras.begin()+max, letras.end());

	tam = max;
}

/** @brief Permutador del contenedor subyacente
  *
  * Genera una nueva permutación de la bolsa de letras
  *
  * @return Condición de orden menor de la permutación actual con respecto a la
  * anterior (última permutación posible)
  */

bool Bolsa :: Siguiente () {
	return std::next_permutation(letras.begin(), letras.end());
}

/** @brief Operador de asignación
  *
  * Iguala los datos miembros a los de la bolsa pasada como argumento.
  *
  * @param otra Referencia constante a la bolsa de la que se asigna
  * @return Referencia a esta bolsa
  */

Bolsa & Bolsa :: operator = (const Bolsa & otra) {
	max    = otra.max;
	tam    = otra.tam;
	letras = otra.letras;

	return *this;
}

/** @brief Operador de acceso direccionado
  *
  * Accede al carácter del índice pasado como argumento.
  *
  * @param i Índice de acceso a la bolsa de letras
  * @return Carácter del índice indicado
  */

char & Bolsa :: operator [] (const unsigned i) {
	return letras[i];
}

