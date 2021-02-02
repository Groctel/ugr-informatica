/** @file malla.cpp
 */

#include "malla.hpp"

std::vector<Tupla3f> Malla3D :: tablas_colores[5];

/**
 * @brief Procesa y genera un VBO para una tabla de la malla.
 * @param tipo Tipo de búfer a procesar.
 * @param bytes Tamaño del búfer a procesar.
 * @param datos Puntero al búfer que procesar.
 * @return Identificador VBO del búfer procesado.
 */

GLuint Malla3D :: VBO (const GLuint & tipo, const GLuint & bytes,
	const GLvoid * datos) const noexcept
{
	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(tipo, vbo);
	glBufferData(tipo, bytes, datos, GL_STATIC_DRAW);
	glBindBuffer(tipo, 0);

	return vbo;
}

/**
 * @brief Carga un color en la tabla de colores.
 * @param tabla Tabla de colores a modificar.
 * @param color Color a cargar en la tabla.
 */

void Malla3D :: InicializarColor (
	std::vector<Tupla3f> & tabla,
	const RGB & color
) noexcept
{
	if (vertices.size() > tabla.size())
	{
		size_t tamanio_original = tabla.size();

		tabla.resize(vertices.size());

		for (size_t i = tamanio_original; i < tabla.size(); i++)
			tabla[i] = color;
	}
}

/**
 * @brief Modifica el orden de las caras para la visualización en ajedrez.
 */

void Malla3D :: GenerarAjedrez () noexcept
{
	Tupla3u intercambia;

	for (size_t i = 0; i < caras.size()/2; i+=2)
	{
		intercambia             = caras[i];
		caras[i]                = caras[caras.size()-i-1];
		caras[caras.size()-i-1] = intercambia;
	}
}

/**
 * @brief Inicializa todos los colores mediante llamadas a InicializarColor.
 */

void Malla3D :: InicializarColores () noexcept
{
	InicializarColor(tablas_colores[azul],    RGBAzul);
	InicializarColor(tablas_colores[magenta], RGBMagenta);
	InicializarColor(tablas_colores[negro],   RGBNegro);
	InicializarColor(tablas_colores[rojo],    RGBRojo);
	InicializarColor(tablas_colores[verde],   RGBVerde);
}

/**
 * @brief Rellena el vector de normales con la correspondiente a cada vértice.
 */

void Malla3D :: CalcularNormales () noexcept
{
	Tupla3f normal_cara;

	normales.resize(vertices.size());

	for (auto it = normales.begin(); it != normales.end(); ++it)
		*it = {0,0,0};

	for (auto it = caras.cbegin(); it != caras.cend(); ++it)
	{
		normal_cara = (
			(Tupla3f) (vertices[(*it)[1]] - vertices[(*it)[0]])
			*
			(Tupla3f) (vertices[(*it)[2]] - vertices[(*it)[0]])
		);

		normales[(*it)[X]] = normales[(*it)[X]] + normal_cara;
		normales[(*it)[Y]] = normales[(*it)[Y]] + normal_cara;
		normales[(*it)[Z]] = normales[(*it)[Z]] + normal_cara;
	}

	for (auto it = normales.begin(); it != normales.end(); ++it)
		*it = it->Normalise();
}

/**
 * @brief Inicializa el vbo de un color utilizado por la malla.
 * @param color Índice del color a inicializar.
 */

void Malla3D :: InicializarVBOColor (const unsigned char color) noexcept
{
	if (vbo_colores[color] == 0)
		vbo_colores[color] = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			tablas_colores[color].data()
		);
}

/**
 * @brief Dibuja el modelo en modo diferido.
 *
 * Permite dibujar más de una visualización del modelo a la vez, pero el modo
 * ajedrez siempre se muestra solo.
 */

void Malla3D :: DibujarDiferido (const unsigned char color) noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	{
		if (glIsEnabled(GL_LIGHTING))
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			{
				if (vbo_normales == 0)
					vbo_normales = VBO(
						GL_ARRAY_BUFFER,
						normales.size()*3*sizeof(float),
						normales.data()
					);

				glBindBuffer(GL_ARRAY_BUFFER, vbo_normales);
				{
					glNormalPointer(GL_FLOAT, 0, 0);
				}
				glBindBuffer(GL_ARRAY_BUFFER, 0);

				material->Aplicar();
			}
			glDisableClientState(GL_NORMAL_ARRAY);
		}
		else
		{
			glEnableClientState(GL_COLOR_ARRAY);
			{
				InicializarVBOColor(color);

				glBindBuffer(GL_ARRAY_BUFFER, vbo_colores[color]);
				{
					glColorPointer(3, GL_FLOAT, 0, 0);
				}
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}
		}

		EnviarDibujoDiferido();
	}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/**
 * @brief Dibuja el modelo en modo inmediato.
 *
 * Permite dibujar más de una visualización del modelo a la vez, pero el modo
 * ajedrez siempre se muestra solo.
 */

void Malla3D :: DibujarInmediato (const unsigned char color) noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	{
		if (glIsEnabled(GL_LIGHTING))
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			{
				glNormalPointer(GL_FLOAT, 0, normales.data());
				material->Aplicar();

				if (textura != nullptr)
				{
					textura->Activar();

					glEnableClientState(GL_TEXTURE_COORD_ARRAY);
					{
						glTexCoordPointer(2, GL_FLOAT, 0, coord_textura.data());
					}
					glDisableClientState(GL_TEXTURE_COORD_ARRAY);
				}
			}
			glDisableClientState(GL_NORMAL_ARRAY);
		}
		else
		{
			glEnableClientState(GL_COLOR_ARRAY);
				glColorPointer(3, GL_FLOAT, 0, tablas_colores[color].data());
		}

		glVertexPointer(3, GL_FLOAT, 0, vertices.data());

		glDrawElements(
			GL_TRIANGLES,    caras.size() * 3,
			GL_UNSIGNED_INT, caras.data()
		);
	}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/**
 * @brief Envía a la GPU los datos de dibujo de la visualización en ajedrez del
 * modelo en modo diferido.
 */

void Malla3D :: DibujarAjedrezDiferido () noexcept
{
	if (vbo_caras_ajedrez.first == 0)
		vbo_caras_ajedrez.first = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			(caras.size()/2)*3*sizeof(int),
			caras.data()
		);

	if (vbo_caras_ajedrez.second == 0)
		vbo_caras_ajedrez.second = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			(caras.size()/2)*3*sizeof(int),
			caras.data()+caras.size()/2
		);

	InicializarVBOColor(negro);
	InicializarVBOColor(magenta);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	{
		glVertexPointer(3, GL_FLOAT, 0, vertices.data());

		glBindBuffer(GL_ARRAY_BUFFER,         vbo_colores[negro]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras_ajedrez.first);
		{
			glColorPointer(3, GL_FLOAT, 0, 0);
			glDrawElements(GL_TRIANGLES, (caras.size()/2)*3, GL_UNSIGNED_INT, 0);
		}
		glBindBuffer(GL_ARRAY_BUFFER,         vbo_colores[magenta]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras_ajedrez.second);
		{
			glColorPointer(3, GL_FLOAT, 0, 0);
			glDrawElements(GL_TRIANGLES, (caras.size()/2)*3, GL_UNSIGNED_INT, 0);
		}
		glBindBuffer(GL_ARRAY_BUFFER,         0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/**
 * @brief Envía a la GPU los datos de dibujo de la visualización en ajedrez del
 * modelo en modo inmediato.
 */

void Malla3D :: DibujarAjedrezInmediato () const noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	{
		glVertexPointer(3, GL_FLOAT, 0, vertices.data());

		glColorPointer(3, GL_FLOAT, 0, tablas_colores[negro].data());
		glDrawElements(
			GL_TRIANGLES,    (caras.size()/2)*3,
			GL_UNSIGNED_INT, caras.data()
		);

		glColorPointer(3, GL_FLOAT, 0, tablas_colores[magenta].data());
		glDrawElements(
			GL_TRIANGLES,    (caras.size()/2)*3,
			GL_UNSIGNED_INT, caras.data()+(caras.size()/2)
		);
	}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Malla3D :: EnviarDibujoDiferido () noexcept
{
	if (vbo_vertices == 0)
		vbo_vertices = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			vertices.data()
		);

	if (vbo_caras == 0)
		vbo_caras = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			caras.size()*3*sizeof(uint32_t),
			caras.data()
		);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	{
		glVertexPointer(3, GL_FLOAT, 0, 0);
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras);
	{
		glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, 0);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/**
 * @brief LLama a todas las funciones de inicialización de la malla y actúa como
 * interfaz de éstas para clases descendientes.
 */

void Malla3D :: InicializarMalla () noexcept
{
	GenerarAjedrez();
	CalcularNormales();
	InicializarColores();
}

/**
 * @brief Inicializa la textura asignada a la malla
 */

void Malla3D :: InicializarTextura () noexcept
{ }

/**
 * @brief Constructor por defecto vacío necesario para las clases descendientes.
 */

Malla3D :: Malla3D () noexcept
{ }

Malla3D :: ~Malla3D () noexcept
{ }

/**
 * @brief Asigna un nuevo material a la malla.
 */

void Malla3D :: AplicarMaterial (Material * nuevo) noexcept
{
	material = nuevo;
}

/**
 * @brief Asigna una nueva textura a la malla y rellena el vector de coordenadas
 * de la misma.
 */

void Malla3D :: AplicarTextura (Textura * nueva) noexcept
{
	textura = nueva;
	coord_textura.resize(vertices.size());

	for (size_t i = 0; i < coord_textura.size(); i++)
	{
		coord_textura[i] = {
			vertices[i][X],
			(vertices[i][Y] - vertices[0][Y])
				/
			(vertices[vertices.size()][Y] - vertices[0][Y])
		};
	}
}

/**
 * @brief Dibuja el modelo en el modo indicado.
 * @param dibujado Modo de envío del dibujo a la GPU.
 * @param ajedrez Condición de dibujado en modo ajedrez.
 * @param color Color con el que dibujar la malla.
 */

void Malla3D :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color
) noexcept
{
	switch (dibujado)
	{
		case Dibujo::Diferido:
			if (ajedrez)
				DibujarAjedrezDiferido();
			else
				DibujarDiferido(color);
		break;

		case Dibujo::Inmediato:
			if (ajedrez)
				DibujarAjedrezInmediato();
			else
				DibujarInmediato(color);
		break;
	}
}

/**
 * @brief Consulta la cara indicada.
 * @param indice Índice de la cara a consultar en la tabla de caras.
 */

Tupla3u Malla3D :: Cara (const size_t indice) const
{
	if (indice >= caras.size())
		throw std::out_of_range("Intento de acceso a cara sobre el máximo.");
	return caras[indice];
}

/**
 * @brief Consulta la tabla de caras.
 */

std::vector<Tupla3u> Malla3D :: Caras () const noexcept
{
	return caras;
}

/**
 * @brief Consulta el vértice indicado.
 * @param indice Índice del vértice a consultar en la tabla de vértices.
 */

Tupla3f Malla3D :: Vertice (const size_t indice) const
{
	if (indice >= vertices.size())
		throw std::out_of_range("Intento de acceso a vértice sobre el máximo.");
	return vertices[indice];
}

/**
 * @brief Consulta la tabla de vértices.
 */

std::vector<Tupla3f> Malla3D :: Vertices () const noexcept
{
	return vertices;
}

/**
 * @brief Consulta la normal indicada.
 * @param indice Índice de la normal a consultar en la tabla de normales.
 */

Tupla3f Malla3D :: Normal (const size_t indice) const
{
	if (indice >= normales.size())
		throw std::out_of_range("Intento de acceso a normal sobre el máximo.");
	return normales[indice];
}

/**
 * @brief Consulta la tabla de normales.
 */

std::vector<Tupla3f> Malla3D :: Normales () const noexcept
{
	return normales;
}
