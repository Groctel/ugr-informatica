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

// NÚMERO FELIZ

/*
   Se dice que un número natural es feliz si cumple que si sumamos los cuadrados
   de sus dígitos y seguimos el proceso con los resultados obtenidos, finalmente
   obtenemos uno (1) como resultado. Por ejemplo, el número 203 es un número
   feliz ya que
      2^2 + 0^2 + 3^2 = 13 -> 1^2 + 3^2 = 10 -> 1^2 + 0^2 = 1.

   Se dice que un número es feliz de grado k si se ha podido demostrar que es
   feliz en un máximo de k iteraciones. Se entiende que una iteración se produce
   cada vez que se elevan al cuadrado los dígitos del valor actual y se suman.
   En el ejemplo anterior, 203 es un número feliz para cualquier grado mayor o
   igual que 3.

   En general, si un número es feliz de grado k' también es feliz para cualquier
   grado k ≥ k'

   Escriba un programa que lea un valor entero n y un valor k. Si el número es
   feliz para un grado k' menor o igual que k, el programa parará y mostrará
   dicho grado k'. En caso contrario, el programa nos dirá que no es feliz para
   cualquier grado menor o igual que k.

      Entrada: 13 2 −− Salida: Es feliz para cualquier grado >= 2
      Entrada: 13 5 −− Salida: Es feliz para cualquier grado >= 2
      Entrada: 13 1 −− Salida: No es feliz para cualquier grado <= 1
      Entrada: 203 1 −− Salida: No es feliz para cualquier grado <= 1
      Entrada: 203 7 −− Salida: Es feliz para cualquier grado >= 3
      Entrada: 102 6 −− Salida: No es feliz para cualquier grado <= 6
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
   // Entrada
   int numero_inicial, grado;
   // Cómputos
   int numero_procesado, numero_referencia, cifra_aislada;
   int i;
   bool encontrado = false;
   // Salida
   int grado_final;

   cout << "Introduzca un número: ";
   cin >> numero_inicial;
   cout << "Introduzca el grado de iteraciones al que desea calcular: ";
   cin >> grado;

   numero_procesado = numero_inicial;
   for (i = 0; i < grado && !encontrado; i++) {
      numero_referencia = numero_procesado;
      numero_procesado = 0;

      while (numero_referencia > 0) {
         cifra_aislada = numero_referencia % 10;
         numero_procesado += pow(cifra_aislada, 2);
         numero_referencia /= 10;
      }

      encontrado = numero_procesado == 1;
      if (encontrado)
         grado_final = ++i;
   }

   cout << "\nEl número " << numero_inicial;
   if(encontrado){
      cout << " es feliz para grados >= " << grado_final << ".";
   }
   else
      cout << " no es feliz para grados <= " << grado << ".";
}

// OBSERVACIONES

/*

*/
