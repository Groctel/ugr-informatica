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

// CONVERTIR MAYÚSCULA EN MINÚSCULA

/*
   Se quiere leer un carácter letra_original desde teclado, y comprobar con una
   estructura condicional si es una letra mayúscula. En dicho caso, hay que
   calcular la minúscula correspondiente almacenando el resultado en una
   variable llamada letra_convertida. En el caso de que no sea una mayúscula, le
   asignaremos a letra_convertida el valor que tenga letra_original. Finalmente,
   imprimiremos en pantalla el valor de letra_convertida.

   No pueden usarse las funciones tolower ni toupper de la biblioteca cctype.

      Entrada: D −− Salida correcta: d
      Entrada: d −− Salida correcta: d
      Entrada: ! −− Salida correcta: !
*/

#include <iostream>
using namespace std;

int main() {
   // Constantes
   const char MAY_A_MIN = 'a' - 'A'
   // Entrada
   char letra_inicial;
   // Salida
   char letra_convertida;

   cout << "Introduzca una letra: ";
   cin >> letra_inicial;

   if ('A' <= letra_inicial && letra_inicial <= 'Z')
      letra_convertida = letra_inicial + MAY_TO_MIN;
   else
      letra_convertida = letra_inicial;

   cout << "\nSu letra convertida es: '" << letra_convertida << "'."
}

// OBSERVACIONES

/*
   Escribimos la comprobación del if como si se tratase de un intervalo para
   hacerlo más fácil de leer y mantener.
*/
