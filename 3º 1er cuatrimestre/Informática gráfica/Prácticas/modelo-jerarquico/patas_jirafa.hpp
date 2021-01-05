#ifndef PRACTICAS_PATAS_JIRAFA
#define PRACTICAS_PATAS_JIRAFA

#include "mallas/cubo.hpp"

class PatasJirafa
{
private:
	Cubo * delantera_izda = nullptr;
	Cubo * delantera_dcha = nullptr;
	Cubo * trasera_izda   = nullptr;
	Cubo * trasera_dcha   = nullptr;

public:
	 PatasJirafa () noexcept;
	~PatasJirafa () noexcept;

	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez,
		const unsigned char color
	) noexcept;
};

#endif
