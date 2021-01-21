/** @file ejes.hpp
 */

#ifndef PRACTICAS_EJES
#define PRACTICAS_EJES

#include <stdexcept>
#include <vector>
#include "global/colores.hpp"
#include "global/tuplasg.hpp"
#include "motor.hpp"

/** @class Ejes
 *
 * @brief Ejes cartesianos centrados en el origen.
 */

class Ejes
{
private:
	float tamanio;
	std::vector<Tupla3f> colores;
	std::vector<Tupla3f> vertices;

	inline void InicializarColores  () noexcept;
	inline void InicializarVertices () noexcept;

public:
	Ejes (float tam=1000);

	void Dibujar () const noexcept;

	float Tamanio () const noexcept;
	void NuevoTamanio (float tam);
};

#endif
