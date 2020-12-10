/** @file malla.cpp
 */

#include "malla.hpp"

std::vector<tuplas::Tupla3f> Malla3D :: tablas_colores[5];

/** @fn inline GLuint Malla3D :: VBO (GLuint tipo, GLuint bytes, GLvoid * datos) const noexcept
 *
 * @brief Procesa y genera un VBO para una tabla de la malla.
 * @param tipo Tipo de búfer a procesar.
 * @param bytes Tamaño del búfer a procesar.
 * @param datos Puntero al búfer que procesar.
 * @return Identificador VBO del búfer procesado.
 */

inline GLuint Malla3D :: VBO (const GLuint & tipo, const GLuint & bytes,
	const GLvoid * datos) const noexcept
{
	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(tipo, vbo);
	glBufferData(tipo, bytes, datos, GL_STATIC_DRAW);
	glBindBuffer(tipo, 0);

	return vbo;
}

inline void Malla3D :: InicializarVBOColor (const VBOColores & color) noexcept
{
	if (vbo_colores[color] == 0)
		vbo_colores[color] = VBO(
			GL_ARRAY_BUFFER,
			vertices.size()*3*sizeof(float),
			tablas_colores[color].data()
		);
}

std::ifstream Malla3D :: AbrirFicheroPLY (const std::string & ruta)
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

void Malla3D :: InterpretarCabeceraPLY (std::ifstream & fi)
{
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

			if (std::regex_search(linea, std::regex("^ *element *face")))
				RedimensionarDesdePLY(linea, caras);

			if (std::regex_search(linea, std::regex("^ *element *vertex")))
				RedimensionarDesdePLY(linea, vertices);
		}
	}

	if (!cabecera_finalizada)
		throw std::runtime_error("Cabecera de PLY no finalizada.");

	if (fi.eof())
		throw std::runtime_error("PLY vacío tras su cabecera.");
}

void Malla3D :: InterpretarVerticesPLY (std::ifstream & fi) noexcept
{
	for (size_t i = 0; i < vertices.size(); i++)
	{
		fi >> vertices[i][0];
		fi >> vertices[i][1];
		fi >> vertices[i][2];
	}
}

void Malla3D :: InterpretarCarasPLY (std::ifstream & fi) noexcept
{
	for (size_t i = 0; i < caras.size(); i++)
	{
		fi >> caras[i][0];
		fi >> caras[i][0];
		fi >> caras[i][1];
		fi >> caras[i][2];
	}
}

template <class T>
inline void Malla3D :: RedimensionarDesdePLY (
	const std::string & linea,
	std::vector<T> & tabla
) noexcept
{
	std::smatch tamanio;
	std::regex_search(linea, tamanio, std::regex("[0-9]+ *$"));
	tabla.resize(std::stoi(tamanio[0]));
}

/** @fn inline void Malla3D :: DibujarDiferido () noexcept
 *
 * @brief Dibuja el modelo en modo diferido.
 *
 * Permite dibujar más de una visualización del modelo a la vez, pero el modo
 * ajedrez siempre se muestra solo.
 */

inline void Malla3D :: DibujarDiferido () noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

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

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	if (visualizacion.test(Visualizacion::Ajedrez))
		EnviarAjedrezDiferido();
	else
	{
		if (visualizacion.test(Visualizacion::Lineas))
		{
			glLineWidth(2);
			EnviarDibujoDiferido(GL_LINE, VBOColores::Verde);
			glLineWidth(1);
		}

		if (visualizacion.test(Visualizacion::Puntos))
			EnviarDibujoDiferido(GL_POINT, VBOColores::Azul);

		if (visualizacion.test(Visualizacion::Solido))
			EnviarDibujoDiferido(GL_FILL, VBOColores::Rojo);
	}

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/** @fn inline void Malla3D :: DibujarInmediato () noexcept
 *
 * @brief Dibuja el modelo en modo inmediato.
 *
 * Permite dibujar más de una visualización del modelo a la vez, pero el modo
 * ajedrez siempre se muestra solo.
 */

inline void Malla3D :: DibujarInmediato () const noexcept
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices.data());

	if (visualizacion.test(Visualizacion::Ajedrez))
		EnviarAjedrezInmediato();
	else
	{
		if (visualizacion.test(Visualizacion::Lineas))
		{
			glLineWidth(2);
			EnviarDibujoInmediato(GL_LINE, tablas_colores[VBOColores::Verde]);
			glLineWidth(1);
		}

		if (visualizacion.test(Visualizacion::Puntos))
			EnviarDibujoInmediato(GL_POINT, tablas_colores[VBOColores::Azul]);

		if (visualizacion.test(Visualizacion::Solido))
			EnviarDibujoInmediato(GL_FILL, tablas_colores[VBOColores::Rojo]);
	}

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/** @fn inline void Malla3D :: EnviarAjedrezDiferido () const noexcept
 *
 * @brief Envía a la GPU los datos de dibujo de la visualización en ajedrez del
 * modelo en modo diferido.
 */

inline void Malla3D :: EnviarAjedrezDiferido () noexcept
{
	glPolygonMode(GL_FRONT, GL_FILL);

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

	InicializarVBOColor(VBOColores::Negro);
	InicializarVBOColor(VBOColores::Magenta);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_colores[VBOColores::Negro]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras_ajedrez.first);

		glColorPointer(3, GL_FLOAT, 0, 0);
		glDrawElements(GL_TRIANGLES, (caras.size()/2)*3, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_colores[VBOColores::Magenta]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras_ajedrez.second);

		glColorPointer(3, GL_FLOAT, 0, 0);
		glDrawElements(GL_TRIANGLES, (caras.size()/2)*3, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/** @fn inline void Malla3D :: EnviarAjedrezInmediato () const noexcept
 *
 * @brief Envía a la GPU los datos de dibujo de la visualización en ajedrez del
 * modelo en modo inmediato.
 */

inline void Malla3D :: EnviarAjedrezInmediato () const noexcept
{
	glPolygonMode(GL_FRONT, GL_FILL);

	glColorPointer(3, GL_FLOAT, 0, tablas_colores[VBOColores::Negro].data());
	glDrawElements(
		GL_TRIANGLES, (caras.size()/2)*3,
		GL_UNSIGNED_INT, caras.data()
	);

	glColorPointer(3, GL_FLOAT, 0, tablas_colores[VBOColores::Magenta].data());
	glDrawElements(
		GL_TRIANGLES, (caras.size()/2)*3,
		GL_UNSIGNED_INT, caras.data()+(caras.size()/2)
	);
}

/** @fn inline void Malla3D :: EnviarDibujoDiferido (GLenum modo, GLuint color) const noexcept
 *
 * @brief Envía a la GPU los datos de dibujo de las visualizaciones del modelo
 * en modo diferido.
 * @param modo Modo de visualización del modelo.
 * @param color VBO del color con el que dibujar el modelo.
 */

inline void Malla3D :: EnviarDibujoDiferido (GLenum modo, VBOColores color) noexcept
{
	glPolygonMode(GL_FRONT, modo);

	InicializarVBOColor(color);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_colores[color]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_caras);

		glColorPointer(3, GL_FLOAT, 0, 0);
		glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/** @fn inline void Malla3D :: EnviarDibujoInmediato (GLenum modo, GLuint color) const noexcept
 *
 * @brief Envía a la GPU los datos de dibujo de las visualizaciones del modelo
 * en modo inmediato.
 * @param modo Modo de visualización del modelo.
 * @param color Tabla de colores con la que dibujar el modelo.
 */

inline void Malla3D :: EnviarDibujoInmediato (
	GLenum modo, std::vector<tuplas::Tupla3f> color) const noexcept
{
	glColorPointer(3, GL_FLOAT, 0, color.data());
	glPolygonMode(GL_FRONT, modo);
	glDrawElements(
		GL_TRIANGLES, caras.size()*3,
		GL_UNSIGNED_INT, caras.data()
	);
}

/** @fn void Malla3D :: InicializarColores (
 * 	tuplas::Tupla3f puntos,
 * 	tuplas::Tupla3f lineas,
 * 	tuplas::Tupla3f solido
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
	InicializarColor(tablas_colores[VBOColores::Azul],    coloresgl::AZUL);
	InicializarColor(tablas_colores[VBOColores::Magenta], coloresgl::MAGENTA);
	InicializarColor(tablas_colores[VBOColores::Negro],   coloresgl::NEGRO);
	InicializarColor(tablas_colores[VBOColores::Rojo],    coloresgl::ROJO);
	InicializarColor(tablas_colores[VBOColores::Verde],   coloresgl::VERDE);
}

inline void Malla3D :: InicializarColor (
	std::vector<tuplas::Tupla3f> & tabla,
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
	std::ifstream fi = AbrirFicheroPLY(ruta);

	InterpretarCabeceraPLY(fi);
	InterpretarVerticesPLY(fi);
	InterpretarCarasPLY(fi);
}

/** @fn void Malla3D :: Dibujar (Dibujo modo) noexcept
 *
 * @brief Dibuja el modelo en el modo indicado.
 * @param modo Modo de envío del dibujo a la GPU.
 */

void Malla3D :: Dibujar (Dibujo modo) noexcept
{
	switch (modo)
	{
		case Dibujo::Diferido:
			DibujarDiferido();
		break;

		case Dibujo::Inmediato:
			DibujarInmediato();
		break;
	}
}

/** @fn bool Malla3D :: Visualizar (Visualizacion vis) const noexcept
 *
 * @brief Consulta el estado del modo de visualización indicado.
 * @param vis Modo de visualización a consultar.
 * @return Estado de la bandera de visualización indicada.
 */

bool Malla3D :: EstadoVisualizacion (Visualizacion vis) const noexcept
{
	return visualizacion.test(vis);
}

/** @fn void Malla3D :: Visualizar (Visualizacion vis, Bitset operacion) noexcept
 *
 * @brief Modifica el estado del modo de visualización indicado.
 * @param vis Modo de visualización a modificar.
 * @param operacion Operación con la que modificar el modo de visualización.
 */

void Malla3D :: ModificarVisualizacion
	(Visualizacion vis, Bitset operacion) noexcept
{
	switch (operacion)
	{
		case Bitset::Flip:
			visualizacion.flip(vis);
		break;

		case Bitset::Reset:
			visualizacion.reset(vis);
		break;

		case Bitset::Set:
			visualizacion.set(vis);
		break;
	}
}

/** @fn tuplas::Tupla3i Malla3D :: Cara (const size_t indice) const
 *
 * @brief Consulta la cara indicada.
 * @param indice Índice de la cara a consultar en la tabla de caras.
 * @return Tupla con la cara consultada.
 * @exception std::out_of_range Intento de acceso a cara sobre el máximo.
 */

tuplas::Tupla3u Malla3D :: Cara (const size_t indice) const
{
	if (indice >= caras.size())
		throw std::out_of_range("Intento de acceso a cara sobre el máximo.");
	return caras[indice];
}

/** @fn std::vector<tuplas::Tupla3i> Malla3D :: Caras () const noexcept
 *
 * @brief Consulta la tabla de caras.
 * @return Tabla de caras del modelo.
 */

std::vector<tuplas::Tupla3u> Malla3D :: Caras () const noexcept
{
	return caras;
}

/** @fn std::string Malla3D :: Nombre () const noexcept
 *
 * @brief Consultor del nombre de la malla.
 * @return Nombre de la malla.
 */

std::string Malla3D :: Nombre () const noexcept
{
	return nombre;
}

/** @fn tuplas::Tupla3i Malla3D :: Vertice (const size_t indice) const
 *
 * @brief Consulta el vértice indicada.
 * @param indice Índice del vértice a consultar en la tabla de vértices.
 * @return Tupla con el vértice consultado.
 * @exception std::out_of_range Intento de acceso a vértice sobre el máximo.
 */

tuplas::Tupla3f Malla3D :: Vertice (const size_t indice) const
{
	if (indice >= vertices.size())
		throw std::out_of_range("Intento de acceso a vértice sobre el máximo.");
	return vertices[indice];
}

/** @fn std::vector<tuplas::Tupla3f> Malla3D :: Vertices () const noexcept
 *
 * @brief Consulta la tabla de vértices.
 * @return Tabla de vértices del modelo.
 */

std::vector<tuplas::Tupla3f> Malla3D :: Vertices () const noexcept
{
	return vertices;
}
