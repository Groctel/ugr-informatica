/** @file rectangulo.cpp
  */

#include "rectangulo.hpp"

/** @brief Constructor por defecto
  */

Rectangulo :: Rectangulo ()
	:altura   (0),
	 anchura  (0),
	 posicion (0)
{ }

/** @brief Constructor con parámetros
  *
  * @param alt  Altura del rectángulo
  * @param anch Anchura del rectángulo
  * @param pos  Posición del rectángulo
  */

Rectangulo :: Rectangulo (unsigned alt, unsigned anch, unsigned pos)
	:altura   (alt),
	 anchura  (anch),
	 posicion (pos)
{ }

/** @brief Consultor de la altura del rectángulo
  *
  * @return Altura del rectángulo
  */

unsigned Rectangulo :: Altura () const {
	return altura;
}

/** @brief Consultor de la anchura del rectángulo
  *
  * @return Anchura del rectángulo
  */

unsigned Rectangulo :: Anchura () const {
	return anchura;
}

/** @brief Consultor de la posición del rectángulo
  *
  * @return Posición del rectángulo
  */

unsigned Rectangulo :: Posicion () const {
	return posicion;
}

/** @brief Modificador de la altura del rectángulo
  *
  * @param unsigned alt Nueva altura del rectángulo
  *
  * @return Éxito de la asignación
  */

bool Rectangulo :: SetAltura (unsigned alt) {
	bool exito = alt < MAX_ALTURA;

	if (exito)
		altura = alt;

	return exito;
}

/** @brief Modificador de la anchura del rectángulo
  *
  * @param unsigned anch Nueva anchura del rectángulo
  *
  * @return Éxito de la asignación
  */

bool Rectangulo :: SetAnchura (unsigned anch) {
	bool exito = anch < MAX_ANCHURA;

	if (exito)
		anchura = anch;

	return exito;
}

/** @brief Modificador de la posición del rectángulo
  *
  * @param unsigned pos Nueva posición del rectángulo
  *
  * @return Éxito de la asignación
  */

bool Rectangulo :: SetPosicion (unsigned pos) {
	bool exito = pos < MAX_POSICION;

	if (exito)
		posicion = pos;

	return exito;
}

/** @brief Modificador de las dimensiones del rectángulo
  *
  * @param unsigned alt  Nueva altura del rectángulo
  * @param unsigned anch Nueva anchura del rectángulo
  * @param unsigned pos  Nueva posición del rectángulo
  *
  * @return Éxito de la asignación
  */

bool Rectangulo :: SetDimensiones (unsigned alt, unsigned anch, unsigned pos) {
	return SetAltura(alt) && SetAnchura (anch) && SetPosicion(pos);
}
