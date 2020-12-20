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

void Malla3D :: InicializarVBOColor (const Colores & color) noexcept
{
	if (vbo_colores[color] == 0)
		vbo_colores[color] = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			tablas_colores[color].data()
		);
}

void Malla3D :: CalcularNormales () noexcept
{
	Tupla3f vectorA;
	Tupla3f vectorB;
	Tupla3f perpendicular;
	Tupla3f normal;

	// para cada cara calculamos los vectores, si por ejemplo la cara esta formada
	// por los puntos p, q y r, A = q - p y B = r - p
	// tendremos una normal por cada vertice
	normales.resize(vertices.size());

	for (auto it = caras.cbegin(); it != caras.cend(); ++it)
	{
		vectorA = vertices[(*it)[Y]] - vertices[(*it)[X]];
		vectorB = vertices[(*it)[Z]] - vertices[(*it)[X]];

		// calculamos la permendicular haciendo el producto vectorial
		perpendicular = vectorA * vectorB;

		// lo normalizamos
		// si podemos, esto esta hecho asi para caso de la esfera
		// que repetimos lospuntos de los polos
		if ((perpendicular | perpendicular) > 0)
			normal = perpendicular.normalized();

		normales[(*it)[X]] = normales[(*it)[X]] + normal;
		normales[(*it)[Y]] = normales[(*it)[Y]] + normal;
		normales[(*it)[Z]] = normales[(*it)[Z]] + normal;
	}

	for (auto it = normales.begin(); it != normales.end(); ++it)
	{
		if ((*it | *it) > 0)
			(*it) = (*it).normalized();
	}
}

/** @fn void Malla3D :: DibujarDiferido (GLenum modo) noexcept
 *
 * @brief Dibuja el modelo en modo diferido.
 *
 * Permite dibujar más de una visualización del modelo a la vez, pero el modo
 * ajedrez siempre se muestra solo.
 */

void Malla3D :: DibujarDiferido (Colores color) noexcept
{
	InicializarVBOColor(color);

	if (vbo_caras == 0)
		vbo_caras = VBO(
			GL_ELEMENT_ARRAY_BUFFER,
			caras.size()*3*sizeof(uint32_t),
			caras.data()
		);

	if (vbo_vertices == 0)
		vbo_vertices = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			vertices.data()
		);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
		{
			glVertexPointer(3, GL_FLOAT, 0, 0);
		}
		glBindBuffer(GL_ARRAY_BUFFER,         vbo_colores[color]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras);
		{
			glColorPointer(3, GL_FLOAT, 0, 0);
			glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, 0);
		}
		glBindBuffer(GL_ARRAY_BUFFER,         0);
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

void Malla3D :: DibujarInmediato (Colores color) const noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	{
		glVertexPointer(3, GL_FLOAT, 0, vertices.data());
		 glColorPointer(3, GL_FLOAT, 0, tablas_colores[color].data());

		glDrawElements(
			GL_TRIANGLES,    caras.size()*3,
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

	InicializarVBOColor(Colores::Negro);
	InicializarVBOColor(Colores::Magenta);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	{
		glVertexPointer(3, GL_FLOAT, 0, vertices.data());

		glBindBuffer(GL_ARRAY_BUFFER,         vbo_colores[Colores::Negro]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras_ajedrez.first);
		{
			glColorPointer(3, GL_FLOAT, 0, 0);
			glDrawElements(GL_TRIANGLES, (caras.size()/2)*3, GL_UNSIGNED_INT, 0);
		}
		glBindBuffer(GL_ARRAY_BUFFER,         vbo_colores[Colores::Magenta]);
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

		glColorPointer(3, GL_FLOAT, 0, tablas_colores[Colores::Negro].data());
		glDrawElements(
			GL_TRIANGLES,    (caras.size()/2)*3,
			GL_UNSIGNED_INT, caras.data()
		);

		glColorPointer(3, GL_FLOAT, 0, tablas_colores[Colores::Magenta].data());
		glDrawElements(
			GL_TRIANGLES,    (caras.size()/2)*3,
			GL_UNSIGNED_INT, caras.data()+(caras.size()/2)
		);
	}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
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

void Malla3D :: InicializarColores () noexcept
{
	InicializarColor(tablas_colores[Colores::Azul],    coloresgl::AZUL);
	InicializarColor(tablas_colores[Colores::Magenta], coloresgl::MAGENTA);
	InicializarColor(tablas_colores[Colores::Negro],   coloresgl::NEGRO);
	InicializarColor(tablas_colores[Colores::Rojo],    coloresgl::ROJO);
	InicializarColor(tablas_colores[Colores::Verde],   coloresgl::VERDE);
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

Malla3D :: Malla3D ()
{ }

Malla3D :: Malla3D (const std::string & ruta)
{
	std::ifstream fi                      = PLY::Abrir(ruta);
	std::pair<size_t, size_t> dimensiones = PLY::LeerCabecera(fi);
	vertices                              = PLY::LeerVertices(fi, dimensiones.first);
	caras                                 = PLY::LeerCaras(fi, dimensiones.second);

	CalcularNormales();
}

void Malla3D :: AplicarMaterial (Material nuevo) noexcept
{
	material = nuevo;
}

/** @fn void Malla3D :: Dibujar (Dibujo modo) noexcept
 *
 * @brief Dibuja el modelo en el modo indicado.
 * @param modo Modo de envío del dibujo a la GPU.
 */

void Malla3D :: Dibujar (Dibujo dibujado, bool ajedrez, Colores color) noexcept
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
 * @brief Consulta el vértice indicada.
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
