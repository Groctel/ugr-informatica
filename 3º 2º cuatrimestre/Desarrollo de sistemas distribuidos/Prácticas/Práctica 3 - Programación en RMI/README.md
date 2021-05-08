# Práctica 3 - Programación en RMI

## Ejecución de los ejemplos

### Ejemplo 1: Envío de mensaje simple

Situarse en el directorio `src`, donde se encuentra el fichero `server.policy` compilar todos los ficheros `.java`:

```sh
javac ejemplo1/*.java
```

Situados en dicho directorio, ejecutar `rmiregistry` (es bloqueante, usar `&` u otra pestaña) y el servidor:

```sh
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo1.Ejemplo
```

Y ejecutar el cliente de nuevo desde `src`:

```sh
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo1.Cliente_Ejemplo localhost 1337
```

### Ejemplo 2: Envío de mensaje multihebrado

Las instrucciones de compilación desde `src` son similares a las del ejemplo anterior:

```sh
javac ejemplo2/*.java
rmiregistry
```
Ejecutar el servidor y el cliente desde el mismo directorio:

```sh
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo2.Ejemplo
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo2.Cliente_Ejemplo_Multi_Thread localhost 10
```

### Ejemplo 3: Contador

```sh
javac ejemplo3/*.java
rmiregistry

java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo3.Servidor
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejemplo3.Cliente
```

## Ejecución del ejercicio

```sh
javac ejercicio/*.java
rmiregistry

java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejercicio.Servidor
java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ejercicio.Cliente
```
