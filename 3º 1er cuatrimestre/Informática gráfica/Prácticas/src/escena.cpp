/** @file escena.cpp
 */

#include "escena.hpp"

Escena * Escena :: instance = nullptr;

/** @fn Escena :: Escena () noexcept
 *
 * @brief Constructor por defectpor defecto.
 *
 * Inicializa todos los elementos de la escena.
 */

Escena :: Escena () noexcept
:
	plano_delantero     (50.0),
	plano_trasero       (2000.0),
	angulo_observador_x (0.0),
	angulo_observador_y (0.0),

	cilindro  (Cilindro(1, 5, 20, 30)),
	cono      (Cono(1, 5, 20, 30)),
	cubo      (Cubo(30)),
	esfera    (Esfera(1, 20)),
	tetraedro (Tetraedro(30)),
	peon      (ObjRevolucion("plys/peon.ply", 20, Tapas::Ambas))
{
	distancia_observador = 4 * plano_delantero,
	ejes.NuevoTamanio(5000);
}

/** @fn void Escena :: CambiarProyeccion (const float ratio_xy) noexcept
 *
 * @brief Modifica el punto de visión de la escena.
 * @param ratio_xy Factor de modificación del eje x.
 */

void Escena :: CambiarProyeccion (const float ratio_xy) noexcept
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	const float wx = altura * ratio_xy;

	glFrustum(-wx, wx, -altura, altura, plano_delantero, plano_trasero);
}

/** @fn void Escena :: CambiarObservador () noexcept
 *
 * @brief Modifica la posición del observador de la escena.
 */

void Escena :: CambiarObservador () noexcept
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -distancia_observador);
	glRotatef(angulo_observador_y, 0.0 ,1.0, 0.0);
	glRotatef(angulo_observador_x, 1.0, 0.0, 0.0);
}

/** @fn inline void Escena :: SeleccionDibujado (unsigned char tecla) noexcept
 *
 * @brief Seleccionador de modo de dibujo.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Alterna entre el modo de dibujo inmediato y diferido.
 */

inline void Escena :: SeleccionDibujado (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (toupper(tecla))
	{
		case 'D':
			dibujo = Dibujo::Diferido;
		break;

		case 'I':
			dibujo = Dibujo::Inmediato;
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionDibujado(true);
}

/** @fn inline void Escena :: SeleccionMenu (unsigned char tecla) noexcept
 *
 * @brief Seleccionador del submenú de la escena.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Cambia el menú al seleccionado por el usuario.
 */

inline void Escena :: SeleccionMenu (unsigned char tecla) noexcept
{
	switch (toupper(tecla))
	{
		case 'D':
			menu = Menu::SeleccionDibujado;
			MsgSeleccionDibujado();
		break;

		case 'O':
			menu = Menu::SeleccionObjeto;
			MsgSeleccionObjeto();
		break;

		case 'V':
			menu = Menu::SeleccionVisualizacion;
			MsgSeleccionVisualizacion();
		break;

		default:
			TeclasComunes(tecla);
		break;
	}
}

/** @fn inline void Escena :: SeleccionObjeto (unsigned char tecla) noexcept
 *
 * @brief Seleccionador del objeto con el que interactuar.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Alterna la muestra del objeto seleccionado.
 */

inline void Escena :: SeleccionObjeto (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (std::toupper(tecla))
	{
		case 'I':
			visibles.flip(obj_cilindro);
		break;

		case 'O':
			visibles.flip(obj_cono);
		break;

		case 'U':
			visibles.flip(obj_cubo);
		break;

		case 'E':
			visibles.flip(obj_esfera);
		break;

		case 'T':
			visibles.flip(obj_tetraedro);
		break;

		case 'P':
			visibles.flip(obj_peon);
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionObjeto(true);
}

/** @fn inline void Escena :: SeleccionVisualizacion (unsigned char tecla) noexcept
 *
 * @brief Seleccionador de la visualización de los objetos visibles.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Alterna los diferentes modos de visualización para los objetos visibles.
 */

inline void Escena :: SeleccionVisualizacion (unsigned char tecla) noexcept
{
	switch (toupper(tecla))
	{
		case 'A':
			Visualizar(Visualizacion::Ajedrez);
		break;

		case 'L':
			Visualizar(Visualizacion::Lineas);
		break;

		case 'P':
			Visualizar(Visualizacion::Puntos);
		break;

		case 'S':
			Visualizar(Visualizacion::Solido);
		break;

		default:
			TeclasComunes(tecla);
		break;
	}
}

/** @fn inline void Escena :: TeclasComunes (unsigned char tecla) noexcept
 *
 * @brief Gestor de teclas pulsables en todos los menús.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Cierra los submenús para salir al menú principal o finaliza la ejecución del
 * programa si el menú actual es el principal.
 */

inline void Escena :: TeclasComunes (unsigned char tecla) noexcept
{
	switch (toupper(tecla))
	{
		case 'Q':
			if (menu != Menu::Inactivo)
			{
				menu = Menu::Inactivo;
				MsgSeleccionMenu();
			}
			else {
				activa = false;
				std::cout  << "Finalizando ejecución del programa..." << std::endl;
			}
		break;
	}
}

/** @fn inline void Escena :: MsgSeleccionDibujado (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de dibujado.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

inline void Escena :: MsgSeleccionDibujado (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[4A";

	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE DIBUJADO:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "D"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (dibujo == Dibujo::Diferido ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Modo diferido" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "I"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (dibujo == Dibujo::Inmediato ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Modo inmediato" << coloresterm::NORMAL << std::endl;

	MsgTeclasComunes();
}

/** @fn inline void Escena :: MsgSeleccionMenu (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de submenús.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

inline void Escena :: MsgSeleccionMenu () const noexcept
{
	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE MENÚ:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "D"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de dibujado" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "O"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de objeto" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "V"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de visualización" << coloresterm::NORMAL << std::endl;

	MsgTeclasComunes();
}

/** @fn inline void Escena :: MsgSeleccionObjeto (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de objetos.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

inline void Escena :: MsgSeleccionObjeto (bool reescribir) noexcept
{
	if (reescribir)
		std::cout << "\033[" << 7 << "A";

	std::cout
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "I"
		<< coloresterm::CIAN_B << "] "
		<< coloresterm::NORMAL
		<< (visibles.test(obj_cilindro) ? coloresterm::VERDE : coloresterm::ROJO)
		<< "Cilindro"
		<< coloresterm::NORMAL << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "O"
		<< coloresterm::CIAN_B << "] "
		<< coloresterm::NORMAL
		<< (visibles.test(obj_cono) ? coloresterm::VERDE : coloresterm::ROJO)
		<< "Cono"
		<< coloresterm::NORMAL << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "U"
		<< coloresterm::CIAN_B << "] "
		<< coloresterm::NORMAL
		<< (visibles.test(obj_cubo) ? coloresterm::VERDE : coloresterm::ROJO)
		<< "Cubo"
		<< coloresterm::NORMAL << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "E"
		<< coloresterm::CIAN_B << "] "
		<< coloresterm::NORMAL
		<< (visibles.test(obj_esfera) ? coloresterm::VERDE : coloresterm::ROJO)
		<< "Esfera"
		<< coloresterm::NORMAL << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "T"
		<< coloresterm::CIAN_B << "] "
		<< coloresterm::NORMAL
		<< (visibles.test(obj_tetraedro) ? coloresterm::VERDE : coloresterm::ROJO)
		<< "Tetraedro"
		<< coloresterm::NORMAL << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "P"
		<< coloresterm::CIAN_B << "] "
		<< coloresterm::NORMAL
		<< (visibles.test(obj_peon) ? coloresterm::VERDE : coloresterm::ROJO)
		<< "Peon"
		<< coloresterm::NORMAL << std::endl;

	MsgTeclasComunes();
}

/** @fn inline void Escena :: MsgSeleccionVisualizacion (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de modos de visualización.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

inline void Escena :: MsgSeleccionVisualizacion (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[5A";

	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE VISUALIZACIÓN:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "A"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< coloresterm::AMARILLO << " Modo ajedrez" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "L"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< coloresterm::AMARILLO << " Modo líneas" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "P"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< coloresterm::AMARILLO << " Modo puntos" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "S"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< coloresterm::AMARILLO << " Modo sólido" << coloresterm::NORMAL
		<< std::endl;

	MsgTeclasComunes();
}

/** @fn inline void Escena :: MsgTeclasComunes () const noexcept
 *
 * @brief Muestra el texto de las teclas comunes a todos los menús.
 */

inline void Escena :: MsgTeclasComunes () const noexcept
{
	std::cout
		<< coloresterm::AZUL_B << "[" << coloresterm::ROJO_B << "Q"
		<< coloresterm::AZUL_B << "]" << coloresterm::NORMAL
		<< ((menu == Menu::Inactivo) ? " Finalizar ejecución del programa"
			: " Volver a la selección de menú") << std::endl;
}

/** @fn inline void Escena :: Visualizar (Visualizacion visualizacion) noexcept
 *
 * @brief Modifica los modos de visualización de los objetos visibles.
 * @param visualizacion Modo de visualización a modificar.
 */

inline void Escena :: Visualizar (Visualizacion visualizacion) noexcept
{
	cilindro.ModificarVisualizacion(visualizacion);
	cono.ModificarVisualizacion(visualizacion);
	cubo.ModificarVisualizacion(visualizacion);
	esfera.ModificarVisualizacion(visualizacion);
	tetraedro.ModificarVisualizacion(visualizacion);
	peon.ModificarVisualizacion(visualizacion);
}

/** @fn Escena * Escena :: Instance () noexcept
 *
 * @brief Instanciador para cumplir con el patrón Singleton.
 */

Escena * Escena :: Instance () noexcept
{
	if (instance == nullptr)
		instance = new Escena;

	return instance;
}

/** @fn Escena :: ~Escena () noexcept
 *
 * @brief Destructor por defecto.
 *
 * Libera todos los objetos creados y almacenados en memoria.
 */

Escena :: ~Escena () noexcept
{
	instance = nullptr;
	exit(0);
}

/** @fn void Escena :: Inicializar (int anchura_ventana, int altura_ventana) noexcept
 *
 * @brief Inicializa los aspectos de dibujo de la escena.
 * @param anchura_ventana Anchura de la ventana en la que se muestra la escena.
 * @param altura_ventana Altura de la ventana en la que se muestra la escena.
 *
 * Llama a las funciones de OpenGL correspondientes para inicializar el motor
 * con los parámetros deseados.
 */

void Escena :: Inicializar (int anchura_ventana, int altura_ventana) noexcept
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glPointSize(5);

	anchura = anchura_ventana / 10;
	altura  = altura_ventana  / 10;

	CambiarProyeccion((float) anchura_ventana / (float) altura_ventana);
	glViewport(0, 0, anchura_ventana, altura_ventana);

	MsgSeleccionMenu();
}

/** @fn void Escena :: Dibujar () noexcept
 *
 * @brief Llama a las funciones de dibujo de cada uno de los objetos visibles.
 */

void Escena :: Dibujar () noexcept
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	CambiarObservador();
	ejes.Dibujar();

	if (visibles.test(obj_cilindro))
	{
		glPushMatrix();
		{
			glTranslatef(-60, 0, -60);
			glScalef(30, 30, 30);
			cilindro.Dibujar(dibujo);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cono))
	{
		glPushMatrix();
		{
			glTranslatef(60, 0, -60);
			glScalef(30, 30, 30);
			cono.Dibujar(dibujo);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cubo))
	{
		glPushMatrix();
		{
			glTranslatef(-60, 0, 60);
			cubo.Dibujar(dibujo);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_esfera))
	{
		glPushMatrix();
		{
			glTranslatef(0, -60, 0);
			glScalef(30, 30, 30);
			esfera.Dibujar(dibujo);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_tetraedro))
	{
		glPushMatrix();
		{
			glTranslatef(0, 60, 0);
			tetraedro.Dibujar(dibujo);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_peon))
	{
		glPushMatrix();
		{
			glTranslatef(60, 0, 60);
			glScalef(30, 30, 30);
			peon.Dibujar(dibujo);
		}
		glPopMatrix();
	}
}

/** @fn void Escena :: Redimensionar (int nueva_anchura, int nueva_altura) noexcept
 *
 * @brief Redimensiona la escena a nuevos valores.
 * @param nueva_anchura Nueva anchura de la escena.
 * @param nueva_altura Nueva altura de la escena.
 */

void Escena :: Redimensionar (int nueva_anchura, int nueva_altura) noexcept
{
	anchura = nueva_anchura / 10;
	altura  = nueva_altura  / 10;

	CambiarProyeccion((float) nueva_altura / (float) nueva_anchura);
	glViewport(0, 0, nueva_anchura, nueva_altura);
}

/** @fn bool Escena :: GestionTeclado (unsigned char tecla, int x, int y) noexcept
 *
 * @brief Llama a las funciones adecuadas según la tecla pulsada.
 * @param tecla Tecla pulsada por el usuario.
 * @param x Parámetro no utilizado de glut.
 * @param y Parámetro no utilizado de glut.
 */

bool Escena :: GestionTeclado (unsigned char tecla, int x, int y) noexcept
{
	switch (menu)
	{
		case Menu::Inactivo:
			SeleccionMenu(tecla);
		break;

		case Menu::SeleccionDibujado:
			SeleccionDibujado(tecla);
		break;

		case Menu::SeleccionObjeto:
			SeleccionObjeto(tecla);
		break;

		case Menu::SeleccionVisualizacion:
			SeleccionVisualizacion(tecla);
		break;
	}

	return activa;
}

/** @fn bool Escena :: GestionTecladoEspecial (unsigned char tecla, int x, int y) noexcept
 *
 * @brief Llama a las funciones adecuadas según la tecla pulsada.
 * @param tecla Tecla pulsada por el usuario.
 * @param x Parámetro no utilizado de glut.
 * @param y Parámetro no utilizado de glut.
 */

void Escena :: GestionTecladoEspecial (int tecla, int x, int y) noexcept
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT:
			angulo_observador_y--;
		break;

		case GLUT_KEY_RIGHT:
			angulo_observador_y++;
		break;

		case GLUT_KEY_UP:
			angulo_observador_x--;
		break;

		case GLUT_KEY_DOWN:
			angulo_observador_x++;
		break;

		case GLUT_KEY_PAGE_UP:
			distancia_observador *= 1.2;
		break;

		case GLUT_KEY_PAGE_DOWN:
			distancia_observador /= 1.2;
		break;
	}
}

