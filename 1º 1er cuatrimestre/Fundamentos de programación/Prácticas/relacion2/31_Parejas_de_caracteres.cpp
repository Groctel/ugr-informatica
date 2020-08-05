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

// INTERVALO

/*
   Escriba un programa que lea cuatro valores de tipo char
      (min_izda, max_izda, min_dcha, max_dcha)
   e imprima las parejas que pueden formarse con un elemento del conjunto
      {min_izda ... max_izda}
   y otro elemento del conjunto
      {min_dcha ... max_dcha}

   Por ejemplo, si
      min_izda = b, max_izda = d, min_dcha = j, max_dcha = m
   el programa debe imprimir las parejas que pueden formarse con un elemento
   de {b c d} y otro elemento de {j k l m}, es decir:

      bj bk bl bm
      cj ck cl cm
      dj dk dl dm
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   char min_izda, max_izda, min_dcha, max_dcha;
   // Cómputos
   int i, j;
   // Salida
   char izda, dcha;

   cout << "Introduzca dos caracteres para las columnas: ";
   cin >> min_izda >> max_izda;
   while (min_izda > max_izda) {
      cout << "El primer carácter debe ser inferior: ";
      cin >> min_izda >> max_izda;
   }
   cout << "Introduzca dos caracteres para las filas: ";
   cin >> min_dcha >> max_dcha;
   while (min_dcha > max_dcha) {
      cout << "El primer carácter debe ser inferior: ";
      cin >> min_dcha >> max_dcha;
   }

   for (i = min_izda; i <= max_izda; i++) {
      izda = i;

      cout << "\n";
      for (j = min_dcha; j <= max_dcha; j++) {
         dcha = j;

         cout << izda << dcha << " ";
      }
   }

   cin >> i;
}

// OBSERVACIONES

/*
   Como los for sólo trabajan con int, primero transformamos los char en int y
   luego esos mismo int en char para imprimirlos. Esto sólo ocurre con el int
   que se usa en las iteraciones. En la comprobación se puede usar un char.
*/
