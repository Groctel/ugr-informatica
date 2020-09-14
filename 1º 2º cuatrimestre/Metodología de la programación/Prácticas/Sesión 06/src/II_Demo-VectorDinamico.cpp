#include <iostream>
#include "VectorDinamico.h"
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

   TipoBase elemento;
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

   VectorDinamico vector = CreaVectorDinamico(TAM_INICIAL, tipo_redimension);

   //*************************************************************************//
   //  INTRODUCCIÓN DE ELEMENTOS EN EL VECTOR
   //*************************************************************************//

   cout << "Introduzca números enteros positivos en el siguiente vector. "
        << "Finalice la secuencia con un número menor que 0." << endl << endl;

   while (bucle) {
      if (vector.usados == vector.capacidad)
         RedimensionaVectorDinamico(vector);

      cout << "Posición " << vector.usados << ":  ";
      cin >> elemento;

      bucle = elemento != TERMINADOR;

      if (bucle) {
         AniadeVectorDinamico(vector, elemento);
      }
   }

   //*************************************************************************//
   //  MUESTRA DEL RESULTADO FINAL DEL VECTOR
   //*************************************************************************//

   cout << "\nIntroducción del vector finalizada correctamente. Resultados:\n"
        << " - CAPACIDAD DEL VECTOR:    " << UsadosVectorDinamico(vector)
        << endl << " - ELEMENTOS INTRODUCIDOS:  "
        << CapacidadVectorDinamico(vector) << endl << endl << "Resultado final:"
        << endl;

   ReajustaVectorDinamico(vector);

   cout << "\nReajuste del vector finalizada correctamente. Resultados:\n"
        << " - CAPACIDAD DEL VECTOR:    " << UsadosVectorDinamico(vector)
        << endl << " - ELEMENTOS INTRODUCIDOS:  "
        << CapacidadVectorDinamico(vector) << endl << endl << "Resultado final:"
        << endl;

   MuestraVectorDinamico(vector);
   LiberaVectorDinamico(vector);

   return 0;
}
