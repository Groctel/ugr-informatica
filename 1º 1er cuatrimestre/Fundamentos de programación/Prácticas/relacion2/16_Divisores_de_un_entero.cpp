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

// DIVISORES DE UN ENTERO

/*
   Realice un programa que lea desde teclado un entero tope e imprima en
   pantalla todos sus divisores positivos propios (diferentes de 1 y él mismo).

   Para obtener los divisores, basta recorrer todos los enteros menores que el
   valor introducido y comprobar si lo dividen.

   A continuación, mejorar el ejercicio obligando al usuario a introducir un
   entero positivo, usando un filtro con un bucle post test (do while).

      Entrada: 16 −− Salida: 2, 4, 8
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int numero;
   // Cómputos y salida
   int i;

   cout << "Introduzca un número natural: ";
   cin >> numero;
   while (numero < 0) {
      cout << "El número debe ser positivo: ";
      cin >> numero;
   }

   for (i = numero / 2; i > 1; i--) {
      if (numero % i == 0)
         cout << "\n - " << i << " es divisor de " << numero << ".";
   }
}

// OBSERVACIONES

/*
   Para dividir los cómputos de la salida en este ejercicio habría que utilizar
   un vector en el que fuéramos introduciendo todos los divisores y luego
   mostrarlos recorriendo dicho vector. Como este tipo de ejercicios no se ven
   hasta la relación 3, utilizamos un bucle con la salida dentro de él.

   Por otro lado, éste es el primer ejercicio de bucles y quiero dejar claro
   algo que se va a repetir a lo largo del resto de ejercicios. Si un bucle
   tiene una variación de su contador constante usaré siempre un for. Si dicha
   variación es diferente según qué caso, usaré un while a menos que el caso en
   el que varíe sea una excepción y se pueda afrontar de forma fácilmente
   legible. En casos en los que la condición de salida venga determinada por una
   expresión booleana usaré un while.

   En el enunciado también se pide usar un filtro de datos mediante un do while.
   Personalmente, a mí me gusta más usar un while que compruebe si se cumple la
   condición que lanza el filtro y mostrarlo a modo de mensaje de error. Eso ya
   cada uno le da el estilo que quiere.
*/
