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

// TARIFA AÉREA CON FILTRO DE ENTRADA DE DATOS

/*
   Recupere la solución del ejercicio 8 [Tarifa aérea con descuentos] de esta
   Relación de Problemas.

   Modifíquelo para obligar al usuario a introducir valores correctos. Por lo
   tanto, debe usar un filtro de entrada de datos para que el número de
   kilómetros sea mayor o igual que cero y el número de puntos sea un valor
   entre 0 y 400 (máximo número posible de puntos).

      Entrada: -2 -5 200 1300 -450 250 −− Salida: 144
      Entrada: 650 1300 -450 90 −− Salida: 185
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
   while (distancia < 0) {
      cout << "Introduzca una distancia positiva: ";
      cin >> distancia;
   }
   cout << "Introduzca el número de puntos de su tarjeta (0-400): ";
   cin >> puntos;
   while (puntos > 0 || 400 < puntos) {
      cout << "Introduzca un número de puntos válido: ";
      cin >> puntos;
   }

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
   De nuevo, usamos los while para mostrar un mensaje de error. De esta manera
   el usuario sabe que algo está haciendo mal y que el programa no ha entrado en
   un bucle infinito.
*/
