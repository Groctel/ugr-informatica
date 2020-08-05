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

// MAYÚSCULA A MINÚSCULA Y VICEVERSA USANDO UN ENUMERADO

/*
   Modifique la solución del ejercicio 9 [Pasar de mayúscula a minúscula y
   viceversa] para que, dependiendo de cómo era la letra introducida, imprima en
   pantalla alguno de los siguientes mensajes:

      - La letra era una mayúscula. Una vez convertida es ...
      - La letra era una minúscula. Una vez convertida es ...
      - El carácter no era una letra.

   Hágalo separando entradas y salidas de los cómputos. Para ello, utilice una
   variable de tipo enumerado que represente las opciones de que un carácter sea
   una mayúscula, una minúscula o un carácter no alfabético.
*/

#include <iostream>
using namespace std;

enum class TipoCaracter
   {mayuscula, minuscula, no_es_letra}

int main() {
   // Constantes
   const char MAY_A_MIN = 'a' - 'A'
   // Entrada
   char letra_inicial;
   // Cómputos
   TipoCaracter tipo_caracter = TipoCaracter::no_es_letra;
   // Salida
   char letra_convertida;

   cout << "Introduzca una letra: ";
   cin >> letra_inicial;

   if ('A' <= letra_inicial && letra_inicial <= 'Z') {
      letra_convertida = letra_inicial + MAY_TO_MIN;
      tipo_caracter = TipoCaracter::mayuscula;
   }
   else if ('a' <= letra_inicial && letra_inicial <= 'z') {
      letra_convertida = letra_inicial - MAY_TO_MIN;
      tipo_caracter = TipoCaracter::minuscula;
   }
   else {
      letra_convertida = letra_inicial;
   }

   cout << "\nSu caracter original ";
   if (tipo_caracter == TipoCaracter::mayuscula)
      cout << "era una mayúscula ";
   else if (tipo_caracter == TipoCaracter::minuscula)
         cout << "era una minúscula ";
   else
      cout << "no era una letra ";
   cout << "y al convertirla queda así: '" << letra_convertida << "'."
}

// OBSERVACIONES

/*
   Inicializamos el valor del enum a la excepción (no_es_letra) para hacer más
   legible el código y poder poner dicho caso excepcional como un else.
*/
