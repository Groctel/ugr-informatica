# EXPRESIONES CON VARIABLES Y EXPRESIONES REGULARES

## 0 - ÓRDENES SHELL BASH

| **bc** | **else** | **if** |
| :---: | :---: | :---: |
| **let** | **test** |

`bc` → Calcula expresiones con una precisión arbitraria
- `bc -i` → Forzar el modo interactivo
- `bc -l` → Define la biblioteca de matemáticas estándar

`else` → Ejecuta un bloque de código si la condición if anterior no se cumple

`if` → Indica la condición para que se ejecute un bloque de código

`let` → Iguala variables a expresiones aritméticas enteras

`test` → Comprueba tipos de archivo y compara valores
- `test -b [file]` → El archivo [file] existe y es un dispositivo de bloques
- `test -c [file]` → El archivo [file] existe y es un dispositivo de caracteres
- `test -d [file]` → El archivo [file] existe y es un directorio
- `test -e [file]` → El archivo [file] existe y existe
- `test -f [file]` → El archivo [file] existe y existe y es un archivo plano o regular
- `test -G [file]` → El archivo [file] existe y es propiedad del grupo del usuario
- `test -L [file]` → El archivo [file] existe y es un enlace simbólico
- `test -o [file]` → El archivo [file] existe y es propiedad del usuario
- `test -r [file]` → El archivo [file] existe y el usuario tiene permiso de lectura
- `test -s [file]` → El archivo [file] existe y no está vacío
- `test -w [file]` → El archivo [file] existe y el usuario tiene permiso de escritura
- `test -x [file]` → El archivo [file] existe y el usuario tiene permiso de ejecución
- `test [file1] -nt [file2]` → El archivo [file1] tiene fecha de modificación más reciente que el archivo [file2] o el archivo [file1] existe y el archivo [file2] no
- `test [file1] -ot [file2]` → El archivo [file1] tiene fecha de modificación más reciente que el archivo [file2]o el archivo [file1] existe no y el archivo [file2] sí
- `test [file1] -ef [file2]` → Los archivos [file1] y [file2] son enlaces que se refieren al mismo archivo

## 1 - EXPRESIONES CON VARIABLES

Bash permite manejar expresiones aritméticas mediante expansión aritmética `$(( ... ))` y sustitución aritmética `$[ ... ]`.

```
$ echo "Faltan $(( (356 - $(date +%j)) / 7 )) semanas hasta fin de año"
  Faltan 7 semanas hasta fin de año
```

### 1.1 - OPERADORES ARITMÉTICOS

| OPERADOR | DESCRIPCIÓN |
| :---: | --- |
| `+` `-` | Suma y resta / + unario y - unario. |
| `*` `/` `%` | Multiplicación, división entera y resto de la división entera. |
| `**` | Potencia (elevado a). |
| `++` `--` | Incremento o decremento en una unidad. |
| `( )` | Agrupación de operaciones. |
| `'` | Separador entre expresiones con evaluación secuencial. |
| `=` | Asignación de una expresión a una variable (sin espacios vacíos). |
| `+=` `-=` `*=` `/=` `%=` | Asignación a una variable de la suma, resta, producto, cociente o resto de ella misma con la expresión del lado de la asignación (sin espacios vacíos). |

Al utilizar las expresiones de incremento y decremento en una unidad es importante tener en cuenta el orden de evaluación y asignación de la variable en función de su posición.

```
$ var=1
$ echo $((var++))
  1
$ echo $((var))
  2
$ echo $((++var))
  3
$ echo $((var))
  3
$ echo $((var--))
  3
$ echo $((var))
  2
$ echo $((--var))
  1
$ echo $((var))
  1
```

Por defecto, bash muestra los resultados de las operaciones como números enteros. Para poder mostrarlos con decimales encauzamos la orden `bc -l`.

```
$ echo 6/5
  6/5
$ echo 6/5|bc
  1
$ echo 6/5|bc -l
  1.20000000000000000000
```

### 1.2 - ASIGNACIÓN Y VARIABLES ARITMÉTICAS

Para asignar variables a expresiones aritméticas usamos la orden `let` (que es el equivalente inglés a la expresión *se tiene que*) con la misma sintaxis que declare o la asignación plana.

    $ let w=3+2
    $ let w='3 + 2'
    $ let w='(4+5)*6'
    $ let w=4+5*6
    $ y=7
    $ let w=y%5

Al igual que con la expansión y sustitución aritmética, no hace falta incluir el símbolo `$` antes del nombre de una variable, pues se sobreentiende que las estamos usando.

La orden `let` también sirve como alternativa a la sustitución aritmética, permitiendo usarla en scripts indistintamente.

```
$ a=10
$ ((a<10))
$ echo $?
  1
$ ((a==10))
$ echo $?
  0
$ if let 'a<10'; then echo “es menor”; else echo “es mayor o igual”; fi
  es mayor o igual
```

### 1.3 - OPERADORES RELACIONALES

A la hora de trabajar con expresiones, pueden interpretarse como verdaderas o falsas (lógica booleana). Si una expresión es verdadera vale `1` y si es falsa vale `0`. Es el caso contrario a la orden `$?`, que evalúa verdadero o falso según si se ha producido un error o no.

| OPERADOR | DESCRIPCIÓN (CASO TRUE)|
| :---: | --- |
| `A = B` `A == B` `A -eq B` | A es igual a B. |
| `A != B` `A -ne B` | A es distinto de B. |
| `A < B` `A -lt B` | A es menor que B. |
| `A > B` `A -gt B` | A es mayor que B. |
| `A <= B` `A -le B` | A es menor o igual que B. |
| `A >= B` `A -ge B` | A es mayor o igual que B. |
| `! A` | Contrario de A. |
| `A && B` | A y B son verdaderas. |
| `A \|\| B` | A, B o ambas son verdaderas. |

Para evaluar una expresión la introducimos entre corchetes. Es muy importante tener en cuenta que una serie de evaluaciones encadenadas deberán ir encerradas en un corchete global.

```
$ echo $[8>3] and $[9<5]
  1 and 0
$ echo $[$[8>3]&&$[9<5]]
  0
```

### 1.4 - OPERADORES DE CONSULTA DE ARCHIVOS

Para realizar comprobaciones booleanas usamos la orden `test`, que equivale a la expresión `[ ... ]`, haciendo especial hincapié en los espacios que separan los corchetes de la expresión. La orden `test` no imprime el resultado en pantalla, sino que evalúa internamente a `true` o `false` en la forma de “se ha producido o no un error”, por lo que debe comprobarse con la orden `$?`.

```
$ echo $?
  0
$ [ -w /bin ]
$ echo $?
  1
```

También puede asignarse su resultado a una variable, aunque debe definirse la forma de expresión de dicho resultado.

```
$ ls -l ejemplo
  -rw-r--r-- 1 groctel groctel 0 Nov  1 18:25 ejemplo
$ xacceso=`test -x ejemplo && echo "true" || echo "false"`
$ echo "$xacceso"
  false
$ wacceso=`test -w ejemplo && echo "true" || echo "false"`
$ echo "$wacceso"
  True
```

También se pueden evaluar varias expresiones mediante los operadores `!` (not), `-a` (and) y `-o` (or inclusivo).

### 1.5 - LA ORDEN IF / ELSE

La orden `if / else` permite ejecutar sentencias si las condiciones de ejecución especificadas son verdaderas. Al igual que en otros lenguajes, los `if` se pueden anidar con la siguiente estructura (cuya indentación es meramente estética e innecesaria):

```shell
if (condition); then
   sentence
elif (condition);
   if (condition); then
      sentence
   else sentence
else sentence
fi
```

Las condiciones que evalúan los `if` en bash son órdenes que basan su propiedad booleana en estado de ejecución legible mediante `$?`, anteriormente descrito.

```
$ valor=0
$ ((valor == 3)) && echo "si" || echo "no"
  no
$ ((valor = 3)) && echo "si" || echo "no"
  si
$ if [ valor == 3 ]; then echo "si"; else echo "no"; fi
  si
```

### 1.6 - COMPARACIONES ARITMÉTICAS

A la hora de realizar comparaciones aritméticas en un `if` se pueden utilizar los símbolos de la tabla del punto 1.3. Las comparaciones aritméticas se pueden declarar con `[ ... ]` y `(( ... ))`. La principal diferencia es que con `(( ... ))` no se pueden utilizar los comparadores precedidos de `-` y obliga a usar el operador de igualdad `==`. Por este motivo, la segunda línea del ejemplo anterior asigna `3` a `valor` en lugar de comprobarlo, por lo que la comprobación de la tercera línea devuelve `true`.

### 1.7 - COMPARACIONES ENTRE CADENAS DE CARACTERES

Para comparar cadenas de caracteres se pueden usar los operadores `==` y `!=` para indicar si las cadenas son iguales o no y los operadores `\<` y `\>` (se necesitan declarar con caracteres de escape dentro de `[ ... ]`) para comprobar si una cadena precede o sucede a la otra.

```
$ if [ "hola" == "adios" ]; then echo "sí"; else echo "no";fi
  no
$ if [ "hola" != "adios" ]; then echo "sí"; else echo "no";fi
  sí
$ if [ "hola" \< "adios" ]; then echo "sí"; else echo "no";fi
  no
$ if [ "hola" \> "adios" ]; then echo "sí"; else echo "no";fi
  Sí
```

Si el contenido de una variable es una cadena de caracteres con espacios en blanco, la variable debe declararse con acotación débil.

```
$ if [ "$hola" = "Hola tú" ]; then echo sí; else echo no; fi
  sí
```

### 1.8 - COMPARACIONES USANDO ÓRDENES

Si la condición de un `if` no está protegida por `[ ... ]`, se pueden ejecutar órdenes mientras se evalúan y los bloques se ejecutarán según si las órdenes se han ejecutado satisfactoriamente o no.

```
$ if ls -m > salida; then echo sí; else echo no; fi
  sí
$ cat salida
  acotados, adios, archivour, args, cola, ejemplo, ejercicio1, fs, hola, holamundo, holi, holo, lslargo, numE, permisos, pola, salida
$ if rm salida; then echo sí; else echo no; fi 2> sal
  sí
$ if rm salida; then echo sí; else echo no; fi 2> sal
  no
$ cat sal
  rm: cannot remove 'salida': No such file or directory
```

También podemos usar la orden test dentro de un if.

## 2 - EXPRESIONES REGULARES

Las expresiones regulares son patrones que describen conjuntos de cadenas de caracteres y que pueden utilizarse para realizar búsquedas en un archivo. Por regla general, las letras son expresiones regulares que se refieren a sí mismos. Para representar el carácter `*` hay que acotarlo fuertemente (`'*'`). La barra de escape `\`, que se utiliza para modificar el siguiente, se debe usar para los caracteres `\(`, `\)`, `\?`, `\*`, `\{`, `\}`, `\+` y `\|`.

### 2.1 - PATRONES EN EXPRESIONES REGULARES

Las expresiones regulares están formadas por patrones que pueden concatenarse. Al concatenar varias cadenas, la expresión equivale a cualquier cadena formada por las subcadenas concatenadas. Por defecto, las reglas de precedencia indican que primero se trata la repetición, luego la concatenación y después la alternación, aunque el uso de paréntesis permite considerar subexpresiones y cambiar esas reglas.

### 2.2 - EXPRESIONES REGULARES CON ÓRDENES DE BÚSQUEDA

| &nbsp;PATRÓN&nbsp; | DESCRIPCIÓN |
| :---: | --- |
| `\` | La barra de escape. Para referenciarla se escribe como `\\`. |
| `.` | Cualquier carácter en su posición. Usado solo representa cualquier cadena. Para referenciarlo se escribe como `\.`. |
| `\( \)` | Un grupo de caracteres considerados como uno sólo. |
| `\?` | Indica que el carácter o el grupo al que sucede puede aparecer una vez o ninguna. |
| `*` | Indica que el carácter o el grupo al que sucede puede no aparecer ninguna vez o varias veces seguidas. |
| `+` | Indica que el carácter o el grupo al que sucede debe aparecer una o más veces seguidas. |
| `\{n\}` | Indica que el carácter o el grupo al que sucede debe aparecer n veces. |
| `\{n,\}` | Indica que el carácter o el grupo al que sucede debe aparecer n o más veces seguidas. |
| `\{n,m\}` | Indica que el carácter o el grupo al que sucede debe aparecer entre n y m (ambas inclusive) veces seguidas. |
| `[ ]` | Una lista de caracteres que se tratan uno a uno como caracteres simples. Si el primer carácter de la lista es `^`, representa a cualquier carácter que no esté en esa lista. |
| `-` | Un rango de caracteres si no está al inicio o al final de la lista. Si está al principio o al final se considera como él mismo. Se pueden declarar rangos absolutos (`[a-e]`) o parciales (`[m-]`, que es equivalente a `(m-z)` o `[-m]`, que es equivalente a `(a-m)`). |
| `^` | Indica el inicio de una línea y filtra aquellas que comiencen por un carácter que le suceda. |
| `$` | Indica el inicio de una línea y filtra aquellas que comiencen por un carácter que le preceda. |
| `\b` | El final de una palabra (acotado fuerte o débilmente).       |
| `\B`| Que no está al final de una palabra (acotado fuerte o débilmente). |
| `\<` | El inicio de una palabra (acotado fuerte o débilmente).      |
| `\>` | El final de una palabra (acotado fuerte o débilmente).       |
| `\|` | Operador OR inclusivo que une expresiones regulares.         |

### 2.3 - EJEMPLOS DE UTILIZACIÓN DE EXPRESIONES REGULARES

Buscar en el directorio `/bin/usr` los archivos cuyo nombre comience con las letras `a` o `z` y acabe con la letra `m`:

    $ find /usr/bin -name "[az]*m"

Buscar en el directorio `/etc` los archivos de configuración que contengan la palabra `dev`:

    $ find /etc -name *dev*.conf”

Localizar en el directorio `/usr/bin` los nombres de archivos que contengan las letras `cd` o `zip`:

    $ find /usr/bin -regex '.*\(cd\|zip\).*'
    $ find /usr/bin -regex '.*cd.*' -o -regex '.*zip.*'

Buscar en el archivo /etc/group las líneas que contengan un carácter `k`, `y` o `z`:

    $ grep [kyz] /etc/group
    $ cat /etc/group | grep [kyz]

El siguiente ejemplo permite añadir a la variable `$PATH` un directorio que se pase como primer argumento del script; si se da la opción after como segundo argumento del script, el directorio se añadirá al final de la variable `$PATH`, en cualquier otro caso el directorio se añadirá al principio de `$PATH`:

###### nuevopath
```shell
#!/bin/bash

if ! echo $PATH | /bin/egrep -q "(^|:)$1($|:)" ; then
   if [ "$2" = "after" ] ; then
      PATH=$PATH:$1
   else
      PATH=$1:$PATH
   fi
else
   echo "$1 ya está en el path"
fi
```

## 3 - EJERCICIOS

### EJERCICIO 1

Utilizando una variable que contenga el valor entero 365 y otra que guarde el número del día actual del año en curso, realice la misma operación del ejemplo anterior usando cada una de las diversas formas de cálculo comentadas hasta el momento, es decir, utilizando `expr`, `$(( ... ))` y `$[ ... ]`.

### EJERCICIO 2

Utilizando el operador de división, ponga un caso concreto donde se aprecie que la asignación abreviada es equivalente a la asignación completa, es decir, que `x /= y` equivale a `x = x / y`.

### EJERCICIO 3

Compruebe qué ocurre si en el ejemplo siguiente utiliza comillas dobles o simples para acotar todo lo que sigue a la orden `echo`. ¿Qué sucede si se acota entre comillas dobles solamente la expresión aritmética que se quiere calcular?. ¿Y si se usan comillas simples?

    $ echo 6/5 | bc -l

### EJERCICIO 4

Calcule con decimales el resultado de la expresión aritmética `(3 - 2) / 5`. Escriba todas las expresiones que haya probado hasta dar con una respuesta válida. Utilizando una solución válida, compruebe qué sucede cuando la expresión aritmética se acota entre comillas dobles; ¿qué ocurre si se usan comillas simples?. ¿Y si se ponen apóstrofos inversos?

### EJERCICIO 5

Con la orden `let` es posible realizar asignaciones múltiples y utilizar operadores que nosotros no hemos mencionado anteriormente. Ponga un ejemplo de asignación múltiple y, por otra parte, copie en un archivo el orden en el que se evalúan los operadores que admite. Apóyese a través de la ayuda que ofrece `help let`.

### EJERCICIO 6

Pruebe los siguientes ejemplos y escriba los resultados obtenidos con la evaluación de expresiones (Los ejemplos están copiados en la solución).

### EJERCICIO 7

Haciendo uso de las órdenes conocidas hasta el momento, construya un script que admita dos parámetros, que compare por separado si el primer parámetro que se le pasa es igual al segundo, o es menor, o es mayor, y que informe tanto del valor de cada uno de los parámetros como del resultado de cada una de las evaluaciones mostrando un `0` o un `1` según corresponda.

### EJERCICIO 8

Usando test, construya un script que admita como parámetro un nombre de archivo y realice las siguientes acciones: asignar a una variable el resultado de comprobar si el archivo dado como parámetro es plano y tiene permiso de ejecución sobre él; asignar a otra variable el resultado de comprobar si el archivo es un enlace simbólico; mostrar el valor de las dos variables anteriores con un mensaje que aclare su significado. Pruebe el script ejecutándolo con /bin/cat y también con /bin/rnano.

### EJERCICIO 9

Responda a los siguientes apartados:
- Razone qué hace la siguiente orden:
    $ if test -f ./sesion5.pdf ; then printf “El archivo ./sesion5.pdf existe\n”; fi
- Añada los cambios necesarios en la orden anterior para que también muestre un mensaje de aviso en caso de no existir el archivo. (Recuerde que, para escribir de forma legible una orden que ocupe más de una línea, puede utilizar el carácter `\` como final de cada línea que no sea la última.)
- Sobre la solución anterior, añada un bloque `elif` para que, cuando no exista el archivo `./sesion5.pdf`, compruebe si el archivo `/bin` es un directorio. Ponga los mensajes adecuados para conocer el resultado en cada caso posible.
- Usando como base la solución del apartado anterior, construya un script que sea capaz de hacer lo mismo pero admitiendo como parámetros la ruta relativa del primer archivo a buscar y la ruta absoluta del segundo. Pruébelo con los dos archivos del apartado anterior.

### EJERCICIO 10

Construya un script que admita como argumento el nombre de un archivo o directorio y que permita saber si somos el propietario del archivo y si tenemos permiso de lectura sobre él.

### EJERCICIO 11

Escriba un script que calcule si el número de días que faltan hasta fin de año es múltiplo de cinco o no, y que comunique el resultado de la evaluación. Modifique el script anterior para que admita la opción `-h` de manera que, al ejecutarlo con esa opción, muestre información de para qué sirve el script y cómo debe ejecutarse. El siguiente script de ejemplo se puede utilizar para borrar el archivo temporal que se le dé como argumento. Si `rm` devuelve `0`, se muestra el mensaje de confirmación del borrado; en caso contrario, se muestra el código de error. Como se puede apreciar, hemos utilizado la variable `$LINENO` que indica la línea actualmente en ejecución dentro del script.

### EJERCICIO 12

¿Qué pasa en el siguiente ejemplo si eliminamos la redirección de la orden if?

###### ej12
```shell
#!/bin/bash

declare -rx SCRIPT=${0##*/} 

if rm ${1} ; then
   printf "%s\n" "$SCRIPT: archivo temporal borrado"
else
   STATUS=177
   printf "%s – código de finalizacion %d\n" "$SCRIPT:$LINENO no es posible borrar archivo" $STATUS
fi 2> /dev/null
```

`SCRIPT` contiene sólo el nombre del script. `${var##[PATRÓN]}` actúa eliminando de `$var` aquella parte que cumpla de `$[PATRÓN]` desde el principio de `$var`. En este caso: elimina todo lo que precede al último slash (`/`).

### EJERCICIO 13

Haciendo uso del mecanismo de cauces y de la orden `echo`, construya un script que admita un argumento y que informe si el argumento dado es una única letra, en mayúsculas o en minúsculas, o es algo distinto de una única letra.

### EJERCICIO 14

Haciendo uso de expresiones regulares, escriba una orden que permita buscar en el árbol de directorios los nombres de los archivos que contengan al menos un dígito y la letra `e` ¿Cómo sería la orden si quisiéramos obtener los nombres de los archivos que tengan la letra `e` y no contengan ni el `0` ni el `1`?

## 4 - SOLUCIONES

### EJERCICIO 1

```
$ declare -i dias_anio=365
$ declare -i dia_actual=$(date +%j)
$ echo "Faltan $(( (dias_anio - dia_actual) / 7)) semanas hasta fin de año"
  Faltan 8 semanas hasta fin de año
$ echo "Faltan $[(dias_anio - dia_actual) / 7] semanas hasta fin de año"
  Faltan 8 semanas hasta fin de año
```

### EJERCICIO 2

```
$ declare -i x=10
$ declare -i y=2
$ echo $[x/=y]
  5
$ declare -i x=10
$ declare -i y=2
$ echo $[x=x/y]
  5
```

### EJERCICIO 3

```
$ echo 6/5 | bc -l
  1.20000000000000000000
$ echo "6/5 | bc -l"
  6/5 | bc -l
$ echo '6/5 | bc -l'
  6/5 | bc -l
$ echo "6/5" | bc -l
  1.20000000000000000000
$ echo '6/5' | bc -l
  1.20000000000000000000
```

Las comillas dobles y simples protegen la expresión completa, pero si pasamos una expresión protegida sin caracteres a proteger como entrada para una orden encauzada, se lee como un argumento normal.

### EJERCICIO 4

```
$ echo "(3-2)/5" | bc -l
  .20000000000000000000
$ echo '(3-2)/5' | bc -l
  .20000000000000000000
$ echo `(3-2)/5` | bc -l
  bash: command substitution: line 1: syntax error near unexpected token `/5'
  bash: command substitution: line 1: `(3-2)/5'
```

### EJERCICIO 5

```
$ let a=1,b=2
$ echo "a vale $a y b vale $b"
  a vale 1 y b vale 2
```

### EJERCICIO 6

```
$ valor=6
$ if [ $valor = 3 ]; then echo si; else echo no; fi
  no
```

```
$ valor=5
$ if [ $valor = 3 ] && ls; then echo si; else echo no; fi
  no
```

```
$ valor=5
$ if [ $valor = 5 ] && ls; then echo si; else echo no; fi
  Desktop        Templates
  Documents      Pictures
  Downloads      Public
  Music          Videos
  si
```

```
$ valor=6
$ if ((valor==3)); then echo si; else echo no; fi
  no
```

```
$ valor=5
$ if ((valor==3)) && ls; then echo si; else echo no; fi
  si
```

```
$ valor=5
$ if ((valor==5)) && ls; then echo si; else echo no; fi
  Desktop        Templates
  Documents      Pictures
  Downloads      Public
  Music          Videos
  si
```

```
$ echo $((3>5))
$ echo $?
  0
```

```
$ ((3>5))
$ echo $?
  1
```

```
$ if ((3>5)); then echo 3 es mayor que 5; else echo 3 no es mayor que 5; fi
  3 no es mayor que 5
```

### EJERCICIO 7

###### mayormenoroigual
```shell
#!/bin/bash

let igual="$1 == $2"
let mayor="$1 > $2"
let menor="$1 < $2"

printf "%d es igual que %d: %d\n" $1 $2 $igual
printf "%d es mayor que %d: %d\n" $1 $2 $mayor
printf "%d es menor que %d: %d\n" $1 $2 $menor
```

```
$ ./mayormenoroigual 1 1
  1 es igual que 1: 1
  1 es mayor que 1: 0
  1 es menor que 1: 0
$ ./mayormenoroigual 2 1
  2 es igual que 1: 0
  2 es mayor que 1: 1
  2 es menor que 1: 0
$ ./mayormenoroigual 1 2
  1 es igual que 2: 0
  1 es mayor que 2: 0
  1 es menor que 2: 1
```

### EJERCICIO 8

###### permisos
```shell
#!/bin/bash

es_plano_ux=`(test -x $1 && test -f $1) && echo "es" || echo "no es"`
es_enlace=`test -h $1 && echo "es" || echo "no es"`
echo "El archivo $1 $es_plano_ux un archivo plano ejecutable"
echo "El archivo $1 $es_enlace un enlace simbólico"
```

```
$ ./permisos /bin/cat
  El archivo /bin/cat es un archivo plano ejecutable
  El archivo /bin/cat no es un enlace simbólico
$ ./permisos /bin/rnano
  El archivo /bin/rnano es un archivo plano ejecutable
  El archivo /bin/rnano es un enlace simbólico
```

### EJERCICIO 9

    $ if test -f ./sesion5.pdf; then printf "El archivo ./sesion5.pdf existe\n"; fi

No hace nada porque el archivo no existe y no hay un mensaje especificado para ese caso.

```
$ if test -f ./sesion5.pdf; then printf "El archivo ./sesion5.pdf existe\n"; else printf "El archivo ./sesion5.pdf no existe\n"; fi
  El archivo ./sesion5.pdf no existe
```

Lo del símbolo `\` está muy chuli pero lo podrían haber puesto antes, la verdad. A estas alturas de la película que ya nos hemos acostumbrado a que las órdenes se inicializan con $ se va a poner a cambiar toda la sintaxis y supuma.

```
$ if test -f ./sesion5.pdf; then printf "El archivo ./sesion5.pdf existe\n"; elif test -d /bin; then printf "El archivo /bin es un directorio\n"; else printf "El archivo ./sesion5.pdf no existe y /bin no es un directorio (wtf)\n"; fi
  El archivo /bin es un directorio
```

###### pdfbin
```shell
if [ -f $1 ]; then
   printf "El archivo $1 existe\n";
elif [ -d $2 ]; then
   printf "El archivo $1 no existe pero $2 es un directorio\n";
else
   printf "El archivo $1 no existe ni $2 es un directorio\n";
fi
```

### EJERCICIO 10 

###### archivour
```shell
#!/bin/bash

if [ -O $1 ]; then
   printf "Usted es el propietario de $1\n";
else
   printf "Usted no es el propietario de $1\n";
fi

if [ -r $1 ]; then
   printf "Usted tiene permiso de lectura sobre $1\n";
else
   printf "Usted no tiene permiso de lectura sobre $1\n";
fi
```

### EJERCICIO 11

###### diasmult5
```shell
#!/bin/bash

if [ "$1" == "-h" ]; then
   echo "Este programa comprueba si el número de días restantes para fin de año es múltiplo de 5."
   echo "Para ejecutarlo simplemente ejecute ./diasmultiplo";
else
   dias_restantes=$[365 -$(date +%j)]
   echo "Quedan $dias_restantes días para el fin de año."
   
   if [ $[dias_restantes % 5] == 0 ]; then
      echo "Y $dias_restantes es múltiplo de 5!";
   else
      echo "Pero $dias_restantes no es múltiplo de 5";
   fi
fi
```

### EJERCICIO 12

Al borrar la redirección del error, éste se imprimiría en la terminal en lugar de irse a mejor gloria en `/dev/null`.

### EJERCICIO 13

###### regex1
```shell
#!/bin/bash

if  echo $1 | grep '^[a-Z]\{1\}$' 2> /dev/null ; then
   echo "Es una única letra";
else
   echo "Es algo distinto de una única letra";
fi 2> /dev/null
```

### EJERCICIO 14