#ifndef PIEZA
#define PIEZA

#include <iostream>
#include <vector>
#include "rotacion.hpp"

class Pieza {
private:
	bool cuadrado,
	     rectangulo;
	char id;

	std::vector<std::vector<bool> > forma;
	std::vector<std::vector<bool> > forma_cw;
	std::vector<std::vector<bool> > forma_ccw;
	std::vector<std::vector<bool> > forma_pi;

	std::vector<std::vector<bool> > RotaCW  () const;
	std::vector<std::vector<bool> > RotaCW  (const std::vector<std::vector<bool> > & rotable) const;
	std::vector<std::vector<bool> > RotaCCW () const;
	std::vector<std::vector<bool> > RotaPI  () const;

public:
	Pieza (bool c, bool r, char i, std::vector<std::vector<bool> > f);

	size_t Altura     (Rotacion rotacion = Rotacion::Original) const;
	size_t Anchura    (Rotacion rotacion = Rotacion::Original) const;
	size_t Tamanio    () const;
	bool   Cuadrado   () const;
	bool   Rectangulo () const;
	char   ID         () const;

	std::vector<std::vector<bool> > Forma (Rotacion rotacion = Rotacion::Original) const;

	void Imprime (Rotacion rotacion = Rotacion::Original) const;

	bool operator < (const Pieza & otra) const;
};


#endif
