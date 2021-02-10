/** @file malla.cpp
 */

#include "malla.hpp"

std::vector<Tupla3f> Malla3D :: tablas_colores[COLORES];

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

void Malla3D :: CalcularCentro () noexcept
{
	for (size_t i = 0; i < vertices.size(); i++)
		centro = vertices[i] / vertices.size();
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

				if (textura != nullptr)
				{
					textura->Activar();
					glEnable(GL_TEXTURE_2D);
					glEnableClientState(GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer(2, GL_FLOAT, 0, coord_textura.data());
				}

			}
			glDisableClientState(GL_NORMAL_ARRAY);
		}
		else
		{
			InicializarVBOColor(color);
			glEnableClientState(GL_COLOR_ARRAY);

			glBindBuffer(GL_ARRAY_BUFFER, vbo_colores[color]);
			{
				glColorPointer(3, GL_FLOAT, 0, 0);
			}
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		EnviarDibujoDiferido();
	}
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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

		EnviarDibujoInmediato();
	}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Malla3D :: DibujarSeleccion (const Dibujo dibujado) noexcept
{
	if (color_seleccion.size() > 0)
	{
				// Para calcular los centros de los objetos
		GLfloat mat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, mat);

		Tupla3f n_centro;

		// aplicamos la transformacion de la matriz al punto
		n_centro[X] = mat[0] * centro[X] + mat[4] * centro[Y] + mat[8] * centro[Z] + mat[12];
		n_centro[Y] = mat[1] * centro[X] + mat[5] * centro[Y] + mat[9] * centro[Z] + mat[13];
		n_centro[Z] = mat[2] * centro[X] + mat[6] * centro[Y] + mat[10] * centro[Z] + mat[14];

		centro_perspectiva = n_centro;

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		{
			switch (dibujado)
			{
				case Dibujo::Diferido:
					if (vbo_color_seleccion == 0)
						vbo_color_seleccion = VBO(
							GL_ARRAY_BUFFER,
							vertices.size() * 3 * sizeof(float),
							color_seleccion.data()
						);


					glBindBuffer(GL_ARRAY_BUFFER, vbo_color_seleccion);
					{
						glColorPointer(3, GL_FLOAT, 0, 0);
					}
					glBindBuffer(GL_ARRAY_BUFFER, 0);

					EnviarDibujoDiferido();
				break;

				case Dibujo::Inmediato:
					glColorPointer(3, GL_FLOAT, 0, color_seleccion.data());
					EnviarDibujoInmediato();
				break;
			}
		}
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
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
			(caras.size() / 2) * 3 * sizeof(uint32_t),
			caras.data()
		);

	if (vbo_caras_ajedrez.second == 0)
		vbo_caras_ajedrez.second = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			(caras.size() / 2) * 3 * sizeof(uint32_t),
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

/**
 * @brief Llama a las funciones de dibujado en modo diferido.
 */

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
 * @brief Llama a las funciones de dibujado en modo inmediato.
 */

void Malla3D :: EnviarDibujoInmediato () const noexcept
{
	glVertexPointer(3, GL_FLOAT, 0, vertices.data());

	glDrawElements(
		GL_TRIANGLES,    caras.size() * 3,
		GL_UNSIGNED_INT, caras.data()
	);
}

/**
 * @brief LLama a todas las funciones de inicialización de la malla y actúa como
 * interfaz de éstas para clases descendientes.
 */

void Malla3D :: InicializarMalla () noexcept
{
	GenerarAjedrez();
	CalcularCentro();
	CalcularNormales();
	InicializarColores();
}

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

void Malla3D :: AplicarTextura (Textura * nueva, const bool calcular) noexcept
{
	textura = nueva;
	coord_textura.resize(vertices.size());

	if (calcular)
	{
		for (size_t i = 0; i < coord_textura.size(); i++)
		{
			coord_textura[i] = {
				vertices[i][X],
				(vertices[i][Y] - vertices.front()[Y])
					/
				(vertices.back()[Y] - vertices.front()[Y])
			};
		}
	}
}

void Malla3D :: Invertir () noexcept
{
	uint32_t intercambia;

	for (size_t i = 0; i < caras.size(); i++)
	{
		intercambia = caras[i][Y];
		caras[i][Y] = caras[i][Z];
		caras[i][Z] = intercambia;
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
	const unsigned char color,
	const bool seleccion
) noexcept
{
	if (seleccion)
	{
		DibujarSeleccion(dibujado);
	}
	else
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
}

void Malla3D :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	color_seleccion.resize(vertices.size());

	for (size_t i = 0; i < vertices.size(); i++)
		color_seleccion[i] = color;
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

Tupla3f Malla3D :: Centro () const noexcept
{
	return centro_perspectiva;
}

Tupla3f Malla3D :: ColorSeleccion () const noexcept
{
	if (color_seleccion.size() > 0)
		return color_seleccion[0];
	else
		return {0, 0, 0};
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
