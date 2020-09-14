#include <iostream>
#include "LeeEntero.h"
using namespace std;

int main(int argc, char *argv[]) {
   int numero, cota_inferior, cota_superior;

   if (argc == 1) {
      cout << "Introduzca uno o dos números enteros" << endl;
      return 1;
   }
   else if (argc == 2 && !EsEntero(argv[1])) {
      cout << "El argumento introducido no es un número." << endl;
      return 1;
   }
   else if (argc == 3) {
      if (!EsEntero(argv[1]) && !EsEntero(argv[2])) {
         cout << "Ninguno de los argumentos introducidos son números." << endl;
         return 1;
      }
      else if (!EsEntero(argv[1])) {
         cout << "El primer argumento introducido no es un número." << endl;
         return 1;
      }
      else if (!EsEntero(argv[2])) {
         cout << "El segundo argumento introducido no es un número." << endl;
         return 1;
      }
   }
   else if (argc > 3) {
      cout << "Ha introducido demasiados argumentos. El programa continuará "
           << "teniendo en cuenta sólo los dos primeros" << endl;
   }

   cout << "Ha introducido el " << LeeEntero(argv[1]);
        if (argc == 3) {
           cout << " y el " << LeeEntero(argv[2]);
        }
   cout << "." << endl;

   if (argc == 2) {
      if (LeeEntero(argv[1]) >= 0) {
         cota_inferior = 0;
         cota_superior = LeeEntero(argv[1]);
      }
      else {
         cota_inferior = LeeEntero(argv[1]);
         cota_superior = 0;
      }
   }
   else {
      if (LeeEntero(argv[1]) < LeeEntero(argv[2])) {
         cota_inferior = LeeEntero(argv[1]);
         cota_superior = LeeEntero(argv[2]);
      }
      else {
         cota_inferior = LeeEntero(argv[2]);
         cota_superior = LeeEntero(argv[1]);
      }
   }

   numero = EnteroIntervalo(cota_inferior, cota_superior);

   cout << "El número " << numero << " pertenece al intervalo ["
        << cota_inferior << "," << cota_superior << "]." << endl;

   return 0;
}
