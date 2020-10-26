#include "ply.hpp"

template <class T>
inline void PLY :: Redimensionar (
	const std::string & linea,
	std::vector<T> & tabla
) noexcept
{
	std::smatch tamanio;
	std::regex_search(linea, tamanio, std::regex("[0-9]+ *$"));
	tabla.resize(std::stoi(tamanio[0]));
}

void PLY :: InterpretarCabecera (std::ifstream & fi)
{
	bool cabecera_finalizada    = false;
	std::string linea;

	std::getline(fi, linea);

	if (! std::regex_search(linea, std::regex("^ *format *ascii")))
		throw std::runtime_error("PLY sin formato ASCII.");

	while (! cabecera_finalizada && std::getline(fi, linea))
	{
		if (! std::regex_search(linea, std::regex("^ *comment")))
		{
			cabecera_finalizada = std::regex_search(linea,
				std::regex("^ *end_header")
			);

			if (std::regex_search(linea, std::regex("^ *element *face")))
				Redimensionar(linea, caras);

			if (std::regex_search(linea, std::regex("^ *element *vertex")))
				Redimensionar(linea, vertices);
		}
	}

	if (!cabecera_finalizada)
		throw std::runtime_error("Cabecera de PLY no finalizada.");

	if (fi.eof())
		throw std::runtime_error("PLY vacío tras su cabecera.");
}

void PLY :: InterpretarVertices (std::ifstream & fi) noexcept
{
	float coordenadas[3];
	std::string linea;

	for (size_t i = 0; i < vertices.size(); i++)
	{
		fi >> coordenadas[0];
		fi >> coordenadas[1];
		fi >> coordenadas[2];

		vertices[i] = {coordenadas[0], coordenadas[1], coordenadas[2]};
	}
}

void PLY :: InterpretarCaras (std::ifstream & fi) noexcept
{
	int vertices[3];
	std::string linea;

	for (size_t i = 0; i < caras.size(); i++)
	{
		fi >> vertices[0];
		fi >> vertices[0];
		fi >> vertices[1];
		fi >> vertices[2];

		caras[i] = {vertices[0], vertices[1], vertices[2]};
	}
}

PLY :: PLY (const std::string & ruta)
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

	InterpretarCabecera(fi);
	InterpretarVertices(fi);
	InterpretarCaras(fi);
}
