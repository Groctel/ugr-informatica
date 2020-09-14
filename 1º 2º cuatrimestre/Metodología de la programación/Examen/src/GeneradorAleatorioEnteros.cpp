#include "GeneradorAleatorioEnteros.h"
using namespace std;

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros()
   : GeneradorAleatorioEnteros(0, 1)
{ }

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros(int min, int max)  {
   const int A_DESCARTAR = 70000;

   auto semilla = Nanosec();
   generador_mersenne.seed(semilla);
   generador_mersenne.discard(A_DESCARTAR);
   distribucion_uniforme = uniform_int_distribution<int> (min, max);
}

int GeneradorAleatorioEnteros :: Siguiente() {
   return (distribucion_uniforme(generador_mersenne));
}

long long GeneradorAleatorioEnteros :: Nanosec() {
   return (chrono::high_resolution_clock::now().time_since_epoch().count());
}
