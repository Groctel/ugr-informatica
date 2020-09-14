# TEMA 4 - COMBINATORIA

A lo largo de este tema trabajaremos con el cardinal $|A|$ de un conjunto $A$ y con el concepto de que dos conjuntos $A$ y $B$ son biyectivos si tienen el mismo cardinal.

## 4.1 - MÉTODOS ELEMENTALES DE CONTEO

### 4.1.1 - PRINCIPIO DE INCLUSIÓN-EXCLUSIÓN

#### 4.1.1.1 - Principio de la suma

> Sean $A_1$ y $A_2$ dos conjuntos disjuntos o ($A_1\cap A_2=\emptyset$), $|A_1\cup A_2|=|A_1|+|A_2|$.

Este principio puede extenderse a un número infinito de conjuntos disjuntos de dos a dos, es decir, si tenemos los conjuntos $A_1,A_2,\cdots,A_n$, $A_i\cup A_j=\emptyset$ si $i\neq j$.

#### 4.1.1.2 - Suma general de conjuntos

> Sean $A_1$ y $A_2$ dos conjuntos, entonces $|A_1\cup A_2|=|A_1|+|A_2|-|A_1\cup A_2|$.

Este principio nos sirve tanto para conjuntos disjuntos como aquellos que no lo son, pues lo que nos dice es que debemos contar el número de elementos de ambos y restar los que se repiten ($0$ en el caso de los disjuntos).

#### 4.1.1.3 - Principio de inclusión-exclusión

> Sean $A_1,A_2,\cdots,A_n$ conjuntos:
>
> $|A_1\cup A_2\cup\cdots\cup A_n|=\sum_{k=1}^{n}(-1)^{k+1}\cdot\sum_{1\leq i_1<\cdots < i_k\leq n}|A_{i_1}\cap\cdots\cap A_{i_k}|$

Visto más mecánicamente, lo que debemos hacer es, conocido el cardinal de la unión de todos los conjuntos, ir restando los elementos que se repiten al comparar de dos en dos todos los conjuntos, luego sumarle los que se repiten al comparar de tres en tres (ya que los habíamos eliminado al comparar de dos en dos), restarle la intersección de cuatro en cuatro y así hasta llegar al número de conjuntos que estamos contando.

\begin{center}
\begin{tikzpicture}[fill=gray]
% left hand
\scope
\clip (-1,-1) rectangle (2,1)
      (1,0) circle (1);
\fill (0,0) circle (1);
\endscope
% right hand
\scope
\clip (-1,-1) rectangle (2,1)
      (0,0) circle (1);
\fill (1,0) circle (1);
\endscope
% outline
\draw (0,0) circle (1)
      (1,0) circle (1);
\end{tikzpicture}
\end{center}

### 4.1.2 - PRINCIPIO DEL PRODUCTO

### 4.1.3 - PRINCIPIO DEL PALOMAR

> Si queremos repartir $n$ objetos en $m$ cajas y $n>m$, al menos una caja ha de contener $2$ o más objetos.
>
> Si $n>m$ no existen aplicaciones inyectivas de un conjunto de cardinal $n$ en un conjunto de cardinal $m$.

#### 4.1.3.1 - Principio del palomar generalizado

> Si queremos repartir $n$ objetos en $m$ cajas, al menos una caja ha de contener al menos $n/m$ elementos.

Si $n/m$ no fuese entero, tomamos el número enterio inmediatamente superior.

## 4.2 - COMBINACIONES

Llamamos combinaciones al proceso de extraer $m$ elementos de un conjunto de cardinal $n$ sin que importe el orden de extracción, lo representamos como ${n\choose m}$ y decimos que estamos **extrayendo $\boldmath{n}$ elementos tomados de $\boldmath{m}$ en $\boldmath{m}$**. Un ejemplo claro sería ordenar las habitaciones de hotel de un viaje de fin de curso, pues que Andrés y Berto duerman en la misma habitación tiene el mismo resultado que si lo hicieran Berto y Andrés. Podemos expresar este resultado como el conjunto $\{Andrés,\ Berto\}$.

> Sean $m,n\in\mathbb{N}$ y $m\leq n$, entonces:
>
> \Large${n\choose m}=\frac{n!}{m!(n-m)!}$\normalsize

### 4.2.1 - TRIÁNGULO DE PASCAL
