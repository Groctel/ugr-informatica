/** @file malla.cpp
 */

#include "malla.hpp"

std::vector<Tupla3f> Malla3D :: tablas_colores[5];

/** @fn GLuint Malla3D :: VBO (GLuint tipo, GLuint bytes, GLvoid * datos) const noexcept
 *
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

void Malla3D :: InicializarColor (
	std::vector<Tupla3f> & tabla,
	const coloresgl::color & color
) noexcept
{
	size_t indice_vacio = tabla.size();

	if (vertices.size() > tabla.size())
		tabla.resize(vertices.size());

	for (; indice_vacio < tabla.size(); indice_vacio++)
		tabla[indice_vacio] = color;
}

void Malla3D :: GenerarAjedrez () noexcept
{
	for (size_t i = 0; i < caras.size()/2; i+=2)
		std::swap(caras[i], caras[caras.size()-i-1]);
}

void Malla3D :: InicializarColores () noexcept
{
	InicializarColor(tablas_colores[azul],    coloresgl::AZUL);
	InicializarColor(tablas_colores[magenta], coloresgl::MAGENTA);
	InicializarColor(tablas_colores[negro],   coloresgl::NEGRO);
	InicializarColor(tablas_colores[rojo],    coloresgl::ROJO);
	InicializarColor(tablas_colores[verde],   coloresgl::VERDE);
}

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

void Malla3D :: InicializarVBOColor (const unsigned char color) noexcept
{
	if (vbo_colores[color] == 0)
		vbo_colores[color] = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			tablas_colores[color].data()
		);
}

/** @fn void Malla3D :: DibujarDiferido (GLenum modo) noexcept
 *
 * @brief Dibuja el modelo en modo diferido.
 *
 * Permite dibujar más de una visualización del modelo a la vez, pero el modo
 * ajedrez siempre se muestra solo.
 */

void Malla3D :: DibujarDiferido (const unsigned char color) noexcept
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
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/** @fn void Malla3D :: DibujarInmediato (GLenum modo) noexcept
 *
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

/** @fn void Malla3D :: EnviarAjedrezDiferido () const noexcept
 *
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

/** @fn void Malla3D :: EnviarAjedrezInmediato () const noexcept
 *
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

void Malla3D :: InicializarMalla () noexcept
{
	GenerarAjedrez();
	CalcularNormales();
	InicializarColores();
}

/** @fn void Malla3D :: InicializarColores (
 * 	Tupla3f puntos,
 * 	Tupla3f lineas,
 * 	Tupla3f solido
 * ) noexcept
 *
 * @brief Crea las tablas de colores
 * @param puntos Color de los puntos
 * @param lineas Color de las líneas
 * @param solido Color de las caras sólidas
 *
 * La tabla creada tiene tantos elementos como vértices tenga la malla,
 * asignando por defecto el color azul a los puntos, el verde a las líneas y el
 * rojo a las caras pintadas en modo sólido.
 */

Malla3D :: Malla3D ()
{ }

Malla3D :: Malla3D (const std::string & ruta)
{
	std::ifstream fi                      = PLY::Abrir(ruta);
	std::pair<size_t, size_t> dimensiones = PLY::LeerCabecera(fi);
	vertices                              = PLY::LeerVertices(fi, dimensiones.first);
	caras                                 = PLY::LeerCaras(fi, dimensiones.second);

	InicializarMalla();
}

void Malla3D :: AplicarMaterial (Material * nuevo) noexcept
{
	material = nuevo;
}

/** @fn void Malla3D :: Dibujar (Dibujo modo) noexcept
 *
 * @brief Dibuja el modelo en el modo indicado.
 * @param modo Modo de envío del dibujo a la GPU.
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

/** @fn Tupla3i Malla3D :: Cara (const size_t indice) const
 *
 * @brief Consulta la cara indicada.
 * @param indice Índice de la cara a consultar en la tabla de caras.
 * @return Tupla con la cara consultada.
 * @exception std::out_of_range Intento de acceso a cara sobre el máximo.
 */

Tupla3u Malla3D :: Cara (const size_t indice) const
{
	if (indice >= caras.size())
		throw std::out_of_range("Intento de acceso a cara sobre el máximo.");
	return caras[indice];
}

/** @fn std::vector<Tupla3i> Malla3D :: Caras () const noexcept
 *
 * @brief Consulta la tabla de caras.
 * @return Tabla de caras del modelo.
 */

std::vector<Tupla3u> Malla3D :: Caras () const noexcept
{
	return caras;
}

/** @fn Tupla3i Malla3D :: Vertice (const size_t indice) const
 *
 * @brief Consulta el vértice indicado.
 * @param indice Índice del vértice a consultar en la tabla de vértices.
 * @return Tupla con el vértice consultado.
 * @exception std::out_of_range Intento de acceso a vértice sobre el máximo.
 */

Tupla3f Malla3D :: Vertice (const size_t indice) const
{
	if (indice >= vertices.size())
		throw std::out_of_range("Intento de acceso a vértice sobre el máximo.");
	return vertices[indice];
}

/** @fn std::vector<Tupla3f> Malla3D :: Vertices () const noexcept
 *
 * @brief Consulta la tabla de vértices.
 * @return Tabla de vértices del modelo.
 */

std::vector<Tupla3f> Malla3D :: Vertices () const noexcept
{
	return vertices;
}

/** @fn Tupla3i Malla3D :: Normal (const size_t indice) const
 *
 * @brief Consulta la normal indicada.
 * @param indice Índice de la normal a consultar en la tabla de normales.
 * @return Tupla con la normal consultada.
 * @exception std::out_of_range Intento de acceso a noemal sobre el máximo.
 */

Tupla3f Malla3D :: Normal (const size_t indice) const
{
	if (indice >= normales.size())
		throw std::out_of_range("Intento de acceso a normal sobre el máximo.");
	return normales[indice];
}

/** @fn std::vector<Tupla3f> Malla3D :: Normales () const noexcept
 *
 * @brief Consulta la tabla de normales.
 * @return Tabla de normales del modelo.
 */

std::vector<Tupla3f> Malla3D :: Normales () const noexcept
{
	return normales;
}
