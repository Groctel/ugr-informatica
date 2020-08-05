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

// PASAR DE MAYÚSCULA A MINÚSCULA Y VICEVERSA

/*
   Queremos modificar el ejercicio 7 para leer un carácter letra_original desde
   teclado y hacer lo siguiente:
      - Si es una letra mayúscula, almacenaremos en la variable letra_convertida
        la correspondiente letra minúscula.
      - Si es una letra minúscula, almacenaremos en la variable letra_convertida
        la correspondiente letra mayúscula.
      - Si es un carácter no alfabético, almacenaremos el mismo carácter en la
      variable letra_convertida

   El programa debe imprimir en pantalla el valor de letra_convertida e indicar
   si la letra introducida era una minúscula, mayúscula o no era una carácter
   alfabético.

   No pueden usarse las funciones tolower ni toupper de la biblioteca cctype.
*/

#include <iostream>
using namespace std;

int main() {
   // Constantes
   const char MAY_A_MIN = 'a' - 'A'
   // Entrada
   char letra_inicial;
   // Cómputos
   bool es_minuscula, es_mayuscula;
   // Salida
   char letra_convertida;

   cout << "Introduzca una letra: ";
   cin >> letra_inicial;

   es_mayuscula = ('A' <= letra_inicial && letra_inicial <= 'Z');
   es_minuscula = ('a' <= letra_inicial && letra_inicial <= 'z');

   if (es_mayuscula)
      letra_convertida = letra_inicial + MAY_TO_MIN;
   else if (es_minuscula)
      letra_convertida = letra_inicial - MAY_TO_MIN;
   else
      letra_convertida = letra_inicial;

   cout << "\nSu caracter original ";
   if (es_mayuscula)
      cout << "era una mayúscula ";
   else if (es_minuscula)
      cout << "era una minúscula ";
   else
      cout << "no era una letra ";
   cout << "y al convertirla queda así: '" << letra_convertida << "'."
}

// OBSERVACIONES

/*
   Utilizamos dos bool que determinan las propiedades del carácter si fuese una
   letra. Como ambos son mutuamente excluyentes, si ninguno de los dos es true,
   el carácter no es una letra.

   En el ejercicio 15 de esta relación se ve cómo hacer lo mismo con un enum en
   lugar de con varios bool.
*/
