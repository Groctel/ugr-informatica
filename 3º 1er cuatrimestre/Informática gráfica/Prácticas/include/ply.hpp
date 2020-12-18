#ifndef PRACTICAS_PLY
#define PRACTICAS_PLY

#include <fstream>
#include <regex>
#include <string>
#include <utility>
#include <vector>
#include "tuplasg.hpp"

class PLY {
private:
	inline size_t LeerDimensiones (const std::string & linea) const noexcept;

public:
	std::ifstream Abrir (const std::string & ruta) const;

	std::pair<size_t, size_t> InterpretarCabecera (std::ifstream & fi) const;

	std::vector<tuplas::Tupla3f> InterpretarVertices (
		std::ifstream & fi,
		const size_t tamanio
	) const noexcept;

	std::vector<tuplas::Tupla3u> InterpretarCaras (
		std::ifstream & fi,
		const size_t tamanio
	) const noexcept;
};

#endif
