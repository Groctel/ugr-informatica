#include <chrono>  // para la semilla
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>  // para la generación de números pseudoaleatorios
#include "ProblemaViajanteComercio.h"
using namespace std;

/*
 MENSAJE DE AYUDA:
 *
 *   Imprime el mensaje de ayuda si no se proporcionan argumentos o si el primer
 argumento vale "-h" o "--help".
 */

void PrintAyuda() {
   cout << "Este programa resuelve de la forma más ótima posible el problema "
        << "del viajante de comercio mediante la heurísitca del vecino más "
        << "cercano." <<endl << endl
        << "ARGUMENTOS DE LLAMADA:" << endl
        << " - [int]: Número de ciudades a visitar." << endl
        << "        > II_ProblemaViajanteComercio 7 #7 ciudades" << endl
        << " - \"-h\" o \"--help\": Imprime este menú de ayuda. También se "
        << "imprime si no se proporcionan argumentos o se proporcionan "
        << "argumentos inválidos.";
}

/*
 CLASE: GENERADOR ALEATORIO ENTEROS:
 *
 Sirve para generar números aleatorios enteros en un rango de valores.
 *
 Hay crear un objeto de esta clase. Se dispone de dos constructores:
 *   1) GeneradorAleatorioEnteros()
 *      El primero no tiene parámetros y establece que únicamente se van a
 *   generar ceros y unos (este constructor llama al segundo).
 *   2) GeneradorAleatorioEnteros(int min, int max)
 *      El segundo tiene dos parámetros, "min" y "max" que delimitan el rango
 correspondiente.
 *
 *   Finalmente, el método
 *      int Siguiente()
 *   devolverá un valor aleatorio en el rango especificado en el constructor.
*/

class GeneradorAleatorioEnteros {
private:
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   long long Nanosec() {
      return (chrono::high_resolution_clock::now().time_since_epoch().count());
   }

public:
   GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1)
   { }

   GeneradorAleatorioEnteros(int min, int max) {

      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006

      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }

   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
};

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
   matriz_tmp.ciudades = new int*[fils];

   for (int i = 0; i < fils; i++) {
      matriz_tmp.ciudades[i] = new int[cols];
   }

   return matriz_tmp;
}

/*
 CREA Y RELLENA MATRIZ 2D:
 *
 *   Llama a CreaMatriz2D para reservar memoria y rellena la matriz de ciudades que
 representan la posición absoluta en la que se encuentran.
 *
 PRE:
 *   - fils > 0 && cols > 0
 *   - fil * col <= 2^16
 *   - fil * col > 0 (contra desbordamientos aritméticos)
 */

Matriz2D CreaYRellenaMatriz2D(int fils, int cols) {
   Matriz2D matriz_tmp = CreaMatriz2D(fils, cols);
   GeneradorAleatorioEnteros generador;

   for (int i = 0; i < matriz_tmp.fils; i++) {
      for (int j = 0; j < matriz_tmp.cols; j++) {
         ModificaElementoMatriz2D(matriz_tmp, i, j, generador.Siguiente());
      }
   }

   return matriz_tmp;
}

/*
 MUESTRA MATRIZ 2D:
 *
 *   Recorre todas las fiilas y columnas de la matriz en orden ascendente y
 llama a ElementoMatriz2D para ir mostrando uno a uno los elementos de forma
 ordenada y con formato elegante.
 */

void MuestraMatriz2D(const Matriz2D &matriz) {
   int elemento_max = 0;
   int espaciado = 0;

   for (int i = 0; i < matriz.fils; i++) {
      for (int j = 0; j < matriz.cols; j++) {
         if (ElementoMatriz2D(matriz, i, j) > elemento_max)
              elemento_max = ElementoMatriz2D(matriz, i, j);
      }
   }

   while(pow(10,espaciado) < elemento_max) {
      espaciado++;
   }

   for (int i = 0; i < matriz.fils; i++) {
      cout << endl;

      for (int j = 0; j < matriz.cols; j++) {
         cout << setw(espaciado) << ElementoMatriz2D(matriz, i, j)
              << ((((i)%matriz.fils+1)==0)?"\n":" ");
      }
   }

   cout << endl;
}

/*
 ELIMINA MATRIZ 2D:
 *
 *   Recorre todas las filas de la matriz en orden descendente y las borra una a
 una. Luego elimina el vector de punteros a las filas de la matriz.
 */

void EliminaMatriz2D(Matriz2D &matriz) {
   for (int i = matriz.fils - 1; i >= 0; i--) {
      delete []matriz.ciudades[i];
   }

   delete []matriz.ciudades;
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

int ElementoMatriz2D(const Matriz2D &matriz, int fil, int col) {
   return matriz.ciudades[fil][col];
}

/*
 MODIFICA ELEMENTO MATRIZ 2D:
 *
 *   Cambia el elemento [fil][col] de una matriz por el elemento int pasado
 como argumento.
 PRE:
 *   - fil >= 0 && col >= 0
 *   - fil < matriz.fils && col < matriz.cols (dentro del rango de la matriz)
 */

void ModificaElementoMatriz2D(const Matriz2D &matriz, int fil, int col,
                              int elemento) {
   matriz.ciudades[fil][col] = elemento;
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
         ModificaElementoMatriz2D(matriz_tmp, i, j, matriz.ciudades[u][j]);
      }
   }

   EliminaMatriz2D(matriz);

   return matriz_tmp;
}



void Resolucion(Matriz2D matriz) {
   int viajes = matriz.fils - 1, ciudad = 1;

   cout << "Resolviendo";

   for (int i = 0; i < viajes; i++) {
      int minimo = -1 , posicion_minimo;
      for (int j = 0; j < matriz.cols; j++) {
         if (matriz.ciudades[ciudad][j] < minimo || minimo < 0) {
            minimo = matriz.ciudades[ciudad][j];
            posicion_minimo = j;
         }
      }
      EliminaFilMatriz2D(matriz, ciudad);
      ciudad = posicion_minimo;

      cout << ".";
   }
}
