#include <cstring>
#include <iostream>
#include "Evento.h"

Evento :: Evento () {
	texto = new char;
}

Evento :: Evento (const char* nuevo_texto) {
	texto = new char;
	Modifica(nuevo_texto);
}

Evento :: Evento (const Evento & otro) {
	texto = new char;
	Modifica(otro.Texto());
}

Evento :: ~Evento() {
	delete [] texto;
}

char* Evento :: Texto() const {
	return texto;
}

Evento & Evento :: operator = (const Evento & otro) {
	if (*this != otro)
		Modifica(otro.Texto());

	return *this;
}

bool Evento :: operator == (const Evento & otro) const {
	return !strcmp(Texto(), otro.Texto());
}

bool Evento :: operator != (const Evento & otro) const {
	return !(*this == otro);
}

bool Evento :: operator > (const Evento & otro) const {
	return strcmp(Texto(), otro.Texto()) > 0;
}

bool Evento :: operator < (const Evento & otro) const {
	return *this != otro && !(*this > otro);
}

bool Evento :: operator >= (const Evento & otro) const {
	return *this == otro || *this > otro;
}

bool Evento :: operator <= (const Evento & otro) const {
	return *this == otro || *this < otro;
}


std::istream & operator >> (std::istream & in, Evento & evento) {
	const int MAX_CHAR = 256;

	char* linea = new char[MAX_CHAR];
	in.getline(linea, MAX_CHAR);

	evento.Modifica(linea);

	delete [] linea;

	return in;
}

std::ostream & operator << (std::ostream & out, const Evento & evento) {
	if (strlen(evento.Texto()))
		out << evento.Texto() << std::endl;

	return out;
}

void Evento :: Modifica (const char* nuevo_texto) {
	char* modificado = new char[strlen(nuevo_texto)+1];
	strcpy (modificado, nuevo_texto);

	if (modificado[0] == '*' && modificado[1] == ')') {
		char* limpio = new char[strlen(modificado)-1];

		for (unsigned i=0; i<strlen(modificado)-2; i++)
			limpio[i]=modificado[i+2];

		limpio[strlen(limpio)] = '\0';
	}

	if (texto)
		delete [] texto;

 	texto = modificado;

	std::cout << ":: Evento modificado con éxito." << std::endl;
}
