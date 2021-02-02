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

#define tapa_inf first
#define tapa_sup second

/** @enum EjeRotacion
 * @brief Eje alrededor del cual se ha de rotar un ObjRevolucion.
 */

enum EjeRotacion
{
	EjeX,
	EjeY,
	EjeZ
};

/** @enum Tapas
 * @brief Cantidad de tapas con las que crear un ObjRevolucion.
 */

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
	size_t iteraciones = 0;
	bool mostrar_tapas = false;

	void GenerarCaras    (Tapas tapas) noexcept;
	void GenerarVertices (Tapas tapas, EjeRotacion eje) noexcept;

	std::pair<Tupla3f, Tupla3f> DetectarTapas (const EjeRotacion eje) noexcept;

	void RotarVerticesX () noexcept;
	void RotarVerticesY () noexcept;
	void RotarVerticesZ () noexcept;

protected:
	std::vector<Tupla3f> perfil;

	void Revolucionar  (
		size_t nuevas_iteraciones,
		Tapas tapas = Tapas::Ambas,
		EjeRotacion eje = EjeY
	) noexcept;

public:
	ObjRevolucion () noexcept;

	ObjRevolucion (
		const std::string & ruta,
		size_t nuevas_iteraciones,
		Tapas tapas = Tapas::Ambas,
		EjeRotacion eje = EjeY
	) noexcept;

	ObjRevolucion (
		const std::vector<Tupla3f> & nuevo_perfil,
		size_t nuevas_iteraciones,
		Tapas tapas = Tapas::Ambas,
		EjeRotacion eje = EjeY
	) noexcept;

	bool MuestraTapas () const noexcept;

	void AplicarTextura (const ModoTextura modo) noexcept;
	void EnviarDibujoDiferido () noexcept;
	void MostrarTapas (const bool nuevo_estado) noexcept;
};

#endif
