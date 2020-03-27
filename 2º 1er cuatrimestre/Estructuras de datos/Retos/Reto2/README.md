# Reto 2 - Abstracción

## Enunciado

Dado un conjunto de 6 enteros sacados aleatoriamente del conjunto:

```
R={1,2,3,4,5,6,7,8,9,10,25,50,75,100}
```

podemos plantearnos conseguir otro entero aleatorio de 3 cifras usando para ello sólo las operaciones de suma, resta, producto y división entera, teniendo encuenta que sólo se puede usar cada número (de los 6) como mucho una vez, aunque es posible que no todos se usen para conseguir el número de 3 cifras.

**Ejemplo:**

Se sacan aleatoriamente del conjunto `C` los números:

```
6,8,10,9,4,75
```

y se pide que con ellos se consiga el número (también aleatoriamente generado):

```
835
```

Una posible solución (que no tiene por qué ser única) es ésta:

> `8/4 = 2`
>
> `9+2 = 11`
>
> 75*11 = 825`
>
> 825+10 = 835`

Como veis, se han usado sólo 5 de los 6 números y sin usar ninguno más de una vez (el dígito `6` no ha hecho falta en esta solución) y sólo operaciones de `+`, `*` y `/` (la resta en este caso tampoco ha hecho falta) para conseguir llegar al número exacto.
No pueden tenerse resultados temporales negativos, es decir, pasos intermedios como `4-8=-4` y usar ese `-4` no están permitidos, como tampoco está permitido hacer una división no exacta, es decir, no puede hacerse `75/11` y redondear.

Obviamente, puede que sea imposible que con 6 números aleatorios se pueda conseguir el aleatorio de 3 cifras y en ese caso hay dos salidas:

- **La más simple:** Que el algoritmo diga que no hay solución.
- **La más interesante:** Que la salida del algoritmo sea conseguir el número más próximo posible al que nos piden.

Evidentemente, en la generación aleatoria podría haber repeticiones y salir, p.ej., estos 6 números:

```
1,3,5,3,100,5
```

donde el `3` y el `5` aparecen 2 veces.
No pasa nada, esto es válido, simplemente que para alcanzar la solución contáis con dos treses y dos cincos, nada más, pero sigue estando presente la restricción de la no repetición, es decir, que contáis con 6 números: un `1`, dos `3`, dos `5` y un `100`, es decir, se puede usar cada número de la serie SÓLO UNA VEZ (como mucho, una vez el `1`, una vez el primer `3`, una vez el primer `5`, una vez el segundo `3`, una vez el `100` y una vez el segundo `5`).

Como curiosidad, indicar que existen combinaciones de 6 números de `C` con las que puede obtenerse cualquier número de 3 cifras (y sería interesante pensar en cómo podrían conseguirse tales combinaciones).
P.ej., a partir del conjunto `C={2,6,7,9,50,75}` se puede conseguir cualquier número de 3 cifras.

El reto consiste en crear un algoritmo para resolver el problema de las cifras.
La idea es que deis (si es posible) un algoritmo (secuencia de pasos) para resolver el problema.
No quiero un programa, quiero una solución que haga uso de vuestra capacidad de abstracción.
Ánimo con las soluciones.
Veamos en qué punto está vuestra creatividad y vuestra capacidad de abstracción de cara a resolver un problema.
Es un reto intelectualmente interesante para un ingeniero informático.
