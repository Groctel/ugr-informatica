#ifndef PRACTICAS_TRONCO_SUPERIOR_JIRAFA
#define PRACTICAS_TRONCO_SUPERIOR_JIRAFA

#include "mallas/cubo.hpp"
#include "modelo-jerarquico/cabeza.hpp"

class TroncoSuperiorJirafa
{
private:
	CabezaJirafa * cabeza      = nullptr;
	Cubo         * base_cuello = nullptr;
	Cubo         * cuello      = nullptr;

public:
	 TroncoSuperiorJirafa ();
	~TroncoSuperiorJirafa ();

	void Dibujar (
		const Dibujo dibujado,
		const bool ajedrez,
		const unsigned char color
	) noexcept;
};

#endif
