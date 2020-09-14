#include <iostream>
#include "Evento.h"

#ifndef FECHAHISTORICA
#define FECHAHISTORICA

class FechaHistorica {
private:
	int     anio;
	int     num_eventos;
	Evento* eventos;

public:
	FechaHistorica  ();
	FechaHistorica  (const int nuevo_anio);
	FechaHistorica  (const int nuevo_anio, const Evento* nuevos_eventos,
	                 const int num_nuevos_eventos);
	FechaHistorica  (const FechaHistorica & otra);
	~FechaHistorica ();

	int Anio () const;
	int NumEventos () const;
	Evento* Eventos () const;

	FechaHistorica & operator =  (const FechaHistorica & otra);
	bool             operator == (const FechaHistorica & otra) const;
	bool             operator != (const FechaHistorica & otra) const;
	bool             operator >  (const FechaHistorica & otra) const;
	bool             operator <  (const FechaHistorica & otra) const;
	bool             operator >= (const FechaHistorica & otra) const;
	bool             operator <= (const FechaHistorica & otra) const;
	Evento &         operator [] (const int indice) const;

	friend std::istream & operator >> (std::istream & in,
	                                   FechaHistorica & fecha);
	friend std::ostream & operator << (std::ostream & out,
	                                   const FechaHistorica & fecha);

	void SetAnio       (const int nuevo_anio);
	void SetNumEventos (const int nuevo_num);

	void Aniade  (const Evento & evento);
	void Elimina (const int indice);
	void Ordena  ();
};

#endif
