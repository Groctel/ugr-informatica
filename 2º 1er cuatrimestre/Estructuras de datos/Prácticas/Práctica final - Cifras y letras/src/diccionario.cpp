/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file src/diccionario.cpp
  */

#include "diccionario.hpp"

Diccionario :: Diccionario () { }

/** @brief Constructor de copia
  *
  * Crea un diccionario con el mismo contenedor que el pasado como argumento.
  *
  * @param otro Referencia constante al diccionario que se copia.
  */

Diccionario :: Diccionario (const Diccionario & otro)
	:palabras (otro.palabras)
{ }

/** @brief Insertador de palabra
  *
  * Inserta una palabra en el contenedor subyacente.
  *
  * @param palabra Palabra a insertar
  */

void Diccionario :: Aniade (std::string palabra) {
	palabras.insert(palabra);
}

/** @brief Consultor del número de palabras
  *
  * @return Número de palabras que componen el diccionario
  */

unsigned Diccionario :: NumPalabras () const {
	unsigned num_palabras = 0;

	for (std::set<std::string>::const_iterator it = palabras.cbegin();
	     it!=palabras.cend(); ++it, num_palabras++);

	return num_palabras;
}

/** @brief Consultor de longitud la palabra más larga
  *
  * @return Longitud de la palabra más larga del diccionario
  */

unsigned Diccionario :: MaximaLongitud () const {
	unsigned max_long = 0;

	for (std::set<std::string>::const_iterator it = palabras.cbegin();
	                                           it!=palabras.cend(); ++it)
		if ((*it).length() > max_long)
			max_long = (*it).length();

	return max_long;
}

/** @brief Consultor de frecuencia individual de cada letra
  *
  * Asocia a cada carácter su frecuencia absoluta y los introduce en sus
  * respectivos objetos de la clase Letra.
  *
  * @return Lista de letras
  */

std::vector<Letra> Diccionario :: CuentaLetras () const {
	std::vector<Letra> contador;
	bool coincide;

	contador.push_back(Letra(*(*palabras.begin()).begin(),0));

	for (std::set<std::string>::const_iterator it=palabras.cbegin();
	                                           it!=palabras.cend(); ++it) {
		for (std::string::const_iterator jt=(*it).cbegin();
		                                 jt!=(*it).cend(); ++jt) {
			coincide = false;

			for (std::vector<Letra>::iterator
			     kt=contador.begin(); kt!=contador.end() && !coincide; ++kt) {
				if (*jt == (*kt).Grafema()) {
					coincide = ++(*kt);
				}
			}

			if (!coincide)
				contador.push_back(Letra(*jt, 1));
		}
	}

	return contador;
}

/** @brief Buscador de palabras
  *
  * Busca palabras que estén compuestas por las letras de la bolsa de letras
  * pasada como argumento.
  *
  * @param bolsa Bolsa de letras que se consulta
  * @return Lista de palabras encontradas
  */

std::set<std::string> Diccionario :: BuscaPalabras (Bolsa bolsa) const {
	std::set<std::string> resultados;

	do {
		for (unsigned long i=0; i<bolsa.Tam(); i++) {
			std::string palabra;

			for (unsigned long j=0; j<=i; j++)
				palabra.push_back(bolsa[j]);

			std::set<std::string>::const_iterator pareja = palabras.find(palabra);

			if (pareja != palabras.cend())
				resultados.insert(*pareja);
		}

	} while (bolsa.Siguiente());

	return resultados;
}

/** @brief Operador asociado de entrada al diccionario
  *
  * Introduce una palabra por línea del flujo de entrada en el diccionario.
  *
  * @param is  Referencia al flujo de entrada
  * @param dic Referencia al diccionario que se modifica
  * @return Flujo de salida
  */

std::istream & operator >> (std::istream & is, Diccionario & dic) {
	std::string palabra;
	unsigned total   = 0,
	         digitos = 0;

	printf ("\033[1;34m==> \033[0m%s\n\n",
	        "Calculando total de palabras a introducir...");

	while (getline(is, palabra))
		total++;

	for (int i=total; i>0; i/=10, digitos++);

	is.clear();
	is.seekg(0);

	for (int i=0; getline(is, palabra); i++) {
		printf ("\r\033[A\033[2K\033[1;34m==> "
		        "\033[1;36m[\033[0m %*d \033[1;36m/\033[0m %d \033[1;36m]"
		        "\033[0m %s\033[1;34m -> \033[0m%s\n",
		        digitos, i+1, total,
		        "Introduciendo palabras", palabra.c_str());
		dic.Aniade(palabra);
	}

	return is;
}

/** @brief Operador asociado de salida del diciconario
  *
  * Muestra ordenadamente todas las letras del diccionario.
  *
  * @param os  Referencia al flujo de salida
  * @param dic Referencia constante al diccionario que se consulta
  * @return Flujo de salida
  */

std::ostream & operator << (std::ostream & os, const Diccionario & dic) {
	for (std::set<std::string>::const_iterator it=dic.palabras.cbegin();
	                                           it!=dic.palabras.cend(); ++it)
		os << *it << std::endl;

	return os;
}
