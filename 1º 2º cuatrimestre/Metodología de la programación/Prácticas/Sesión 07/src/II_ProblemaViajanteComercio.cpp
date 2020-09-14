#include <iostream>
#include <cctype>
#include "ProblemaViajanteComercio.h"
using namespace std;

int main(int argc, char *argv[]) {
   Matriz2D ciudades;
   bool menu = true;
   int opcion_menu;

   cout << endl
        << "#########################################" << endl
        << "##                                     ##" << endl
        << "##  PROBLEMA DEL VIAJANTE DE COMERCIO  ##" << endl
        << "##                                     ##" << endl
        << "#########################################" << endl << endl;

   if (argc == 1) {
      PrintAyuda();
      return 0;
   }
   else if (argc == 2) {
      if (atoi(argv[1]) > 0) {
         ciudades = CreaYRellenaMatriz2D(atoi(argv[1]), atoi(argv[1]));
      }
      else {
         PrintAyuda();
         return 0;
      }
   }
   else {
      PrintAyuda();
      return 0;
   }

   while(menu) {
      cout << "\nIndique la acción a realizar:" << endl
           << " [1]: Mostrar la matriz de ciudades." << endl
           << " [2]: Mostrar un elemento de la matriz de trabajo." << endl
           << " [0]: Salir del programa." << endl
           << "> ";

      cin >> opcion_menu;

      if (opcion_menu == 1) {
         MuestraMatriz2D(ciudades);
      }
      else if (opcion_menu == 2) {
         Resolucion(ciudades);
      }
      else if (opcion_menu == 0) {
         cout << "\nFinalizando ejecución..." << endl;
      }
      else {
         cout << "\nIntroduzca una opción válida." << endl;
      }

      menu = !(opcion_menu == 0);
   }


   EliminaMatriz2D(ciudades);

   return 0;
}
