// A C++ program print Eulerian Trail in a given Eulerian or Semi-Eulerian Grafo
#include "grafo.hpp"

// Driver program to test above function
int main () {
	Grafo g1;
	g1.AniadeArista(0, 1);
	g1.AniadeArista(0, 2);
	g1.AniadeArista(1, 2);
	g1.AniadeArista(2, 3);
	g1.Fleury();

	Grafo g2;
	g2.AniadeArista(0, 1);
	g2.AniadeArista(1, 2);
	g2.AniadeArista(2, 0);
	g2.Fleury();

	Grafo g3;
	g3.AniadeArista(1, 0);
	g3.AniadeArista(0, 2);
	g3.AniadeArista(2, 1);
	g3.AniadeArista(0, 3);
	g3.AniadeArista(3, 4);
	g3.AniadeArista(3, 2);
	g3.AniadeArista(3, 1);
	g3.AniadeArista(2, 4);
	g3.Fleury();

	return 0;
}
