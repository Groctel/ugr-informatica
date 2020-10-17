#include "escena.hpp"

Escena * Escena :: instance = nullptr;

Escena::Escena ()
{
	Front_plane       = 50.0;
	Back_plane        = 2000.0;
	Observer_distance = 4*Front_plane;
	Observer_angle_x  = 0.0;
	Observer_angle_y  = 0.0;

	ejes.NuevoTamanio(5000);

	cubo      = new Cubo(60);
	tetraedro = new Tetraedro(60);
}

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

inline void Escena :: SeleccionObjeto (unsigned char tecla) noexcept
{
	bool continuar = true;

	switch (toupper(tecla))
	{
		case 'C':
			mostrar_cubo = !mostrar_cubo;
		break;

		case 'T':
			mostrar_tetraedro = !mostrar_tetraedro;
		break;

		default:
			TeclasComunes(tecla);
			continuar = false;
		break;
	}

	if (continuar)
		MsgSeleccionObjeto(true);
}

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

inline void Escena :: MsgSeleccionDibujado (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[4A";

	std::cout << coloresterm::AZUL_B << "SELECCIÓN DE DIBUJADO:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "D"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (dibujo == Dibujo::Diferido ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Modo diferido" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "I"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (dibujo == Dibujo::Inmediato ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Modo inmediato" << std::endl;

	MsgTeclasComunes();
}

inline void Escena :: MsgSeleccionMenu (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[5A";

	std::cout << coloresterm::AZUL_B << "SELECCIÓN DE MENÚ:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "D"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de dibujado" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "O"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de objeto" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "V"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< " Selección de visualización" << std::endl;

	MsgTeclasComunes();
}

inline void Escena :: MsgSeleccionObjeto (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[4A";

	std::cout << coloresterm::AZUL_B << "SELECCIÓN DE OBJETO:" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "C"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (mostrar_cubo ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Cubo" << std::endl
		<< coloresterm::CIAN_B << "[" << coloresterm::AMARILLO_B << "T"
		<< coloresterm::CIAN_B << "]" << coloresterm::NORMAL
		<< (mostrar_tetraedro ? coloresterm::VERDE : coloresterm::ROJO)
		<< " Tetraedro" << std::endl;

	MsgTeclasComunes();
}

inline void Escena :: MsgSeleccionVisualizacion (bool reescribir) const noexcept
{
	if (reescribir)
		std::cout << "\033[5A";

	std::cout << coloresterm::AZUL_B << "SELECCIÓN DE VISUALIZACIÓN:" << std::endl
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
		<< coloresterm::AMARILLO << " Modo sólido" << std::endl;

	MsgTeclasComunes();
}

inline void Escena :: MsgTeclasComunes () const noexcept
{
	std::cout
		<< coloresterm::AZUL_B << "[" << coloresterm::ROJO_B << "Q"
		<< coloresterm::AZUL_B << "]" << coloresterm::NORMAL
		<< ((menu == Menu::Inactivo) ? " Finalizar ejecución del programa"
			: " Volver a la selección de menú") << std::endl;
}

inline void Escena :: Visualizar (Visualizacion visualizacion) noexcept
{
	if (mostrar_cubo)
		cubo->Visualizar(visualizacion);

	if (mostrar_tetraedro)
		tetraedro->Visualizar(visualizacion);
}

Escena * Escena :: Instance ()
{
	if (instance == nullptr)
		instance = new Escena;

	return instance;
}

Escena :: ~Escena ()
{
	instance = nullptr;
	delete cubo;
	delete tetraedro;
	exit(0);
}

void Escena :: Inicializar (int UI_window_width, int UI_window_height)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glPointSize(5);

	Width  = UI_window_width  / 10;
	Height = UI_window_height / 10;

	CambiarProyeccion(float(UI_window_width)/float(UI_window_height));
	glViewport(0, 0, UI_window_width, UI_window_height);

	MsgSeleccionMenu();
}

void Escena :: Dibujar ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	change_observer();
	ejes.Dibujar();
	cubo->Dibujar(dibujo);
	tetraedro->Dibujar(dibujo);
}

bool Escena :: GestionTeclado (unsigned char tecla, int x, int y)
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

void Escena :: GestionTecladoEspecial (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT:
			Observer_angle_y--;
		break;

		case GLUT_KEY_RIGHT:
			Observer_angle_y++;
		break;

		case GLUT_KEY_UP:
			Observer_angle_x--;
		break;

		case GLUT_KEY_DOWN:
			Observer_angle_x++;
		break;

		case GLUT_KEY_PAGE_UP:
			Observer_distance *= 1.2;
		break;

		case GLUT_KEY_PAGE_DOWN:
			Observer_distance /= 1.2;
		break;
	}
	//std::cout << Observer_distance << std::endl;
}

void Escena :: CambiarProyeccion (const float ratio_xy)
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	const float wx = float(Height)*ratio_xy ;
	glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}

void Escena :: Redimensionar (int newWidth, int newHeight)
{
	Width  = newWidth/10;
	Height = newHeight/10;
	CambiarProyeccion(float(newHeight) / float(newWidth));
	glViewport(0, 0, newWidth, newHeight);
}

void Escena :: change_observer ()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -Observer_distance);
	glRotatef(Observer_angle_y, 0.0 ,1.0, 0.0);
	glRotatef(Observer_angle_x, 1.0, 0.0, 0.0);
}

