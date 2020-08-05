///////////////////////////////////////////////////////////////////////////////
// Copyright 2018 Atanasio Rubio Gil https://github.com/TaxoRubio
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
///////////////////////////////////////////////////////////////////////////////

// SUSTITUIR CARÁCTER POR VECTOR (CON VECTOR AUXILIAR)

/*

*/

#include <iostream>
using namespace std;

int main() {
   // Constantes
   const int LONGITUD_ORIGINAL = 1337; // Por qué no
   const char TERMINADOR = '#';
   // Entrada
   char original[LONGITUD_ORIGINAL];
   char sustitutivo[LONGITUD_ORIGINAL];
   char caracter, char_sustituido;
   // Cómputos
   bool terminado = false;
   int longitud_original = 0;
   int longitud_sustitutivo = 0;
   int ocurrencias, longitud_final;
   int i, o, s;
   // Salida
   char final[LONGITUD_ORIGINAL];

   cout << "VECTOR ORIGINAL:\n"
        << "Introduzca caracteres y termine la secuencia con '#'.\n";

   for(i = 0; !terminado; i++){
      cout << "Introduzca un carácter: ";
      cin >> caracter;

      if(caracter != TERMINADOR) {
         original[i] = caracter;
         longitud_original++;
      }
      else
         terminado = true;
   }

   cout << "\nVECTOR SUSTITUTIVO:\n"
        << "Introduzca caracteres y termine la secuencia con '#'.\n";

   terminado = false;
   for(i = 0; !terminado; i++){
      cout << "Introduzca un carácter: ";
      cin >> caracter;

      if(caracter != TERMINADOR) {
         sustitutivo[i] = caracter;
         longitud_sustitutivo++;
      }
      else
         terminado = true;
   }

   cout << "\nIntroduzca el carácter que desea sustituir: ";
   cin >> char_sustituido;

   for (i = 0; i < longitud_original; i++) {
      if (original[i] == char_sustituido)
         ocurrencias++;
   }

   longitud_final = (longitud_original) +
                    (longitud_sustitutivo * (ocurrencias - 1));

   for(i = 0, o = 0; i < longitud_final; i++, o++){
      if(original[o] == char_sustituido){
         for (s = 0; s < longitud_sustitutivo; s++) {
            final[i] = sustitutivo[s];
            i++;
         }
         i--;
      }
      else{
         final[i] = original[o];
      }
   }

   cout << "\nEl vector final es: ";
   for(i = 0; i < longitud_final; i++){
      cout << final[i] << " ";
   }
}
// OBSERVACIONES

/*

*/
