/** @file vd.hpp
  */

#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

#include <cstdio>

/** @class VD
  * @brief Vector de tamaño dinámico
  *
  * @tparam T Dato a introducir en el vector
  *
  * El diseño de este vector es similar al de la clase `std::vector`.
  */

template <typename T>
class VD {
private:
	static size_t const MAXIMO = 2147483647;

	T* datos;
	size_t tamanio;
	size_t capacidad;

	bool ajusta_tamanio  ();
	void reemplaza_datos ();
public:
	VD  (size_t capacidad = 1);
	VD  (const VD<T> & otro);
	~VD ();

	// Capacidad
	size_t capacity        () const;
	size_t size            () const;
	size_t max_size        () const;
	bool     empty         () const;
	void     reserve       (size_t nueva_capacidad);
	void     resize        (size_t nuevo_tamanio, const T & relleno);
	void     shrink_to_fit ();

	// Acceso a alementos
	T& operator [] (size_t i) const;
	T& at          (size_t i) const;
	T& front       () const;
	T& back        () const;
	T* data        () const;

	// Modificadores
	void push_back (const T & elemento);
	void pop_back  ();
	void insert    (size_t i, const T & elemento);
	void erase     (size_t i);
	void erase     (size_t a, size_t b);
	void clear     () noexcept;
};

#endif


/** @brief Ajustador de tamaño
  * Ajusta el tamaño del vector en múltiplos y divisores de 2.
  */

template <typename T>
bool VD<T> :: ajusta_tamanio () {
	bool exito = true;

	if (capacidad <= tamanio) {
		if (capacidad == MAXIMO) {
			printf ("\033[1;31m:: %s\033[0m\n",
			        "NO SE PUEDEN AÑADIR MÁS ELEMENTOS AL VECTOR");
			exito = false;
		}
		else {
			if (capacidad*2 > MAXIMO)
				capacidad = MAXIMO;

			while (capacidad <= tamanio)
				capacidad *= 2;

			reemplaza_datos();
		}
	}
	else if (tamanio <= capacidad/2) {
		shrink_to_fit();
	}

	return exito;
}

/** @brief Reemplazador de datos
  * Crea un nuevo vector con la capacidad actual y copia en él todos los datos
  * del que se está reemplazando, que se elimina.
  */

template <typename T>
void VD<T> :: reemplaza_datos () {
	bool vacio = false;

	if (capacidad == 0) {
		vacio = true;
		capacidad = 1;
	}

	T* nuevo_datos = new T[capacidad];

	if (!vacio) {
		for (unsigned i=0; i<tamanio; i++)
			nuevo_datos[i] = datos[i];
	}

	delete [] datos;
	datos = nuevo_datos;
}

/** @brief Constructor por defecto
  * Crea un array de datos con la capacidad indicada, que es 1 en caso de no
  * especificarse.
  *
  * @param cap Capacidad con la que crear el array de datos.
  */

template <typename T>
VD<T> :: VD (size_t cap)
	:tamanio   (0),
	 capacidad (cap)
	{
	datos = new T[capacidad];
}

/** @brief Constructor de copia
  * Crea un array de datos con la misma capacidad que el del vector pasado como
  * argumento y realiza una copia profunda de los datos.
  *
  * @param otro Vector que se va a copiar
  */

template <typename T>
VD<T> :: VD (const VD<T> & otro)
	:tamanio   (otro.tamanio),
	 capacidad (otro.capacidad)
	{
	datos = new T[capacidad];

	for (unsigned i=0; i<capacidad; i++)
		datos[i] = otro.datos[i];
}

/** @brief Constructor por defecto
  * Libera la memoria ocupada por el array de datos.
  */

template <typename T>
VD<T> :: ~VD () {
	delete [] datos;
}


/** @brief Consultor de capacidad
  * Devuelve el número de elementos que puede albergar el vector antes de
  * redimensionarse.
  */

template <typename T>
size_t VD<T> :: capacity () const {
	return capacidad;
}

/** @brief Consultor del tamaño
  * Devuelve el número de elementos almacenados en el vector.
  */

template <typename T>
size_t VD<T> :: size () const {
	return tamanio;
}

/** @brief Consultor del tamaño máximo
  * Devuelve el número máximo de elementos almacenables en el vector.
  */

template <typename T>
size_t VD<T> :: max_size () const {
	return MAXIMO;
}

/** @brief Consultor de estado
  * Devuelve true en caso de que el vector contenga cero elementos y false en
  * cualquier otro caso.
  */

template <typename T>
bool VD<T> :: empty () const {
	return tamanio == 0;
}

/** @brief Reservador de memoria
  * Copia el array de datos a un array de la capacidad pasada como parámetro. Si
  * esta capacidad es mayor o igual que el máximo de elementos albergables, se
  * reserva espacio para este máximo de elementos. Si es menor que la actual, se
  * eliminarán tantos elementos como la diferencia de capacidades.
  *
  * @param nueva_capacidad Capacidad con la que se va a crear el nuevo array de
  * datos
  */

template <typename T>
void VD<T> :: reserve (size_t nueva_capacidad) {
	if (nueva_capacidad < MAXIMO)
		capacidad = nueva_capacidad;
	else
		capacidad = MAXIMO;

	reemplaza_datos();
}


/** @brief Encogedor del array de datos
  * Si hay más datos reservados que usados, se iguala el tamaño del array de
  * datos al número de datos usados.
  */

template <typename T>
void VD<T> :: shrink_to_fit () {
	if (capacidad > tamanio)
		reserve (capacidad = tamanio);
}

/** @brief Modificador del tamaño del array de datos
  * Modifica el tamaño del array de datos y rellena todos los elementos libres
  * con el especificado en el segundo argumento.
  *
  * @param nuevo_tamanio Tamaño del nuevo array de datos
  * @param relleno Referencia constante al elemento con el que se va a rellenar
  * el vector
  */

template <typename T>
void VD<T> :: resize (size_t nuevo_tamanio, const T & relleno) {
	unsigned antiguo_tamanio = tamanio;

	reserve(tamanio = nuevo_tamanio);
	for (int i=antiguo_tamanio; i<tamanio; i++)
		datos[i] = relleno;
}

/** @brief Operador []
  * Devuelve una referencia al elemento de índice pasado como argumento.
  *
  * @param i Índice sobre el que acceder al vector
  */

template <typename T>
T& VD<T> :: operator [] (size_t i) const {
	return datos[i];
}

/** @brief Consultor de elemento
  * Devuelve una referencia al elemento de índice pasado como argumento. Para
  * ello, hace uso del operador [].
  *
  * @param i Índice sobre el que acceder al vector
  */

template <typename T>
T& VD<T> :: at (size_t i) const {
	return this[i];
}

/** @brief Consultor de la cabeza del vector
  * Devuelve una referencia al primer elemento del vector.
  */

template <typename T>
T& VD<T> :: front () const {
	return datos[0];
}

/** @brief Consultor de la cola del vector
  * Devuelve una referencia al último elemento del vector.
  */

template <typename T>
T& VD<T> :: back () const {
	return datos[tamanio-1];
}

/** @brief Consultor de datos
  * Devuelve una referencia al contenido completo del vector.
  */

template <typename T>
T* VD<T> :: data () const {
	return datos;
}

/** @brief Insertador de elemento al final del vector
  * Inserta un elemento al final del vector.
  *
  * @param elemento Referencia constante del elemento a insertar
  */

template <typename T>
void VD<T> :: push_back (const T & elemento) {
	insert (tamanio, elemento);
}

/** @brief Extractor del último elemento
  * Extrae el último elemento del vector. Para ello, decrementa en 1 el tamaño
  * del mismo.
  */

template <typename T>
void VD<T> :: pop_back () {
	tamanio--;
}

/** @brief Insertador de elemento
  * Inserta un elemento en el índice indicado.
  *
  * @param i Índice en el que insertar el elemento
  * @param elemento Referencia constante del elemento a insertar
  */

template <typename T>
void VD<T> :: insert (size_t i, const T & elemento) {
	if (ajusta_tamanio()) {
		for (unsigned j=i; j<tamanio; j++)
			datos[j+1] = datos[j];

		datos[i] = elemento;
		tamanio++;
	}
}

/** @brief Eliminador de elementos
  * Elimina el elemento con el índice pasado como argumento.
  *
  * @param i Índice del elemento a eliminar
  */

template <typename T>
void VD<T> :: erase (size_t i) {
	~datos[i]();

	for (i; i<tamanio-1; i++)
		datos[i] = datos[i+1];

	tamanio--;
	ajusta_tamanio();
}

/** @brief Eliminador de elementos secuencial
  * Elimina secuencialmente todos los elementos desde el índice del primer
  * argumento hasta el índice del segundo.
  *
  * @param a Índice del inicio de la secuencia de eliminación (inclusive)
  * @param b Índice del final de la secuencia de eliminación (no inclusive)
  */

template <typename T>
void VD<T> :: erase (size_t a, size_t b) {
	bool ajustado = false;

	if (a > b) {
		for (unsigned i=a; i<tamanio-b; i++)
			datos[i] = datos[i+b-a];
		tamanio -= b-a;
	}
	else if (a < b) {
		for (unsigned i=a+1 ;i<tamanio-b+1 ;i++)
			datos[i] = datos[i+b-a];
		tamanio -= a-b;
	}
	else {
		erase(a);
		ajustado = true;
	}

	if (!ajustado)
		ajusta_tamanio();
}

/** @brief Eliminador de datos
  * Elimina todos los datos del vector y redimensiona el array de datos
  * consecuentemente.
  */

template <typename T>
void VD<T> :: clear () noexcept {
	capacidad = 1;
	ajusta_tamanio();
}
