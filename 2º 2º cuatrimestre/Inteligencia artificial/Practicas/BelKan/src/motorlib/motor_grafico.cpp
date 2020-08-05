#include "motorlib.hpp"

#include <glui/glui.h>
#include <dirent.h>

MonitorJuego monitor;

// variables que determninan la posicion y tamaño de la ventana X
const int IU_ancho_ventana = 1024;
const int IU_alto_ventana = 768;

//Variables que controlan las ventanas y vistas
GLuint ventanaPrincipal, vistaPrincipal, vistaMiniMapa, vistaIU;
GLUI * panelSelecMapa, * panelSelecMapaConfig;
GLUI_Listbox * listbox;
GLUI_RadioGroup * group;
GLUI_Button * botonElegirMapa, * botonConfigurar, * botonPaso, * botonEjecucion, * botonEjecutar, * botonSalir;
GLUI_EditText * editPosX, * editPosY, * editTextPasos, * editTextRetardo;
GLUI_Checkbox * drawMM;
GLUI_StaticText * lineaVacia, * info0, * info1, * info2, * info3,* info4, * info5, * info6, * info7, * info8, * info9;
GLUI_Spinner *setup1, *setup2, *setup3, *setup4, *setup5, *setup6;

int nPasos = 10, tRetardo = 1, MMmode = 0, posX = 1, posY = 1, tMap = 100, colisiones = 0;

void irAlJuego(int valor);

/*void keyboard(unsigned char key, int x, int y) {
  float a;
  switch(key) {
    case 'w': // UP
      a = monitor.getMapa()->getAngle();
      a = a + 0.01;
      cout << "Y1: " << a << endl;
      monitor.getMapa()->putAngle(a);
      break;

    case 's': // DCHA
      a = monitor.getMapa()->getParamX();
      a = a + 0.01;
      cout << "Y2: " << a << endl;
      monitor.getMapa()->PutParamX(a);
      break;

    case 'a': // IZQDA
      a = monitor.getMapa()->getParamZ();
      a = a + 0.01;
      cout << "Y3: " << a << endl;
      monitor.getMapa()->PutParamZ(a);
      break;

    case 'd': // IZQDA
      a = monitor.getMapa()->getParamZ();
      a = a - 0.01;
      cout << "Y3: " << a << endl;
      monitor.getMapa()->PutParamZ(a);
      break;

    default: // Paranoia
      cout << key << " " << "ERROR\n";
      break;
  }
}*/

//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion: nuevo ancho, nuevo alto
//***************************************************************************

void reshape(int ancho, int alto) {
  if((ancho > 1) and (alto > 1)) {
    //parametros de la ventana principal

    float ratio = ((float) ancho * 0.7) / (float) alto;

    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, ancho, alto);
    glLoadIdentity();
    gluOrtho2D(0, ancho, alto, 0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //Display vista principal
    glutSetWindow(vistaPrincipal);
    glutPositionWindow(0, 0);
    glutReshapeWindow(ancho*0.7, alto);
    glutPostRedisplay();

    //Display vista mini-mapa

    glutSetWindow(vistaMiniMapa);
    glutPositionWindow(ancho*0.7, 0);
    glutReshapeWindow( (ancho*0.3) + 1, alto*0.3);
    glutPostRedisplay();

    //Display interfaz
    glutSetWindow(vistaIU);
    glutPositionWindow(ancho*0.7, alto*0.3);
    glutReshapeWindow((ancho*0.3) + 1, (alto*0.7) + 1);
    lineaVacia->set_w((ancho*0.3) + 1);
    lineaVacia->set_h((alto*0.7) + 1);
    glutPostRedisplay();
  }
}

void ResetViewport() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-10.0, 10.0, -10.0, 10.0, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display_ventPrincipal(void) {
    //Background Color
    glClearColor(0.8, 0.8, 0.8, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void display_vistPrincipal() {
    ResetViewport();

    glMatrixMode(GL_PROJECTION);

    if(monitor.getMapa() != 0) {
      float ratio = ((float) IU_ancho_ventana * 0.7) / (float) IU_alto_ventana;
      gluPerspective(45,ratio,1,1000);
      glClearColor(60.0/256.0, 154.0/256.0, 201.0/256.0, 1);
    }
    else{
      glClearColor(0.0, 0.0, 0.0, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
    if(monitor.jugar()) {
      if(monitor.getMapa() != 0) {
        monitor.getMapa()->drawFirstPerson();
      }
    }
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void display_vistMiniMapa() {
    ResetViewport();

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    if(monitor.jugar()/* or monitor.resultadosMostrados()*/) {
      if(MMmode == 1) {
        monitor.getMapa()->drawMM1(posY,posX);
      }
      else{
        monitor.getMapa()->drawMM2(posY,posX);
      }
    }
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void Descomponer(string str, vector<string> & strs) {
    while(str.length() != 0) {
      strs.push_back(str.substr(0, str.find('\n')));
      str = str.substr(str.find('\n')+1, str.length());
    }
}

void display_vistIU() {
    ResetViewport();
    GLUI_Master.auto_set_viewport();
    std::vector<std::string> strs;
    string str;

    if(monitor.jugar() and monitor.numero_entidades() > 0) {
      str = monitor.get_entidad(0)->toString();

      Descomponer(str, strs);

      int i = 0;
      for (vector<string>::const_iterator it = strs.begin(); it != strs.end(); it++) {
          switch (i) {
             case 0: info0->set_text(it->c_str()); break;
             case 1: info1->set_text(it->c_str()); break;
             case 2: info2->set_text(it->c_str()); break;
             case 3: info3->set_text(it->c_str()); break;
             case 4: info4->set_text(it->c_str()); break;
             case 5: info5->set_text(it->c_str()); break;
             case 6: info6->set_text(it->c_str()); break;
             case 7: info7->set_text(it->c_str()); break;
             case 8: info8->set_text(it->c_str()); break;
             case 9: info9->set_text(it->c_str()); break;
          }
          i++;
      }
    }
    glutSwapBuffers();
}

void update(int valor) {
    glutSetWindow(vistaPrincipal);
    glutPostRedisplay();

    glutSetWindow(vistaMiniMapa);
    glutPostRedisplay();

    glutSetWindow(vistaIU);
    glutPostRedisplay();
    //glutKeyboardFunc(keyboard);

    glutTimerFunc(1,irAlJuego,0);
}

void irAlJuego(int valor) {
  if (lanzar_motor_juego(colisiones, -1, editPosX, editPosY)) {
    botonElegirMapa->enable();
    botonPaso->disable();
    botonEjecucion->disable();
    botonEjecutar->disable();
    botonSalir->disable();
    editPosX->disable();
    editPosY->disable();
    editTextPasos->disable();
    editTextRetardo->disable();
    botonSalir->enable();
    colisiones = 0;
  }
  //glutKeyboardFunc(keyboard);
  glutTimerFunc(1, update, 0);
}

void botonCancelarNuevoMapaCB(int valor) {
    panelSelecMapa->close();

    botonElegirMapa->enable();
    botonSalir->enable();
}


void botonAceptarNuevoMapaCB(int valor) {
  panelSelecMapa->close();

  botonElegirMapa->enable();
  drawMM->disable();
  botonPaso->enable();
  botonEjecucion->enable();
  botonEjecutar->enable();
  botonSalir->enable();
  editPosX->enable();
  editPosY->enable();
  editTextPasos->enable();
  editTextRetardo->enable();

  int item = listbox->get_int_val();

  if (item > 0) {
    char path[255];
    strcpy(path, "./mapas/");
    const char * file = listbox->curr_text.c_str();
    monitor.setMapa(strcat(path,file));

    int nivel = group->get_int_val();

    monitor.startGame(nivel+1);
    if (monitor.inicializarJuego()) {
      monitor.inicializar();
      tMap = monitor.juegoInicializado();
      if (nivel+1 == 4) {
        MMmode = 0;
        drawMM->set_int_val(0);
        drawMM->enable();
      }
    }
  }
  else {
    cout << "No se puede leer el fichero..." << endl;
  }
}

vector<string> getFilesList(string name, string extension) {
    vector<string> v;

    DIR* dirp = opendir(name.c_str());
    struct dirent * dp = readdir(dirp);
    while (dp) {
        string fname(dp->d_name);
        if (fname.find(extension, 0) < fname.size()) {
           v.push_back(fname);
        }
	dp = readdir(dirp);
    }
    closedir(dirp);

    return v;
}


void botonConfigurarSimOK(int valor) {
  srand(setup1->get_int_val());
  monitor.inicializar();

  monitor.setObjX(setup4->get_int_val());
  monitor.setObjY(setup5->get_int_val());
  editPosY->set_int_val(setup5->get_int_val());
  editPosX->set_int_val(setup4->get_int_val());
  monitor.get_entidad(0)->setPosicion(setup3->get_int_val(),setup2->get_int_val());
  monitor.get_entidad(0)->setOrientacion(static_cast<Orientacion>(setup6->get_int_val()));


  panelSelecMapaConfig->close();
}


void botonConfigurarSimCANCEL(int valor) {
  panelSelecMapaConfig->close();
}



void botonConfigurarNuevoMapaCB(int valor){
  /* LLamada para cargar el mapa */
  panelSelecMapa->close();

  botonElegirMapa->enable();
  drawMM->disable();
  botonPaso->enable();
  botonEjecucion->enable();
  botonEjecutar->enable();
  botonSalir->enable();
  editPosX->enable();
  editPosY->enable();
  editTextPasos->enable();
  editTextRetardo->enable();

  int item = listbox->get_int_val();

  if (item > 0) {
    char path[255];
    strcpy(path, "./mapas/");
    const char * file = listbox->curr_text.c_str();
    monitor.setMapa(strcat(path,file));

    int nivel = group->get_int_val();

    monitor.startGame(nivel+1);
    if (monitor.inicializarJuego()) {
      monitor.inicializar();
      tMap = monitor.juegoInicializado();
      if (nivel+1 == 4) {
        MMmode = 0;
        drawMM->set_int_val(0);
        drawMM->enable();
      }
    }
  }
  else {
    cout << "No se puede leer el fichero..." << endl;
  }

  /* Paso las variables de monitor a variables locales a este metodo */
  int semilla = 1;

  int ObjX = monitor.getObjX();
  int ObjY = monitor.getObjY();
  int posX = monitor.get_entidad(0)->getX();
  int posY = monitor.get_entidad(0)->getY();
  int orienta = monitor.get_entidad(0)->getOrientacion();
  // posY and posX estan definidas en este fichero


  panelSelecMapaConfig = GLUI_Master.create_glui("Configurar Mapa");



  int num_filas = monitor.getMapa()->getNFils();
  int num_col = monitor.getMapa()->getNCols();


  GLUI_Panel *obj_panel = panelSelecMapaConfig->add_panel("Setup");
  setup1 = panelSelecMapaConfig->add_spinner_to_panel(obj_panel, "                Semilla ", GLUI_SPINNER_INT, &semilla);
  setup3 = panelSelecMapaConfig->add_spinner_to_panel(obj_panel, "           Origen Fila ", GLUI_SPINNER_INT, &posX);
  setup3->set_int_limits(0,num_filas,GLUI_LIMIT_WRAP);
  setup2 = panelSelecMapaConfig->add_spinner_to_panel(obj_panel, "    Origen Columna ", GLUI_SPINNER_INT, &posY);
  setup2->set_int_limits(0,num_col,GLUI_LIMIT_WRAP);
  setup6 = panelSelecMapaConfig->add_spinner_to_panel(obj_panel, " Orientacion Robot ", GLUI_SPINNER_INT, &orienta);
  setup6->set_int_limits(0,4,GLUI_LIMIT_WRAP);
  setup5 = panelSelecMapaConfig->add_spinner_to_panel(obj_panel, "          Destino Fila ", GLUI_SPINNER_INT, &ObjY);
  setup5->set_int_limits(0,num_filas,GLUI_LIMIT_WRAP);
  setup4 = panelSelecMapaConfig->add_spinner_to_panel(obj_panel, "   Destino Columna ", GLUI_SPINNER_INT, &ObjX);
  setup4->set_int_limits(0,num_col,GLUI_LIMIT_WRAP);

  panelSelecMapaConfig->add_button("Ok", 1, botonConfigurarSimOK);
  panelSelecMapaConfig->add_button("Cancel", 1, botonConfigurarSimCANCEL);

}



void botonElegirMapaCB(int valor) {
    panelSelecMapa = GLUI_Master.create_glui("Nuevo Juego");

    botonElegirMapa->disable();
    botonPaso->disable();
    botonEjecucion->disable();
    botonEjecutar->disable();
    botonSalir->disable();
    editPosX->disable();
    editPosY->disable();
    editTextPasos->disable();
    editTextRetardo->disable();

    listbox = panelSelecMapa->add_listbox("Mapas");

    int i = 1;
    vector<string> filesPaths = getFilesList("mapas/", ".map");
    vector<string>::const_iterator it = filesPaths.begin();
    while (it != filesPaths.end()) {
      listbox->add_item(i++, (*it).c_str());
      it++;
    }

    GLUI_Panel *obj_panel = panelSelecMapa->add_panel("Nivel");
    group = panelSelecMapa->add_radiogroup_to_panel(obj_panel);
    panelSelecMapa->add_radiobutton_to_group(group, "Nivel 1, Comportamiento 1: Profundidad");
    panelSelecMapa->add_radiobutton_to_group(group, "Nivel 1, Comportamiento 2: Anchura");
    panelSelecMapa->add_radiobutton_to_group(group, "Nivel 1, Comportamiento 3: Coste Uniforme");
    panelSelecMapa->add_radiobutton_to_group(group, "Nivel 2, Comportamiento 4: Reto");

    panelSelecMapa->add_button("Ok", 1, botonAceptarNuevoMapaCB);
    panelSelecMapa->add_button("Ok y Configurar", 2, botonConfigurarNuevoMapaCB);
    panelSelecMapa->add_button("Salir", 3, botonCancelarNuevoMapaCB);
}


void botonPasoCB(int valor) {
  monitor.setPasos(1);
}

void botonEjecucionCB(int valor) {
  monitor.setPasos(3000);
}

void botonEjecutarCB(int valor) {
  monitor.setPasos(nPasos);
}

void setRetardo(int valor) {
  monitor.setRetardo(tRetardo);
}

void setPosX(int valor) {
  monitor.setObjX(posX);
}

void setPosY(int valor) {
  monitor.setObjY(posY);
}

void botonSalirCB(int valor) {
  monitor.cerrarBelkan();
  exit(0);
}

void mouseClick(int button, int state, int x, int y) {
  int tx, ty, tw, th;
  GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
  int nx = round(x * tMap * 1.0 / tw);
  int ny = round(y * tMap * 1.0 / th);

  if ((button == GLUT_LEFT_BUTTON) and (state == GLUT_DOWN)) {
    if ((nx >= 0) and (nx <= tMap-1) and (ny >= 0) and (ny <= tMap-1)) {
    editPosY->set_int_val(ny);
    editPosX->set_int_val(nx);
    setPosY(ny);
    setPosX(nx);
  }
}
}

void lanzar_motor_grafico(int argc, char **argv) {
    glutInit(&argc, argv);
    //Mode Setting
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    //window size (+gap size)
    glutInitWindowSize(IU_ancho_ventana, IU_alto_ventana);
    float ratio = ((float) IU_ancho_ventana * 0.7) / (float) IU_alto_ventana;
    //Initial position
    glutInitWindowPosition(300, 0);

    //Main Window
    ventanaPrincipal = glutCreateWindow("Practica 2");
    //Main Window callback function
    glutReshapeFunc(reshape);
    glutDisplayFunc(display_ventPrincipal);

    //World Window and Display
    vistaPrincipal = glutCreateSubWindow(ventanaPrincipal, 0, 0, IU_ancho_ventana*0.7, IU_alto_ventana);
    glutDisplayFunc(display_vistMiniMapa);
    glutMouseFunc(mouseClick);
    //glutKeyboardFunc(keyboard);

    //screen Window and Display
    vistaMiniMapa = glutCreateSubWindow(ventanaPrincipal, IU_ancho_ventana*0.7, 0, (IU_ancho_ventana*0.3) + 1, IU_alto_ventana*0.3);
    glutDisplayFunc(display_vistPrincipal);

    vistaIU = glutCreateSubWindow(ventanaPrincipal, IU_ancho_ventana*0.7, IU_alto_ventana*0.3, (IU_ancho_ventana*0.3) + 1, (IU_alto_ventana*0.7) + 1);
    glutDisplayFunc(display_vistIU);

    glutInitWindowPosition(IU_ancho_ventana*0.7,50);
    glutInitWindowSize(50, 50);

    GLUI * panelIU = GLUI_Master.create_glui_subwindow(vistaIU, GLUI_SUBWINDOW_TOP);
    panelIU->set_main_gfx_window(vistaIU);

    botonElegirMapa = panelIU->add_button("Nuevo Juego", 0, botonElegirMapaCB);
    botonElegirMapa->set_alignment(GLUI_ALIGN_CENTER);

    MMmode = 1;
    drawMM = panelIU->add_checkbox("Mostrar mapa", &MMmode);
    drawMM->set_alignment(GLUI_ALIGN_CENTER);
    drawMM->disable();

    lineaVacia = panelIU->add_statictext("");

    GLUI_Panel *obj_panel = panelIU->add_panel("Ir a...");
    posX = 3;
    posY = 3;
    editPosY = panelIU->add_edittext_to_panel(obj_panel, "Fila", GLUI_EDITTEXT_INT, &posY, -1, setPosY);
    editPosX = panelIU->add_edittext_to_panel(obj_panel, "Columna", GLUI_EDITTEXT_INT, &posX, -1, setPosX);
    setPosX(posX);
    setPosY(posY);
    editPosX->set_int_limits(0, 100, GLUI_LIMIT_CLAMP);
    editPosY->set_int_limits(0, 100, GLUI_LIMIT_CLAMP);
    editPosX->set_alignment(GLUI_ALIGN_CENTER);
    editPosY->set_alignment(GLUI_ALIGN_CENTER);

    //lineaVacia = panelIU->add_statictext("");

    GLUI_Panel *run_panel = panelIU->add_panel("Control");

    editTextPasos = panelIU->add_edittext_to_panel(run_panel, "Pasos", GLUI_EDITTEXT_INT, &nPasos);
    editTextPasos->set_int_val(nPasos);
    editTextPasos->set_int_limits(1, 10000000, GLUI_LIMIT_CLAMP);
    editTextPasos->set_alignment(GLUI_ALIGN_CENTER);

    editTextRetardo = panelIU->add_edittext_to_panel(run_panel, "Retardo", GLUI_EDITTEXT_INT, &tRetardo, -1, setRetardo);
    editTextRetardo->set_int_val(tRetardo);
    editTextRetardo->set_int_limits(0, 10000000, GLUI_LIMIT_CLAMP);
    editTextRetardo->set_alignment(GLUI_ALIGN_CENTER);
    setRetardo(tRetardo);

    //lineaVacia = panelIU->add_statictext_to_panel(run_panel, "");

    botonPaso = panelIU->add_button_to_panel(run_panel, "Paso", 0, botonPasoCB);
    botonPaso->set_alignment(GLUI_ALIGN_CENTER);
    botonEjecutar = panelIU->add_button_to_panel(run_panel, "Ciclo", 0, botonEjecutarCB);
    botonEjecutar->set_alignment(GLUI_ALIGN_CENTER);
    botonEjecucion = panelIU->add_button_to_panel(run_panel, "Ejecucion", 0, botonEjecucionCB);
    botonEjecucion->set_alignment(GLUI_ALIGN_CENTER);

    lineaVacia = panelIU->add_statictext("");

    botonSalir = panelIU->add_button("Salir", 0, botonSalirCB);
    botonSalir->set_alignment(GLUI_ALIGN_CENTER);

    lineaVacia = panelIU->add_statictext("");

    GLUI_Panel * panelInfo = panelIU->add_panel("Informacion");
    panelInfo->set_alignment(GLUI_ALIGN_CENTER);

    info0 = panelIU->add_statictext_to_panel(panelInfo, "              No hay informacion disponible           ");
    info1 = panelIU->add_statictext_to_panel(panelInfo, "");
    info2 = panelIU->add_statictext_to_panel(panelInfo, "");
    info3 = panelIU->add_statictext_to_panel(panelInfo, "");
    info4 = panelIU->add_statictext_to_panel(panelInfo, "");
    info5 = panelIU->add_statictext_to_panel(panelInfo, "");
    info6 = panelIU->add_statictext_to_panel(panelInfo, "");
    info6->set_font(GLUT_BITMAP_8_BY_13);
    info7 = panelIU->add_statictext_to_panel(panelInfo, "");
    info7->set_font(GLUT_BITMAP_8_BY_13);
    info8 = panelIU->add_statictext_to_panel(panelInfo, "");
    info8->set_font(GLUT_BITMAP_8_BY_13);
    info9 = panelIU->add_statictext_to_panel(panelInfo, "");
    info9->set_font(GLUT_BITMAP_8_BY_13);

    //panelIU->add_separator_to_panel(panelInfo);

    lineaVacia = panelIU->add_statictext("");

    glutTimerFunc(100,update,0);

    botonPaso->disable();
    botonEjecucion->disable();
    botonEjecutar->disable();
    editPosX->disable();
    editPosY->disable();
    editTextPasos->disable();
    editTextRetardo->disable();

    glutMainLoop();
}
