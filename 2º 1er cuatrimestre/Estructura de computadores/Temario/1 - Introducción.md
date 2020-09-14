# TEMA 1 - INTRODUCCIÓN

## §1.1 - Unidades funcionales

Un computador con arquitectura Von Neumann está formado por tres bloques fundamentales unidos mediante buses:

- **CPU:** Unidades de procesamiento (ALU) y control (UC) de datos.
	- **ALU:** Unidad aritmético-lógica.
	- **UC:** Unidad de control.
- **Memoria principal:** Almacenamiento de datos e instrucciones.
- **E/S** Unidades homónimas y almacenamiento masivo.
	- **Entrada:** Codifican, digitalizan y transmiten información a la máquina.
	- **Salida:** Codifican, almacenan y transmiten información al usuario.

### CPU

La CPU está dividida en la ALU y la UC, ambos los componentes más rápidos del computador.

La ALU contiene registros de almacenamiento de memoria temporal, para acceso rápido a los datos que almacenan, con los que realiza operaciones aritméticas (enteras y de coma flotante) y lógicas (bit a bit).
La UC controla todos los circuitos del computador según indique el programa almacenado en memoria principal.

Las CPUs se pueden clasificar en función de los operandos de las instrucciones de su ALU, llamada **clasificación m/n** (se admiten $n$ operandos, de los cuales $m$ provienen de memoria.
Esta clasifiación tiene algunas combinaciones típicas:

- **Máquinas pila (0/0):** Realizan operaciones `push`, `pop`, `add`, `and`...
- **Máquinas de acumulador (1/1):** Tienen como operando implícito un registro acumulador $A$, cuyo acceso es más rápido que a memoria. Realizan operaciones `load`, `store`, `add`, `and`...
- **Máquinas de GPR (x/2, x/3):** Máquinas de registos de propósito general con múltiples acumuladores.

Las máquinas GPR pueden clasificarse en funición de su arquitectura:

- **Arquitecturas R/R (registro a registro) (0/2, 0/3):** Realizan operaciones tomando registros como operandos y guardando los resultados en registros. Es la arquitectura rípica de **RISC**.
- **Arquitecturas R/M (registro a memoria) (1/2, 1/3):** Realizan operaciones tomando registros como operandos y guardando los resultados en memoria. Es la arquitectura rípica de **CISC**. 2/3 es poco frecuente.
- **Arquitecturas M/M (2/2, 3/3):** Realizan operaciones tomando posiciones de memoria como operando y guardando los resultados en la misma. Es poco frecuente porque requiere demasiados accesos a memoria en una instrucción máquina.

### Memoria principal

Es importante distinguir entre instrucciones y datos, ya que las primeras son ejecutadas por la CPU para trabajar con las segundas, pero nunca al revés.
Distinguimos entre tres tipos de instrucciones:

- **Transferencia:** Desplazamiento de datos en memoria y módulos E/S.
- **Operaciones:** Modificaciones de los datos llevadas a cabo por la ALU.
- **Contro:** Direccionamiento del flujo de operaciones llevada a cabo por la UC.

Los programas almacenados en memoria determinan el comportamiento de la máquina, a menos que se produzcan excepciones.
Estos programas se almacenan en memoria semiconductora o **memoria principal** (RAM) en palabras (secciones de datos indexables, típicamente de entre 16 y 64 bits) accesibles en una única operación básica de R/W.
El almacenamiento secundario (discos, unidades ópticas...) no es memoria Von-Neumann, sino E/S.
Aún así, se considera al fichero `swap` como parte de la jerarquía de memoria.
Se ahondará en esto en §6.1.

Generalmente, la memoria se organiza en bytes, lo cual crea el problema de almacenamiento y recuperación de palabras de tamaño mayor.
Para solucionar esto, existen dos estrategias de ordenamiento:

- **Little-endian:** Se almacenan los bytes en orden ascendente de significación. Es más fácil encontrar los divisores del dato guardado.
- **Bit-endian:** Se almacenan los bytes en orden descendente de signifiación. Es más fácil ordenar el dato guardado por tamaño.

Por ejemplo, si queremos guardar el valor `ab7523`, con little-endian utilizaremos tres posiciones de memoria: `23`, `75` y `ab`.
Con big-endian, `ab`, `75` y `23`.
En toda esta asignatura se asume que trabajamos en little-endian.

A la hora de almacenar en memoria una palabra de $n$ bytes, debe estar alineada en una dirección $n\cdot k$.
Algunas CPUs pueden dar error de bus en caso de que una palabra no se encuentre alineada.
Esto se hace para evitar fallos de transferencia a otras memorias o para gestión de paginación.

### E/S

Los módulos de **entrada** codifican la información del usuario para que el computador pueda trabajar con ella, recuperan información almacenada en unidades de memoria y permiten recibir información de otros computadores.
Por su parte, los módulos de **salida** codifican la información del computador para que el usuario pueda trabajar con ella, la almacena para su uso posterior en unidades de memoria y envían información a otros computadores.
Muchos dispositivos, como los de red, son duales de E/S.

## §1.2 - Conceptos básicos de funcionamiento

## §1.3 - Estructuras de bus

## §1.4 - Rendimiento

