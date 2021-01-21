/** @file obj_revolucion.hpp
 */

#ifndef PRACTICAS_OBJREVOLUCION
#define PRACTICAS_OBJREVOLUCION

#include <array>
#include <string>
#include <utility>
#include <vector>
#include "global/globals.hpp"
#include "global/tuplasg.hpp"
#include "malla.hpp"

enum Tapas
{
	Ninguna  = 0,
	Superior = 1,
	Inferior = 1,
	Ambas    = 2
};

class ObjRevolucion : public Malla3D
{
private:
	bool mostrar_tapas;

	void GenerarCaras (
		const std::vector<Tupla3f> & perfil,
		const size_t iteraciones,
		Tapas tapas
	) noexcept;

	void GenerarVertices (
		std::vector<Tupla3f> & perfil,
		const size_t iteraciones,
		Tapas tapas
	) noexcept;

protected:
	void Revolucionar  (
		std::vector<Tupla3f> & perfil,
		size_t iteraciones,
		Tapas tapas = Tapas::Ambas
	) noexcept;

public:
	ObjRevolucion () noexcept;

	ObjRevolucion (
		const std::string & ruta,
		size_t iteraciones,
		Tapas tapas = Tapas::Ambas
	) noexcept;

	ObjRevolucion (
		const std::vector<Tupla3f> & nuevo_perfil,
		size_t iteraciones,
		Tapas tapas = Tapas::Ambas
	) noexcept;

	bool MuestraTapas () const noexcept;

	void MostrarTapas (const bool estado) noexcept;
};

#endif
