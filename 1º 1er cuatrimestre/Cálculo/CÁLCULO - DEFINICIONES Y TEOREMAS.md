# CÁLCULO - DEFINICIONES Y TEOREMAS

Estos apuntes contienen simplemente las definiciones y teoremas básicos de la asignatura. No están demostrados más allá de lo estrictamente necesario.

# 1 - EL CONJUNTO DE LOS NÚMEROS REALES

## 1.1 - VALOR ABSOLUTO

Se define el valor absoluto de un número real *x* como:
```
|x| = { x,   si x ≥ 0
      { -x,  si x < 0
```

### Desigualdad triangular

- |*x* + *y*| ≤ |*x*| + |*y*|
- ||*x*|-|*y*|| ≤ |*x* - *y*|
- **No se cumple en el producto:** |*xy*| = |*x*||*y*|

## 1.2 - PRINCIPIO DE INDUCCIÓN

Un subconjunto *A* ∈ ℝ es inductivo si verifica dos propiedades:
- 1 ∈ *A*
- *a* ∈ *A* ⇒ *a* + 1 ∈ *A*

###### El conjunto de los números reales es el menor conjunto inductivo (la intersección de todos los conjuntos inductivos).

## 1.3 - ACOTACIÓN

#### *A* ⊂ ℝ

- *M* ∈ ℝ es una **cota superior o mayorante** de *A* ⇔ *a* ≤ *M*, ∀*a* ∈ *A*.
  - *A* está **acotado superiormente o mayorado** si tiene una cota superior.
  - *A<sub>0</sub>* ∈ *A* es el **máximo absoluto *max*(*A*)** de *A* ⇔ *a* ≤ *a<sub>0</sub>*, ∀*a* ∈ *A*.
  - El **supremo *sup*(*A*)** de *A* es el mínimo del conjunto de sus cotas superiores.
- *M* ∈ ℝ es una **cota inferior o minorante** de *A* ⇔ *a* ≥ *M*, ∀*a* ∈ *A*.
  - *A* está **acotado inferiormente o minorado** si tiene una cota inferior.
  - *A<sub>0</sub>* ∈ *A* es el **mínimo absoluto *min*(*A*)** de *A* ⇔ *a* ≥ *a<sub>0</sub>*, ∀*a* ∈ *A*.
  - El **ínfimo *inf*(*A*)** de *A* es el máximo del conjunto de sus cotas inferiores.
- *A* está **acotado** si está mayorado y minorado.

```
TODO CONJUNTO ACOTADO SUPERIORMENTE TIENE SUPREMO.
TODO CONJUNTO ACOTADO INFERIORMENTE TIENE ÍNFIMO.
```

#### *A* ⊂ ℝ acotado superiormente, *sup*(*A*) = *x* ∈ ℝ (resp. *inf*(*a*))

- *x* ∉ *A* ⇒ *A* **no tiene máximo.**
- *x* ∈ *A* ⇒ *A* **tiene máximo** ∴ *max(A) = x*.
- *a* ≤ *x*, ∀*a* ∈ *A*.
- Dado *ɛ* > *0*, ∃*a* ∈ *A* : *x* - *ɛ* < *a*.

## 1.4 - INTERVALOS

*I* ⊆ ℝ es un intervalo ⇔ [*x*,*y*] = {*t* ∈ ℝ : *x* ≤ *t* ≤ *y*} ⊆ *I*, ∀*x*,*y* ∈ *I*

#### *A* ⊆ ℝ
- *a* ∈ *A* es un **punto interior** ⇦ ∃*ɛ* > 0 : ]*a*-*ɛ*,*a*+*ɛ*[ ⊂ *I*
- El **interior de *A*** es el conjunto **Å** = {*a* ∈ *A* : *a* es un punto interior}`
  - *A* es **abierto** si coincide con su interior.
- *x* ∈ ℝ es un **punto adherente** ⇦ ]*a*-*ɛ*,*a*+*ɛ*[ ∩ *A* ≠ 0, ∀*ɛ* > 0
- El **cierre o adherencia** del conjunto *A* es **Ā** = {*x* ∈ ℝ : *x* es un punto adherente de A}
  - *A* es **cerrado** si coincide con su adherencia.
- *x* ∈ ℝ es un **punto de acumulación** de *A* ⇦ ]*a*-*r*,*a*+*r*[ ∩ (*A* \ {*a*}) *A* ≠ 0, ∀*r* > 0
  - **A’** es el **conjunto de puntos de acumulación** de *A*.
- *x* ∈ ℝ es un **punto aislado** de *A* ⇦ ∃*r* : ]*a*-*r*,*a*+*r*[ ∩ *A* = {*a*}
- La **frontera** de *A* es **Fr(A)** = *Ā* \ *Å*
- *Å* ⊂ *A* ⊂ *Ā*
- *A* es abierto ⇔ ℝ \ *A* es cerrado

# 2 - FUNCIONES ELEMENTALES

## 2.1 - DOMINIO, RANGO E IMAGEN

Una función *f* : *A* → *B* representa una regla mediante la cual se asocia un único elemento *b* de *B* a cada elemento *a* de *A*.
- Su **dominio** es el conjunto *A*.
- Su **codominio** es el conjunto *B*.
- La **imagen** de la función es el conjunto de elementos de *A* que se asocian a *B*.
  - *f*(*A*) = {*b* ∈ *B* : ∃*a* ∈ *A* : f(*a*) = *b*}
- La **preimagen** de un elemento *b* de *B* son los elementos de *A* cuya imagen es *B*.
  - *f*<sup>-1</sup>(*b*) = {*a* ∈ *A* : f(*a*) = *b*}
- La **gráfica** de una función es el conjunto de puntos que devuelve la función.
  - Gr(*f*) = {(*a*,*b*) ∈ *A* × *B* : f(*a*) = *b*}

## 2.2 - FUNCIONES INYECTIVAS, SOBREYECTIVAS Y BIYECTIVAS

- Una función es **inyectiva** si no hay dos elementos distintos con la misma imagen.
  - *x* ≠ *y* ⇒ f(*x*) ≠ f(*y*)
- Una función es **sobreyectiva** si todo elemento tiene una preimagen.
  - ∃*a* ∈ *A* : f(*a*) = *b* ∀*b* ∈ *b*
- Una función es **biyectiva** si es inyectiva y sobreyectiva
  - Cada elemento de *A* se relaciona con un solo elemento de *B*.
- Una función **puede no pertenecer a ninguna de las tres categorías anteriores**, pero sí un intervalo de ella.
  - *f* : ℝ → ℝ definida como *f*(*x*) = *x*<sup>2</sup> no es inyectiva ni sobreyectiva.
  - *f* : ℝ → ℝ<sub>0</sub><sup>+</sup>, la función pasa a ser sobreyectiva, pero no inyectiva.
  - *f* : ℝ<sup>+</sup> → ℝ ó *f* : ℝ<sup>-</sup> → ℝ, la hacen inyectiva.
  - *f* : ℝ<sup>+</sup> → ℝ<sub>*0*</sub><sup>+</sup> ó *f* : ℝ<sup>-</sup> → ℝ<sub>*0*</sub><sup>+</sup> la hacen biyectiva.

## 2.3 - FUNCIÓN INVERSA

La inversa de *f* : *A* → *B*, denotada como *f*<sup>⁻¹</sup>, es la función que toma *f(a)* y devuelve *a*.
- *f*<sup>⁻¹</sup> : *f*(*A*) → *A* definida por *f*<sup>⁻¹</sup>(*f*(*a*)) = *a*
- Para que esto se cumpla, *f* : *A* → *B* **debe ser inyectiva**.
- En caso de ser **sobreyectiva** obtendremos varias inversas, una para cada uno de los casos en los que pueda ser inyectiva:

## 2.4 - FUNCIONES PARES E IMPARES

- Una función es **par** ⇔ *f*(*a*) = *f*(-*a*), ∀*a* ∈ *A*
  - Las funciones pares son simétricas respecto al eje *OY*.
- Una función es **impar** ⇔ *f*(*a*) = -*f*(-*a*), ∀*a* ∈ *A*
  - Las funciones impares son simétricas, pero su eje de simetría no es igual para todas.

## 2.5 - FUNCIONES PERIÓDICAS

*f* ℝ → ℝ es periódica ⇔ ∃*T* ∈ ℝ : *f*(*x*) = *f*(*x*+*T*), ∀*x* ∈ ℝ.
- Llamamos **periodo** de la función a cualquier valor de *f*(*x*+*T*).
- El **periodo fundamental (*ω*)** es el menor de todos los periodos.
  - *ω* = *inf*{*T* : *f*(*x*) = *f*(*x*+*T*), ∀*x* ∈ ℝ}

## 2.6 - FUNCIONES ACOTADAS

#### *f* : *A* → ℝ
- Está **acotada superiormente** ⇔ ∃*M* : *f*(*a*) ≤ *M*, ∀*a* ∈ *A*
  - *f*(*A*) también está acotada superiomente.
- Está **acotada inferiormente** ⇔ ∃*M* : *f*(*a*) ≥ *M*, ∀*a* ∈ *A*
  - *f*(*A*) también está acotada inferiormente.
- Está **acotada** si lo está superior e inferiormente.
- Tiene **máximo** si *f*(*A*) lo tiene.
  - Lo alcanza en *a*<sub>0</sub> ∈ *A* ⇔ *f*(*a*) ≤ *f*(*a*<sub>0</sub>), ∀*a* ∈ *A*.
- Tiene **mínimo** si *f*(*A*) lo tiene.
  - Lo alcanza en *a*<sub>0</sub> ∈ *A* ⇔ *f*(*a*) ≥ *f*(*a*<sub>0</sub>), ∀*a* ∈ *A*.
- Aún teniendo **supremo y/o ínfimo**, puede no alcanzar su máximo y/o mínimo.
  - *f* : ]0,1[ →]0,1[ definida como *f*(*x*)

## 2.7 - FUNCIONES MONÓTONAS

#### *f* : *A* ⊆ ℝ → ℝ
- Es **monótona** si es creciente o decreciente.
  - Es **creciente** ⇔ *x* ≤ *y* ⇒ *f*(*x*) ≤ *f*(*y*)
  - Es **decreciente** ⇔ *x* ≥ *y* ⇒ *f*(*x*) ≥ *f*(*y*)
- Es **estrictamente monótona** si es creciente o decreciente.
  - Es **estrictamente creciente** ⇔ *x* < *y* ⇒ *f*(*x*) < *f*(*y*)
  - Es **estrictamente decreciente** ⇔ *x* > *y* ⇒ *f*(*x*) > *f*(*y*)

Diremos que una función es creciente si el valor de su imagen no baja en ningún momento, por lo que diremos también que las funciones constantes son crecientes.

Las funciones estrictamente monótonas siempre son inyectivas, pero el recíproco no siempre es cierto.

# 3 - LÍMITES Y CONTINUIDAD

## 3.1 - DEFINICIÓN Y PROPIEDADES DE LÍMITES

#### *f,g* : *A* ⊆ ℝ → ℝ
*f* tiene límite en *x*<sub>0</sub> ∈ *A'* y vale *L* si para cualquier sucesión {*x<sub>n</sub>*} de elementos de *A* distintos de *x*<sub>0</sub> que tienda a *x*<sub>0</sub> se cumple que *f*{*x<sub>n</sub>*} tiende a *L*.
- Lo escribiremos como **lim *x*→*x*<sub>0</sub> *f*(*x*) = *L***
- ∃*δ* > 0 : 0 < |*x*-*x*<sub>0</sub>| < *δ* ∧ *x* ∈ *A* ⇒ |*f*(*x*) - *L*| < *ɛ*, ∀*ɛ* > 0.
- lim *x*→*x*<sub>0</sub> (*f*+*g*)(*x*) = lim *x*→*x*<sub>0</sub> *f*(*x*) + lim *x*→*x*<sub>0</sub> *g*(*x*)
- lim *x*→*x*<sub>0</sub> (*fg*)(*x*) = **(**lim *x*→*x*<sub>0</sub> *f*(*x*)**)(**lim *x*→*x*<sub>0</sub> *g*(*x*)**)**
  - lim *x*→*x*<sub>0</sub> *f*(*x*) = 0 ∧ *g* está acotada ⇒ lim *x*→*x*<sub>0</sub> (*fg*)(*x*) = 0
- lim *x*→*x*<sub>0</sub> ∧ *g*(*x*) ≠ 0 ⇒ lim *x*→*x*<sub>0</sub> (*f*/*g*)(*x*) = lim *x*→*x*<sub>0</sub> *f*(*x*) **/** lim *x*→*x*<sub>0</sub> *g*(*x*)

## 3.2 - LÍMITES LATERALES

#### *f* : *A* ⊆ ℝ → ℝ ∧ *x*<sub>0</sub> ∈ *A*'
- *x*<sub>0</sub> ∈ (*A*<sup>-</sup>)' = {*x* ∈ *A* : *x* < *x*<sub>0</sub>} ⇒ definimos el **límite por la izquierda** de *f* en *x*<sub>0</sub> como lim *x*→*x*<sub>0</sub><sup>-</sup> *f*(*x*)
- *x*<sub>0</sub> ∈ (*A*<sup>+</sup>)' = {*x* ∈ *A* : *x* > *x*<sub>0</sub>} ⇒ definimos el **límite por la derecha** de *f* en *x*<sub>0</sub> como lim *x*→*x*<sub>0</sub><sup>+</sup> *f*(*x*)
- *x*<sub>0</sub> ∈ (*A*<sup>-</sup>)' ∧ *x*<sub>0</sub> ∉ (*A*<sup>+</sup>)' ⇒ ∃lim *x*→*x*<sub>0</sub> *f*(*x*) = *L* ⇔ ∃lim *x*→*x*<sub>0</sub><sup>-</sup> *f*(*x*) = *L*
- *x*<sub>0</sub> ∈ (*A*<sup>+</sup>)' ∧ *x*<sub>0</sub> ∉ (*A*<sup>-</sup>)' ⇒ ∃lim *x*→*x*<sub>0</sub> *f*(*x*) = *L* ⇔ ∃lim *x*→*x*<sub>0</sub><sup>+</sup> *f*(*x*) = *L*
- *x*<sub>0</sub> ∈ (*A*<sup>-</sup>)' ∩ (*A*<sup>+</sup>)' ⇒ ∃lim *x*→*x*<sub>0</sub> *f*(*x*) = *L* ⇔ ∃lim *x*→*x*<sub>0</sub><sup>-</sup> *f*(*x*) = lim *x*→*x*<sub>0</sub><sup>+</sup> *f*(*x*) = *L*

## 3.3 - LÍMITES INFINITOS Y EN EL INFINITO

#### *f* : *A* ⊆ ℝ → ℝ ∧ *x*<sub>0</sub> ∈ *A*'
- lim *x*→*x*<sub>0</sub><sup>-</sup> *f*(*x*) = ∞ ⇔ [∀{*x<sub>n</sub>*} →*x*<sub>0</sub> ⇒ {*f*(*x<sub>n</sub>*)} → ∞]
- **Asíntota vertical en *x*<sub>0</sub>:** ∃*δ* > 0 : 0 < |*x*-*x*<sub>0</sub>| < *δ* ∧ *x* ∈ *A* ⇒ *f*(*x*) > *M*, ∀*M* ∈ ℝ