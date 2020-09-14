# ÁLGEBRA DE BOOLE

Las funciones booleanas devuelven dos valores: `true` y `false`.

## 1 - DEFINICIÓN

Sea *B* un conjunto, *B* tiene estructura de álgebra de Boole si se tienen definidas en él dos operaciones:
- **Suma (OR):** ∨: B×B → B : (x,y) ↦ x∨y
- **Producto (AND):** ∧: B×B → B : (x,y) ↦ x∧y

Las operaciones suma y producto cumplen las siguientes propiedades:
- **Asociativa:**
- **Conmutativa:**
- **Distributiva de la suma respecto al producto:**
- **Elemento neutro de la suma:** *x*∨0 = *x*
- **Elemento neutro del producto:** *x*∧1 = *x*
- **Ídempotencia:** *x*∨*x* = *x*, *x*∧*x* = *x*
- **Complementario de la suma:** = 1
- **Complementario del producto:** = 0
- **Dominación:** *x*∨1 = 1, *x*∧*x* = 0
- **Absorción:** *x*∨(*x*∧*y*) = *x*, *x*∧(*x*∨*y*) = *x*
- **Cancelación:** *x*∨*y* = *x*∨*z* ⇒ *y* = *z*, *x*∧*y* = *x*∧*z* ⇒ *y* = *z*
- ¬¬*x* = *x*
- ¬(*x*∨*y*) = ¬*x*∧¬*y*
- ¬(*x*∧*y*) = ¬*x*∨¬*y*
- *x* = *x*∨0 = *x*∨(*x*∧¬*x*) = (*x*∨*x*)∧(*x*∨¬*x*) = (*x*∨*x*)∧1 = ***x*∨*x***
- **Dualidad:** Al cambiar todos los 0 por 1 y todos los ∨ por ∧ se obtienen nuevas propiedades (excepto en casos en los que se llegue a la misma propiedad).

###### 𝔹 = {0,1}

| **∨** | **0** | **1** | | **∧** | **0** | **1** |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | 0 | 1 | | **0** | 0 | 0 |
| **1** | 1 | 1 | | **1** | 0 | 1 |

Sea X un conjunto, P(X) es un álgebra de Boole con las operaciones **unión** e **intersección**.

Sea 𝔹<sup>n</sup>, se distribuyen sus operaciones de la siguiente manera:
- **Suma:** (*x*<sub>1</sub>, *x*<sub>2</sub>, ... ,*x<sub>n</sub>*)∨(*y*<sub>1</sub>, *y*<sub>2</sub>, ... ,*y<sub>n</sub>*) = (*x*<sub>1</sub>∨*y*<sub>1</sub>, *x*<sub>2</sub>∨*y*<sub>2</sub>, ... ,*x<sub>n</sub>*∨*y<sub>n</sub>*)
- **Producto:** (*x*<sub>1</sub>, *x*<sub>2</sub>, ... ,*x<sub>n</sub>*)∧(*y*<sub>1</sub>, *y*<sub>2</sub>, ... ,*y<sub>n</sub>*) = (*x*<sub>1</sub>∧*y*<sub>1</sub>, *x*<sub>2</sub>∧*y*<sub>2</sub>, ... ,*x<sub>n</sub>*∧*y<sub>n</sub>*)

El conjunto D(30) = {1,2,3,5,6,10,15,30} es álgebra de Boole, ya que *x*∨*y* = *mcm*(*x*,*y*) = 6∨10 = 30 y *x*∧*y* = *mcd*(*x*∧*y*) = 6∧10 = 2. Sin embargo, D(20) no es álgebra de Boolem ya que **falta la existencia del complementario en alguno de sus elementos**. Esto se debe a que el número de combinaciones de respuestas booleanas dadas a las preguntas del tipo *¿es múltiplo de *x*?* es superior al número de elementos totales, pues hay preguntas que dependen de las anteriores (no puede ser múltiplo de 4 sin serlo de 2).

En el conjunto D(30) el elemento neutro es para la suma 1, ya que *mcm*(6,{1,2,3,6})=6 y *mcm*(5,{1,5})=5 y el 1 es el único que coincide en ambos casos.

## 2 - ORDEN

Sea B un álgebra de Boole y sean *x*, *y* ∈ B, *x*≤*y* ⇔ *x*∨*y* = *y*

Las relaciones de orden deben ser:
- **Reflexivas:** *x*≤*x* ⇔ *x*∨*x* = *x*
- **Antisimétricas:** *x*≤*y* *y*≤*x* ⇒ *x* = *y* ∵ *x*∨*y* = *y*, *y*∨*x* = *x* ⇒ *x* = *y*
- **Transitivas:** *x*≤*y* *y*≤*z* ⇒ *x*≤*z* ∵ *x*∨*y* = *y*, *y*∨*z* = *z* ⇒ *x*∨(*y*∨*z*) = (*x*∨*y*)∨*z* = *y*∨*z* = *z*

## 3 - ESTRUCTURA DE ÁLGEBRAS DE BOOLE FINITAS

Sea B un álgebra de Boole finita y a ∈ B, **a es un átomo** ⇔ a != 0, b ≤ a ⇒ b = 0 ∨ b = a

###### Sea 𝔹<sup>5</sup>

Átomos:
- (1, 0, 0, 0, 0) = a<sub>1</sub>
- (0, 1, 0, 0, 0) = a<sub>2</sub>
- (0, 0, 1, 0, 0) = a<sub>3</sub>
- (0, 0, 0, 1, 0) = a<sub>4</sub>
- (0, 0, 0, 0, 1) = a<sub>5</sub>

(1, 0, 1, 0, 0) = a<sub>1</sub> ∨ a<sub>3</sub>
(1, 1, 0, 1, 1) = a<sub>1</sub> ∨ a<sub>2</sub> ∨ a<sub>4</sub> ∨ a<sub>5</sub>

Sea B un álgebra de Boole finita, A sus átomos y *x* != 0 ∈ B, *x* se escribe de forma única (salvo el orden) como disyunción de átomos

| **∨** | **0** | **a** | **b** | **c** | **1** |
| :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | 0 | a | b | c | 1 |
| **a** | a | a | 1 | 1 | 1 |
| **b** | b | 1 | b | 1 | 1 |
| **c** | c | 1 | 1 | c | 1 |
| **1** | 1 | 1 | 1 | 1 | 1 |

| **∧** | **0** | **a** | **b** | **c** | **1** |
| :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | 0 | 0 | 0 | 0 | 0 |
| **a** | 0 | a | 0 | 0 | a |
| **b** | 0 | 0 | b | 0 | b |
| **c** | 0 | 0 | 0 | c | c |
| **1** | 0 | a | b | c | 1 |

No es álgebra de Boole (Diamante), porque falla la propiedad distributiva.

Sea B un álgebra de Boole, cualquier elemento distinto de 1 se expresa como conjunción de coátomos.

