#include <iostream>
#include "Matriz2D_1.h"
using namespace std;

int main() {
   Matriz2D matriz, matriz_aux;
   int fil, col, fil_fin, col_fin, opcion_menu;
   TipoBase elemento;
   bool menu1 = true, menu2 = true, error_creacion, pre_salir = false;

   cout << endl
        << "##########################################" << endl
        << "##                                      ##" << endl
        << "##  GESTOR DE MATRICES BIDIMENSIONALES  ##" << endl
        << "##                                      ##" << endl
        << "##########################################" << endl << endl;

   while(menu1) {
      error_creacion = false;
      fil = 0;
      col = 0;

      cout << "Indique la acción a realizar:" << endl
           << " [1]: Crear una nueva matriz." << endl
           << " [2]: Crear una nueva matriz y rellenarla." << endl
           << " [0]: Salir del programa." << endl
           << "> ";

      cin >> opcion_menu;

      if (opcion_menu == 1 || opcion_menu == 2) {
         cout << "Introduzca el número de filas y columnas: ";
         cin >> fil >> col;
      }
      else if (opcion_menu == 0) {
         cout << "\nFinalizando ejecución..." << endl;
         menu2 = false;
         pre_salir = true;
      }
      else {
         cout << "Introduzca una opción válida." << endl;
      }

      if (opcion_menu == 1 || opcion_menu == 2) {
         if (fil <= 0 || col <= 0) {
            PrintAviso(1);
            error_creacion = true;
         }
         else if (fil * col > MAX_TAMANIO) {
            PrintAviso(2);
            error_creacion = true;
         }
         else if (fil * col <= 0) {
            PrintAviso(3);
            error_creacion = true;
         }
      }

      menu1 = error_creacion || (opcion_menu != 1 && opcion_menu != 2
              && opcion_menu != 0);
   }

   if (menu2) {
      if (opcion_menu == 1) {
         matriz = CreaMatriz2D(fil, col);
      }
      else if (opcion_menu == 2) {
         matriz = CreaYRellenaMatriz2D(fil, col);
      }
      matriz_aux = CreaMatriz2D(0, 0);
   }


   while(menu2) {
      cout << "\nIndique la acción a realizar:" << endl
           << " [1]: Mostrar la matriz de trabajo." << endl
           << " [2]: Mostrar un elemento de la matriz de trabajo." << endl
           << " [3]: Modificar un elemento de la matriz de trabajo." << endl
           << " [4]: Duplicar la matriz de trabajo." << endl
           << " [5]: Extraer una submatriz de la matriz de trabajo." << endl
           << " [6]: Eliminar una fila de la matriz de trabajo." << endl
           << " [7]: Eliminar una columna de la matriz de trabajo." << endl
           << " [8]: Trasponer la matriz de trabajo." << endl
           << " [9]: Invertir por filas la matriz de trabajo." << endl
           << " [0]: Salir del programa." << endl
           << "> ";

      cin >> opcion_menu;

      if (opcion_menu == 1) {
         MuestraMatriz2D(matriz);
      }
      else if (opcion_menu == 2) {
         cout << "\nSu matriz contiene " << matriz.fils << " filas, [0,"
              << matriz.fils-1 <<"] y " << matriz.cols << " columnas, [0,"
              << matriz.cols-1 << "]. Indique la fila y columna del elemento "
              << "que desea mostrar: ";
         cin >> fil >> col;

         if (fil < 0 || col < 0) {
            PrintAviso(4);
         }
         else if (fil >= matriz.fils || col >= matriz.cols) {
            PrintAviso(5);
         }
         else {
            cout << "\nEl elemento [" << fil << "," << col << "] vale " <<
            ElementoMatriz2D(matriz, fil, col) << "." << endl;
         }
      }
      else if (opcion_menu == 3) {
         cout << "\nSu matriz contiene " << matriz.fils << " filas, [0,"
              << matriz.fils-1 <<"] y " << matriz.cols << " columnas, [0,"
              << matriz.cols-1 << "]. Indique la fila y columna del elemento "
              << "que desea modificar: ";
         cin >> fil >> col;

         cout << "\nEl elemento [" << fil << "][" << col << "] vale "
              << ElementoMatriz2D(matriz, fil, col) << ". Indique el nuevo "
              << " valor del elemento: ";
         cin >> elemento;

         if (fil < 0 || col < 0) {
            PrintAviso(4);
         }
         else if (fil >= matriz.fils || col >= matriz.cols) {
            PrintAviso(5);
         }
         else {
            ModificaElementoMatriz2D(matriz, fil, col, elemento);
         }

         cout << "\nMatriz de trabajo modificada. El elemento [" << fil << "]["
              << col << "] ahora vale " << ElementoMatriz2D(matriz, fil, col)
              << endl;
      }
      else if (opcion_menu == 4) {
         EliminaMatriz2D(matriz_aux);
         matriz_aux = CopiaMatriz2D(matriz);

         cout << "\nÉsta es la copia de su matriz de trabajo:" << endl;
         MuestraMatriz2D(matriz_aux);
      }
      else if (opcion_menu == 5) {
         cout << "\nSu matriz contiene " << matriz.fils << " filas, [0,"
              << matriz.fils-1 <<"] y " << matriz.cols << " columnas, [0,"
              << matriz.cols-1 << "]. Indique la fila y columna del elemento "
              << "por el cual desea comenzar su submatriz: ";
         cin >> fil >> col;

         if (fil < 0 || col < 0) {
            PrintAviso(4);
         }
         else if (fil >= matriz.fils || col >= matriz.cols) {
            PrintAviso(5);
         }
         else {
            cout << "\nIndique ahora la fila y columna del elemento en el cual "
                 << "desea finalizar su submatriz: ";
            cin >> fil_fin >> col_fin;

            if (fil_fin < fil || col_fin < fil) {
               PrintAviso(6);
            }
            else if (fil_fin >= matriz.fils || col_fin >= matriz.cols) {
               PrintAviso(5);
            }
            else {
               EliminaMatriz2D(matriz_aux);
               matriz_aux = ExtraeSubmatriz2D(matriz, fil, col,
                                              fil_fin, col_fin);

               cout << "\nÉsta es su sumbatriz:" << endl;
               MuestraMatriz2D(matriz_aux);
            }
         }
      }
      else if (opcion_menu == 6) {
         cout << "\nSu matriz contiene " << matriz.fils << " filas, [0,"
              << matriz.fils-1 <<"]. Indique la fila que desea eliminar: ";
         cin >> fil;

         matriz = EliminaFilMatriz2D(matriz, fil);

         cout << "\nFila eliminada. Su matriz ahora contiene " << matriz.fils
              << " filas." << endl;
      }
      else if (opcion_menu == 7) {
         cout << "\nSu matriz contiene " << matriz.cols << " columnas, [0,"
              << matriz.cols-1 << "]. Indique la columna que desea eliminar: ";
         cin >> col;

         matriz = EliminaColMatriz2D(matriz, col);

         cout << "\nColumna eliminada. Su matriz ahora contiene " << matriz.cols
              << " columnas." << endl;
      }
      else if (opcion_menu == 8) {
         EliminaMatriz2D(matriz_aux);
         matriz_aux = TraspuestaMatriz2D(matriz);

         cout << "\nÉsta es su matriz de trabajo traspuesta:" << endl;
         MuestraMatriz2D(matriz_aux);
      }
      else if (opcion_menu == 9) {
         EliminaMatriz2D(matriz_aux);
         matriz_aux = InvierteMatriz2D(matriz);

         cout << "\nÉsta es su matriz de trabajo inversa:" << endl;
         MuestraMatriz2D(matriz_aux);
      }
      else if (opcion_menu == 0) {
         cout << "\nFinalizando ejecución..." << endl;
      }
      else {
         cout << "\nIntroduzca una opción válida." << endl;
      }

      menu2 = !(opcion_menu == 0);
   }

   if (!pre_salir) {
      EliminaMatriz2D(matriz);
      EliminaMatriz2D(matriz_aux);
   }

   return 0;
}
