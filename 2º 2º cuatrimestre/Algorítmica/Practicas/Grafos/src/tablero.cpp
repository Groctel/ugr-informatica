#include "tablero.hpp"

size_t Tablero :: DFS (size_t fila, size_t columna, std::vector<std::vector<char> > & matriz) const {
	size_t contador = (matriz[fila][columna] == 'T') ? 0 : 1;

	matriz[fila][columna] = 'T';

	if (fila+1 < Altura() && matriz[fila+1][columna] == '-' )
		contador += DFS(fila+1, columna, matriz);

	if (fila != 0 && matriz[fila-1][columna] == '-')
		contador += DFS(fila-1, columna, matriz);

	if (columna+1 < Anchura() && matriz[fila][columna+1] == '-')
		contador += DFS(fila, columna+1, matriz);

	if (columna != 0 && matriz[fila][columna-1] == '-')
		contador += DFS(fila, columna-1, matriz);

	return contador;
}

Tablero :: Tablero (size_t altura, size_t anchura) {
	for (size_t i=0; i<altura; i++) {
		matriz.emplace_back(std::vector<char>());

		for (size_t j=0; j<anchura; j++)
			matriz[i].push_back('-');
	}
}

Tablero :: Tablero (const Tablero & otro) {
	*this = otro;
}

size_t Tablero :: Altura () const {
	return matriz.size();
}

size_t Tablero :: Anchura () const {
	size_t anchura = 0;

	for (auto it=matriz.cbegin(); it!=matriz.cend(); ++it)
		anchura = std::max(anchura, (*it).size());

	return anchura;
}

std::vector<std::vector<char> > Tablero :: Matriz () const {
	return matriz;
}

size_t Tablero :: Accesibles () const {
	size_t minimo_espacio = UINT_MAX;

	for (size_t i=0; i<Altura(); i++)
		for (size_t j=0; j<Anchura(); j++)
			if (matriz[i][j] == '-')
				minimo_espacio = std::min(minimo_espacio, Accesibles(i, j));

	if (minimo_espacio == UINT_MAX)
		minimo_espacio = 0;

	return minimo_espacio;
}

size_t Tablero :: Accesibles (size_t fila, size_t columna) const {
	size_t accesibles;

	if (matriz[fila][columna] == '-') {
		std::vector<std::vector<char> > matriz_busqueda = matriz;
		accesibles = DFS(fila, columna, matriz_busqueda);
	}
	else {
		accesibles = 0;
	}

	return accesibles;
}

size_t Tablero :: Coloca (size_t fila, size_t columna, Pieza pieza, Rotacion rotacion) {
	size_t minimo_espacio = UINT_MAX;
	bool colocada = true;
	std::vector<std::vector<char> > prueba = matriz;

	for (size_t i=0; i<pieza.Altura(rotacion) && colocada; i++) {
		for (size_t j=0; j<pieza.Anchura(rotacion) && colocada; j++) {
			if ((colocada = fila+i<Altura() && columna+j<Anchura())) {
				if ((colocada = pieza.Forma(rotacion)[i][j] && prueba[fila+i][columna+j] == '-'))
					prueba[fila+i][columna+j] = pieza.ID();
				else
					colocada = !pieza.Forma(rotacion)[i][j];
			}
		}
	}

	if (colocada) {
		matriz         = prueba;
		minimo_espacio = Accesibles();
	}

	return minimo_espacio;
}

Tablero & Tablero :: operator = (const Tablero & otro) {
	matriz = otro.matriz;

	return *this;
}

void Tablero :: Imprime (bool sobreescribe) const {
	for (size_t i=0; i<Altura() && sobreescribe; i++)
		std::cout << "\x1b[A";

	for (auto it=matriz.cbegin(); it!=matriz.cend(); ++it) {
		for (auto jt=(*it).cbegin(); jt!=(*it).cend(); ++jt)
			std::cout << *jt;

		std::cout << std::endl;
	}
}
