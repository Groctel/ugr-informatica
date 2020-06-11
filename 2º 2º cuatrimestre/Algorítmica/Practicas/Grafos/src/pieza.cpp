#include <algorithm>
#include "pieza.hpp"

std::vector<std::vector<bool> > Pieza :: RotaCW () const {
	return RotaCW(forma);
}

std::vector<std::vector<bool> > Pieza ::RotaCW (const std::vector<std::vector<bool> > & rotable) const {
	size_t filas = 0;
	std::vector<std::vector<bool> > rotada;

	for (auto it=rotable.cbegin(); it!=rotable.cend(); ++it)
		filas = std::max(filas, (*it).size());

	for (size_t i=0; i<filas; i++)
		rotada.emplace_back(std::vector<bool>());

	for (auto it=rotable.crbegin(); it!=rotable.crend(); ++it) {
		size_t fila = 0;

		for (auto jt=(*it).cbegin(); jt!=(*it).cend(); ++jt, fila++)
			rotada[fila].push_back(*jt);
	}

	return rotada;
}

std::vector<std::vector<bool> > Pieza ::RotaCCW () const {
	return RotaCW(RotaCW(RotaCW()));
}

std::vector<std::vector<bool> > Pieza ::RotaPI  () const {
	return RotaCW(RotaCW());
}

Pieza :: Pieza (bool c, bool r, char i, std::vector<std::vector<bool> > f)
	:cuadrado   (c),
	 rectangulo (r),
	 id         (i),
	 forma      (f) {

	forma_cw  = RotaCW();
	forma_ccw = RotaCCW();
	forma_pi  = RotaPI();
}

size_t Pieza :: Altura (Rotacion rotacion) const {
	size_t altura = 0;

	switch (rotacion) {
		case Rotacion::Original:
			altura = forma.size();
		break;

		case Rotacion::CW:
			altura = forma_cw.size();
		break;

		case Rotacion::CCW:
			altura = forma_ccw.size();
		break;

		case Rotacion::PI:
			altura = forma_pi.size();
		break;
	}

	return altura;
}

size_t Pieza :: Anchura (Rotacion rotacion) const {
	size_t anchura = 0;

	switch (rotacion) {
		case Rotacion::Original:
			for (auto it=forma.cbegin(); it!=forma.cend(); ++it)
				anchura = std::max(anchura, (*it).size());
		break;

		case Rotacion::CW:
			for (auto it=forma_cw.cbegin(); it!=forma_cw.cend(); ++it)
				anchura = std::max(anchura, (*it).size());
		break;

		case Rotacion::CCW:
			for (auto it=forma_ccw.cbegin(); it!=forma_ccw.cend(); ++it)
				anchura = std::max(anchura, (*it).size());
		break;

		case Rotacion::PI:
			for (auto it=forma_pi.cbegin(); it!=forma_pi.cend(); ++it)
				anchura = std::max(anchura, (*it).size());
		break;
	}

	return anchura;
}

size_t Pieza :: Tamanio () const {
	size_t tamanio = 0;

	for (auto it=forma.cbegin(); it!=forma.cend(); ++it)
		tamanio += std::count((*it).cbegin(), (*it).cend(), true);

	return tamanio;
}

bool Pieza :: Cuadrado () const {
	return cuadrado;
}

bool Pieza :: Rectangulo () const {
	return rectangulo;
}

char Pieza :: ID () const {
	return id;
}

std::vector<std::vector<bool> > Pieza :: Forma (Rotacion rotacion) const {
	std::vector<std::vector<bool> > extraible;

	switch (rotacion) {
		case Rotacion::Original:
			extraible = forma;
		break;

		case Rotacion::CW:
			extraible = forma_cw;
		break;

		case Rotacion::CCW:
			extraible = forma_ccw;
		break;

		case Rotacion::PI:
			extraible = forma_pi;
		break;
	}

	return extraible;
}

void Pieza :: Imprime (Rotacion rotacion) const {
	std::vector<std::vector<bool> > imprimible = forma;

	if (rotacion == Rotacion::CW) {
		imprimible = forma_cw;
	}
	else if (rotacion == Rotacion::CCW) {
		imprimible = forma_ccw;
	}
	else if (rotacion == Rotacion::PI) {
		imprimible = forma_pi;
	}

	for (auto it=imprimible.cbegin(); it!=imprimible.cend(); ++it) {
		for (auto jt=(*it).cbegin(); jt!=(*it).cend(); ++jt)
			std::cout << ((*jt) ? "X" : "·");

		std::cout << std::endl;
	}
}

bool Pieza :: operator < (const Pieza & otra) const {
	return Tamanio() < otra.Tamanio();
}
