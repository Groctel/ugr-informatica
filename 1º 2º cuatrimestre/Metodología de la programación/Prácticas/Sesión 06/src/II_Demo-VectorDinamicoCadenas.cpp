#include <iostream>
#include <cstring>
#include <cctype>
#include "VectorDinamicoCadenas.h"
using namespace std;


int main(){
   string cadena, cadena_completa = "";
   int num_lineas = 0;

   while (getline (cin,cadena)){
      cadena_completa = cadena_completa + cadena;
      cadena_completa.push_back('\n');
   }

   char **v = SepararCadena(cadena_completa, num_lineas);

   cout << "El archivo tiene " << num_lineas << " líneas, de las cuales "
        << NumLineasVacias (v, num_lineas) << " están vacías. " << endl << endl
        << "El archivo está compuesto por " << NumParrafos (v,num_lineas)
        << " párrafos " << endl;

   delete [] v;

   return 0;
}
