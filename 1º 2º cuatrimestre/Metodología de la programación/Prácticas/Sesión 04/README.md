# Práctica 4

**Punteros (1)**

Se trata de realizar tres ejercicios sobre el uso de punteros, el último de ellos compuesto por varias funciones sobre cadenas tipo C.
Para ninguno de estos ejercicios puede usarse el operador `[]`, por lo que se deben resolver usando aritmética de punteros.

## Primer ejercicio: `mezcla-sencilla-vectores`

Dados dos vectores de números reales de tamaño `n`, ordenarlos en un vector de tamaño `2n` de menor a mayor.

## Segundo ejercicio: `reorganiza-vector`

Dado un vector de números reales, ordenarlo de forma que los elementos menores que el primero queden a la izquierda de éste y los mayores, a la derecha (casi igual que el primer paso del algoritmo [QuickSort](https://en.wikipedia.org/wiki/Quicksort)).
Para ello, colocamos un punterio al inicio y al final del vector y realizamos la siguiente acciones mientras que el puntero principal referencie una posición inferior que el puntero reverso:

- Aumentar el puntero principal mientras que apunte a un valor menor o igual que el primero.
- Aumentar el puntero reverso mientras que apunte a un elemento mayor que el primero.
- Si los punteros no se han cruzado, se intercambian los valores.

## Tercer ejercicio: `demo-cadena-clasica`

Las cadenas tipo C, cadenas clásicas o *null terminated string*, son cadenas que no almacenan su tamaño, sino que indican su final con un carácter nulo `'\0'` (`0x00`).
En este ejercicio se implementan varias funciones de trabajo con dichas cadenas cuyos prototipos pueden consultarse en `include/mi-cadena-clasica.hpp`.

Para poder utilizar la función `std::max` sin incluir bibliotecas innecesarias se ha definido la siguiente macro para el preprocesador:

```cpp
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

En lugar de llamar a `std::max(a, b)`, llamamos a `MAX(a, b)` sin necesidad de incluir `<algorithm>`.
