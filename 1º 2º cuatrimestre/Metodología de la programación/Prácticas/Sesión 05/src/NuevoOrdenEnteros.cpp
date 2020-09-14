#include <chrono>
#include <random>
#include "NuevoOrdenEnteros.h"
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

void Intercambia(int a, int b) {
   int aux = a;
   a = b;
   b = aux;
}
