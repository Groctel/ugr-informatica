#include <iostream>
#include "VectorDinamico.h"
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
   //  CREA UN VECTOR DINÁMICO CON UNA CAPACIDAD Y REDIMENSIÓN ESPECÍFICOS
   //*************************************************************************//

VectorDinamico CreaVectorDinamico (int cap_inic, TipoRedimension tipo) {
   VectorDinamico tmp;
   tmp.datos = new TipoBase[cap_inic];
   tmp.capacidad = cap_inic,
   tmp.usados = 0;
   tmp.tipo_redimension = tipo;

   return tmp;
}

   //*************************************************************************//
   //  ELIMINA UN VECTOR DINÁMICO DEL HEAP
   //*************************************************************************//


void LiberaVectorDinamico(VectorDinamico &vector) {
   delete [] vector.datos;
}

   //*************************************************************************//
   //  MUESTRA LOS ESPACIOS USADOS EN EL VECTOR
   //*************************************************************************//

int UsadosVectorDinamico(const VectorDinamico vector) {
   return vector.usados;
}

   //*************************************************************************//
   //  MUESTRA LA CAPACIDAD TOTAL DEL VECTOR
   //*************************************************************************//

int CapacidadVectorDinamico(const VectorDinamico vector) {
   return vector.capacidad;
}

   //*************************************************************************//
   //  MUESTRA UN ELEMENTO EN ESPECÍFICO DEL VECTOR
   //*************************************************************************//


TipoBase ElementoVectorDinamico(const VectorDinamico vector, int num_casilla) {
   return vector.datos[num_casilla];
}

   //*************************************************************************//
   //  MUESTRA EL VECTOR ENTERO
   //*************************************************************************//

void MuestraVectorDinamico(const VectorDinamico vector) {
   for (int i = 0; i < vector.usados; i++) {
      cout << ElementoVectorDinamico(vector, i) << endl;
   }
}

   //*************************************************************************//
   //  INSERTA UN DATO EN EL VECTOR
   //*************************************************************************//

void AniadeVectorDinamico(VectorDinamico &vector, const TipoBase valor) {
   vector.datos[vector.usados] = valor;
   vector.usados++;
}

   //*************************************************************************//
   //  MODIFICA EL TAMAÑO DEL VECTOR SEGÚN EL TIPO DE REDIMENSIÓN
   //*************************************************************************//

void RedimensionaVectorDinamico(VectorDinamico &vector) {
   int redimension;

   if (vector.tipo_redimension == TipoRedimension::DeUnoEnUno) {
      redimension = vector.capacidad + 1;
   }
   else if (vector.tipo_redimension == TipoRedimension::EnBloques) {
      redimension = vector.capacidad + TAM_BLOQUE;
   }
   else if (vector.tipo_redimension == TipoRedimension::Duplicando) {
      redimension = 2 * vector.capacidad;
   }

   TipoBase * nuevo_vector = new TipoBase[redimension];

   for (int i = 0; i < vector.usados; i++) {
      nuevo_vector[i] = vector.datos[i];
   }

   vector.capacidad = redimension;
   delete []vector.datos;
   vector.datos = nuevo_vector;
}

   //*************************************************************************//
   //  MODIFICA EL TAMAÑO DEL VECTOR PARA QUE SU CAPACIDAD SEA IGUAL AL NÚMERO
   //  DE ELEMENTOS QUE CONTIENE
   //*************************************************************************//

void ReajustaVectorDinamico(VectorDinamico &vector) {
   TipoBase * nuevo_vector = new TipoBase[vector.usados];

   for (int i = 0; i < vector.usados; i++) {
      nuevo_vector[i] = vector.datos[i];
   }

   vector.capacidad = vector.usados;
   delete []vector.datos;
   vector.datos = nuevo_vector;
}
