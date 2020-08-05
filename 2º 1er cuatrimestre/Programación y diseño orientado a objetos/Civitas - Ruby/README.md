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

## Historial de prácticas

Mediante este enlace puedes visitar el estado del proyecto en la práctica anterior:

- [Práctica 1](https://github.com/Groctel/ugr-informatica/tree/99367a5f56243258e18a4dc3b97a0fea86718698/2%C2%BA%201er%20cuatrimestre/Programaci%C3%B3n%20y%20dise%C3%B1o%20orientado%20a%20objetos/Civitas%20-%20Ruby)

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

### Práctica 2

- Modificados los siguientes enumerados:
	- `TipoSorpresa::POR_CASA_HOTEL` **->** `TipoSorpresa::POR_EDIFICIO`
	- `TipoSorpresa::SALIR_CARCEL` **->** `TipoSorpresa::SALVOCONDUCTO`
- Modificados los siguientes nombres de métodos:
	- `CivitasJuego::contabilizar_pasos_por_salida` **->** `CivitasJuego::total_vueltas`
	- `CivitasJuego::inicializar_mazo_sorpresas` **->** `CivitasJuego::init_mazo`
	- `CivitasJuego::inicializar_tablero` **->** `CivitasJuego::init_tablero`
	- `Jugador::cantidad_casas_hoteles` **->** `Jugador::cantidad_edificios`
	- `Jugador::existe_la_propiedada` **->** `Jugador::propiedad_correcta`
	- `Jugador::paga` **->** `Jugador::pagar`
	- `Jugador::paga_alquiler` **->** `Jugador::pagar_alquiler`
	- `Jugador::paga_impuesto` **->** `Jugador::pagar_impuesto`
	- `Jugador::pasa_por_salida` **->** `Jugador::pasar_por_salida`
	- `Jugador::puedo_edificar_casa` **->** `Jugador::puede_edificar_casa`
	- `Jugador::puedo_edificar_hotel` **->** `Jugador::puede_edificar_hotel`
	- `Jugador::puedo_gastar` **->** `Jugador::puede_gastar`
	- `Jugador::recibe` **->** `Jugador::recibir`
	- `Jugador::tiene_algo_que_gestionar` **->** `Jugador::gestiones_pendientes`
	- `Sorpresa::aplicar_a_jugador` **->** `Sorpresa::aplicar`
	- `Sorpresa::aplicar_a_jugador_ir_a_casilla` **->** `Sorpresa::aplicar_casilla`
	- `Sorpresa::aplicar_a_jugador_ir_carcel` **->** `Sorpresa::aplicar_carcel`
	- `Sorpresa::aplicar_a_jugador_pagar_cobrar` **->** `Sorpresa::aplicar_pagar_cobrar`
	- `Sorpresa::aplicar_a_jugador_por_casa_hotel` **->** `Sorpresa::aplicar_por_edificio`
	- `Sorpresa::aplicar_a_jugador_por_jugador` **->** `Sorpresa::aplicar_por_jugador`
	- `Sorpresa::aplicar_a_jugador_salir_carcel` **->** `Sorpresa::aplicar_salir_carcel`
	- `Sorpresa::salir_del_mazo` **->** `Sorpresa::sacar_del_mazo`
	- `Sorpresa::usada` **->** `Sorpresa::devolver_al_mazo`
	- `Tablero::aniade_casilla` **->** Sobrecarga del operador `<<`
	- `Tablero::get_casilla` **->** Sobrecarga del operador `[]`
	- `TituloPropiedad::actualiza_propietario_por_conversion` **->** `TituloPropiedad::actualiza_propietario`
	- `TituloPropiedad::cantidad_casas_hoteles` **->** `TituloPropiedad::total_edificios`
	- `TituloPropiedad::es_este_el_propietario` **->** `TituloPropiedad::es_propieratio`
	- `TituloPropiedad::get_importe_cancelar_hipoteca` **->** `TituloPropiedad::importe_cancelar_hipoteca`
	- `TituloPropiedad::get_precio_alquiler` **->** `TituloPropiedad::precio_alquiler`
	- `TituloPropiedad::get_precio_venta` **->** `TituloPropiedad::precio_venta`
- En los argumentos que reciben los métodos de `Casilla` se ha sustituido `iactual` por `actual` para que vaya acorde al resto de argumentos de los argumentos que toman los métodos de las otras clases.
- Se han sustituido los argumentos de algunos métodos por nombres que concuerden con el atributo que modifican.
- Se han eliminado los métodos `init` a favor de `initialize`.
