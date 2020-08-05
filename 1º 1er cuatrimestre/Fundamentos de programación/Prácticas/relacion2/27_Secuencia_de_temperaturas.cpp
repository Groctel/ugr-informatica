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
   Construya un programa que calcule cuándo se produjo la mayor secuencia de
   días consecutivos con temperaturas crecientes. El programa leerá una
   secuencia de reales representando temperaturas. La entrada de datos parará
   cuando se introduzca una temperatura fuera del rango [-90, 60].

   El programa debe calcular la subsecuencia de números ordenada, de menor a
   mayor, de mayor longitud. El programa nos debe decir la posición donde
   comienza la subsecuencia y su longitud.

   Por ejemplo, ante la entrada siguiente:
      17.2 17.3 16.2 16.4 17.1 19.2 18.9 100
   el programa nos debe indicar que la mayor subsecuencia empieza en la posición
   3 (en el 16.2) y tiene longitud 4 (termina en 19.2)

   En este ejercicio, es posible que tenga que repetir algo de código y comparar
   distintas temperaturas con los extremos del rango [-90,60].

      Entrada: 17.2 17.3 16.2 16.4 17.1 19.2 18.9 100
      −− Salida: Inicio: 3 Longitud: 4
      Entrada: 17.2 17.3 16.2 16.4 17.1 19.2 100
      −− Salida: Inicio: 3 Longitud: 4
      Entrada: 17.2 17.3 100
      −− Salida: Inicio: 1 Longitud: 2
      Entrada: 17.2 15.3 100
      −− Salida: Inicio: 1 Longitud: 1
      Entrada: 17.2 100
      −− Salida: Inicio: 1 Longitud: 1
      Entrada: 100
      −− Salida: Inicio: 1 Longitud: 0
*/

#include <iostream>
using namespace std;

int main () {
   // Constantes
   const int cota_inf = -90;
   const int cota_sup = 60;
   const int LONGITUD_BASE = 1;
   // Entrada
   double temperatura;
   // Cómputos
   int longitud = 0;
   int posicion = 1;
   int iteracion = 1;
   double temperatura_anterior = -90;
   // Salida
   int longitud_max = LONGITUD_BASE;
   int posicion_max = posicion;

   cout << "Introduzca una temperatura: ";
   cin >> temperatura;

   while (cota_inf <= temperatura && temperatura <= cota_sup) {
      // Me acojo a la definición de "creciente" vs "estrictamente creciente"
      if (temperatura >= temperatura_anterior) {
         longitud++;
      }
      else {
         longitud = LONGITUD_BASE;
         posicion = iteracion;
      }

      // Guarda la última de todas las iteraciones máximas
      if (longitud >= longitud_max){
         longitud_max = longitud;
         posicion_max = posicion;
      }

      iteracion++;
      temperatura_anterior = temperatura;

      cout << "Introduzca otra temperatura: ";
      cin >> temperatura;
   }

   cout << "\nLa secuencia más grande de temperaturas crecientes comienza en la posición "
      << posicion_max << " y tiene una longitud de " << longitud_max << " elementos.";
}
