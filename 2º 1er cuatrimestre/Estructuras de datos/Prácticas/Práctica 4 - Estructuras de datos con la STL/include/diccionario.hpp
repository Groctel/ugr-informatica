#include <iostream>
#include <list>
#include "termino.hpp"

#ifndef DICCIONARIO
#define DICCIONARIO

/** @file dicionario.hpp
  *
  * @brief Implementación de un diccionario (tipo STL map)
  *
  * @typedef KEY Identificador único de cada término (palabra)
  * @typedef DEF Definición de un término
  */

template <class KEY, class DEF>
class Diccionario {
private:
	std::list<Termino<KEY,DEF> > datos;

	void Copiar (const Diccionario<KEY,DEF> & otro);
	void Borrar ();
public:
	Diccionario  ();
	Diccionario  (const Diccionario<KEY,DEF> & otro);
	~Diccionario ();

	Diccionario<KEY,DEF> & operator = (const Diccionario<KEY,DEF> & otro);

	bool     vacio () const;
	unsigned size  () const;

	bool definida (const KEY & palabra,
	               typename std::list<Termino<KEY,DEF> >::iterator & it);
	void insertar (const KEY & palabra, const std::list<DEF> & definicion);
	void definir  (const KEY & palabra, const DEF & definicion);

	std::list<DEF> definiciones (const KEY & palabra);

	typename std::list<Termino<KEY,DEF> >::iterator & begin ();
	typename std::list<Termino<KEY,DEF> >::iterator & end ();
	typename std::list<Termino<KEY,DEF> >::const_iterator & begin () const;
	typename std::list<Termino<KEY,DEF> >::const_iterator & end () const;
};

#include "diccionario.cpp"

#endif

