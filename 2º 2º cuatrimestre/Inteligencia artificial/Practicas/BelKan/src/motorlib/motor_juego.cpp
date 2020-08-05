#include "motorlib.hpp"

#include <unistd.h>

extern MonitorJuego monitor;

bool actuacionJugador(unsigned char celda_inicial, unsigned char celda_fin, Action accion, unsigned int x, unsigned int y) {
  unsigned int mix, miy;
  unsigned char celdaRand;
  bool salida = false;

  if (accion != actIDLE){
    int gasto = monitor.get_entidad(0)->fixBateria_sig_accion(celda_inicial);
    if (gasto > monitor.get_entidad(0)->getBateria()){
      monitor.get_entidad(0)->setBateria(0);
      return false;
    }
  }

  monitor.get_entidad(0)->fixBateria_default();
  switch (accion) {
    case actFORWARD:
      if (monitor.getMapa()->casillaOcupada(0) == -1) {
        switch (celda_fin) {
          case 'M': // Muro
                monitor.get_entidad(0)->seAostio(); break;
                break;
          case 'P': // Precipicio
                  cout << "Se cayo por un precipicio\n";
                  do {
                    mix = aleatorio(monitor.getMapa()->getNFils()-1);
                    miy = aleatorio(monitor.getMapa()->getNCols()-1);

                    celdaRand = monitor.getMapa()->getCelda(mix, miy);
                  }
                  while(celdaRand == 'P' or celdaRand == 'M' or monitor.getMapa()->entidadEnCelda(mix, miy) == '_' );

                  monitor.get_entidad(0)->setPosicion(mix,miy);
                  monitor.get_entidad(0)->setOrientacion(norte);
                  monitor.get_entidad(0)->resetEntidad();
                  monitor.get_entidad(0)->setHitbox(true);
                  monitor.finalizarJuego();
                  monitor.setMostrarResultados(true);

                  break;
          case 'X': // Casilla Rosa (Recarga)
                  monitor.get_entidad(0)->increaseBateria(10);
                  monitor.get_entidad(0)->setPosicion(x,y);
                  salida = true;
                  break;
          case 'D': // Casilla Morada (Zapatillas)
                  if (!monitor.get_entidad(0)->Has_Zapatillas()){
                    monitor.get_entidad(0)->Cogio_Zapatillas(true);
                  }
                  monitor.get_entidad(0)->setPosicion(x,y);
                  salida = true;
                  break;
          case 'K': // Casilla Amarilla (Bikini)
                  if (!monitor.get_entidad(0)->Has_Bikini()){
                    monitor.get_entidad(0)->Cogio_Bikini(true);
                  }
                  monitor.get_entidad(0)->setPosicion(x,y);
                  salida = true;
                  break;
          case 'B': // Arbol
          case 'A': // Agua
          default:
            monitor.get_entidad(0)->setPosicion(x,y);
            salida = true;
            break;
        }
        monitor.get_entidad(0)->fixBateria_sig_accion(celda_inicial);
      }
      else{
        monitor.get_entidad(0)->seAostio();
        /*if (monitor.get_entidad(monitor.getMapa()->casillaOcupada(0))->getSubTipo() == aldeano) {
            monitor.get_entidad(0)->perderPV(1);
        }*/
        salida = false;
      }
    break;

    case actTURN_R:
      if (celda_inicial =='X'){ // Casilla Rosa (Recarga)
          monitor.get_entidad(0)->increaseBateria(10);
        }

      switch (monitor.get_entidad(0)->getOrientacion()) {
        case norte:
          monitor.get_entidad(0)->setOrientacion(este);
        break;

        case este:
          monitor.get_entidad(0)->setOrientacion(sur);
        break;

        case sur:
          monitor.get_entidad(0)->setOrientacion(oeste);
        break;

        case oeste:
          monitor.get_entidad(0)->setOrientacion(norte);
        break;
      }
      monitor.girarJugadorDerecha();
      salida = true;
      monitor.get_entidad(0)->fixBateria_sig_accion(celda_inicial);
    break;

    case actTURN_L:
      if (celda_inicial =='X'){ // Casilla Rosa (Recarga)
        monitor.get_entidad(0)->increaseBateria(10);
      }

      switch (monitor.get_entidad(0)->getOrientacion()) {
        case norte:
          monitor.get_entidad(0)->setOrientacion(oeste);
        break;

        case este:
          monitor.get_entidad(0)->setOrientacion(norte);
        break;

        case sur:
          monitor.get_entidad(0)->setOrientacion(este);
        break;

        case oeste:
          monitor.get_entidad(0)->setOrientacion(sur);
        break;
        }
        monitor.get_entidad(0)->fixBateria_sig_accion(celda_inicial);
        monitor.girarJugadorIzquierda();
        salida = true;
    break;

    case actIDLE:
      if (celda_inicial =='X'){ // Casilla Rosa (Recarga)
        monitor.get_entidad(0)->increaseBateria(10);
      }

      salida = true;
    break;
  }

  return salida;
}

bool actuacionNPC(unsigned int entidad, unsigned char celda, Action accion, unsigned int x, unsigned int y) {
  bool out = false;
  switch (monitor.get_entidad(entidad)->getSubTipo()) {
      case aldeano: //Acciones para el aldeano
        switch (accion) {
          case actFORWARD:
           if ((celda != 'P' and celda != 'M') and monitor.getMapa()->casillaOcupada(entidad) == -1) {
             monitor.get_entidad(entidad)->setPosicion(x,y);
             out = true;
           }
           break;

          case actTURN_R:
            switch (monitor.get_entidad(entidad)->getOrientacion()) {
              case norte:
                monitor.get_entidad(entidad)->setOrientacion(este);
                break;

              case este:
                monitor.get_entidad(entidad)->setOrientacion(sur);
                break;

              case sur:
                monitor.get_entidad(entidad)->setOrientacion(oeste);
                break;

              case oeste:
                monitor.get_entidad(entidad)->setOrientacion(norte);
                break;
            }
            out = true;
            break;

          case actTURN_L:
            switch (monitor.get_entidad(entidad)->getOrientacion()) {
              case norte:
                monitor.get_entidad(entidad)->setOrientacion(oeste);
                break;

              case este:
                monitor.get_entidad(entidad)->setOrientacion(norte);
                break;

              case sur:
                monitor.get_entidad(entidad)->setOrientacion(este);
                break;

              case oeste:
                monitor.get_entidad(entidad)->setOrientacion(sur);
                break;
            }
            out = true;
            break;
        }
  }
  return out;
}

bool actuacion(unsigned int entidad, Action accion) {
  bool out = false;
  unsigned char celda_inicial, celda_fin, objetivo;
  unsigned int x,y;

  x = monitor.get_entidad(entidad)->getX();
  y = monitor.get_entidad(entidad)->getY();


  celda_inicial = monitor.getMapa()->getCelda(x,y);
  //Calculamos cual es la celda justo frente a la entidad
  switch (monitor.get_entidad(entidad)->getOrientacion()) {
    case norte:
      x = x - 1;
      y = y;
    break;

    case sur:
      x = x + 1;
      y = y;
    break;

    case este:
      x = x;
      y = y + 1;
    break;

    case oeste:
      x = x;
      y = y - 1;
    break;
  }

  celda_fin = monitor.getMapa()->getCelda(x,y);

  //Dependiendo el tipo de la entidad actuamos de una forma u otra
  switch (monitor.get_entidad(entidad)->getTipo()) {
    case jugador:
      out = actuacionJugador(celda_inicial, celda_fin, accion,  x, y);
    break;

    case npc:
      out = actuacionNPC(entidad, celda_fin, accion, x, y);
    break;
  }

  return out;
}

void nucleo_motor_juego(MonitorJuego &monitor, int acc, GLUI_EditText * editPosX, GLUI_EditText * editPosY) {
  Action accion;
  unsigned char celdaRand;

  vector < vector < vector <unsigned char> > > estado;

  estado.clear();

  for(unsigned int i = 0; i < monitor.numero_entidades(); i++) {
    estado.push_back(monitor.getMapa()->vision(i));
  }

  if (monitor.get_entidad(0)->ready()){
    clock_t t0 = clock();
    accion = monitor.get_entidad(0)->think(acc, estado[0], monitor.getLevel());
    clock_t t1 = clock();

    monitor.get_entidad(0)->addTiempo(t1-t0);
    monitor.get_entidad(0)->getLastAction(accion);
    actuacion(0, accion);
    monitor.get_entidad(0)->setVision(monitor.getMapa()->vision(0));
  }
  else {
    monitor.get_entidad(0)->perderPV(1);
  }


  for(unsigned int i = 1; i < monitor.numero_entidades(); i++) {
    clock_t t0 = clock();
    accion = monitor.get_entidad(i)->think(-1, estado[i], monitor.getLevel());
    clock_t t1 = clock();

    monitor.get_entidad(i)->addTiempo(t1-t0);
    actuacion(i, accion);
    monitor.get_entidad(i)->setVision(monitor.getMapa()->vision(i));
  }


  monitor.get_entidad(0)->decBateria_sig_accion();
  monitor.decPasos(editPosX, editPosY);


  if (acc != -1) {
    sleep(monitor.getRetardo() / 10);
  }
}

bool lanzar_motor_juego(int & colisiones, int acc, GLUI_EditText * editPosX, GLUI_EditText * editPosY) {
  bool out = false;

  if (monitor.continuarBelkan()) {
    if (monitor.jugar()) {
      if ((monitor.getPasos() != 0) and (!monitor.finJuego())) {
        unsigned char celdaRand;
        if (monitor.getObjY() >= monitor.getMapa()->getNFils() or monitor.getObjX() >= monitor.getMapa()->getNCols()){
          celdaRand = 'P';
        }
        else {
          celdaRand = monitor.getMapa()->getCelda(monitor.getObjY(), monitor.getObjX());
        }

        if (celdaRand == 'P' or celdaRand == 'M'){
          int mix = -1, miy = -1;
          do {
            miy = aleatorio(monitor.getMapa()->getNFils()-1);
            mix = aleatorio(monitor.getMapa()->getNCols()-1);

            celdaRand = monitor.getMapa()->getCelda(miy, mix);
          }
          while( (celdaRand == 'P' or celdaRand == 'M') );

          monitor.setObjX(mix);
          monitor.setObjY(miy);
          if (editPosX != NULL)
          editPosX->set_int_val(mix);
          if (editPosY != NULL)
          editPosY->set_int_val(miy);
          cout << "Cambiado el objetivo\n";
        }
        nucleo_motor_juego(monitor, acc, editPosX, editPosY);
      }
    }

    if (monitor.mostrarResultados()) {
      cout << "Instantes de simulacion no consumidos: " << monitor.get_entidad(0)->getInstantesPendientes() << endl;
      cout << "Tiempo Consumido: " << 1.0 * monitor.get_entidad(0)->getTiempo() / CLOCKS_PER_SEC << endl;
      cout << "Nivel Final de Bateria: " << monitor.get_entidad(0)->getBateria() << endl;
      cout << "Colisiones: " << monitor.get_entidad(0)->getColisiones() << endl;
      cout << "Muertes: " << monitor.get_entidad(0)->getMuertesI() << endl;
      cout << "Objetivos encontrados: " << monitor.get_entidad(0)->getMisiones() << endl;
      monitor.setMostrarResultados(false);

      out = true;
    }
  }
  return out;
}


void lanzar_motor_juego2(MonitorJuego &monitor) {

  monitor.get_entidad(0)->setObjetivo(monitor.getObjX(), monitor.getObjY());

  while (!monitor.finJuego() && monitor.jugar()) {
      nucleo_motor_juego(monitor,-1, NULL, NULL);
  }

  if (monitor.mostrarResultados()) {
    cout << "Instantes de simulacion no consumidos: " << monitor.get_entidad(0)->getInstantesPendientes() << endl;
    cout << "Tiempo Consumido: " << 1.0 * monitor.get_entidad(0)->getTiempo() / CLOCKS_PER_SEC << endl;
    cout << "Nivel Final de Bateria: " << monitor.get_entidad(0)->getBateria() << endl;
    cout << "Colisiones: " << monitor.get_entidad(0)->getColisiones() << endl;
    cout << "Muertes: " << monitor.get_entidad(0)->getMuertesI() << endl;
    cout << "Objetivos encontrados: " << monitor.get_entidad(0)->getMisiones() << endl;
    monitor.setMostrarResultados(false);
  }
}
