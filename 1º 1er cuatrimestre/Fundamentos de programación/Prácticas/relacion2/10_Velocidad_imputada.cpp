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

// VELOCIDAD IMPUTADA

/*
   La velocidad de los vehículos en las vías de circulación es captada por unos
   aparatos electrónicos conocidos como radares o cinemómetros. Éstos pueden ser
   fijos o móviles y presentan un margen de error que hay que aplicar a la
   velocidad captada por el radar. Dichos márgenes vienen especificados en la
   orden ITC/3123/2010, de 26 de noviembre:
      https://www.boe.es/diario_boe/txt.php?id=BOE-A-2010-18556

   a) En el caso de un radar fijo:
      I) Si la velocidad captada por el radar es menor o igual que 100 km/h, el
         margen de error es de ± 5km/h.
      II) En caso contrario, el margen de error es de un 5%

   b) En el caso de un radar móvil:
      I) Si la velocidad captada por el radar es menor o igual que 100 km/h, el
         margen de error es de 7km/h.
      II) En caso contrario, el margen de error es de un 7%

   Los márgenes de error se aplican sobre la velocidad captada y da como
   resultado la velocidad imputada. Por ejemplo, si la velocidad captada es de
   95 km/h, la velocidad imputada sería de 95 - 5 = 90 km/h en el caso de un
   radar fijo y de 95 - 7 = 88 km/h en el caso de un radar móvil.

   Si la velocidad captada es, por ejemplo, de 104 km/h, la velocidad imputada
   sería de:
      104 - 5% de 104 = 104 - 5.2 = 98.8 km/h en el caso de un radar fijo
      104 - 7% de 104 = 104 - 7.28 = 96.72 km/h en el caso de un radar móvil.

   Construya un programa que lea desde teclado un carácter que indique el tipo
   de radar ('F' para fijo y cualquier otra letra para móvil), la velocidad
   captada, e imprima la velocidad imputada.

      Entrada: F 95 −− Salida: 90
      Entrada: M 95 −− Salida: 88
      Entrada: F 104 −− Salida: 98.8
      Entrada: M 104 −− Salida: 96.72
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
   // Constantes
   const int VELOCIDAD_MINIMA_FIJO = 5;
   const int VELOCIDAD_MINIMA_FIJO = 7;
   // Entrada
   char radar;
   double velocidad;
   // Salida
   double velocidad_imputada

   cout << "Introduzca el tipo de radar ('F' para fijo, cualquier letra para "
        << "otro tipo) y la velocidad a la que circulaba: ";
   cin >> radar >> velocidad;

   radar = toupper(radar);
   if (radar == 'F') {
      if (velocidad <= VELOCIDAD_MINIMA_FIJO)
         velocidad_imputada = velocidad - 5;
      else
         velocidad_imputada = velocidad - (velocidad * 0.05);
   }
   else {
      if (velocidad <= VELOCIDAD_MINIMA_MOVIL)
         velocidad_imputada = velocidad - 7;
      else
         velocidad_imputada = velocidad - (velocidad * 0.07);
   }

   cout << "\nSe le imputa conducir a " << velocidad_imputada << "km/h.";
}

// OBSERVACIONES

/*
   Utilizamos la función toupper de cctype para asegurarnos que el usuario
   introduce la letra f, no el carácter 'F' en mayúscula.
*/
