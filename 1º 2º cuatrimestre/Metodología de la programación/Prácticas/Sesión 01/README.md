# Práctica 1

**Compilación de C++ con `g++`**

En esta práctica se dan los primeros pasos de compilación manual de un proyecto de C++.
Para ello, usaremos el programa `g++`, que viene incluido en el paquete de compiladores `gcc` (GNU compiler collection).

## Primer ejercicio

Compilar el fichero `src/saludo.cpp` para crear un ejecutable y un módulo objeto.
Para crear el ejecutable basta con que llamemos a `g++` sin argumentos:

```sh
g++ src/saludo.cpp
```

Para crear el módulo objeto usamos el argumento `-c`:

```
g++ -c src/saludo.cpp
```

## Segundo ejercicio

Los dos comandos del ejercicio anterior nos crean en el directorio raíz de la práctica los ficheros `a.out` para el ejecutable y `saludo.o` para el módulo objeto.
Podemos definir el fichero de salida de `g++` con el argumento `-o`:

```sh
mkdir bin obj
g++ src/saludo.cpp -o bin/saludo
g++ -c src/saludo.cpp -o obj/saludo
```

## Tercer ejercicio

Crear el ejecutable a partir del módulo objeto.
Para ello, ejecutaremos dos órdenes de `g++`:

```sh
g++ -c src/saludo.cpp -o obj/saludo.o
g++ obj/saludo.o -o bin/saludo_en_dos_pasos
```

## Cuarto ejercicio

Crear el ejecutable mostranto las advertencias (*warnings*) del compilador y con símbolos de depuración.
Los *warnings* podemos mostrarlos con la opción `-W` seguida, sin espacios, del tipo de *warning* que queremos.
En general, usaremos los siguientes *warnings* para captar cualquier tipo de inconsistencia en el código:

| ***Warning***   | Descripción                                                                  |
| :-------------: | ---------------------------------------------------------------------------- |
| `-Wall`         | Todos los *warnings* sobre construcciones cuestionables y fáciles de evitar. |
| `-Wextra`       | Más *warnings* que `-Wall` no habilita.                                      |
| `-Wfloat-equal` | *Warning* sobre comparar dos `float` con `==`.                               |
| `-Wpedantic`    | *Warnings* sobre extensiones que no sean estrictamente ISO C++.              |

Para más información sobre los *warnings*, consultar el `man` de `g++`.
Para generar el fichero con símbolos de depuración usaremos la opción `-g`.
Podemos ver con detalle qué órdenes ejecuta `g++` a lo largo del proceso de compilación con la opción `-v`:

```sh
g++ -g -Wall -Wextra -Wpedantic src/saludo.cpp -o bin/saludo
g++ -v src/saludo.cpp -o bin/saludo
```

## Quinto ejercicio

Compilar `demo.cpp` teniendo en cuenta el fichero de cabecera.
Para ello usaremos la opción `-I` seguida, sin espacios, del directorio en el que se encuentran los ficheros de cabecera (generalmente `include`).
Para que el preprocesador de `g++` sepa qué ficheros debe buscar, usamos la directiva `#include` de la siguiente forma:

```cpp
#include <iostream>
#include "utils.hpp"
```

Cuando indicamos la inclusión en una etiqueta (`<>`), el preprocesador busca los ficheros de cabecera en los directorios del sistema (por ejemplo, en `/usr/include`), mientras que cuando indicamos la inclusión en una cadena (`""`), los busca en el directorio indicado por `-I`.

Para este ejercicio crearemos un ejecutable de `src/demo.cpp`.
Para ello, deberemos crear un módulo objeto de `utils.cpp` y enlazarlo con el fichero donde se encuentre el `main`.
Para enlazarlo basta con indicar el módulo objeto como argumento en la orden de compilación del ejecutable:

```sh
g++ -c src/utils.cpp -o obj/utils.o -Iinclude
g++ src/demo.cpp -o bin/demo obj/utils.o -Iinclude
```
