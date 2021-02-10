/** @file escena.cpp
 */

#include "escena.hpp"

Escena * Escena :: instance = nullptr;

/**
 * @brief Constructor por defecto.
 */

Escena :: Escena () noexcept
:
	ejes      (new Ejes()),
	cilindro  (new Cilindro(1, 5, 20, 30)),
	cono      (new Cono(1, 5, 20, 30)),
	cuadro    (new Cuadro()),
	cubo      (new Cubo(20)),
	cielo     (new Esfera(1, 50)),
	esfera    (new Esfera(1, 20)),
	tetraedro (new Tetraedro(30)),
	peon      (new ObjRevolucion("plys/peon.ply", 20, Tapas::Ambas, EjeY, true)),
	araxxor   (new Araxxor()),

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
	plastico_verde (new Material(
		{0.0f,  0.0f,  0.0f,  1.0f},
		{0.1f,  0.35f, 0.1f,  1.0f},
		{0.45f, 0.55f, 0.45f, 1.0f},
		32.0f
	)),
   turquesa (new Material(
		{0.1f,      0.18725f, 0.1745f,   1.0f},
		{0.396f,    0.74151f, 0.69102f,  1.0f},
		{0.297254f, 0.30829f, 0.306678f, 1.0f},
		12.8f
	)),

	t_araxxor (new Textura("texturas/araxxor.jpg", GL_LINEAR, GL_LINEAR)),
	cesped    (new Textura("texturas/grass.jpg")),
	madera    (new Textura("texturas/madera.jpg")),
	lata      (new Textura("texturas/text-lata-1.jpg")),
	tierra    (new Textura("texturas/dirt.jpg")),

	camaras {
		new Camara(
			Perspectiva,
			{100.0f, 100.0f, 100.0f},
			{0, 0,      0},
			{0, 1.0f,   0},
			50.0f,
			2000.0f
		),
		new Camara(
			Ortogonal,
			{100.0f, 100.0f, 100.0f},
			{0, 0,      0},
			{0, 1.0f,   0},
			50.0f,
			2000.0f
		),
		new Camara(
			Perspectiva,
			{100.0f, 100.0f, 100.0f},
			{0, 0,      0},
			{0, 1.0f,   0},
			50.0f,
			2000.0f
		)
	}
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> gen_tierra(1, 100);

	for (int i = 0; i < CUADRANTES; i++)
		for (int j = 0; j < TAM_SUELO; j++)
			for (int k = 0; k < TAM_SUELO; k++)
			{
				suelo[k][j][i] = new Cubo(20);
				suelo[k][j][i]->AplicarMaterial(plastico_verde);

				if (gen_tierra(gen) >= 60)
					suelo[k][j][i]->AplicarTextura(tierra);
				else
					suelo[k][j][i]->AplicarTextura(cesped);
			}

	std::uniform_int_distribution<> pos_flores(1, TAM_SUELO);

	for (int i = 0; i < FLORES; i++)
	{
		flores[i] = new Flor(pos_flores(gen), pos_flores(gen));
		flores[i]->AplicarMaterial(laton, plastico_verde);
	}

	cielo->Invertir();

	ejes->NuevoTamanio(5000);

	cilindro->AplicarMaterial(cromo);
	cono->AplicarMaterial(goma_negra);
	cuadro->AplicarMaterial(cromo);
	cubo->AplicarMaterial(estanio);
	cielo->AplicarMaterial(turquesa);
	esfera->AplicarMaterial(laton);
	tetraedro->AplicarMaterial(obsidiana);
	peon->AplicarMaterial(turquesa);
	araxxor->AplicarMaterial(turquesa);

	araxxor->AplicarTextura(t_araxxor, false);
	cilindro->AplicarTextura(lata, Cilindrica);
	cuadro->AplicarTextura(cesped);
	cubo->AplicarTextura(madera);

	araxxor->NuevoColorSeleccion(seleccion_araxxor);
	cilindro->NuevoColorSeleccion(seleccion_cilindro);

	luz0->Pulsar();
	luz1->Pulsar();
	visualizacion.flip(Iluminacion);
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

void Escena :: CambiarProyeccion () const noexcept
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	camara_activa->Proyectar();
}

/**
 * @brief Modifica la posición del observador de la escena.
 */

void Escena :: CambiarObservador () noexcept
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camara_activa->Observar();
	glGetFloatv(GL_MODELVIEW_MATRIX, matriz_vista);
}

void Escena :: DibujarSeleccion () noexcept
{
	const bool luces_activadas    = glIsEnabled(GL_LIGHTING);
	const bool texturas_activadas = glIsEnabled(GL_TEXTURE);

	glDisable(GL_DITHER);

	if (luces_activadas)
		glDisable(GL_LIGHTING);

	if (texturas_activadas)
		glDisable(GL_TEXTURE);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	CambiarObservador();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	DibujarMallas(incoloro, false, true);

	if (texturas_activadas)
		glEnable(GL_TEXTURE);

	if (luces_activadas)
		glEnable(GL_LIGHTING);

	glEnable(GL_DITHER);
}

/**
 * @brief Llama a las funciones de dibujado de las mallas activas.
 */

void Escena :: DibujarMallas (
	const unsigned char color,
	const bool ajedrez,
	const bool seleccion
) const noexcept
{
	/* glPushMatrix(); */
	/* { */
	/* 	glScalef(1600, 1600, 1600); */
	/* 	cielo->Dibujar(dibujo, ajedrez, color, seleccion); */
	/* } */
	/* glPopMatrix(); */

	/* for (int i = 0; i < CUADRANTES; i++) */
	/* { */
	/* 	const int eje_x = (i % 3 == 0) ? 1 : -1; */
	/* 	const int eje_z = (i > 1)      ? 1 : -1; */

	/* 	for (int j = 1; j <= TAM_SUELO; j++) */
	/* 		for (int k = 1; k <= TAM_SUELO; k++) */
	/* 		{ */
	/* 			glPushMatrix(); */
	/* 			{ */
	/* 				glScalef(1, 0, 1); */
	/* 				glTranslatef(eje_x * (40 * j - 20), -20, eje_z * (40 * k - 20)); */

	/* 				suelo[k-1][j-1][i]->Dibujar(dibujo, ajedrez, color, seleccion); */
	/* 			} */
	/* 			glPopMatrix(); */
	/* 		} */

	/* 	for (int j = 0; j < FLORES/CUADRANTES; j++) */
	/* 	{ */
	/* 		glPushMatrix(); */
	/* 		{ */
	/* 			glTranslatef(0, 30, 0); */
	/* 			glTranslatef( */
	/* 				eje_x * (40 * flores[(FLORES*i)/CUADRANTES + j]->PosX() - 20), */
	/* 				-20, */
	/* 				eje_z * (40 * flores[(FLORES*i)/CUADRANTES + j]->PosY() - 20) */
	/* 			); */
	/* 			glScalef(2, 2, 2); */
	/* 			flores[(FLORES*i)/CUADRANTES + j]->Dibujar(dibujo, ajedrez, color, seleccion); */
	/* 		} */
	/* 		glPopMatrix(); */
	/* 	} */
	/* } */

	if (visibles.test(obj_araxxor))
	{
		glPushMatrix();
		{
			glScalef(0.5f, 0.5f, 0.5f);
			araxxor->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cilindro))
	{
		glPushMatrix();
		{
			glTranslatef(-60, 0, -60);
			glScalef(30, 30, 30);
			cilindro->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cono))
	{
		glPushMatrix();
		{
			glTranslatef(60, 0, -60);
			glScalef(30, 30, 30);
			cono->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_cubo))
	{
		glPushMatrix();
		{
			glTranslatef(0, 20, 0);
			glRotatef(-90, 1, 0, 0);
			glScalef(0.035f, 0.035f, 0.035f);
			cubo->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_esfera))
	{
		glPushMatrix();
		{
			glTranslatef(0, -60, 0);
			glScalef(30, 30, 30);
			esfera->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_tetraedro))
	{
		glPushMatrix();
		{
			glTranslatef(0, 60, 0);
			tetraedro->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}

	if (visibles.test(obj_peon))
	{
		glPushMatrix();
		{
			glTranslatef(60, 0, 60);
			glScalef(30, 30, 30);
			peon->Dibujar(dibujo, ajedrez, color, seleccion);
		}
		glPopMatrix();
	}
}

Tupla3f Escena :: TrasladarPerspectiva (const Tupla3f & punto) const noexcept
{
	Tupla3f n_centro;
	GLfloat inv[16];

	InvertirMatriz16(matriz_vista, inv);

	n_centro[X] = inv[0] * punto[X] + inv[4] * punto[Y] + inv[8]  * punto[Z] + inv[12];
	n_centro[Y] = inv[1] * punto[X] + inv[5] * punto[Y] + inv[9]  * punto[Z] + inv[13];
	n_centro[Z] = inv[2] * punto[X] + inv[6] * punto[Y] + inv[10] * punto[Z] + inv[14];

	return n_centro;
}

void Escena :: SeleccionAnimacion (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (toupper(tecla))
	{
		case 'R':
			animacion = !animacion;
		break;

		case '+':
			velocidad_animacion = std::min(velocidad_animacion + 0.05f, 0.8f);
		break;

		case '-':
			velocidad_animacion = std::max(velocidad_animacion - 0.05f, 0.05f);
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionAnimacion(true);
}

/**
 * @brief Seleccionador de la cámara.
 * @param tecla Tecla pulsada por el usuario.
 */

void Escena :: SeleccionCamara (unsigned char tecla) noexcept
{
	bool continuar    = true;
	bool seleccionada = false;

	size_t seleccion = tecla - '0' - 1;

	if (seleccion < CAMARAS)
	{
		camara_activa = camaras[seleccion];
		seleccionada  = true;
	}
	else
	{
		TeclasComunes(tecla);
		continuar = false;
	}

	if (seleccionada)
	{
		CambiarObservador();
		CambiarProyeccion();
	}

	if (continuar)
		MsgSeleccionCamara(true);
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
			dibujo = Diferido;
		break;

		case 'I':
			dibujo = Inmediato;
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
		case 'A':
			menu = Menu::SeleccionAnimacion;
			MsgSeleccionAnimacion();
		break;

		case 'C':
			menu = Menu::SeleccionCamara;
			MsgSeleccionCamara();
		break;

		case 'D':
			menu = Menu::SeleccionDibujado;
			MsgSeleccionDibujado();
		break;

		case 'L':
			menu = Menu::SeleccionLuces;
			MsgSeleccionLuces();
		break;

		case 'M':
			menu = Menu::SeleccionMovimiento;
			MsgSeleccionMovimiento();
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

void Escena :: SeleccionMovimiento (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (std::toupper(tecla))
	{
		case '1':
			araxxor->NuevoMovmiento(Cabeza);
		break;

		case '2':
			araxxor->NuevoMovmiento(Femur);
		break;

		case '3':
			araxxor->NuevoMovmiento(Tibia);
		break;

		case '4':
			araxxor->NuevoMovmiento(Metatarso);
		break;

		case '5':
			araxxor->NuevoMovmiento(Tarso);
		break;

		case '+':
			araxxor->Mover(0.1f);
		break;

		case '-':
			araxxor->Mover(-0.1f);
		break;

		case 'X':
			araxxor->NuevoMovmiento(Estatico);
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionMovimiento(true);
}

/**
 * @brief Seleccionador del objeto Tienecon el que interactuar.
 * @param tecla Tecla pulsada por el usuario.
 */

void Escena :: SeleccionObjeto (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (std::toupper(tecla))
	{
		case 'A':
			visibles.flip(obj_araxxor);
		break;

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
			visualizacion.flip(Ajedrez);
			visualizacion.reset(Iluminacion);
		break;

		case 'I':
			visualizacion.flip(Iluminacion);
			visualizacion.reset(Ajedrez);
			visualizacion.reset(Lineas);
			visualizacion.reset(Puntos);
			visualizacion.reset(Solido);
		break;

		case 'L':
			visualizacion.flip(Lineas);
			visualizacion.reset(Iluminacion);
		break;

		case 'P':
			visualizacion.flip(Puntos);
			visualizacion.reset(Iluminacion);
		break;

		case 'S':
			visualizacion.flip(Solido);
			visualizacion.reset(Iluminacion);
		break;

		case 'T':
			visualizacion.flip(Texturas);

			if (visualizacion.test(Texturas))
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

void Escena :: MsgSeleccionAnimacion (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[5A";

	std::cout
		<< TermAzulB << "SELECCIÓN DE ANIMACIÓN:" << std::endl

		<< "\033[2K"
		<< TermCianB << "[" << TermAmarilloB << "R" << TermCianB << "]"
		<< (animacion ? TermVerde : TermRojo)
		<< " Reproducir animación (x " << velocidad_animacion << ")" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "+" << TermCianB << "]"
		<< TermNormal << " Incrementar velocidad" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "-" << TermCianB << "]"
		<< TermNormal << " Decrementar velocidad" << std::endl;

	MsgTeclasComunes();
}

/**
 * @brief Muestra el texto del menú de selección de cámaras.
 * @param reescribir Superposición del menú nuevo sobre el antiguo.
 */

void Escena :: MsgSeleccionCamara (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[5A";

	std::cout << TermAzulB << "SELECCIÓN DE CÁMARA:" << std::endl;

	for (size_t i = 0; i < CAMARAS; i++)
	{
		std::cout << "\033[2K"
		<< TermCianB << "[" << TermAmarilloB << i + 1 << TermCianB << "]"
		<< (camara_activa == camaras[i] ? TermVerde : TermRojo)
		<< " Cámara " << i + 1 << " ["
		<< (camaras[i]->Tipo() == Perspectiva ? "Perspectiva, " : "Ortogonal,   ")
		<< "E:" << camaras[i]->Eye() << ", A:" << camaras[i]->At() << ", U:"
		<< camaras[i]->Up() << "]" << std::endl;
	}

	std::cout << TermNormal;

	MsgTeclasComunes();
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
		<< (dibujo == Diferido ? TermVerde : TermRojo)
		<< " Modo diferido" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "I" << TermCianB << "]"
		<< (dibujo == Inmediato ? TermVerde : TermRojo)
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

		<< TermCianB  << "[" << TermAmarilloB << "A" << TermCianB << "]"
		<< TermNormal << " Animación del modelo" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "C" << TermCianB << "]"
		<< TermNormal << " Selección de cámara" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "D" << TermCianB << "]"
		<< TermNormal << " Selección de dibujado" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "L" << TermCianB << "]"
		<< TermNormal << " Selección de luces" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "M" << TermCianB << "]"
		<< TermNormal << " Movimiento manual del modelo" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "O" << TermCianB << "]"
		<< TermNormal << " Selección de objeto" << std::endl

		<< TermCianB  << "[" << TermAmarilloB << "V" << TermCianB << "]"
		<< TermNormal << " Selección de visualización" << std::endl;

	MsgTeclasComunes();
}

void Escena :: MsgSeleccionMovimiento (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[10A";

	std::cout
		<< TermAzulB << "MOVIMIENTO MANUAL DEL MODELO" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "1" << TermCianB << "]"
		<< (araxxor->Movimiento() == Cabeza ? TermVerde : TermRojo)
		<< " Cabeza (Traslación)" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "2" << TermCianB << "]"
		<< (araxxor->Movimiento() == Femur ? TermVerde : TermRojo)
		<< " Fémur (Rotación)" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "3" << TermCianB << "]"
		<< (araxxor->Movimiento() == Tibia ? TermVerde : TermRojo)
		<< " Tibia (Rotación)" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "4" << TermCianB << "]"
		<< (araxxor->Movimiento() == Metatarso ? TermVerde : TermRojo)
		<< " Metatarso (Rotación)" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "5" << TermCianB << "]"
		<< (araxxor->Movimiento() == Tarso ? TermVerde : TermRojo)
		<< " Tarso (Rotación)" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "+" << TermCianB << "]"
		<< TermNormal << " Incrementar movimiento" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "-" << TermCianB << "]"
		<< TermNormal << " Decrementar movimiento" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "X" << TermCianB << "]"
		<< TermNormal << " Cancelar movimiento" << TermNormal << std::endl;

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

		<< TermCianB << "[" << TermAmarilloB << "A" << TermCianB << "]"
		<< (visibles.test(obj_araxxor) ? TermVerde : TermRojo)
		<< " Araxxor" << std::endl

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
		<< (visualizacion.test(Ajedrez) ? TermVerde : TermRojo)
		<< " Modo ajedrez" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "I" << TermCianB << "]"
		<< (visualizacion.test(Iluminacion) ? TermVerde : TermRojo)
		<< " Modo iluminación" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "L" << TermCianB << "]"
		<< (visualizacion.test(Lineas) ? TermVerde : TermRojo)
		<< " Modo líneas" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "P" << TermCianB << "]"
		<< (visualizacion.test(Puntos) ? TermVerde : TermRojo)
		<< " Modo puntos" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "S" << TermCianB << "]"
		<< (visualizacion.test(Solido) ? TermVerde : TermRojo)
		<< " Modo sólido" << std::endl

		<< TermCianB << "[" << TermAmarilloB << "T" << TermCianB << "]"
		<< (visualizacion.test(Texturas) ? TermVerde : TermRojo)
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

void Escena :: SeleccionarMalla (const int x, const int y) noexcept
{
	/* glDisable(GL_DITHER); */
	/* glDisable(GL_LIGHTING); */
	/* glDisable(GL_TEXTURE_2D); */

	DibujarSeleccion();

	GLint viewport[4];
	GLfloat pixel[3];

	glGetIntegerv(GL_VIEWPORT, viewport);
	glReadPixels(x, viewport[3]-y, 1, 1, GL_RGB, GL_FLOAT, (void *) pixel);

	Tupla3f pixel_pulsado = {pixel[0], pixel[1], pixel[2]};
	Malla3D * seleccion = nullptr;

	if (pixel_pulsado == cilindro->ColorSeleccion())
	{
		seleccion = cilindro;
	}
	else if (pixel_pulsado == araxxor->ColorSeleccion())
	{
		seleccion = araxxor->Cuerpo();
	}


	camara_activa->Fijar(seleccion);

	if (seleccion == nullptr)
		camara_activa->NuevoAt({0, 0, 0});
	else
		camara_activa->NuevoAt(TrasladarPerspectiva(seleccion->Centro()));

	CambiarObservador();

	/* glEnable(GL_TEXTURE_2D); */
	/* glEnable(GL_LIGHTING); */
	/* glEnable(GL_DITHER); */

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
	delete cuadro;
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

	for (size_t i = 0; i < CAMARAS; i++)
		delete camaras[i];

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

	anchura = anchura_ventana / 10.0f;
	altura  = altura_ventana  / 10.0f;

	for (size_t i = 0; i < CAMARAS; i++)
	{
		camaras[i]->NuevoLeft(-anchura);
		camaras[i]->NuevoRight(anchura);
		camaras[i]->NuevoTop(altura);
		camaras[i]->NuevoBottom(-altura);
	}

	CambiarObservador();
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

	if (visualizacion.test(Ajedrez))
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		DibujarMallas(incoloro, true);
	}
	else
	{
		if (visualizacion.test(Iluminacion))
		{
			glEnable(GL_LIGHTING);
			{
				glPolygonMode(GL_FRONT, GL_FILL);
				AplicarLuces();
				DibujarMallas(incoloro);
			}
			glDisable(GL_LIGHTING);
		}

		if (visualizacion.test(Lineas))
		{
			glPolygonMode(GL_FRONT, GL_LINE);
			DibujarMallas(verde);
		}

		if (visualizacion.test(Puntos))
		{
			glPolygonMode(GL_FRONT, GL_POINT);
			DibujarMallas(azul);
		}

		if (visualizacion.test(Solido))
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
	const float relacion_aspecto = (float) (nueva_anchura / nueva_altura);

	for (size_t i = 0; i < CAMARAS; i++)
	{
		camaras[i]->NuevoLeft(camaras[i]->Bottom() * relacion_aspecto);
		camaras[i]->NuevoRight(camaras[i]->Top()   * relacion_aspecto);
	}

	CambiarProyeccion();
	glViewport(0, 0, nueva_anchura, nueva_altura);
}

void Escena :: ReproducirAnimacion () const noexcept
{
	if (animacion)
	{
		araxxor->NuevoMovmiento(Abdomen);
		araxxor->Mover(velocidad_animacion / 2.0f);

		araxxor->NuevoMovmiento(Cabeza);
		araxxor->Mover(velocidad_animacion);

		araxxor->NuevoMovmiento(Femur);
		araxxor->Mover(velocidad_animacion);

		araxxor->NuevoMovmiento(Tibia);
		araxxor->Mover(velocidad_animacion);

		araxxor->NuevoMovmiento(Metatarso);
		araxxor->Mover(velocidad_animacion);

		araxxor->NuevoMovmiento(Tarso);
		araxxor->Mover(velocidad_animacion);
	}
}

/**
 * @brief Llama a las funciones adecuadas según la tecla pulsada.
 * @param tecla Tecla pulsada por el usuario.
 * @param x Parámetro no utilizado de glut.
 * @param y Parámetro no utilizado de glut.
 */

bool Escena :: GestionTeclado (unsigned char tecla, int x, int y) noexcept
{
	(void) x;
	(void) y;

	switch (menu)
	{
		case Menu::Inactivo:
			SeleccionMenu(tecla);
		break;

		case Menu::SeleccionAnimacion:
			SeleccionAnimacion(tecla);
		break;

		case Menu::SeleccionCamara:
			SeleccionCamara(tecla);
		break;

		case Menu::SeleccionDibujado:
			SeleccionDibujado(tecla);
		break;

		case Menu::SeleccionLuces:
			SeleccionLuces(tecla);
		break;

		case Menu::SeleccionMovimiento:
			SeleccionMovimiento(tecla);
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
	(void) x;
	(void) y;

	switch (tecla)
	{
		case GLUT_KEY_LEFT:
			camara_activa->RotarExaminarY(-2*DEG_TO_RAD);
		break;

		case GLUT_KEY_RIGHT:
			camara_activa->RotarExaminarY(2*DEG_TO_RAD);
		break;

		case GLUT_KEY_UP:
			camara_activa->RotarExaminarX(-2*DEG_TO_RAD);
		break;

		case GLUT_KEY_DOWN:
			camara_activa->RotarExaminarX(2*DEG_TO_RAD);
		break;

		case GLUT_KEY_PAGE_UP:
			camara_activa->Zoom(1.2);
		break;

		case GLUT_KEY_PAGE_DOWN:
			camara_activa->Zoom(0.8);
		break;
	}

	if (menu == Menu::SeleccionCamara)
		MsgSeleccionCamara(true);

	CambiarProyeccion();
}

void Escena :: ClickRaton (int boton, int estado, int x, int y) noexcept
{
	switch (boton)
	{
		case GLUT_RIGHT_BUTTON:
			if (estado == GLUT_DOWN)
			{
				if (camara_activa->ObjetoFijo() == nullptr)
					raton = Movimiento1raPersona;
				else
					raton = MovimientoExaminar;
			}
			else
			{
				raton = Reposo;
			}
		break;

		case WHEEL_UP:
			camara_activa->Zoom(0.8);
		break;

		case WHEEL_DOWN:
			camara_activa->Zoom(1.2);
		break;

		case GLUT_LEFT_BUTTON:
			if (estado == GLUT_UP)
				SeleccionarMalla(x,y);
		break;
	}

	x_previa = x;
	y_previa = y;

	CambiarProyeccion();
}

void Escena :: MovimientoRaton (int x, int y) noexcept
{
	switch (raton)
	{
		case MovimientoExaminar:
			camara_activa->GirarExaminar(x - x_previa, y - y_previa);
			x_previa = x;
			y_previa = y;
		break;

		case Movimiento1raPersona:
			camara_activa->Girar1raPersona(x - x_previa, y - y_previa);
			x_previa = x;
			y_previa = y;
		break;

		case Reposo: break;
	}

	if (menu == Menu::SeleccionCamara)
		MsgSeleccionCamara(true);

	CambiarObservador();
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
