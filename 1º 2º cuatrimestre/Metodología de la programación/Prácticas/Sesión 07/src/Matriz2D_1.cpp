#include <cmath>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <random>  // para la generación de números pseudoaleatorios
#include "Matriz2D_1.h"
using namespace std;

/*
 CONTROL DE ERRORES:
 *
 *   Imprime errores críticos justo antes de cerrar el programa.
 *
 LEYENDA:
 *   0: Error inesperado de consecuencias críticas.
 */

void PrintError(int error) {
   if (error == 0) {
      cerr << "Este aviso no debería salir en el programa. Frenando ejecución."
           << endl;
   }
}

/*
 CONTROL DE AVISOS:
 *
 *   Imprime avisos o mensajes de error que no impiden la continuación del
 programa.
 *
 LEYENDA:
 *   0: Aviso inesperado de consecuencias no críticas.
 *   1: El número de filas o de columnas es menor o igual que cero.
 *   2: El número total de filas y columnas es mayor que 16 bits.
 *   3: El número total de filas y columnas crea un desbordamiento aritmético.
 *   4: Se intenta acceder a un número de filas o columnas negativo.
 *   5: Se intenta acceder a un número de filas o columnas superior al total.
 */

void PrintAviso(int aviso) {
   if (aviso == 0) {
      cerr << "\nEste aviso no debería salir en el programa, pero no es lo "
           << "suficientemente grave como para frenar su ejecución." << endl;
   }
   else if (aviso == 1) {
      cerr << "\nTanto las filas como las columnas deben ser mayores que 0."
           << endl;
   }
   else if (aviso == 2) {
      cerr << "\nPara prevenir errores de desbordamiento aritmético, el límite "
           << "de elementos disponibles en una matriz es 65535 (2^16-1)."
           << endl;
   }
   else if (aviso == 3) {
      cerr << "\nEl número de filas y columnas es tan grande que ha producido "
           << "un desbordamiento aritmético. ";
           PrintAviso(2);
   }
   else if (aviso == 4) {
      cerr << "\nTanto la fila como la columna a acceder deben ser mayores que "
           << "cero." << endl;
   }
   else if (aviso == 5) {
      cerr << "\nTanto la fila como la columna a acceder deben ser menores que "
           << "el número total de filas y/o columnas que componen la matriz"
           << endl;
   }
   else if (aviso == 6) {
      cerr << "Tanto la fila como la columna a acceder deben ser mayores que "
           << "la fila y la columna seleccionadas previamente" << endl;
   }
}

/*
 CREA MATRIZ 2D:
 *
 *   Reserva memoria para una matriz 2D con un número de filas y columnas
 determinado.
 *
 PRE:
 *   - fils > 0 && cols > 0
 *   - fil * col <= 2^16
 *   - fil * col > 0 (contra desbordamientos aritméticos)
 */

Matriz2D CreaMatriz2D(int fils, int cols) {
   Matriz2D matriz_tmp;

   matriz_tmp.fils = fils;
   matriz_tmp.cols = cols;
   matriz_tmp.datos = new TipoBase*[fils];

   for (int i = 0; i < fils; i++) {
      matriz_tmp.datos[i] = new TipoBase[cols];
   }

   return matriz_tmp;
}


/*
 CREA Y RELLENA MATRIZ 2D:
 *
 *   Llama a CreaMatriz2D para reservar memoria y rellena la matriz de datos que
 representan la posición absoluta en la que se encuentran.
 *
 PRE:
 *   - fils > 0 && cols > 0
 *   - fil * col <= 2^16
 *   - fil * col > 0 (contra desbordamientos aritméticos)
 */

Matriz2D CreaYRellenaMatriz2D(int fils, int cols) {
   Matriz2D matriz_tmp = CreaMatriz2D(fils, cols);

   for (int i = 0, valor = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0; j < matriz_tmp.cols; j++, valor++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j, valor);
      }
   }

   return matriz_tmp;
}

/*
 ELIMINA MATRIZ 2D:
 *
 *   Recorre todas las filas de la matriz en orden descendente y las borra una a
 una. Luego elimina el vector de punteros a las filas de la matriz.
 */

void EliminaMatriz2D(Matriz2D &matriz) {
   for (int i = matriz.fils - 1; i >= 0; i--) {
      delete []matriz.datos[i];
   }

   delete []matriz.datos;
}

/*
 MUESTRA MATRIZ 2D:
 *
 *   Recorre todas las fiilas y columnas de la matriz en orden ascendente y
 llama a ElementoMatriz2D para ir mostrando uno a uno los elementos de forma
 ordenada y con formato elegante.
 */

void MuestraMatriz2D(const Matriz2D &matriz) {
   TipoBase elemento_max = 0;
   int espaciado = 0;
   string total_filas, fila;

   if (matriz.fils > elemento_max);
      elemento_max = matriz.fils;

   for (int i = 0; i < matriz.fils; i++) {
      for (int j = 0; j < matriz.cols; j++) {
         if (ElementoMatriz2D(matriz, i, j) > elemento_max)
              elemento_max = ElementoMatriz2D(matriz, i, j);
      }
   }

   while(pow(10,espaciado) < elemento_max) {
      espaciado++;
   }

   cout << "      ";

   for (int i = 0; i < matriz.cols; i++) {
      cout << setw(espaciado) << i << ((((i)%matriz.fils+1)==0)?"\n":" ");
   }

   cout << endl << "      ";

   for (int i = 0; i < matriz.cols; i++) {
      cout << setw(espaciado) << "|" << ((((i)%matriz.fils+1)==0)?"\n":" ");
   }

   total_filas = to_string(matriz.fils);

   for (int i = 0; i < matriz.fils; i++) {
      fila = to_string(i);

      cout << endl;

      for (int i = 0; i < total_filas.size() - fila.size() + 1; i++) {
         cout << " ";
      }

      cout << i << "-[ ";

      for (int j = 0; j < matriz.cols; j++) {
         cout << setw(espaciado) << ElementoMatriz2D(matriz, i, j)
              << ((((i)%matriz.fils+1)==0)?"\n":" ");
      }

      cout << "]-" << i;
   }

   cout << endl << "      ";

   for (int i = 0; i < matriz.cols; i++) {
      cout << setw(espaciado) << "|" << ((((i)%matriz.fils+1)==0)?"\n":" ");
   }

   cout << endl << "      ";

   for (int i = 0; i < matriz.cols; i++) {
      cout << setw(espaciado) << i << ((((i)%matriz.fils+1)==0)?"\n":" ");
   }

   cout << endl;
}

/*
 ELEMENTO MATRIZ 2D:
 *
 *   Devuelve el elemento [fil][col] de una matriz.
 *
 PRE:
 *   - fil >= 0 && col >= 0
 *   - fil < matriz.fils && col < matriz.cols (dentro del rango de la matriz)
 */

TipoBase ElementoMatriz2D(const Matriz2D &matriz, int fil, int col) {
   return matriz.datos[fil][col];
}

/*
 MODIFICA ELEMENTO MATRIZ 2D:
 *
 *   Cambia el elemento [fil][col] de una matriz por el elemento TipoBase pasado
 como argumento.
 PRE:
 *   - fil >= 0 && col >= 0
 *   - fil < matriz.fils && col < matriz.cols (dentro del rango de la matriz)
 */

void ModificaElementoMatriz2D(const Matriz2D &matriz, int fil, int col,
                              TipoBase elemento) {
   matriz.datos[fil][col] = elemento;
}

/*
 COPIA MATRIZ 2D:
 *
 *   Crea una matriz con las dimensiones de la que se le indica y recorre todos
 los elementos de la matriz copia para ir añadiendo de uno en uno sus
 equivalentes en la matriz principal.
 */

Matriz2D CopiaMatriz2D(const Matriz2D &matriz) {
   Matriz2D matriz_tmp = CreaMatriz2D(matriz.fils, matriz.cols);

	for (int i = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0; j < matriz_tmp.cols; j++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j, matriz.datos[i][j]);
      }
   }

   return matriz_tmp;
}

/*
 EXTRAE SUBMATRIZ 2D:
 *
 *   Crea una matriz con (fin - incicio) filas y columnas y recorre la matriz
 original ateniéndose a dichas restricciones para copiar sólo los valores que
 formen la submatriz deseada.
 PRE:
 *   - fil >= 0 && col >= 0
 *   - fil < matriz.fils && col < matriz.cols (dentro del rango de la matriz)
 *   - fil_fin >= fil && col_fin >= col
 *   - fil_fin < matriz.fils && col_fin < matriz.cols
 */

 Matriz2D ExtraeSubmatriz2D(const Matriz2D &matriz, int fil_inicio,
                            int col_inicio, int fil_fin, int col_fin) {
   Matriz2D matriz_tmp = CreaMatriz2D(fil_fin - fil_inicio + 1,
                                      col_fin - col_inicio + 1);

   for (int i = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0; j < matriz_tmp.cols; j++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j,
                                  matriz.datos[fil_inicio + i][col_inicio + j]);
      }
   }

   return matriz_tmp;
}

/*
 ELIMINA FILA MATRIZ 2D:
 *
 *   Crea una nueva matriz con una fila menos que la original. Copia una a una
 todas las filas excepto la marcada para eliminar.
 */

Matriz2D EliminaFilMatriz2D(Matriz2D &matriz, int fil) {
   Matriz2D matriz_tmp = CreaMatriz2D(matriz.fils - 1, matriz.cols);

   for (int i = 0, u = 0; i < matriz_tmp.fils; i++, u++) {
      if (i == fil)
         u++;

      for (int j = 0; j < matriz_tmp.cols; j++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j, matriz.datos[u][j]);
      }
   }

   EliminaMatriz2D(matriz);

   return matriz_tmp;
}

/*
 ELIMINA COLUMNA MATRIZ 2D:
 *
 *   Crea una nueva matriz con una columna menos que la original. Copia una a
 una todas las filas saltándose el elemento de la columna marcada para eliminar.
 */

Matriz2D EliminaColMatriz2D(Matriz2D &matriz, int col) {
   Matriz2D matriz_tmp = CreaMatriz2D(matriz.fils, matriz.cols -1);

   for (int i = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0, u = 0; j < matriz_tmp.cols; j++, u++) {
         if (j == col)
            u++;
         ModificaElementoMatriz2D(matriz_tmp, i, j, matriz.datos[i][u]);
      }
   }

   EliminaMatriz2D(matriz);

   return matriz_tmp;
}

/*
 TRASPUESTA MATRIZ 2D:
 *
 *   Crea una nueva matriz con tantas filas como columnas tenga la original y
 viceversa. Recorre la nueva matriz por filas y columnas y va rellenando con los
 elementos de la original por columnas y filas.
 */

Matriz2D TraspuestaMatriz2D(const Matriz2D &matriz) {
   Matriz2D matriz_tmp = CreaMatriz2D(matriz.cols, matriz.fils);

   for (int i = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0; j < matriz_tmp.cols; j++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j, matriz.datos[j][i]);
      }
   }

   return matriz_tmp;
}

/*
 INVIERTE MATRIZ 2D:
 *
 *   Crea una nueva matriz con las dimensiones de la original y copia en ella la
 original en orden descendente de filas.
 */

Matriz2D InvierteMatriz2D(const Matriz2D &matriz) {
   Matriz2D matriz_tmp = CreaMatriz2D(matriz.fils, matriz.cols);

   for (int i = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0; j < matriz_tmp.cols; j++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j,
                                  matriz.datos[matriz.fils - i - 1][j]);
      }
   }

   return matriz_tmp;
}
