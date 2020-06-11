#ifndef GRAFO
#define GRAFO

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Grafo {
private:
	std::vector<std::set<size_t> > vertices;

	bool EsPuente        (size_t vertice1, size_t vertice2);
	size_t DFS           (size_t vertice, bool visitados[]);
	void ImprimeElemento (size_t vertice);

public:
	void AniadeArista      (const size_t vertice1, const size_t vertice2);
	void EliminaArista     (const size_t vertice1, const size_t vertice2);
	void Fleury            ();
};

#endif
