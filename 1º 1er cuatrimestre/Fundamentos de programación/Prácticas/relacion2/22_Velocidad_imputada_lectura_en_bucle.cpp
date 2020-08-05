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

// VELOCIDAD IMPUTADA: LECTURA EN BUCLE

/*
   Recupere la solución del ejercicio 10 [Velocidad imputada] de esta Relación
   de Problemas.

   Modifique el programa principal para que vaya leyendo los siguientes datos
   dentro de un bucle: en primer lugar, se leerá la matrícula del vehículo (en
   un dato de tipo string), a continuación el tipo de radar (dato de tipo char)
   y finalmente la velocidad del vehículo (en un dato de tipo double).

   Supondremos que el carácter 'F' está asociado al radar fijo y el carácter
   'M' al radar móvil y que el usuario introduce un carácter correcto.

   El programa calculará las velocidades imputadas según se indicó en el
   ejercicio 10 [Velocidad imputada] e imprimirá en pantalla la matrícula de
   aquel vehículo que tenga máxima velocidad imputada (también imprimirá dicha
   velocidad).

   La lectura de los datos terminará cuando la matrícula del vehículo sea la
   cadena "#"

      Entrada: 4312BHG F 95 8342DFW F 104 4598IJG M 95 # −− Salida: 8342DFW 98.8
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
   // Constantes
   const int VELOCIDAD_MINIMA_FIJO = 5;
   const int VELOCIDAD_MINIMA_FIJO = 7;
   const char TERMINADOR = '#';
   // Entrada
   char radar;
   double velocidad;
   string matricula;
   // Cómputos y salida
   string max_matricula_imputada;
   double max_velocidad_imputada;

   cout << "Introduzca su matrícula: ";
   cin >> matricula;

   while (matricula != TERMINADOR) {
      cout << "Introduzca el tipo de radar ('F' para fijo, 'M' para móvil) y la "
           << "velocidad a la que circulaba: ";
      cin >> radar >> velocidad;

      radar = toupper(radar);
      if (radar == 'F') {
         if (velocidad <= VELOCIDAD_MINIMA_FIJO)
            velocidad_imputada = velocidad - 5;
         else
            velocidad_imputada = velocidad - (velocidad * 0.05);
      }
      else if (radar == 'M'){
         if (velocidad <= VELOCIDAD_MINIMA_MOVIL)
            velocidad_imputada = velocidad - 7;
         else
            velocidad_imputada = velocidad - (velocidad * 0.07);
      }

      if (velocidad > max_velocidad_imputada) {
         max_velocidad_imputada = velocidad;
         max_matricula_imputada = matricula;
      }

      cout << "Introduzca otra matrícula: ";
      cin >> matricula;
   }

   cout << "\nSe le imputa conducir a " << max_velocidad_imputada << "km/h con un "
        << "vehículo con matrícula " << max_matricula_imputada << ".\n"
        << "El resto de vehículos introducidos circulaban a una velocidad inferior.";
}

// OBSERVACIONES

/*
   Como el terminador se encuentra en la matrícula, metemos dentro del bucle el resto
   de entradas para no repetir código.
*/
