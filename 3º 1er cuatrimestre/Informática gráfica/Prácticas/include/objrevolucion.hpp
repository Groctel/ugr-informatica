/** @file objrevolucion.hpp
 */

#ifndef PRACTICAS_OBJREVOLUCION
#define PRACTICAS_OBJREVOLUCION

#include <string>
#include <utility>
#include <vector>
#include "malla.hpp"
#include "tuplasg.hpp"

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
	void GenerarCaras    (const size_t iteraciones, Tapas tapas = Tapas::Ambas) noexcept;
	void GenerarVertices (const size_t iteraciones, Tapas tapas = Tapas::Ambas) noexcept;
	void GenerarTapas    () noexcept;

protected:
	std::vector<tuplas::Tupla3f> perfil;

public:
	ObjRevolucion () noexcept;
	ObjRevolucion (
		const std::string & nuevo_nombre,
		const std::string & ruta
	) noexcept;
	ObjRevolucion (
		const std::string & nuevo_nombre,
		const std::vector<tuplas::Tupla3f> & nuevo_perfil
	) noexcept;

	tuplas::Tupla3f              PuntoPerfil (const size_t indice) const;
	std::vector<tuplas::Tupla3f> Perfil      () const noexcept;

	void RenovarPerfil (const std::string & ruta) noexcept;
	void RenovarPerfil (const std::vector<tuplas::Tupla3f> & nuevo_perfil) noexcept;
	void Revolucionar  (size_t iteraciones, Tapas tapas = Tapas::Ambas) noexcept;
};

#endif
