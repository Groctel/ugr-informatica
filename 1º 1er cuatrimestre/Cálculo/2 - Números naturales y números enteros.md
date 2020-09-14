# TEMA 2 - NÚMEROS NATURALES Y NÚMEROS ENTEROS

A lo largo de este tema suponemos conocido el conjunto de los números naturales $\mathbb{N}=\{0,1,2,3,\cdots\}$, que satisface los [axiomas de Peano](). También suponemos conocidos los números enteros $\mathbb{Z}$, los números racionales $\mathbb{Q}$, los números reales $\mathbb{R}$ y los números complejos $\mathbb{C}$. Todos estos conjuntos, salvo $\mathbb{C}$, satisfacen una estructura algebraica y de orden.

## 2.1 - NÚMEROS NATURALES

### 2.1.1 PROPIEDADES DE LOS NÚMEROS NATURALES

Dados dos números naturales $m$ y $n$, podemos llamar a su **suma** $m+n$ y a su **producto**, $m\cdot n$. De esta forma podemos definir dos números naturales nuevos a partir de dos iniciales, satisfaciendo las siguientes propiedades:

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

### 2.1.2 - PRINCIPIO DE INDUCCIÓN

> Sea $A\subset\mathbb{N}$ tal que:
>
> - $0\in A$
>
> - $n\in A\Rightarrow n+i\in A$
>
> Entonces $A = \mathbb{N}$.

Lo que este principio nos dice es que podemos recorrer $\mathbb{N}$ sumando $1$ cada vez sin dejar números por medio, es decir, $\mathbb{N}$ es un conjunto infinito numerable, no como $\mathbb{R}$ u otros. También podemos deducir que $m<n\Rightarrow m+1\leq n$.

Dados $m,n\in\mathbb{N}$, tenemos definida la potencia $m^n$ excepto cuando $m=n=0$, que satisface las siguientes propiedades:

- $\forall m,n,p\in\mathbb{N}:m\neq0,m^{n+p}=m^n\cdot m^p$.
- $\forall m,n,p\in\mathbb{N}:m\neq0,m^{n^p}=m^{n\cdot p}$.
- $\forall m,n,p\in\mathbb{N}:m\neq0,(m\cdot n)^p=m^p\cdot n^p$.

Del principio de inducción podemos concluir varios teoremas:

#### 2.1.2.1 - Principio de buena ordenación

> Sea $B\subset\mathbb{N}$ y $B\neq\emptyset$, $B$ tiene mínimo.
>
> No existen sucesiones infinitas y estictaamente decrecientes en $\mathbb{N}$.

#### 2.1.2.2 - Algoritmo de la división

> Sean $a,b\in\mathbb{N}$ y $b\neq0$, existen únicos $c,r\in\mathbb{N}$ tales que $a=bc+r$ y $r<b$.

#### 2.1.2.3 - Módulo y división

> Sean $a,b\in\mathbb{N}$, llamamos operación módulo a $a\ m\acute{o}d\ b$ y operación división a $a\ div\ b$.

Estas operaciones satisfacen las siguientes propiedades:

- $a=b\cdot(a\ div\ b)+(a\ m\acute{o}d\ b)$.
- $a\ m\acute{o}d\ b<b$

En otras palabras, $a\ m\acute{o}d\ b$ es el resto de la división y $a\ div\ b$ es el cociente de la misma.

### 2.1.3 - SISTEMAS DE NUMERACIÓN

Al escribir los números naturales utilizamos un **sistema de numeración posicional**. En este sistema cada número tiene un valor mayor en función de cuán lejos se encuentra del número más a la derecha. Las unidades valen $1$ cada una, las decenas valen $10$, las centenas valen $100$... Estos valores equivalen a $10^0$, $10^1$ y $10^2$ respectivamente. Por tanto, estamos contando en **base decimal**, por ejemplo, $1996=1\cdot10^3+9\cdot10^2+9\cdot10^1+6\cdot10^0$.

#### 2.1.3.1 - Valor de un número en un sistema posicional

> Sean $a,b\in\mathbb{N}\land a\neq0\land b\geq2$, existen únicos $m\in\mathbb{N}$ y $a_0,a_1,\cdots,a_m\in\mathbb{N}$ tales que:
>
> - $a_m\neq0$.
> - $a=\sum_{k=0}^ma_kb^k=a_mb^m+\cdots+a_1b+a_0$.
> - $a_i<b$.

Llamamo $b$ a la **base** en la que está escrita el número $a$ y $a_i$ a cada una de las cifras de $a$. Cualquier numero $a$ puede expresarse en su base como $a=(a_ma_{m-1}\cdots a_1a_0)_b$.

Utilizamos esta notación de la siguiente forma:

- Podemos añadir tantos ceros a la izquierda de $a_m$ como queramos sin que cambie el valor del número.
  - Lo normal es elegir la representación en la que no haya ceros a la izquierda de $a_{m-1}$.
- Si $a_m\neq0$, $a$ tiene $m+1$ cifras.
- Siempre especificamos la notación en base decimal, pues si lo hiciéramos en base $b$ siempre sería $10$.
  - La base por defecto es $10$, no es necesario especificarla.

Conociendo esta expresión, podemos calcular las cifras de un número en una base distinta a $10$.

\pagebreak

#### 2.1.3.2 - Algoritmo BASE

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

## 2.2 - NÚMEROS ENTEROS

### 2.2.1 - PROPIEDADES DE LOS NÚMEROS ENTEROS

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

### 2.2.2 - REPRESENTACIÓN EN COMPLEMENTOS

## 2.3 - DIVISIBILIDAD

## 2.4 - NÚMEROS PRIMOS

## 2.5 - CLASES RESIDUALES MÓDULO $m$

## 2.6 - SISTEMAS DE CONGRUENCIAS

## 2.7 - ECUACIONES DIOFÁNTICAS
