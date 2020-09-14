# TEMA 4 - SEGMENTACIÓN DE CAUCE

## §4.1 - Concepto de segmentación

Trabajando secuencialmente, el tiempo que tardan en completarse $n$ tareas es $t_1+t_2+\cdots+t_{n-1}+t_n$ siendo $t_i$ el tiempo que tarda cada tarea en completarse.
La segmentación de cauce permite incrementar la velocidad de procesamiento sin incrementar el número de procesadores.

Al igual que en una cadena de montaje se segmenta el proceso de fabricación en distintos estadios permitiendo el solapamiento de los mismos, podemos segmentar el procesador en un número $n$ de etapas permitiendo el solapamiento en la ejecución de instrucciones, pudiendo ejecutar hasta $n$ instrucciones a la vez.
Cada una de estas instrucciones tarda en completarse individualmente $t_i$ unidades de tiempo, pero si analizamos el total de instrucciones ejecutadas en este tiempo, tenemos el mismo resultado que si se hubieran ejecutado secuencialmente tardando cada una $frac{t_i}{n}$ unidades.

Tengamos un procesador que realiza cinco actividades:

- **IF:** Búsqueda de instrucción (*instruction fetch*).
- **ID:** Decodificación de instrucción y lectura de registros (*instruction decode*).
- **EX:** Ejecución y cálculo de direcciones (*execute*).
- **MEM:** Acceso a memoria (*memory*).
- **WB:** Escritura de resultados (*write back*).

Cada una de estas actividdes componen una etapa del procesador, es decir, éste está dividido en secciones individuales conectadas entre sí que hacen cada una una de estas actividades.

Para que esto sea posible, cada etapa del cauce debe poder completarse en un mismo $t_i$ (idealmente un ciclo de reloj), por lo que el período del reloj se escoge de acuerdo a la etapa más lenta.

## §4.2 - Aceleración

Tengamos cuatro procesos $P_1$, $P_2$, $P_3$ y $P_4$ divididos en las cinco etapas descritas en §4.1.
Si los ejecutamos secuencialmente, tardaremos $20$ unidades de tiempo en completarlos todos (suponiendo una unidad por etapa):

\pagebreak

| Proceso | $1-5$ | $6-10$ | $11-15$ | $16-20$ |
| :-----: | :---: | :----: | :-----: | :-----: |
|  $P_1$  | $P_1$ |        |         |         |
|  $P_2$  |       | $P_2$  |         |         |
|  $P_3$  |       |        |  $P_3$  |         |
|  $P_4$  |       |        |         |  $P_4$  |

Si segmentamos el procesador en cinco etapas $S_i$ podemos completar los cuatro procesos en $8$ unidades de tiempo:

| Proceso |  $1$  |  $2$  |  $3$  |  $4$  |  $5$  |  $6$  |  $7$  |  $8$  |
| :-----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  $P_1$  | $S_1$ | $S_2$ | $S_3$ | $S_4$ | $S_5$ |       |       |       |
|  $P_2$  |       | $S_1$ | $S_2$ | $S_3$ | $S_4$ | $S_5$ |       |       |
|  $P_3$  |       |       | $S_1$ | $S_2$ | $S_3$ | $S_4$ | $S_5$ |       |
|  $P_4$  |       |       |       | $S_1$ | $S_2$ | $S_3$ | $S_4$ | $S_5$ |

Definimos la aceleración práctica como la razón entre el tiempo de ejecución sin y con segmentación:

\begin{center}
$$\frac{\text{Tiempo sin segmentación}}{\text{Tiempo con segmentación}}$$
\end{center}

Definimos así la aceleración ideal de $k$ instrucciones con un procesador de $n$ etapas:

\begin{center}
$$\frac{k\cdot T}{\frac{(n-1+k)\cdot T}{n}}=\frac{n\cdot k\cdot T}{(n+k-1)\cdot T}=n$$
\end{center}

Como era de esperar, la aceleración no siempre es la ideal en esta realidad de sometimientos euclidianos.
La duración del ciclo de reloj impuesto por la etapa más lenta, el coste de la segmentación o los riesgos que ésta conlleva disminuyen la aceleración.

## §4.3 - Riesgos

Existen situaciones que impiden la ejecución de la siguiente instrucción del flujo del programa durante su ciclo de reloj correspondiente, lo cual obliga a modificar la forma en la que avanzan las instrucciones a lo largo de las etapas del procesador y reducen las prestaciones logradas por la segmentación.

### Riesgos estructurales

Supongamos el siguiente programa en ensamblador[^lw] MIPS:

```asm
lw  r4, 20(r1)    # IF ID EX MEM WB
and r7, r2,    r2 #    IF ID EX  MEM WB
or  r9, r6,    r2 #       IF ID  EX  MEM WB
add r9, r2,    r2 #          IF  ID  EX  MEM WB
```

Como podemos observar, el acceso a memoria `MEM` de `lw` entra en colisión con el acceso a memoria `IF` de `add`, por lo que debemos retrasar la ejecución de este último para evitarla:

```asm
lw  r4, 20(r1)    # IF ID EX MEM WB
and r7, r2,    r2 #    IF ID EX  MEM WB
or  r9, r6,    r2 #       IF ID  EX  MEM WB
add r9, r2,    r2 #          -   IF  ID  EX MEM WB
```

Ocurriría lo mismo si tuviéramos una operación con más de un ciclo `EX` (volvemos a usar MIPS):

```asm
add rx, rx, rx # IF ID EX MEM WB
mul rd, rs, rs #    IF ID EX  EX  EX  MEM WB
add rx, rx, rx #       IF ID  EX  MEM WB
add rx, rx, rx #          IF  ID  EX  MEM WB
add rx, rx, rx #              IF  ID  EX  MEM WB
```

Vemos que entrar en colisión varios `EX`, `MEM` y `WB`, por lo que debemos ajustar la ejecución:

```asm
add rx, rx, rx # IF ID EX MEM WB
mul rd, rs, rs #    IF ID EX  EX  EX  MEM WB
add rx, rx, rx #       IF ID  -   -   EX  MEM WB
add rx, rx, rx #          IF  -   -   ID  EX  MEM WB
add rx, rx, rx #              -   -   IF  ID  EX  MEM WB
```

También podría pasar que una instrucción tuviera más de un cicle `IF`, lo cual crearía un fallo de caché.
Para subsanar esto, se realiza una precaptación de las instrucciones y se almacenan en una cola antes de que sean necesarias.

### Riesgos por dependencias de datos

También es posible que tengamos errores por dependencias de datos, es decir, el valor de éstos depende del resultado de instrucciones precedentes:

```asm
sub r2, r1, r3 # IF ID EX MEM WB
and r7, r2, r5 #    IF ID EX  MEM WB
or  r8, r6, r2 #       IF ID  EX  MEM WB
add r9, r2, r2 #          IF  ID  EX  MEM WB
```

En este caso, el valor de `r2` en `and`, `or` y `add` depende del valor del mismo devuelto por `sub` en la etapa `WB`, por lo que habría que realizar ajustes:

```asm
sub r2, r1, r3 # IF ID EX MEM WB
and r7, r2, r5 #    IF -  -   -  ID EX  MEM WB
or  r8, r6, r2 #       IF -   -  -  ID  EX  MEM WB
add r9, r2, r2 #          -   -  -  IF  ID  EX  MEM WB
```

Podríamos elimitar este retardo si, en lugar de obligar a `r2` a pasar por `MEM` y `WB`, lo mandáramos desde fuera de la ALU (por donde sale al final de `EX`) de vuelta a ella para la `EX` siguiente.

Las dependencias por dependencias de datos las descubre el mismo hardware al decodificar las instrucciones si no han sido resueltas por el compilador, en cuyo caso añadiría tantas instrucciones `nop` como fuesen necesarias para subsanar este riesgo:

```asm
sub r2, r1, r3 # IF ID EX MEM WB
nop            #    IF ID EX  MEM WB
nop            #       IF ID  EX  MEM WB
nop            #          IF  ID  EX  MEM WB
add r9, r2, r2 #              IF  ID  EX  MEM WB
```

Este sistema tiene la ventaja de que simplifica el hardware, ya que no tiene que realizar el trabajo de encontrar estos riesgos en tiempo de ejecución, y que reorganiza las instrucciones para realizar trabajo útil para el programa en lugar de `nop`.
Sin embargo, esto aumenta el tamaño del código.

### Riesgos de control

Las instrucciones de salto tienen el problema de que no realizan dicho salto hasta su etapa `EX`, punto en el cual las dos siguientes instrucciones ya han avanzado hasta `ID` e `IF` respectivamente, por lo que se pierden dos ciclos en la instrucción.
Llamamos a esta pérdida huecos de retardo de salto (*branch delay slot*).
Para reducir este retardo, queremos averiguar la dirección de salto cuanto antes.
Si la averiguamos en `ID`, perdemos sólo un ciclo.
En el caso de las instrucciones condicionales, perdemos siempre dos ciclos si se produce el salto y ninguno si no se produce.

Para arreglar esto, realizamos un **salto retardado**, que consiste en colocar una instrucción lógicamente anterior al salto (y que no afecte a su posible condición) después del mismo.
Se garantiza que esta instrucción se realizará después del salto y antes de la instrucción de destino.

```asm
# Salto normal
mov $0, %rcx
jmp destino
nop

# Salto retardado
jmp destino
mov $0, %rcx
```

También podría colocarse la primera instrucción de destino tras el salto:

```asm
# Salto normal
	call subrutina
	nop
subrutina:
	mov $0, %rcx

# Salto retardado
	call subrutina+4
	mov $0, %rcx
subrutina:
	mov $0, %rcx # No se ejecuta
```

Esta estrategia no funcionaría para saltos condicionales, ya que no podemos desplazar una instrucción que se ejecuta condicionalmente a una posición que se ejecuta incondicionalmente.
Para estos casos buscamos un **salto anulante**, que ejecute la instrucción siguente únicamente si se produce el salto.
Para ello, debemos predecir si una instrucción concreta producirá un salto o no (*branch (not)? taken*).
Como los resultados de las instrucciones son determinísticos (no aleatorios), podemos realizar dicha predicción de forma dinámica en función de la historia de ejecución del programa.
Para ello, definimos cuatro estados de la predicción:

- **ST:** Salto muy probable (*surely taken*).
- **LT:** Salto algo probable (*likely taken*).
- **LNT:** Salto poco probable (*likely not taken*).
- **SNT:** Salto muy poco probable (*surely not taken*).

Estos estados determinan la posibilidad de que se haga el salto (**BT**, branch taken) o no (**BNT**, branch not taken).
Podemos predecirlo mediante algoritmos de dos y cuatro estados (uno y dos bits por instrucción respectivamente):

\begin{center}
\begin{tikzpicture}[scale=0.2]
\tikzstyle{every node}+=[inner sep=0pt]
\draw [black] (11.9,-13.1) circle (3);
\draw (11.9,-13.1) node {$LNT$};
\draw [black] (21.2,-13.1) circle (3);
\draw (21.2,-13.1) node {$LT$};
\draw [black] (39.7,-5.7) circle (3);
\draw (39.7,-5.7) node {$SNT$};
\draw [black] (52.5,-5.7) circle (3);
\draw (52.5,-5.7) node {$LNT$};
\draw [black] (39.7,-19.5) circle (3);
\draw (39.7,-19.5) node {$LT$};
\draw [black] (52.5,-19.5) circle (3);
\draw (52.5,-19.5) node {$ST$};
\draw [black] (13.219,-10.462) arc (135.14587:44.85413:4.699);
\fill [black] (19.88,-10.46) -- (19.67,-9.54) -- (18.96,-10.25);
\draw [black] (19.408,-15.448) arc (-54.72018:-125.27982:4.948);
\fill [black] (13.69,-15.45) -- (14.06,-16.32) -- (14.63,-15.5);
\draw [black] (23.88,-11.777) arc (144:-144:2.25);
\draw (28.45,-13.1) node [right] {$BT$};
\fill [black] (23.88,-14.42) -- (24.23,-15.3) -- (24.82,-14.49);
\draw [black] (9.22,-14.423) arc (-36:-324:2.25);
\draw (4.65,-13.1) node [left] {$BNT$};
\fill [black] (9.22,-11.78) -- (8.87,-10.9) -- (8.28,-11.71);
\draw [black] (37.02,-7.023) arc (324:36:2.25);
\draw (32.45,-5.7) node [left] {$BNT$};
\fill [black] (37.02,-4.38) -- (36.67,-3.5) -- (36.08,-4.31);
\draw [black] (55.18,-18.177) arc (144:-144:2.25);
\draw (59.75,-19.5) node [right] {$BT$};
\fill [black] (55.18,-20.82) -- (55.53,-21.7) -- (56.12,-20.89);
\draw [black] (41.903,-3.689) arc (121.6464:58.3536:8);
\fill [black] (50.3,-3.69) -- (49.88,-2.84) -- (49.35,-3.7);
\draw (46.1,-2) node [above] {$BT$};
\draw [black] (50.128,-7.513) arc (-62.46399:-117.53601:8.714);
\fill [black] (42.07,-7.51) -- (42.55,-8.33) -- (43.01,-7.44);
\draw (46.1,-9) node [below] {$BNT$};
\draw [black] (41.956,-17.548) arc (120.37102:59.62898:8.196);
\fill [black] (50.24,-17.55) -- (49.81,-16.71) -- (49.3,-17.58);
\draw (46.1,-15.92) node [above] {$BT$};
\draw [black] (50.346,-21.562) arc (-57.21504:-122.78496:7.841);
\fill [black] (41.85,-21.56) -- (42.26,-22.42) -- (42.8,-21.57);
\draw (46.1,-23.31) node [below] {$BNT$};
\draw [black] (52.5,-8.7) -- (52.5,-16.5);
\fill [black] (52.5,-16.5) -- (53,-15.7) -- (52,-15.7);
\draw (52,-12.6) node [left] {$BT$};
\draw [black] (39.7,-16.5) -- (39.7,-8.7);
\fill [black] (39.7,-8.7) -- (39.2,-9.5) -- (40.2,-9.5);
\draw (40.2,-12.6) node [right] {$BNT$};
\end{tikzpicture}
\end{center}

## §4.4 - Influencia en el repertorio de instrucciones

### Modos de direccionamiento

Idealmente, un operando no debería necesitar más de un acceso a memoria y sólo podrían acceder a ellas las instrucciones de carga y almacenamiento.
Tomemos como ejemplo el siguiente código MIPS:

```asm
lw  r4, (20(r1))    # IF ID EX MEM MEM WB
and r7, r2,      r5 #    IF ID EX  -   MEM WB
```

Podemos adaptarlo para un hardware más sencillo con la misma duración de ejecución limitando `lw` a un solo acceso a memoria:

```asm
lw  r2, 20(r1)    # IF ID EX MEM WB
lw  r4, r3        #    IF ID EX  MEM WB
and r7, r2,    r5 #       IF ID  EX  MEM WB
```

### Códigos de direccionamiento

Las dependencias introducidas por los bits de condición dificultan la tarea del compilador de reordenación del código que usamos para evitar riesgos, pero podemos desplazar las instrucciones de condición hacia posiciones anteriores si las instrucciones siguientes no generan conflictos de sincronización:

```asm
# Desperdiciando un ciclo
add r1, r2
cmp r3, r4
jz  etiqueta

# Sin desperdicio
cmp r3, r4
add r1, r2
jz etiqueta
```

## §4.5 - Funcionamiento superescalar

Contrariamente al procesamiento segmentado, que es secuencia, tenemos el procesamiento superescalar, que permite la ejecución de varias instrucciones en paralelo.
Para ello, son necesarias varias unidades funcionales, de forma que se pueda ejecutar más de una instrucción por ciclo de reloj (**emisión múltiple**).
Para el correcto funcioamiento de este procesamiento, es fundamental poder captar las instrucciones rápidamente, teniendo una conexión ancha con la caché y una cola de instrucciones.

Sin embargo, el efecto negativo de los riesgos es más pronunciado, aunque el compilador puede reordenar las instrucciones para evitarlos.
Igualmente, las instrucciones pueden resolverse de forma desordenada.
Se abordará más sobre este funcionamiento en Arquitectura de Computadores.

[^lw]: Para este ejemplo usamos la instrucción MIPS `lw`, que realiza un accesso a memoria en la cuarta etapa.
