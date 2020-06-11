#ifndef TABLERO
#define TABLERO

#include <climits>
#include <vector>
#include "pieza.hpp"

class Tablero {
private:
	std::vector<std::vector<char> > matriz;

	size_t DFS (size_t fila, size_t columna, std::vector<std::vector<char> > & matriz) const;

public:
	Tablero (size_t altura, size_t anchura);
	Tablero (const Tablero & otro);

	size_t Altura  () const;
	size_t Anchura () const;
	std::vector<std::vector<char> > Matriz () const;

	size_t Accesibles () const;
	size_t Accesibles (size_t fila, size_t columna) const;
	size_t Coloca     (size_t fila, size_t columna, Pieza pieza, Rotacion rotacion = Rotacion::Original);
	void   Imprime    (bool sobreescribe = false) const;

	Tablero & operator = (const Tablero & otro);
};


#endif
