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

// TARIFA AÉREA CON DESCUENTOS

/*
   Recupere la solución del ejercicio 5 [Tarifa aérea] de esta Relación de
   Problemas. Una vez se ha obtenido el precio del billete (según el número de
   kilómetros recorridos), se quieren aplicar varios descuentos acumulativos.

   Un primer descuento vendrá determinado por el número de kilómetros del
   trayecto. El segundo descuento dependerá del número de puntos de la tarjeta
   de fidelización del cliente que ha comprado el billete. En concreto:
      a) Si el trayecto es mayor de 700 km, se aplica un descuento del 2 %
      b) Si el número de puntos es mayor de 100, se aplica un descuento del 3 %
         y si es mayor de 200, se aplica un descuento del 4 %.

   Los dos descuentos anteriores (por longitud del trayecto y el correspondiente
   al número de puntos), son independientes y acumulables. En cualquier caso,
   ambos se aplican sobre el precio del billete, es decir, un descuento no se
   aplica sobre el resultado de haber aplicado previamente el otro descuento.
   Por lo tanto, un cliente podría beneficiarse de un descuento del 2%, del 3%,
   del 4%, del 5%, del 6%, o ninguno.

   Construya un programa que lea el número de kilómetros del trayecto y el
   número de puntos del cliente e imprima en pantalla el precio final del
   billete con los descuentos aplicados, en su caso.

      Entrada: 200 90 −− Salida: 150
      Entrada: 200 120 −− Salida: 145.5
      Entrada: 200 250 −− Salida: 144
      Entrada: 650 90 −− Salida: 185
      Entrada: 650 120 −− Salida: 179.45
      Entrada: 800 90 −− Salida: 196
      Entrada: 800 120 −− Salida: 190
      Entrada: 800 250 −− Salida: 188
*/

#include <iostream>
#using namespace std;

int main() {
   // Constantes
   const int BASE = 15000;
   const int PRECIO_KM = 10;
   const int DISTANCIA_MINIMA = 300;
   const int DISTANCIA_DESCUENTO = 700;
   const int PUNTOS_DESCUENTO1 = 100;
   const int PUNTOS_DESCUENTO2 = 200;
   const int CENTIMOS_A_EUROS = 100.0;
   // Entrada
   int distancia, puntos;
   // Cómputos
   int precio_centimos = BASE;
   double descuento;
   // Salida
   double precio_euros;

   cout << "Introduzca la longitud en kilómetros de su vuelo: ";
   cin >> distancia;
   cout << "Introduzca el número de puntos de su tarjeta: ";
   cin >> puntos;

   if (distancia > DISTANCIA_MINIMA)
      precio_centimos += PRECIO_KM * distancia;

   if (distancia > DISTANCIA_DESCUENTO)
      descuento = 2;

   if (puntos > PUNTOS_DESCUENTO2)
      descuento += 4;
   else if (puntos > PUNTOS_DESCUENTO1)
      descuento += 3;

   descuento /= 100;
   precio_centimos -= precio_centimos * descuento;
   precio_euros = precio_centimos / CENTIMOS_A_EUROS;

   cout << "Su billete vale " << precio_euros << "€.";
}

// OBSERVACIONES

/*
   Para evitar errores de aproximación a la hora de sumar los descuentos, los
   tratamos primeros como números enteros y luego los dividimos entre 100.
*/
