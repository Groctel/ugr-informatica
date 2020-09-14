# SISTEMA DE CÓMPUTO

## 1 - COMPONENTES DE UN SISTEMA DE CÓMPUTO

### 1.1 - DEFINICIONES BÁSICAS
- **Informática:** Conjunto de conocimientos científicos y técnicos que hacen posible el tratamiento automático de la información por medio de ordenadores
- **Computador, computadora u ordenador:** Máquina capaz de aceptar unos datos de entrada, efectuar con ellos operaciones lógicas y aritméticas y proporcionar la información resultante a través de un medio de salida: todo ello sin intervención de un operador humano y bajo el control de un programa de instrucciones previamente almacenado en el sistema. Sistema cuyas salidas o resultados dependen de sus entradas, constituidas por datos e instrucciones.
- **Operaciones lógicas:** Funciones tales como comparar, ordenar, seleccionar o copiar símbolos tanto numéricos como no.
- **Calculadora:** Máquina capaz de efectuar operaciones aritméticas bajo el control directo del usuario. No es un computador ya que no enlaza automáticamente las operaciones que efectúa ni realiza operaciones de tipo lógico, ya que sólo actúa con datos numéricos.
- **Ciencia e ingeniería de los computadores:** Campo de conocimiento que abarca el diseño y uso de los computadores.
- **Grafismo:** Carácter.
- **Codificación:** Transformación que representa los elementos de un conjunto mediante los de otro de tal forma que a cada elemento del primero le corresponda un elemento del segundo.
- **Lenguaje de programación:** Lenguaje formal estructurado que abarca una serie de instrucciones usadas para producir varios tipos de salida de datos.
- **Lenguaje de programación de alto nivel:** Instrucciones legibles por un humano que el ordenador debe compilar para poder ejecutarlas.
- **Lenguaje máquina:** Instrucciones que el computador comprende y ejecuta.
- **Lenguaje ensamblador:** Instrucciones de lenguaje máquina traducidas a un formato legible por un humano.

### 1.2 - EL BIT - BINARY DIGIT

Es la unidad mínima de información que puede representar un computador. Cada bit individual puede representar dos estados: Encendido `1` y Apagado `0`. La combinación de bits permite la representación de elementos que tengan más de dos estados (como una tabla de caracteres). Una agrupación de 8 bits se conoce comúnmente como un **byte**.

#### CÁLCULOS DE ELEMENTOS Y BITS

|**Nº de elementos representables = 2nº de bits**|
|:----:|
|**Nº de bits necesarios = Log2 nº de elementos**|

#### MÚLTIPLOS DE BITS

|PREFIJO|SÍMBOLO|FACTOR DECIMAL|FACTOR BINARIO|
|:---:|:---:|:---:|:---:|
|Kilo-|k-|10001 = 103|10241 = 210|
|Mega-|M-|10002 = 106|10242 = 220|
|Giga-|G-|10003 = 109|10243 = 230|
|Tera-|T-|10004 = 1012|10244 = 240|
|1Peta-|P-|10005 = 1015|10245 = 250|
|Exa-|E-|10006 = 1018|10246 = 260|
|Zetta-|Z-|10007 = 1021|10247 = 270|
|Yotta-|Y-|10008 = 1024|10248 = 280|

#### CONVERSIÓN DE BINARIO A DECIMAL

Empezando desde el `1` por el dígito más a la derecha, se va multiplicando por `2` a cada salto a la izquierda. Si el valor es `1`, se suma su posición. si es `0`, no.

```c
100101 = 25 + 0 + 0 + 22 + 0 + 20 = 32 + 4 + 1 = 37
```

#### CONVERSIÓN DE DECIMAL A BINARIO:

Se divide recursivamente el número entre `2` y se leen los restos en orden inverso.

```c
53 / 2 = 26   53 % 2 = 1
26 / 2 = 13   26 % 2 = 0
 13 / 2 = 6   13 % 2 = 1
  6 / 2 = 3   6 % 2 = 0
  3 / 2 = 1   3 % 2 = 1
  1 / 2 = 0   1 % 2 = 1
        53  =  110101
```
### 1.3 - INSTRUCCIONES VS DATOS

Una **instrucción** es un conjunto de símbolos insertados en una secuencia estructurada o específica que el procesador interpreta y ejecuta.

Un **dato** es un conjunto de símbolos utilizado para expresar o representar un valor numérico, un hecho, un objeto o una idea de forma adecuada para ser objeto de tratamiento, es decir, un elemento de información que procesa o genera un programa.

Ambos se representan mediante código binario, ya que es el único lenguaje que puede comprender un procesador. Es por esto que es necesario saber distinguir si una palabra en memoria es una instrucción o un dato antes de procesarla.

- **Instrucción en lenguaje natural:** Suma lo que hay en `A` con lo que tiene la posición `17` de una secuencia de valores
- **Instrucción en lenguaje de alto nivel:** `a = a + mem[17];`
- **Instrucción en lenguaje ensamblador:** `ADD A, M[17]`
- **Instrucción en lenguaje máquina:** `11000 001 0001 010001`

### 1.4 - ESTRUCTURA DE UN COMPUTADOR

![img](https://i.imgur.com/F6u0Bw1.png)

El **hardware** es el soporte físico que contiene los circuitos y componentes necesarios para la computación de datos.

El **firmware** está formado por instrucciones en lenguaje máquina para propósitos específicos del sistema en el que se aplican grabadas en una memoria, normalmente de sólo lectura, que establecen la lógica de más bajo nivel que controla los circuitos electrónicos de cualquier tipo.

El **sistema operativo** es el conjunto de programas del sistema que gestiona los recursos del hardware y permite la ejecución del resto del software, ejecutándose en modo privilegiado con respecto a los restantes.

El **software** es el conjunto de programas, instrucciones y reglas informáticas que permiten ejecutar distintas tareas en un computador.

## 2 - LA CAPA HARDWARE

### 2.1 - ARQUITECTURA DE UN SISTEMA

![img](https://i.imgur.com/rlhra6z.png)

La **placa base** es el órgano principal del ordenador. Sirve como centro de conexión entre el procesador, la memoria RAM, las ranuras de expansión y otros dispositivos de E/S que se le puedan instalar al ordenador. No se considera que un ordenador es nuevo por mucho que se cambien sus piezas hasta que se reemplace la placa base.

El **procesador** es el encargado de ejecutar todos los programas del sistema en todas sus capas. Trabaja sólo con las órdenes disponibles a bajo nivel que tenga programadas (operaciones aritméticas y lógicas simples) que pueda procesar con la Unidad Aritmético-Lógica (**ALU**) y la capacidad de sus registros.

### 2.2 - REGISTROS DEL PROCESADOR

- **Registros básicos de control y estado:** Usados por el procesador para controlar su operación y por rutinas privilegiadas del SO para controlar la ejecución de programas.
  - **IR Registro de instrucción:** Contiene la última instrucción leída.
  - **PC Contador de programa:** Contiene la dirección de la próxima instrucción que se leerá de la memoria.
  - **PSW Registro o palabra de estado:** Usado por el procesador para controlar su operación y por rutinas privilegiadas del SO para controlar la ejecución de programas.
  - **SP Puntero de pila:** Contiene la dirección de la instrucción superior de la pila.
- **Registros de propósito general:** Usados en operaciones aritméticas y lógicas. Están formados por cuatro registros (`A`, `B`, `C` y `D`) que pueden leerse en la totalidad de sus 32 bits (`EAX`, `EBX`, `ECX` y `EDX`), en sus 16 primeros bits (`AX`, `BX`, `CX` y `DX`) o sólo en sus 8 primeros (`AL`, `BL`, `CL` y `DL`). También es posible dividir en dos los primeros 16 bits de los registros para tener dos registros de 8 bits (`AH`, `AL`, `BH`, `BL`, `CH`, `CL`, `DH`, `DL`). Cada registro tiene una función específica:
  - `AX` **accumulator:** Se utiliza como E/S en la mayoría de operaciones aritméticas.
  - `BX` **base:** Es el único que se puede usar para direccionamiento indirecto. Por ejemplo, `MOV [BX]`, `AX` mueve el dato de `AX` a la dirección que contenga `BX` en ese momento.
  - `CX` **counter:** Registra el contador de bucles en las operaciones iterativas.
  - `DX` **data:** Se utiliza en las operaciones E/S y trabaja con `AX` para realizar multiplicaciones y divisiones de valores muy grandes.

### 2.3 - EJECUCIÓN DE INSTRUCCIONES

El **procesamiento de instrucciones** consta de dos pasos:
- El procesador lee instrucciones de la memoria de una en una
- El procesador ejecuta cada instrucción

El **ciclo de instrucción** es el procesamiento requerido por una única instrucción.

La **ejecución de un programa** consiste en repetir el proceso de búsqueda y ejecución de instrucciones hasta llegar al final. Estructuralmente, el proceso es el siguiente:
- Se lee la instrucción cuya dirección está en el `PC`
- Se incrementa el `PC` en una unidad
- Se ejecuta la instrucción
- Vuelta al inicio del ciclo

### 2.4 - REPERTORIO ELEMENTAL DE INSTRUCCIONES

- **Transferencia de datos**
  - `MOV SRC,DST` Mueve el contenido de la dirección fuente `SRC` a la dirección destino `DST`.
- **Aritmético-Lógicas**
  - `ADD OP1,OP2,DST` Suma el contenido de los operadores `OP1` y `OP2` y los almacena en la dirección destino `DST`.
  - `COMP SRC,DST` Compara el contenido de la dirección fuente `SRC`, que puede ser un dato constante, un registro o una palabra en memoria, y la dirección destino `DST`, que puede ser un registro o una palabra en memoria, y cambia el bit de estado a `0` si es `false` y `1` si es `true`.
  - `MULT OP1,OP2,DST` Multiplica el contenido de los operadores `OP1` y `OP2` y lo almacena en la dirección destino `DST`.
- **Entrada/Salida**
  - `IN PRT,DST` Toma una palabra de entrada del puerto `PRT` y lo almacena en la dirección destino DST.
  - `OUT SRC,PRT` Toma una palabra de salida de la fuente `SRC` y lo envía al puerto `PRT`.
- **Control**
  - `CALL TAG` Iguala el valor del contador de programa a la posición de memoria en la que está declarada la función `TAG`.
  - `JUMP MEM` → Iguala el valor del contador de programa a la posición de memoria MEM.
   - `JE TAG` Si el registro de estado es 0, salta a la dirección de memoria o función `TAG`.
  - `JNE TAG` Si el registro de estado es distinto de 0, salta a la dirección de memoria o función TAG.
  - `HALT` Cesa la ejecución de instrucciones.

**Ejemplo: Sumar dos números cargados en las direcciones de memoria DR1 y DR2 y guardar el resultado en la dirección de memoria DR3:**

```assembly
MOV DR1, R0
MOV DR2, R1
ADD R0, R1, R2
MOV R2, DR3
HALT
```

### 2.5 - TÉCNICAS DE COMUNICACIÓN DE E/S

Existen tres técnicas para manejar operaciones de E/S:
- **E/S programada:** El procesador encuentra una instrucción de E/S y genera un mandato al módulo E/S apropiado, adoptando un papel activo en la instrucción y comprobando periódicamente su estado hasta su finalización
  - **Problema:** El procesador pasa mucho tiempo esperando a la finalización del módulo en el que podría continuar realizando trabajo útil
- **E/S dirigida por interrupciones:** El procesador genera un mandato de E/S para un módulo y sigue realizando trabajo útil hasta que recibe una interrupción del módulo para que ejecute la transferencia de datos y luego seguir trabajando
  - **Problema:** En transferencias de gran tamaño el uso del procesador es excesivo
- **Acceso directo a memoria DMA:** La operación de E/S se realiza por un módulo separado conectado en el bus del sistema o se incluye en el módulo E/S, permitiendo leer o escribir bloques de datos

### 2.6 - TRATAMIENTO DE INTERRUPCIONES VECTORIZADAS

Las **interrupciones vectorizadas** son interrupciones que informan al procesador de la rutina que ha de ejecutarse en ese momento. Cuando la interrupción generada por el módulo apropiado llega al procesador, éste termina la ejecución de la instrucción actual, confirma que la interrupción ha llegado y apila el registro de estado y el contador de programa en la pila de control. Justo después salta al valor del `PC` indicado en la interrupción. Para procesarla guarda la información de estado del proceso anterior, procesa la interrupción, restaura la información de estado del proceso anterior y los valores del registro de estado y el `PC`.

### 2.7 - EXCEPCIONES

Las **excepciones** son eventos inesperados generados por alguna condición que ocurre durante la ejecución de una instrucción máquina, como un desbordamiento aritmético, una dirección inválida o una instrucción privilegiada. Son eventos síncronos.

El sistema operativo se encarga de manejar y resolver un conjunto predefinido de excepciones, como los fallos de memoria. Algunos lenguajes de programación, como Java, permiten tratar algunas excepciones durante la ejecución de los programas.

No todas las excepciones están relacionadas con errores de software, un módulo mal conectado también lanza una excepción.

### 2.8 - PROTECCIÓN DEL PROCESADOR

El funcionamiento en **Modo Dual** permite dos modos diferentes de ejecución de instrucciones en función de quién tiene acceso a ellas:
- **Instrucciones no privilegiadas (modo usuario):** Instrucciones cuya ejecución no presenta ningún problema de seguridad para el resto de programas, como incrementar un contador.
- **Instrucciones privilegiadas (modo kernel):** Instrucciones cuya ejecución pueda interferir en la ejecución de un programa cualquiera o del SO, como escribir en el puerto de un dispositivo.

### 2.9 - PROTECCIÓN DE LOS DISPOSITIVOS DE E/S

Los dispositivos de E/S son recursos que deben estar protegidos de órdenes maliciosas. Esta protección se consigue asignando todas las instrucciones de E/S como privilegiadas. Por esto, cualquier acceso a los dispositivos desde un programa de usuario se hace mediante peticiones al SO, que se tramitan a través de interrupciones, no desde el propio programa.

### 2.10 - PROTECCIÓN DE MEMORIA

Como cada programa en ejecución requiere de un espacio en memoria para poder cargar y leer todas sus instrucciones, hay que proteger tanto la zona de memoria asignada para cada programa como la memoria en la que está el código del sistema operativo y sus datos. Para ello existe la MMU o Unidad de Gestión de Memoria, que es un hardware especial encargado de controlar las regiones de memoria asignadas a los programas y velar por su protección

## 3 - EL SISTEMA OPERATIVO

Un sistema operativo o **SO** es un programa o conjunto de programas que controla la ejecución de los programas de aplicación y que actúa como interfaz entre el usuario de una computadora y el hardware de la misma.

### 3.1 - EL SO COMO INTERFAZ USUARIO/COMPUTADORA

Para el usuario medio, el SO es una interfaz (una capa visual que hace de mediadora entre la máquina y el usuario) mucho más fácil de tratar y configurar que el hardware del equipo, ya que ocupa la complejidad de la administración del sistema a bajo nivel. Por ejemplo, evita que el usuario tenga que escribir y leer posiciones de memoria para copiar y pegar archivos o permite que los programas puedan escribirse en lenguajes de alto nivel.

Un SO ofrece a sus usuarios utilidades en las siguientes áreas:
- **Desarrollo de programas:** Editores de textos, compiladores y depuradores.
- **Ejecución de programas:** Cargador y ejecutor de programas.
- **Acceso a dispositivos E/S:** Permite su acceso en modo kernel.
- **Acceso al sistema:** Controla dicho acceso y el uso de recursos del sistema.
- **Detección y respuesta de errores:** A nivel software y hardware.
- **Contabilidad:** Estadísticas de uso de los recursos y del rendimiento del sistema.

### 3.2 - EL SO COMO ADMINISTRADOR DE RECURSOS

Al ser el computador un conjunto de recursos de computación, el SO debe encargarse de gestionarlos. Para ello cuenta con un mecanismo de control de doble función basado en programas del propio SO ejecutados por el procesador de la misma forma que el resto del software y en la cesión del control a otros programas, dependiendo del procesador para retomarlo.

Esto hace que el SO desempeñe las siguientes funciones:
- Dirige al procesador en el uso de los recursos del sistema y en la temporización de la ejecución de otros programas.
- Carga una parte de su código (kernel y otras partes que se estén ejecutando) en memoria principal, dejando el resto de memoria ocupada por programas y datos de usuario.
- Asigna la memoria principal junto con el hardware de gestión de memoria del procesador.
- Decide cuándo un programa puede usar un dispositivo E/S y el acceso y uso de los ficheros.

### 3.3 - CARACTERÍSTICAS DESEABLES EN UN SISTEMA OPERATIVO

Un sistema operativo debe ser útil para usuarios de todos los niveles de conocimiento, por lo que debe cumplir las siguientes características:
- **Comodidad:** El uso del computador debe ser sencillo e intuitivo
- **Eficiencia:** Como existen más programas que recursos, el SO debe gestionar los recursos entre los programas de la forma más óptima posible
- **Facilidad de evolución:** Un SO debe estar diseñado para que las actualizaciones que reciba tanto de software como de hardware sean sencillas de implementar y mantener

### 3.4 - PROGRAMAS DE SERVICIO DEL SO

Los programas de servicio son programas que pueden considerarse como una ampliación del SO. Entre ellos se encuentran la interfaz gráfica, el salvapantallas, programas de seguridad como el antivirus y gestores de comunicaciones, discos y datos.

### 3.5 - HERRAMIENTAS GENERALES

Los sistemas operativos también ofrecen programas que permiten a su usuarios crear otros programas. Estos programas son editores de texto, compiladores, intérpretes, enlazadores, cargadores, montadores...
