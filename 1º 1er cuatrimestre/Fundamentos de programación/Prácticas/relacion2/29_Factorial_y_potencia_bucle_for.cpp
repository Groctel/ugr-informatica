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

// FACTORIAL Y POTENCIA: BUCLE FOR

/*
   Retome la solución del ejercicio 21 [Factorial y Potencia] y modifíquelo para
   que el bucle principal sea un bucle for en vez de un bucle while.
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int n;
   double x;
   // Cómputos
   int i;
   // Salida
   int factorial = 1;
   double potencia = 1;

   cout << "Introduzca un valor entero y un valor real: ";
   cin >> n >> x;

   for (i = 2; i <= n; i++) {
      factorial *= i;
   }

   for (i = 0; i < x; i++) {
      potencia *= n;
   }

   cout << "\nn! = " << factorial
        << "\nn^x =" << potencia;
}

// OBSERVACIONES

/*
   Tanto este ejercicio como el siguiente ofrecen las mismas soluciones que los
   anteriores debido a la política de uso de while y for que siguen estas
   soluciones.
*/
