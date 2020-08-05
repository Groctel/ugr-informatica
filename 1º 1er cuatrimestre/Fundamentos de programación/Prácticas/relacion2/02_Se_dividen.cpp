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

// SE DIVIDEN

/*
   Realice un programa que lea dos valores enteros desde teclado y diga si
   cualquiera de ellos divide o no (de forma entera) al otro. En este problema
   no hace falta decir quién divide a quién. Supondremos que los valores leídos
   desde teclado son ambos distintos de cero.

      Entrada: 3 4 −− Salida: Ninguno divide al otro
      Entrada: 2 4 −− Salida: Uno de ellos divide al otro
      Entrada: 4 2 −− Salida: Uno de ellos divide al otro
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int numero1, numero2;
   // Cómputos
   bool son_divisores = false;

   cout << "Introduzca dos números enteros distintos de cero: ";
   cin >> numero1 >> numero2;

   son_divisores = (numero1 % numero2 == 0
                 || numero2 % numero1 == 0);

   if (son_divisores)
      cout << "\nUno de ellos ";
   else
      cout << "\nNinguno ";
   cout << "divide al otro.";
}

// OBSERVACIONES

/*
   Al igual que en el ejercicio anterior, el inicio de la salida viene marcado
   por un if y luego se imprime el resto, que es común para ambas salidas.
*/
