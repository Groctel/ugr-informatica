#include "cubo.hpp"

inline void Cubo :: InicializarCaras () noexcept
{
	caras.resize(12);

	caras[0]  = {6, 4, 2};
	caras[1]  = {0, 2, 4};

	caras[2]  = {2, 0, 3};
	caras[3]  = {1, 3, 0};

	caras[4]  = {3, 1, 7};
	caras[5]  = {5, 7, 1};

	caras[6]  = {7, 5, 6};
	caras[7]  = {4, 6, 5};

	caras[8]  = {2, 3, 6};
	caras[9]  = {7, 6, 3};

	caras[10] = {1, 0, 5};
	caras[11] = {4, 5, 0};
}

inline void Cubo :: InicializarColores () noexcept
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

inline void Cubo :: InicializarVertices (const float escala) noexcept
{
	vertices.resize(8);

	for (size_t  i=0; i<vertices.size(); i++)
	{
		vertices[i] = {
			(float) (escala * ((i/4%2)?1:-1)),
			(float) (escala * ((i/2%2)?1:-1)),
			(float) (escala * ((i%2)?1:-1))
		};
	}
}

Cubo :: Cubo (const float escala)
{
	InicializarVertices(escala);
	InicializarCaras();
	InicializarColores();
	GenerarAjedrez();
}

