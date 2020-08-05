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

// DIVISORES ANIDADO

/*
   Retome la solución del ejercicio 16 [Divisores de un entero].

   Modifíquelo para que el programa principal lea un número entero ultimo e
   imprima en pantalla los divisores de todos y cada uno de los números
   positivos menor o iguales que último.

      Entrada: 6
      −− Salida:
         Divisores de 6: 2 3
         Divisores de 5: Ninguno
         Divisores de 4: 2
         Divisores de 3: Ninguno
         Divisores de 2: Ninguno
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int numero;
   // Cómputos
   int i, j;
   // Salida
   int divisores;

   cout << "Introduzca un número natural: ";
   cin >> numero;
   while (numero < 0) {
      cout << "El número debe ser positivo: ";
      cin >> numero;
   }

   for (i = numero; i < 1; i --) {
      for (j = i / 2, divisores = 0; j > 1; j--) {
         if (i % j == 0)
            divisores++;
         cout << "\n - Divisores de " << i << ": " << divisores << ".";
      }
   }
}

// OBSERVACIONES

/*
   Cambiamos la variable i del ejercicio anterior a j, ya que se refiere a la
   variable de un for anidado dentro de otro. Siendo un ejercicio sencillo, este
   cambio no es complicado, pero en ejercicios más largos es mejor dejarlo todo
   como estaba para no dejar una variable sin cambiar y llenar el programa de
   errores lógicos.
*/
