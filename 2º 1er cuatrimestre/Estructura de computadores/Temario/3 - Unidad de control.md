# TEMA 3 - UNIDAD DE CONTROL

## §3.1 - Camino de datos

### Unidades de procesamiento y control

Un computador con arquitectura Von Neumann está formado por tres bloques fundamentales unidos mediante buses:

- **CPU:** Unidad de procesamiento y control de datos.
- **Memoria principal:** Almacenamiento de datos e instrucciones.
- **E/S** Unidades homónimas y almacenamiento masivo.

En la CPU, la unidad de procesamiento contiene las unidades funcionales (ALU, desplazadores, multiplicadores...), los registros, multiplexores, buses internos...
Por otra parte, la unidad de control interpreta y controla la ejecución de las instrucciones de la memoria principal.
Esta tarea siempre la hace en dos fases:

- **Captación y secuenciamiento de las instrucciones:**
	- Lee de la memoria principal la instrucción a la que apunta el PC.
	- Determina la dirección de la siguiente instrucción y la carga en el PC.
- **Interpretación y ejecución de las instrucciones en IR:**
	- Reconoce el tipo de instrucción.
	- Manda las señales necesarias para dirigir los operandos necesarios a las unidades funcionales adecuadas.
	- Manda las señales necesarias para realizar la operación.
	- Manda las señales necesarias para enviar los resultados a su destino.

### Unidad de procesamiento con un bus

Las unidades

## §3.2 - Unidades de control cableadas y microprogramadas

## §3.3 - Control microprogramado
