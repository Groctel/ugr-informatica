/** @file objrevolucion.hpp
 */

#ifndef PRACTICAS_OBJREVOLUCION
#define PRACTICAS_OBJREVOLUCION

#include <array>
#include <string>
#include <utility>
#include <vector>
#include "globals.hpp"
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
	inline void GenerarCaras
		(const size_t iteraciones, Tapas tapas) noexcept;

	inline void GenerarVertices
		(const size_t iteraciones, Tapas tapas, bool generar_tapas) noexcept;

	inline void InsertarTapas (Tapas tapas, bool generar_tapas) noexcept;

protected:
	std::vector<tuplas::Tupla3f>   perfil;
	std::array<tuplas::Tupla3f, 2> puntos_tapas;

	void EliminarTapas () noexcept;

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
	void Revolucionar  (
		size_t iteraciones,
		Tapas tapas = Tapas::Ambas,
		bool generar_tapas = true
	) noexcept;
};

#endif
