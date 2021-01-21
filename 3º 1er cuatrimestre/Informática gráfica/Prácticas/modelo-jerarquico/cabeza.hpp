#ifndef PRACTICAS_CABEZA_JIRAFA
#define PRACTICAS_CABEZA_JIRAFA

#include "mallas/cubo.hpp"

class CabezaJirafa
{
private:
	Cubo * craneo      = nullptr;
	Cubo * cuerno_izdo = nullptr;
	Cubo * cuerno_dcho = nullptr;
	Cubo * mandibula   = nullptr;
	Cubo * oreja_izda  = nullptr;
	Cubo * oreja_dcha  = nullptr;

public:
	 CabezaJirafa ();
	~CabezaJirafa ();

	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez,
		const unsigned char color
	) noexcept;
};

#endif

