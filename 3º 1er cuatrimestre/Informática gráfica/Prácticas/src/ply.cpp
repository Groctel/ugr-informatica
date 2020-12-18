#include "ply.hpp"

std::ifstream PLY :: Abrir (const std::string & ruta)
{
	std::ifstream fi;
	std::string linea;

	if (! std::regex_search(ruta, std::regex("\\.ply$")))
		fi.open(ruta + ".ply");
	else
		fi.open(ruta);

	if (! fi.is_open())
		throw std::runtime_error("Error crítico al abrir \"" + ruta + "\".");

	std::getline(fi, linea);

	if (linea != "ply")
		throw std::runtime_error("Fallo en sintaxis PLY de \"" + ruta + "\".");

	return fi;
}

std::pair<size_t, size_t> PLY :: LeerCabecera (std::ifstream & fi)
{
	bool cabecera_finalizada = false;
	std::string linea;
	std::pair<size_t, size_t> dimensiones;

	std::getline(fi, linea);

	if (! std::regex_search(linea, std::regex("^ *format *ascii")))
		throw std::runtime_error("PLY sin formato ASCII.");

	while (! cabecera_finalizada && std::getline(fi, linea))
	{
		if (! std::regex_search(linea, std::regex("^ *comment")))
		{
			cabecera_finalizada = std::regex_search(
				linea,
				std::regex("^ *end_header")
			);

			if (std::regex_search(linea, std::regex("^ *element *vertex")))
				dimensiones.first = LeerDimensiones(linea);

			if (std::regex_search(linea, std::regex("^ *element *face")))
				dimensiones.second = LeerDimensiones(linea);
		}
	}

	if (!cabecera_finalizada)
		throw std::runtime_error("Cabecera de PLY no finalizada.");

	if (fi.eof())
		throw std::runtime_error("PLY vacío tras su cabecera.");

	return dimensiones;
}

std::vector<tuplas::Tupla3f> PLY :: LeerVertices (
	std::ifstream & fi,
	const size_t tamanio
) noexcept
{
	std::vector<tuplas::Tupla3f> vertices(tamanio);

	for (size_t i = 0; i < vertices.size(); i++)
	{
		fi >> vertices[i][0];
		fi >> vertices[i][1];
		fi >> vertices[i][2];
	}

	return vertices;
}

std::vector<tuplas::Tupla3u> PLY :: LeerCaras (
	std::ifstream & fi,
	const size_t tamanio
) noexcept
{
	std::vector<tuplas::Tupla3u> caras(tamanio);

	for (size_t i = 0; i < caras.size(); i++)
	{
		fi >> caras[i][0];
		fi >> caras[i][0];
		fi >> caras[i][1];
		fi >> caras[i][2];
	}

	return caras;
}

size_t PLY :: LeerDimensiones (const std::string & linea) noexcept
{
	std::smatch tamanio;
	std::regex_search(linea, tamanio, std::regex("[0-9]+ *$"));
	return (std::stoi(tamanio[0]));
}

