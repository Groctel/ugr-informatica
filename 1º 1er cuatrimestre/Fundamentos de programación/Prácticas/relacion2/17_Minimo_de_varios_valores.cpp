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

// MÍNIMO DE VARIOS VALORES

/*
   Realice un programa que lea enteros desde teclado y calcule cuántos se han
   introducido y cual es el mínimo de dichos valores (pueden ser positivos o
   negativos). Se dejará de leer datos cuando el usuario introduzca el valor 0.

   Realice la lectura de los enteros dentro de un bucle sobre una única variable
   llamada dato. Es importante controlar los casos extremos, como por ejemplo,
   que el primer valor leído fuese ya el terminador de entrada (en este caso, el
   cero).

      Entrada: 0 −− Salida: 0
      Entrada: 1 3 -1 2 0 −− Salida: -1
      Entrada: 1 3 1 2 0 −− Salida: 1
*/

#include <iostream>
using namespace std;

int main() {
   // Constantes
   const int TERMINADOR = 0;
   // Entrada
   int dato;
   // Cómputos
   bool existe_minimo;
   // Salida
   int minimo;

   cout << "Introduzca una secuencia de números que termine con 0.\n"
        << "Introduzca el primer número: ";
   cin >> dato;

   minimo = dato;
   existe_minimo = (dato != TERMINADOR);

   while (dato != TERMINADOR) {
      if (dato < minimo)
         minimo = dato;

      cout << "Introduzca otro número: ";
      cin >> dato;
   }

   if (exsiste_minimo)
      cout << "\nEl número más pequeño de su secuencia es el " << minimo << ".";
   else
      cout << "\nSu secuencia está vacía.";
}

// OBSERVACIONES

/*
   En este caso, como podemos separar las entradas de las salidas, utilizamos
   un bool para comprobar las diferentes opciones de salida.

   Usamos la constante terminador en lugar de referirmos al literal 0
   directamente para hacer el código más fácil de mantener. Esto se verá mucho
   más en ejercicios posteriores.
*/
