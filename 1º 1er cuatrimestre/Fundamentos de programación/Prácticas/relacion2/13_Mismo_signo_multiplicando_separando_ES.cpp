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

// MISMO SIGNO MULTIPLICANDO, SEPARANDO E/S

/*
   Recupere la solución del ejercicio 1 [Mismo signo :multiplicando] de esta
   Relación de Problemas.

   Resuelva el mismo problema de ver si dos enteros tienen el mismo signo pero
   sin mezclar Entradas/Salidas y Cómputos. Para ello, use una variable lógica
   mismo_signo y asígnele el valor correspondiente de la expresión lógica.
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int numero1, numero2;
   // Cómputos
   bool tienen_mismo_signo;

   cout << "Introduzca dos números enteros: ";
   cin >> numero1 >> numero2;

   tienen_mismo_signo = (numero1 * numero2 > 0);

   cout << "\nLos números " << numero1 << " y " << numero2;
   if (!tienen_mismo_signo)
      cout << " no";
   cout << " tienen el mismo signo";
}

// OBSERVACIONES

/*
   Ya lo había hecho así en el ejercicio anterior, pero dejo el resultado por si
   alguien sólo mira esta solución.
*/
