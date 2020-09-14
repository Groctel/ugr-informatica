/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file src/letra.cpp
  */

#include "letra.hpp"

/** @brief Constructor por defecto
  *
  * Crea una letra nula sin ninguna aparición
  */

Letra :: Letra ()
	:grafema    ('\0'),
	 frecuencia (0)
{ }

/** @brief Constructor con argumentos
  *
  * Crea una letra con un grafema y frecuencias específicos
  *
  * @param g Grafema a asignar
  * @param f Frecuencia a asignar
  */

Letra :: Letra (char g, unsigned f)
	:grafema    (g),
    frecuencia (f)
{ }

/** @brief Constructor de copia
  *
  * Crea una letra con las mismas propiedades que la letra pasada como
  * argumento.
  *
  * @param otra Referencia constante a la letra de la que se copia
  */

Letra :: Letra (const Letra & otra)
	:grafema    (otra.grafema),
    frecuencia (otra.frecuencia)
{ }

/** @brief Consultor del grafema
  *
  * @return Grafema de la letra
  */

char Letra :: Grafema () const {
	return grafema;
}

/** @brief Consultor de la frecuencia
  *
  * @return Frecuencia de la letra
  */

unsigned Letra :: Frecuencia () const {
	return frecuencia;
}

/** @brief Modificador del grafema
  *
  * Cambia el grafema al pasado como argumento.
  *
  * @param g Grafema que se va a asignar
  */

void Letra :: NuevoGrafema (const char g) {
	grafema = g;
}

/** @brief Modificador de la frecuencia
  *
  * Cambia la frecuencia a la pasada como argumento.
  *
  * @param f Frecuencia que se va a asignar
  */

void Letra :: NuevaFrecuencia (unsigned f) {
	frecuencia = f;
}

/** @brief Operador de asignación
  *
  * Iguala los atributos a los de la letra pasada como argumento.
  *
  * @param otra Referencia constante a la letra de la que se asigna
  * @return Referencia a esta letra
  */

Letra & Letra :: operator = (const Letra & otra) {
	grafema    = otra.grafema;
	frecuencia = otra.frecuencia;

	return *this;
}

/** @brief Operador de igualdad con respecto a otra letra
  *
  * Se consideran iguales dos letras que tienen el mismo grafema.
  *
  * @param otra Referencia constante a la letra con la que se compara
  * @return Condición de igualdad de amblas letras
  */

bool Letra :: operator == (const Letra & otra) const {
	return grafema == otra.grafema;
}

/** @brief Operador de igualdad con respecto a otra letra
  *
  * Se consideran iguales dos letras que tienen el mismo grafema.
  *
  * @param otra Referencia constante a la letra con la que se compara
  * @return Condición de igualdad de amblas letras
  */

bool Letra :: operator != (const Letra & otra) const {
	return !(*this == otra);
}

/** @brief Operador de orden menor con respecto a otra letra
  *
  * Se consideran una letra es menor que otra si su grafema se encuentra antes
  * en el orden alfabético.
  *
  * @param otra Referencia constante a la letra con la que se compara
  * @return Condición de orden menor de la primera letra con la segunda
  */

bool Letra :: operator < (const Letra & otra) const {
	return grafema < otra.grafema;
}

/** @brief Operador de orden mayor con respecto a otra letra
  *
  * Se consideran una letra es mayor que otra si no es menor ni igual que ésta.
  *
  * @param otra Referencia constante a la letra con la que se compara
  * @return Condición de orden mayor de la primera letra con la segunda
  */

bool Letra :: operator > (const Letra & otra) const {
	return !(*this == otra || *this < otra);
}

/** @brief Operador de orden menor o igual con respecto a otra letra
  *
  * Se consideran una letra es menor o igual que otra si cumple una de estas dos
  * condiciones.
  *
  * @param otra Referencia constante a la letra con la que se compara
  * @return Condición de orden menor o igual de la primera letra con la segunda
  */

bool Letra :: operator <= (const Letra & otra) const {
	return *this < otra || *this == otra;
}

/** @brief Operador de orden mayor o igual con respecto a otra letra
  *
  * Se consideran una letra es mayor o igual que otra si cumple una de estas dos
  * condiciones.
  *
  * @param otra Referencia constante a la letra con la que se compara
  * @return Condición de orden mayor o igual de la primera letra con la segunda
  */

bool Letra :: operator >= (const Letra & otra) const {
	return *this > otra || *this == otra;
}

/** @brief Operador unario de suma
  *
  * Aumenta en uno la frecuencia de la letra.
  *
  * @return Valor de la frecuencia una vez aumentada
  */

unsigned & Letra :: operator ++ () {
	return ++frecuencia;
}

/** @brief Operador unario de resta
  *
  * Decrementa en uno la frecuencia de la letra.
  *
  * @return Valor de la frecuencia una vez decrementada
  */

unsigned & Letra :: operator -- () {
	return --frecuencia;
}
