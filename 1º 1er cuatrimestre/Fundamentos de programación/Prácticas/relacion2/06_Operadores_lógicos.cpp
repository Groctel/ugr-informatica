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

// OPERADORES LÓGICOS

/*
   En este ejercicio no hace falta construir ningún programa. Debe crear un
   fichero de texto (con extensión cpp o txt) explicando qué problemas observa
   en los siguientes condicionales:

   a) char tipo_radar;
      cin >> tipo_radar;
      if (tipo_radar == 'F' && tipo_radar == 'f')
         ......

   b) double velocidad;
      cin >> velocidad;
      if (velocidad > 100 && velocidad < 70)
         cout << "\nVelocidad fuera del rango";

   c) double velocidad;
      cin >> velocidad;
      if (velocidad > 100 || velocidad > 110)
         cout << "Velocidad excesiva";
*/

// OBSERVACIONES

/*
   CONDICIONAL A:
      Un carácter no puede ser a la vez una letra mayúscula y minúscula. Para
      arreglar esto podemos cambiar el && por || o, usando la biblioteca cctype,
      realizar la siguiente asignación:
         tipo_radar = toupper(tipo_radar);
      De esta manera, siempre se comprueba la letra mayúscula.

   CONDICIONAL B:
      El intervalo de velocidades es menor que 70 y mayor que 100. Aún no he
      visto un vehículo que pueda alcanzar dos velocidades distintas a la vez;
      y si lo hubiese, sería carísmo.

   CONDICIONAL C:
      Si velocidad > 110, siempre se va a cumplir que velocidad > 100, ya sea
      con || o con &&, por lo que sólo necesitamos evaluar el mayor valor de los
      mayores (o el menor valor de los menores cuando proceda).
*/
