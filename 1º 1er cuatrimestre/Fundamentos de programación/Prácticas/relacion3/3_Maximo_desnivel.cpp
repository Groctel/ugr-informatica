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

// MÁXIMO DESNIVEL

/*
   Supongamos un vector de enteros relativo a un conjunto de alturas de un track
   GPS. Cada entero representa la altura de la posición GPS en un instante dado.

   Se quiere calcular lo siguiente:
      - Máximo desnivel (máxima diferencia en valor absoluto) entre dos alturas
        consecutivas.
           Por ejemplo, si el vector es
              1 3 2 4 7 5
           las diferencias son
              +2 -1 +2 +3 -2
           siendo 3 la máxima en valor absoluto.
           Si el vector fuese
              1 3 2 4 1 2
           las diferencias serían
              +2 -1 +2 -3 +1
           siendo 3 la máxima en valor absoluto.
      - Desnivel acumulado positivo.
        La idea es ir buscando puntos consecutivos en los que la altura vaya
        aumentando. El desnivel acumulado se calcula como la suma de todas esas
        diferencias positivas.
           Por ejemplo, si el vector es
              1 3 2 4 7 5
           las diferencias son
              +2 -1 +2 +3 -2
           por lo que el desnivel acumulado positivo será 7 (sumando +2 +2 +3).

   Construir un programa que, en primer lugar, lea un número entero que indique
   el número de valores de altura que se van a introducir. A continuación el
   programa leerá dichos valores y los almacenará en un vector. El programa
   calculará el máximo desnivel y el desnivel acumulado positivo y los imprimirá
   en pantalla.

      Entrada: 6 1 3 2 4 7 5 −− Salida: 3 7
      Entrada: 2 4 1 −− Salida: 3 0
      Entrada: 1 7 −− Salida: No hay datos suficientes
*/

#include <iostream>
using namespace std;

int main() {
   // Entrada
   int comp_alturas, dato_altura;
   // Cómputos
   int comp_desniveles, posicion;
   int pos_max_desnivel = 0;
   // Salida
   int max_desnivel = 0;
   int desnivel_consecutivo = 0;

   cout << "Introduzca el número de datos que desea comparar: ";
   cin >> comp_alturas;
   comp_desniveles = comp_alturas - 1;
   int alturas[comp_alturas];
   int desniveles[comp_desniveles];

   for (posicion = 0; posicion < comp_alturas; posicion++) {
      cout << "Introduzca el dato de altura " << posicion << ": ";
      cin >> dato_altura;
      alturas[posicion] = dato_altura;
   }

   for (posicion = 1; posicion < comp_alturas; posicion++) {
      desniveles[posicion - 1] = alturas[posicion] -
                                 alturas[posicion - 1];
   }

   for (posicion = 0; posicion < comp_desniveles; posicion++) {
      if (abs(desniveles[posicion]) > abs(desniveles[pos_max_desnivel]))
         pos_max_desnivel = posicion;
      if (desniveles[posicion] >= 0)
         desnivel_consecutivo += desniveles[posicion];
   }
   max_desnivel = abs(desniveles[pos_max_desnivel]);

   cout << "\nEl punto de máximo desnivel es: " << max_desnivel << ".";
   cout << "\nLa consecución de desniveles es: " << desnivel_consecutivo << ".";
}

// OBSERVACIONES

/*

*/
