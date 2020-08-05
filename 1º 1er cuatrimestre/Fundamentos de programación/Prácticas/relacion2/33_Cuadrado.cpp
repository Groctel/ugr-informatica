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

// CUADRADO

/*
   Cree un programa que ofrezca en pantalla la siguiente salida:
      1 2 3 4 5 6
      2 3 4 5 6 7
      3 4 5 6 7 8
      4 5 6 7 8 9
      5 6 7 8 9 10
      6 7 8 9 10 11
   Modifique la solución para que se lea desde teclado el valor inicial y el
   número de filas a imprimir. En el ejemplo anterior el valor inicial era 1 y
   se imprimía un total de 6 filas.
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int valor_inicial, numero_filas;
   // Cómputos
   int i;
   // Salida
   int j;

   cout << "Introduzca un valor inicial y el número de filas que desea: ";
   cin >> valor_inicial >> numero_filas;

   for (i = valor_inicial; i <= numero_filas; i++) {
      cout << "\n";
      for (j = i; j < numero_filas + i; j++) {
         cout << j << " ";
      }
   }

   cin >> i;
}

// OBSERVACIONES

/*
   Al contrario que en el ejercicio anterior, el segundo for es válido para
   menor estricto de j, ya que si no nos daría una fila extra y pasaría a ser un
   rectángulo.
*/
