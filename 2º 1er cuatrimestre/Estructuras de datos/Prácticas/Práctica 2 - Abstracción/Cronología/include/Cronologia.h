#include <iostream>
#include "FechaHistorica.h"

#ifndef CRONOLOGIA
#define CRONOLOGIA

class Cronologia {
private:
	int num_fechas;
	FechaHistorica* fechas;

public:
	Cronologia  ();
	Cronologia  (const FechaHistorica & nueva_fecha);
	Cronologia  (const FechaHistorica* nuevas_fechas,
	             const int num_nuevas_fechas);
	Cronologia  (const Cronologia & otra);
	~Cronologia ();

	int NumFechas          () const;
	FechaHistorica* Fechas () const;


	Cronologia &     operator =  (const Cronologia & otra);
	bool             operator == (const Cronologia & otra) const;
	bool             operator != (const Cronologia & otra) const;
	FechaHistorica & operator [] (const int indice) const;

	friend std::istream & operator >> (std::istream & in, Cronologia & cron);
	friend std::ostream & operator << (std::ostream & outt, Cronologia & cron);

	void Aniade  (const FechaHistorica & fecha);
	void Elimina (const int indice);
	void Ordena  ();
};

#endif
