#include <iostream>
#include "VectorDinamico-1.h"
using namespace std;


int main(int argc, char **argv) {

   //*************************************************************************//
   //  CONTROL DE ERRORES
   //*************************************************************************//

   if (argc == 2 && *argv[1] != '1' && *argv[1] != '2' && *argv[1] != '3') {
      PrintError(1);
      return 1;
   }
   else if (argc > 2) {
      if (*argv[1] == '1' || *argv[1] == '2' || *argv[1] == '3') {
         PrintAviso(1);
      }
      else {
         PrintError(2);
         return 1;
      }
   }

   //*************************************************************************//
   //  DECLARACIÓN DE VARIABLES
   //*************************************************************************//

   int *vector = new int[TAM_INICIAL], capacidad = TAM_INICIAL, util = 0, num;
   TipoRedimension tipo_redimension;
   bool bucle = true;

   //*************************************************************************//
   //  ASIGNACIÓN DEL TIPO DE REDIMENSIÓN
   //*************************************************************************//

   if (argc >= 2) {
      if (*argv[1] == '1') {
         tipo_redimension = TipoRedimension::DeUnoEnUno;
      }
      else if (*argv[1] == '2') {
         tipo_redimension = TipoRedimension::EnBloques;
      }
      else if (*argv[1] == '3') {
         tipo_redimension = TipoRedimension::Duplicando;
      }
      else {
         PrintError(0);
         return 1337;
      }
   }

   //*************************************************************************//
   //  INTRODUCCIÓN DE ELEMENTOS EN EL VECTOR
   //*************************************************************************//

   cout << "Introduzca números enteros positivos en el siguiente vector. "
        << "Finalice la secuencia con un número menor que 0." << endl << endl;

   while (bucle) {
      if (util == capacidad)
         vector = Redimensiona (vector, tipo_redimension, capacidad);

      cout << "Posición " << util << ":  ";
      cin >> num;

      bucle = vector[util] != TERMINADOR;

      if (bucle) {
         vector[util] = num;
         util++;
      }
   }

   //*************************************************************************//
   //  MUESTRA DEL RESULTADO FINAL DEL VECTOR
   //*************************************************************************//

   cout << "\nIntroducción del vector finalizada correctamente. Resultados:\n"
        << " - CAPACIDAD DEL VECTOR:    " << capacidad << endl
        << " - ELEMENTOS INTRODUCIDOS:  " << util << endl << endl
        << "Resultado final:" << endl;

   for (int i = 0; i < util; i++) {
      cout << vector[i] << endl;
   }

   return 0;
}
