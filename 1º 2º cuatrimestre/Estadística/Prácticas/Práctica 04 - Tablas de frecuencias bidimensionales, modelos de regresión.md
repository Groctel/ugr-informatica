# TABLAS DE FRECUENCIAS BIDIMENSIONALES, MODELOS DE REGRESIÓN

En esta práctica vamos a trabajar con las siguientes variables:

| **DESCRIPCIÓN** | **NOMBRE** | **TIPO** |
| ---: | :--- | :--- |
| Marca temporal | **T** | Fecha |
| Edad | **Edad** | Discreta |
| Altura (en cm) | **Altura** | Continua |
| Peso (en kg) | **Peso** | Continua |
| Grupo | **Grupo** | Cualitativa |
| Sexo | **Sexo** | Cualitativa |
| ¿Cómo accediste a esta titulación? | **Acceso** | Cualitativa |
| ¿El Grado en Ingeniería Informática era tu primera opción? | **I_1opcion** | Cualitativa |
| Número de hermanos (incluyéndote a ti) | **n_herm** | Discreta |
|                             Número de miembros de tu hogar | **n_miem** | Discreta |
|                            Número de vehículos de tu hogar | **n_veh**| Discreta |
|                     ¿Has estudiado alguna vez Estadística? | **Est_Est** | Cualitativa |
| ¿Qué red social prefieres para comunicarte? | **Red** | Cualitativa |
| ¿Qué plataforma docente prefiestes? | **Plataf** | Cualitativa |

## EJERCICIO 1

- Copiamos `respuestas.xls` a una carpeta llamada `Práctica 4` y cambiamos el directorio de trabajo a dicha carpeta:

```shell
$ mkdir Práctica 4 && mv ~/Downloads/respuestas.xls Práctica4
```
```R
setwd("/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 04")
# File > Change working directory
```

- Importamos los datos de Excel a R-Commander, los visualizamos y los guardamos como fichero `Respuestas.RData`.

```R
Respuestas <- 
+   readXL("/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 04/respuestas.xls",
+   rownames=FALSE, header=TRUE, na="", sheet="Respuestas", stringsAsFactors=TRUE)
# Data > Import data > From excel file...
```

- Creamos una tabla de doble entrada con variables cualitativas (*Sexo* y *Redo Social Preferida*) para ver si el sexo influye en la preferencia. Calculamos para ello los porcentajes totales, por fila y por columna para obtener los marginales y condicionales de la tabla.

```R
> library(abind, pos=16)
> local({
+   .Table <- xtabs(~Red+Sexo, data=Respuestas)
+   cat("\nFrequency table:\n")
+   print(.Table)
+   cat("\nRow percentages:\n")
+   print(rowPercents(.Table))
+ })
# Statistics > Contingency tables > Two-way tables...
	# Data
		# Row variable -> Red
		# Column variable -> Sexo
	# Statistics > Compute percentages > Row percentages
```
```
Frequency table:
           Sexo
Red         Mujer Varón
  Facebook     10    60
  Instagram     3     8
  Otra          8    69
  Tuenti        0     1
  Twitter       9    87
  WhatsApp     36   362

Row percentages:
           Sexo
Red         Mujer Varón Total Count
  Facebook   14.3  85.7   100    70
  Instagram  27.3  72.7   100    11
  Otra       10.4  89.6   100    77
  Tuenti      0.0 100.0   100     1
  Twitter     9.4  90.6   100    96
  WhatsApp    9.0  91.0   100   398
```
```R
> local({
+   .Table <- xtabs(~Red+Sexo, data=Respuestas)
+   cat("\nFrequency table:\n")
+   print(.Table)
+   cat("\nColumn percentages:\n")
+   print(colPercents(.Table))
+ })
# Statistics > Contingency tables > Two-way tables...
	# Data
		# Row variable -> Red
		# Column variable -> Sexo
	# Statistics > Compute percentages > Column percentages
```
```
Frequency table:
           Sexo
Red         Mujer Varón
  Facebook     10    60
  Instagram     3     8
  Otra          8    69
  Tuenti        0     1
  Twitter       9    87
  WhatsApp     36   362

Column percentages:
           Sexo
Red         Mujer Varón
  Facebook   15.2  10.2
  Instagram   4.5   1.4
  Otra       12.1  11.8
  Tuenti      0.0   0.2
  Twitter    13.6  14.8
  WhatsApp   54.5  61.7
  Total      99.9 100.1
  Count      66.0 587.0
```
```R
> local({
+   .Table <- xtabs(~Red+Sexo, data=Respuestas)
+   cat("\nFrequency table:\n")
+   print(.Table)
+   cat("\nTotal percentages:\n")
+   print(totPercents(.Table))
+ })
# Statistics > Contingency tables > Two-way tables...
	# Data
		# Row variable -> Red
		# Column variable -> Sexo
	# Statistics > Compute percentages > Percentages of total
```
```
Frequency table:
           Sexo
Red         Mujer Varón
  Facebook     10    60
  Instagram     3     8
  Otra          8    69
  Tuenti        0     1
  Twitter       9    87
  WhatsApp     36   362

Total percentages:
          Mujer Varón Total
Facebook    1.5   9.2  10.7
Instagram   0.5   1.2   1.7
Otra        1.2  10.6  11.8
Tuenti      0.0   0.2   0.2
Twitter     1.4  13.3  14.7
WhatsApp    5.5  55.4  60.9
Total      10.1  89.9 100.0
```

- Para estudiar el grado de relación/asociación entre las variables se puede obtener el estadístico chi-cuadrado, acotado como **formula que pandoc no coge**, siendo 0 la mínima asociación.

```R
> local({
+   .Table <- xtabs(~Red+Sexo, data=Respuestas)
+   cat("\nFrequency table:\n")
+   print(.Table)
+   .Test <- chisq.test(.Table, correct=FALSE)
+   print(.Test)
+ })
```
```
Frequency table:
           Sexo
Red         Mujer Varón
  Facebook     10    60
  Instagram     3     8
  Otra          8    69
  Tuenti        0     1
  Twitter       9    87
  WhatsApp     36   362

	Pearson's Chi-squared test

data:  .Table
X-squared = 5.5825, df = 5, p-value = 0.349
```

- Construimos una tabla de doble entreada del número de vehículo y número de miembros de la unidad familiar. ¿Influye esta segunda variable en la primera? Para determinar esto, obtenemos la distribución condicionada del número de miembros cuando las familias solamente tienen un vehículo en su lugar.

## EJERCICIO 2

Se quiere estudiar la posible asociación entre el nivel de estudios de un grupo de personas y el hábito de fumar. Las personas se han seleccionado de forma aleatoria y los datos se presentan en la tabla adjunta.

| **FUMAR / ESTUDIOS** | **PRIMARIOS** | **MEDIOS** | **SUPERIORES** |
| :---: | :---: | :---: | :---: |
| **SÍ** | 20 | 10 | 4 |
| **NO** | 16 | 12 | 2 |

- Introducimos los datos en R-Commander.
- Calculamos las distribuciones marginales.
- ¿Son dichas variables independientes?

## EJERCICIO 3

Vamos a obtener un modelo de regresión lineal para predecir el peso en función de la altura a partir de `Respuestas.RData` graficando la nube de puntos y realizando el ajuste.

### APARTADO 3.1

Creamos un diagrama de dispersión.

```R
> library(lattice, pos=17)
> xyplot(Peso ~ Altura, type="p", pch=16, auto.key=list(border=TRUE), 
+   par.settings=simpleTheme(pch=16), scales=list(x=list(relation='same'), 
+   y=list(relation='same')), data=Respuestas)
# Graphs > XY Conditioning Plot...
	# Explanatory variables -> Altura
	# Response variables -> Peso
```
# CAPTURA1

### APARTADO 3.2

Realizamos el ajuste del peso en función de la altura. Escribimos el modelo e interpretamos el coeficiente de correlación lineal y de determinación.

```R
> RegModel.1 <- lm(Peso~Altura, data=Respuestas)
> summary(RegModel.1)
# Statistics > Fit models > Lineal regression...
	# Response variable (pick one) -> Peso
	# Explanatory variables (pick one or more) -> Altura
```
```
Call:
lm(formula = Peso ~ Altura, data = Respuestas)

Residuals:
    Min      1Q  Median      3Q     Max 
-25.810  -4.937   0.107   5.041  38.190 

Coefficients:
              Estimate Std. Error t value Pr(>|t|)    
(Intercept) -100.84935    8.01134  -12.59   <2e-16 ***
Altura         0.98735    0.04521   21.84   <2e-16 ***
---
Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1

Residual standard error: 9.041 on 662 degrees of freedom
Multiple R-squared:  0.4188,	Adjusted R-squared:  0.4179 
F-statistic:   477 on 1 and 662 DF,  p-value: < 2.2e-16
```

Podemos cambiar la selección escribiendo `Sexo==Varón` o `Sexo==Mujer` en la casilla `Subset expression` del menú anterior.

Graficamos la línea de regresión cambiando los puntos por círculos con el siguiente script:

```R
plot(Respuestas$Altura, Respuestas$Peso, main="Nube de puntos y ajuste",
xlab="Altura", ylab="Peso")
abline(lm(Respuestas$Peso ~ Respuestas$Altura), col="red")
lines(lowess(Respuestas$Peso, Respuestas$Altura), col="blue")
```

Graficamos el ajuste por sexos con el siguiente script:

```R
scatterplot(Peso ~ Altura | Sexo, xlab="Altura", ylab="Peso", data=Respuestas)
```

### APARTADO 3.3