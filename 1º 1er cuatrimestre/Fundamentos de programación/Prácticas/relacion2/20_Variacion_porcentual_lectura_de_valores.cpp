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

// VARIACIÓN PORCENTUAL: LECTURA DE VALORES

/*
   Recupere la solución del ejercicio 8 [Variación porcentual] de la Relación de
   Problemas I.

   Modifíquelo para realizar una lectura de múltiples pares de valores. La
   entrada de datos se interrumpirá cuando se introduzca cualquier valor
   negativo.

   Por cada par de valores, el programa mostrará la correspondiente variación
   porcentual.

      Entrada: 5 6 6 5 -1 −− Salida: Variaciones porcentuales: 20% 16.6667%
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   // Constantes
   const int TERMINADOR = 0;
   // Entrada
   double num_inicial, num_final;
   // Salida
   double var_porcentual;

   cout << "Introduzca pares de números positivos.\n"
        << "Introduzca el primer par de números separados por espacios: ";
   cin >> num_inicial >> num_final;

   while (num_inicial >= TERMINADOR && num_final >= TERMINADOR) {
      var_porcentual = abs(100 * ((num_final - num_inicial) / num_inicial));

      cout << "Entre sus dos valores hay una variación porcentual del "
           << var_porcentual << "%.\n"
           << "Introduzca otro par de números: ";
      cin >> num_inicial >> num_final;
   }
}

// OBSERVACIONES

/*
   Volviendo al ejercicio 8 de la relación 1, puede verse que los nombre de las
   variables son diferentes (de valor a num) para ahorrar espacio y que se han
   combinado los cout en uno sólo, ya que es más sencillo de leer. También es
   buena costumbre hacer los saltos de línea en el código a la vez que se
   introduce el carácter de escape \n, pues lo hace más fácil de leer.
*/
