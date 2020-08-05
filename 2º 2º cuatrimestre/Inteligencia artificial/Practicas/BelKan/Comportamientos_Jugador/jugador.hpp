#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>
#include <set>

enum Terreno : unsigned char {
	Agua        = 'A',
	Bikini      = 'K',
	Bosque      = 'B',
	Desconocido = '?',
	Muro        = 'M',
	Precipicio  = 'P',
	Recarga     = 'X',
	Suelo       = 'S',
	Tierra      = 'T',
	Zapatillas  = 'D',
};

enum Superficie : unsigned char {
	Aldeano = 'a',
	Jugador = 'j'
};

struct Estado {
	bool zapatillas;
	bool bikini;
	int fila;
	int columna;
	int orientacion;
};

struct Nodo {
	Estado estado;
	list<Action> acciones;
	int coste_g;
	int coste_h;
};

struct ComparaCostes {
	bool operator () (const Nodo & uno, const Nodo & otro) const {
		return (uno.coste_g + uno.coste_h) <= (otro.coste_g + otro.coste_h);
	}
};

struct ComparaEstados {
	bool operator () (const Estado & a, const Estado & n) const {
		return a.fila > n.fila
		    || a.fila == n.fila
		       && a.columna > n.columna
		    || a.fila == n.fila
		       && a.columna == n.columna
		       && a.orientacion > n.orientacion
		    || a.fila == n.fila
		       && a.columna == n.columna
		       && a.orientacion == n.orientacion
		       && (  a.bikini != n.bikini
		          || a.zapatillas != n.zapatillas);
	}
};

class ComportamientoJugador : public Comportamiento {
public:
	ComportamientoJugador (unsigned int size): Comportamiento(size) {
		// Inicializar Variables de Estado
		fil                 = col = 99;
		brujula             = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
		destino.fila        = -1;
		destino.columna     = -1;
		destino.orientacion = -1;
		hay_plan            = false;
		recalcula           = 0;
	}

	ComportamientoJugador (std::vector< std::vector< unsigned char> > mapaR)
	                      : Comportamiento(mapaR) {
		// Inicializar Variables de Estado
		fil                 = col = 99;
		brujula             = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
		destino.fila        = -1;
		destino.columna     = -1;
		destino.orientacion = -1;
		hay_plan            = false;
		recalcula           = 0;
	}

	ComportamientoJugador (const ComportamientoJugador & comport)
	                      : Comportamiento(comport) { }
	~ComportamientoJugador () { }

	Action think(Sensores sensores);
	int interact(Action accion, int valor);
	void VisualizaPlan(const Estado & estado, const list<Action> & plan);
	ComportamientoJugador * clone () {
		return new ComportamientoJugador(*this);
	}

private:
	// Declarar Variables de Estado
	int fil, col, brujula, recalcula;
	Estado actual, destino, tmp_bateria;
	list<Action> plan;
	bool hay_plan;
	set<Estado, ComparaEstados> baterias;

	// Métodos privados de la clase
	bool pathFinding             (Sensores sensores, const Estado & origen,
	                              const Estado & destino, list<Action> & plan);
	bool pathFinding_Profundidad (const Estado & origen,
	                              const Estado & destino,
	                              list<Action> & plan);
	bool pathFinding_Anchura     (const Estado & origen,
	                              const Estado & destino,
	                              list<Action> & plan);
	bool pathFinding_Raro     (const Estado & origen,
	                              const Estado & destino,
	                              list<Action> & plan);
	bool pathFinding_CUniforme   (const Estado & origen,
	                              const Estado & destino,
	                              list<Action> & plan);
	bool pathFinding_AEstrella   (const Estado & origen,
	                              const Estado & destino,
	                              list<Action> & plan);

	double NecesidadRecarga (const set<Estado, ComparaEstados> & baterias,
	                         Sensores sensores);

	void PiramideVisionaria (Sensores sensores);

	void Coste (Nodo & nodo);
	void PintaPlan(const list<Action> plan) const;
	bool HayObstaculoDelante(Estado &st);
	Estado EncuentraEnMapa (Terreno terreno);
};

#endif
