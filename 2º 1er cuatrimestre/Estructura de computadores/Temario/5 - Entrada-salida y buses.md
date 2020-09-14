# TEMA 5 - ENTRADA/SALIDA Y BUSES

## §5.1 - Funciones del sistema de E/S e interfaces

Los sistemas de E/S conectan el procesador con una gran variedad de dispositivos periféricos teniendo en cuenta que las características de esos suelen diferir de las del procesador, especialmente en la velocidad de trasnferencia, la longitud de palabra y los códigos de representación de datos.
Para compatibilizar ambos componentes se usan circuitos de interfaz o controladores de periféricos.

### Interfaces de E/S

Los circuitos de interfaz o controladores de periféricos son circuitos que adaptan el formado de las señalas y las características de temporización entre el procesador y los dispositivos de E/S, proporcionando todas las transferencias de datos encesarias entre el procesador y los periféricos mediante un bus de E/S.
Estas interfaces requieren uso de programas de E/S ejecutados por el procesador que controlan la transferencia de información con los dispotivios.
En computadores de altas prestaciones se utilizan procesadores especializados de E/S (IOP) cuyos conjuntos de instrucciones se restringen a las necesarias en las operaciones de E/S y que se hacen cargo de todas las transferencias con los periféricos.

### Funciones que debe incluir el sistema de E/S

Los sistemas de E/S deben poder seleccionar el periférico especificado por el procesador sin posibilidad de colisiones con otros dispositivos conectados.
En general, con $n$ bits pueden direccionarse $2^n$ direcciones diferentes, cada una con uno o dos puertos de E/S, pues una misma dirección puede combinar el puerto de entrada y el de salida.
Cada interfaz de periférico usa varios puertos para comunicarse con el procesador.
Este direccionamiento se puede realizar mediante tres técnicas:

- **Direccionamiento por selección lineal:** Se asigna un bit del bus de direcciones a cada puerto. Es la solución más ineficiente.
- **Direccionamiento por decodificación:** Se decodifican los bits de dirección para seleccionar un puerto de una interfaz. En una decodificación centralizada un decodificador es el que selecciona cada puerto, mientras que en una decodificación individual por cada puerto es éste quien reconoce su propia dirección.

Los sistemas de E/S también crean una comunicación física entre el periférico y el procesador mediante dos técnicas básicas:

- **Bus:** Permite conectar en paralelo un gran número de periféricos con un sistema fácilmente expendible mediante la adición de tarjetas o circuitos de interfaz.
- **Multiplexor / demultiplexor:** Con la ayuda de un decodificador manda las señales de entrada y salida a cada periférico, pero su expansión es muy difícil y conlleva demasiada circuitería.

Los sistemas E/S deben estar sincronizados con el procesador de la máquina a la que se conectan, adapdándose a las velocidades del procesador y la memoria principal.
Para ello, establecen un mecanismo para saber cuándo puedne enviar o recibir datos, incluyendo palabras de memoria temporal que sirvan de búfer para minimizar el tiempo de envío y señales de control de conformidad para realizar las operaciones en el momento adecuado.
La temporización de estas señales puede ser síncrona y asíncrona:

- **Temporización síncrona:** Es el procesador quien establece la temporización para que la siga el periférico. A la hora de escribir, el procesador sitúa los datos en el bus homónimo y genera una señal `WR#=0`, de forma que el flanco de subida de `WR#` activa la carga del búfer del controlador. Para leer, procesador genera una señal `RD#=0` y da al controlador un tiempo para suminisntrar la palabra al bus de datos.
- **Temporización asíncrona o con *handshaking*:** Se establece un diálogo para adaptar el cronograma a las necesidades de tiempo del periférico, con la ventaja de que se pueden conectar dispositivos con distintos requisitos y se da una mayor garantía de que el dato sea válido, estableciendo un periodo de espera máximo para evitar el bloqueo del sistema. Esto se consigue mediante una señal de aceptación `ACK` con la que el controlador constesta a la petición de transferencia del procesador.

Por último, los sistemas de E/S realizan funciones de conversión de datos, control de los periféricos conectados, control de errores tanto de funcionamiento como de datos y deben implementar un mecanismo que determine la cantidad de información a transmitir en una operación de E/S y cuente el número de palabras ya transmitidas.

### Conceptos diferenciados

LLamamos **transferencia elemental de información** al envío o recepción de una única palabra, y **operación completa de E/S** a la transferencia de un conjunto de datos, como un sector de disco o una línea de pantalla.

Son **dispositivos de E/S físicos** aquellos para los que el ordenador carece de sistema operativo o drivers adecuados, con los que el programador debe tratar directamente asumiendo sus detalles de funcionamiento y características físicas, y **dispositivos de E/S lógicos** aquellos para los que el programador efectú a las transferencias de datos activando rutinas de E/S proporcionadas por el sistema operativo.

Llamamos **E/S aislada o independiente** a aquella en la que el procesador distingue internamente entre espacio de memoria y espacio de E/S, y **E/S mapeada en memoria** a aquella en la que el procesador no distingue entre accesos a memoria y accesos a los dispositivos de E/S.

### E/S independiente frente a E/S en memoria

La E/S aislada emplea la patilla `IO/M#` del procesador, que a nivel alto indica a la memoria y los dispositivos de E/S que se va a efectuar una operación de E/S específica y a nivel bajo efectúa operaciones de intercambio de datos con memoria `LOAD`, `STORE` o `MOVE`.
Las instrucciones `IN` y `OUT` tienen poca riqueza de funcionamiento.
Esta E/S tiene de ventaja un diseño más limpio de la decodificación de las direcciones de memoria, una facilidad de la protección de la E/S y una mayor velocidad en los programas debido a la sencillez de la decodificación.
Sin embargo, tiene como desventaja una mayor complejidad en el diseño del procesador.

En la E/S mapeada en memoria se usan algunas direcciones de memoria para acceder a los puertos de E/S tras decodificarlas, sin que el procesador distinga entre accesos a memoria y a dispositivos de E/S (no se usa la patilla `IO/M#` y no se dispone de instrucciones especiales, únicamente `LOAD`, `STORE` y `MOVE`).
Para evitar particionar el mapa dedicado a memoria, se agrupa la E/S en una zona bien definida al principio o al final del mismo.
Esta E/S tiene como ventaja una menor complejidad del procesador, pero cada puerto de una interfaz ocupa una dirección que no puede utilizarse para memoria y las instrucciones de acceso a memoria suelen ser más largas que las específicas de E/S.

## §5.2 - E/S programada

Todos los pasos de una operación de E/S requieren de la intervención del procesador, que ejecuta una instrucción de E/S en la que un operando es un registro del controlador del periférico (el puerto) y otro es un registro del procesador o una posición de memoria.
Al decodificar dicha instrucción, la UC envía al exterior información sobre la dirección del periférico con el que se realiza la transferencia, el tipo de operación y la temporización o sincronización de la misma.
Acto seguido, envía el dato o se prepara para recibirlo.

En las operaciones de salida, el procesador ejecuta una instrucción de carga de una palabra de memoria a un registro y una instrucción de salida que transfiere el dato del procesador a un puerto de salida.
En las de entrada, el procesador ejecuta una instrucción de entrada y otra de almacenamiento.
En ambas pueden necesitar instrucciones adicionales, como actualizar el número de palabras transferidas en total (como en la llamada al sistema `write`).

La E/S programada puede reakuzarse cony sin consulta de estado:

- **Sin consulta de estado (incondicional):** El procesador decide cuándo se realiza la transferencia y el dispositivo debe estar siempre dispuesto a recibir datos o tener siempre datos disponibles.
- **Con consulta de estado (condicional):** El procesador pregunta al periférico a través de la interfaz si está preparado para la transferencia, por lo que éste debe incorporar un registro de estado con información sobre si tiene datos listos para entrada o está libre para salida.

## §5.3 - Interrupciones

Las interrupciones son bifurcaciones externas[^irq] al programa en ejecución provocadas por causas externas o internas cuyo objetivo es reclamar la atención del procesador sobre un hecho importante y pedir que se ejecute un programa específico para tratar dicho hecho, suspendiendo temporalemnte el programa en ejecución.
El programa ejecutado por una interrupción recibe el nombre de ISR (*interrupt service routine*).

A la hora de trabajar con instrucciones debemos diferenciar entre La propia interrupción, que es el diálogo de señales necesario para que el procesador acepte la petición de interrupción correctamente y salte a la ISR, y el tratamiento de la misma, que es la ejecución de la ISR.
Esta diferenciación puede ser difusa, ya que hay pasos de la interrupción que se realizan mediante diálogo de señales en algunos casos y mediante programas en otros.

Las interrupciones pueden darse por fallos de hardware si alguna de las comprobaciones periódicas de los circuitos falla, por errores del programa como overflows, divisiones entre cero o violaciones de segmento, condiciones de tiempo real en las que se rompe alguna barrera temporal, o para procesar E/S de forma que no se bloqueen los sistemas hasta que se efectúe la operación.

Distinguimos entre tres tipos de interrupciones:

- **Interrupciones externas:** Se inician a petición de dispositivos externos.
	- **Enmascarables:** Se pueden habilitar o inhibir usando instrucciones del tipo `EI` y `DI` (*enable/disable interrupt*).
	- **No enmascarables:** Tienen mayor prioridad que las enmascarables.
- **Interrupciones internas (excepciones y traps):** Se activan internamente mediante condiciones excepcionales, como errores del programa o fallos de hardware.
- **Interrupciones software:** Realizan llamadas al SO. Son instrucciones más cortas que las que llaman ISRs y el programador no necesita conocer la dirección del SO en memoria.

### Determinación de la dirección de la ISR

La dirección de comienzo de la ISR puede ser fija y definida en los circuitos del procesador o vectorizadas, en las que es el dispositivo que solicita la interrupción quien suministra la dirección de la ISR.

El direccionamiento provisto por las interrupciones vectorizadas puede ser obsoluto si se suministra la dirección completa de su ISR o relativo si sólo se envía parte de la dirección para que el procesador la complete, lo cual reduce el número de bits necesarios para trnasmitir la interfaz pero limita el número de dispositivos que el procesador puede identificar automáticamente.
También puede enviarse una instrucción de bifurcación completa en lugar de simplemente la dirección.

Con estos métodos, la ISR de un dispositivo debe comenzar siempre en la misma dirección.
Para ofrecer una mayor flexibilidad, el programador puede realizar un direccionamiento indirecto, que consiste en almacenar en la localización una instrucción de salto (vector de interrupción) a la rutina adecuada.
Para sincronizar la transmisión de la dirección, el procesador envía una señal de control `INTA#` (*interrupt acknowledge*), haciendo que la fuente de la interrupción sitúe la dirección en un bus para ser leída.
Este bus puede ser uno especial, el de datos o el de direcciones.

### Identificación de la fuente de interrupción

Como los computadores pueden tener conectados muchos dispositivos que pueden realizar interrupciones, la acción de las mismas depende del dispositivo que la envía, por lo que es necesario que haya ISR diferentes para cada una de las causas e identificar la causa o el dispositivo que produjo la interrupción.

Para solucionar esto, pueden existir múltiples líneas de interrupción con un dispositivo por línea de formaque cada fuente fenera una señal en la línea apropiada y la identificación del dipositivo es truvial y la dirección de comienzo de la ISR puede ser fija o vectorizada.
También pueden existir múltiples líneas de interrupción con más de un dispositivo por línea, de forma que se pueden tener varios dispositivos conectados a la misma línea de interrupción, por lo que el dispositivo solicitante ha de ser identificando por software o hardware.

La identificación de estas últimas puede realizarse

## §5.4 - DMA

## §5.5 - Estructuras de bus básicas

## §5.6 - Especificación de un bus, transferencias, temporización y arbitraje

## §5.7 - Ejemplos y estándares

[^irq]: Excepto en el caso de las interrupciones software.
