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

// FACTORIAL Y POTENCIA

/*
   Calcule mediante un programa en C++ la función potencia x^n, y la función
   factorial n! con n un valor entero y x un valor real.

   No pueden usarse las funciones definidas en cmath, por lo que tendrá que
   implementar los cómputos con los bucles necesarios.

   El factorial de un entero n se define de la forma siguiente:
      0! = 1
      n! = 1 * 2 * 3 * ... * n, ∀n ≥ 1

   Escriba un programa de prueba que lea un número entero n obligando a que esté
   en el intervalo [1, 20]. A continuación lea un valor real x y calcule e
   imprima en pantalla el factorial de n y la potencia de x elevado a n.
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int n;
   double x;
   // Cómputos
   int i;
   // Salida
   int factorial = 1;
   double potencia = 1;

   cout << "Introduzca un valor entero y un valor real: ";
   cin >> n >> x;

   for (i = 2; i <= n; i++) {
      factorial *= i;
   }

   for (i = 0; i < x; i++) {
      potencia *= n;
   }

   cout << "\nn! = " << factorial
        << "\nn^x =" << potencia;
}

// OBSERVACIONES

/*
   Mientras que el for de la potencia utiliza la estructura clásica de
      (i = 0; i < TERMINADOR; i++)
   el for del factorial empieza en 2 y se cumple siempre que i <= n. Esto ocurre
   porque, de esta manera, 0! = 1 y 1! = 1 vienen ya inicializados y no hace
   falta calcularlos y al calcular el resto de factoriales nos ahorramos la
   iteración 1 * 1.
*/
