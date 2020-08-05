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

// TARIFA AÉREA

/*
   Retome la solución del ejercicio 6 [Tarifa aérea según km] de la Relación de
   Problemas I. La forma de calcular la tarifa final del billete cambia ahora de
   la forma siguiente: la tarifa base sigue siendo de 150 euros, la misma para
   todos los destinos. Ahora bien, si el destino está a menos de 300 kilómetros,
   el precio final es la tarifa base. Para destinos a más de 300 Km, se suman 10
   céntimos por cada kilómetro de distancia al destino (a partir del Km 300).

   Cree un programa para que lea el número de kilómetros al destino y calcule el
   precio final del billete.

      Entrada: 120 −− Salida: 150
      Entrada: 300 −− Salida: 150
      Entrada: 301 −− Salida: 150.1
      Entrada: 452 −− Salida: 165.2
*/

int main() {
   // Constantes
   const int BASE = 15000;
   const int PRECIO_KM = 10;
   const int DISTANCIA_MINIMA = 300;
   const int CENTIMOS_A_EUROS = 100.0;
   // Entrada
   int distancia;
   // Cómputos
   int precio_centimos = BASE;
   // Salida
   double precio_euros;

   cout << "Introduzca la longitud en kilómetros de su vuelo: ";
   cin >> distancia;

   if (distancia > DISTANCIA_MINIMA)
      precio_centimos += PRECIO_KM * distancia;

   precio_euros = precio_centimos / CENTIMOS_A_EUROS;

   cout << "Su billete vale " << precio_euros << "€.";
}

// OBSERVACIONES

/*
   Como la tarifa base es la misma para todos y sólo se varía el precio a partir
   de la distancia mínima, inicializamos el precio a la hora de declararlo y
   luego le sumamos el precio variable unitario a partir de los 300km.
*/
