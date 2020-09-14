# INTERVALOS DE CONFIANZA

## EJERCICIO 1

### APARTADO 1.1

Calculamos un intervalo de confizanza al 95% de la `Altura` media poblacional.

```R
> with(Respuestas, (t.test(Altura, alternative='two.sided', mu=0.0, conf.level=.95)))
```
```
	One Sample t-test

data:  Altura
t = 587.34, df = 663, p-value < 2.2e-16
alternative hypothesis: true mean is not equal to 0
95 percent confidence interval:
 176.4428 177.6265
sample estimates:
mean of x 
 177.0346
```

Calculamos un intervalo de confianza al 99% de la `Altura` media poblacional.

```R
> with(Respuestas, (t.test(Altura, alternative='two.sided', mu=0.0, conf.level=.99)))
```
```
	One Sample t-test

data:  Altura
t = 587.34, df = 663, p-value < 2.2e-16
alternative hypothesis: true mean is not equal to 0
99 percent confidence interval:
 176.2560 177.8133
sample estimates:
mean of x 
 177.0346
```

### APARTADO 1.2

Filtramos el conjunto de datos activo para seleccionar sólamente a los varones y calculamos el nuevo intervalo de confianza para la `Altura`media poblacional.

```R
> Respuestas_varones <- subset(Respuestas, subset=Sexo=="Varón")
> with(Respuestas_varones, (t.test(Altura, alternative='two.sided', mu=0.0, conf.level=.95)))
```
```
	One Sample t-test

data:  Altura
t = 608.53, df = 596, p-value < 2.2e-16
alternative hypothesis: true mean is not equal to 0
95 percent confidence interval:
 177.4673 178.6165
sample estimates:
mean of x 
 178.0419
```

## EJERCICIO 2

Creamos una distribución N(0,1) a partir de una muestra aleatoria de 500 elementos.

```R
> NormalSamples <- as.data.frame(matrix(rnorm(500*1, mean=0, sd=1), ncol=1))
> rownames(NormalSamples) <- paste("sample", 1:500, sep="")
> colnames(NormalSamples) <- "obs"
```

Calculamos el intervalo de confianza para la varianza  mediante el siguiente script:

```R
> N01 <- rnorm(500,mean=0,sd=1)
> ci <- 499*sd(N01)/qchisq(0.975,499) #Para la cota inferior.
> cs <- 499*sd(N01)/qchisq(0.025,499) #Para la cota superior.
> c(ci,cs) # Para que aparezcan en la ventana de resultados.
```
```
[1] 0.9185494 1.1775678
```

## EJERCICIO 3

## EJERCICIO 4

## EJERCICIO 5

## EJERCICIO 6

Construimos un intervalo de confianza al 95% para la proporción de 