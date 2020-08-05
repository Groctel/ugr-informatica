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

// COMPARACIÓN DE DOS INSTANTES

/*
   Construya un programa que lea dos instantes de tiempo (según se define en el
   ejercicio 10 [Segundos entre dos instantes] de la Relación de Problemas I) y
   nos diga si el primero es anterior al segundo. Hágalo de dos formas:
      a) Calculando los segundos que hay de diferencia entre ambos instantes,
         tal y como se hizo en el ejercicio 10 [Segundos entre dos instantes] de
         la Relación de Problemas I. Una vez hecho este apartado, inclúyalo como
         un comentario del código.
      b) Sin calcular el número de segundos. Por lo tanto, tendrá que usar los
         valores de la hora, minuto y segundo del instante inicial y compararlos
         apropiadamente con los del instante final.

      Entrada: 9 12 9 10 34 55 −− Salida: El primero es anterior
      Entrada: 10 34 55 9 12 9 −− Salida: El primero no es anterior
      Entrada: 10 34 55 10 34 55 −− Salida: El primero no es anterior
*/

int main() {
   // Constantes
   const int HOR_A_MIN = 60;
   const int MIN_A_SEG = 60;
   // Entrada
   int hora1, minuto1, segundo1;
   int hora2, minuto2, segundo2:
   // Cómputos
   int instante1, instante2;
   bool es_primero_anterior;
   // Salida
   int segundos_entre_instantes;

   cout << "Introduzca un instante siguiendo el formato HH MM SS:";
   cin >> hora1 >> minuto1 >> segundo1;
   cout << "Introduzca otro instante siguiendo el mismo formato: ";
   cin >> hora2 >> minuto2 >> segundo2;

   // MÉTODO ARITMÉTICO
   /*instante1 = (hora1 * HOR_A_MIN + minuto1) * MIN_A_SEG + segundo1;
   instante2 = (hora2 * HOR_A_MIN + minuto2) * MIN_A_SEG + segundo2;

   if (instante1 > instante2)
      es_primero_anterior = true;*/

   // MÉTODO BOOLEANO
   es_primero_anterior = (hora1 > hora2
                       || hora1 == hora2 && minuto1 > minuto2
                       || hora1 == hora2 && minuto1 == minuto2
                          && segundo1 > segundo2);

   cout << "El primero ";
   if (!es_primero_anterior)
      cout << "no ";
   cout << "es anterior."
}

// OBSERVACIONES

/*
   Usamos la tabulación en la asignación del bool para indicar qué operaciones
   van en qué grupo según la jerarquía de operadores lógicos.
*/
