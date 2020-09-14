#include <iostream>
#include "MultiConjunto.h"
#include "SecuenciaEnteros.h"
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

   MultiConjunto multiconjuntoA = CreaMultiConjunto(TAM_INICIAL, tipo_redimension),
                 multiconjuntoA = CreaMultiConjunto(TAM_INICIAL, tipo_redimension);

   //*************************************************************************//
   //  INTRODUCCIÓN DE ELEMENTOS EN LOS MULTICONJUNTOS
   //*************************************************************************//

   cout << "Introduzca números entre 1 y 1000 en el multiconjunto A:"
        << endl << endl;

   while (bucle) {
      cout << "Posición " << multiconjuntoA.usados << ":  ";
      cin >> elemento;

      bucle = TOPE_SUPERIOR <= elemento && elemento <= TOPE_INFERIOR;

      if (bucle) {
         Aniade(multiconjuntoA, elemento);
      }
   }

   cout << "Introduzca números entre 1 y 1000 en el multiconjunto B:"
        << endl << endl;

   while (bucle) {
      cout << "Posición " << multiconjuntoB.usados << ":  ";
      cin >> elemento;

      bucle = TOPE_SUPERIOR <= elemento && elemento <= TOPE_INFERIOR;

      if (bucle) {
         Aniade(multiconjuntoB, elemento);
      }
   }

   //*************************************************************************//
   //  MUESTRA DEL RESULTADO FINAL DE LOS MULTICONJUNTOS
   //*************************************************************************//

   cout << "\nIntroducción del multiconjunto finalizada correctamente. Resultados:\n"
        << " - CAPACIDAD DEL MULTICONJUNTO A:  " << Usados(multiconjuntoA)
        << endl << " - ELEMENTOS INTRODUCIDOS:       "
        << Capacidad(multiconjuntoA) << endl << endl
        << " - CAPACIDAD DEL MULTICONJUNTO B:  " << Usados(multiconjuntoB)
        << endl << " - ELEMENTOS INTRODUCIDOS:       "
        << Capacidad(multiconjuntoB) << endl;

   ReajustaMultiConjunto(multiconjuntoA);
   ReajustaMultiConjunto(multiconjuntoB);

   cout << "\nReajuste del multiconjunto finalizada correctamente. Resultados:\n"
        << " - CAPACIDAD DEL MULTICONJUNTO A:    " << Usados(multiconjuntoA)
        << endl << " - ELEMENTOS INTRODUCIDOS:         "
        << Capacidad(multiconjuntoA) << endl << endl
        << " - CAPACIDAD DEL MULTICONJUNTO B:    " << Usados(multiconjuntoB)
        << endl << " - ELEMENTOS INTRODUCIDOS:         "
        << Capacidad(multiconjuntoB) << endl;


   cout << "\nSoporte del multiconjunto A: " << endl << Soporte(multiconjuntoA)
        << "\nSoporte del multiconjunto A: " << endl << Soporte(multiconjuntoB);
        << "\nUnión: "
   Union(multiconjuntoA, multiconjuntoB);
   Interseccion(multconjuntoA, multiconjuntoB);
   Inclusion(multiconjuntoA, multiconjuntoB);

   return 0;
}
