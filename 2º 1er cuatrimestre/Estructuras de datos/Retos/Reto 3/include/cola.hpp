/** @file cola.hpp
  */

#include <stack>

#ifndef COLA_PILA
#define COLA_PILA

/** @class Cola
  * @brief Una cola implementada a partir de una pila
  *
  * La cola esá formada por una sola `pila` y un dato miembro que se utiliza
  * para almacenar la `referencia` que deba devolver una de las funciones
  * miembro. Trabaja con un constructor y destructor por defecto.
  */

template <typename T>
class Cola {
private:
	std::stack<T> pila;
	T referencia;

public:
	bool empty () const;
	size_t size () const;
	const T & front ();
	const T & back () const;
	void push (T & elemento);
	void pop ();
};

#include "cola.cpp"

#endif
