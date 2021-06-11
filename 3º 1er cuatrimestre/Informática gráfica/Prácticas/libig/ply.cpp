#include "ply.hpp"

size_t PLY :: LeerDimensiones (const std::string & linea) noexcept
{
	std::smatch tamanio;
	std::regex_search(linea, tamanio, std::regex("[0-9]+ *$"));
	return (std::stoi(tamanio[0]));
}

size_t PLY :: PosicionPropiedad (
	const std::vector<PropiedadesPLY> propiedades,
	const PropiedadesPLY propiedad
) noexcept
{
	size_t posicion;
	bool encontrada = false;

	for (posicion = 0; posicion < propiedades.size() && !encontrada; posicion++)
		encontrada = propiedades[posicion] == propiedad;

	if (!encontrada)
		posicion = nulppt;

	return posicion - 1;
}

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

CabeceraPLY PLY :: LeerCabecera (std::ifstream & fi)
{
	CabeceraPLY cabecera;

	bool cabecera_finalizada = false;
	std::string linea;

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
				cabecera.vertices = LeerDimensiones(linea);

			if (std::regex_search(linea, std::regex("^ *element *face")))
				cabecera.caras = LeerDimensiones(linea);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *x")))
				cabecera.propiedades.push_back(PropiedadesPLY::x);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *y")))
				cabecera.propiedades.push_back(PropiedadesPLY::y);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *z")))
				cabecera.propiedades.push_back(PropiedadesPLY::z);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *nx")))
				cabecera.propiedades.push_back(PropiedadesPLY::nx);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *ny")))
				cabecera.propiedades.push_back(PropiedadesPLY::ny);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *nz")))
				cabecera.propiedades.push_back(PropiedadesPLY::nz);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *s")))
				cabecera.propiedades.push_back(PropiedadesPLY::s);

			if (std::regex_search(linea, std::regex("^ *property *float[0-9]* *t")))
				cabecera.propiedades.push_back(PropiedadesPLY::t);
		}
	}

	if (!cabecera_finalizada)
		throw std::runtime_error("Cabecera de PLY no finalizada.");

	if (fi.eof())
		throw std::runtime_error("PLY vacío tras su cabecera.");

	return cabecera;
}

std::vector<Tupla3f> PLY :: LeerVertices (
	std::ifstream & fi,
	const CabeceraPLY cabecera
) noexcept
{
	std::vector<Tupla3f> vertices(cabecera.vertices);
	std::string linea;
	bool cabecera_finalizada = false;

	size_t pos_x = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::x);
	size_t pos_y = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::y);
	size_t pos_z = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::z);

	pos_y -= (pos_x + 1);
	pos_z -= (pos_x + pos_y + 2);

	if (
		pos_x == (size_t) nulppt ||
		pos_y == (size_t) nulppt ||
		pos_z == (size_t) nulppt
	) {
		return vertices;
	}

	fi.seekg(0);

	while (!cabecera_finalizada)
	{
		std::getline(fi, linea);
		cabecera_finalizada = std::regex_search(
			linea,
			std::regex("^ *end_header")
		);
	}

	for (size_t i = 0; i < vertices.size(); i++)
	{
		for (size_t i = 0; i < pos_x; i++)
			fi >> vertices[i][X];

		fi >> vertices[i][X];

		for (size_t i = 0; i < pos_y; i++)
			fi >> vertices[i][Y];

		fi >> vertices[i][Y];

		for (size_t i = 0; i < pos_z; i++)
			fi >> vertices[i][Z];

		fi >> vertices[i][Z];

		fi.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return vertices;
}

std::vector<Tupla3u> PLY :: LeerCaras (
	std::ifstream & fi,
	const CabeceraPLY cabecera
) noexcept
{
	std::vector<Tupla3u> caras(cabecera.caras);
	std::string linea;
	bool cabecera_finalizada = false;

	fi.seekg(0);

	while (!cabecera_finalizada)
	{
		std::getline(fi, linea);
		cabecera_finalizada = std::regex_search(
			linea,
			std::regex("^ *end_header")
		);
	}

	for (size_t i = 0; i < cabecera.vertices; i++)
		fi.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (size_t i = 0; i < caras.size(); i++)
	{
		fi >> caras[i][0];
		fi >> caras[i][0];
		fi >> caras[i][1];
		fi >> caras[i][2];
	}

	return caras;
}

std::vector<Tupla3f> PLY :: LeerNormales (
	std::ifstream & fi,
	const CabeceraPLY cabecera
) noexcept
{
	std::vector<Tupla3f> normales(cabecera.vertices);
	std::string linea;
	bool cabecera_finalizada = false;

	size_t pos_nx = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::nx);
	size_t pos_ny = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::ny);
	size_t pos_nz = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::nz);

	pos_ny -= (pos_nx + 1);
	pos_nz -= (pos_nx + pos_ny + 2);

	if (
		pos_nx == (size_t) nulppt ||
		pos_ny == (size_t) nulppt ||
		pos_nz == (size_t) nulppt
	) {
		return normales;
	}

	fi.seekg(0);

	while (!cabecera_finalizada)
	{
		std::getline(fi, linea);
		cabecera_finalizada = std::regex_search(
			linea,
			std::regex("^ *end_header")
		);
	}

	for (size_t i = 0; i < normales.size(); i++)
	{
		for (size_t i = 0; i < pos_nx; i++)
			fi >> normales[i][X];

		fi >> normales[i][X];

		for (size_t i = 0; i < pos_ny; i++)
			fi >> normales[i][Y];

		fi >> normales[i][Y];

		for (size_t i = 0; i < pos_nz; i++)
			fi >> normales[i][Z];

		fi >> normales[i][Z];

		fi.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return normales;
}

std::vector<Tupla2f> PLY :: LeerCoordTextura (
	std::ifstream & fi,
	const CabeceraPLY cabecera
) noexcept
{
	std::vector<Tupla2f> coord_textura(cabecera.vertices);
	std::string linea;
	bool cabecera_finalizada = false;

	size_t pos_s = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::s);
	size_t pos_t = PosicionPropiedad(cabecera.propiedades, PropiedadesPLY::t);

	pos_t -= (pos_s + 1);

	if (
		pos_s == (size_t) nulppt ||
		pos_t == (size_t) nulppt
	) {
		return coord_textura;
	}

	fi.seekg(0);

	while (!cabecera_finalizada)
	{
		std::getline(fi, linea);
		cabecera_finalizada = std::regex_search(
			linea,
			std::regex("^ *end_header")
		);
	}

	for (size_t i = 0; i < coord_textura.size(); i++)
	{
		for (size_t i = 0; i < pos_s; i++)
			fi >> coord_textura[i][0];

		fi >> coord_textura[i][0];

		for (size_t i = 0; i < pos_t; i++)
			fi >> coord_textura[i][1];

		fi >> coord_textura[i][1];

		fi.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return coord_textura;
}
