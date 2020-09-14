/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file include/diccionario.hpp
  */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "bolsa.hpp"
#include "letra.hpp"

/** @class Diccionario
  * @brief Almacenamiento de palabras conocidas por el programa
  *
  * @var palabras Contenedor de palabras conocidas
  */

class Diccionario {
private:
	std::set<std::string> palabras;

public:
	Diccionario ();
	Diccionario (const Diccionario & otro);

	void Aniade (std::string palabra);
	unsigned NumPalabras () const;
	unsigned MaximaLongitud () const;

	std::vector<Letra> CuentaLetras () const;
	std::set<std::string> BuscaPalabras (Bolsa bolsa) const;

	friend std::istream & operator >> (std::istream & is, Diccionario & dic);
	friend std::ostream & operator << (std::ostream & os,
	                                   const Diccionario & dic);
};
