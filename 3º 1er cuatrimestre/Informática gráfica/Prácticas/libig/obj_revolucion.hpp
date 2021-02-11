/** @file obj_revolucion.hpp
 */

#ifndef PRACTICAS_OBJREVOLUCION
#define PRACTICAS_OBJREVOLUCION

#include <array>
#include <string>
#include <utility>
#include <vector>
#include "enum.hpp"
#include "global/globals.hpp"
#include "global/tuplasg.hpp"
#include "malla.hpp"
#include "ply.hpp"

#define tapa_inf first
#define tapa_sup second

class ObjRevolucion : public Malla3D
{
private:
	size_t iteraciones = 0;
	bool mostrar_tapas = true;

	GLuint vbo_vertices_sin_tapas = 0;
	GLuint vbo_caras_sin_tapas    = 0;
	std::pair<GLuint, GLuint> vbo_caras_ajedrez_tapas = {0,0};

	void AplicarTexturaCilindrica () noexcept;
	void AplicarTexturaEsferica   () noexcept;
	void AplicarTexturaPlana      () noexcept;

	void DibujarAjedrezDiferido  () noexcept override;
	void DibujarAjedrezInmediato () const noexcept override;
	void EnviarDibujoDiferido    () noexcept override;
	void EnviarDibujoInmediato   () const noexcept override;

	void GenerarAjedrez  () noexcept override;
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

	void AplicarTextura (Textura * nueva, const ModoTextura modo) noexcept;
	void MostrarTapas   (const bool nuevo_estado) noexcept;
};

#endif
