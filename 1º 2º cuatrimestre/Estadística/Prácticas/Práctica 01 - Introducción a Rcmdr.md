# INTRODUCCIÓN A RCMDR

## 1 - INSTALACIÓN

## EJERCICIO 1

Se han medido las alturas de un grupo de alumnos:

	1.75, 1.80, 1.77, 1.75, 1.71, 1.64, 1.69, 1.95, 1.75, 1.67

### APARTADO 1.1

Creamos una carpeta llamada `Práctica 1` e introducimos en ella los datos de esta variable llamada `Altura` en un fichero llamado `Ejercicio1`.

```R
> setwd("/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 1")
# File > Change working directory...
# Data > New data set...
	# Enter name for data set: -> Ejercicio1
```

### APARTADO 1.2

Guardamos el conjunto de datos activo en la carpeta `Práctica 1`.

```R
> save("Ejercicio1", 
+   file="/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 1/Ejercicio1.RData")
# Data > Active data set > Save active data set...
```

### APARTADO 1.3

Añadimos las variables `Nombre`, `Edad`, `Sexo`, `Calif` de la tabla siguiente y las introducimos en `Ejercicio1`. Es muy importante no acentuarlas.

| NOMBRE | EDAD | SEXO | CALIF |
| :---: | :---: | :---: | :---: |
| Juan | 20 | H | 6.3 |
| Salvador | 21 | H | 9.1 |
| Luis | 20 | H | 5.2 |
| José | 19 | H | 3.1 |
| Lola | 19 | M | 5.8 |
| Daniel | 18 | H | 8.6 |
| David | 20 | H | 2.2 |
| Carlos | 18 | H | 6.3 |
| Agustín | 19 | H | 9.3 |
| Maite | 19 | M | 9.5 |

Guardamos el fichero de nuevo y miramos el nombre de las variables.

```R
> save("Ejercicio1", 
+   file="/home/$USER/Ingenieria-Informatica/1º 2º cuatrimestre/Estadística/Prácticas/Práctica 1/Ejercicio1.RData")
# Data > Active data set > Save active data set...
> names(Ejercicio1)
# Data > Active data set > Variables in active data set
```
```
[1] "Altura" "Nombre" "Edad"   "Sexo"   "Calif"
```

### APARTADO 1.4

Establecemos los nombres de los casos por la variable `Nombre`. Para operaciones de este tipo, todos los casos deben ser distintos.

```R
> row.names(Ejercicio1) <- as.character(Ejercicio1$Nombre)
> Ejercicio1$Nombre <- NULL
# Data > Active data set > Set case names...
	# Select variable containing row names -> Nombre
```

### APARTADO 1.5

Filtramos el conjunto de datos para obtener un fichero que contenga a los alumnos con altura superior a **1.70**. Visualizamos el fichero y lo guardamos como `Ejercicio1b`.

```R
> Ejercicio1b <- subset(Ejercicio1, subset=Altura>1.70)
# Data > Active data set > Subset data set...
	# Include all variables -> True
	# Variables (select one or more) -> Altura
	# Subset expression -> Altura>1.70
	# Name for new data set -> Ejercicio1b
```

## EJERCICIO 2

### APARTADO 2.1

Cargamos `Ejercicio1.RData` y visualizamos su contenido.