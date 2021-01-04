#include "motor.hpp"
#include "escena.hpp"

void Dibujar ()
{
	Escena::Instance()->Dibujar();
	glutSwapBuffers();
}

void Redimensionar (int anchura, int altura)
{
	Escena::Instance()->Redimensionar(anchura, altura);
	glutPostRedisplay();
}

void GestionTeclado (unsigned char tecla, int x, int y)
{
	bool escena_activa = Escena::Instance()->GestionTeclado(tecla, x, y);

	if (!escena_activa) {
		Escena::Instance()->~Escena();
		exit(0);
	}

	glutPostRedisplay();
}

void GestionTecladoEspecial (int tecla, int x, int y)
{
	Escena::Instance()->GestionTecladoEspecial(tecla, x, y);
	glutPostRedisplay();
}

int main (int argc, char ** argv)
{
	const int
		UI_window_pos_x  = 50,
		UI_window_pos_y  = 50,
		UI_window_width  = 500,
		UI_window_height = 500;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);
	glutInitWindowSize(UI_window_width, UI_window_height);
	glutCreateWindow("Prácticas IG: Atanasio Rubio Gil");

	glutDisplayFunc(Dibujar);
	glutReshapeFunc(Redimensionar);
	glutKeyboardFunc(GestionTeclado);
	glutSpecialFunc(GestionTecladoEspecial);

	#ifdef LINUX
	{
		const GLenum codigo = glewInit();

		if (codigo != GLEW_OK) {
			std::cout << "Imposible inicializar ’GLEW’, mensaje recibido: "
				<< glewGetErrorString(codigo) << std::endl;
			exit(1);
		}
	}
	#endif

	Escena::Instance()->Inicializar(UI_window_width, UI_window_height);
	glutMainLoop();

	return 0;
}
