#ifndef GENERADOR_ALEATORIO_ENTEROS
#define GENERADOR_ALEATORIO_ENTEROS

#include <cctype>
#include <chrono>
#include <cstdlib>
#include <random>
using namespace std;

class GeneradorAleatorioEnteros {
private:
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution <int>  distribucion_uniforme;
   long long Nanosec();

public:
   GeneradorAleatorioEnteros();
   GeneradorAleatorioEnteros(int min, int max);
   int Siguiente();
};

#endif
