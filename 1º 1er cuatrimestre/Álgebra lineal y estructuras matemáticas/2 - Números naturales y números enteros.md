# TEMA 1 - NÚMEROS NATURALES Y NÚMEROS ENTEROS

A lo largo de este tema suponemos conocido el conjunto de los números naturales $\mathbb{N}=\{0,1,2,3,\cdots\}$, que satisface los [axiomas de Peano](https://en.wikipedia.org/wiki/Peano_axioms).
También suponemos conocidos los números enteros $\mathbb{Z}$, los números racionales $\mathbb{Q}$, los números reales $\mathbb{R}$ y los números complejos $\mathbb{C}$.
Todos estos conjuntos, salvo $\mathbb{C}$, satisfacen una estructura algebraica y de orden.

## 1.1 - NÚMEROS NATURALES

### 1.1.1 PROPIEDADES DE LOS NÚMEROS NATURALES

Dados dos números naturales $m$ y $n$, podemos llamar a su **suma** $m+n$ y a su **producto**, $m\cdot n$.
De esta forma podemos definir dos números naturales nuevos a partir de dos iniciales, satisfaciendo las siguientes propiedades:

- **PROPIEDADES DE LA SUMA:**
  - **Propiedad asociativa:** $\forall m,n,p\in\mathbb{N},(m+n)+p=m+(n+p)$.
  - **Propiedad conmutativa:** $\forall m,n\in\mathbb{N},m+n=n+m$.
  - **Elemento neutro:** $\forall m\in\mathbb{N},m+0=m$.
  - **Propiedad cancelativa:** $m+n=m+p\iff n=p$.
- **PROPIEDADES DEL PRODUCTO:**
  - **Propiedad asociativa:** $\forall m,n,p\in\mathbb{N},(m\cdot n)\cdot p=m\cdot (n\cdot p)$.
  - **Propiedad conmutativa:** $\forall m,n\in\mathbb{N},m\cdot n=n\cdot m$.
  - **Elemento neutro:** $\forall m\in\mathbb{N},m\cdot1=m$.
  - **Propiedad cancelativa:** $m\cdot n=m\cdot p\land m\neq0\Rightarrow n=p$.
- **PROPIEDADES RELACIONALES:**
  - **Propiedad distributiva:** $\forall m,n,p\in\mathbb{N},m\cdot(n+p)=m\cdot n+m\cdot p$.
  - $m\leq n\iff\exists p\in\mathbb{N}:m+p=n$ satisface las siguientes propiedades:
    - $\forall m\in\mathbb{N},m\leq m$.
    - $m\leq n\land n\leq m\Rightarrow m=n$.
    - $m\leq n\land n\leq p\Rightarrow m\leq p$.
    - $\forall m,n\in\mathbb{N},m\leq n\lor n\leq m$.
    - $\forall p\in\mathbb{N}, m\leq n\rightarrow m+p\leq n+p$.
    - $m+p\leq n+p\rightarrow m\leq n$.
    - $m\leq n\rightarrow m\cdot p\leq n\cdot p$.
    - $m\cdot p\leq n\cdot p\land p\neq0\Rightarrow m\leq n$.

Aunque todas estas propiedades también son válidas para $\mathbb{Q}^+$, $\mathbb{R}^+$ y otros conjuntos, $\mathbb{N}$ es el único que cumple el **Principio de inducción**.

### 1.1.2 - PRINCIPIO DE INDUCCIÓN

> Sea $A\subset\mathbb{N}$ tal que:
>
> - $0\in A$
>
> - $n\in A\Rightarrow n+i\in A$
>
> Entonces $A = \mathbb{N}$.

Lo que este principio nos dice es que podemos recorrer $\mathbb{N}$ sumando $1$ cada vez sin dejar números por medio, es decir, $\mathbb{N}$ es un conjunto infinito numerable, no como $\mathbb{R}$ u otros.
También podemos deducir que $m<n\Rightarrow m+1\leq n$.

Dados $m,n\in\mathbb{N}$, tenemos definida la potencia $m^n$ excepto cuando $m=n=0$, que satisface las siguientes propiedades:

- $\forall m,n,p\in\mathbb{N}:m\neq0,m^{n+p}=m^n\cdot m^p$.
- $\forall m,n,p\in\mathbb{N}:m\neq0,m^{n^p}=m^{n\cdot p}$.
- $\forall m,n,p\in\mathbb{N}:m\neq0,(m\cdot n)^p=m^p\cdot n^p$.

Del principio de inducción podemos concluir varios teoremas:

#### 1.1.2.1 - Principio de buena ordenación

> Sea $B\subset\mathbb{N}$ y $B\neq\emptyset$, $B$ tiene mínimo.
>
> No existen sucesiones infinitas y estictaamente decrecientes en $\mathbb{N}$.

#### 1.1.2.2 - Algoritmo de la división

> Sean $a,b\in\mathbb{N}$ y $b\neq0$, existen únicos $c,r\in\mathbb{N}$ tales que $a=bc+r$ y $r<b$.

#### 1.1.2.3 - Módulo y división

> Sean $a,b\in\mathbb{N}$, llamamos operación módulo a $a\ m\acute{o}d\ b$ y operación división a $a\ div\ b$.

Estas operaciones satisfacen las siguientes propiedades:

- $a=b\cdot(a\ div\ b)+(a\ m\acute{o}d\ b)$.
- $a\ m\acute{o}d\ b<b$

En otras palabras, $a\ m\acute{o}d\ b$ es el resto de la división y $a\ div\ b$ es el cociente de la misma.

### 1.1.3 - SISTEMAS DE NUMERACIÓN

Al escribir los números naturales utilizamos un **sistema de numeración posicional**.
En este sistema cada número tiene un valor mayor en función de cuán lejos se encuentra del número más a la derecha.
Las unidades valen $1$ cada una, las decenas valen $10$, las centenas valen $100$...
Estos valores equivalen a $10^0$, $10^1$ y $10^2$ respectivamente.
Por tanto, estamos contando en **base decimal**, por ejemplo, $1996=1\cdot10^3+9\cdot10^2+9\cdot10^1+6\cdot10^0$.

#### 1.1.3.1 - Valor de un número en un sistema posicional

> Sean $a,b\in\mathbb{N}\land a\neq0\land b\geq2$, existen únicos $m\in\mathbb{N}$ y $a_0,a_1,\cdots,a_m\in\mathbb{N}$ tales que:
>
> - $a_m\neq0$.
> - $a=\sum_{k=0}^ma_kb^k=a_mb^m+\cdots+a_1b+a_0$.
> - $a_i<b$.

Llamamos $b$ a la **base** en la que está escrita el número $a$ y $a_i$ a cada una de las cifras de $a$.
Cualquier numero $a$ puede expresarse en su base como $a=(a_ma_{m-1}\cdots a_1a_0)_b$.

Utilizamos esta notación de la siguiente forma:

- Podemos añadir tantos ceros a la izquierda de $a_m$ como queramos sin que cambie el valor del número.
  - Lo normal es elegir la representación en la que no haya ceros a la izquierda de $a_{m-1}$.
- Si $a_m\neq0$, $a$ tiene $m+1$ cifras.
- Siempre especificamos la notación en base decimal, pues si lo hiciéramos en base $b$ siempre sería $10$.
  - La base por defecto es $10$, no es necesario especificarla.

Conociendo esta expresión, podemos calcular las cifras de un número en una base distinta a $10$.

\pagebreak

#### 1.1.3.2 - Algoritmo BASE

>Algoritmo BASE(a,b)
>
> - Entrada:
>   - $a,b\in\mathbb{N};a\geq1,b\geq2$.
> - Salida:
>   - $m,a_0,a_1,\cdots,a_m$.
>   - $m\in\mathbb{N}$.
>   - $a_0,a_1,\cdots,a_m\in\mathbb{N}$.
>   - $0\leq a_i\leq b$.
>   - $a_m\neq0$.
>   - $a=a_m\cdot b^m+a_{m-1}\cdot b^{m-1}+\cdots+a_1\cdot b+a_0$.
>   - $m:=0$
>   - Mientras $a\geq b$:
>     - $a_m:=a\ m\acute{o}d\ b$.
>     - $a:=a\ div\ b$.
>     - $m:=m+1$.
>   - $a_m:=a$
>   - Devuelve $m,a_0,a_1.\cdots,a_m$.

Podemos ejecutar el algoritmo en una tabla. Por ejemplo, digamos que $a=446$ y $b=5$.

Primero colocamos los valores iniciales:

+:-----:+:-----:+
|  $b$  |  $5$  |
+-------+-------+
|  $a$  | $446$ |
+-------+-------+
|  $m$  |  $0$  |
+-------+-------+
| $a_m$ |       |
+-------+-------+

Como $446\geq5$, calculamos la primera iteración del bucle:

+:-----:+:-----:+:-----:+
|  $b$  |  $5$  |       |
+-------+-------+-------+
|  $a$  | $446$ |  $89$ |
+-------+-------+-------+
|  $m$  |  $0$  |  $1$  |
+-------+-------+-------+
| $a_m$ |  $1$  |       |
+-------+-------+-------+

Hacemos lo mismo hasta que $a<b$:

+:-----:+:-----:+:-----:+:-----:+:-----:+
|  $b$  |  $5$  |       |       |       |
+-------+-------+-------+-------+-------+
|  $a$  | $446$ |  $89$ |  $87$ |  $3$  |
+-------+-------+-------+-------+-------+
|  $m$  |  $0$  |  $1$  |  $2$  |  $3$  |
+-------+-------+-------+-------+-------+
| $a_m$ |  $1$  |  $4$  |  $2$  |  $3$  |
+-------+-------+-------+-------+-------+

Así demostramos que $446)_{10}=1423_{5}$, ya que $446=3\cdot5^3+2\cdot5^2+4\cdot5^1+1\cdot5^0$.

Este algoritmo sirve para pasar número de una base a otra cualquiera. Sin embargo, es mucho más sencillo pasar primero es número a base decimal y luego utilizar el algoritmo (en lugar de hacer divisiones en base $5$ podemos calcular que $1423)_5=446)_{10}$ y pasar de ahí a otra base.

También existen casos en los que no es necesario utilizar el algoritmo, como para pasar un número binario a un número en base potencia de $2$ o viceversa:

$10101111011000001010100)_2=(57\mathrm{B}054)_{16}$

- Separamos las cifras binarias de derecha a izquierda en grupos de $4$ ($16=2^4$):
  - $101\ 0111\ 1011\ 0000\ 0101\ 0100$ (El grupo más significativo no tiene por que ser de $4$ cifras).
- Calculamos el valor decimal de cada uno de los grupos:
  - $5\ 7\ 11\ 0\ 5\ 4$
- Como estamos calculando en base hexadecimal, tenemos que $\mathrm{A}=10$ hasta $\mathrm{F}=15$. Reconstruimos el número con las nuevas cifras:
  - $57\mathrm{B}054$.

> Todos los algoritmos de suma, resta, multiplicación y división que conocemos en base decimal funcionan en cualquier otra base.

## 1.2 - NÚMEROS ENTEROS

### 1.2.1 - PROPIEDADES DE LOS NÚMEROS ENTEROS

Los números enteros son el conjunto $\mathbb{Z}=\{\cdots,-2,-1,0,1,2,\cdots\}\supset\mathbb{N}$.

Dados dos números naturales $a$ y $b$, podemos llamar a su **suma** $a+b$ y a su **producto**, $a\cdot b$. De esta forma podemos definir dos números naturales nuevos a partir de dos iniciales, satisfaciendo las siguientes propiedades:

- **PROPIEDADES DE LA SUMA:**
  - **Propiedad asociativa:** $\forall a,b,c\in\mathbb{Z},(a+b)+c=a+(b+c)$.
  - **Propiedad conmutativa:** $\forall a,b\in\mathbb{Z},a+b=b+a$.
  - **Elemento neutro:** Es el mismo que en $\mathbb{N}$.
  - **Elemento opuesto:** $\forall a\in\mathbb{Z}\exists-a\in\mathbb{Z}:a+(-a)=0$.
    - La existencia de un elemento opuesto demuestra que la suma en $\mathbb{Z}$ es cancelativa.
    - **Resta en $\mathbb{Z}$:** Dados $a,b\in\mathbb{Z}$ definimos $a-b$ como $a+(-b)$.
- **PROPIEDADES DEL PRODUCTO:**
  - **Propiedad asociativa:** $\forall a,b,c\in\mathbb{Z},(a\cdot b)\cdot c=a\cdot (b\cdot c)$.
  - **Propiedad conmutativa:** $\forall a,b\in\mathbb{Z},a\cdot b=b\cdot a$.
  - **Elemento neutro:** Es el mismo que en $\mathbb{N}$.
  - **Propiedad cancelativa:** $a\cdot b=a\cdot c\land a\neq0\Rightarrow b=c$.
- **PROPIEDADES RELACIONALES:**
  - **Propiedad distributiva:** $\forall a,b,c\in\mathbb{Z},a\cdot(b+c)=a\cdot b+a\cdot c$.
  - $a\leq b\iff b-a\in\mathbb{N}$
    - $\forall a\in\mathbb{Z},a\leq a$.
    - $a\leq b\land b\leq a\Rightarrow a=b$.
    - $a\leq b\land b\leq c\Rightarrow a\leq c$.
    - $\forall a,b\in\mathbb{Z},a\leq b\lor b\leq a$.
    - $\forall c\in\mathbb{Z}, a\leq b\rightarrow a+c\leq b+c$.
    - $a\leq b\land c\geq0\rightarrow a\cdot c\leq b\cdot c$.
    - $a\leq b\land c\leq0\rightarrow b\cdot c\leq a\cdot c$.
    - $a\cdot c\leq b\cdot c\land c>0\Rightarrow a\leq b$.
    - $a\cdot c\leq b\cdot c\land c<0\Rightarrow b\leq a$.

En $\mathbb{Z}$ definimos así la aplicación **valor absoluto** $|\ |:\mathbb{Z}\rightarrow\mathbb{N}$:

> $|a|=\Bigg\{
         \begin{array}{rl}
           a & si\ a\geq0 \\
           -a & si\ a<0
         \end{array}$

Dicha aplicación satisface las siguientes propiedades:

- $|a|=0\iff a=0$.
- $|a\cdot b|=|a|\cdot|b|$.
- $|a+b|\leq|a|+|b|$.
- $|a|\leq b\iff-b\leq a\leq b$.

### 1.2.2 - REPRESENTACIÓN EN COMPLEMENTOS

#### 1.2.2.1 - Resta de enteros en complementos

Interpretando la resta $x-y$ como la suma $x+(-y)$, podemos  utilizar únicamente el algoritmo de la suma para realizar la operación representado $-y$ en complementos.

Cuando representamos un número $a$ en una base $b\geq2$, podemos representarlo en complemento $b$ o a $b-1$. Para ello le restamos cada cifra $a_i$ a $b$ o a $b-1$. De esta forma, si $b=10$, el número $23$ quedaría como $87$ en complemento a $10$ y $76$ en complemento a $9$.

Una propiedad que tiene la representación en complementos es que, al igual que el número de ceros a la izquierda no cambia el valor del número ($123=000123$), el número de nueves a la izquierda no cambia el valor del número en complemento a $9$ ($6343=99996343$), pues $9=9-0$, es decir, la cifra que representa el $9$ al pasar el número a complemento es $0$.

Por último, para operar con números en complemento, es importante que ambos tengan el mismo número de cifras y al menos una de ellas sea un $0$ o un $b$ (en función del complemento) a la izquierda. Por ejemplo, si estamos trabajando en complemento a $9$ y queremos calcular $431-12$, seguimos los siguientes pasos:

- **Cálculo a realizar:** $431-12$
- **Representamos $12$ en complemento a $9$:** $431+87$
- **Añadimos dos $0$ a la izquierda de $431$:** $00431+87$
- **Añadimos tantos $9$ a la izquierda de $87$ como sean necesarios para que ambos números tengan el mismo número de cifras:** $0431+99987$
- **Sumamos:**

\begin{center}
\begin{tabular}{cccccc}
         & $0$ & $0$ & $4$ & $3$ & $1$ \\
     $+$ & $9$ & $9$ & $9$ & $8$ & $7$ \\
     \hline
     $1$ & $0$ & $0$ & $4$ & $1$ & $8$ \\
\end{tabular}
\end{center}

Ahora interpretamos el resultado. Al estar calculando en base $10$ y representando en complemento a $9$, tenemos sumarle $1$ al resultado total y eliminar el acarreo (el $1$ de la izquierda). Así, el resultado pasaría de ser $100418$ a $419$, el resultado de la resta $431-12$.

Aunque podríamos haber añadido un solo $0$ a $431$ obteniendo el mismo resultado, el segundo $0$ nos quita ambigüedad en caso de no saber si los números están en complemento o no. Por ejemplo, ¿trabajamos con números en complemento en $941+937=1878$? ¿Deberíamos interpretar el resultado como $879$? Si añadimos un $9$ a la izquierda, tenemos que $9941+9937=19878$. Interpretando el resultado obtenemos $9879$, que está inequívocamente representado en complemento a $9$.

#### 1.2.2.2 - Definiciones formales de la representación en complementos

> Sea $b\geq2$, $x$ un número entero y $(a_na_{n-1}\cdots a_1a_0)_b$ su representación en base $b$, diremos que $c_n\cdots c_1c_0$ es una representación de $x$ en complemento a $b-1$ si:
>
> - $c_n=0$ y $x=(c_nc_{n-1}\cdots c_1c_0)_b$ cuando $x\geq0$.
> - $c_n=b-1$ y $x=(c_{n-1}\cdots c_1c_0)_b-(b^n-1)$ cuando $x<0$

> Sea $b\geq2$, $x$ un número entero y $(a_na_{n-1}\cdots a_1a_0)_b$ su representación en base $b$, diremos que $c_n\cdots c_1c_0$ es una representación de $x$ en complemento a $b$ si:
>
> - $c_n=0$ y $x=(c_nc_{n-1}\cdots c_1c_0)_b$ cuando $x\geq0$.
> - $c_n=b-1$ y $x=(c_{n-1}\cdots c_1c_0)_b-b^n$ cuando $x<0$

Estas definiciones satisfacen las siguientes propiedades:

- Al representar un numero $x$ en complemento a $b-1$ ó $b$, la cifra de la izquierda nos indica el signo de ese número $x$.
- Podemos añadir tantas veces como queramos la última cifra de la representación, es decir, $c_nc_{n-1}\cdots c_1c_0=c_nc_nc_{n-1}\cdots c_1c_0$.
- Con $n+1$ dígitos podemos representar todos los números entre $-(b^n-1)$ y $b^n-1$ en case de estar representado en complemento a $b-1$ y todos los número entre $-b^n$ y $b^n-1$ en caso de estar representado en complemento a $b$.
- Si $c_nc_{n-1}\cdots c_1c_0$ es la representación en complemento a $b-1$ de $x$, podemos representar $-x$ (su opuesto) en coplemento a $b.-1$ como $d_nd_{n-1}\cdots d_1d_0$, donde $d_i=(b-1)-c_i$, ya sea $x$ positivo o negativo.

## 1.3 - DIVISIBILIDAD

### 1.3.1 - DEFINICIONES BÁSICAS

> Sean $a,b\in\mathbb{Z}$ con $b\neq0$, existen únicos $c,r\in\mathbb{Z}$ tales que $a=bc+r$ y $0\leq r\leq|b|$.

> Sean $a,b\in\mathbb{Z}$ con $b\neq0$, definimos los números resto a $a\ m\acute{o}d\ b$ y cociente a $a\ div\ b$. Estos números son los únicos que cumplen las siguientes condiciones:
>
> - $a=b\cdot(a\ div\ b)+(a\ m\acute{o}d\ b)$.
> - $0\leq a\ m\acute{o}d\ b<|b|$.

> Dados $a,b\in\mathbb{Z}$, decimos que $a$ divide a $b$ o que $b$ es múltiplo de $a$, y escribiremos $a|b$ si existe $c\in\mathbb{Z}$ tal que $b=ac$. Esta definición satisface las siguientes propiedades:
>
> - $\forall a\in\mathbb{Z},1|a\land a|0$.
> - $\forall a\in\mathbb{Z},a|a$.
> - $a|b\land b|a\Rightarrow a=\pm b$.
> - $a|b\land b|c\Rightarrow a|c$.
> - $a|b\land a|c\Rightarrow a|(b+c)$.
> - $a|b\Rightarrow \forall c\in\mathbb{Z},a|bc$.
> - $a|b\iff b\ m\acute{o}d\ a=0$ (sólo tiene sentido si $a\neq0$).
> - Si $a|b$ y $a\neq0$, existe un único $c$ tal que $b=ac$ y lo representamos como $\frac{b}{a}$.

> Sean $a,b\in\mathbb{Z}$, $d$ es su máximo común divisor ($mcd$) si se satisfacen dos condiciones:
>
> - $d|a\land d|b$.
> - $c|a\land c|b\Rightarrow c|d$.
>
> Este número satisface las siguientes propiedades:
>
> - $mcd(a,b)=mcd(a,-b)=mcd(-a,b)=mcd(-a,-b)=mcd(|a|,|b|)$.
> - $mcd(a,0)=|a|$.
> - $mcd(a,1)=1$.
> - $a|b\Rightarrow mcd(a,b)=|a|$.
> - $mcd(a,mcd(b,c))=mcd(mcd(a,b),c)=mcd(a,b,c)$.
> - $mcd(ac,bc)=mcd(a,b)\cdot|c|$.
> - $d|a\land d|b\Rightarrow mcd(\frac{a}{d},\frac{b}{d})=\frac{mcd(a,b)}{|d|}$.

> Sean $a,b\in\mathbb{Z}$, $m$ es su mínimo común múltiplo ($mcm$) si se satisfacen dos condiciones:
>
> - $a|m\land b|b$.
> - $a|n\land b|n\Rightarrow m|n$.

## 1.4 - NÚMEROS PRIMOS

## 1.5 - CLASES RESIDUALES MÓDULO $m$

## 1.6 - SISTEMAS DE CONGRUENCIAS

## 1.7 - ECUACIONES DIOFÁNTICAS
