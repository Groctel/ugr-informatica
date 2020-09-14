#include <iostream>
#include "NuevoOrdenEnteros.h"
using namespace std;


int main(int argc, char **argv) {
   int v[TOPE];

   //.......................................................................
   // Comprobacion de argumentos

   if (argc>4) {
      cerr << "Error: demasiados argumentos" << endl << endl;
      exit(1);
   }

   // Valores por defecto

   int usados = TOPE;
   int min_aleat = MIN_ALEAT;
   int max_aleat = MAX_ALEAT;

   // Otros valores

   if (argc > 1) {

      usados = atoi(argv[1]); // "usados" desde argv[1]

      if (argc > 2) {

         max_aleat = atoi(argv[2]); // "max_aleat" desde argv[2]
                                    // "min_aleat" es MIN_ALEAT
         if (argc > 3) {

            max_aleat = atoi(argv[2]); // "max_aleat" desde argv[2]
            min_aleat = atoi(argv[3]); // "min_aleat" desde argv[3]

            // Intercambiar los valores de "max_aleat" y "min_aleat"
            // si fuera necesario

            if (min_aleat > max_aleat)
               Intercambia(&min_aleat, &max_aleat);
         }
      }
   }

   // Comprobar la validez de "usados"
   if (usados <= 0 || usados > TOPE)  {
      cerr << "Error: numero de casillas (" << usados << ") incorrecto. ";
      cerr << "Debe ser 0 < casillas <= " << TOPE << endl << endl;
      exit(2);
   }
   // Comprobar la validez de "min_aleat"
   if (min_aleat < MIN_ALEAT || min_aleat > MAX_ALEAT)  {
      cerr << "Error: min.aleatorio (" << min_aleat << ") incorrecto. ";
      cerr << "Debe ser " << MIN_ALEAT << " <= min.aleatorio <= "
           << MAX_ALEAT << endl << endl;
      exit(3);
   }
   // Comprobar la validez de "max_aleat"
   if (max_aleat < MIN_ALEAT || max_aleat > MAX_ALEAT)  {
      cerr << "Error: max.aleatorio (" << max_aleat << ") incorrecto. ";
      cerr << "Debe ser " << MIN_ALEAT << " <= max.aleatorio <= "
           << MAX_ALEAT << endl << endl;
      exit(3);
   }

   cout << endl;
   cout << "Se va a crear un array de " << usados << " datos." << endl;
   cout << "Los datos estaran comprendidos entre "<< min_aleat << " y "
        << max_aleat << " (incluidos)" << endl;
   cout << endl;

   // Fin comprobacion argumentos
   //.......................................................................

   // Rellenar el vector con numeros aleatorios

   GeneradorAleatorioEnteros generador (min_aleat, max_aleat);

   // Iniciar el vector aleatoriamente

   for (int i=0; i<usados; i++)
      v[i] = generador.Siguiente();

   return 0;
}
