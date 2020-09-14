#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
#include "MezclaArrays.h"
using namespace std;


////////Clase para generar enteros aleatorios.
class GeneradorAleatorioEnteros {
private:
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   long long Nanosec(){
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


void RellenaVector(int v[], int util, int min, int max) {
   GeneradorAleatorioEnteros generador(min, max);

   for (int i = 0, p = v1; i < util; i++) {
      *(p + i) = generador.Siguiente();
   }
   for (int i = 0, p = v2; i < util; i++) {
      *(p + i) = generador.Siguiente();
   }
}

void OrdenaVector(int *v[], int util) {
   int *p = v, permuta;

   for (int i = 0; i < util; i++) {
      for (int j = i+1; j < util; j++) {
         if (*(p+i) > *(p+j)) {
            permuta = *(p+i);
            *(p+i) = *(p+j);
            *(p+j) = permuta;
         }
      }
   }
}

void MuestraVector(char *mensaje, int v[], int util, int n) {

}

int MezclaVectores(int mezcla[], int v1[], int util_v1, int v2[], int util_v2) {
   
}
