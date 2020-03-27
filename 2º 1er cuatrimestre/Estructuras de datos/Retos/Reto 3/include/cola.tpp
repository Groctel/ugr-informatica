/** @file cola.tpp
  */

#ifndef COLA_PILA
#define COLA_PILA

#include <stack>

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

#endif

/** @file cola.cpp
  */

/** @brief Consultor de contenido de la cola
  *
  * Consulta si la cola está vacía mediante una llamada al método `empty` de
  * `std::stack`.
  *
  * @return `true` si el tamaño del contenedor subyacente es igual a `0` y
  * `false` en cualquier otro caso.
  */
template <typename T>
bool Cola<T> :: empty () const {
	return pila.empty();
}

/** @brief Consultor de tamaño de la cola
  *
  * Debido a que el el método `size` de `std::stack` devuelve un valor de tipo
  * `size_t`, esta función devuelve lo mismo para evitar castings innecesarios.
  *
  * @return Número de elementos del contenedor subyacente.
  */

template <typename T>
size_t Cola<T> :: size () const {
	return pila.size();
}

/** @brief Consultor del elemento más antiguo de la cola
 *
 * Debido a que no es posible realizar más acciones tras la sentencia `return`
 * de un método, la implementación de este método se ve obligada a almacenar una
 * copia del valor a devolver en el dato miembro `referencia` y devolverlo tras
 * reordenar el contenedor subyacente.
 *
 * @return Referencia constante al elemento más antiguo del contenedor
 * subyacente.
 */

template <typename T>
const T & Cola<T> :: front () {
	std::stack<T> aux;

	while (!pila.empty()) {
		aux.push(pila.top());
		pila.pop();
	}

	referencia = aux.top();

	while (!aux.empty()) {
		pila.push(aux.top());
		aux.pop();
	}

	return referencia;
}

/** @brief Consultor del elemento más reciente de la cola
  *
  * Este método simplemente llama al método `top` de `std::stack` para devolver
  * la referencia.
  *
  * @return Referencia constante al elemento más reciente del contenedor
  * subyacente.
  */

template <typename T>
const T & Cola<T> :: back () const {
	return pila.top();
}

/** @brief Insertor de elemento
  *
  * Inserta una referencia a un nuevo elemento en el contenedor subyacente. Para
  * ello llama al método `push` de `std::stack`.
  */

template <typename T>
void Cola<T> :: push (T & elemento) {
	pila.push(elemento);
}

/** @brief Extractor del elemento más antiguo
  *
  * Extrae el elemento más antiguo del contenedor subyacente. Para realizar esta
  * función, se crea localmente una segunda pila sobre la cual se vuelca el
  * contenido de la principal. Sobre esta pila secundaria se ejecuta el método
  * `pop` de `std::stack` y luego se vuelca de vuelta a la pila principal.
  */

template <typename T>
void Cola<T> :: pop () {
	std::stack<T> aux;

	while (!pila.empty()) {
		aux.push(pila.top());
		pila.pop();
	}

	aux.pop();

	while (!aux.empty()) {
		pila.push(aux.top());
		aux.pop();
	}
}
