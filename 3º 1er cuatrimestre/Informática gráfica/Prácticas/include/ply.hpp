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
	static size_t LeerDimensiones (const std::string & linea) noexcept;

public:
	static std::ifstream Abrir (const std::string & ruta);

	static std::pair<size_t, size_t> LeerCabecera (std::ifstream & fi);

	static std::vector<tuplas::Tupla3f> LeerVertices (
		std::ifstream & fi,
		const size_t tamanio
	) noexcept;

	static std::vector<tuplas::Tupla3u> LeerCaras (
		std::ifstream & fi,
		const size_t tamanio
	) noexcept;
};

#endif
