/** @file objrevolucion.hpp
 */

#ifndef PRACTICAS_OBJREVOLUCION
#define PRACTICAS_OBJREVOLUCION

#include <string>
#include <vector>
#include "malla.hpp"
#include "tuplasg.hpp"

enum Tapas
{
	Ninguna,
	Superior,
	Inferior,
	Ambas
};

class ObjRevolucion : public Malla3D
{
protected:
	std::vector<tuplas::Tupla3f> perfil;

public:
	ObjRevolucion () noexcept;
	ObjRevolucion (
		const std::string & ruta,
		size_t iteraciones,
		const float escala=1,
		Tapas tapas = Tapas::Ambas
	) noexcept;
	ObjRevolucion (
		const std::vector<tuplas::Tupla3f> & nuevo_perfil,
		size_t iteraciones,
		Tapas tapas = Tapas::Ambas
	) noexcept;

	tuplas::Tupla3f              PuntoPerfil (const size_t indice) const;
	std::vector<tuplas::Tupla3f> Perfil      () const noexcept;

	void RenovarPerfil (const std::string & ruta) noexcept;
	void RenovarPerfil (const std::vector<tuplas::Tupla3f> & nuevo_perfil) noexcept;
	void Revolucionar  (size_t iteraciones, Tapas tapas = Tapas::Ambas) noexcept;
};

#endif
