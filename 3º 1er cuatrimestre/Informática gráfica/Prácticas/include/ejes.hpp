#ifndef PRACTICAS_EJES
#define PRACTICAS_EJES

#include "motor.hpp"

class Ejes {
private:
	float tamanio;
	std::vector<tuplas::Tupla3f> colores;
	std::vector<tuplas::Tupla3f> vertices;

	void InicializarColores();
	void InicializarVertices();

public:
	Ejes (float tam=1000);

	void Dibujar ();
	void NuevoTamanio (float nuevo);
};

#endif
