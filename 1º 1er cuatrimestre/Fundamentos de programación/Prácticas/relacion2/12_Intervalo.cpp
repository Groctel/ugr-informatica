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

// INTERVALO

/*
   Recupere la solución del ejercicio 13 [Lectura de un intervalo] de la
   Relación de Problemas I. Después de haber leído los datos que definen el
   intervalo el programa debe leer un valor real y determinar si está o no
   dentro del intervalo.

      Entrada: (3.5 , 5.1] 4.8
      −− Salida: El valor 4.8 está dentro del intervalo (3.5, 5.1]
      Entrada: (3.5 , 5.1] 8.3
      −− Salida: El valor 8.3 no está dentro del intervalo (3.5, 5.1]
      Entrada: (3.5 , 5.1] 3.5
      −− Salida: El valor 3.5 no está dentro del intervalo (3.5, 5.1]
      Entrada: (3.5 , 5.1] 5.1
      −− Salida: El valor 5.1 está dentro del intervalo (3.5, 5.1]
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   char extremo_inf, coma, extremo_sup;
   double cota_inf, cota_sup, numero;
   // Salida
   bool esta_dentro;

   cout << "Introduzca un intervalo siguendo el siguiente formato:"
        << "\n  - Extremos cerrados -> []"
        << "\n  - Extremos abiertos -> ][ ó ()"
        << "\n  - Introduzca una coma entre ambas cotas"
        << "\n  - Su intervalo debería ser similar a [3,4) o ]8,12[\n>"
   cin >> extremo_inf >> cota_inf >> coma >> cota_sup >> extremo_sup;
   cout << "Introduzca ahora un número: ";
   cin >> numero;

   esta_dentro = (cota_inf < numero && numero < cota_sup
               || numero == cota_inf && extremo_inf == '['
               || numero == cota_sup && extremo_sup == ']');

   cout << "El número " << numero;
   if (!esta_dentro)
      cout << " no";
   cout << " pertenece al intervalo " << extremo_inf << cota_inf << coma
        << cota_sup << extremo_sup << ".";
}

// OBSERVACIONES

/*
   Utilizamos sólo una comprobación para ver si está dentro. Por razones de
   legibilidad, iniciamos cada línea con ||, indicando así que la asignación no
   ha terminado aún.
*/
