#include <random>
#include <chrono>

GeneradorAleatorioEnteros::long long Nanosec(){
   return (chrono::high_resolution_clock::now().time_since_epoch().count());
}

GeneradorAleatorioEnteros::GeneradorAleatorioEnteros()
   : GeneradorAleatorioEnteros(0, 1)
   { }

GeneradorAleatorioEnteros::GeneradorAleatorioEnteros(int min, int max) {
   const int A_DESCARTAR = 70000;
   // ACM TOMS Volume 32 Issue 1, March 2006

   auto semilla = Nanosec();
   generador_mersenne.seed(semilla);
   generador_mersenne.discard(A_DESCARTAR);
   distribucion_uniforme = uniform_int_distribution<int> (min, max);
}

GeneradorAleatorioEnteros::int Siguiente(){
   return (distribucion_uniforme(generador_mersenne));
}
