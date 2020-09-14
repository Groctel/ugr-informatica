#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
   int v1[TOPE], v2[TOPE], mezcla[TOPE*2];
   int *p, min, max, util_v1, util_v2, util_mezcla;

   if (argc == 1) {
      min = 1; max = 100;
   }
   else if (argc == 2) {
      min = 1; max = argv[1];
   }
   else if (argc == 3) {
      min = argv[1]; max = argv[2];
   }
   else {
      cout << "Este programa sólo tendrá en cuenta los dos primeros argumentos."
           << endl;
      min = argv[1]; max = argv[2];
   }

   cout << "Indique el número de elementos que insertar en el primer vector: ";
   cin >> util_v1;

   if (util_v1 > 100) {
      cout << "Valor máximo excedido, limitado a 100 en esta ejecución.";
      util_v1 = 100;
   }
   else if (util_v1 < 0) {
      cout << "Valor mínimo no alcanzado, transformado a 50 en esta ejecucion.";
      util_v1 = 50;
   }

   cout << "Indique el número de elementos que insertar en el segundo vector: ";
   cin >> util_v2;

   if (util_v2 > 100) {
      cout << "Valor máximo excedido, limitado a 100 en esta ejecución.";
      util_v2 = 100;
   }
   else if (util_v2 < 0) {
      cout << "Valor mínimo no alcanzado, transformado a 50 en esta ejecucion.";
      util_v2 = 50;
   }

   RellenaVector (v1, util_v1, min, max);
   RellenaVector (v2, util_v2, min, max);
   util_mezcla = util_v1 + util_v2;

   OrdenaVector(int *v1, int util_v1);
   OrdenaVector(int *v2, int util_v2);


}
