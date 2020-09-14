# CONCEPTOS BÁSICOS DE VARIABLES ALEATORIAS

## 1 - DEFINICIONES BÁSICAS

- **Variable aleatoria:** Función que asigna a cada suceso del espacio muestral $E$ un número real.
  - $X$ = Número de caras que salen al lanzar una moneda. $X_i=\{0,1,2,3\}$.
- **Variable aleatoria discreta:** $X$ toma un conjunto infinito numerable de valores.
- **Variable aleatorio continua:** $X$ toma un conjunto infinito no numerable de valores.

## 2 - VARIABLES DISCRETAS

### 2.1 - FUNCIÓN MASA DE PROBABILIDAD

| SUCESO ($x_i$) | Probabilidad ($P[X=x_i$) |
| :---: | :---: |
| $x_1$ | $p_1$ |
| $x_2$ | $p_2$ |
| $\cdots$ | $\cdots$ |
| $x_3$ | $p_3$ |
| **Sumatorio ($\sum$)** | $1$ |

### 2.2 - FUNCIÓN DE DISTRIBUCIÓN

### 2.3 - ESPERANZA

<span style="font-size:1.5em">
$E[X]=\sum_{i=1}^kx_iP(x_i)$
</span>

Representa el resultado esperado del experimento. Es la forma de calcular la media esperada de los resultados de un experimento que aún no se ha realizado.

### 2.4 - VARIANZA

<span style="font-size:1.5em">
$Var[X]=\sum_{i=1}^k(x_i-E[X])^2P(x_i)$
</span>

## 3 - VARIABLES CONTINUAS

### 3.1 - FUNCIÓN DE DENSIDAD

<span style="font-size:1,5em">
$f(x):\begin{matrix}
  f(x)\geq0
  \\
  \int_{b}^{a}f(x)=1
\end{matrix}$
</span>

### 3.2 - FUNCIÓN DE DISTRIBUCIÓN

<span style="font-size:1,5em">
$F(x)=P[X\leq x]:\begin{matrix}
  \lim_{x\rightarrow\infty}F(x)=1
  \\
  F(x)=\int_{-\infty}^{\infty}f(k)dk
\end{matrix}$
</span>

### 3.3 - ESPERANZA

### 3.4 - VARIANZA