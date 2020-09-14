# COMPILACIÓN Y ENLAZADO DE PROGRAMAS

## 1 - LENGUAJES DE PROGRAMACIÓN

Un lenguaje de programación es un conjunto de símbolos y reglas que, al combinarlos, se usan para expresar algoritmos. Tienen las siguientes características:
- **Sus instrucciones se expresan mediante texto:** Dicho texto contiene caracteres alfanuméricos, así como caracteres especiales (`+`, `-`, `*`, `/`. `%`, etc.).
- **Permiten asignar nombres simbólicos a determinados componentes**, como las variables, para hacer el código más legible por los humanos.
- **Permiten introducir comentarios:** Éstos facilitan la lectura del código y ayudan a su comprensión.
- **Pasan por un proceso de traducción:** Al escribir un programa en un lenguaje de alto nivel (o incluso ensamblador), éste traduce sus instrucciones a lenguaje máquina para que el computador pueda procesarlas.
- **Son independientes de la arquitectura física del computador:** Esto aumenta la portabilidad de los programas entre computadores (aunque pueda haber discrepancias entre sistemas operativos).

Se definen dos niveles de lenguaje de programación según su estructura:
- **Alto nivel:** Más fáciles de comprender, pues permiten asignar nombres simbólicos a las variables y otros componentes, y con un nivel alto de abstracción. Son más cercanos al problema  (sumar todos los elementos de un vector) que a la solución.
- **Bajo nivel:** Más difíciles de comprender y con un nivel bajo de abstracción. Son más cercanos a la solución (introducir cada uno de los elementos de las posiciones de memoria en las que está reservado el vector en los registros adecuados y sumarlos ordenadamente) que al problema.

## 2 - CONSTRUCCIÓN DE TRADUCTORES

### 2.1 - GRAMÁTICA

Una gramática es **una serie de normas que determinan la estructura sintáctica de un lenguaje** (tanto natural como de programación). La complejidad de la verificación sintáctica de un lenguaje viene determinada por su tipo de gramática (no es lo mismo C que ASM al igual que no es lo mismo hablar latín que español).

Las gramáticas ofrecen beneficios tanto para los diseñadores de lenguajes como de traductores como, por ejemplo:
- Proporcionan una especificación sintáctica precisa de un lenguaje de programación.
- Ofrecen la posibilidad de construir un analizador sintáctico eficiente.
- Permiten revelar ambigüedades sintácticas y puntos problemáticos en el diseño del lenguaje.
- Permiten que el lenguaje pueda evolucionar o se desarrolle de forma iterativa agregando nuevas construcciones.

Una gramática debe tener los siguientes cuatro elementos:
- **Alfabeto:** Conjunto finito de símbolos.
  - Ejemplo: Binario = `{0, 1}`.
- **Cadena:** Secuencia finita de símbolos usando su alfabeto.
  - Ejemplo: Binario = `{0, 1, 10, 11, 100, 101, 110, 111, 1000, ...}`.
- **Símbolos terminales:** Elementos del alfabetos usados para formar cadenas.
-   - Ejemplo: Binario = `{0, 1}`.
- **Símbolos no terminales:** Variables sintácticas que representan conjuntos de cadenas utilizadas en las reglas gramaticales sin ser elementos del alfabeto.
  - Ejemplo: Binario = `N -> N0 | N1 | 0 | 1`. Este ejemplo se ampliará más adelante.

La gramática de un lenguaje tiene cuatro elementos definidos por la siguiente fórmula:

    G = (Vn, Vt, P, S)

- **Vn:** Conjunto de símbolos no terminales.
- **Vt:** Conjunto de símbolos terminales.
- **P:** Conjunto de producciones o reglas gramaticales.
- **S:** Símbolo inicial (no terminal).

Se dice que una gramática es **libre de contexto** cuando su conjunto deproducciones P tiene la siguiente forma, que se desarrollará más adelante:

    P = { A → a : A ∈ Vn, a ⊂ (Vn∪Vt)*}

Las gramáticas libres de contexto sólo admiten un símbolo no terminal en la parte izquierda de las producciones. Las llamamos así porque donde aparezca `A` se puede poner `a` independientemente del contexto en el que se encuentre.

Toda gramática debe ser interpretada por un traductor, que es un programa que recibe como entrada un texto en un lenguaje de programación y devuelve un texto en lenguaje máquina equivalente. Existen dos tipos de traductores: los compiladores y los intérpretes.

### 2.2 - TRADUCTORES

Un traductor es **un programa que recibe como entrada un texto en un lenguaje de programación y produce como salida un texto equivalente en languaje máquina**. Distinguimos entre dos tipos de traductores:

#### 2.2.1 - Compilador

Un compilador **traduce la especificación de entrada a lenguaje máquina incompleto y con instrucciones máquina incompletas**.

Para completar la traducción se usa un **enlazador** o *linker*, que unifica varios programas compilados para completar la información de las rutinas no programadas directamente en el programa fuente. Esto se amplía en la Práctica 7.

![img](https://imgur.com/CwfaTXR.png)

#### 2.2.2 - Intérprete

Un intérprete **lee un programa fuente escrito para una máquina virtual, realiza la interpretación internamente y ejecuta las instrucciones obtenidas para la máquina real**. A lo largo de este proceso no se genera ningún programa objeto equivalente al descrito en el programa fuente.

![img](https://imgur.com/mLc5G8q)

## 2.3 - ESQUEMA DE TRADUCCIÓN

![img](https://i.imgur.com/Nfjksoq.png)

## 2.4 - CREACIÓN DE UN ÁRBOL SINTÁCTICO A PARTIR DE UNA GRAMÁTICA

A la hora de definir los elementos de una gramática usamos expresiones regulares como las siguientes:
- **Un carácter se repite cero o más veces:** `*`.
- **Un carácter se repite una o más veces:** `+`.
- **Un carácter se repite cero o una vez:** `?`.
- **Una lista de caracteres:** `a | b | c | d | e`.
  - Esta lista puede resumirse en el intervalo `[a - e].

Supongamos la gramática siguiente:

```
P = {E -> E O E | (E) | id
     O -> + | - | * | /}
Vn = {E, O}
Vt = {(,), id, +, -, *, /}
S = E
```

Si a dicha gramática le aplicamos el texto de entrada `id+id*(id-(id/id))` obtenemos el siguiente árbol sintáctico que valida su construcción, verificando que la sintaxis es correcta:

![img](https://i.imgur.com/rnG6ds1.png)

## 3 - FASES DE TRADUCCIÓN

![img](https://i.imgur.com/VwI6Wg3.png)

### 3.1 - FASE DE ANÁLISIS

#### 3.1.1 - Análisis léxico

La función del análisis léxico es **leer los caracteres de entrada del programa fuente, agruparlos en lexemas y producir como salida una secuencia de tokens para cada lexema**. A lo largo de este proceso se eliminan todos los caracteres superfluos y comentarios del código fuente.

Dada la definición anterior, debemos aclarar tres conceptos:
- **Lexema:** Palabra. Secuencia de caracteres del alfabeto con significado propio.
- **Token:** Concepto asociado a un conjunto de lexemas que, según la gramática del lenguaje guente, tienen la misma misión sintáctica.
- **Patrón:** Descripcción de la forma que pueden tomar los lexemas de un token.

| TOKEN | DESCRIPCIÓN INFORMAL | LEXEMAS DE EJEMPLO |
| :---: | --- | --- |
| **IF** | Caracteres `i` y `f`. | `if` |
| **ELSE** | Caracteres `e`, `l`, `s` y `e`. | `else` |
| **OP_COMP** | Operadores `<`, `>`, `<=`, `>=`, `!=` y `==`. | `<=`, `==`, `!=` |
| **INDENT** | Letra seguida por letras y números. | `tau`, `valor1`, `util_vector` |
| **NUMBER** | Cualquier constante numérica. | `0`, `1`, `2`, `3`, `5`, `8`, `11`, ... |

En muchos lenguajes de programación se consideran la mayoría de estos tokens:
- Uno para cada **palabra reservada** (`if`, `do`, `while`, ...).
- Unos para los **operadores**, de forma individual o agrupándolos.
- Uno que represente a todos los **identificadores** tanto de variables como de subprogramas.
- Uno o más que representen las **constantes** tanto numéricas como literales.
- Uno para cada **signo de puntuación** (`(`, `)`, `{`, `}`, ...).

Decimos que se produce un **error léxico** cuando un carácter de entrada no esté asociado a ninguno de los patrones de la lista de tokens (`whlie` en lugar de `while`).

Dada la gramática anterior, los patrones que van a definir a los tokens son los siguientes:

```
     S -> A | C
     A -> id = E
     C -> if E then S
     E -> E O E | (E) | id
     O -> + | - | * | /
    id -> letra | id digito | id letra
 letra -> [a - z]
codigo -> [0 - 9]
```

Mostrados en la tabla de símbolos se verían de la siguiente manera:

| TOKEN | PATRÓN |
| :---: | --- |
| **ID** | `letra((letra | digito)*` |
| **ASIGN** | `=` |
| **IF** | `if` |
| **THEN** | `then` |
| **PAR_IZQ** | `(` |
| **PAR_DER** | `)` |
| **OP_BIN** | `+ | - | * | /` |

#### 3.1.2 - Análisis sintáctico

La función del análisis sintáctico es **analizar las secuencias de tokens y comprobar que son correctas sintácticamente**. Esto se hace devolviendo dos respuestas a la consulta de análisis:
- Si la secuencia es correcta o no sintácyicamente.
- El orden en el que hay que aplicar las producciones de gramática para obtener la secuencia de entrada (el árbol sintáctico).

Si no se encuentra un árbol sintáctico para una secuencia de entrada es que es incorrecta sintácticamente y han de solucionarse sus errores.

Existen gramáticas que pueden producir más de un árbol sintáctico, como es el caso de la indicada en el apartado 2.4, con la que podríamos crear los dos siguientes árboles usando la misma entrada:

![img](https://i.imgur.com/Asr5W2Y.png)

Para subsanar esto utilizamos el análisis semántico.

#### 3.1.2 - Análisis semántico

La semántica de un lenguaje es **el significado dado a las distintas construcciones semánticas**. En un lenguaje de programación, dicho significado está ligado a la estructura sintáctica de las sentencias.

Por ejemplo, una sentencia de asignación en C++ tiene la siguiente semántica:

    ID OP_ASIG expr PYC

En ella, `ID`, `OP_ASIG` y `PYC` son tokens que representan, respectivamente, el nombre que identifica a una variable, el operador de asignación `=` y el delimitador de sentencia `;`. Para que dicha sentencia sea correcta deben cumplirse las siguientes reglas semánticas:
- `ID` debe estar previamente declarado y debe tener asignado un tipo de dato.
- El tipo de dato de la `expr` debe ser acorde con el tipo de dato de `ID`.

Los errores de análisis semántico se producen cuando se detectan construcciones sin un significado correcto, como variables no declaradas o tipos de dato incompatibles. La flexibilidad en la asignación de tipos de dato (*casting*) varía según el lenguaje. Mientras que C++ necesita de funciones específicas para transformar datos y JavaScript permite cambiar una variable de tipo de dato en cualquier momento, otros lenguajes como Pascal impiden directamente asignaciones de datos de diferente tipo.

## 3.2 - GENERACIÓN DE CÓDIGO

En esta fase **se genera un archivo con un código en lenguaje objeto (generalmente máquina) con el mismo significado que el texto fuente**. En algunos casos se intercala una fase de generación de código intermedio para proporcionar más portabilidad al compilador o hacer más fácil la optimización del código.

## 3.3 - OPTIMIZACIÓN DE CÓDIGO

En esta fase **se examinan fragmentos de código para mejorarlo**, ya sea en secciones locaales a un bloque de instrucciones concreto o a nivel global. Las optimizaciones se pueden aplicar tanto al código intermedio como al código objeto final, aunque generalmente se aplican a códis intermedios.

Por ejemplo, tomemos este bucle en C++:

```c++
for (int i = 0; i < 10; i++) {
   a = 37 - i * 35;
   b = 7.5;
   c = b - sin(-a / 350000);
}
```

Al ver que la tercera línea se repite en todas las iteraciones del bucle, el optimizador optará por variar el código para hacer que consuma menos recuros de computación y dejar la versión final de la siguiente manera:

```c++
b = 7.5;

for (int i = 0; i < 10; i++) {
   a = 37 - i * 35;
   c = b - sin(-a / 350000);
}
```

##  3.4 EJEMPLO PASO A PASO DE UN PROCESO DE TRADUCCIÓN

Tomemos la siguiente código fuente, que calcula la distancia recorrida en una hora:

    posicion_final = posicion_inicial + velocidad * 60

El primer paso de traducción es el **análisis léxico**, que nos devuelve la siguiente estructura léxica y tabla de símbolos:

    identificador asignación identificador op_bin identificador op_bin constante

| | REFERENCIA | NOMBRE |
| ---: | :---: | --- |
| **[** | 1 | `posicion_final` |
| **IDENTIFICADORES [** | 2 | `posicion_inicial` |
| **[** | 3 | `velocidad` |
| | **REFERENCIA** | **VALOR** |
| **CONSTANTES [** | 1 | `60` |

El segundo paso es el **análisis sintáctico**, que nos devuelve el siguiente árbol:

```
asignación
   - identificador
   - op_bin (+)
      - identificador
      - op_bin (*)
         - identificador
         - constante
```

A partir de este árbol, el **análisis semántico** nos devuelve la correspondencia entre el árbol sintáctico y la tabla de símbolos:

```
=
   - identificador1
   - +
      - identificador2
      - *
         - identificador3
         - numeroentero
            - 60
```

Conocidos los elementos con los que se trabaja y habiendo comprobado que no existen errores, se hace una **generación de código intermedio**:

```
temp1 = numeroentero(60);
temp2 = identificador3 * temp1;
temp3 = identificador2 + temp2;
identificador1 = temp3;
```

Para hacerlo más eficiente, se hace una **optimización del código**:

```
temp1 = identificador3 * 60.0;
identificador1 = identificador2 + temp1
```

Por último, se hace una **generación de código máquina** que puedda ser ejecutable:

```
MOVF identificador3, R2
MULF #60.0, R2
MOVF identificador2, R1
ADDF R2, R1
MOVF R1, identificador1
```

## 4 - INTÉRPRETES

## 5 - MODELOS DE MEMORIA DE UN PROCESO

## 6 - CICLO DE VIDA DE UN PROGRAMA

## 7 - BIBLIOTECAS

## 8 - AUTOMATIZACIÓN DEL PROCESO DE COMPILACIÓN Y ENLAZADO