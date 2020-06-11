#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include "pieza.hpp"
#include "tablero.hpp"

std::vector<Pieza> InicializaPiezas() {
	std::vector<Pieza> piezas;

	std::vector<std::vector<bool> > forma_0;
	std::vector<std::vector<bool> > forma_1;
	std::vector<std::vector<bool> > forma_2;
	std::vector<std::vector<bool> > forma_3;
	std::vector<std::vector<bool> > forma_4;
	std::vector<std::vector<bool> > forma_5;
	std::vector<std::vector<bool> > forma_6;
	std::vector<std::vector<bool> > forma_7;

	for (size_t i=0; i<3; i++)
		forma_0.emplace_back(std::vector<bool>());

	forma_0[0].push_back(true);
	forma_0[0].push_back(true);
	forma_0[0].push_back(true);
	forma_0[1].push_back(true);
	forma_0[1].push_back(true);
	forma_0[1].push_back(true);
	forma_0[2].push_back(true);
	forma_0[2].push_back(true);
	forma_0[2].push_back(true);

	for (size_t i=0; i<3; i++)
		forma_1.emplace_back(std::vector<bool>());

	forma_1[0].push_back(true);
	forma_1[1].push_back(true);
	forma_1[2].push_back(true);

	for (size_t i=0; i<3; i++)
		forma_2.emplace_back(std::vector<bool>());

	forma_2[0].push_back(true);
	forma_2[0].push_back(false);
	forma_2[1].push_back(true);
	forma_2[1].push_back(true);
	forma_2[2].push_back(true);
	forma_2[2].push_back(false);

	for (size_t i=0; i<3; i++)
		forma_3.emplace_back(std::vector<bool>());

	forma_3[0].push_back(true);
	forma_3[0].push_back(true);
	forma_3[0].push_back(true);
	forma_3[1].push_back(true);
	forma_3[1].push_back(false);
	forma_3[1].push_back(false);
	forma_3[2].push_back(true);
	forma_3[2].push_back(false);
	forma_3[2].push_back(false);

	for (size_t i=0; i<5; i++)
		forma_4.emplace_back(std::vector<bool>());

	forma_4[0].push_back(false);
	forma_4[0].push_back(true);
	forma_4[0].push_back(false);
	forma_4[1].push_back(false);
	forma_4[1].push_back(true);
	forma_4[1].push_back(false);
	forma_4[2].push_back(true);
	forma_4[2].push_back(true);
	forma_4[2].push_back(true);
	forma_4[3].push_back(true);
	forma_4[3].push_back(true);
	forma_4[3].push_back(true);
	forma_4[4].push_back(true);
	forma_4[4].push_back(true);
	forma_4[4].push_back(true);

	for (size_t i=0; i<2; i++)
		forma_5.emplace_back(std::vector<bool>());

	forma_5[0].push_back(true);
	forma_5[0].push_back(true);
	forma_5[0].push_back(true);
	forma_5[1].push_back(true);
	forma_5[1].push_back(true);
	forma_5[1].push_back(true);

	for (size_t i=0; i<4; i++)
		forma_6.emplace_back(std::vector<bool>());

	forma_6[0].push_back(true);
	forma_6[0].push_back(true);
	forma_6[0].push_back(false);
	forma_6[1].push_back(true);
	forma_6[1].push_back(true);
	forma_6[1].push_back(false);
	forma_6[2].push_back(true);
	forma_6[2].push_back(true);
	forma_6[2].push_back(false);
	forma_6[3].push_back(true);
	forma_6[3].push_back(true);
	forma_6[3].push_back(true);

	for (size_t i=0; i<2; i++)
		forma_7.emplace_back(std::vector<bool>());

	forma_7[0].push_back(true);
	forma_7[0].push_back(true);
	forma_7[0].push_back(true);
	forma_7[0].push_back(true);
	forma_7[1].push_back(false);
	forma_7[1].push_back(true);
	forma_7[1].push_back(true);
	forma_7[1].push_back(true);

	Pieza pieza_0(true, true, '0', forma_0);
	Pieza pieza_1(false, true, '1', forma_1);
	Pieza pieza_2(false, false, '2', forma_2);
	Pieza pieza_3(false, false, '3', forma_3);
	Pieza pieza_4(false, false, '4', forma_4);
	Pieza pieza_5(false, true, '5', forma_5);
	Pieza pieza_6(false, false, '6', forma_6);
	Pieza pieza_7(false, false, '7', forma_7);

	piezas.push_back(pieza_1);
	piezas.push_back(pieza_2);
	piezas.push_back(pieza_3);
	piezas.push_back(pieza_5);
	piezas.push_back(pieza_7);
	piezas.push_back(pieza_4);
	piezas.push_back(pieza_0);
	piezas.push_back(pieza_6);

	return piezas;
}

size_t MinimoTamanio (const std::vector<Pieza> & piezas, const size_t inicio) {
	size_t minimo_tamanio = UINT_MAX;

	for (size_t i=inicio; i<piezas.size(); i++)
		minimo_tamanio = std::min(minimo_tamanio, piezas[i].Tamanio());

	return minimo_tamanio;
}

bool Resuelve (const Tablero & tablero, std::vector<Pieza> & piezas, const size_t & inicio, bool & resuelto) {
	for (size_t fila=0; fila<tablero.Altura() && !resuelto; fila++) {
		for (size_t columna=0; columna<tablero.Anchura() && !resuelto; columna++) {
			Rotacion rotacion;

			for (unsigned i=0; i<4 && !resuelto; i++) {
				switch (i) {
					case 0: rotacion = Rotacion::Original; break;
					case 1: rotacion = Rotacion::CW;       break;
					case 2: rotacion = Rotacion::CCW;      break;
					case 3: rotacion = Rotacion::PI;       break;
				}

				if ((piezas[inicio].Cuadrado() && rotacion == Rotacion::Original)
				||  (piezas[inicio].Rectangulo() && (rotacion == Rotacion::Original || rotacion == Rotacion::CW))
				||  (!piezas[inicio].Cuadrado() && !piezas[inicio].Rectangulo())) {
					Tablero tablero_hijo(tablero);
					size_t accesibles = tablero_hijo.Coloca(fila, columna, piezas[inicio], rotacion);

					tablero_hijo.Imprime(true);

					if (accesibles != UINT_MAX) {
						resuelto = !accesibles;

						if (!resuelto && accesibles >= MinimoTamanio(piezas, inicio+1)) {
							size_t inicio_hijo = inicio + 1;
							Resuelve(tablero_hijo, piezas, inicio_hijo, resuelto);
						}
					}
				}
			}
		}
	}

	return resuelto;
}

int main (int argc, char ** argv) {
	Tablero tablero(6, 9);
	bool resuelto = false;
	std::vector<Pieza> piezas = InicializaPiezas();

	tablero.Imprime();

	std::sort(piezas.begin(), piezas.end());
	std::reverse(piezas.begin(), piezas.end());
	std::cout << (Resuelve(tablero, piezas, 0, resuelto) ? "Solución encontrada."
	                                                     : "Solución no encontrada")
	          << std::endl;

	return 0;
}
