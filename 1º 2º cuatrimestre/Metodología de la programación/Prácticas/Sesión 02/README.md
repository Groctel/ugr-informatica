# Práctica 2

**Trabajo en proyectos complejos con `make`**

Vista la compilación manual de un proyecto de C++, en esta práctica se explora la automatización de dicho proceso mediante la orden `make` y los ficheros `Makefile`.

## Intorucción a `make` y los ficheros `Makefile`

Desarrollado por GNU, `make` es un programa encargado de automatizar la compilación de un proyecto de software mediante la interpretación y ejecución de las instrucciones, llamadas ***recetas***, definidas en éste.
Para comprender cómo funciona `make`, primero debemos examinar la sintaxis de los ficheros `Makefile`:

```make
# Comentario

objetivo0: dependencia0 dependencia1 dependencia2
	receta0
	receta1
	receta2

objetivo1: dependencia0 dependencia1 dependencia2
	receta0
	receta1
	receta2

objetivo2: dependencia0 dependencia1 dependencia2
	receta0
	receta1
	receta2
```

Cada fichero `Makefile` está formado por una serie de reglas que contienen los siguientes elementos:

- **Objetivo:** Nombre por el que se identifica la regla.
- **Dependencias:** Lista de reglas que deben cumplirse antes de ejecutar las instrucciones.
- **Recetas:** Órdenes precedidas obligatoriamente de una tabulación que se ejecutan secuencialmente en la *shell*.

Por ejemplo, veamos el siguiente fichero:

```make
all: inicio continuacion
	@echo "Fin de la ejecución"

continuacion: paso_preliminar
	@echo "Y esto se imprimirá después"

inicio:
	@echo "Comenzando ejecución..."

paso_preliminar:
	@echo "Esto se imprimirá antes"
```

Si guardamos este texto en un fichero `Makefile`, podemos ejecutar `make` en el directorio en el que se encuentre y el programa buscará y ejecutará la primera regla que encuentre (`all` en este caso).
Debido a que las reglas de la lista de dependencias se evalúan de izquierda a derecha, siempre quedará la siguiente salida de texto:

```
Comenzando ejecución...
Esto se imprimirá antes
Y esto se imprimirá después
Fin de la ejecución
```

Aunque este caso no contiene instrucciones de compilación reales, ilustra bien la estructura de los ficheros.
Vamos a usar `make` para compilar el proyecto de la sesión anterior:

```make
all: directorios bin/saludo

bin/saludo: src/saludo.cpp
	g++ src/saludo.cpp -o bin/saludo

directorios:
	@mkdir -p bin
```

En general no es necesario tener una regla que cree los directorios, ya que éstos se incluyen vacíos en el propio proyecto, pero aquí la usamos para crear aquellos directorios vacíos que `git` no tiene en cuenta y que no aparecen al descargar el repositorio.

Al evaluar las dependencias, `make` distingue entre dos tipos de reglas:

- **Reglas explícitas:** Están asociadas a un objetivo y hacen a `make` saltar a una nueva receta antes de seguir con la actual.
- **Reglas implícitas:** No están asociadas a ningún objetivo, por lo que `make` decide qué hacer con ellas en función de su implementación.

En este caso, la regla `bin/saludo` está asociada a un objetivo homónimo, por lo que es una regla explícita.
Sin embargo, `src/saludo.cpp` no tiene ningún objetivo con dicho nombre, por lo que `make` decide las acciones que realizar con ella.
En el caso de reglas implícitas con rutas de ficheros, `make` comprueba si éstos se han actualizado después de la última llamada al programa.
De esta forma, si uno de los módulos del programa no se ha modificado, no es necesaario recompilarlo en detrimento del tiempo que esto lleva consigo.
