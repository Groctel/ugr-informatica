# Civitas - Ruby

**Clon de Monopoly escrito en Ruby**

Ésta es una de las versiones del proyecto de las prácticas de PDOO, basado en programar un clon de Monopoly tanto en Ruby como en Java. El proyecto está dividido en cinco prácticas en las que se van implementando distintos aspectos del juego, aunque la versión de Ruby sólo tiene cuatro debido a que no se implementa una interfaz gráfica.

## Ejecución y documentación del proyecto

Ejecuta el proyecto con `ruby` llamando al fichero `lib/main`:

```sh
ruby lib/main.rb
```

La documentación está diseñada para ser generada con [RDoc](https://github.com/ruby/rdoc). Puedes generarla desde el directorio raíz o el directorio `lib/`. La opción `-a` permite la visibilidad de los métodos y atributos privados en la documentación generada.

```
rdoc -a
```

## Modificaciones sobre la estructura original del proyecto

A pesar de que se ofrece un guión explícito de pasos a seguir para la implementación del proyecto, se permiten modificaciones debidamente documentadas sobre la estructura del mismo.
Las modificaciones documentadas en una práctica afectan a las siguientes, que puede hacer adiciones a las modificaciones anteriores sin necesidad de indicarlas.

### Práctica 1

- Los ficheros se han ordenado en directorios.
- Se han implementado nuevos métodos sobre la clase `String` para estilizar la muestra de datos por la salida estándar.
- Se ha creado un enum de `Figuras` prediseñadas para mostrar ágilmente símbolos por la salida estándar.
- Se ha explicitado el número de caras como argumento en el método `Dado::tirar`, por defecto 6, para utilizar dicho método en todas las operaciones de carácter aleatorio del juego.
- Se ha predeterminado la salida de `Dado::salgo_de_la_carcel` a `true` si `:debug` vale `true`.
- Se ha definido el método privado `Tablero::aniade_carcel` para evitar repetir código en el método público `Tablero::aniade_casilla`.
