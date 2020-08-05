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

// APROXIMACIÓN DE PI POR WALLIS

/*
   Otra aproximación de π introducida en el siglo XVII por el matemático inglés
   John Wallis viene dada por:
      π/2 ≈ 2/1 * 2/3 * 4/3 * 4/5 * 6/5 * 6/7 ...

   Construya un programa que lea el valor tope obligando a que esté entre 1 y
   cien mil, calcule la aproximación de π mediante la anterior fórmula
   (multiplicando un total de tope fracciones) e imprima el resultado en
   pantalla.

   Debe resolver este problema de dos formas distintas, a saber:
      a) Observe que el numerador y el denominador varían de forma alternativa
         (aunque ambos de la misma forma, a saltos de 2. Cuando a uno le toca
         cambiar, el otro permanece igual. Este comportamiento se puede
         controlar con una única variable de tipo de dato bool.
      b) Otra forma de implementar los cambios en el numerador y denominador es
      observando que en cada iteración, el numerador es el denominador de la
      iteración anterior más 1 y el denominador es el numerador de la iteración
      anterior más 1.

      Entrada: 1000 −− Salida: 3.1400238186006
      Entrada: 100000 −− Salida: 3.14157694582286
*/

#include <iostream>
using namespace std;

int main () {
   // Entrada
   int tope;
   // Cómputos
   int numerador = 0;
   int numerador_anterior = 0;
   int denominador = 1;
   int denominador_anterior = 1;
   double productorio = 1;
   int i;
   // Salida
   double pi_aprox;
   cout.precision(15);

   cout << "Introduzca el número de iteraciones (1-100k): ";
   cin >> tope;
   while (tope < 1 || 100000 < tope) {
      cout << "Introduzca un valor correcto: ";
      cin >> tope;
   }

   // MÉTODO BOOLEANO
   /*for (i = 0; i < tope; i++) {
      if (i % 2 == 0)
         numerador += 2;
      else
         denominador += 2;

      productorio *= (numerador * 1.0) / (denominador * 1.0);
   }*/

   // MÉTODO ARITMÉTICO
   for (i = 0; i < tope; i++) {
      numerador = denominador_anterior + 1;
      denominador = numerador_anterior + 1;

      productorio *= (numerador * 1.0) / (denominador * 1.0);

      numerador_anterior = numerador;
      denominador_anterior = denominador;
   }

   pi_aprox = productorio * 2;

   cout << "\nEl número pi, aproximado a " << tope << " iteraciones, vale "
        << pi_aprox;
}

// OBSERVACIONES

/*
   Al contrario que en el ejercicio anterior, el método booleano es más sencillo
   de implementar, pues utiliza menos variables y hace más claro el cambio que
   hay en cada iteración del productorio.
*/
