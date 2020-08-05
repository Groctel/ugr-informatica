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

// APROXIMACIÓN DE PI POR MADHAVA SIN USAR POW

/*
   En el siglo XIV el matemático indio Madhava of Sangamagrama calculó el arco
   tangente a travéarctan(x)s de un desarrollo de Taylor (este tipo de
   desarrollos se ve en la asignatura de Cálculo)
      arctan(x) = SUM(i=0,∞) -> ((-1)^i * x^(2i+1))/(2i +1)
   Usando como x el valor 1, obtenemos la serie de Leibniz vista en el
   ejercicio 24:
      arctan(1) = π/4 = SUM(i=0,∞) -> (-1)^i/(2i +1)
   Usando como x el valor 1/√3, obtenemos:
      arctan(1/√3) = π/6 = SUM(i=0,∞) -> ((-1)^i * (1/√3)^(2i+1))/(2i +1)
   Por lo tanto, podemos usar la siguiente aproximación:
      π/6 ≈ SUM(i=0,tope) -> ((-1)^i * (1/√3)^(2i+1))/(2i +1)
   Construya un programa que lea el valor tope obligando a que esté entre 1 y
   cien mil, calcule la aproximación de π mediante la anterior serie e imprima
   el resultado en pantalla.
   Importante: En la implementación de esta solución NO puede usar la función
   pow ni ningún condicional if.
      Entrada: 1000 −− Salida: 3.14159265358979
      Entrada: 100000 −− Salida: 3.14159265358979
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   // Constantes
   const double NUMERADOR = 1 / sqrt(3);
   // Entrada
   int tope;
   // Cómputos
   double sumatorio = 0;
   int signo = -1;
   double numerador = sqrt(3);
   double denominador;
   int i;
   // Salida
   double pi_aprox;
   cout.precision(15);

   do {
      cout << "Introduzca el número de iteraciones (1-100k): ";
      cin >> tope;
   } while (tope < 1 || 100000 < tope);

   for (i = 0; i < tope; i++) {
      signo = -signo;
      numerador *= NUMERADOR * NUMERADOR;
      denominador = 2 * i + 1;
      sumatorio += signo * numerador / denominador;
   }

   pi_aprox = sumatorio * 6;

   cout << "El número pi, aproximado a " << tope << " iteraciones, vale "
        << pi_aprox;
}

// OBSERVACIONES

/*

*/
