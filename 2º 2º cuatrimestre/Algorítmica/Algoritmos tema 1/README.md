# Algoritmos tema 1

**Demo de varios algoritmos presentados a lo largo del tema 1.**

## Argumentos

Este programa permite los siguientes argumentos:

| ARGUMENTO     | DESCRIPCIÓN                                            |
| :------------ | :----------------------------------------------------- |
| `bubble`      | Ordenar un vector por bubble sort en el caso peor.     |
| `factorial`   | Calcular el *n*-ésimo número factorial.                |
| `fibonacci`   | Calcular el *n*-ésimo valor de la secuencia Fibonacci. |
| `repetitivas` | Demostración de bucles y bucles anidados.              |

Los argumentos pueden introducirse en cualquier orden para ejecutar cada uno de los algoritmos a los que se refieren.
Si no se introduce ningún argumento, se ejecutarán todos los algoritmos.

## Compilación

Este programa se compila con `make`:

```bash
make
```

El fichero de salida es `/bin/demo-algoritmos`.
La creación de directorios auxiliares viene gestionada en el fichero `Makefile`.
