#ifndef PRACTICAS_PLY
#define PRACTICAS_PLY

#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include "enum.hpp"
#include "global/tuplasg.hpp"

#define nulppt ~0

typedef struct
{
	size_t vertices;
	size_t caras;
	std::vector<PropiedadesPLY> propiedades;
} CabeceraPLY;

class PLY {
private:
	static size_t LeerDimensiones   (const std::string & linea) noexcept;
	static size_t PosicionPropiedad (
		const std::vector<PropiedadesPLY> propiedades,
		const PropiedadesPLY propiedad
	) noexcept;

public:
	static std::ifstream Abrir (const std::string & ruta);

	static CabeceraPLY LeerCabecera (std::ifstream & fi);

	static std::vector<Tupla3f> LeerVertices (
		std::ifstream & fi,
		const CabeceraPLY cabecera
	) noexcept;

	static std::vector<Tupla3u> LeerCaras (
		std::ifstream & fi,
		const CabeceraPLY cabecera
	) noexcept;

	static std::vector<Tupla3f> LeerNormales (
		std::ifstream & fi,
		const CabeceraPLY cabecera
	) noexcept;

	static std::vector<Tupla2f> LeerCoordTextura (
		std::ifstream & fi,
		const CabeceraPLY cabecera
	) noexcept;
};

#endif
