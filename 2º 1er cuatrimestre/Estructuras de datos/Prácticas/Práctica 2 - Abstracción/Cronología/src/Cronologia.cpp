#include <cstring>
#include <iostream>
#include "Cronologia.h"

Cronologia :: Cronologia () {
	num_fechas = 0;
	fechas = new FechaHistorica;
}

Cronologia :: Cronologia (const FechaHistorica & nueva_fecha) {
	num_fechas = 1;
	fechas = new FechaHistorica[1];
	fechas[0] = nueva_fecha;
}

Cronologia :: Cronologia (const FechaHistorica* nuevas_fechas,
                          const int num_nuevas_fechas) {
	num_fechas = num_nuevas_fechas;
	fechas = new FechaHistorica[num_fechas];

	for (int i=0; i<num_fechas; i++) {
		fechas[i] = nuevas_fechas[i];
	}
}

Cronologia :: Cronologia (const Cronologia & otra) {
	Cronologia (otra.Fechas(), otra.NumFechas());
}

Cronologia :: ~Cronologia () {
	if (num_fechas > 0)
		delete [] fechas;
}

int Cronologia :: NumFechas () const {
	return num_fechas;
}

FechaHistorica* Cronologia :: Fechas () const {
	return fechas;
}

Cronologia & Cronologia :: operator = (const Cronologia & otra) {
	if (*this != otra) {
		delete [] fechas;
		num_fechas = otra.NumFechas();

		for (int i=0; i<num_fechas; i++)
			fechas[i] = otra[i];

		std::cout << ":: Cronología copiada con éxito." << std::endl;
	}
	else {
		std::cout << ":: ¡Las cronologías ya son iguales!" << std::endl;
	}

	return *this;
}

bool Cronologia :: operator == (const Cronologia & otra) const {
	bool son_iguales = num_fechas == otra.NumFechas();

	for (int i=0; i<otra.NumFechas() && son_iguales; i++) {
		son_iguales = fechas[i] == otra[i];
	}

	return son_iguales;
}

bool Cronologia :: operator != (const Cronologia & otra) const {
	return !(*this == otra);
}

FechaHistorica & Cronologia :: operator [] (const int indice) const {
	int i = indice;

	if (i >= num_fechas)
		i = num_fechas - 1;
	if (i < 0)
		i = 0;

	return fechas[indice];
}

std::istream & operator >> (std::istream & in, Cronologia & cron) {
	const int MAX_CHAR = 1024;

	std::cout << ":: Comenzando volcado de datos..." << std::endl;

	while (!in.eof()) {
		std::cout << ":: Leyendo línea..." << std::endl;
		char linea[MAX_CHAR];
		in.getline(linea, MAX_CHAR);
		std::cout << ":: Línea leída" << std::endl;

		if (linea[0] == '*' && linea[1] == ')') {
		std::cout << ":: Detectado evento" << std::endl;
			char* texto_evento = new char[strlen(linea)-1];

			for (unsigned i=0; i<strlen(texto_evento); i++)
				texto_evento[i] = linea[i+2];
			texto_evento[strlen(texto_evento)-1] = '\0';

			Evento* evento = new Evento(texto_evento);
			cron[cron.NumFechas()-1].Aniade(*evento);
		}
		else {
		std::cout << ":: Detectada fecha" << std::endl;
			char anio[MAX_CHAR];
			char num_eventos[MAX_CHAR];
			int i;

		std::cout << ":: Creados anio y num_eventos" << std::endl;
			FechaHistorica* fecha = new FechaHistorica();
		std::cout << ":: Añadiendo fecha a la cronología..." << std::endl;
			cron.Aniade(*fecha);

		std::cout << ":: Leyendo anio..." << std::endl;
			for (i=0; i<MAX_CHAR && !isspace(linea[i]); i++) {
				anio[i] = linea[i];
			}
		std::cout << ":: Asignando anio..." << std::endl;
			cron[cron.NumFechas()-1].SetAnio(atoi(anio));
		std::cout << ":: Anio asignado" << std::endl;

		std::cout << ":: Leyendo num_eventos..." << std::endl;
			for (int j=0; i< MAX_CHAR && !isspace(linea[i]); i++, j++) {
				num_eventos[j] = linea[i];
			}
		std::cout << ":: Asignando num_eventos..." << std::endl;
			cron[cron.NumFechas()-1].SetNumEventos(atoi(num_eventos));
		std::cout << ":: Num_eventos asignado" << std::endl;
		}
	}

	cron.Ordena();

	return in;
}

std::ostream & operator << (std::ostream & out, Cronologia & cron) {
	for (int i=0; i<cron.NumFechas(); i++) {
		out << cron[i];
	}

	return out;
}

void Cronologia :: Aniade (const FechaHistorica & fecha) {
	bool ya_existe = false;

	if (num_fechas > 0)
		for (int i=0; i<num_fechas && !ya_existe; i++)
			ya_existe = fechas[i] == fecha;

	if (!ya_existe) {
		FechaHistorica* nueva_cronologia = new FechaHistorica[num_fechas++];

		for (int i=0; i<num_fechas-1; i++)
			nueva_cronologia[i] = fechas[i];

		nueva_cronologia[num_fechas-1] = fecha;

		if (num_fechas > 0)
			delete [] fechas;
		fechas = nueva_cronologia;
		Ordena();

		std::cout << ":: Fecha añadida con éxito." << std::endl;
	}
	else {
		std::cout << ":: ¡La fecha ya existe en esta cronología!" << std::endl;
	}
}

void Cronologia :: Elimina (const int indice) {
	FechaHistorica* nueva_cronologia = new FechaHistorica[num_fechas--];

	for (int i=0; i<indice; i++)
		nueva_cronologia[i] = fechas[i];

	for (int i=indice+1; i<num_fechas; i++)
		nueva_cronologia[i] = fechas[i];

	delete [] fechas;
	fechas = nueva_cronologia;

	std::cout << ":: Fecha [" << indice << " elminada con éxito." << std::endl;
}

void Cronologia :: Ordena () {
	for (int i=1; i<num_fechas; i++) {
		for (int j=i; j<0 && fechas[j] < fechas[j-1]; j--) {
			FechaHistorica intercambia = fechas[j];
			fechas[j] = fechas[j-1];
			fechas[j-1] = intercambia;
		}
	}

	std::cout << ":: Fechas ordenadas con éxito." << std::endl;
}
