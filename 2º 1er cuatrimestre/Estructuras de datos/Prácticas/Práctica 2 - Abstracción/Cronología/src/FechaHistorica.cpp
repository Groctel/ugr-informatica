#include <iostream>
#include <cstring>
#include "FechaHistorica.h"
#include "Evento.h"

FechaHistorica :: FechaHistorica () {
	anio = 0;
	num_eventos = 0;
	eventos = new Evento;
}

FechaHistorica :: FechaHistorica (const int nuevo_anio) {
	anio = nuevo_anio;
	eventos = new Evento;
}

FechaHistorica :: FechaHistorica (const int nuevo_anio,
                                  const Evento* nuevos_eventos,
                                  const int num_nuevos_eventos) {
	anio = nuevo_anio;
	num_eventos = num_nuevos_eventos;
	eventos = new Evento[num_eventos];

	for (int i=0; i<num_eventos; i++) {
		eventos[i] = nuevos_eventos[i];
	}

	Ordena();
}

FechaHistorica :: FechaHistorica (const FechaHistorica &otra) {
	FechaHistorica (otra.Anio(), otra.Eventos(), otra.NumEventos());
}

FechaHistorica :: ~FechaHistorica () {
	if (num_eventos > 0)
		delete [] eventos;
}

int FechaHistorica :: Anio () const {
	return anio;
}

int FechaHistorica :: NumEventos () const {
	return num_eventos;
}

Evento* FechaHistorica :: Eventos () const {
	return eventos;
}

FechaHistorica & FechaHistorica :: operator = (const FechaHistorica & otra) {
	if (*this != otra) {
		anio = otra.Anio();
		num_eventos = otra.NumEventos();

		delete [] eventos;
		eventos = new Evento[num_eventos];

		for (int i=0; i<num_eventos; i++)
			eventos[i] = otra[i];

		std::cout << ":: Fecha copiada con éxito." << std::endl;
	}
	else {
		std::cout << ":: ¡Las fechas ya son iguales!" << std::endl;
	}

	return *this;
}

bool FechaHistorica :: operator == (const FechaHistorica & otra) const {
	bool son_iguales = Anio() == otra.Anio() && num_eventos == otra.NumEventos();

	for (int i=0; i<otra.NumEventos() && son_iguales; i++)
		son_iguales = eventos[i] == otra[i];

	return son_iguales;
}

bool FechaHistorica :: operator != (const FechaHistorica & otra) const {
	return !(*this == otra);
}

bool FechaHistorica :: operator > (const FechaHistorica & otra) const {
	return Anio() > otra.Anio();
}

bool FechaHistorica :: operator < (const FechaHistorica & otra) const {
	return *this != otra && !(*this > otra);
}

bool FechaHistorica :: operator >= (const FechaHistorica & otra) const {
	return *this == otra || *this > otra;
}

bool FechaHistorica :: operator <= (const FechaHistorica & otra) const {
	return *this == otra || *this > otra;
}


Evento & FechaHistorica :: operator [] (const int indice) const {
	int i = indice;

	if (indice >= num_eventos)
		i = num_eventos - 1;
	if (indice < 0)
		i = 0;

	return eventos[i];
}

std::istream & operator >> (std::istream & in, FechaHistorica & fecha) {
	const int MAX_CHAR = 2048;

	char linea[MAX_CHAR];
	char anio[MAX_CHAR];
	char num_eventos[MAX_CHAR];
	int i;

	in.getline(linea, MAX_CHAR);

	for (i=0; i<MAX_CHAR && !isspace(linea[i]); i++) {
		anio[i] = linea[i];
	}
	fecha.SetAnio(atoi(anio));

	for (int j=0; i<MAX_CHAR && !isspace(linea[i]); i++, j++) {
		num_eventos[j] = linea[i];
	}
	fecha.SetNumEventos(atoi(num_eventos));

	for (i=0;!in.eof() && i<fecha.NumEventos(); i++) {
		in.getline(linea, MAX_CHAR);
		Evento* evento = new Evento(linea);
		fecha.Aniade(*evento);
	}

	return in;
}

std::ostream & operator << (std::ostream & out, const FechaHistorica & fecha) {
	if (fecha.NumEventos() > 0) {
		out << fecha.Anio() << std::endl;

		for (int i=0; i<fecha.NumEventos()-1; i++) {
			out << "├─ " << fecha[i];
		}

		out << "└─ " << fecha[fecha.NumEventos()-1] << std::endl;
	}

	return out;
}

void FechaHistorica :: SetAnio (const int nuevo_anio) {
	anio = nuevo_anio;
	std::cout << ":: Año modificado a " << anio << "." << std::endl;
}

void FechaHistorica :: SetNumEventos (const int nuevo_num) {
	num_eventos = nuevo_num;
	std::cout << ":: Número de eventos modificado a " << num_eventos << "."
	          << std::endl;
}

void FechaHistorica :: Aniade (const Evento & evento) {
	bool ya_existe = false;

	for (int i=0; i<NumEventos() && !ya_existe; i++)
		ya_existe = eventos[i] == evento;

	if (!ya_existe) {
		Evento* nuevo_eventos = new Evento[num_eventos++];

		for (int i=0; i<num_eventos-1; i++)
			nuevo_eventos[i] = eventos[i];

		nuevo_eventos[num_eventos-1] = evento;
		delete [] eventos;
		eventos = nuevo_eventos;

		Ordena();

		std::cout << ":: Evento añadido a la fecha con éxito." << std::endl;
	}
	else {
		std::cout << ":: ¡El evento ya existe en esta fecha!" << std::endl;
	}
}

void FechaHistorica :: Elimina (const int indice) {
	if (0 <= indice && indice < num_eventos) {
		Evento* nuevo_eventos = new Evento[num_eventos--];

		for (int i=0; i<indice; i++)
			nuevo_eventos[i] = eventos[i];

		for (int i=indice+1; i<num_eventos; i++)
			nuevo_eventos[i] = eventos[i];

		delete [] eventos;
		eventos = nuevo_eventos;

		std::cout << ":: Evento [" << indice << "] eliminado con éxito."
	             << std::endl;
	}
	else {
		std::cout << ":: Evento [" << indice << "] no eliminado. "
		          << "Índice no accesible (0-" << num_eventos << ")."
					 << std::endl;
	}
}

void FechaHistorica :: Ordena () {
	for (int i=1; i<num_eventos; i++) {
		for (int j=i; j>0 && eventos[j] < eventos[j-1]; j--) {
			Evento intercambia = eventos[j];
			eventos[j] = eventos[j-1];
			eventos[j-1] = intercambia;
		}
	}

	std::cout << ":: Eventos de " << anio << " ordenados con éxito."
	          << std::endl;
}
