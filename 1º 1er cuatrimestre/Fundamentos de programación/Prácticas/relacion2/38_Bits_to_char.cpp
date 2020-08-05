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

// BITS TO CHAR

/*
   Implemente un programa que lea bits (ceros y unos) desde teclado, hasta que
   se introduzca un valor negativo. Si se introduce un positivo distinto de 0 y
   1, el programa lo descartará y volverá a leer un valor. Cada 8 valores de
   bits leídos, el programa calculará el número entero que representa y lo
   transformará en el carácter (char) correspondiente. Debe tener en cuenta que
   el primer bit leído es el más significativo.

   Por ejemplo, si el usuario introduce los siguientes enteros:
      0 1 0 0 1 3 4 1 1 1
   acaba de completar un octeto ya que el 3 y el 4 no son bits (0 o 1) y se
   descartan.

   Por tanto, el octeto completado es 0 1 0 0 1 1 1 1 que corresponde al número
   entero 79 y por tanto al carácter 'O'. El programa debe ir construyendo el
   entero 79 como suma de potencias de 2 (0 ∗ 2^7 + 1 ∗ 2^6 + ...)

   Si no es posible completar el último bloque con 8 bits (porque se haya
   introducido un negativo antes del octavo bit), se descartarán todos los bits
   de ese último bloque incompleto. Si el carácter obtenido corresponde a una
   letra -mayúscula o minúscula- lo mostrará por pantalla.

   Una vez terminada la entrada de datos, el programa mostrará el porcentaje de
   letras y otros símbolos (distintos de letras) leídos.

   Entrada: 0 1 0 0 1 3 4 1 1 1 2 0 1 1 0 1 0 1 1 9 0 0 1 7 0 0 0 0 1 1 0 -1
   −− Salida:
      Ok!
      Letras: 66.67%
      Otros: 33.33%

   Donde las correspondencias son 01001111 → O, 01101011 → k, y 00100001 → !.
   Los bits finales 10 se descartan ya que no se ha completado un octeto.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   // Constante
   const int BITS = 7;
   // Entrada
   int numero;
   // Cómputos
   int bit = BITS;
   int absoluto_letras = 0;
   int absoluto_otros = 0;
   int absoluto_total, i;
   int caracter_numero = 0;
   // Salida
   char caracter;
   double porcentaje_letras, porcentaje_otros;

   cout << "Introduzca un bit (0-1): ";
   cin >> numero;

   while (numero >= 0) {
      if (numero == 1) {
         caracter_numero += pow(2, bit);
         bit--;
      }
      else if (numero == 0) {
         bit--;
      }

      if (bit < 0) {
         caracter = caracter_numero;
         cout << " --> Ha introducido el carácter " << caracter << ".\n\n";

         if ('A' <= caracter && caracter <= 'Z' ||
             'a' <= caracter && caracter <= 'z') {
            absoluto_letras++;
         }
         else {
            absoluto_otros++;
         }

         caracter_numero = 0;
         bit = BITS;
      }

      cout << "Introduzca un bit (0-1): ";
      cin >> numero;
   }

   absoluto_total = absoluto_letras + absoluto_otros;
   porcentaje_letras = ((absoluto_letras * 1.0) / absoluto_total) * 100;
   porcentaje_otros = ((absoluto_otros * 1.0) / absoluto_total) * 100;

   cout << "\nLetras: " << porcentaje_letras << "%."
        << "\nOtros: " << porcentaje_otros << "%.";
}


// OBSERVACIONES

/*

*/
