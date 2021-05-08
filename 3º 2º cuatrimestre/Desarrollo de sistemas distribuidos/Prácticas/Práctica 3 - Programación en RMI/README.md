# Práctica 3 - Programación en RMI

## Ejecución de los ejemplos

### Ejemplo 1: Envío de mensaje simple

Situarse en el directorio `src`, donde se encuentra el fichero `server.policy` y ejecutar `rmiregistry`.
Luego, en otra pestaña dentro del mismo directorio o habiendo usado el operador `&`, compilar todos los ficheros `.java`:

```sh
javac ejemplo1/*.java
```

Situados en dicho directorio, ejecutar el servidor:

```sh
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo1/Ejemplo
```

Y ejecutar el cliente de nuevo desde `src`:

```sh
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo1/Cliente_Ejemplo localhost 1337
```
