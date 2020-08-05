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

// MISMO SIGNO CON CONDICIONALES

/*
   Recupere la solución del ejercicio 13 [Mismo signo, separando E/S] de esta
   Relación de Problemas.

   Resuelva el mismo problema de ver si dos enteros tienen el mismo signo sin
   utilizar la operación de multiplicación. Para ello, se pide que implemente
   todas y cada una de las siguientes posibilidades:
      a) Enumerando todas las posibles situaciones, es decir, los dos positivos,
         los dos negativos, el primero positivo y el segundo negativo o el
         primero negativo y el segundo positivo. En esta versión, sí puede (y
         debe) usar los operadores lógicos &&, ||, !.
      b) Utilizar una estructura condicional anidada en la que sólo se permiten
         expresiones lógicas simples, es decir, no se pueden usar los operadores
         lógicos &&, ||, !.
      c) Sin utilizar estructuras condicionales. Debe construir una única
         expresión lógica compuesta y asignarle su valor a una variable lógica.
         En esta versión, sí puede (y debe) usar los operadores lógicos.

      Entrada: 0 0 −− Salida: No tienen el mismo signo
      Entrada: 0 3 −− Salida: No tienen el mismo signo
      Entrada: 3 0 −− Salida: No tienen el mismo signo
      Entrada: 3 4 −− Salida: Tienen el mismo signo
      Entrada: -3 -4 −− Salida: Tienen el mismo signo
      Entrada: 3 -4 −− Salida: No tienen el mismo signo
      Entrada: -3 4 −− Salida: No tienen el mismo signo
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int numero1, numero2;
   // Salida
   bool tienen_mismo_signo;

   cout << "Introduzca dos números enteros: ";
   cin >> numero1 >> numero2;

   // MÉTODO EXTENSIVO
   /*if (numero1 > 0 && numero2 > 0) {
      tienen_mismo_signo = true;
   }
   else if (numero1 < 0 && numero2 < 0) {
      tienen_mismo_signo = true;
   }
   else if (numero1 > 0 && numero2 < 0) {
      tienen_mismo_signo = false
   }
   else if (numero1 < 0 && numero2 > 0) {
      tienen_mismo_signo = false;
   }
   else if (numero1 == 0 || numero2 == 0) {
      tienen_mismo_signo = false;
   }*/

   // MÉTODO ANIDADO
   /*if (numero1 > 0) {
      if (numero2 > 0) {
         tienen_mismo_signo = true;
      }
      else if (numero2 < 0) {
         tienen_mismo_signo = false;
      }
   }
   else if (numero1 < 0) {
      if (numero2 > 0) {
         tienen_mismo_signo = false;
      }
      else if (numero2 < 0) {
         tienen_mismo_signo = true;
      }
   }
   else if (numero1 == 0) {
      tienen_mismo_signo = false
   }
   else if (numero2 == 0) {
      tienen_mismo_signo = false;
   }*/

   // MÉTODO INTENSIVO
   tienen_mismo_signo = (numero1 > 0 && numero2 > 0
                      || numero1 < 0 && numero2 < 0);
}

// OBSERVACIONES

/*
   El método extensivo, aunque es más detallado, es más difícil de mantener, ya
   que los cambios que se hagan deben hacerse en todas las diferentes
   posibilidades que plantea el código.

   El método anidado tiene el mismo resultado que el extensivo con la diferencia
   de que es más difícil de leer, pues hay que ir saltando de línea en línea.

   La solución ideal es la del método intensivo, ya que permite implementar el
   condicional en una sola línea.
*/
