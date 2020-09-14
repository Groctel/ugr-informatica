#include <iostream>

#ifndef EVENTO
#define EVENTO

class Evento {
private:
	char* texto;
public:
	Evento  ();
	Evento  (const char* nuevo_texto);
	Evento  (const Evento & otro);
	~Evento ();

	char* Texto () const;

	Evento & operator =  (const Evento & otro);
	bool     operator == (const Evento & otro) const;
	bool     operator != (const Evento & otro) const;
	bool     operator >  (const Evento & otro) const;
	bool     operator <  (const Evento & otro) const;
	bool     operator >= (const Evento & otro) const;
	bool     operator <= (const Evento & otro) const;

	friend std::istream & operator >> (std::istream & in, Evento & evento);
	friend std::ostream & operator << (std::ostream & out,
	                                   const Evento & evento);

	void Modifica (const char* nuevo_texto);
};

#endif

