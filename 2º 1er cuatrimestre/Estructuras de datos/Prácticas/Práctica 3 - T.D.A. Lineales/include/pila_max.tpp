/** @file pila_max.tpp
  */

/* CONTENEDOR
 *
 * Indica al compilador qué contenedor va a compilarse como estructura
 * subyacente de la pila.
 * OPCIONES:
 * 1 - Vector dinámico (vd.hpp)
 * 2 - Cola (cola.hpp)
 *
 * El Makefile se encarga de su modificación.
 */

#define CONTENEDOR 1

#if CONTENEDOR == 1
	#include "vd.tpp"
#elif CONTENEDOR == 2
	#include "cola.tpp"
#else
	#error Valor incorrecto para CONTENEDOR en pila_max.tpp
#endif

#include "pareja.tpp"

#ifndef PILAMAX
#define PILAMAX

/** @class PilaMax
  * @brief Pila que almacena parejas de elementos, siendo el primero de la
  * pareja el elemento introducido y el segundo, el máximo de todos los
  * elementos de la misma
  *
  * @tparam Tipo de dato a introducir en la pila
  *
  * Dependiendo de si se compila con `CONTENEDOR 1` o `CONTENEDOR 1`, el
  * contenedor subyacente de la pila será un vector dinámico o una cola
  * respectivamente.
  */

template <typename T>
class PilaMax {
private:
	#if CONTENEDOR == 1
		VD<Pareja<T,T> > datos;   // Pareja <dato, maximo>
	#else
		Cola<Pareja<T,T> > datos; // Pareja <dato, maximo>
	#endif
public:
	PilaMax (unsigned cap = 1);
	PilaMax (PilaMax<T>& otra);

	// Capacidad
	unsigned size     () const;
	unsigned max_size () const;
	bool empty        () const;

	// Acceso a elementos
	const Pareja<T,T> & top () const;

	// Modificadores
	void push (T& elemento);
	void pop  ();
};

#endif

/** @brief Constructor por defecto
  * Crea una pila vacía (inicio = fin = 0) con la capacidad indicada, que vale
  * 1 por defecto. Crea la pila con un vector dinámico o con una cola en función
  * del valor de la variable CONTENEDOR (pila_max.tpp) al compilar.
  *
  * @param capacidad Capacidad con la que se va a crear el array de datos.
  */

template <typename T>
PilaMax<T> :: PilaMax (unsigned cap) {
	#if CONTENEDOR == 1
		datos = VD<Pareja<T,T> >();
	#else
		datos = Cola<Pareja<T,T> >();
	#endif
}

/** @brief CONSTRUCTOR DE COPIA
  * Crea una pila con los mismos elementos que la anterior, volcando los datos
  * de la pila copiada en un array e introduciendo uno a uno los elementos de
  * vuelta a la pila de copia y en la copiada.
  *
  * @param otra Referencia no constante a la pila que se va a copiar
  */

template <typename T>
PilaMax<T> :: PilaMax (PilaMax<T>& otra) {
	#if CONTENEDOR == 1
		datos = VD<Pareja<T,T> >();
	#else
		datos = Cola<Pareja<T,T> >();
	#endif

		unsigned tamanio = otra.size();
		Pareja<T,T>* tmp = new Pareja<T,T>[otra.size()];

		for (unsigned i=0; !otra.empty(); i++) {
			tmp[i] = otra.top();
			otra.pop();
		}

		for (unsigned i=otra.size()-1; i<=0; i--) {
			push(tmp[i]);
			otra.push(tmp[i]);
		}

		delete [] tmp;
}

/** @brief Consultor del tamaño de la pila
  * Devuelve el número de elementos útiles almacenados en la estructura
  * subyacente.
  */

template <typename T>
unsigned PilaMax<T> :: size () const {
	return datos.size();
}

/** @brief Consultor del tamaño máximo de la pila
  * Devuelve el número máximo de elementos almacenables en la estructura
  * subyacente.
  */

template <typename T>
unsigned PilaMax<T> :: max_size () const {
	return datos.max_size();
}

/** @brief Consultor del estado de la pila
  * Devuelve true en caso de que la estructura subyacente contenga cero
  * elementos y false en cualquier otro caso.
  */

template <typename T>
bool PilaMax<T> :: empty () const {
	return datos.empty();
}

/** @brief Consultor del tope de la pila
  * Devuelve una referencia constante al elemento más nuevo de la pila.
  */

template <typename T>
const Pareja<T,T> & PilaMax<T> :: top () const {
	return datos.back();
}

/** @brief Introductor de elementos en la pila
  * Recibido un elemento, evalúa el valor máximo de la pila tras su inminente
  * introducción y crea una pareja en la que el primer atributo es el elemento
  * recibido y el segundo, el máximo introducido. Tras esto, lo introduce con
  * la función correspondiente al contenedor subyacente.
  *
  * @param elemento Elemento a introducir
  * @pre El elemento debe incorporar al menos un operador de orden
  */

template <typename T>
void PilaMax<T> :: push (T& elemento) {
	T max;

	if (empty() || elemento > datos.back().second())
		max = elemento;
	else
		max = datos.back().second();

	Pareja<T,T> pareja(elemento, max);

	#if CONTENEDOR == 1
		datos.push_back(pareja);
	#else
		datos.push(pareja);
	#endif
}

/** @brief Extractor del último elemento de la pila
  * Extrae de la pila el elemento más nuevo. Si el contenedor subyacente es un
  * vector dinámico, extrae el último elemento; si es una cola, la rota de forma
  * que el elemento más nuevo pase a ser el más antiguo y lo extrae.
  */

template <typename T>
void PilaMax<T> :: pop () {
	#if CONTENEDOR == 1
		datos.pop_back();
	#else
		datos.rotate(datos.size()-1);
		datos.pop();
	#endif
}
