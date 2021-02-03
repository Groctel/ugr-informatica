/** @file escena.cpp
 */

#include "escena.hpp"

Escena * Escena :: instance = nullptr;

/**
 * @brief Constructor por defecto.
 */

Escena :: Escena () noexcept
:
	plano_delantero     (50.0),
	plano_trasero       (2000.0),
	angulo_observador_x (0.0),
	angulo_observador_y (0.0),

	ejes      (new Ejes()),
	cilindro  (new Cilindro(1, 5, 3, 3)),
	cono      (new Cono(1, 5, 20, 30)),
	cubo      (new Cubo(30)),
	esfera    (new Esfera(1, 20)),
	jirafa    (new Jirafa()),
	tetraedro (new Tetraedro(30)),
	peon      (new ObjRevolucion("plys/peon.ply", 20, Tapas::Ambas)),

	luz0 (new LuzDireccional(
		GL_LIGHT0,
		{0,   0,   0, 1},
		{1,   1,   1, 1},
		{1,   1,   1, 1},
		{200, 150, 200}
	)),
	luz1 (new LuzPosicional(
		GL_LIGHT1,
		{0, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 10}
	)),

	// http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html
   cromo (new Material(
		{0.25f,     0.25f,     0.25f,     1.0f},
		{0.4f,      0.4f,      0.4f,      1.0f},
		{0.774597f, 0.774597f, 0.774597f, 1.0f},
		76.8f
	)),
   goma_negra (new Material(
		{0.02f, 0.02f, 0.02f, 1.0f},
		{0.01f, 0.01f, 0.01f, 1.0f},
		{0.4f,  0.4f,  0.4f,  1.0f},
		10.0f
	)),
   estanio (new Material(
		{0.105882f, 0.058824f, 0.113725f, 1.0f},
		{0.427451f, 0.470588f, 0.541176f, 1.0f},
		{0.333333f, 0.333333f, 0.521569f, 1.0f},
		9.84615f
	)),
	laton (new Material(
		{0.329412f, 0.223529f, 0.027451f, 1.0f},
		{0.780392f, 0.568627f, 0.113725f, 1.0f},
		{0.992157f, 0.941176f, 0.807843f, 1.0f},
		27.8974f
	)),
   obsidiana (new Material(
		{0.05375f,  0.05f,     0.06625f,  0.82f},
		{0.18275f,  0.17f,     0.22525f,  0.82f},
		{0.332741f, 0.328634f, 0.346435f, 0.82f},
		38.4f
	)),
   turquesa (new Material(
		{0.1f,      0.18725f, 0.1745f,   1.0f},
		{0.396f,    0.74151f, 0.69102f,  1.0f},
		{0.297254f, 0.30829f, 0.306678f, 1.0f},
		12.8f
	)),

	madera (new Textura("texturas/madera.jpg"))
{
	distancia_observador = 4 * plano_delantero,
	ejes->NuevoTamanio(5000);

	cilindro->AplicarMaterial(cromo);
	cono->AplicarMaterial(goma_negra);
	cubo->AplicarMaterial(estanio);
	esfera->AplicarMaterial(laton);
	tetraedro->AplicarMaterial(obsidiana);
	peon->AplicarMaterial(turquesa);

	cubo->AplicarTextura(madera);
}

void Escena :: AplicarLuces () noexcept
{
	luz0->Aplicar();
	luz1->Aplicar();
}

/**
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

/**
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

/**
 * @brief Llama a las funciones de dibujado de las mallas activas.
 */

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

	if (visibles.test(obj_jirafa))
	{
		glPushMatrix();
		{
			glScalef(30, 30, 30);
			jirafa->Dibujar(dibujo, ajedrez, color);
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

/**
 * @brief Seleccionador de modo de dibujo.
 * @param tecla Tecla pulsada por el usuario.
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

/**
 * @brief Selector y manipulador de las luces.
 * @param tecla Tecla pulsada por el usuario.
 */

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

		case 'A':
			angulos.rotx = !angulos.rotx;
		break;

		case 'B':
			angulos.roty = !angulos.roty;
		break;

		case '<':
			if (angulos.rotx)
				luz0->VariarRotX(-0.05);

			if (angulos.roty)
				luz0->VariarRotY(-0.05);
		break;

		case '>':
			if (angulos.rotx)
				luz0->VariarRotX(0.05);

			if (angulos.roty)
				luz0->VariarRotY(0.05);
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionLuces(true);
}

/**
 * @brief Seleccionador del submenú de la escena.
 * @param tecla Tecla pulsada por el usuario.
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

/**
 * @brief Seleccionador del objeto con el que interactuar.
 * @param tecla Tecla pulsada por el usuario.
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

		case 'J':
			visibles.flip(obj_jirafa);
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

/**
 * @brief Seleccionador de la visualización de los objetos visibles.
 * @param tecla Tecla pulsada por el usuario.
 */

void Escena :: SeleccionVisualizacion (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (toupper(tecla))
	{
		case 'A':
			visualizacion.flip(Visualizacion::Ajedrez);
			visualizacion.reset(Visualizacion::Iluminacion);
		break;

		case 'I':
			visualizacion.flip(Visualizacion::Iluminacion);
			visualizacion.reset(Visualizacion::Ajedrez);
			visualizacion.reset(Visualizacion::Lineas);
			visualizacion.reset(Visualizacion::Puntos);
			visualizacion.reset(Visualizacion::Solido);
		break;

		case 'L':
			visualizacion.flip(Visualizacion::Lineas);
			visualizacion.reset(Visualizacion::Iluminacion);
		break;

		case 'P':
			visualizacion.flip(Visualizacion::Puntos);
			visualizacion.reset(Visualizacion::Iluminacion);
		break;

		case 'S':
			visualizacion.flip(Visualizacion::Solido);
			visualizacion.reset(Visualizacion::Iluminacion);
		break;

		case 'T':
			visualizacion.flip(Visualizacion::Texturas);

			if (visualizacion.test(Visualizacion::Texturas))
				glEnable(GL_TEXTURE_2D);
			else
				glDisable(GL_TEXTURE_2D);
		break;

		case 'X':
			cilindro->MostrarTapas(!cilindro->MuestraTapas());
			cono->MostrarTapas(!cono->MuestraTapas());
			esfera->MostrarTapas(!esfera->MuestraTapas());
			peon->MostrarTapas(!peon->MuestraTapas());
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionVisualizacion(true);
}

/**
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

/**
 * @brief Muestra el texto del menú de selección de dibujado.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionDibujado (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[4A";

	std::cout
		<< TermAzulB << "SELECCIÓN DE DIBUJADO:" << std::endl
		<< TermCianB << "[" << TermAmarilloB << "D" << TermCianB << "]"
		<< (dibujo == Dibujo::Diferido ? TermVerde : TermRojo)
		<< " Modo diferido" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "I" << TermCianB << "]"
		<< (dibujo == Dibujo::Inmediato ? TermVerde : TermRojo)
		<< " Modo inmediato" << TermNormal << std::endl;

	MsgTeclasComunes();
}

/**
 * @brief Muestra el texto del menú de selección y manipulación de luces.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionLuces (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[8A";

	std::cout
		<< TermAzulB << "SELECCIÓN DE LUCES:" << std::endl
		<< TermCianB << "[" << TermAmarilloB << "0" << TermCianB << "]"
		<< (luz0->Activada() ? TermVerde : TermRojo)
		<< " Luz 0" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "1" << TermCianB << "]"
		<< (luz1->Activada() ? TermVerde : TermRojo)
		<< " Luz 1" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "A" << TermCianB << "]"
		<< (angulos.rotx ? TermVerde : TermRojo)
		<< " Rotación x en luces direccionales (ángulo alfa)" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "B" << TermCianB << "]"
		<< (angulos.roty ? TermVerde : TermRojo)
		<< " Rotación y en luces direccionales (ángulo beta)" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "<" << TermCianB << "]"
		<< TermNormal << " Decremento del ángulo" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << ">" << TermCianB << "]"
		<< TermNormal << " Incremento del ángulo" << TermNormal << std::endl;

	MsgTeclasComunes();
}

/**
 * @brief Muestra el texto del menú de selección de submenús.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionMenu () const noexcept
{
	std::cout
		<< TermAzulB  << "SELECCIÓN DE MENÚ:" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "D" << TermCianB << "]"
		<< TermNormal << " Selección de dibujado" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "L" << TermCianB << "]"
		<< TermNormal << " Selección de luces" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "O" << TermCianB << "]"
		<< TermNormal << " Selección de objeto" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "V" << TermCianB << "]"
		<< TermNormal << " Selección de visualización" << std::endl;

	MsgTeclasComunes();
}

/**
 * @brief Muestra el texto del menú de selección de objetos.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionObjeto (bool reescribir) noexcept
{
	if (reescribir)
		std::cout << "\033[9A";

	std::cout
		<< TermAzulB << "SELECCIÓN DE OBJETO:" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "C" << TermCianB << "]"
		<< (visibles.test(obj_cubo) ? TermVerde : TermRojo)
		<< " Cubo" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "I" << TermCianB << "]"
		<< (visibles.test(obj_cilindro) ? TermVerde : TermRojo)
		<< " Cilindro" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "O" << TermCianB << "]"
		<< (visibles.test(obj_cono) ? TermVerde : TermRojo)
		<< " Cono" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "E" << TermCianB << "]"
		<< (visibles.test(obj_esfera) ? TermVerde : TermRojo)
		<< " Esfera" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "J" << TermCianB << "]"
		<< (visibles.test(obj_jirafa) ? TermVerde : TermRojo)
		<< " Jirafa" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "T" << TermCianB << "]"
		<< (visibles.test(obj_tetraedro) ? TermVerde : TermRojo)
		<< " Tetraedro" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "P" << TermCianB << "]"
		<< (visibles.test(obj_peon) ? TermVerde : TermRojo)
		<< " Peon" << TermNormal << std::endl;

	MsgTeclasComunes();
}

/**
 * @brief Muestra el texto del menú de selección de modos de visualización.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionVisualizacion (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[9A";

	std::cout
		<< TermAzulB << "SELECCIÓN DE VISUALIZACIÓN:" << std::endl
		<< TermCianB << "[" << TermAmarilloB << "A" << TermCianB << "]"
		<< (visualizacion.test(Visualizacion::Ajedrez) ? TermVerde : TermRojo)
		<< " Modo ajedrez" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "I" << TermCianB << "]"
		<< (visualizacion.test(Visualizacion::Iluminacion) ? TermVerde : TermRojo)
		<< " Modo iluminación" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "L" << TermCianB << "]"
		<< (visualizacion.test(Visualizacion::Lineas) ? TermVerde : TermRojo)
		<< " Modo líneas" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "P" << TermCianB << "]"
		<< (visualizacion.test(Visualizacion::Puntos) ? TermVerde : TermRojo)
		<< " Modo puntos" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "S" << TermCianB << "]"
		<< (visualizacion.test(Visualizacion::Solido) ? TermVerde : TermRojo)
		<< " Modo sólido" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "T" << TermCianB << "]"
		<< (visualizacion.test(Visualizacion::Texturas) ? TermVerde : TermRojo)
		<< " Modo texturas" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "X" << TermCianB << "]"
		<< (peon->MuestraTapas() ? TermVerde : TermRojo)
		<< " Mostrar tapas" << TermNormal << std::endl;

	MsgTeclasComunes();
}

/**
 * @brief Muestra el texto de las teclas comunes a todos los menús.
 */

void Escena :: MsgTeclasComunes () const noexcept
{
	std::cout
		<< TermAzulB << "[" << TermRojoB << "Q" << TermAzulB << "]"
		<< TermNormal << (
			(menu == Menu::Inactivo)
			? " Finalizar ejecución del programa"
			: " Volver a la selección de menú"
		)
		<< std::endl;
}

/**
 * @brief Instanciador para cumplir con el patrón Singleton.
 */

Escena * Escena :: Instance () noexcept
{
	if (instance == nullptr)
		instance = new Escena;

	return instance;
}

/**
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

	delete cromo;
	delete laton;
	delete goma_negra;
	delete estanio;
	delete obsidiana;
	delete turquesa;

	delete madera;

	exit(0);
}

/**
 * @brief Inicializa los aspectos de dibujo de la escena.
 * @param anchura_ventana Anchura de la ventana en la que se muestra la escena.
 * @param altura_ventana Altura de la ventana en la que se muestra la escena.
 */

void Escena :: Inicializar (int anchura_ventana, int altura_ventana) noexcept
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glShadeModel(GL_SMOOTH);

	glPointSize(5);
	glLineWidth(2);

	anchura = anchura_ventana / 10;
	altura  = altura_ventana  / 10;

	CambiarProyeccion((float) anchura_ventana / (float) altura_ventana);
	glViewport(0, 0, anchura_ventana, altura_ventana);

	MsgSeleccionMenu();
}

/**
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
			glPolygonMode(GL_FRONT, GL_LINE);
			DibujarMallas(verde);
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

/**
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

/**
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

/**
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

/**
 * @brief Consultor del estado de visualización de los objetos de la escena.
 * @param vis Estado de visualización a consultar.
 */

bool Escena :: EstadoVisualizacion (Visualizacion vis) const noexcept
{
	return visualizacion.test(vis);
}

/**
 * @brief Modificador del estado de visualización de los objetos de la escena.
 * @param vis Estado de visualización a modificar.
 *
 * Al estar almacenados los estados en un `std::bitset`, la visuación se
 * modifica invirtiendo su estado actual.
 */

void Escena :: ModificarVisualizacion (Visualizacion vis) noexcept
{
	visualizacion.flip(vis);
}
