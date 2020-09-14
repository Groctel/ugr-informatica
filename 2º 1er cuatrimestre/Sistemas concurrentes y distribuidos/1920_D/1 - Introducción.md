# 1 - INTRODUCCIÓN

## 1.1 - CONCEPTOS BÁSICOS Y MOTIVACIÓN

### 1.1.1 - DEFINICIONES

- **Programa secuencia:** Declaraciones de datos y conjunto de instrucciones sobre dichos datos que se deben ejecutar en secuencia.
- **Programa concurrente:** Conjunto de programas secuenciales ordinarios que se pueden ejecutar lógicamente en paralelo.
- **Proceso:** Ejecución de un programa secuencial.
- **Concurrencia:** Potencial para ejecución paralela.
- **Ejecución paralela:** Solapamiento real o virtual de varas actividades en el tiempo.
- **Programación concurrente (PC):** Conjunto de notaciones y técnicas de programación usadas para expresar paralelismo potencial y resolver problemas de sincronización y comunicación.
  - Es independiente de la implementación del paralelismo. Es una abstracción.
- **Programación paralela:** Programación cuyo principal objetivo es acelerar la resolución de problemas concretos mediante el aprovechamiento de la capacidad de procesamiento en paralelo del hardware disponible.
- **Programación distribuida:** Programación cuyo principal objetivo es hacer que varios componentes software localizados en diferentes ordenadores trabajen juntos.
- **Programación de tiempo real:** Programación cnetrada en la programación de sistemas que están funcionando continuamente, recibiendo entradas y enviando salidas a/desde componentes hardware (**sistemas reactivos**) en los que se trabaja con restricciones muy estrictas en cuanto a la respuesta temporal (**sistemas de tiempo real**).

> La programación concurrente es necesaria porque mejora la eficiencia.

## 1.2 - MOTIVACIÓN

Aunque sea más compleja que la programación secuencial, a programación concurrente permite aprovechar mejor los recursos hardware existentes:

- **En sistemas con un solo procesador:**
  - Al tener varias tareas, cuando la tarea que tiene el control del procesador necesita realizar una E/S cede el control a otra, evitando la espera ociosa del procesador.
  - También permite que varios usuarios usen el sistema de forma interactiva (actuales sistemas operativos multiusuario).
- **En sistemas con varios procesadores:**
  - Esposible repartir las tareas entre los procesadores, reduciendo el tiempo de ejecución.
  - Fundamental para acelerar cómputos numéricos complejos.

Muchos programas se entienden mejor como varios procesos ejecutándose concurrentemente que como un único programa secuencial:

- Reserva de tickets en un servidor web.
- Los Sims.

## 1.2 - MODELOS ABSTRACTO Y CONSIDERACIONES SOBRE EL HARDWARE

### 1.2.1 - MODELOS DE ARQUITECTURAS PARA PROGRAMACIÓN CONCURRENTE

Mecanismos de implementación de la concurrencia:

- Dependen fuertemente de la arquitectura.
- Considera una máquina virtual que representa un sistema (multiprocesador o distribuido), proporcionando base homogénea para ejecución de los procesos concurrentes.
- El tipo de paralelismo afecta a la eficiencia pero no a la corrección.

#### 1.2.1.1 - Concurrencia en sistemas monoprocesador

- **Multiprogramación:** El sistema operativo gestiona cómo se reparten la CPU los diferentes procesos.
  - Se aprovecha mejor la CPU.
  - Se ofrece un servicio interactivo a varios usuarios.
  - Permite utilizar soluciones de diseño concurrentes.
  - Los procesos se sincronizan y se comunican entre sí mediante variables compartidas.

#### 1.2.1.2 - Concurrencia en multiprocesadores de memoria compartida

Los procesadores comparten un espacio de direcciones, pero no siempre comparten físicamente la memoria, por lo que la interacción entre los procesoss se puede implementar mediante variables alojadas en direcciones del espacio compartido.

#### 1.2.1.3 - Concurrencia en sistemas distribuidos

Al no existir una memoria común cada procesador tiene su espacio de direcciones privado, por lo que interaccionan compartiendo datos a través de una red de interconexión.

Al no existir una memoria común cada procesador tiene su espacio de direcciones privado, por lo que interaccionan compartiendo datos a través de una red de interconexión.

- **Programación distribuida:** Trata con problemas como la trasparencia, heterogeneidad y tratamiento de fallos además de la concurrencia.

### 1.2.2 - MODELO ABSTRACTO DE CONCURRENCIA

#### 1.2.2.1 - Sentencias atómicas y no atómicas

**Sentencia atómica (indivisible):** Sentencia o instrucción de un proceso en un programa concurrente es atómica si **siempre** se ejecuta de principio a fin sin verse afectada durante su ejecución por otras sentencias en ejecución de otros procesos del programa.

- No se verá afectada cuando el funcionamiento de dicha instrucción no dependa nunca de cómo se estén ejecutando otras instrucciones

# TODO: ACABAR

- La celda de memoria o registro en el que se escribe tomará siempre un valor concreto predecible siempre a partir del estado al inicio.
- Ejemplos:
  - Leer una celda de memoria y cargar su valor en ese momento en un registro de procesador.
  - Incrementar el valor de un registro.
  - Escribir el valor de un registro en una celda de memoria.

**Sentencia no atómica:** El resultado depende de que haya o no otras sentencias ejecutándose a la vez escribiendo simultáneamente sobre la misma celda de memoria o registro, por lo que no se puede predecir el estado final a partir del inicial.

Ejemplo de sentencia no atómica:

```c++
var++;
```

## 1.3 - RESTRICCIONES SOBRE EL ENTREMEZCLADO

Debido a que el entremezclado de las sentencias atómicas de diferentes procesos concurrentes es arbitrario y que existen procesos que no son idependientes entre sí (son cooperativos), se pueden dar dos casos en los que algunas secuencias no sean válidas: La condición de sincronización y la exclusión mutua.

### 1.3.1 - CONDICIÓN DE SINCRONIZACIÓN

Una condición de sincronización se produce cuando existe una restricción en el orden en el que se pueden mezclar las instrucciones de los procesos, es decir, **no todas las posibles interfoliaciones de las secuencias de instrucciones atómicas de los procesos son correctas**.

Un ejemplo sencillo de esto es un programa con dos procesos que acceden a una variable compartida.
En este ejemplo en concreto, el único uso correcto del programa es que cada valor producido se consuma una sola vez.

```pascal
{ variables compartidas }
var x : integer ;
```

```pascal
{ Productor: Calcula el valor de x }
process Productor ;
	var a : integer ; { local }
begin
	while true do begin
		a := ProducirValor() ; { Calcula un valor }
		x := a ; { Sentencia E }
	end
end
```

```pascal
{ Consumidor: Lee x }
process Consumidor ;
	var b : integer ; { local }
begin
	while true do begin
		b := x { Sentencia L }
		UsarValor(b) ; { Opera sobre el valor leído }
	end
end
```

Tenemos las sentencias $E$ (escritura) y $L$ (lectura).
De esta forma, sabemos que el orden correcto de ejecución de este programa es $E,L,E,L,\cdots$.
Tenemos tres tipos de interfoliaciones incorrectas:
- **$L,E,L,E,\cdots$:** Se hace una lectura de `x` antes de escribir en ella, leyendo un valor basura.
- **$E,L,E,E,L,\cdots$:** Se escribe un valor en `x` que no llega a utilizarse en ningún momento.
- **$E,L,L,E,\cdots$:** Se producen dos lecturas y usos del mismo valor de `x`.

Para solucionar esto utilizamos una condición de sincronización:
- `Consumidor` no puede leer `x` hasta que `Productor` no haya escrito un valor nuevo en ella.
- `Productor` no puede escribir un valor en `x` hasta que `Consumidor` no lo haya leído.

### 1.3.2 - EXCLUSIÓN MUTUA

Las exclusiones mutuas son un caso particular de la condición de sincronización.
Se dan cuando existen secuencias de instrucciones de dos o más procesos que no pueden entremezclarse (**secciones críticas**), pues al hacerlo los procesos no funcionan corerctamente.
Es imperativo que haya como máximo una sección crítica ejecutándose a la vez en cada instante de tiempo.

Tomemos como ejemplo los siguientes procesos:

```pascal
{ Variables compartidas }
var x : integer ;
```

```pascal
{ Proceso 0 }
x := x + 1 ;
```

```pascal
{ Proceso 1 }
x := x + 1 ;
```

Ambos procesos ($P_0$ y $P_1$) son iguales y pueden dividirse en las siguientes instrucciones atómicas:

+:----------------------------+:---------------------------------------------+
| `load r`$_i\leftarrow$`x`   | Carga `x` en un registro `r`.                |
+:----------------------------+:---------------------------------------------+
| `add r`$_i,$`1`             | Incrementa `r` en `1`.                       |
+:----------------------------+:---------------------------------------------+
| `store r`$_i\rightarrow$`x` | Guarda `r` en la posición de memoria de `x`. |
+-----------------------------+----------------------------------------------+

Consideraremos que $P_0$ accede al registro `r`$_0$ y $P_1$, a `r`$_1$.
Podemos obtener dos valores finales de `x` (partiendo de que `x:=0`)distintos dependiendo de si se entremezclan ambas secciones críticas:

+:---------------------------:+:---------------------------:+:---:+
|            $P_0$            |            $P_1$            | `x` |
+:---------------------------:+:---------------------------:+:---:+
|  `load r`$_0\leftarrow$`x`  |                             | `0` |
+:---------------------------:+:---------------------------:+:---:+
|       `add r`$_0,$`1`       |                             | `0` |
+:---------------------------:+:---------------------------:+:---:+
| `store r`$_0\rightarrow$`x` |                             | `1` |
+:---------------------------:+:---------------------------:+:---:+
|                             |  `load r`$_1\leftarrow$`x`  | `1` |
+:---------------------------:+:---------------------------:+:---:+
|                             |       `add r`$_1,$`1`       | `1` |
+:---------------------------:+:---------------------------:+:---:+
|                             | `store r`$_1\rightarrow$`x` | `2` |
+-----------------------------+-----------------------------+-----+

+:---------------------------:+:---------------------------:+:---:+
|            $P_0$            |            $P_1$            | `x` |
+:---------------------------:+:---------------------------:+:---:+
|  `load r`$_0\leftarrow$`x`  |                             | `0` |
+:---------------------------:+:---------------------------:+:---:+
|                             |  `load r`$_1\leftarrow$`x`  | `0` |
+:---------------------------:+:---------------------------:+:---:+
|       `add r`$_0,$`1`       |                             | `0` |
+:---------------------------:+:---------------------------:+:---:+
|                             |       `add r`$_1,$`1`       | `0` |
+:---------------------------:+:---------------------------:+:---:+
| `store r`$_0\rightarrow$`x` |                             | `1` |
+:---------------------------:+:---------------------------:+:---:+
|                             | `store r`$_1\rightarrow$`x` | `1` |
+-----------------------------+-----------------------------+-----+

Podemos indicar las secciones críticas en el pseudocódigo encapsuándolas en `< >`:

```pascal
begin
	x := 0;
	cobegin
		x := x + 1 ;
		x := x - 1 ;
	coend
end
```

```pascal
begin
	x := 0;
	cobegin
		< x := x + 1 > ;
		< x := x - 1 > ;
	coend
end
```

En el primer código `x` puede tener los valores `-1`, `0` ó `1`, mientras que en el segundo tenemos la seguridad de que va a acabar con valor `0`.

## 1.4 - PROPIEDADES DE LOS SISTEMAS CONCURRENTES

## 1.5 - VERIFICACIÓN DE PROGRAMAS CONCURRENTES

