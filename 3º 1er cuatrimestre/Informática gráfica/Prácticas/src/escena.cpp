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

	ejes      (new Ejes()),
	cilindro  (new Cilindro(1, 5, 20, 30)),
	cono      (new Cono(1, 5, 20, 30)),
	cubo      (new Cubo(30)),
	esfera    (new Esfera(1, 20)),
	tetraedro (new Tetraedro(30)),
	peon      (new ObjRevolucion("plys/peon.ply", 20, Tapas::Ambas)),

	luz0 (new LuzDireccional(
		GL_LIGHT0,
		{0, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 10}
	)),
	luz1 (new LuzPosicional(
		GL_LIGHT1,
		{0, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{200, 150, 200}
	)),

	// http://devernay.free.fr/cours/opengl/materials.html
   esmeralda (new Material(
		{0.0215f,  0.1745f,   0.0215f,  1},
		{0.07568f, 0.61424f,  0.07568f, 1},
		{0.633f,   0.727811f, 0.633f,   1},
		0.6 * 128.0f
	)),
   perla (new Material(
		{0.25f,     0.20725f,  0.20725f,  1},
		{1,         0.829f,    0.829f,    1},
		{0.296648f, 0.296648f, 0.296648f, 1},
		128.0f * 0.088
	)),
   plata (new Material(
		{0.19225f,  0.19225f,  0.19225f,  1},
		{0.50754f,  0.50754f,  0.50754f,  1},
		{0.508273f, 0.508273f, 0.508273f, 1},
		0.4*128.0f
	)),
	oro (new Material(
		{0.24725f,  0.1995f,   0.0745f,   1},
		{0.75164f,  0.60648f,  0.22648f,  1},
		{0.628281f, 0.555802f, 0.366065f, 1},
		0.4f * 128.0f
	)),
   ruby (new Material(
		{0.1745f,   0.01175f,  0.01175f,  1},
		{0.61424f,  0.04136f,  0.04136f,  1},
		{0.727811f, 0.626959f, 0.626959f, 1},
		128.0f * 0.6f
	)),
   turquesa (new Material(
		{0.1f,      0.18725f, 0.1745f,   1},
		{0.396f,    0.74151f, 0.69102f,  1},
		{0.297254f, 0.30829f, 0.306678f, 1},
		0.1 * 128.0f
	))
{
	distancia_observador = 4 * plano_delantero,
	ejes->NuevoTamanio(5000);

	cilindro->AplicarMaterial(esmeralda);
	cono->AplicarMaterial(perla);
	cubo->AplicarMaterial(plata);
	esfera->AplicarMaterial(oro);
	tetraedro->AplicarMaterial(ruby);
	peon->AplicarMaterial(turquesa);
}

void Escena :: AplicarLuces () noexcept
{
	luz0->Aplicar();
	luz1->Aplicar();
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

void Escena :: DibujarMallas (
	const unsigned char color,
	const bool ajedrez
) const noexcept
{
	if (visibles.test(obj_cilindro))
	{
		glPushMatrix();
		{
			glTranslatef(-60, 0, -60);
			glScalef(30, 30, 30);
			cilindro->Dibujar(dibujo, ajedrez, color);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cono))
	{
		glPushMatrix();
		{
			glTranslatef(60, 0, -60);
			glScalef(30, 30, 30);
			cono->Dibujar(dibujo, ajedrez, color);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cubo))
	{
		glPushMatrix();
		{
			glTranslatef(-60, 0, 60);
			cubo->Dibujar(dibujo, ajedrez, color);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_esfera))
	{
		glPushMatrix();
		{
			glTranslatef(0, -60, 0);
			glScalef(30, 30, 30);
			esfera->Dibujar(dibujo, ajedrez, color);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_tetraedro))
	{
		glPushMatrix();
		{
			glTranslatef(0, 60, 0);
			tetraedro->Dibujar(dibujo, ajedrez, color);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_peon))
	{
		glPushMatrix();
		{
			glTranslatef(60, 0, 60);
			glScalef(30, 30, 30);
			peon->Dibujar(dibujo, ajedrez, color);
		}
		glPopMatrix();
	}
}

/** @fn void Escena :: SeleccionDibujado (unsigned char tecla) noexcept
 *
 * @brief Seleccionador de modo de dibujo.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Alterna entre el modo de dibujo inmediato y diferido.
 */

void Escena :: SeleccionDibujado (unsigned char tecla) noexcept
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

void Escena :: SeleccionLuces (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (toupper(tecla))
	{
		case '0':
			luz0->Pulsar();
		break;

		case '1':
			luz1->Pulsar();
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionLuces(true);
}

/** @fn void Escena :: SeleccionMenu (unsigned char tecla) noexcept
 *
 * @brief Seleccionador del submenú de la escena.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Cambia el menú al seleccionado por el usuario.
 */

void Escena :: SeleccionMenu (unsigned char tecla) noexcept
{
	switch (toupper(tecla))
	{
		case 'D':
			menu = Menu::SeleccionDibujado;
			MsgSeleccionDibujado();
		break;

		case 'L':
			menu = Menu::SeleccionLuces;
			MsgSeleccionLuces();
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

/** @fn void Escena :: SeleccionObjeto (unsigned char tecla) noexcept
 *
 * @brief Seleccionador del objeto con el que interactuar.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Alterna la muestra del objeto seleccionado.
 */

void Escena :: SeleccionObjeto (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (std::toupper(tecla))
	{
		case 'C':
			visibles.flip(obj_cubo);
		break;

		case 'I':
			visibles.flip(obj_cilindro);
		break;

		case 'O':
			visibles.flip(obj_cono);
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

/** @fn void Escena :: SeleccionVisualizacion (unsigned char tecla) noexcept
 *
 * @brief Seleccionador de la visualización de los objetos visibles.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Alterna los diferentes modos de visualización para los objetos visibles.
 */

void Escena :: SeleccionVisualizacion (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (toupper(tecla))
	{
		case 'A':
			visualizacion.flip(Visualizacion::Ajedrez);
			if (visualizacion.test(Visualizacion::Iluminacion))
				visualizacion.flip(Visualizacion::Iluminacion);
		break;

		case 'I':
			visualizacion.flip(Visualizacion::Iluminacion);
			if (visualizacion.test(Visualizacion::Ajedrez))
				visualizacion.flip(Visualizacion::Ajedrez);
			if (visualizacion.test(Visualizacion::Lineas))
				visualizacion.flip(Visualizacion::Lineas);
			if (visualizacion.test(Visualizacion::Puntos))
				visualizacion.flip(Visualizacion::Puntos);
			if (visualizacion.test(Visualizacion::Solido))
				visualizacion.flip(Visualizacion::Solido);
		break;

		case 'L':
			visualizacion.flip(Visualizacion::Lineas);
			if (visualizacion.test(Visualizacion::Iluminacion))
				visualizacion.flip(Visualizacion::Iluminacion);
		break;

		case 'P':
			visualizacion.flip(Visualizacion::Puntos);
			if (visualizacion.test(Visualizacion::Iluminacion))
				visualizacion.flip(Visualizacion::Iluminacion);
		break;

		case 'S':
			visualizacion.flip(Visualizacion::Solido);
			if (visualizacion.test(Visualizacion::Iluminacion))
				visualizacion.flip(Visualizacion::Iluminacion);
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionVisualizacion(true);
}

/** @fn void Escena :: TeclasComunes (unsigned char tecla) noexcept
 *
 * @brief Gestor de teclas pulsables en todos los menús.
 * @param tecla Tecla pulsada por el usuario.
 *
 * Cierra los submenús para salir al menú principal o finaliza la ejecución del
 * programa si el menú actual es el principal.
 */

void Escena :: TeclasComunes (unsigned char tecla) noexcept
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

/** @fn void Escena :: MsgSeleccionDibujado (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de dibujado.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionDibujado (bool reescribir) const noexcept
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

void Escena :: MsgSeleccionLuces (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[4A";

	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE LUCES:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "0"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (luz0->Activada() ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Luz 0" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "1"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (luz1->Activada() ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Luz 1"
		<< coloresterm::NORMAL << std::endl;

	MsgTeclasComunes();
}

/** @fn void Escena :: MsgSeleccionMenu (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de submenús.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionMenu () const noexcept
{
	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE MENÚ:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "D"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de dibujado" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "L"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de luces" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "O"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de objeto" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "V"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de visualización" << coloresterm::NORMAL << std::endl;

	MsgTeclasComunes();
}

/** @fn void Escena :: MsgSeleccionObjeto (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de objetos.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionObjeto (bool reescribir) noexcept
{
	if (reescribir)
		std::cout << "\033[8A";

	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE OBJETO:" << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "C"
		<< coloresterm::CIAN_B << "]"
		<< coloresterm::NORMAL
		<< (visibles.test(obj_cubo) ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Cubo" << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "I"
		<< coloresterm::CIAN_B << "]"
		<< coloresterm::NORMAL
		<< (visibles.test(obj_cilindro) ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Cilindro" << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "O"
		<< coloresterm::CIAN_B << "]"
		<< coloresterm::NORMAL
		<< (visibles.test(obj_cono) ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Cono" << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "E"
		<< coloresterm::CIAN_B << "]"
		<< coloresterm::NORMAL
		<< (visibles.test(obj_esfera) ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Esfera" << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "T"
		<< coloresterm::CIAN_B << "]"
		<< coloresterm::NORMAL
		<< (visibles.test(obj_tetraedro) ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Tetraedro" << std::endl
		<< coloresterm::CIAN_B << "["
		<< coloresterm::AMARILLO_B << "P"
		<< coloresterm::CIAN_B << "]"
		<< coloresterm::NORMAL
		<< (visibles.test(obj_peon) ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Peon"
		<< coloresterm::NORMAL << std::endl;

	MsgTeclasComunes();
}

/** @fn void Escena :: MsgSeleccionVisualizacion (bool reescribir) const noexcept
 *
 * @brief Muestra el texto del menú de selección de modos de visualización.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionVisualizacion (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[7A";

	std::cout
		<< coloresterm::AZUL_B << "SELECCIÓN DE VISUALIZACIÓN:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "A"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (visualizacion.test(Visualizacion::Ajedrez)
				? coloresterm::VERDE
				: coloresterm::ROJO
			)
		<< " Modo ajedrez" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "I"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (visualizacion.test(Visualizacion::Iluminacion)
				? coloresterm::VERDE
				: coloresterm::ROJO
			)
		<< " Modo iluminación" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "L"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (visualizacion.test(Visualizacion::Lineas)
				? coloresterm::VERDE
				: coloresterm::ROJO
			)
		<< " Modo líneas" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "P"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (visualizacion.test(Visualizacion::Puntos)
				? coloresterm::VERDE
				: coloresterm::ROJO
			)
		<< " Modo puntos" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "S"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (visualizacion.test(Visualizacion::Solido)
				? coloresterm::VERDE
				: coloresterm::ROJO
			)
		<< " Modo sólido" << coloresterm::NORMAL
		<< std::endl;

	MsgTeclasComunes();
}

/** @fn void Escena :: MsgTeclasComunes () const noexcept
 *
 * @brief Muestra el texto de las teclas comunes a todos los menús.
 */

void Escena :: MsgTeclasComunes () const noexcept
{
	std::cout
		<< coloresterm::AZUL_B << "[" << coloresterm::ROJO_B << "Q"
		<< coloresterm::AZUL_B << "]" << coloresterm::NORMAL
		<< ((menu == Menu::Inactivo) ? " Finalizar ejecución del programa"
			: " Volver a la selección de menú") << std::endl;
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
	delete ejes;
	delete cilindro;
	delete cono;
	delete cubo;
	delete esfera;
	delete tetraedro;
	delete peon;

	delete luz0;
	delete luz1;

	delete esmeralda;
	delete oro;
	delete perla;
	delete plata;
	delete ruby;
	delete turquesa;

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

	ejes->Dibujar();

	if (visualizacion.test(Visualizacion::Ajedrez))
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		DibujarMallas(incoloro, true);
	}
	else
	{
		if (visualizacion.test(Visualizacion::Iluminacion))
		{
			glEnable(GL_LIGHTING);
			{
				glPolygonMode(GL_FRONT, GL_FILL);
				AplicarLuces();
				DibujarMallas(incoloro);
			}
			glDisable(GL_LIGHTING);
		}

		if (visualizacion.test(Visualizacion::Lineas))
		{
			glLineWidth(2);
			{
				glPolygonMode(GL_FRONT, GL_LINE);
				DibujarMallas(verde);
			}
			glLineWidth(1);
		}

		if (visualizacion.test(Visualizacion::Puntos))
		{
			glPolygonMode(GL_FRONT, GL_POINT);
			DibujarMallas(azul);
		}

		if (visualizacion.test(Visualizacion::Solido))
		{
			glPolygonMode(GL_FRONT, GL_FILL);
			DibujarMallas(rojo);
		}
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

		case Menu::SeleccionLuces:
			SeleccionLuces(tecla);
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

