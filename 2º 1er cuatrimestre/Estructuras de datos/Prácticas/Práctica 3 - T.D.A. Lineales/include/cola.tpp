/** @file cola.tpp
  */

#ifndef COLA
#define COLA

#include <cstdio>

/** @class Cola
  * @brief Implementación básica de una cola
  *
  * @tparam T Dato a introducir en la cola
  *
  * El diseño de esta cola es similar al de la clase `std::queue`.
  */

template <typename T>
class Cola {
private:
	static unsigned const MAXIMO = 2147483647;

	T* datos;
	size_t inicio;
	size_t fin;
	size_t capacidad;

	bool ajusta_tamanio  ();
	void reemplaza_datos ();

public:
	Cola  (size_t cap = 1);
	Cola  (const Cola<T> & otra);
	~Cola ();

	// Capacidad
	size_t size     () const;
	size_t max_size () const;
	bool   empty    () const;

	// Acceso a elementos
	const T & front () const;
	const T & back  () const;

	// Modificadores
	void push   (const T & elemento);
	void pop    ();
	void rotate (size_t i = 1);
};

#endif

/** @brief Ajustador de tamaño según el inicio y fin de la cola
  * - Si comienza en cero y la capacidad es el máximo indica que no puede añadir
  *   más elementos.
  * - Si comienza en cero y la capacidad es menor que el máximo se iguala a él
  *   o se dobla.
  * - En cualquier otro caso, desplaza todos los elementos al inicio del array
  *   para evitar redimensionar inútilmente.
  */

template <typename T>
bool Cola<T> :: ajusta_tamanio () {
	bool exito = true;

	if (fin == capacidad) {
		if (inicio == 0) {
			if (capacidad == MAXIMO) {
				printf ("\033[1;31m%s\033[0m\n",
				        ":: NO SE PUEDEN AÑADIR MÁS ELEMENTOS");
				exito = false;
			}
			else {
				if (capacidad*2 >= MAXIMO)
					capacidad = MAXIMO;
				else
					capacidad *= 2;

				T* nuevos_datos = new T[capacidad];

				for (unsigned i=0; i<fin; i++)
					nuevos_datos[i] = datos[i];

				delete [] datos;
				datos = nuevos_datos;
			}
		}
		else {
			for (unsigned i=0; i<size(); i++)
				datos[i] = datos[i+inicio];

			fin -= inicio;
			inicio = 0;
		}
	}

	return exito;
}

/** @brief Constructor por defecto
  * Crea una cola vacía (inicio = fin = 0) con la capacidad indicada, que vale
  * 1 por defecto.
  *
  * @param capacidad Capacidad con la que se va a crear el array de datos.
  */

template <typename T>
Cola<T> :: Cola (size_t cap)
	:inicio    (0),
	 fin       (0),
	 capacidad (cap)
	{
	datos = new T[capacidad];
}

/** @brief Constructor de copia
  * Crea una cola con los mismos elementos que la anterior.
  * Debido a que los datos útiles de la cola son los que se encuentrar entre el
  * inicio y el fin de la misma, sólo necesita realizar una copia profunda de
  * éstos.
  *
  * @param otra Referencia constante a la cola que se va a copiar
  */

template <typename T>
Cola<T> :: Cola (const Cola<T> & otra)
	:inicio    (otra.inicio),
	 fin       (otra.fin),
	 capacidad (otra.capacidad)
	{
	datos = new T[capacidad];

	for (unsigned i=inicio; i<fin; i++)
		datos[i] = otra.datos[i];
}

/** @brief Destructor por defecto
  * Libera la memoria del array de datos.
  */

template <typename T>
Cola<T> :: ~Cola () {
	delete [] datos;
}

/** @brief Consultor de estado de la cola
  * Devuelve true si la cola está vacía (tiene 0 elementos) y false en cualquier
  * otro caso.
  */

template <typename T>
bool Cola<T> :: empty () const {
	return size() == 0;
}

/** @brief Consultor del tamaño de la cola
  * Devuelve el tamaño útil de la cola, sin tener en cuenta los elementos del
  * array de datos que no forman parte de ella.
  */

template <typename T>
size_t Cola<T> :: size () const {
	return fin-inicio;
}

/** @brief Consultor del tamaño máximo de la cola
  * Devuelve el tamaño máximo que puede adoptar el array de datos de la cola.
  */

template <typename T>
size_t Cola<T> :: max_size () const {
	return MAXIMO;
}

/** @brief Consultor de la cabeza de la cola
  * Devuelve una referencia constante al elemento más antiguo de la cola.
  */

template <typename T>
const T & Cola<T> :: front () const {
	return datos[inicio];
}

/** @brief Consultor de la cola de la cola (valga la redundancia)
  * Devuelve una referencia constante al elemento más nuevo de la cola.
  */

template <typename T>
const T & Cola<T> :: back () const {
	return datos[fin-1];
}

/** @brief Insertador de elementos en la cola
  * Inserta un elemento al final de la cola. Para ello comprueba si es necesario
  * ajustar el tamaño y, si se pueden insertar elementos, se añade tras el
  * último elemento.
  *
  * @param elemento Referencia constante al elemento que se va a insertar
  */

template <typename T>
void Cola<T> :: push (const T & elemento) {
	if (ajusta_tamanio())
		datos[fin++] = elemento;
}

/** @brief Extractor de elementos de la cola
  * Extrae el elemento más antiguo de la cola. Para ello, simplemente avanza el
  * inicio una posición, dejando el elemento al que referenciaba inutilizable.
  * Si no quedan elementos en la cola, indica que no se pueden extraer elementos
  * de la misma.
  */

template <typename T>
void Cola<T> :: pop () {
	if (!empty()) {
		inicio++;
	}
	else {
		printf ("\033[1;31m%s\033[0m\n",
		        ":: NO QUEDAN ELEMENTOS PARA EXTRAER DE LA COLA");
	}
}

/** @brief Rotador de elementos dentro de la cola
  * Definimos una rotación como extraer el elemento más antiguo de la cola e
  * insertarlo al final de la misma.
  *
  * @param i Número de rotaciones que se van a realizar
  */

template <typename T>
void Cola<T> :: rotate (size_t i) {
	for (unsigned j=0; j<i; j++) {
		push(datos[inicio]);
		pop();
	}
}
