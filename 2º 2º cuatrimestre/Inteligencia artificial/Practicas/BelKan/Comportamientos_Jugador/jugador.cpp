#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <utility>

int DistanciaManhattan (const Estado & origen, const Estado & destino) {
	return abs(origen.fila - destino.fila)
	     + abs(origen.columna - destino.columna);
}

Action ComportamientoJugador :: think (Sensores sensores) {
	if (sensores.terreno[0] == Terreno::Bikini)
		actual.bikini = true;

	if (sensores.terreno[0] == Terreno::Zapatillas)
		actual.zapatillas = true;

	if (destino.fila    != sensores.destinoF
	||  destino.columna != sensores.destinoC)
		hay_plan  = false;

	if (sensores.nivel == 4) {
		if (sensores.terreno[2] == Terreno::Agua   && !actual.bikini
		||  sensores.terreno[2] == Terreno::Bosque && !actual.zapatillas)
			hay_plan = false;

		if (NecesidadRecarga(baterias, sensores) > 0.75) {
			Estado mas_cercana;
			mas_cercana.fila    = 100;
			mas_cercana.columna = 100;

			for (auto it=baterias.cbegin(); it!=baterias.cend(); ++it) {
				if (DistanciaManhattan(actual, *it) < DistanciaManhattan(actual, mas_cercana)) {
					mas_cercana.fila    = (*it).fila;
					mas_cercana.columna = (*it).columna;
				}
			}

			tmp_bateria = destino;
			destino     = mas_cercana;
			hay_plan    = false;
		}

		if (recalcula == 0)
			hay_plan = false;
	}

	if (!hay_plan) {
		actual.fila        = sensores.posF;
		actual.columna     = sensores.posC;
		actual.orientacion = sensores.sentido;
		destino.fila       = sensores.destinoF;
		destino.columna    = sensores.destinoC;
		hay_plan           = pathFinding(sensores, actual, destino, plan);
	}

	Action siguiente;

	if (sensores.nivel != 4) {
		if (hay_plan && plan.size() > 0) {
			siguiente = plan.front();
			plan.erase(plan.begin());
		}
		else {
			// No se pudo encontrar un comportamiento o el método de búsqueda está mal
		}
	}
	else {
		if ((sensores.sentido == norte
		   && mapaResultado[sensores.posF-3][sensores.posC] == Terreno::Desconocido
		|| sensores.sentido == sur
		   && mapaResultado[sensores.posF+3][sensores.posC] == Terreno::Desconocido
		|| sensores.sentido == este
		   && mapaResultado[sensores.posF][sensores.posC+3] == Terreno::Desconocido
		|| sensores.sentido == oeste
		   && mapaResultado[sensores.posF][sensores.posC-3] == Terreno::Desconocido)
		&& recalcula <= 0)
			recalcula = 3;
		PiramideVisionaria(sensores);

		if (sensores.terreno[0] == Terreno::Recarga
		&&  (3000-sensores.bateria) < 20) {
			siguiente = actIDLE;
		}
		else if (sensores.terreno[0] == Terreno::Recarga
		     &&  sensores.posF == destino.fila
			  &&  sensores.posC == destino.columna) {
				siguiente = actIDLE;
				destino   = tmp_bateria;
				hay_plan  = false;
		}
		else if (hay_plan && plan.size() > 0) {
			if (sensores.superficie[2] == Superficie::Aldeano) {
				siguiente = actIDLE;
			}
			else if (( sensores.terreno[2] == Terreno::Muro
			        || sensores.terreno[2] == Terreno::Precipicio)
			     && (*plan.begin()) == actFORWARD) {
				if (sensores.destinoF < sensores.posF
				||  sensores.destinoC < sensores.posC)
					siguiente = actTURN_L;
				else
					siguiente = actTURN_R;

				hay_plan  = false;
			}
			else {
				siguiente = plan.front();

				if (plan.front() == actFORWARD)
					recalcula --;

				plan.erase(plan.begin());
			}
		}
		else if (plan.empty()) {
			hay_plan = false;
		}
	}

	return siguiente;
}

// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador :: pathFinding (Sensores sensores,
                                           const Estado & origen,
                                           const Estado & destino,
                                           list<Action> & plan) {

	switch (sensores.nivel) {
		case 1:
			cout << "Busqueda en profundad" << endl;
			return pathFinding_Profundidad(origen, destino, plan);
		break;

		case 2:
			cout << "Busqueda en Anchura" << endl;
			return pathFinding_Anchura(origen, destino, plan);
		break;

		case 3:
			cout << "Busqueda Costo Uniforme" << endl;
			return pathFinding_CUniforme(origen, destino, plan);
		break;

		case 4:
			cout << "Busqueda para el reto" << endl;
			return pathFinding_AEstrella(origen, destino, plan);
		break;
	}

	cout << "Comportamiento sin implementar" << endl;
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo (unsigned char casilla) {
	if (casilla=='P' or casilla=='M')
		return true;
	else
	  return false;
}

// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador :: HayObstaculoDelante (Estado & st) {
	unsigned fil = st.fila,
	         col = st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
		st.fila    = fil;
		st.columna = col;

		if (mapaResultado[fil][col] == Terreno::Bikini)
			st.bikini = true;

		if (mapaResultado[fil][col] == Terreno::Zapatillas)
			st.zapatillas = true;

		return false;
	}
	else {

	  return true;
	}
}

bool EstadosIguales (const Estado & a, const Estado & n) {
	return (a.fila        == n.fila
	    &&  a.columna     == n.columna
	    &&  a.orientacion == n.orientacion
	    &&  a.bikini      == n.bikini
	    &&  a.zapatillas  == n.zapatillas);
}

// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador :: pathFinding_Profundidad (const Estado & origen,
                                                       const Estado & destino,
                                                       list<Action> & plan) {
	//Borro la lista
	cout << "Calculando plan" << endl;
	plan.clear();
	set<Estado, ComparaEstados> cerrados; // Lista de Cerrados
	stack<Nodo> abiertos; // Lista de Abiertos

	Nodo current;
	current.estado = origen;
	current.acciones.clear();

	abiertos.push(current);

	while (!abiertos.empty()
	   && (  current.estado.fila != destino.fila
	      || current.estado.columna != destino.columna)) {
		abiertos.pop();
		cerrados.insert(current.estado);

		// Generar descendiente de girar a la derecha
		Nodo hijoTurnR = current;
		hijoTurnR.estado.orientacion = (hijoTurnR.estado.orientacion + 1) % 4;

		if (cerrados.find(hijoTurnR.estado) == cerrados.end()) {
			hijoTurnR.acciones.push_back(actTURN_R);
			abiertos.push(hijoTurnR);
		}

		// Generar descendiente de girar a la izquierda
		Nodo hijoTurnL = current;
		hijoTurnL.estado.orientacion = (hijoTurnL.estado.orientacion + 3) % 4;

		if (cerrados.find(hijoTurnL.estado) == cerrados.end()) {
			hijoTurnL.acciones.push_back(actTURN_L);
			abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		Nodo hijoForward = current;

		if (!HayObstaculoDelante(hijoForward.estado)
		&&  cerrados.find(hijoForward.estado) == cerrados.end()) {
			hijoForward.acciones.push_back(actFORWARD);
			abiertos.push(hijoForward);
		}

		// Tomo el siguiente valor de la pila
		if (!abiertos.empty()) {
			current = abiertos.top();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.estado.fila == destino.fila
	&&  current.estado.columna == destino.columna) {
		cout << "Cargando el plan" << endl;
		plan = current.acciones;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);

		return true;
	}
	else {
		cout << "No encontrado plan" << endl;
	}

	return false;
}

bool ComportamientoJugador :: pathFinding_Anchura (const Estado & origen,
                                                       const Estado & destino,
                                                       list<Action> & plan) {
	//Borro la lista
	cout << "Calculando plan" << endl;
	plan.clear();
	set<Estado, ComparaEstados> cerrados; // Lista de Cerrados
	queue<Nodo> abiertos; // Lista de Abiertos

	Nodo current;
	current.estado = origen;
	current.acciones.clear();

	abiertos.push(current);

	while (!abiertos.empty()
	   && (  current.estado.fila != destino.fila
	      || current.estado.columna != destino.columna)) {
		abiertos.pop();
		cerrados.insert(current.estado);

		// Generar descendiente de girar a la derecha
		Nodo hijoTurnR = current;
		hijoTurnR.estado.orientacion = (hijoTurnR.estado.orientacion + 1) % 4;

		if (cerrados.find(hijoTurnR.estado) == cerrados.end()) {
			hijoTurnR.acciones.push_back(actTURN_R);
			abiertos.push(hijoTurnR);
		}

		// Generar descendiente de girar a la izquierda
		Nodo hijoTurnL = current;
		hijoTurnL.estado.orientacion = (hijoTurnL.estado.orientacion + 3) % 4;

		if (cerrados.find(hijoTurnL.estado) == cerrados.end()) {
			hijoTurnL.acciones.push_back(actTURN_L);
			abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		Nodo hijoForward = current;

		if (!HayObstaculoDelante(hijoForward.estado)
		&&  cerrados.find(hijoForward.estado) == cerrados.end()) {
			hijoForward.acciones.push_back(actFORWARD);
			abiertos.push(hijoForward);
		}

		// Tomo el siguiente valor de la pila
		if (!abiertos.empty()) {
			current = abiertos.front();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.estado.fila == destino.fila
	&&  current.estado.columna == destino.columna) {
		cout << "Cargando el plan" << endl;
		plan = current.acciones;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);

		return true;
	}
	else {
		cout << "No encontrado plan" << endl;
	}

	return false;
}

// Implementación de la búsqueda en anchura.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador :: pathFinding_Raro (const Estado & origen,
                                                   const Estado & destino,
                                                   list<Action> & plan) {
	//Borro la lista
	cout << "Calculando plan" << endl;
	plan.clear();
	set<Estado,ComparaEstados> cerrados; // Lista de Cerrados
	queue<Nodo> abiertos; // Lista de Abiertos

	Nodo current;
	current.estado = origen;
	current.acciones.clear();

	abiertos.push(current);

	while (!abiertos.empty()
	   && (  current.estado.fila != destino.fila
		   || current.estado.columna != destino.columna)) {

		abiertos.pop();
		cerrados.insert(current.estado);
	/*
	 *	Generar descendiente de girar a la derecha
	 */
		Nodo hijoTurnR = current;
		hijoTurnR.estado.orientacion = (hijoTurnR.estado.orientacion + 1) % 4;

		if (cerrados.find(hijoTurnR.estado) == cerrados.end()) {
			hijoTurnR.acciones.push_back(actTURN_R);
			abiertos.push(hijoTurnR);
		}
	/*
	 *	Generar descendiente de girar a la izquierda
	 */
		Nodo hijoTurnL = current;
		hijoTurnL.estado.orientacion = (hijoTurnL.estado.orientacion + 3) % 4;

		if (cerrados.find(hijoTurnL.estado) == cerrados.end()) {
			hijoTurnL.acciones.push_back(actTURN_L);
			abiertos.push(hijoTurnL);
		}
	/*
	 *	Generar descendiente de avanzar
	 */
		Nodo hijoForward = current;

		if (!HayObstaculoDelante(hijoForward.estado)
		&&  cerrados.find(hijoForward.estado) == cerrados.end()) {
			hijoForward.acciones.push_back(actFORWARD);
			abiertos.push(hijoForward);
		}
	/*
	 *	Tomamos el siguiente valor de la cola
	 */
		if (!abiertos.empty()) {
			current = abiertos.front();
			abiertos.pop();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.estado.fila    == destino.fila
	&&  current.estado.columna == destino.columna) {
		cout << "Cargando el plan" << endl;
		plan = current.acciones;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);

		return true;
	}

	cout << "No encontrado plan" << endl;

	return false;
}

void ComportamientoJugador :: Coste (Nodo & nodo) {
	switch (mapaResultado[nodo.estado.fila][nodo.estado.columna]) {
		case Terreno::Agua:
			nodo.coste_g           += (nodo.estado.bikini ? 10 : 100);
		break;

		case Terreno::Bikini:
			nodo.coste_g           += 1;
		break;

		case Terreno::Bosque:
			nodo.coste_g           += (nodo.estado.zapatillas ? 5 : 50);
		break;

		case Terreno::Desconocido:
			nodo.coste_g           += 3;
		break;

		case Terreno::Recarga:
			nodo.coste_g           += 1;
		break;

		case Terreno::Suelo:
			nodo.coste_g           += 1;
		break;

		case Terreno::Tierra:
			nodo.coste_g           += 2;
		break;

		case Terreno::Zapatillas:
			nodo.coste_g           += 1;
		break;
	}
}

multiset<Nodo, ComparaCostes> :: const_iterator BuscaNodo
                                (const multiset<Nodo, ComparaCostes> & abiertos,
                                 const Nodo & nodo){
	for (auto it=abiertos.begin(); it!=abiertos.end(); ++it) {
		if(EstadosIguales((*it).estado, nodo.estado))
			return it;
	}

  return abiertos.end();
}


//Costo uniforme
bool ComportamientoJugador::pathFinding_CUniforme (const Estado & origen,
                                                   const Estado & destino,
                                                   list<Action> & plan) {
	//Borrar la lista
	cout << "Calculando plan" << endl;
	plan.clear();

	multiset<Nodo, ComparaCostes> abiertos;
	set<Estado, ComparaEstados> cerrados;

	Nodo current;
	current.estado  = origen;
	current.coste_g = 0;
	current.coste_h = 0;
	current.estado.bikini = false;
	current.estado.zapatillas = false;
	current.acciones.clear();

	abiertos.insert(current);

	while (!abiertos.empty()
	   && (  current.estado.fila    != destino.fila
		   || current.estado.columna != destino.columna)) {
		abiertos.erase(abiertos.begin());
		cerrados.insert(current.estado);

		// Generar descendiente de girar a la derecha
		Nodo hijoTurnR = current;
		hijoTurnR.estado.orientacion = (hijoTurnR.estado.orientacion + 1) % 4;

		if (cerrados.find(hijoTurnR.estado) == cerrados.end()) {
			Coste(hijoTurnR);
			hijoTurnR.acciones.push_back(actTURN_R);

			auto it = BuscaNodo(abiertos, hijoTurnR);

			if (it == abiertos.end()) {
				abiertos.insert(hijoTurnR);
			}
			else if (hijoTurnR.coste_g < (*it).coste_g) {
				abiertos.erase(it);
				abiertos.insert(hijoTurnR);
			}
		}

		// Generar descendiente de girar a la izquierda
		Nodo hijoTurnL = current;
		hijoTurnL.estado.orientacion = (hijoTurnL.estado.orientacion + 3) % 4;

		if (cerrados.find(hijoTurnL.estado) == cerrados.end()) {
			hijoTurnL.acciones.push_back(actTURN_L);
			Coste(hijoTurnL);

			auto it = BuscaNodo(abiertos, hijoTurnL);

			if (it == abiertos.end()) {
				abiertos.insert(hijoTurnL);
			}
			else if (hijoTurnL.coste_g < (*it).coste_g) {
				abiertos.erase(it);
				abiertos.insert(hijoTurnL);
			}
		}

		// Generar descendiente de avanzar
		Nodo hijoForward = current;

		Coste(hijoForward);
		if (!HayObstaculoDelante(hijoForward.estado)
		&&  cerrados.find(hijoForward.estado) == cerrados.end()) {
			hijoForward.acciones.push_back(actFORWARD);

			auto it = BuscaNodo(abiertos, hijoForward);

			if (it == abiertos.end()) {
				abiertos.insert(hijoForward);
			}
			else if (hijoForward.coste_g < (*it).coste_g) {
				abiertos.erase(it);
				abiertos.insert(hijoForward);
			}
		}

		if (!abiertos.empty()) {
			current = *abiertos.begin();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.estado.fila    == destino.fila
	&&  current.estado.columna == destino.columna) {
		cout << "Cargando el plan\n";
		plan = current.acciones;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);

		return true;
	}
	else
		cout << "No encontrado plan" << endl;

	return false;
}

// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador :: PintaPlan (const list<Action> plan) const {
	for (auto it=plan.cbegin(); it!=plan.cend(); ++it) {
		if (*it == actFORWARD) {
			cout << "A";
		}
		else if (*it == actTURN_R) {
			cout << "D";
		}
		else if (*it == actTURN_L) {
			cout << "I";
		}
		else {
			cout << "-";
		}

		cout << " ";
	}

	cout << endl;
}

void ComportamientoJugador :: PiramideVisionaria (Sensores sensores) {
	int k = 0;

	mapaResultado[sensores.posF][sensores.posC] = sensores.terreno[0];

	for (unsigned i=0; i<4; i++) {
		for (unsigned j=0; j<=i*2; j++) {
			switch (sensores.sentido) {
				case norte:
					mapaResultado[sensores.posF-i][sensores.posC-i+j] = sensores.terreno[k];
				break;

				case sur:
					mapaResultado[sensores.posF+i][sensores.posC+i-j] = sensores.terreno[k];
				break;

				case este:
					mapaResultado[sensores.posF-i+j][sensores.posC+i] = sensores.terreno[k];
				break;

				case oeste:
					mapaResultado[sensores.posF+i-j][sensores.posC-i] = sensores.terreno[k];
				break;
			}

			if (sensores.terreno[k] == Terreno::Recarga) {
				int fila, columna;

				switch (sensores.sentido) {
					case norte:
						fila    = sensores.posF-i;
						columna = sensores.posC-i+j;
					break;

					case sur:
						fila    = sensores.posF+i;
						columna = sensores.posC+i-j;
					break;

					case este:
						fila    = sensores.posF-i+j;
						columna = sensores.posC+i;
					break;

					case oeste:
						fila    = sensores.posF+i-j;
						columna = sensores.posC-i;
					break;
				}

				Estado bateria;
				bateria.fila    = fila;
				bateria.columna = columna;
				baterias.insert(bateria);
			}

			k++;
		}
	}
}

double ComportamientoJugador :: NecesidadRecarga (const set<Estado, ComparaEstados> & baterias,
                                                  Sensores sensores) {
	double necesidad = 0;
	Estado actual;
	actual.fila      = sensores.posF;
	actual.columna   = sensores.posC;

	if (!baterias.empty()) {
		Estado mas_cercana;
		mas_cercana.fila    = 100;
		mas_cercana.columna = 100;

		for (auto it=baterias.cbegin(); it!=baterias.cend(); ++it) {
			if (DistanciaManhattan(actual, *it) <  DistanciaManhattan(actual, mas_cercana)) {
				mas_cercana.fila    = (*it).fila;
				mas_cercana.columna = (*it).columna;
			}
		}

		necesidad = ( ((3000.0 - sensores.bateria) / 1000.0)
		            * (200.0 -  DistanciaManhattan(actual, mas_cercana))
		          / 600.0);
	}

	return necesidad;
}

bool ComportamientoJugador :: pathFinding_AEstrella (const Estado & origen,
                                                     const Estado & destino,
                                                     list<Action> & plan) {
	//Borrar la lista
	cout << "Calculando plan" << endl;
	plan.clear();

	multiset<Nodo, ComparaCostes> abiertos;
	set<Estado, ComparaEstados> cerrados;

	Nodo current;
	current.estado  = origen;
	current.coste_g = 0;
	current.coste_h = DistanciaManhattan(origen, destino);
	current.estado.bikini = origen.bikini;
	current.estado.zapatillas = origen.zapatillas;
	current.acciones.clear();

	abiertos.insert(current);

	while (!abiertos.empty()
	   && (  current.estado.fila    != destino.fila
		   || current.estado.columna != destino.columna)) {
		abiertos.erase(abiertos.begin());
		cerrados.insert(current.estado);

		// Generar descendiente de girar a la derecha
		Nodo hijoTurnR = current;
		hijoTurnR.estado.orientacion = (hijoTurnR.estado.orientacion + 1) % 4;

		if (cerrados.find(hijoTurnR.estado) == cerrados.end()) {
			Coste(hijoTurnR);
			hijoTurnR.coste_h = DistanciaManhattan(hijoTurnR.estado, destino);
			hijoTurnR.acciones.push_back(actTURN_R);

			auto it = BuscaNodo(abiertos, hijoTurnR);

			if (it == abiertos.end()) {
				abiertos.insert(hijoTurnR);
			}
			else if (hijoTurnR.coste_g+hijoTurnR.coste_h
			      <  (*it).coste_g+(*it).coste_h) {
				abiertos.erase(it);
				abiertos.insert(hijoTurnR);
			}
		}

		// Generar descendiente de girar a la izquierda
		Nodo hijoTurnL = current;
		hijoTurnL.estado.orientacion = (hijoTurnL.estado.orientacion + 3) % 4;

		if (cerrados.find(hijoTurnL.estado) == cerrados.end()) {
			hijoTurnL.acciones.push_back(actTURN_L);
			Coste(hijoTurnL);
			hijoTurnL.coste_h = DistanciaManhattan(hijoTurnL.estado, destino);

			auto it = BuscaNodo(abiertos, hijoTurnL);

			if (it == abiertos.end()) {
				abiertos.insert(hijoTurnL);
			}
			else if (hijoTurnL.coste_g+hijoTurnL.coste_h
			      <  (*it).coste_g+(*it).coste_h) {
				abiertos.erase(it);
				abiertos.insert(hijoTurnL);
			}
		}

		// Generar descendiente de avanzar
		Nodo hijoForward = current;

		Coste(hijoForward);
		hijoForward.coste_h = DistanciaManhattan(hijoForward.estado, destino);

		if (!HayObstaculoDelante(hijoForward.estado)
		&&  cerrados.find(hijoForward.estado) == cerrados.end()) {
			hijoForward.acciones.push_back(actFORWARD);

			auto it = BuscaNodo(abiertos, hijoForward);

			if (it == abiertos.end()) {
				abiertos.insert(hijoForward);
			}
			else if (hijoForward.coste_g+hijoForward.coste_h
			      <  (*it).coste_g+(*it).coste_h) {
				abiertos.erase(it);
				abiertos.insert(hijoForward);
			}
		}

		if (!abiertos.empty()) {
			current = *abiertos.begin();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.estado.fila    == destino.fila
	&&  current.estado.columna == destino.columna) {
		cout << "Cargando el plan\n";
		plan = current.acciones;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);

		return true;
	}
	else
		cout << "No encontrado plan" << endl;

	return false;
}

void AnularMatriz (vector<vector<unsigned char> > & m) {
	for (unsigned i=0; i<m[0].size(); i++)
		for (unsigned j=0; j<m.size(); j++)
			m[i][j]=0;
}

// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador :: VisualizaPlan (const Estado & estado,
                                             const list<Action> & plan) {
	AnularMatriz(mapaConPlan);
	Estado cst = estado;

	auto it = plan.begin();
	while (it!=plan.end()) {
		if (*it == actFORWARD) {
			switch (cst.orientacion) {
				case 0: cst.fila--;    break;
				case 1: cst.columna++; break;
				case 2: cst.fila++;    break;
				case 3: cst.columna--; break;
			}

			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R) {
			cst.orientacion = (cst.orientacion + 1) % 4;
		}
		else {
			cst.orientacion = (cst.orientacion + 3) % 4;
		}

		it++;
	}
}

int ComportamientoJugador :: interact (Action accion, int valor) {
  return false;
}
