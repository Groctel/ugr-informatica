# ESTADÍSTICA DESCRIPTIVA UNIDIMENSIONAL

## 1 - CONCEPTOS BÁSICOS

### 1.1 - FENÓMENOS

Un fenómeno es un hecho que ocurre y produce un resultado. Previo a hacer un análisis de él, debemos identificar dos tipos fundamentales:
- **Fenómeno determinista:** Se obtiene el mismo resultado al repetirlo en idénticas condiciones.
  - Desplazamiento de un cuerpo en un tiempo y velocidad fijos.
- **Fenómeno aleatorio:** No es posible predecir el resultado.
  - Resultado de una tirada de un dado.

### 1.2 - ESTADÍSTICA

La estadística se ocupa de recopilar, analizar, interpretar y representar los fenómenos aleatorios en grandes cantidades de datos numéricos. Existen dos ramas fundamentales de la estadística:
- **Estadística descriptiva:** Busca manejar cantidades ingentes de datos resumiéndolos y presentándolos de forma que su interpretación sea mucho más sencilla, reflejando en pocos valores la máxima información posible.
- **Inferencia estadística:** Utiliza la estadística descriptiva y la teoría de la probabilidad para averiguar qué está ocurriendo en una población a partir de una muestra.

### 1.3 - ESTUDIO ESTADÍSTICO

Dentro de un estudio estadístico debemos conocer una serie de conceptos:
- **Población:** Conjunto objeto del estudio (todas las tiradas del d20 en una campaña). Proporcionan información en forma de datos.
- **Individuo o unidad:** Cada uno de los elementos de la población (una tirada de un d20).
- **Muestra:** Subconjunto de la población que se estudia (las tiradas lanzadas en una sesión de una campaña). Debido a la imposibilidad de estudiar la población entera muchas veces, se toma una muestra para estudiarla.
- **Tamaño de la población `N`:** Número de individuos de la población (cuántas tiradas se han producido en una campaña).
- **Tamaño de la muestra `n`:** Número de individuos de la muestra (cuántas tiradas se han producido en una sesión de una campaña).
- **Carácter o variable:** Propiedad que se desea observar sobre los elementos de la población (puntuación obtenida al lanzar un d20).
  - **Variables cualitativas:** Sus modalidades son características no numéricas.
    - **Ordinales:** Pueden ordenarse a partir de un orden lógico inherente a su significado a pesar de no ser numéricas (suspenso, aprobado, notable, sobresaliente).
    - **Nominales:** No existe un orden lógico, por lo que no pueden ordenarse (coche favorito). Pueden ordenarse por órdenes arbitrarios como el alfabético, pero cada orden produce un resultado diferente.
  - **Variables cuantitativas:** Sus modalidades son características numéricas.
    - **Discretas:** El paso de un valor al siguiente representa un salto (nota obtenida en una asignatura).
    - **Continuas:** Existen infinitos valores posibles entre dos conocidos (tiempo transcurrido entre dos instantes). Puede transformarse en continua modificando la forma de medición de la misma (limitándonos a los milisegundos).
- **Modalidad:** Cada uno de los posible valores observables de una característica (cada una de las caras del d20). Deben ser incompatibles y exhaustivas.

### 1.4 - TABLAS DE FRECUENCIAS

Junto con las modalidades, las tablas de frecuencias almacenan una serie de datos para la interpretación del estudio:
- **Frecuencia absouta *n<sub>i</sub>*:** Número de individuos que presentan la modalidad *M<sub>i</sub>*.
- **Frecuencia relativa *f<sub>i</sub>*:** Razón entre los individuos que presentan la modalidad *M<sub>i</sub>* y el tamaño total de la población.
- **Frecuencia absouta acumulada *N<sub>i</sub>*:** Suma de las frecuencias absolutas hasta la *i*-ésima modalidad.
- **Frecuencia relativa acumulada *F<sub>i</sub>*:** Suma de las frecuencias relativas hasta la *i*-ésima modalidad.

| MODALIDADES | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: |
| *M*<sub>1</sub> | *n*<sub>1</sub> | *f*<sub>1</sub> | *N*<sub>1</sub> | *F*<sub>1</sub> |
| *M*<sub>2</sub> | *n*<sub>2</sub> | *f*<sub>2</sub> | *N*<sub>2</sub> | *F*<sub>2</sub> |
| ... | ... | ... | ... | ... |
| *M<sub>k</sub>* | *n<sub>k</sub>* | *f<sub>k</sub>* | *N<sub>k</sub>* = *N* | *F<sub>k</sub>* = 1 |
| **Suma (Σ)** | ***N*** | **1** | | |

Si las modalidades vienen dadas en intervalos debemos completar la tabla de frecuencia con las siguientes columnas:
- **Marca de clase *x<sub>i</sub>*:** Punto medio del intervalo ]*I<sub>i-I</sub>*, *I<sub>i</sub>*].
- **Amplitud del intervalo *a<sub>i</sub>*:** Diferencia entre los límites superior e inferior del intervalo.
- **Densidad de frecuencia *h<sub>i</sub>*:** Razón entre la frecuencia absoluta del intervalo y su amplitud.

| INTERVALOS | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| ]*I*<sub>0</sub>, *I*<sub>1</sub>] | *x*<sub>1</sub> | *a*<sub>1</sub> | *h*<sub>1</sub> | *n*<sub>1</sub> | *f*<sub>1</sub> | *N*<sub>1</sub> | *F*<sub>1</sub> |
| ]*I*<sub>2</sub>, *I*<sub>3</sub>] | *x*<sub>2</sub> | *a*<sub>2</sub> | *h*<sub>2</sub> | *n*<sub>2</sub> | *f*<sub>2</sub> | *N*<sub>2</sub> | *F*<sub>2</sub> |
| ... | ... | ... | ... | ... | ... | ... | ... |
| ]*I<sub>k-I</sub>*, *I<sub>k</sub>*] | *x<sub>k</sub>* | *a<sub>k</sub>* | *h<sub>k</sub>* | *n<sub>k</sub>* | *f<sub>k</sub>* | *N<sub>k</sub>* = *N* | *F<sub>k</sub>* = 1 |
| **Suma (Σ)** | | | | ***N*** | **1** | | |

Al trabajar con intervalos es común que busquemos valores dentro de ellos. Para referenciar estos valores asumimos que la evolución dentro del intervalo es lineal y los calculamos mediante la siguiente fórmula:

### 1.5 - REPRESENTACIÓN GRÁFICA DE LAS FRECUENCIAS

#### 1.5.1 - VARIABLES CUALITATIVAS

<p align="center">
	<img src="https://drive.google.com/uc?export=view&id=1HCp8KUMd43Wn7LIh0WXbAa624UQfPZk9">
	<b>Diagrama de barras y gráfico de sectores</b>
</p>

El gráfico de sectores sirve para aquellos datos no ordenables, como puede ser la comida favorita de los individuos, pues en un diagrama de barras se distribuyen los datos cualitativos a lo largo del eje *X* y se da información incorrecta diciendo implícitamente que una modalidad es mayor que otra.

#### 1.5.2 - VARIABLES CUANTITATIVAS DISCRETAS

<p align="center">
	<img src="https://drive.google.com/uc?export=view&id=13KDoCnM8dLVOrcEeetSCyU8pi7oyttIM">
	<b>Diagrama de barras y polígono de frecuencias</b>
</p>
Utilizamos barras delgadas para que no se encuentren a caballo entre dos valores y las colocamos a una distancia de las otras directamente proporcional a la diferencia entre los valores de la modalidad de forma que se van los saltos (si los hubiera) en los valores de la modalidad.


<p align="center">
	<img src="https://drive.google.com/uc?export=view&id=1hK_FOz16023Tq6Ux8g0EMI8oqT6xoHDT">
	<b>Curva acumulativa o de distribución y diagrama de tallos y hojas</b>
</p>

El diagrama de tallos y hojas toma la parte común de una serie de números y la pone a la derecha de una barra. Los dígitos a la izquierda de la barra completan la información de la columna común. La columna de la izquierda va tomando la acumulación de datos simultáneamente de forma ascendente y descendente hasta que se encuentran en un punto en el que la acumulación tome el mismo valor. Si se llegase a un punto en el que se solaparan, se escribe entre paréntesis la longitud del tallo y se marca la hoja que se encuentra en la mitad de la acumulación.

#### 1.5.2 - VARIABLES CUANTITATIVAS CONTINUAS

<p align="center">
	<img src="https://drive.google.com/uc?export=view&id=1qN7CeTL-d3urZDJG_ctusfKruuoQy4ig">
	<b>Histograma e histograma acumulado</b>
</p>
Los histogramas contienen una barra por intervalo, cuya altura corresponde a la densidad de frecuencia de dicho intervalo.

Los histogramas acumulados muestran las frecuencias acumuladas y nos permiten ver qué porción de la población se encuentra en cada extremo del intervalo. La línea que los cruza, que representa la **función de distribución**, se dibuja suponiendo que los datos están distribuidos de forma lineal dentro del intervalo y puede guiarnos para calcular el porcentake de 


## 2 - MEDIDAS DE POSICIÓN CENTRAL

### 2.1 - MEDIA ARITMÉTICA

Suma de los valores de la variable ponderada por sus frecuencias relativas. Representa el *centro de gravedad* alrededor del cual oscilan los valores de la muestra.

![equation](https://latex.codecogs.com/gif.latex?\overline{x}=\sum_{i=1}^{k}x_{i}f_{i}=\frac{\sum_{i=1}^{k}x_{i}n_{i}}{N})

### 2.2 - MEDIANA

Valor de la variable que divide a los individuos de la población en dos partes iguales. Se corresponde con *F*<sub>i</sub> = 0.5. Podemos tomar la mediana en dos casos:
- ∃*F*<sub>i</sub> = 0.5:
![equation](https://latex.codecogs.com/gif.latex?Me=\frac{x_{i}-x_{i+1}}{2})
- ∃!*F*<sub>i</sub> = 0.5:
![equation](https://latex.codecogs.com/gif.latex?Me=I_{i-1}+\frac{\frac{N}{2}-N_{i-1}}{n_{i}}a_{i})

### 2.3 - MODA

Valor más frecuente de la distribución. No tiene por qué ser único.

![equation](https://latex.codecogs.com/gif.latex?Mo=I_{i-1}+\frac{h_{i}-h_{i-1}}{(h_{i}-h_{i-1})+(h_{i}-h_{i+1})}a_{i})

## 3 - MEDIDAS DE POSICIÓN NO CENTRAL

### 3.1 - CUANTILES

El cuantil de orden α ∈ [0,1] es el valor de la variable que acumula el 100α% de la distribución.

![equation](https://latex.codecogs.com/gif.latex?C(\alpha)=I_{i-1}&plus;\frac{\alpha\cdot%20N-N_{i-1}}{n_{i}}a_{i})

### 3.2 - CUARTILES (*Q<sub>i</sub>*)

Puntos de la distribución que se dividen en cuatro partes, agrupando cada una el 25% de los datos.111

    α = 0.25, 0.5, 0.75

Llamamos **rango intercuartílico** (RIQ) a la diferencia entre *Q*<sub>3</sub> y *Q*<sub>1</sub>.

### 3.3 - DECILES (*D<sub>i</sub>*)

Puntos de la distribución que se dividen en diez partes, agrupando cada una el 10% de los datos.

    α = 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9

### 3.4 - PERCENTILES (*P<sub>i</sub>*)

Puntos de la distribución que se dividen en cien partes, agrupando cada una el 1% de los datos.

    α = 0.01, 0.02, 0.03, ... , 0.97, 0.98, 0.99

## 4- MEDIDAS DE DISPERSIÓN

### 4.1 - VARIANZA

![equation](https://latex.codecogs.com/gif.latex?\sigma_{X}^{2}=Var(X)=\frac{1}{N}\sum_{i=1}^{k}(x_{i}-\overline{x})^2n_{i}=\frac{1}{N}\sum_{i=1}^{k}x_{i}^2n_{i}-\overline{x}^2)

### 4.2 - DESVIACIÓN TÍPICA

![equation](https://latex.codecogs.com/gif.latex?\sigma_{X}=\sqrt{Var(X)})

### 4.3 - COEFICIENTE DE VARIACIÓN

![equation](https://latex.codecogs.com/gif.latex?CV=\frac{\sigma}{\overline{x}})

## 5 - EJERCICIOS

### EJERCICIO 1

Se hace una encuesta al inicio del curso 2012-2013, donde a los alumnos se les pregunta una serie de cuestiones y se hace una clasificación de los alumnos por sexo. Para este primer día de curso, la encuesta dio que el número de alumnas que acudieron y contestaron la encuesta es 3. Si se hicieron 41 encuestas en total.
- Define la población y la muestra así como el tamaño de la muestra.
- ¿Qué tipo de variable es la que se está estudiando?
- Construir la tabla de frecuencias de esta variable.
- Elegir un gráfico apropiado para esta variable.

### EJERCICIO 2

A continuación aparecen los resultados obtenidos en la encuesta inicial del curso 2012-2013, sobre si los alumnos que asistieron el primer dı́a a clase han estudiado estadística en educación secundaria:

    poco, poco, nada, poco, nada, nada, nada, poco, nada, nada, poco, bastante, poco, poco, nada, poco, mucho, poco, nada, poco, nada, poco, nada, poco, poco, mucho, poco, bastante, poco, nada, bastante, poco, poco, poco, nada, nada, mucho, nada, poco, poco, bastante

- Definir la población y la muestra así como el tamaño de la muestra.
- ¿Qué tipo de variable es la que se está estudiando?
- Construir la tabla de frecuencias de esta variable.
- Elegir un gráfico apropiado para esta variable.

### EJERCICIO 3

Los datos siguientes son los obtenidos en la encuesta inicial del curso 2012-2013, salvo para 3 casos eliminados, acerca de la edad de los alumnos:

    20, 19, 20, 19, 20, 19, 18, 18, 18, 20, 18, 23, 18, 20, 23, 34, 19, 18, 20, 18, 19, 21, 22, 39, 23, 23, 22, 21, 19, 21, 18, 22, 18, 18, 19, 19, 19, 21

- Dar el tamaño de la muestra.
- ¿Qué tipo de variable es la que se está estudiando?
- Construir la tabla de frecuencias de esta variable.
- Elegir un gráfico apropiado para esta variable.

### EJERCICIO 4

Disponemos de 50 datos relativos a un estudio sobre el número de empleados que faltan al trabajo en una empresa durante 50 días. Los datos recogidos son:

    0, 0, 1, 4, 3, 2, 0, 1, 2, 0, 1, 0, 0, 0, 2, 1, 1, 1, 0, 5, 2, 0, 1, 1, 0, 0, 2, 0, 0, 0, 1, 0, 0, 3, 4, 0, 3,1, 0, 0, 0, 0, 1, 0, 0, 1, 2, 2, 1, 0.

Obtener:
-  Distribución de frecuencias del número de trabajadores que han faltado al trabajo.
-  Elegir un gráfico apropiado para esta variable.
- Calcular la media e interpretar su valor.

### EJERCICIO 5

Se dispone de la siguiente tabla de datos:

| *x<sub>i</sub>* | *n<sub>i</sub>* |
| :---: | :---: |
| 0 | 1 |
| 1 | 12 |
| 2 | 22 |
| 3 | 34 |
| 4 | 26 |
| 5 | 14 |

- Obtener las frecuencias relativas, relativas acumuladas y absolutas acumuladas.
- Elegir una representación gráfica para esta distribución.
- Calcular el porcentaje de valores menores o iguales a 3.
- Calcular el porcentaje de valores mayores a 4.

### EJERCICIO 6

Se desea estudiar la estatura de los alumnos de cierto curso y sus 40 componentes proporcionaron los siguientes datos en metros:

```
1.52, 1.69, 1.67, 1.62, 1.58, 1.59, 1.66, 1.72, 1.70, 1.70, 1.68, 1.68, 1.68, 1.79, 1.73, 1.70, 1.65, 1.76, 1.74, 1.65, 1.80, 1.75, 1.81, 1.74, 1.72, 1.60, 1.85, 1.75, 1.71, 1.62, 1.53, 1.77, 1.60, 1.61, 1.72, 1.76, 1.68, 1.66, 1.50, 1.71
```

Se pide:
- Distribución de frecuencias agrupando los datos en intervalos de amplitud 5 cm.
- Completar la tabla de frecuencias.
- Calcular el valor medio e interpretar su valor.

### EJERCICIO 7

Se ha observado el peso de 70 personas de una determinada población (en Kg.) y se ha obtenido la siguiente tabla:

| PESOS | *n<sub>i</sub>* |
| :---: | :---: |
| 50-60 | 7 |
| 60-70 | 16 |
| 70-80 | 26 |
| 80-90 | 17 |
| 90-100 | 5 |


Se pide:
- Obtener frecuencias relativas y frecuencias acumuladas.
- Obtener marcas de clase y amplitud de los intervalos.
- Calcular el valor medio e interpretar el valor.

### EJERCICIO 8

En una empresa automovilı́stica trabajan 60 personas, cuyos salarios mensuales, en euros, vienen determinados en la tabla siguiente:

| SALARIO | TRABAJADORES |
| :---: | :---: |
| 300-600 | 13 |
| 600-1000 | 15 |
| 1000-1500 | 20 |
| 1500-1800 | 8 |
| 1800-2500 | 4 |

- Frecuencias absolutas y frecuencias absolutas acumuladas.
- Frecuencias relativas y frecuencias relativas acumuladas.
- Marcas de clase y amplitud de los intervalos.
- Calcular qué tanto por ciento de trabajadores perciben salarios
  - entre 600 y 1000.
  - inferiores a 1500.
  - inferiores a 1700.
  - superiores a 1900.

### EJERCICIO 9

Dada la siguiente distribución:
| *I*<sub>*i*−1</sub>−*I<sub>i</sub>* | *n<sub>i</sub>* |
| :---: | :---: |
| 0–5 | 3 |
| 5–10 | 12 |
| 10–20 | 4 |
| 20-50 | 1 |

Calcular la media aritmética, la moda y la mediana. Interpretar los valores obtenidos.

### EJERCICIO 10

En siete momentos del día se observa el número de clientes que hay en un negocio, anotando:
    2, 5, 2, 7, 3, 4, 9

Calcular e interpretar los valores de la media aritmética, mediana y moda.

### EJERCICIO 11

Completar las siguientes tablas de frecuencias:

#### a)

| *x<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: |
| 2 | 6 | | | |
| 4 | 8 | | | |
| 6 | 5 | | | |
| 8 | 1 | | | |

#### b)

| *x<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 3 |  |  |  |
| 2 |  | 0.1 |  |  |
| 3 |  | 0.2 |  |  |
| 4 |  |  |  | 0.75 |
| 5 |  |  | 60 |  |

#### c)

| | *n<sub>i</sub>* | *N<sub>i</sub>* | *f<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0-100 | 238 |  |  |  |  |  |  |
| 100-200 | 145 |  |  |  |  |  |  |
| 200-500 | 341 |  |  |  |  |  |  |
| 500-1000 | 127 |  |  |  |  |  |  |
| 1000-1200 | 149 |  |  |  |  |  |  |


#### d)

| | *n<sub>i</sub>* | *N<sub>i</sub>* | *f<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0-10 |  |  |  | 0.28 |  |  |  |
|  |  |  | 0.32 |  |  | 20 |  |
|  | 30 |  |  |  |  |  | 3 |
| 40-100 |  |  |  | 0.925 |  |  |  |
|  |  | 200 |  |  | 125 |  |  |

#### e)

| | *n<sub>i</sub>* | *N<sub>i</sub>* | *f<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 20-50 | 10 | 10 |  |  | 35 |  |  |
| -60 |  | 14 |  | 0.112 |  |  |  |
| 60-70 |  |  |  | 0.24 |  | 10 |  |
|  |  |  | 0.208 |  | 75 |  |  |
|  | 44 |  |  |  |  |  | 2.2 |
| 100- |  | 125 |  |  |  | 50 | 0.5 |

### EJERCICIO 12

En la siguiente tabla se resume el peso de 90 individuos:

| PESO | *n<sub>i</sub>* |
| 40-50 | 7 |
| 50-60 | 12 |
| 60-65 | 18 |
| 65-70 | 22 |
| 70-75 | 13 |
| 75-80 | 10 |
| 80-90 | 5 |
| 90-100 | 3 |

Calcular:
- La media aritmética.
- La moda.
- Percentiles 12, 22, 64 y 81.
- Deciles 3, 6 y 9.
- Si se consideran obesos aquellos cuyo peso está sobre el percentil 85, ¿qué peso mínimo habrá de tener un individuo para considerarse obeso?
- Si se consideran delgados aquellos cuyo peso está por debajo del percentil 15, ¿qué peso máximo ha de tener un individuo para considerarlo delgado?

### EJERCICIO 13

La tabla siguiente indica la distribución de coeficientes intelectuales de 14 alumnos:

| 60-80 | 80-90 | 90-100 | 100-115 | 115-130 | 130-140 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 25 | 25 | 46 | 37 | 6 | 1 |

Se pide:
- Si se consideran adelantados los alumnos cuya puntuación pertenece al grupo del 36,71% de las puntuaciones más altas, ¿qué puntuación mínima habrá de tener un individuo para ser considerado adelantado?
- Si se consideran atrasados los alumnos cuya punntuación pertenece al grupo del 25% de las puntuaciones más bajas, ¿qué puntuación máxima habrá de tener un individuo para ser considerado atrasado?
- ¿Qué porcentaje de alumnos presenta una puntuación inferior a 100? ¿Y superior a 124? ¿Y entre 92 y 114?

### EJERCICIO 14

### EJERCICIO 15

### EJERCICIO 16

### EJERCICIO 17

### EJERCICIO 18

### EJERCICIO 19

### EJERCICIO 20

### EJERCICIO 21

### EJERCICIO 22

### EJERCICIO 23

## 6 - SOLUCIONES

### EJERCICIO 1

- La población son todos los alumnos del curso 2012-2013. La muestra está compuesta por los 41 alumnos que respondieron la encuesta.
- Se está estudiando el sexo de los estudiantes.

| SEXO | *n<sub>i</sub>* |
| :---: | :--: |
| M | 38 |
| F | 3 |

- Al tratarse de una distribución discreta de variables cualitativas nominales y al ser un estudio enfocado en ver el número de personas de uno u otro sexo dentro de la clase un gráfico de sectores es lo más apropiado, ya que permite comparar a ojo la razón de cada modalidad.

### EJERCICIO 2

- La población son todos los alumnos del curso 2012-2013. La muestra está compuesta por los 41 alumnos que respondieron la encuesta.
- Se está estudiando una variable cualitativa ordinal, ya que pueden ordenarse los datos con un orden lógico ascendente.

| ESTUDIO | *n<sub>i</sub>* |
| :---: | :--: |
| Nada | 14 |
| Poco | 20 |
| Bastante | 4 |
| Mucho | 3 |

- Al tratarse de una distribución discreta de variables cualitativas ordinales y al ser un estudio enfocado en ver la cantidad de tiempo que se ha estudiado a la asignatura un diagrama de barras es lo más apropiado, ya que permite ver el número de alumnos que han estudiado una cierta cantidad a lo largo de la secundaria.

### EJERCICIO 3

- La muestra consta de 38 alumnos.
- Se está estudiando una variable cuantitativa discreta, ya que la edad de una persona tiene dominio en ℕ.

| EDAD | *n<sub>i</sub>* |
| :---: | :--: |
| 18 | 10 |
| 19 | 9 |
| 20 | 6 |
| 21 | 4 |
| 22 | 3 |
| 23 | 4 |
| 34 | 1 |
| 39 | 1 |

- Al tratarse de una distribución de variables cuantitativas discretas, lo más lógico parece ser usar un diagrama de barras. Sin embargo, ya que las edades pueden entenderse como unidades continuas (18 años y medio), un polígono de frecuencias parece más adecuado.

### EJERCICIO 4

| FALTAS | *n<sub>i</sub>* |
| :---: | :--: |
| 0 | 24 |
| 1 | 13 |
| 2 | 7 |
| 3 | 3 |
| 4 | 2 |
| 5 | 1 |

- Al tratarse de una distribución de variables cuantitativas discretas, lo más adecuado es usar un diagrama de barras.
- La media aritmética viene dada por la suma de cada frecuencia absoluta ponderada por su correspondiente número de faltas, siendo su resultado total 0.98. Esto nos indica que, en general, la empresa ha tenido un trabajador ausente cada día excepto uno.

### EJERCICIO 5

| *x<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: |
| 0 | 1 | 0.0091 | 1 | 0.0091 |
| 1 | 12 | 0.11 | 13 | 0.1191 |
| 2 | 22 | 0.2018 | 35 | 0.3209 |
| 3 | 34 | 0.3119 | 69 | 0.6328 |
| 4 | 26 | 0.2385 | 95 | 0.8713 |
| 5 | 14 | 0.1284 | 109 | 0.9997 (1) |

- Al tratarse de una distribución de variables cuantitativas discretas, lo más adecuado es usar un diagrama de barras.
- Sumamos las frecuencias absoutas de [0-3], dividimos entre el total de la muestra y multliplicamos por 100. Nos da un 63.3027%.
- Sumamos la frecuencia absoluta de 5, dividimos entre el total de la muestra y multiplicamos por 100. Nos da un 12.844%.

### EJERCICIO 6

| ALTURA | *x<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :--: | :--: | :--: | :--: | :---: |
| [1.50-1.55[ | 1.525 | 3 | 0.075 | 3 | 0.075 |
| [1.55-1.60[ | 1.575 | 3 | 0.075 | 6 | 0.15 |
| [1.60-1.65[ | 1.625 | 7 | 0.175 | 13 | 0.325 |
| [1.65-1.70[ | 1.675 | 11 | 0.275 | 24 | 0.6 |
| [1.70-1.75[ | 1.725 | 8 | 0.2 | 32 | 0.8 |
| [1.75-1.80[ | 1.775 | 5 | 0.125 | 37 | 0.925 |
| [1.80-1.85] | 1.825 | 3 | 0.075 | 40 | 1 |

- La media aritmética viene dada por la suma de cada frecuencia absoluta ponderada por la marca de clase de cada una de las alturas, siendo su resultado total 1.68125. Esto nos indica que una mitad de los alumnos están por debajo que esa altura y la otra mitad, por encima.

### EJERCICIO 7

| PESOS | *x<sub>i</sub>* | *a<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 50-60 | 55 | 10 | 7 | 0.1 | 7 | 0.1 |
| 60-70 | 65 | 10 | 15 | 0.2142 | 22 | 0.3142 |
| 70-80 | 75 | 10 | 26 | 0.3714 | 48 | 0.6856 |
| 80-90 | 85 | 10 | 17 | 0.2428 | 65 | 0.9284 |
| 90-100 | 95 | 10 | 5 | 0.0714 | 70 | 0.9998 (1) |

- La media aritmética viene dada por la suma de cada frecuencia absoluta ponderada por la marca de clase de cada una de las alturas, siendo su resultado total 74.7142. Esto nos indica que una mitad de la población está por debajo que esa altura y la otra mitad, por encima.

### EJERCICIO 8

| SALARIO | TRABAJADORES | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 300-600 | 13 | 0.21(6) | 13 | 0.21(6) | 450 | 300 |
| 600-1000 | 15 | 0.25 | 28 | 0.4(6) | 800 | 400 |
| 1000-1500 | 20 | 0.(3) | 48 | 0.8 | 1250 | 500 |
| 1500-1800 | 8 | 0.1(3) | 56 | 0.9(3) | 1650 | 300 |
| 1800-2500 | 4 | 0.0(6) | 60 | 1 | 2150 | 700 |

- Un 25% de los trabajadores perciben un salario entre 600 y 1000 euros.
- Un 80% de los trabajadores perciben un salario inferior a 1500 euros.
- Un 88.(8)% de los trabajadores perciben un salario inferior a 1700 euros.
- Un 99.(047619)% de los trabajadores perciben un salario superior a 1900 euros.

### EJERCICIO 9

- La media aritmética viene dada por la suma de todas las frecuencias absolutas entre el número de modalidades, siendo su valor 5. Esto nos indica que los valores de la muestra oscilan alrededor del 5.
- La mediana es el intervalo [5,10]. Esto nos indica que es esta modalidad la que divide la muestra en dos mitades.
- La moda es el intervalo [5,10]. Esto nos indica que es la modalidad que más se repite en la muestra tomada.

### EJERCICIO 10

- La media aritmética viene dada por la suma del número de clientes en cada momento entre el número de veces que se ha medido, siendo su resultado total 4.5714. Esto nos indica que, en general, ha habido entre 4 y 5 personas en la tienda durante toda la jornada.
- La mediana es 5, ya que es la modalidad cuya frecuencia se encuentra exactamente entre ambas mitadas de la distribución frecuencial. **TODO: Interpretar la mediana.**
- La moda es el 2. Esto nos indica que la tienda está mayormente vacía y tiene picos de clientes en horas concretas.

### EJERCICIO 11

#### a)

| *x<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: |
| 2 | 6 | 0.3 | 6 | 0.3 |
| 4 | 8 | 0.4 | 14 | 0.7 |
| 6 | 5 | 0.25 | 19 | 0.95 |
| 8 | 1 | 0.05 | 20 | 1 |

#### b)

| *x<sub>i</sub>* | *n<sub>i</sub>* | *f<sub>i</sub>* | *N<sub>i</sub>* | *F<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 3 | 0.05 | 3 | 0.05 |
| 2 | 6 | 0.1 | 9 | 0.15 |
| 3 | 12 | 0.2 | 21 | 0.35 |
| 4 | 24 | 0.4 | 45 | 0.75 |
| 5 | 15 | 0.25 | 60 | 1 |

#### c)

| | *n<sub>i</sub>* | *N<sub>i</sub>* | *f<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0-100 | 238 | 238 | 0.238 | 0.238 | 50 | 100 | 2.38 |
| 100-200 | 145 | 383 | 0.145 | 0.383 | 150 | 100 | 1.45 |
| 200-500 | 341 | 724 | 0.341 | 0.724 | 350 | 300 | 1.13(6) |
| 500-1000 | 127 | 851 | 0.127 | 0.851 | 750 | 500 | 0.254 |
| 1000-1200 | 149 | 1000 | 0.149 | 1 | 1100 | 200 | 0.745 |

#### d)

| | *n<sub>i</sub>* | *N<sub>i</sub>* | *f<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0-10 | 56 | 56 | 0.28 | 0.28 | 5 | 10 | 5.6 |
| 10-30 | 64 | 120 | 0.32 | 0.6 | 20 | 20 | 3.2 |
| 30-40 | 30 | 150 | 0.15 | 0.75 | 35 | 10 | 3 |
| 40-100 | 35 | 185 | 0.175 | 0.925 | 70 | 60 | 0.58(3) |
| 100-150 | 15 | 200 | 0.075 | 1 | 125 | 50 | 0.3 |

#### e)

| | *n<sub>i</sub>* | *N<sub>i</sub>* | *f<sub>i</sub>* | *F<sub>i</sub>* | *x<sub>i</sub>* | *a<sub>i</sub>* | *h<sub>i</sub>* |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 20-50 | 10 | 10 | 0.08 | 0.08 | 35 | 30 | 0.(3) |
| 50-60 | 4 | 14 | 0.032 | 0.112 | 55 | 5 | 0.8 |
| 60-70 | 14 | 28 | 0.128 | 0.24 | 65 | 10 | 1.4 |
| 70-80 | 26 | 54 | 0.208 | 0.448 | 75 | 10 | 2.6 |
| 80-100 | 44 | 98 | 0.325 | 0.773 | 90 | 20 | 2.2 |
| 100-150 | 27 | 125 | 0.216 | 1 | 125 | 50 | 0.5 |

### EJERCICIO 12

- La media aritmética se calcula a partir del producto de las marcas de clase 

### EJERCICIO 13

### EJERCICIO 14

### EJERCICIO 15

### EJERCICIO 16

### EJERCICIO 17

### EJERCICIO 18

### EJERCICIO 19

### EJERCICIO 20

### EJERCICIO 21

### EJERCICIO 22

### EJERCICIO 23