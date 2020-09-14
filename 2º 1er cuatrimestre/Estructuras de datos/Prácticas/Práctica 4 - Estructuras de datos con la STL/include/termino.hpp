#include <list>

#ifndef TERMINO
#define TERMINO

/** @file termino.hpp
  *
  * @brief Un término consiste en una palabra y sus definiciones. Al estar
  * trabajando con un map, las palabras son únicas.
  *
  * @typedef KEY Identificador único de cada término (palabra)
  * @typedef DEF Definición de un término
  */

template <class KEY, class DEF>
struct Termino {
	KEY palabra;                 ///< Identificador único de cada término
	std::list<DEF> definiciones; ///< Lista de definiciones de cada término
};

#include "termino.cpp"

#endif
