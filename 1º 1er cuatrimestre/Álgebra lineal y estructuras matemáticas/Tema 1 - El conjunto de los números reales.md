# EL CONJUNTO DE LOS NÚMEROS REALES

###### Estos apuntes utilizan lenguaje matemático en todos los casos en los que sea aplicable. Consulta [la lista de símbolos matemáticos de Wikipedia](https://en.wikipedia.org/wiki/List_of_mathematical_symbols) si encuentras alguno que desconozcas.

## 0 - INTRODUCCIÓN

Existen dos formas de definir los números reales: [axiomática o constructivamente](https://en.wikipedia.org/wiki/Real_number#Definition). Por motivos de simplificación, estos apuntes asumen que el estudiante conoce el concepto de [número real](https://en.wikipedia.org/wiki/Real_number) y se parte desde la definición axiomática del conjunto.

## 1 - ℝ, EL CONJUNTO DE LOS NÚMEROS REALES

Definimos ℝ en función de las operaciones que se pueden realizar en él y sus propiedades, ya que es más sencillo definir qué se puede hacer con los números de ℝ que definir qué son. Podemos realizar dos operaciones en ℝ:

### 1.1 - SUMA DE NÚMEROS REALES

Verificamos la suma en ℝ mediante las siguientes cuatro propiedades:

    a, b, c ∈ ℝ

- **Propiedad conmutativa:** `a + b = b + a`
- **Propiedad asociativa:** `a + (b + c) = (a + b) + c`
- **Existencia de elemento neutro:** `a + 0 = a`
- **Existencia de elemento opuesto:** `a + (-a) = 0`

A partir de la cuarta propiedad podemos definir la **resta de números reales**, que no es más que la suma del elemento opuesto.

Podemos resumir estas propiedades diciendo que (ℝ, +) es un [*grupo abeliano* o *conmutativo*](https://es.wikipedia.org/wiki/Grupo_abeliano).

### 1.2 - PRODUCTO DE NÚMEROS REALES

Verificamos el producto en ℝ mediante cuatro propiedades:

    a, b, c ∈ ℝ

- **Propiedad conmutativa:** `ab = ba`
- **Propiedad asociativa:** `a(bc) = (ab)c`
- **Existencia de elemento neutro:** `1a = a`
- **Existencia de elemento inverso:** `a(1/a) = 1, ∀a ≠ 0`

A partir de la cuarta propiedad conocemos la **división de números reales**. Es importante tener en cuenta que no estamos hablando de cómo se dividen, sino de que la división es la operación inversa a la multiplicacion. Es decir, si en la suma el *opuesto* de `a` es `-a`, en la multiplicación el *inverso* de `a` es `1/a`, que también podremos denotarlo como `a^-1`.

### 1.3 - SIMPLIFICACIÓN DE LAS OPERACIONES

A la hora de restar y dividir utilizaremos las dos siguientes simplificaciones::

    a + (-b) = a - b
    b(1/a) = b/a

### 1.4 - ORDEN DE NÚMEROS REALES

El orden es una propiedad que nos permite averiguar la jerarquía de valores entre varios números. Vamos a definir sus propiedades sobre `≤`, aunque `<`, `>` y `≥` nos darían propiedades análogas.

    a, b, c ∈ ℝ

- **Propiedad reflexiva:** `a ≤ a`
- **Propiedad antisimétrica:** `a ≤ b ∧ b ≤ a ⇒ a = b`
- **Propiedad transitiva:** `a ≤ b ∧ b ≤ c ⇒ a ≤ c`
- **El orden es total:** `a ≤ b ∨ b ≤ a ∀a,b ∈ ℝ`

### 1.5 - RELACIÓN ENTRE SUMA, PRODUCTO Y ORDEN EN ℝ

Definidos la suma y el producto, encontramos una propiedad que los relaciona:
- **Propiedad distributiva:** `a(b + c) = ab + ac`

Definido también el orden, encontramos dos propiedades que relacionan a los tres:
- **Persistencia del orden tras la suma:** `a ≤ b ⇒ a + c ≤ b + c`
- **Persistencia del orden tras el producto:** `a ≤ b ⇒ ac ≤ bc ∀c ≥ 0`

### 1.6 - EL ÚLTIMO AXIOMA

Las propiedades definidas hasta ahora no delimitan el conjunto de los números reales, ya que se pueden verificar otros conjuntos, como ℚ, mediante ellas. Por tanto, es necesaria una propiedad que se cumpla únicamente en ℝ.

![img](https://drive.google.com/uc?export=view&id=18mTPIg5OXrYIbowrWUcmQLWbl9UT4WXs)

Si definimos dos conjuntos `A,B : a ≤ b ∀a ∈ A, ∀b ∈ B`, podemos encontrar un valor `x` que se encuentre entre ambos conjuntos. Esta propiedad sigue sin ser únicamente aplicable a ℝ ya que entre los conjuntos `A = {a : a < -1}` y `B = {b : b > 1}` podemos encontrar números que pertenecen a ℕ (`0`) o a ℚ (`1/2`). Sin embargo, podemos juntar los extremos de ambos conjuntos y encontrar una propiedad únicamente válida en ℝ.

![img](https://drive.google.com/uc?export=view&id=1skKcYiaJKqBrGnULICLhHCwDOJq_lyuC)

Esta propiedad se cumple tanto en todos los conjuntos numéricos englobados en ℝ. De hecho, la figura muestra como elemento intermedio `π`, que es un número irracional. Por tanto, mediante este último axioma podemos definir todo el conjunto de los números reales.

| AXIOMA DEL ELEMENTO INTERMEDIO |
| :---: |
| `a ≤ b ∀a ∈ A, ∀b ∈ B ⇒ ∃ x : a ≤ x ≤ b ∀a ∈ A, ∀b ∈ B` |

## 2 - NATURALES, ENTEROS, RACIONALES E IRRACIONALES

Aunque se hayan mencionado anteriormente, estas son las definiciones de los cuatro conjuntos englobados en ℝ:

### 2.1 - ℕ, EL CONJUNTO DE LOS NÚMEROS NATURALES

    ℕ = {1, 2, 3, 4, 5, ...}

No incluímos `0` en ℕ por simplificación (aunque en álgebra sí se incluye, cuidado), ya que así podemos evitar estar añadiendo constantemente `∀n ≠ 0` al hablar de operaciones como `log(n)` o `1/n` en ℕ.

### 2.2 - ℤ, EL CONJUNTO DE LOS NÚMEROS ENTEROS

    ℤ = {... ,-3, -2, -1, 0, 1, 2, 3,...}

La operación de la suma en ℤ es una operación interna. Esto quiere decir que `a,b ∈ ℤ ⇒ a + b ∈ ℤ`. No ocurre lo mismo con la multiplicación, ya que el inverso de un entero pertenece a ℚ.

### 2.3 - ℚ, EL CONJUNTO DE LOS NÚMEROS RACIONALES

    ℚ = {p/q : p ∈ ℤ, q ∈ ℕ}

Podemos intercambiar las pertenencias y decir que `p ∈ ℕ, q ∈ ℤ` y el resultado sería el mismo. Esta relación de pertenencia es necesaria en caso de que `p/q ≤ 0`, ya que `0 ∉ ℕ` y sólo podemos expresar valores negativos en ℤ. Como un número racional `(-p)/q = (-1)(p/q)` y ambos son menores que `0`, decimos que `p ∈ ℤ, q ∈ ℕ` para simplificar la forma de expresarlo, ya que así colocamos el símbolo `-` en el numerador o delante de la fracción.

Los números racionales pueden tener un número finito o infinito periódico de decimales.

### 2.4 - ℝ\ℚ, EL CONJUNTO DE LOS NÚMEROS IRRACIONALES

El conjunto de los irracionales está compuesto por todos los números que tienen un número infinito no periódico de decimales.

ℝ\ℚ no es un espacio vectorial, como ocurre con otros conjuntos, ya que el elemento neutro de la suma o el producto (`0` y `1` respectivamente) no pertenecen a él. También se da el caso de que la suma o el producto de números irracionales no sea irracional:

    2π/π = 2

### 2.5 - NÚMEROS ALGEBRÁICOS Y TRASCENDENTES

Decimos que un número es **algebráico** si es solución (o raíz) de un polinomio con coeficientes enteros.

    x² - 2 = 0 ⇔ x² 

## 3 - VALOR ABSOLUTO

## 4 - EL PRINCIPIO DE INDUCCIÓN

## 5 - CONJUNTOS DESTACADOS

## 6 - DEMOSTRACIONES NO FUNDAMENTALES

### 6.? - √2 ∈ ℝ\ℚ

Las únicas posibles raíces racionales del polinomio x 2 2 = 0 son ±1, ±2. Cómo
p
ninguna de ellas es solución del polinomio,
2 no puede ser un número racional.
p
La otra demostración usual de que 2 no es un número racional p utiliza la descomposición en
primos de un número y la reducción al p absurdo: supongamos que 2 fuera racional. Eso quiere
decir que podría escribirse de la forma 2 = q p , donde q p es una fracción irreducible. Si elevamos
al cuadrado obtenemos que 2q 2 = p 2 y, en consecuencia, p 2 es un número par. Pero para que
el cuadrado de un número sea par, necesariamente dicho número debe ser par. Luego p = 2a
para conveniente a. Sustituyendo, q 2 = 2a 2 y, por tanto, q también es par. Hemos obtenido una
contradicción: la fracción
p p/q no puede ser irreducible y, a la vez, que numerador y denominador
sean pares. Por tanto, 2 no puede ser raci

## 7 - EJERCICIOS

## 8 - SOLUCIONES