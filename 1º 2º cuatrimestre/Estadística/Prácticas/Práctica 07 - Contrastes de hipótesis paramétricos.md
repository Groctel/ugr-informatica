# CONSTRASTES DE HIPÓTESIS PARAMÉTRICOS

Copiamos `respuestas.xls` a una carpeta llamada `Práctica 07` y cambiamos el directorio de trabajo a dicha carpeta:

```shell
$ mkdir Práctica 07 && mv ~/Downloads/respuestas.xls Práctica\ 07
```
```R
setwd("/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 07")
# File > Change working directory
```

## EJERCICIO 1

### APARTADO 1.1

Importamos los datos de Excel a R-Commander mediante el Menú Datos. Los visualizamos y los guardamos como fichero Respuestas.RData.

### APARTADO 1.2

Contrastamos la hipótesis de que la altura media de los alumnos de Informática es de 185 cm a un nivel de significación del 5%.

```R
> with(Dataset, (t.test(Altura, alternative='two.sided', mu=185, conf.level=.95)))
# Statistics > Means > Single-sample t-test...
	# Variable -> Altura
	# Alternative Hypothesis
		# Population mean != mu0
		# Null hypothesis: mu = -> 185
		# Conficence Level: -> .95
```
```
	One Sample t-test

data:  Altura
t = -26.426, df = 663, p-value < 2.2e-16
alternative hypothesis: true mean is not equal to 185
95 percent confidence interval:
 176.4428 177.6265
sample estimates:
mean of x 
 177.0346 
```

Debido a que `p-value` es menor que el nivel de significación (0.5), podemos afirmar que, al 5%, de significación hay evidencia muestral suficiente para afirmar que la altura media del alumnano no es de 185cm.

### APARTADO 1.3

Contrastamos la hipótesis de que la altura media de los alumnos de Informática es inferior a 180 cm a un nivel de significación del 1%.

```R
> with(Dataset, (t.test(Altura, alternative='less', mu=180, conf.level=.99)))
# Statistics > Means > Single-sample t-test...
	# Variable -> Altura
	# Alternative Hypothesis
		# Population mean < mu0
		# Null hypothesis: mu = -> 180
		# Conficence Level: -> .99
```
```
	One Sample t-test

data:  Altura
t = -9.8381, df = 663, p-value < 2.2e-16
alternative hypothesis: true mean is less than 180
99 percent confidence interval:
     -Inf 177.7375
sample estimates:
mean of x 
 177.0346
```

Debido a que `p-value` es menor que el nivel de significación (0.1), podemos afirmar que, al 1% de significación, hay evidencia muestral suficiente de que la altura media del alumnado de informática es menor de 180cm.

### APARTADO 1.4

Contrastamos la hipótesis de que la altura media de las alumnas de Informática es inferior a la altura media de los alumnos a un nivel de significación del 5%. Para ello, comprobamos  previamente si las varianzas poblacionales son iguales en ambos grupos.

```R
> var.test(Altura ~ Sexo, alternative='two.sided', conf.level=.95, data=Dataset)
# Statistics > Variances > Two Variances F-test...
	# Data
		# Groups -> Sexo
		# Response Variable -> Altura
	# Options
		# Alternative Hypothesis -> Two-sided
		# Confidence Level: -> .95
```
```
	F test to compare two variances

data:  Altura by Sexo
F = 1.0483, num df = 66, denom df = 596, p-value = 0.7586
alternative hypothesis: true ratio of variances is not equal to 1
95 percent confidence interval:
 0.7493835 1.5460967
sample estimates:
ratio of variances 
          1.048297
```

Debido a que `p-value` es superior al nivel de signifiación, afirmamos que,  al 5% de significación, la varianza de las alturas en hombres y mujeres es la misma.

```R
> t.test(Altura~Sexo, alternative='less', conf.level=.95, var.equal=TRUE, data=Dataset)
# Statistics > Means > Independent samples T-Test...
	# Data
		# Groups -> Sexo
		# Response Variable -> Altura
	# Options
		# Difference -> Mujer - Varón
		# Alternative Hypothesis -> Difference < 0
		# Confidence Level -> .95
		# Assume equal variances? -> Yes
```
```
	Two Sample t-test

data:  Altura by Sexo
t = -10.812, df = 662, p-value < 2.2e-16
alternative hypothesis: true difference in means is less than 0
95 percent confidence interval:
      -Inf -8.461399
sample estimates:
mean in group Mujer mean in group Varón 
           168.0597            178.0419
```

Debido a que `p-value` es inferior al nivel de significación, podemos afirmar que, al 5% de significación, la estatura media de las mujeres es inferior a la estatura media de los hombres.

## EJERCICIO 2

Se desea contrastar si el número medio de hermanos en la población de mujeres es semejante al de la población masculina en Informática.

### APARTADO 2.1

```R
> var.test(n_herm ~ Sexo, alternative='two.sided', conf.level=.95, data=Dataset)
```
```
	F test to compare two variances

data:  n_herm by Sexo
F = 0.94211, num df = 66, denom df = 596, p-value = 0.7848
alternative hypothesis: true ratio of variances is not equal to 1
95 percent confidence interval:
 0.6734744 1.3894843
sample estimates:
ratio of variances 
         0.9421098 
```

si

### APARTADO 2.2

```R
> t.test(n_herm~Sexo, alternative='two.sided', conf.level=.95, var.equal=TRUE, data=Dataset)
```
```
	Two Sample t-test

data:  n_herm by Sexo
t = -0.93927, df = 662, p-value = 0.3479
alternative hypothesis: true difference in means is not equal to 0
95 percent confidence interval:
 -0.3392705  0.1197150
sample estimates:
mean in group Mujer mean in group Varón 
           2.089552            2.199330
```

si

### APARTADO 2.3

### APARTADO 2.4

## EJERCICIO 3

### APARTADO 3.1

Contrastamos la hipótesis de que la mitad de los alumnos de informática ha estudiado Estadística en alguna ocasión a un nivel de significación del 1%.

```R
> local({
+   .Table <- xtabs(~ Est_Est , data= Dataset )
+   cat("\nFrequency counts (test is for first level):\n")
+   print(.Table)
+   prop.test(rbind(.Table), alternative='two.sided', p=.5, conf.level=.99, correct=FALSE)
+ })
```
```
Frequency counts (test is for first level):
Est_Est
 No  Sí 
393 267 

	1-sample proportions test without continuity correction

data:  rbind(.Table), null probability 0.5
X-squared = 24.055, df = 1, p-value = 0.0000009364
alternative hypothesis: true p is not equal to 0.5
99 percent confidence interval:
 0.5455308 0.6434782
sample estimates:
        p 
0.5954545
```

Debido a que `p-value` es inferior al nivel del nivel de significación, podemos afirmar que, al 1% de significación, la proporcion de estudiantes que han estudiado previamente estadística no es del 50%.

### APARTADO 3.2

Contrastamos la hipótesis de que la proporción de estudiantes femeninas que han estudiado estadística es superior a la proporción de estudiantes masculinos a un nivel de significación del 5%.

```R
> library(abind, pos=16)

> local({  .Table <- xtabs(~Sexo+Est_Est, data=Dataset)
+   cat("\nPercentage table:\n")
+   print(rowPercents(.Table))
+   prop.test(.Table, alternative='greater', conf.level=.95, correct=FALSE)
+ })
```
```
Percentage table:
       Est_Est
Sexo      No   Sí Total Count
  Mujer 52.2 47.8   100    67
  Varón 60.4 39.6   100   593

	2-sample test for equality of proportions without continuity correction

data:  .Table
X-squared = 1.6527, df = 1, p-value = 0.9007
alternative hypothesis: greater
95 percent confidence interval:
 -0.1869941  1.0000000
sample estimates:
   prop 1    prop 2 
0.5223881 0.6037099
```

Debido a que `p-value` es superior al nivel de significación (0.05), podemos afirmar que, al 5% de significación, no hay evidencia muestral suficiente de que la proporción de mujeres que hayan estudiado Estadística es superior a la de hombres.

## EJERCICIO 4

Generamos dos muestras aleatorias de una distribución N(0,1) con tamaño 500.

```R
> NormalSamples <- as.data.frame(matrix(rnorm(500*2, mean=0, sd=1), ncol=2))

> rownames(NormalSamples) <- paste("sample", 1:500, sep="")

> colnames(NormalSamples) <- paste("obs", 1:2, sep="")

> editDataset(NormalSamples)

> StackedData <- stack(NormalSamples[, c("Muestra1","Muestra2")])

> names(StackedData) <- c("Datos", "Muestra")
```

Contrastamos las hipótesis de igualdad de varianzas y medias a un nivel del 5%.

Representamos los histogramas y qqPlots.