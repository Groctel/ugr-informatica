# ÁLGEBRA DE SUCESOS

## 1 - DEFINICIONES BÁSICAS

- **Suceso:** Resultado de un experimento aleatorio.
- **Sucesos elementales:** Cada uno de los resultados posibles que no se pueden dividir en sucesos más pequeños.
- **Espacio muestral ($E$):** Conjunto formado por todos los sucesos elementales.
- **Suceso seguro:** Aquél que ocurre siempre. Contiene a todos los sucesos elementales.
- **Suceso imposible ($\varnothing$):** Aquél que no puede ocurrir. No contiene a ningún suceso elemental.
- **Sucesos incompatibles:** Aquéllos que no pueden suceder simultáneamente.
- **Unión de elementos ($A\cup B$):** Suceso que ocurre cuando ocurre $A$, $B$ o ambos simultáneamente. Contiene todos los sucesos elementales de $A$ y $B$.
- **Intersección de elmentos ($A\cap B$):** Suceso que ocurre cuando ocurren $A$ y $B$ simultáneamente Contiene todos los sucesos elementales de $A$ y $B$. Si $A$ y $B$ son incompatibles, su intersección es $\varnothing$.
- **Suceso complementario ($\overline{A}=A^{c}$):** Suceso que ocurre cuando no ocurre $A$. Contiene todos los sucesos elementales no contenidos en $A$.

### 1.1 - PROPIEDADES DE LAS OPERACIONES

| UNIÓN | INTERSECCIÓN |
| :---: | :---: |
| $A\cup A=A$ | $A\cap A=A$ |
| $A\cup B=B\cup A$ | $A\cap B=B\cap A$ |
| $(A\cup B)\cup C = A\cup(B\cup C)$ | $(A\cap B)\cap C = A\cap(B\cap C)$ |
| **$\overline{\varnothing} = E$** | **$\overline{E} = \varnothing$** |
| $A\cup\overline{A} = E$ | $A\cap\overline{A} = \varnothing$ |
| $\overline{A}\cup\overline{B}=\overline{A\cap B}$ | $\overline{A}\cap\overline{B}=\overline{A\cup B}$ |

- $(A\cup B)\cap C=(A\cap C)\cup(B\cap C)$

## 2 - PROBABILIDAD

### 2.1 - DEFINICIONES DE PROBABILIDAD

#### 2.1.1 - Definición clásica de Laplace

Razón entre el número de casos en el que ocurre $A$ y el número de casos posibles. Sólo sirve si todos los sucesos elementales son equiprobables.

<span style="font-size:1.5em;">
	$P(A)=\frac{\text{casos favorables}}{\text{casos posibles}}$
</span>

#### 2.1.2 - Definición frecuentista

Realizado el experimento un número suficientemente grande de veces, la probabilidad de que un suceso ocurra es el límite del número de veces que ocurre el suceso entre el número total de veces que se ha realizado dicho experimento.

#### 2.1.3 - Definicion axiomática de Kolmogorov

Dado un experimento aleatorio y su espacio muestral *E*, una aplicación que asocia a cada suceso un número real es una probabilidad si se verifican tres axiomas:
-  $P(A)\geq0,\,\forall A\in E$.
-  $P(E)=1$.
-  $P(\bigcup_iA_i)=\sum_iP(A_i)\Leftrightarrow A_1,A_2,A_3,\cdots,A_n$ son incompatibles.

Esta definición aporta una serie de propiedades a las operaciones sobre la probabilidad:
- $P(\overline{A})=1-P(A)$
- $P(E)=1\therefore P(\varnothing)=0$
- $P(A\cup B)=P(A)+P(B)-P(A\cap B)$
- $P(A\cup B\cup C)=P(A)+P(B)+P(C)-P(A\cap B)-P(B\cap C)-P(A\cap C)+P(A\cap B\cap C)$

### 2.2 - PROBABILIDAD CONDICIONADA

Dado un suceso $B$ con probabilidad no nula, llamamos probabilidad de $A$ condicionada a $B$, denotada como $P(A|B)$, a la probabilidad de que ocurra $A$ una vez ocurrido $B$.

<span style="font-size:1.5em">
	$P(A|B)=\frac{P(A\cap B)}{P(B)}$
</span>

### 2.3 - INDEPENDENCIA

Dos sucesos $A$ y $B$ son independientes si el hecho de que uno de ellos haya ocurrido antes que el otro no influye en las probabilidades de que ocurra el otro. Esto sucede únicamente si su intersección es $\varnothing$.

<span style="font-size:1.5em">
	$\begin{matrix}
		P(A|B)=P(A)
		\\
		P(B|A)=P(B)
	\end{matrix}
	\Leftrightarrow P(A\cap B)=P(A)P(B)$
</span>

### 2.4 - TEOREMA DE LA PROBABILIDAD TOTAL

Si $B$ es un suceso con probabilidad no nula y $A_1,A_2,A_3,\cdots,A_n$ una partición de $E$, la probabilidad de que ocurra $B$ es la suma de las probabilidades de que ocurra en cada partición $A_i$.

<span style="font-size:1.5em">
	$P(B)=\sum_{i=1}^nP(B|A_i)P(A_i)$
</span>

### 2.5 - TEOREMA DE BAYES

Si $B$ es un suceso con probabilidad no nula y $A_1,A_2,A_3,\cdots,A_n$ una partición de $E$, la probabilidad de que $B$ haya sucedido en una partición $A_k$ es la razón entre la probabilidad de que ocurra $B$ en dicha partición $A_k$ por la probabilidad de que ocurra $A_k$ y la probabilidad total de $B$.

<span style="font-size:1.5em">
	$P(A_k|B)=\frac{P(B|A_k)P(A_k)}{\sum_{i=1}^nP(B|A_i)P(A_i)}$
</span>

## 3 - EJERCICIOS

### EJERCICIO 1

Escribir el espacio muestral del experimento que consiste en lanzar simultáneamente una moneda y un dado.

### EJERCICIO 2

Se lanza una moneda 3 veces. Se pide:
- Construir el espacio muestral.
- Expresar, en función de los sucesos elementales, los siguientes sucesos:
  - Los tres lanzamientos producen el mismo resultado.
  - El mismo resultado aparece dos veces exactamente.
  - Al menos dos veces sale cara.
  - Exactamente dos veces sale cara.
  - La cara aparece en el primero y en el segundo de los lanzamientos.

### EJERCICIO 3

### EJERCICIO 4

### EJERCICIO 5

### EJERCICIO 6

### EJERCICIO 7

### EJERCICIO 8

### EJERCICIO 9

### EJERCICIO 10

### EJERCICIO 11

### EJERCICIO 12

### EJERCICIO 13

### EJERCICIO 14

### EJERCICIO 15

### EJERCICIO 16

### EJERCICIO 17

### EJERCICIO 18

### EJERCICIO 19

Un ratón huye de un gato y puede entrar en los callejones $A$, $B$, $C$ y $D$. LA probabilidad de que entre en cada uno de ellos es, respectivamente, $0.25$, $0.54$, $0.08$ y $0.13$. Se sabe que la probabilidad de que el ratón sea cazado en el callejón $A$ es $0.4$, en el callejón $B$ es $0.5$, en el $C$ es $0.9$ y en el $D$, $0.12$.

- Calcular la probabilidad de que el gato cace al ratón.
- Si el ratón finalmente es alcanzado por el gato, ¿qué callejón es más probable que eligiera?

### EJERCICIO 20

### EJERCICIO 21

## 4 - SOLUCIONES

### EJERCICIO 1

Contando con que el dado tiene seis caras, tenemos seis sucesos elementales para él:
- $1,2,3,4,5,6$

Para la moneda tenemos que puede salir cara ($C$) o cruz ($X$).

El conjunto del espacio muestral es el siguiente:

$E=\{\begin{matrix}
	C1&C2&C3&C4&C5&C6
	\\ 
	X1&X2&X3&X3&X5&X6
\end{matrix}\}$

### EJERCICIO 2

- Tenemos los sucesos elementales cara ($C$) y cruz ($X$). El espacio muestral es el siguiente:

  - $E=\{\begin{matrix}
	CCC&CCX&CXC&CXX
	\\
	XCC&XCX&XXC&XXX
\end{matrix}\}$

- Tenemos los siguientes sucesos elementales:

  - Los tres lanzamientos producen el mismo resultado: $\{CCC,XXX\}$

  - El mismo resultado aparece dos veces exactamente: $\{CCX,CXC,CXX,XCC,XCX,XXC\}$
  - Al menos dos veces sale cara: $\{CCC,CCX,CXC,XCC\}$
  - Exactamente dos veces sale cara: $\{CCX,CXC,XCC\}$
  - La cara aparece en el primero y en el segundo de los lanzamientos. $\{CCC,CCX\}$

### EJERCICIO 3

Un operario de una fábrica observa de tres en tres las piezas producidas por una máquina, anotando si cada una de ellas es defectuosa o no.
- Escribir el espacio muestral correspondiente a esta situación.
- Sea $A$ el suceso la primera pieza observada es defectuosa, $B$ el suceso la segunda pieza observada es defectuosa y $C$ el suceso la tercera pieza observada es defectuosa. Dar la descomposición en sucesos elementales de los siguientes sucesos: $A,B,C,A\cup B,A\cup CB\cup C,A\cup B\cup C,B\cap C,A\cap B\cap C$.

### EJERCICIO 4

Se tienen los sucesos aleatorios $A$ y $B$ y se conocen las probabilidades $P(A)=0.4;P(B)=0.2,P(A\cup B)=0.5$. ¿Son estos sucesos incompatibles? ¿Son estos sucesos independientes?

### EJERCICIO 5

Una caja contiene 6 bombillas, de las cuales dos son defectuosas. Si las bombillas son probadas hasta encontrar una defectuosa, descrı́base el espacio muestral del experimento.

### EJERCICIO 6

Un dado se lanza dos veces. Se pide:
- Construir el espacio muestral.
- Sea $A$ el suceso en el primer lanzamiento, el número es menor o igual que 2. Calcular $P(A)$ suponiendo que el dado está bien construido.
- Sea $B$ el suceso en el segundo lanzamiento el número es menor que 5, calcular $P(B)$.
- Calcular $P(A\cup B)$.

### EJERCICIO 7

Consideremos el experimento aleatorio consistente en el lanzamiento de dos monedas y un dado.
- Escribir el espacio muestral correspondiente.
- Expresar explı́citamente los sucesos siguientes:
  - $A$: aparecen dos caras y un número primo.
  - $B$: aparece un 3.
  - $C$: aparecen exactamente una cara y un número primo.
- Expresar explı́citamente los sucesos:
  - $A$ y $B$ suceden.
  - Sucede solamente $B$.
  - Sucede $B$ o $C$.

### EJERCICIO 8

Supongamos que $A$ y $B$ son dos sucesos para los cuales $P(A)=x,P(B)=y,P(A\cap B)=z$. Expresar cada una de las probabilidades siguientes en términos de $x$, $y$ y $z$:
- $P(A\cup B)$.
- $P(A\cap B)$.
- $P(A\cap B)$.

### EJERCICIO 9

La caja A contiene 4 bolas rojas, 1 verde y 3 negras. La caja B contiene 8 bolas rojas, 1 verde y 7
negras. Se tira un dado y si sale un número entre 1 y 4 entonces se selecciona al azar una bola de
la caja A. Si en el dado sale 5 o 6 se selecciona una bola de la caja B. Consideremos los sucesos A:
seleccionar la caja A, B: seleccionar la caja B, R: sacar la bola roja, V : sacar la bola verde y N :
sacar la bola negra. Se pide:
a) Escribir el espacio muestral asociado al experimento aleatorio.
b) P (R|A)
c) P (V )
d ) $P(V\cap B)$
e) $P(R\cup A)$
f ) $P(R\cup V)$
g) P (B|N )
h) ¿Son R y A sucesos independientes?

### EJERCICIO 10

### EJERCICIO 11

### EJERCICIO 12

### EJERCICIO 13

### EJERCICIO 14

### EJERCICIO 15

### EJERCICIO 16

### EJERCICIO 17

### EJERCICIO 18

### EJERCICIO 19

| **CALLEJÓN** | **ENTRA EN EL CALLEJÓN ($E$)** | **ES CAZADO ($X$)** |
| :---: | :---: | :---: |
| ***A*** | 0.25 | 0.4 |
| ***B*** | 0.54 | 0.5 |
| ***C*** | 0.08 | 0.9 |
| ***D*** | 0.13 | 0.12 |

Calculamos la probabilidad de que el gato cace al ratón mediante el teorema de la probabilidad total:

$P(X)=\sum_{i=1}^{N}P(X|E_{i})P(E_{i})$

### EJERCICIO 20

### EJERCICIO 21
