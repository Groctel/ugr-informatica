#include "motorlib/monitor.hpp"

#include <fstream>

void MonitorJuego::cambiarOrientacion(unsigned char entidad, unsigned char orientacion) {
  Orientacion aux;
  switch (orientacion) {
    case 0:
    	aux = norte;
    	break;

    case 1:
    	aux = este;
    	break;

    case 2:
    	aux = sur;
    	break;

    case 3:
    	aux = oeste;
    	break;
  }
  entidades[entidad]->setOrientacion(aux);
}

void MonitorJuego::setMapa(char * file) {
  ifstream ifile;
  ifile.open(file, ios::in);

  unsigned int colSize, filSize;
  ifile >> colSize;
  ifile >> filSize;

  vector<vector<unsigned char> > mapAux;
  vector<unsigned char> colAux(colSize);

  for (unsigned int i = 0; i < filSize; i++) {
    mapAux.push_back(colAux);
  }

  for (unsigned int i = 0; i < filSize; i++) {
    for (unsigned int j = 0; j < colSize; j++) {
      ifile >> mapAux[i][j];
    }
  }
  ifile.close();

  mapa = new Mapa(mapAux, &entidades);
}

bool MonitorJuego::inicializarJuego() {
  bool aux = empezarJuego;
  if (empezarJuego) {
      empezarJuego = false;
      resultados = false;
  }
  return aux;
}


void MonitorJuego::decPasos(GLUI_EditText * editPosX, GLUI_EditText * editPosY) {
  if (get_entidad(0)->fin()) {
    if (nivel < 4) {
      jugando = false;
      resultados = true;
    }
    else {
      // Nivel 4
      if (!get_entidad(0)->vivo()
           or get_entidad(0)->getBateria() == 0
           or get_entidad(0)->getTiempo() > get_entidad(0)->getTiempoMaximo()) {
        jugando = false;
        resultados = true;
      }
      else {
        // Nuevo destino
        if (objetivos.empty()) {
          int mix = -1, miy = -1;
          char celdaRand = '_';
          do {
            miy = aleatorio(getMapa()->getNFils()-1);
            mix = aleatorio(getMapa()->getNCols()-1);

            celdaRand = getMapa()->getCelda(miy, mix);
          }
          while( (celdaRand == 'P' or celdaRand == 'M') );

          setObjX(mix);
          setObjY(miy);
          if (editPosX != NULL)
          editPosX->set_int_val(mix);
          if (editPosY != NULL)
          editPosY->set_int_val(miy);
          cout << "Nuevo objetivo: (" << miy << "," << mix << ")" << endl;
          get_entidad(0)->resetFin();

          if (pasos > 0) {
            pasos--;
            pasosTotales++;
          }

        }
        else {
          pair<int,int> aqui = objetivos.front();
          objetivos.pop_front();
          setObjX(aqui.second);
          setObjY(aqui.first);
          if (editPosX != NULL)
          editPosX->set_int_val(aqui.second);
          if (editPosY != NULL)
          editPosY->set_int_val(aqui.first);
          cout << "Nuevo objetivo de la lista: (" << aqui.second << "," << aqui.first << ")" << endl;
          get_entidad(0)->resetFin();

          if (pasos > 0) {
            pasos--;
            pasosTotales++;
          }

        }
      }
    }
  }
  else {
    if (pasos > 0) {
      pasos--;
      pasosTotales++;
    }

    if (!get_entidad(0)->vivo() or get_entidad(0)->getBateria() == 0) {
      jugando = false;
      resultados = true;
    }
  }
}

void MonitorJuego::setObjX(int valor) {
	objX = valor;
	if (jugar()) {
		get_entidad(0)->setObjetivo(objX, objY);
	}
}

void MonitorJuego::setObjY(int valor) {
	objY = valor;
	if (jugar()) {
		get_entidad(0)->setObjetivo(objX, objY);
	}
}

void MonitorJuego::inicializar(int mix, int miy, int seed) {
  clear();
  srand(seed);
  int tama = getMapa()->getNCols();

  int naldeanos = tama / 10;
  unsigned char celdaRand;
  int bruj;

  //Se construye una lisa con 200 objetivos
  if (nivel == 4) {
    int ox, oy;
    for (int i=0; i<200; i++) {
      do {
        ox = aleatorio(getMapa()->getNFils()-1);
        oy = aleatorio(getMapa()->getNCols()-1);
        celdaRand = getMapa()->getCelda(ox, oy);
      }
      while( (celdaRand == 'P') or (celdaRand == 'M') );
      pair<int,int> punto;
      punto.first = oy;
      punto.second = ox;
      objetivos.push_back(punto);
    }
  }

  //Primero SIEMPRE se coloca al jugador. SIEMPRE.
  if ((mix == -1) or (miy == -1)) {
    do {
      mix = aleatorio(getMapa()->getNFils()-1);
      miy = aleatorio(getMapa()->getNCols()-1);
      celdaRand = getMapa()->getCelda(mix, miy);
    }
    while( (celdaRand == 'P') or (celdaRand == 'M') or (getMapa()->entidadEnCelda(mix, miy) != '_') );
  }
  else {
    // para hacer que la secuencia de recogida de numeros aleatorios sea independiente si da o no las coordenadas al principio
    int kkx = aleatorio(getMapa()->getNFils()-1);
    int kky = aleatorio(getMapa()->getNCols()-1);

  }

  // Para los primeros niveles hago el mapa visible
  if ((nivel == 1) or (nivel == 2) or (nivel == 3)) {
    vector< vector< unsigned char> > mAux(getMapa()->getNFils(), vector< unsigned char>(getMapa()->getNCols(), '?'));
    for (int i = 0; i < getMapa()->getNFils(); i++)
      for (int j = 0; j < getMapa()->getNCols(); j++)
        mAux[i][j] = getMapa()->getCelda(i, j);
    // Esto coloca al jugador en el mapa
    bruj = rand() % 4;
    nueva_entidad(new Entidad(jugador, jugador_,static_cast<Orientacion>(bruj), mix, miy, new Jugador3D(""), new ComportamientoJugador(mAux), objX, objY, 3000));
  }
  else {
    // Esto coloca al jugador en el mapa
    bruj = rand() % 4;
    nueva_entidad(new Entidad(jugador, jugador_, static_cast<Orientacion>(bruj), mix, miy, new Jugador3D(""), new ComportamientoJugador(getMapa()->getNFils()), objX, objY, 3000));
  }

  // Para el último nivel genero los aldeanos
  if (nivel == 4) {
    for (int i=0; i<naldeanos; i++) {
      do {
        mix = aleatorio(getMapa()->getNFils()-1);
        miy = aleatorio(getMapa()->getNCols()-1);
        celdaRand = getMapa()->getCelda(mix, miy);
      }
      while( (celdaRand == 'P') or (celdaRand == 'M') or (getMapa()->entidadEnCelda(mix, miy) != '_') );
      nueva_entidad(new Entidad(npc, aldeano, norte, mix, miy, new Aldeano3D(""), new ComportamientoAldeano()));
    }
  }

  get_entidad(0)->setVision(getMapa()->vision(0));
  if ((nivel == 1) or (nivel == 2) or (nivel == 3))
    get_entidad(0)->notify();

  srand(seed);
  /* quitar esto una vez verificado */
  //PintaEstadoMonitor();

}



void MonitorJuego::PintaEstadoMonitor(){
  cout << "*********************************************\n";
  cout << "Pos X: " << get_entidad(0)->getX() <<endl;
  cout << "Pos y: " << get_entidad(0)->getY() <<endl;
  cout << "Brujula: " << get_entidad(0)->getOrientacion() <<endl;
  cout << "Obj X: " << get_entidad(0)->getObjX() <<endl;
  cout << "Obj Y: " << get_entidad(0)->getObjY() <<endl;
  cout << "aldeanos: " << numero_entidades() << endl;
  for (int i=1; i<numero_entidades(); i++){
    cout << "  Pos X: " << get_entidad(i)->getX() <<endl;
    cout << "  Pos y: " << get_entidad(i)->getY() <<endl;
    cout << "  Brujula: " << get_entidad(i)->getOrientacion() <<endl << endl;
  }
  cout << "*********************************************\n";
}
