# ESTADÍSTICA DESCRIPTIVA UNIDIMENSIONAL

En esta práctica vamos a trabajar con las siguientes variables, obtenidas de datos sobre los estudiantes de la escuela:

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

### APARTADO 1.1

Copiamos los datos `respuestas.xls` a una nueva carpeta `Práctica 3`, a la que cambiamos el directorio de trabajo.

```R
setwd("/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 03")
```

Importamos `respuestas.xls` y guardamos los datos como `Respuestas.RData`.

```R
> Respuestas <- 
+   readXL("/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 03/respuestas.xls",
+    rownames=FALSE, header=TRUE, na="", sheet="Respuestas", stringsAsFactors=TRUE)

> save("Respuestas", 
+   file="/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 03/Respuestas.RData")
```

### APARTADO 1.2

Calculamos la media, desviación típica y cuantiles de `Altura`.

```R
> numSummary(Respuestas[,"Altura", drop=FALSE], statistics=c("mean", "sd", "quantiles"), quantiles=c(0,.25,.5,
+   .75,1))
```
```
     mean       sd  0% 25% 50% 75% 100%   n
 177.0346 7.766988 155 172 177 182  200 664
```

### APARTADO 1.3

Calculamos el coeficiente de variación de `Altura` según `Sexo`. ¿Qué distribución es más homogénea?

Lo calculamos ahora según `Edad`. Para ello, convertimos dicha variable en un factor.

### APARTADO 1.4

Calculamos las frecuencias absolutas y los porcentajes o frecuencias relativas asociadas a cada modalidad de `Edad` (como factor), `Plataf` y `Red`.

### APARTADO 1.5

Calculamos la media y coeficiente de variación de `Peso`.

Obtenemos la varianza mediante el siguiente script:

```R
> var(Respuestas$Peso)
```
```
[1] 140.4345
```

### APARTADO 1.6

Calculamos el peso mínimo del 20% de los estudiantes más pesado.

```R
> numSummary(Respuestas[,"Altura", drop=FALSE], statistics=c("quantiles"), quantiles=c(.8))
```
```
  80% 
183.4
```

Obtenemos el peso máximo que debería tener un estudiante para estar dentro del 30% más ligero.

```R
> numSummary(Respuestas[,"Altura", drop=FALSE], statistics=c("quantiles"), quantiles=c(.3))
```
```
30% 
173
```

## EJERCICIO 2

