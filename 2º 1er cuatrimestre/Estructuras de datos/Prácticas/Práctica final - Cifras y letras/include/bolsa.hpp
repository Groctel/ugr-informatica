/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file include/bolsa.hpp
  */

#include <vector>
#include <algorithm>

#ifndef BOLSA
#define BOLSA

/** @class Bolsa
  * @brief Almacenamiento de la bolsa de letras
  *
  * @var max    Tamaño máximo de la bolsa
  * @var tam    Tamaño actual de la bolsa
  * @var letras Contenedor subyacente de la bolsa
  */

class Bolsa {
private:
	unsigned max;
	unsigned tam;

	std::vector<char> letras;

public:
	Bolsa ();
	Bolsa (const unsigned m);
	Bolsa (const Bolsa & otra);

	unsigned          Max    () const;
	unsigned          Tam    () const;
	std::vector<char> Letras () const;

	void Aniade   (const char c);
	void NuevoMax (const unsigned m);

	bool Siguiente ();

	Bolsa & operator =  (const Bolsa & otra);
	char  & operator [] (const unsigned i);
};

#endif
