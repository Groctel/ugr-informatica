# EJERCICIO 5

**¿Dónde es más compleja una llamada al sistema, en un sistema monolítico o por capas?**

Las llamadas al sistema son más complejas en los sistemas monolóticos con respecto a los sistemas por capas debio a que no tienen la estructura de los últimos.

# EJERCICIO 10

**Describa las tareas típicas de las funciones que se realizan cuando se inicia y finaliza la utilización de un módulo.**

Se pueden cargar módulos sin sus dependencias mediante la orden `insmod`, con ellas mediante `modprobe` y eliminarlas con `rmmod`.

# EJERCICIO 11

**Puesto que el propio núcleo de Linux puede requerir módulos, ¿cómo lleva a cabo Linux la carga automáticas de dichos módulos?**

Los módulos se definen mediante dos tablas:

- Tabla de módulos: Tiene, para cada módulo, un puntero hacia el siguiente y hacia su nombre, las páginas que ocupa, el contador de uso, las opciones, el número de símbolos exportados y módulos referenciados, un punterio hacia la tabla de símbolos y hacia la lista de módulos que usa.
- Tabla de símbolos: Define los símbolos controlados por el módulo que se utilizan en otros sitios.

# EJERCICIO 13

**¿Cuál es la principal ventaja de Namespaces en comparación con entornos virtualizados tales como KVM y VMWare?**

La limpieza y simplicidad del código, pues sustituye llamadas a las diferentes clases por palabras más simple o, simplemente, elimina la necesidad de añadirlas.

# EJERCICIO 16

**Cuestiones sobre procesos, y asignación de CPU:**

- **¿Es necesario que lo último que haga todo proceso antes de finalizar sea una llamada al sistema para finalizar? ¿Sigue siendo esto cierto en sistemas monoprogramados?**

Sí, pues el sistema operativo debe saber cuándo ha acabado un proceso para poder liberarlo y ofrecer sus recursos a procesos posteriores.
En sistemas operativos monoprogramados el caso es el mismo, sólo que varían las acciones que lleva a cabo el SO tras recibir la llamada.

- **Cuando un proceso se bloquea, ¿deberá encargarse él directamente de cambiar el valor de su estado en el descriptor de proceso o PCB?**

Dado que el PCB es un dato del sistema operativo, quien se debe encargar de cambiarlo es él mismo desde el modo kernel.

- **¿Qué debería hacer el planificador a corto plazo cuando es invocado pero no hay ningún proceso en la cola de ejecutables?**

En muchos sistemas se invoca un proceso `null`, que se ejecuta indefinidamente con prioridad mínima, impidiendo bloquear el paso a futuros procesos.
La función principal de este proceso es asegurar que la cola de procesos nunca esté vacía mientras realiza tareas básicas de mantenimiento.

- **¿Qué algoritmos de planificación quedan descartados para ser utilizados en sistemas de tiempo compartido?**

Debido a que en sistemas de tiempo compartido prima la facilidad de concurrencia entre procesos, se prefieren algoritmos que favorezcan procesos cortos, descartando todos los que no los favorezcan.
De igual manera, se descartan todos los algoritmos que puedan crear inanición de procesos debido a su prioridad, como es el caso del algoritmo SJF.

# EJERCICIO 17

**La representación gráfica del cociente `(tiempo_en_cola_ejecutables + tiempo_de_CPU) / tiempo_de_CPU` frente a `tiempo_de_CPU` suele mostrar valores muy altos para ráfagas muy cortas en casi todos los algoritmos de asignación de CPU
¿Por qué?**

Este cociente, llamado *penalización*, aumenta con procesos muy cortos debido a que, en general, el tiempo que pasa un proceso en la cola de procesos es mayor que el que pasa ejecutándose si éste es muy corto, por lo que la razón entre el tiempo total del proceso y el tiempo activo aumenta.

# EJERCICIO 20

**Sea un sistema multiprogramado que utiliza el algoritmo Por Turnos (Round-Robin).
Sea $S$ el tiempo que tarda el despachador en cada cambio de contexto.
¿Cuál debe ser el valor de quantum $Q$ para que el porcentaje de uso de la CPU por los procesos de usuario sea del $80%$?**

Tenemos que el tiempo total de uso de la CPU es $T=S+Q$.
Si queremos que el porcentaje de uso de la CPU por los procesos del usuario sea del $80%$, tenemos que $Q=0.8T$.
Por tanto:

\begin{center}
$$\frac{5Q}{4}=S+Q\rightarrow S=\frac{5Q}{4}-Q\rightarrow S=\frac{Q}{4}\rightarrow Q=4S$$
\end{center}

$Q$ debe valer cuatro veces $S$ para que el porcentaje de uso de la CPU por los procesos del usuario sea del $80%$.

# EJERCICIO 25

**En el algoritmo de planificación FCFS, la penalización definida por `(t + tº_espera) / t`, ¿es creciente, decreciente o constante respecto a `t` (tiempo de servicio de CPU requerido por un proceso)?
Justifique su respuesta.**

Sea la penalización:

\begin{center}
$$\frac{t+t_{espera}}{t}=1+\frac{t_{espera}}{t}$$
\end{center}

La penalización del proceso es decreciente con respecto a $t$, ya que, manteniéndose $t_{espera}$ constante, $\frac{t_{espera}}{t}$ es inversamente proporcional a $t$.

\pagebreak

# EJERCICIO 26

**En la tabla siguiente se describen cinco procesos:**

| Proceso | Tiempo de creación | Tiempo de CPU |
| :-----: | :----------------: | :-----------: |
|   `A`   |         4          |       1       |
|   `B`   |         0          |       5       |
|   `C`   |         1          |       4       |
|   `D`   |         8          |       3       |
|   `E`   |         12         |       2       |

+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+
|     | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ | $8$ | $9$ | $10$ | $11$ | $12$ | $13$ | $14$ |
+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+
| $A$ |     |     |     |     |     |     |     |     |     | $X$ |      |      |      |      |      |
+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+
| $B$ | $X$ | $X$ | $X$ | $X$ | $X$ |     |     |     |     |     |      |      |      |      |      |
+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+
| $C$ |     |     |     |     |     | $X$ | $X$ | $X$ | $X$ |     |      |      |      |      |      |
+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+
| $D$ |     |     |     |     |     |     |     |     |     |     | $X$  | $X$  | $X$  |      |      |
+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+
| $E$ |     |     |     |     |     |     |     |     |     |     |      |      |      | $X$  | $X$  |
+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:---:+:----:+:----:+:----:+:----:+:----:+

**Si suponemos que tenemos un algoritmo de planificación que utiliza una política FCFS (primero en llegar, primero en ser servido), calcula:**

- **Tiempo medio de respuesta:**

\begin{center}
$$\frac{(5+1)+(0+5)+(4+4)+(2+3)+(1+2)}{5}=5.4$$
\end{center}

El tiempo medio de respuesta es de $5.4$ unidades de tiempo.

- **Tiempo medio de espera:**

\begin{center}
$$\frac{(5+4)+0+5+(5+4+1)+(5+4+1+3)}{5}=7.4$$
\end{center}

El tiempo medio de espera es de $7.4$ unidades de tiempo.

- **La penalización, es decir, el cociente entre el tiempo de respuesta y el tiempo de CPU:**
  - `A`: $\frac{10}{1}=10$
  - `B`: $\frac{5}{5}=1$
  - `C`: $\frac{9}{4}=2.25$
  - `D`: $\frac{13}{3}=4.\overline{3}$
  - `E`: $\frac{15}{2}=7.5$


# EJERCICIO 30

**Suponga que debe maximizar la eficiencia de un sistema multiusuario y que está recibiendo quejas de muchos usuarios sobre los pobres tiempos de respuesta (o tiempos de vuelta) de sus procesos.
Los resultados obtenidos con una herramienta de monitorización del sistema nos muestran que la CPU se utiliza al $99.9%$ de su tiempo y que los procesadores de E/S están activos sólo un $10%$ de su tiempo.
¿Cuáles pueden ser las razones de estos tiempos de respuesta pobres y por qué?**

- **El quantum en la planificación Round-Robin es muy pequeño.**

Ésta no puede ser una de las razones, ya que el valor reducido de un quantum puede crear una sobrecarga del sistema, pero no tiempos de respuesta elevados.

- **La memoria principal es insuficiente.**

La insuficiencia de memoria principal sí puede ser una de las razones, ya que implica que los procesos necesitan más tiempo para acceder a recursos del sistema.

- **El sistema operativo tiene que manejar mucha memoria principal por lo que las rutinas de gestión de memoria están consumiendo todos los ciclos de CPU.**

Ésta no puede ser una de las razones, ya que el tamaño de la memoria no tiene por qué significar que su acceso sea complejo.

- **La CPU es muy lenta.**

Ésta no puede ser una de las causas, ya que una CPU muy lenta está activa el $100%$ del tiempo.

- **El quantum en la planificación Round-Robin es muy grande.**

Ésta sí puede ser una de las razones, ya que un quantum de tiempo muy grande en el Round-Robin hace que se dé prioridad a procesos largos antes que a procesos cortos, haciendo que la CPU esté demasiando tiempo ocupada sin realizar operaciones de E/S.

