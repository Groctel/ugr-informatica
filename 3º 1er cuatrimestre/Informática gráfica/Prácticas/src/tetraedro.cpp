#include "tetraedro.hpp"

inline void Tetraedro :: InicializarCaras () noexcept
{
	caras.resize(4);

	caras[0]  = {0, 1, 2};
	caras[1]  = {1, 3, 2};
	caras[2]  = {2, 3, 0};
	caras[3]  = {3, 1, 0};
}

inline void Tetraedro :: InicializarColores () noexcept
{
	colores_lineas.resize(vertices.size());
	colores_puntos.resize(vertices.size());
	colores_solido.resize(vertices.size());

	for (size_t i=0; i<vertices.size(); i++)
	{
		colores_lineas[i] = coloresgl::VERDE;
		colores_puntos[i] = coloresgl::AZUL;
		colores_solido[i] = coloresgl::ROJO;
	}
}

inline void Tetraedro :: InicializarVertices (const float escala) noexcept
{
	vertices.resize(4);

	float mediana = sqrt(pow(escala, 2) - pow(escala/2, 2));
	float altura  = sqrt(pow(escala, 2) - pow(mediana/3, 2));

	vertices[0] = {-escala/2, -altura/2, -mediana/2};
	vertices[1] = {escala/2,  -altura/2, -mediana/2};
	vertices[2] = {0,         -altura/2, mediana/2 };
	vertices[3] = {0,         altura/2,  0         };
}

Tetraedro :: Tetraedro (const float escala)
{
	InicializarVertices(escala);
	InicializarCaras();
	InicializarColores();
	GenerarAjedrez();
}

