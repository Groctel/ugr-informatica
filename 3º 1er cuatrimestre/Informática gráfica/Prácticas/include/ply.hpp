#ifndef PRACTICAS_PLY
#define PRACTICAS_PLY

#include <fstream>
#include <regex>
#include <string>
#include <utility>
#include <vector>
#include "tuplasg.hpp"

class PLY {
protected:
	std::ifstream Abrir (const std::string & ruta);

	std::pair<size_t, size_t> InterpretarCabecera (std::ifstream & fi);

	std::vector<tuplas::Tupla3f> InterpretarVertices (
		std::ifstream & fi,
		const size_t tamanio
	) noexcept;

	std::vector<tuplas::Tupla3u> InterpretarCaras (
		std::ifstream & fi,
		const size_t tamanio
	) noexcept;

	inline size_t LeerDimensiones (const std::string & linea) noexcept;
};

#endif
