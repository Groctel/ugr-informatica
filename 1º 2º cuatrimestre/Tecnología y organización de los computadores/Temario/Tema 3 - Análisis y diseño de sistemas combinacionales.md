# ANÁLISIS Y DISEÑO DE SISTEMAS COMBINACIONALES

## 1 - CONCEPTO DE SISTEMA COMBINACIONAL

### 1.1 - DEFINICIÓN

Sistema en el que las salidas en cualquier instante dependen sólo de los valores de las entradas en ese mismo instante.

<span style="font-size:1.5em">
	$z_{i}(t)=f_{i}(x_{1}(t),x_{2}(t),\cdots,x_{n}(t))$
</span>

En la práctica, este valor depende de la combinación del valor de las entradas un cierto tiempo antes, ya que se produce un retardo de propagación $pd$ en el sistema.

<span style="font-size:1.5em">
	$z_{i}(t)=f_{i}(x_{1}(t-t_{pd}),x_{2}(t-t_{pd}),\cdots,x_{n}(t-t_{pd}))$
</span>

## 2 - ANÁLISIS DE CIRCUITOS COMBINACIONALES

Un circuito como el del ejemplo se puede analizar de dos formas diferentes.

# CAPTURA 2

- **Funcional:** Deduce la función lógica que realiza el circuito. Se representa con tablas de verdad, expresiones booleanas o mapas de Karnaugh. Es el acercamiento más teórico al sistema.

	$y=a+bc+\overline{b}\overline{c}$

| **a** | **b** | **c** | **y** |
| :---: | :---: | :---: | :---: |
| 0 | 0 | 0 | **1** |
| 0 | 0 | 1 | **0** |
| 0 | 1 | 0 | **0** |
| 0 | 1 | 1 | **1** |
| 1 | 0 | 0 | **1** |
| 1 | 0 | 1 | **1** |
| 1 | 1 | 0 | **1** |
| 1 | 1 | 1 | **1** |

- **Temporal:** Busca conocer el retardo de propagación y el valor de cada nodo en respuesta a una secuencia de entradas. Representa el comportamiento dinámico del circuito mediante cronogramas. Es el acercamiento más teórico al sistema.

| **t** | **0** | **1** | **2** | **3** | **4** | **5** | **6** | **7** |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **a** | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| **b** | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |
| **c** | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
| **y** | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 1 |

## 3 - DISEÑO DE CIRCUITOS COMBINACIONALES

### 3.1 - PASOS DE DISEÑO DE UN CIRCUITO

- Obtención de una descripción verbal de su comportamiento.
- Realización de una tabla de verdad.
- Obtención de la expresión analítica (teorema de Shannon).
- Minimización y expresión de la función en términos del tipo de puertas a usar en la implementación.
- Implementación del circuito de menos coste de hardware y/o menor retardo.

## 4 - COMPONENTES COMBINACIONALES ESTÁNDAR