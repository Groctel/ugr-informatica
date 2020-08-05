<center><h1>FUNCIONES</h1></center>
<center><b>Fundamentos de programación</b></center>

<<<<<<< HEAD


=======
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128
## INTRODUCCIÓN

Las funciones son estructuras que permiten agrupar en una sola pieza de código una serie de sentencias que se van ejecutar varias veces, ya sea de la misma manera o con algunas variaciones.

Por ejemplo, en lugar de tener que escribir siempre este tochazo:

```c++
if (x == 0 || x == 1) {
   result = x;
}
else {
   for (int i = 1, result = 1; result <= x; i++) {
      result = i * i;
   }
}
```

Podemos simplemente importar una función definida en una biblioteca:

```c++
#include <cmath>
<<<<<<< HEAD
#include <iostream>
using namespace std;

int main() {
   double x, raiz;
   
   cin >> x;
   
   raiz = sqrt(x); // sqrt() viene ya definida en cmath
   
   cout << raiz;
}
=======

...

result = sqrt(x);
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128
```

Otro ejemplo, vamos a calcular el módulo de dos vectores:

```c++
int main() {
   int v1_A, v1_B, v2_A, v2_B;
   double modulo1, modulo2;
   
   ...
   
   modulo1 = sqrt(pow(v1_A, 2) + pow(v1_B, 2));
   modulo2 = sqrt(pow(v2_A, 2) + pow(v2_B, 2));
}
```

<<<<<<< HEAD
En este caso los cálculos son muy similares y pueden dar errores a la hora de copiar y pegar además de que es mucho más difícil de mantener. Para evitar esto, trabajaremos con funciones.
=======
En este caso los cálculos son muy similares y pueden dar errores. Para evitar esto, trabajaremos con funciones.
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128

## DEFINICIÓN

Para definir una función seguimos la siguiente estructura:

```
[tipo de dato] [nombre de la función]([parámetros formales]) {
   [sentencias]
   return [expresión];
}
```

<<<<<<< HEAD
###### Visto esto, podemos observar que `int main()` es una función.
=======
###### Visto esto, podemos ver que `int main() {}` es una función.
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128

Llamamos **cabecera** o *header* a línea de la función en la que se declaran su tipo, su nombre y sus parámetros.

La definición de funciones debe hacerse antes que la función `main`, ya que para poder llamar a una función esta debe haber sido declarada previamente en el código.

Por convención, nombramos las funciones con **UpperCamelCase**, excepto `main`, que va siempre en minúscula.

## PARÁMETROS DE UNA FUNCIÓN

Las funciones pueden tener dos tipos de parámetros:
- **Parámetros formales:** *Formal parameters*. Se especifican en la cabecera de la función y son aquellos con los que tratará la función. Se debe especificar su tipo de dato al declararlos y separarlos con comas si hubiera más de uno.
- **Parámetros reales:** *Actual parameters*. Son las expresiones que se pasan a la función cuando se la llama desde el código. También se separan por comas pero no se especifica su tipo.

Como ejemplo muy sencillo para diferenciar ambos parámetros, vamos a hacer una función que sume 1 a un entero:

```c++
int Funcion(int parametro_formal) {
   return ++parametro_formal;
}

int main() {
   int parametro_real, masuno;
   
   cin >> parametro_real; // Introducimos 5
   
   masuno = Funcion(parametro_real);
   
   cout << "\n" << masuno; // Devuelve 6
}
```

<<<<<<< HEAD
Como no se ha producido ninguna asignación sobre su valor aunque se haya utilizado para trabajar en las funciones, `parametro_real` sigue valiendo `5` al final de la ejecución del programa.

Como podemos ver, el programa evalúa qué parámetros reales corresponden a qué parámetros formales y opera con ellos. **Si tenemos más de un parámetro formal, se evalúan en orden**. Por supuesto, todos los parámetros deben tener un valor asignado antes de llamar a la función. Por ejemplo:
=======
Fíjate en que `parametro_real` va a seguir valiendo `5`, porque no se ha producido ninguna asignación sobre su valor aunque se haya utilizado para trabajar en las funciones.

Como puedes ver, el programa evalúa qué parámetros reales corresponden a qué parámetros formales y opera con ellos. Si tenemos más de un parámetro formal, se evalúan en orden. Por ejemplo:
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128

```c++
int RestaDos(int valor1, int valor2) {
   return valor1 - valor2;
}

int main() {
   int numero1, numero2, resultado;
<<<<<<< HEAD

   cin >> numero1 >> numero2; // 3 y 4 || 4 y 3

   resultado = RestaDos(numero1, numero2);

   cout << "\n" << resultado; // -1 || 1
}
```

A la hora de llamar a una función, **el número de parámetros formales y reales debe ser el mismo**. Si no lo es, se produce un error en tiempo de compilación. Los parámetros reales deben ser **del mismo tipo o de un tipo compatible** a los formales para poder operar con ellos. De no serlo, se provocan errores en tiempo de ejecución, como desbordamientos aritméticos.
=======
   
   cin >> numero1 >> numero2; // 3 y 4 -- 4 y 3
   
   resultado = RestaDos(numero1, numero2);
   
   cout << "\n" << resultado; // -1 -- 1
}
```

Es muy importante que los nombre de los parámetros formales y los reales no coincidan y que se llame a las funciones con tantos parámetros reales como parámetros formales tengan declarados. Un fallo en cualquiera de estas partes resultará en un error de compilación.

Los parámetros reales deben ser **del mismo tipo o de un tipo compatible** a los formales para poder operar con ellos. De no serlo, se provocan errores lógicos.
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128

También podemos realizar operaciones en los parámetros reales, pero esto es muy poco recomendable, pues parte el trabajo de la función en dos sectores completamente distintos del código.

```c++
double CalcHip(int valor1, int valor2) {
   return sqrt(valor1 + valor2); // Tenemos que confiar en que la
}                                // llamada a la función sea correcta
<<<<<<< HEAD
                                 //    ||
int main() {                     //    ||
   int lado1, lado2, hipotenusa; //    ||
                                 //    ||
   cin >> lado1 >> lado2;        //    ||
                                 //    \/
   hipotenusa = CalcHip(pow(lado1, 2), pow(lado2, 2))
}
```

Los parámetros formales y los reales pueden tener el mismo nombre, ya que sus ámbitos son el interior de sus funciones y el computador los trata como datos diferentes.

## FLUJO DE TRABAJO

Cuando se llama a una función, el programa sigue la siguiente estructura de trabajo:
- Realiza la correspondencia entre parámetros (`formal = real`).
- Ejecuta una a una las sentencias de la función.
  - Al llegar a la sentencia `return` termina la ejecución de la función y devuelve el resultado de su expresión.
- El programa continúa por donde se detuvo para empezar a trabajar con la función.

Supongamos el programa de ejemplo que suma `1` a un valor introducido. Su ejecución sería la siguiente:

```c++
cin >> parametro_real;
parametro_formal = parametro_real;
masuno = ++parametro_formal;
cout << "\n" << masuno;
```

## TRABAJO CON FUNCIONES

Dentro de una función no se pueden declarar otras funciones, pero sí se puede llamar a otras **previamente declaradas**, de otra forma se produce un error de compilación. Ampliemos el ejemplo anterior:

```c++
int Cuadrado(int factor) {
   return pow(factor, 2);
}

double CalcHip(int valor1, int valor2) {
   return sqrt(Cuadrado(valor1) + Cuadrado(valor2));
}
=======
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128

int main() {
   int lado1, lado2, hipotenusa;
   
   cin >> lado1 >> lado2;
   
<<<<<<< HEAD
   hipotenusa = CalcHip(lado1, lado2)
}
```

Las funciones **deben devolver siempre un valor**. Una función que tenga casos en los que pueda no devolverlos no producirá un error de compilación (pues el compilador lee la sentencia `return`) pero sí un error en tiempo de ejecución.

```c++
int APositivo(valor) {
   if (valor < 0)     // La sentencia "return" existe, pero no para
      return -valor;  // los casos "else".
}
```

## DATOS LOCALES DE UNA FUNCIÓN

Como ya hemos dicho, el ámbito de los parámetros de una función es la función en la que están definidos. De la misma manera, podemos añadir constantes y variables en el interior de las funciones (de la misma manera que lo hacemos en `main()`) que sólo son accesibles desde dentro de la función. Por ejemplo, calculemos el factorial de un número con una función:

```c++
#include <iostream>
using namespace std;

long long Factorial (int n){
   int i;
   long long fact = 1;

   for (i = 2; i <= n; i++)
      fact = fact * i;

   return fact;
}

int main(){
   int valor;
   long long resultado;

   cout << "Introduzca un número entero: ";
   cin >> valor;

   resultado = Factorial(valor);

   cout << "\n" << valor << "! = " << resultado;
}
```

Este ejemplo es correcto porque en ningún momento se intenta acceder a datos de otras funciones. En cambio, estas líneas serían incorrectas:

```c++
for (i = 2; i <= valor; i++) // valor no está definida en Factorial
cout << i; // i no está definida en main
n = 5; // Se está modificando el parámetro formal, no el real
```

Sabiendo esto, podemos poner el mismo nombre a los datos locales de ambas funciones, ya que existen en ámbitos diferentes. El programa anterior podría quedar así sin ningún problema de compilación ni ejecución:

```c++
#include <iostream>
using namespace std;

long long Factorial (int n){
   int i;
   long long fact = 1;

   for (i = 2; i <= n; i++)
      fact = fact * i;

   return fact;
}

int main(){
   int n;
   long long fact;

   cout << "Introduzca un número entero: ";
   cin >> n;

   resultado = Factorial(n);

   cout << "\n" << n << "! = " << fact;
}
```

## LA PILA

Cada vez que un programa llama a una función, ésta se crea dentro de una zona de memoria principal llamada **pila** o *stack* (ampliado en [FS](https://github.com/DEIIT/Ingenieria-Informatica/blob/master/1%C2%BA%201er%20cuatrimestre/Fundamentos%20del%20software/Temario/Tema%201%20-%20Sistema%20de%20c%C3%B3mputo.md#22---registros-del-procesador)). El trabajo de la pila es el siguiente:
- Crea un compartimento o **marco** asociado a la función que se llama en el que se almacenan:
  - Los parámetros formales.
  - Los datos locales.
  - La dirección de retorno (el punto en el que seguir cuando termine la función).
- Cuando termina la función, se elimina el marco asociado a ella.

La ventaja de la pila es que, al crear un marco, lo crea *encima* de los anteriores y no permite acceder a los anteriormente creados hasta que los que se están procesando hayan finalizado. Tomemos como ejemplo el programa de la seccion **Trabajo con funciones**:
=======
   hipotenusa = CalcHip(pow(lado1, 2), pow(lado2, 2))
}
```

Dentro de una función no se pueden declarar otras funciones, pero sí se puede llamar a otras **previamente declaradas**, de otra forma se produce un error de compilación. Ampliemos el ejemplo anterior:
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128

```c++
int Cuadrado(int factor) {
   return pow(factor, 2);
}

double CalcHip(int valor1, int valor2) {
   return sqrt(Cuadrado(valor1) + Cuadrado(valor2));
}

int main() {
<<<<<<< HEAD
   int lado1, lado2, hip;
   
   cin >> lado1 >> lado2;
   
   hip = CalcHip(lado1, lado2)
}
```

El comportamiento de la pila sería el siguiente

| MARCOS | PASO 1 | PASO 2 | PASO 3 | PASO 4 | PASO 5 | PASO 6 |
| :---: | --- | --- | --- | --- | --- | --- |
| **Cuadrado** | | | `factor = 3`<br/>`return = 9` | `factor = 4`<br/>`return = 16` | |
| **CalcHip** | | `valor1 = 3`<br/>`valor2 = 4`<br/>`return = ?` | `valor1 = 3`<br/>`valor2 = 4`<br/>`return = ?` | `valor1 = 3`<br/>`valor2 = 4`<br/>`return = ?` | `valor1 = 3`<br/>`valor2 = 4`<br/>`return = 25` | |
| **main** | `lado1 = 3`<br/>`lado2 = 4`<br/>`hip = ?` | `lado1 = 3`<br/>`lado2 = 4`<br/>`hip = ?` | `lado1 = 3`<br/>`lado2 = 4`<br/>`hip = ?` | `lado1 = 3`<br/>`lado2 = 4`<br/>`hip = ?` | `lado1 = 3`<br/>`lado2 = 4`<br/>`hip = ?` | `lado1 = 3`<br/>`lado2 = 4`<br/>`hip = 25` |



<p align="center">
   <b>Este repositorio es fruto del esfuerzo de los estudiantes de la Universidad de Granada</b></br>
   <a href="http://deiit.ugr.es/"><img width="200" height="80" src="https://imgur.com/1lXPd4l.png"></a>
</p>
=======
   int lado1, lado2, hipotenusa;
   
   cin >> lado1 >> lado2;
   
   hipotenusa = CalcHip(lado1, lado2)
}
```

Las funciones **deben devolver siempre un valor**. Una función que tenga casos en los que

<center><h3>UNIVERSIDAD DE GRANDA</h3></center>
>>>>>>> 0c746a731db14defe6ef1cfbd43763a1eb481128
