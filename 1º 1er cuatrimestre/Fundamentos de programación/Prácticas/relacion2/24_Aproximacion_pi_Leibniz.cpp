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

// APROXIMACIÓN DE PI POR GEORGE LEIBNIZ

/*
   En el siglo XVII el matemático alemán Gottfried Leibniz y el matemático
   escocés James Gregory introdujeron una forma de calcular π a través de una
   serie, es decir, de una suma de términos:
      π/4 = SUM(i=0,∞) -> (-1)^i/(2i +1)

   Esta es una serie infinita, pues realiza la suma de infinitos términos. Como
   en Programación no podemos realizar un número infinito de operaciones, habrá
   que parar en un índice dado, llamémosle tope, obteniendo por tanto una
   aproximación al valor de π. Usaremos el símbolo ≈ para denotar esta
   aproximación:
      π/4 ≈ SUM(i=0,tope) -> (-1)^i/(2i +1)

   Construya un programa que lea el valor tope obligando a que esté entre 1 y
   cien mil, calcule la aproximación de π mediante la anterior serie e imprima
   el resultado en pantalla.

   Resuelva este problema de dos formas distintas:
      a) Usando la función pow (potencia) de cmath para implementar (−1)^i.
      b) Sin usar la función pow. Observe que el valor de (−1)^i es 1 para los
         valores pares de i y −1 para los impares.

   Recuerde que, para visualizar 15 cifras decimales, por ejemplo, debe incluir
   la sentencia cout.precision(15); antes de realizar la salida en pantalla.

      Entrada: 1000 −− Salida: 3.14259165433954
      Entrada: 100000 −− Salida: 3.14160265348972
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int tope;
   // Cómputos
   double sumatorio, numerador;
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

   // MÉTODO ARITMÉTICO
   for (i = 0; i < tope; i++) {
      sumatorio += pow (-1, i) / (2 * i + 1);
   }

   // MÉTODO BOOLEANO
   /*for (i = 0; i < tope; i++) {
      if (i % 2 == 0)
         numerador = 1;
      else
         numerador = -1;

      sumatorio += numerador / (2 * i + 1);
   }*/

   pi_aprox = sumatorio * 4;

   cout << "El número pi, aproximado a " << tope << " iteraciones, vale "
        << pi_aprox;
}

// OBSERVACIONES

/*
   El método aritmético es mucho más sencillo de implementar que el booleano,
   pero este último nos podría servir si hubiera que hacer más modificaciones en
   función del signo del numerador.
*/
