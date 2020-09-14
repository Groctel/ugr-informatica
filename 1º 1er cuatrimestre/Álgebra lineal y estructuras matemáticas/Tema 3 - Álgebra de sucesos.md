# ÁLGEBRA DE SUCESOS

## 1 - DEFINICIONES BÁSICAS

- **Suceso:** Resultado de un experimento aleatorio.
- **Sucesos elementales:** Cada uno de los resultados posibles que no se pueden dividir en sucesos más pequeños.
- **Espacio muestral (*E*):** Conjunto formado por todos los sucesos elementales.
- **Suceso seguro:** Aquél que ocurre siempre. Contiene a todos los sucesos elementales.
- **Suceso imposible (Ø):** Aquél que no puede ocurrir. No contiene a ningún suceso elemental.
- **Sucesos incompatibles:** Aquéllos que no pueden suceder simultáneamente.
- **Unión de elementos ![equation](https://latex.codecogs.com/gif.latex?a\cup%20b):** Suceso que ocurre cuando ocurre *A*, *B* o ambos simultáneamente. Contiene todos los sucesos elementales de *A* y *B*.
<div style="page-break-after: always;"></div>

- **Intersección de elmentos ![equation](https://latex.codecogs.com/gif.latex?a\cap%20b):** Suceso que ocurre cuando ocurren *A* y *B* simultáneamente Contiene todos los sucesos elementales de *A* y *B*. Si *A* y *B* son incompatibles, su intersección es Ø.
- **Suceso complementario ![equation](https://latex.codecogs.com/gif.latex?\overline{A}=A^{c}):** Suceso que ocurre cuando no ocurre *A*. Contiene todos los sucesos elementales no contenidos en *A*.

### 1.1 - PROPIEDADES DE LAS OPERACIONES

$a\cup b$

## 2 - PROBABILIDAD

- **Definición clásica:** Razón entre el número de casos en el que ocurre *A* y el número de casos posibles. Sólo sirve si todos los sucesos elementales son equiprobables.

$P(A)=\frac{casos\,favorables}{casos\,posibles}$

- **Definición frecuentista:** Realizado el experimento un número suficientemente grande de veces, la probabilidad de que un suceso ocurra es el límite del número de veces que ocurre el suceso entre el número total de veces que se ha realizado dicho experimento.

- **Definicion axiomática de Kolmogorov:** Dado un experimento aleatorio y su espacio muestral *E*, una aplicación que asocia a cada suceso un número real es una probabilidad si se verifican tres axiomas:
  1. $P(A)\geq0,\,\forall A\in E$.
  2. $P(E)=1$.
  3. $P(\bigcup_{i}A_i)=\sum_{i}P(A_i)$ si *A*<sub>1</sub>, *A*<sub>2</sub>, *A*<sub>3</sub>, ... , *A<sub>i</sub>* son incompatibles.