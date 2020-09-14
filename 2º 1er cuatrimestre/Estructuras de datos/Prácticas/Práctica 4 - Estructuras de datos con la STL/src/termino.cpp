/** @file termino.hpp
  */

/** @brief Comparador de términos
  * Devuelve true si la clave del primer término es menor que la del segundo y
  * false en cualquier otro caso.
  *
  * @param uno  Primer término a evaluar
  * @param otro Segundo término a evaluar
  */

template <class KEY, class DEF>
bool operator < (const Termino<KEY,DEF> & uno, const Termino<KEY,DEF> & otro) {
	return uno.clave < otro.clave;
}

/** @brief Comparador de términos
  * Devuelve true si la clave del primer término es mayor que la del segundo y
  * false en cualquier otro caso.
  *
  * @param uno  Primer término a evaluar
  * @param otro Segundo término a evaluar
  */

template <class KEY, class DEF>
bool operator > (const Termino<KEY,DEF> & uno, const Termino<KEY,DEF> & otro) {
	return !(uno < otro);
}
