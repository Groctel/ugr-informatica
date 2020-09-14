# 1 - INTRODUCCIÓN

## 1.1 - DEFINICIONES

- **Arquitectura:** Aspectos necesarios para redactar un programa ensamblador correcto.
  - Incluye los registros de la CPU, el repertorio de instrucciones, los modos de direccionamiento, etc.
  - **Arquitectura von Neumann:** Distingue cinco componentes o **unidades funcionales**:
    - **Dispositivos de entrada Entrada:** Codifican, digitalizan, transmiten (leen) datos.
    - **Dispositivos de Salida:** Codifican, almacenan, transmiten (escriben) datos.
    - **Memoria:** Almacena instrucciones y datos.
    - **CPU:** Unidad de procesamiento central del computador que procesa información de la entrada y la memoria al ejecutar programas.
      - **ALU:** Unidad Aritmético-Lógica. Realiza operaciones aritméticas y lógicas.
      - **Unidad de Control:** Controla los circuitos del computador.
- **Organización:** Estructura y funcionamiento del computador, la CPU, y la ALU.
  - **Estructura:** Componentes y su interconexión.
  - **Funcionamiento:** Dinámica de procesamiento de la información.
- **Computador:** Máquina formada por unas unidades funcionales.

## 1.2 - UNIDADES FUNCIONALES

### 1.2.1 - MEMORIA

Todo lo que se encuentra en memoria son datos codificados en binario, por lo que es tarea del computador interpretarlos correctamente.
Existen tres formas de interpretar la memoria:
  - **Interpretar como programa (codop)**
  - **Compilar o desensamblar**
  - **Codificar:** Se puede codificar de diversas formas
    - Instrucciones
	 - Números enterios, con signo, con coma flotante...
	 - Alfabéticamente

Distinguimos entre dos tipos de memoria: almacenamiento primario y secundario.

#### Almacenamiento primario:

Se trata de la memoria principal, que comúnmente conocemos como *memoria RAM*.
Está formada por semiconductores, que hacen que la transferencia y modificación de su cotenido sea muy rápida.

Almacena **instrucciones máquina**, consistentes en instrucciones codificadas en la arquitectura del computador que procesa la CPU.
Debido a que consiste en pulsos eléctricos (binarios) que abren o cierran puertas lógicas y circuitos, el **lenguaje máquina** es el único lenguaje que entiende la CPU.
Distinguimos entre tres clases de instrucciones:
- **Transferencia:** Instrucciones de memoria, entrada y salida (`mov`, `in`, `out`...).
- **Operaciones:** Instrucciones de la ALU (`add`, `and`, `xor`...).
- **Control:** Intrucciones de control del programa (`jmp`, `call`, `set`...).

Estas instrucciones están formadas por bits que se agrupan en dos campos:
- **Campo de código de operación:** Envía a la CPU la información sobre la operación que ha de activarse.
- **Campos de direcciones:** Especifican las posiciones de memoria o registros con los que trabajar y operar.

Por ejemplo, para rellenar la posición de memoria `F` con el valor de la posición `8`, usamos la instrucción `mov 8 F`.
Si sabemos que, por ejemplo, `mov` corresponde al código `0110` y traducimos `8` y `F` a binario, tenemos que la instrucción máquina correspondiente a `mov 8 F` es `0110 1000 1111` (supuesta un bus da datos de 4 bits).

Un conjunto de instrucciones máquina almacenadas en memoria se consideran un **programa almacenado**, que determina el comportamiento de la máquina salvo en caso de que se produzca una interrupción o *IRQ* (Interrupt Request).

La información se almacena en **palabras**, secciones independiendes de memoria que contienen una cantidad predeterminada de bits.
Las palabras tienen una longitud típica de entre 16 y 64 bits, siendo lo más frecuente almacenarla en múltiplos de 8 (memoria de bytes).
Por su parte, el tamaño típico de las memorias es un número de gigabytes múltiplo de 2 (8GB, 512GB...).
Para acceder a las palabras de la memoria se utilizan tres buses:
- **Bus de direcciones:** Indica a la memoria en qué dirección está la palabra con la que se quiere trabajar.
- **Bus de datos:** Transmite a o de la CPU la palabra almacenada en la dirección activa.
- **Bus de control:** Indica si se está realizando una operación de lectura o escritura.

#### Almacenamiento secundario:

No es memoria von Neumann, pues se considera un dispositivo de Entrada/Salida de datos.
Denota todos los dispositivos de almacenamiento a largo plazo, como pueden ser unidades ópticas, discos duros u otras unidades de memoria no principales.

### 1.2.2 - DISPOSITIVOS DE ENTRADA

Los dispositivos de entrada reciben información externa con la que el computador trabaja.
Pueden hacerlo de tres formas distintas:
- Codificando la información que reciben desde periféricos.
- Recuperando información previamente almacenada en unidades de memoria externas a la memoria principal.
- Recibindo información de otros computadores.

### 1.2.3 - DISPOSITIVOS DE SALIDA

Los dispositivos de salida trasladan la información procesada por el computador a unidades externas a la memoria principal.
Pueden hacerlo de tres formas distintas:
- Codificando la información para su lectura por un usuario humano a partir de un periférico.
- Almacenando la información en unidades externas para su uso posterior.
- Enviando la información a otros computadores.

> Muchos dispositivos son duales E/S. Por ejemplo, un mando de xbox permite enviar información sobre los botones pulsados al ordenador y mostrar luces o vibrar en la mano del jugador durante la partida.

### 1.2.4 - CPU

Como indica su nombre, la CPU (Central Processing Unit) es la unidad funcional que gestiona el procesamiento de datos del computador.
Está dividida en dos unidades: la ALU y la Unidad de Control.

#### ALU:

La ALU (Arithmetic-Logic Unit) está compuesta por un procesador capaz de realizar operaciones aritméticas (`add`, `sub`...) y lógicas (`xor`, `nand`...) y una serie de **registros** que almacenan datos recogidos de la memoria principal o que son resultado de las operaciones de la propia ALU.

#### Unidad de Control:

La Unidad de Control gestiona el funcionamiento de los circuitos del computador siguiendo las instrucciones del programa almacenado en memoria principal.
Para ello, envía selales de control a la memoria princpal y a los dispositivos de Entrada/Salida cuando recibe una instrucción de transferencia y a la ALU cuando recibe instrucciones aritmético-lógicas.
Internamente, gestiona mediante pulsos de reloj la temporización de estas señales para que el computador funcione correctamente.

## 1.3 - ESTRUCTURA FUNCIONAL DE UN COMPUTADOR

## 1.4 - 

# PREGUNTAS:

- ¿Qué significa **codop** en `interpretado como programa (codop)` referido a los datos en memoria?
