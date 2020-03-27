# Práctica 3 - T.D.A. Lineales

## Enunciado

Crear el T.D.A `Pila_max` (Pila con máximo).
Esta `Pila` contiene un conjunto de enteros pero además se almacena el valor máximo que existe en la `Pila`.

El alumno debe llevar a cabo las siguientes tareas:

- Dar una especificación del T.D.A. `Pila_max`.
- Definir el conjunto de operaciones con sus especificaciones.
- Usar dos estructuras de datos para implementar el T.D.A. `Pila_max`.
  - Como un `Vector Dinámico`.
  - Como un `Cola`.
- Probar los módulos con programas test.

**IMPORTANTE:** Para llevar a cabo la implementación de los diferentes módulos no se podrá usar la STL.

## Compilación

Puedes compilar esta práctica con cuatro opciones:

- `make all`: Ejecutar todos los métodos secuencialmente
- `make cola`: Compilar el proyecto con una cola
- `make vd`: Compilar el proyecto con un vector dinámico
- `make docs`: Generar la documentación con Doxygen

La orden `make` simplemente muestra un menú con esta información.

## Errores conocidos

Al compilar con una cola, algún método de acceso a la misma modifica los elementos de forma indebida.
La sobreescritura de los mismos es determinista, es decir, siempre se sobreescriben los mismos dados una serie de modificaciones al código de la estructura, pero no he sido capaz de identificarlos.
