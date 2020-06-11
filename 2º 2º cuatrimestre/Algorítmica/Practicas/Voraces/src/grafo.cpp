#include "grafo.hpp"

/** @fn bool Grafo :: AristaValida (size_t vertice1, size_t vertice2)
  * @brief
  *
  * @param vertice1 Vértice que marca el primer extremo de la arista
  * @param vertice2 Vértice que marca el segundo extremo de la arista
  *
  * @return Capacidad de la arista `vertice1-vertice2` como componente del ciclo
  * de Euler
  *
  * Consideramos que la arista `vertice1-vertice2` es válida en dos casos:
  *
  * - `vertice2` es el único vértice adyacente a `vertice1`.
  * - Hay múltiples vértices adyacentes, en cuyo caso `vertice1-vertice2` sólo
  *   es válido si el resultado de contar los vértices accesibles desde
  *   `vertice1` teniendo en cuenta la arista es mayor que dicho resultado sin
  *   tenerla en cuenta.
  */

bool Grafo :: EsPuente (size_t vertice1, size_t vertice2) {
	size_t total_adyacentes     = vertices[vertice1].size(),
	       profundidad_original = 0,
	       profundidad_truncada = 0;

	if (total_adyacentes != 1) {
		bool visited[vertices.size()];

		for (size_t i=0; i<vertices.size(); i++)
			visited[i] = false;

		profundidad_original = DFS(vertice1, visited);
		EliminaArista(vertice1, vertice2);

		for (size_t i=0; i<vertices.size(); i++)
			visited[i] = false;

		profundidad_truncada = DFS(vertice1, visited);
		AniadeArista(vertice1, vertice2);
	}

	return total_adyacentes != 1
	    && profundidad_original > profundidad_truncada;
}

/** @fn int Grafo :: DFS (int vertice, bool visited[])
  * @brief Contador de vértices accesibles mediante búsqueda en profundidad
  *
  * @param vertice   Vértice sobre el que se buscan los vértices accesibles
  * @param visitados Vector de vértices visitados por el algoritmo
  *
  * @return Cuenta de accesibilidad desde el vértice `vertice`
  */

size_t Grafo :: DFS (const size_t vertice, bool visitados[]) {
	size_t accesibles = 1;

	visitados[vertice] = true;

	for (std::set<size_t>::const_iterator it=vertices[vertice].cbegin();
	     it!=vertices[vertice].cend(); ++it) {
		if (!visitados[*it])
			accesibles += DFS(*it, visitados);
	}

	return accesibles;
}

/** void Grafo :: ImprimeElementoEuler (int u)
  * @brief Imprime un ciclo de Euler
  *
  * @param vertice Vértice a partir del cual se empieza el ciclo de Euler
  */

void Grafo :: ImprimeElemento (size_t vertice) {
	for (auto it=vertices[vertice].cbegin();
	     !vertices[vertice].empty() && it!=vertices[vertice].cend(); ++it) {
		size_t adyacente = *it;

		if (!EsPuente(vertice, adyacente)) {
			std::cout << " - " << adyacente;

			EliminaArista(vertice, adyacente);
			ImprimeElemento(adyacente);
		}
	}
}

/** @fn void Grafo :: AniadeArista (size_t vertice1, size_t vertice2)
  * @brief Añade una arista
  *
  * @param vertice1 Vértice que marca el primer extremo de la arista
  * @param vertice2 Vértice que marca el segundo extremo de la arista
  *
  * Añade a la seta de vértices adyacentes de cada vértice el vértice opuesto
  * para crear la conexión entre ambos.
  */

void Grafo :: AniadeArista (const size_t vertice1, const size_t vertice2) {
	if (std::max(vertice1, vertice2) >= vertices.size())
		for (size_t i=vertices.size(); i<std::max(vertice1, vertice2)+1; i++)
			vertices.emplace_back(std::set<size_t>());

	vertices[vertice1].insert(vertice2);
	vertices[vertice2].insert(vertice1);
}

/** @fn void Grafo :: EliminaArista (size_t vertice1, size_t vertice2)
  * @brief Elimina la arista que une los vértices `vertice1` y `vertice2`
  *
  * @param vertice1 Vértice que marca el primer extremo de la arista
  * @param vertice2 Vértice que marca el segundo extremo de la arista
  *
  * Busca el vértice opuesto en la seta de vértices adyacentes de cada vértice
  * y los reemplaza por `-1`.
  */

void Grafo :: EliminaArista (const size_t vertice1, const size_t vertice2) {
	auto it_v1 = find(vertices[vertice1].begin(),
	                  vertices[vertice1].end(),
	                  vertice2);

	auto it_v2 = find(vertices[vertice2].begin(),
	                  vertices[vertice2].end(),
	                  vertice1);

	vertices[vertice1].erase(*it_v1);
	vertices[vertice2].erase(*it_v2);
}

/** @fn void Grafo :: ImprimeCicloEuler ()
  * @brief Imprime un ciclo de Euler
  *
  * Busca un vértice de grado impar y comienza el ciclo de Euler por él.
  */

void Grafo :: Fleury () {
	bool encontrado  = false;
	size_t vertice = 0;

	for (size_t i=0; i<vertices.size() && !encontrado; i++) {
		if (vertices[i].size() & 1)
			encontrado = (vertice = i);
	}

	std::cout << "{ " << vertice;
	ImprimeElemento(vertice);
	std::cout << " }" << std::endl;
}
