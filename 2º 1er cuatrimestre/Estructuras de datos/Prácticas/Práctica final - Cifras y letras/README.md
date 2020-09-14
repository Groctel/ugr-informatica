# CIFRAS Y LETRAS

**Programa que juega (¡y gana!) a *Cifras y Letras*.**

## Implementación

Las palabras con las que se va a jugar se almacenen en un **Diccionario** basado en un `std::set<std::string>`, una vez almacenadas, se calcula la frecuencia de todos los caracteres almacenándolos en un TDA **Letra**.
Para buscar las palabras, se usa una **Bolsa** de caracteres, basada en un `std::vector<char>`, que busca todas las posibles permutaciones de la misma en el diccionario.
Una vez encontradas todas las palabras generables por la bolsa de caracteres, se busca de ésta la más larga y la que tiene la mayor puntuación.
Para el cálculo de la puntuación, de forma que el diseño se pueda generalizar a cualquier diccionario, se da valor a cada letra como la diferencia entre el total de éstas y su frecuencia absoluta.

## Compilación

- `make`: Compila el programa y la documentación.
- `make main`: Compila únicamente el programa.
- `make docs`: Compila únicamente la documentación.

## Ejecución

Ejecuta el programa con un único argumento: el fichero de palabras.

```
cifras_y_letras diccionario.txt
```

El proyecto incorpora un fichero diccionario en `datos/es.txt`.

