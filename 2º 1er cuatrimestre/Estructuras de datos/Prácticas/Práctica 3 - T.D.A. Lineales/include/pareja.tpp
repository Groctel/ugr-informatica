/** @file pareja.tpp
  */

#ifndef PAREJA
#define PAREJA

/** @class Pareja
  * @brief Estructura que almacena dos elementos de cualquier tipo en pareja.
  *
  * @tparam T1 Dato `first` de la pareja
  * @tparam T2 Dato `second` de la pareja
  *
  * El diseño de esta estructura es similar al de la estructura `std::pair`.
  */

template <typename T1, typename T2>
class Pareja {
private:
	T1 primero;
	T2 segundo;
public:
	Pareja ();
	Pareja (const T1 p, const T2 s);
	Pareja (const Pareja & otra);

	// Acceso
	const T1 & first  () const;
	const T2 & second () const;

	// Modificadores
	void set_first  (const T1 & elemento);
	void set_second (const T2 & elemento);

	Pareja<T1,T2> & operator = (const Pareja & otra);
};

#endif

/** @brief Constructor por defecto
  * Construye una pareja de elementos inicializando ambos a valores basura.
  */

template <typename T1, typename T2>
Pareja<T1,T2> :: Pareja () { }

/** @brief Constructor con argumentos
  * Construye una pareja de elementos inicializando cada uno a su
  * correspondiente argumento del constructor.
  *
  * @param p Elemento a introducir como primer elemento
  * @param s Elemento a introducir como segundo elemento
  */

template <typename T1, typename T2>
Pareja<T1,T2> :: Pareja (const T1 p, const T2 s)
	:primero (p),
	 segundo (s)
{ }

/** @brief Constructor de copia
  * Construye una pareja de elementos inicializando cada uno a su
  * correspondiente elemento de la pareja pasada como argumento.
  *
  * @param otra Referencia constante a la pareja que se va a copiar
  */

template <typename T1, typename T2>
Pareja<T1,T2> :: Pareja (const Pareja & otra)
	:primero (otra.first()),
	 segundo (otra.second())
{ }

/** @brief Consultor del primer elemento
  * Devuelve una referencia constante al primer elemento de la pareja.
  */

template <typename T1, typename T2>
const T1 & Pareja<T1,T2> :: first () const {
	return primero;
}

/** @brief Consultor del segundo elemento
  * Devuelve una referencia constante al segundo elemento de la pareja.
  */

template <typename T1, typename T2>
const T2 & Pareja<T1,T2> :: second () const {
	return segundo;
}

/** @brief Modificador del primer elemento
  * Asigna al primer elemento el pasado como argumento de la función.
  *
  * @param elemento Referencia constante al elemento que va a sustituir al
  * primer elemento actual
  */

template <typename T1, typename T2>
void Pareja<T1,T2> :: set_first (const T1 & elemento) {
	primero = elemento;
}

/** @brief Modificador del segundo elemento
  * Asigna al segundo elemento el pasado como argumento de la función.
  *
  * @param elemento Referencia constante al elemento que va a sustituir al
  * segundo elemento actual
  */

template <typename T1, typename T2>
void Pareja<T1,T2> :: set_second (const T2 & elemento) {
	segundo = elemento;
}

/** @brief Operador de asignación
  * Modifica cada elemento de la pareja para que tome el valor de su
  * correspondiente de la pareja pasada como argumento.
  *
  * @param otra Referencia constante a la pareja de la que se va a asignar
  */

template <typename T1, typename T2>
Pareja<T1,T2> & Pareja<T1,T2> :: operator = (const Pareja & otra) {
	primero = otra.first();
	segundo = otra.second();

	return *this;
}
