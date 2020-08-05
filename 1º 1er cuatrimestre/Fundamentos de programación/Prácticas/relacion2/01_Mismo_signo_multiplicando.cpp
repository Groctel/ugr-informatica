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

// MISMO SIGNO: MULTIPLICANDO

/*
   Construya un programa que lea dos datos a y b de tipo int y nos diga si
   tienen el mismo signo. Se considera que el cero no tiene signo por lo que
   cualquier número (incluido el cero) tiene un signo distinto del cero. Para
   ello, basta comprobar si la multiplicación de a y b es positiva o no.

      Entrada: 0 0 −− Salida: No tienen el mismo signo
      Entrada: 0 3 −− Salida: No tienen el mismo signo
      Entrada: 3 0 −− Salida: No tienen el mismo signo
      Entrada: 3 4 −− Salida: Tienen el mismo signo
      Entrada: -3 -4 −− Salida: Tienen el mismo signo
      Entrada: 3 -4 −− Salida: No tienen el mismo signo
      Entrada: -3 4 −− Salida: No tienen el mismo signo
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int numero1, numero2;
   // Cómputos
   bool tienen_mismo_signo;

   cout << "Introduzca dos números enteros: ";
   cin >> numero1 >> numero2;

   tienen_mismo_signo = (numero1 * numero2 > 0);

   cout << "\nLos números " << numero1 << " y " << numero2;
   if (!tienen_mismo_signo)
      cout << " no";
   cout << " tienen el mismo signo";
}

// OBSERVACIONES

/*
   Para asignar un bool como true o false asignamos dicho bool a una expresión
   booleana en lugar de usar un if, que lo dejaremos para casos en los que
   tengamos que decidir qué acción realizar en función de un valor booleano,
   como ocurre en la salida de datos. Esto tiene la ventaja de que hace que no
   sea necesario inicializar los bool a true o false para ahorrar código.

   Encapsulamos la operación booleana entre paréntesis paa hacerla más sencilla
   de leer, aunque no es estrictamente necesario.

   Como en el cout sólo cambia una palabra, podemos poner el if en medio para
   no tener que repetir el mensaje dos veces. Esta es una ventaja que tiene
   separar las entradas de las salidas y los cómputos.
*/
