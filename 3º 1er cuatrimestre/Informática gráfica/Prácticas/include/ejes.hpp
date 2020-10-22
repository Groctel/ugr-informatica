/** @file ejes.hpp
 */

#ifndef PRACTICAS_EJES
#define PRACTICAS_EJES

#include <stdexcept>
#include "colores.hpp"
#include "motor.hpp"

/** @class Ejes
 *
 * @brief Ejes cartesianos centrados en el origen.
 */

class Ejes {
private:
	float tamanio;
	std::vector<tuplas::Tupla3f> colores;
	std::vector<tuplas::Tupla3f> vertices;

	inline void InicializarColores() noexcept;
	inline void InicializarVertices() noexcept;

public:
	Ejes (float tam=1000);

	void Dibujar ();

	void Tamanio () const noexcept;
	void Tamanio (float tam);
};

#endif
