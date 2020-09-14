#include <iostream>
#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
#include "SecuenciacionGenetica.h"
using namespace std;


char * SecuenciaConsenso(char *secuencia[][MAXLONGITUD], int longitud, int total) {
   char secuencia_consenso[longitud];

   for (int i = 0; i < longitud; i++) {
      int nucleotidos[NUM_NUCLEOTIDOS] = {0, 0, 0, 0}; // A, C, G, T
      int nucleotido_lider = 0;
      int *p_adn = nucleotidos;

      for (int j = 0; j < total; j++) {
         if (*secuencia[i][j] == 'A') {
            *p_adn++;
         }
         else if (*secuencia[i][j] == 'C') {
            *p_adn++;
         }
         else if (*secuencia[i][j] == 'G') {
            *p_adn++;
         }
         else if (*secuencia[i][j] == 'T') {
            *p_adn++;
         }
      }

      for (int j = 0; j < NUM_NUCLEOTIDOS; j++) {
         if (*(p_adn+j) >= nucleotidos[nucleotido_lider])
            nucleotido_lider = j;
      }

      *secuencia = NUCLEOTIDOS[nucleotido_lider];
   }

   return secuencia_consenso;
}

/*
char * SecuenciaConsenso(char *secuencia_consenso, char matriz[][MAXLONGITUD],int fils, int cols){
   int contador, maximo, pos_mas_repetido, j;
   char *ptr = secuencia_consenso;

   for(int i = 0; i < cols; i++) {
      maximo = 0;
      pos_mas_repetido = 0;

      for(j = 0; j < fils; j++) {
         contador = 0;

      for(int k = 0; k < fils; k++) {
         if(matriz[j][i] == matriz[k][i])
            contador++;
      }

      if(contador > maximo) {
         pos_mas_repetido = j;
         maximo = contador;
      }
   }
      *(ptr+i) = matriz[pos_mas_repetido][i];
   }

   return ptr;
}

char * SecuenciaInconexa(char *secuencia_inconexa, char matriz[][MAXLONGITUD],int fils, int cols){
   int mayor_distancia = -1, usados = 0, fila = 0, distancia;
   const int TAM = 100;
   char secuencia[TAM], secuencia_consenso[TAM],*ptr_consenso;

   for(int j = 0; j < fils; j++){
      for(int i = 0; i < cols; i++){
         secuencia[i] = matriz[fila][j];
      }

      ptr_consenso = SecuenciaConsenso(secuencia_consenso, matriz, fils, cols);
      distancia = DistanciaHamming(secuencia_consenso, secuencia);

      if(distancia > mayor_distancia){
         mayor_distancia = distancia;
         for(int k = 0; k < cols; k++){
            *(secuencia_inconexa+k) = *(secuencia);
         }
      }
   }

   return secuencia_inconexa;
}
*/
