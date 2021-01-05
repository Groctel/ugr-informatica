#ifndef PRACTICAS_JIRAFA
#define PRACTICAS_JIRAFA

#include "mallas/cubo.hpp"
#include "modelo-jerarquico/patas_jirafa.hpp"

class Jirafa
{
private:
	Cubo        * tronco_inferior = nullptr;
	PatasJirafa * patas           = nullptr;

public:
	 Jirafa () noexcept;
	~Jirafa () noexcept;

	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez,
		const unsigned char color
	) noexcept;
};

#endif
