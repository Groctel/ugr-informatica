#include <iostream>
#include "VectorDinamico-1.h"
using namespace std;


   //*************************************************************************//
   //  GESTIÓN DE ERRORES
   //*************************************************************************//


void PrintError(int error) {
   if (error == 0) {
      cerr << "Este aviso no debería salir en el programa. Frenando ejecución."
           << endl;
   }
   else if (error == 1) {
      cerr << "Argumento inválido. Introduzca uno de estos tres argumentos:\n"
           << " - 1:   Redimensión unitaria.\n"
           << " - 2:   Redimensión en bloques.\n"
           << " - 3:   Redimensión duplicada.\n"
           << "Introduzca el argumento \"-h\" para más información" << endl;
   }
   else if (error == 2) {
      cerr << "Introduzca sólo un argumento." << endl;
      PrintError(1);
   }
}

   //*************************************************************************//
   //  GESTIÓN DE AVISOS
   //*************************************************************************//

void PrintAviso(int aviso) {
   if (aviso == 0) {
      cerr << "Este aviso no debería salir en el programa, pero no es lo "
           << "suficientemente grave como para frenar su ejecución." << endl;
   }
   else if (aviso == 1) {
      cerr << "Demasiados argumentos. Sólo se tendrá en cuenta el primero."
           << endl;
   }
}

   //*************************************************************************//
   //  MODIFICA EL TAMAÑO DEL VECTOR SEGÚN EL TIPO DE REDIMENSIÓN
   //*************************************************************************//


int * Redimensiona (int *p, TipoRedimension tipo, int &cap) {
   int redimension;

   if (tipo == TipoRedimension::DeUnoEnUno) {
      redimension = cap + 1;
   }
   else if (tipo == TipoRedimension::EnBloques) {
      redimension = cap + TAM_BLOQUE;
   }
   else if (tipo == TipoRedimension::Duplicando) {
      redimension = 2 * cap;
   }

   int * nuevo_vector = new int [redimension];

   for (int i = 0; i < cap; i++){
      nuevo_vector[i] = p[i];
   }

   cap = redimension;
   delete []p;
   return nuevo_vector;
}
