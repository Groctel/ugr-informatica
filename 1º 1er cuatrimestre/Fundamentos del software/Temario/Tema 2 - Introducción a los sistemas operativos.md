# INTRODUCCIÓN A LOS SISTEMAS OPERATIVOS

## 1 - COMPONENTES DE UN SO MULTIPROGRAMADO

### 1.1 - SISTEMAS MULTIPROGRAMADOS Y DE TIEMPO COMPARTIDO

En un **sistema monoprogramado** sólo puede ejecutarse un programa cada vez. Esto implica que, cada vez que el programa realiza una petición de E/S y espera a procesarla, se desperdicia tiempo en el que el procesador podría estar trabajando en otras tareas. También implica que el tiempo utilizado en la planificación y configuración de los trabajos es excesivamente largo, ya que el proceso de carga del programa únicamente se puede realizar cuando el programa anterior ha concluido y, en caso de encontrar un error, el programa debe terminar antes de poder iniciarse de nuevo.

Una medida para arreglar este problema es el **sistema por lotes**, que agrupa trabajos (el conjunto del programa, sus datos y las órdenes de control para el sistema) similares para que se ejecuten a la vez, necesitando menos interacción del usuario y reduciendo el tiempo de planificación. Esto lo lleva a cabo el **monitor** mediante un lenguaje de control de trabajos (**JCL**), consistente en una serie de instrucciones que permiten al monitor, la interfaz entre el usuario y la máquina, desempeñar las funciones de planificación.

Sin embargo, sigue existiendo el problema del tiempo que durante el cual el procesador se encuentra ocioso. Para solucionar esto existen los **sistemas multiprogramados**, que permiten la ejecución de las instrucciones de un programa mientras otro se encuentra bloqueado esperando una E/S.

![img](https://i.imgur.com/fqM4b6W.png)

Si tenemos en cuenta también el resto de recursos del sistema, la disminución del tiempo de ejecución disminuye drásticamente al pasar de monoprogramación a multiprogramación.

![img](https://i.imgur.com/yiyIj1e.png)

Entre los diferentes tipos de sistemas operativos existen diferentes categorías en función del número de programas, usuarios y tiempo: 
- **Monoprogramado:** Sólo permite ejecutar un programa cada vez
- **Multiprogramado:** Permite que se ejecute más de un proceso simultáneamente
- **Monousuario:** Proporciona servicios a un único usuario
- **Multiusuario:** Proporciona servicios a varios usuarios simultáneamente
- **Monoprocesador:** Gestiona un sistema de computación de un único procesador
- **Multiprocesador:** Gestiona un sistema de computación de varios procesadores
- **De tiempo compartido:** SO multiprogramado, especialmente diseñado para sistemas interactivos en el que se realiza un reparto del tiempo del procesador en pequeñas porciones (o *quantums*) para que todos los procesos puedan avanzar adecuadamente

### 1.2 - CONCEPTO DE PROCESO

A la hora de referirnos a las **tareas que está realizando un programa**, utilizamos el nombre de "procesos". Los procesos son más que el bloque de instrucciones cargadas en  memoria que el procesador está ejecutando. Son estructuras basadas en varios elementos que entre todos forman el Bloque de Control de Proceso (**PCB**):
- **Identificador del proceso (PID):** Una palabra que identifica el proceso
- **Contexto de ejecución:** Registros del procesador que pueden reescribirse y leerse al reanudar el proceso
- **Información del proceso:** Relacionada con el uso de recursos del sistema
- **Estado del proceso:** Situación en la que se encuentra en cada momento
- **Otra información para el control del proceso:**
  - Información de estado y planificación
  - Descripción de las regiones de memoria asignadas
  - Recursos asignados
  - Enlaces a colas de procesos
  - Comunicación entre procesos

Utilizando este esquema, podemos ver los procesos como una estructura de datos que van guiando y coordinando los procesos en su ejecución junto a otros.

Para realizar el cambio entre procesos, el sistema operativo lleva cargado en memoria un módulo llamado **Dispatcher** (¿*pasador*?), que guarda el contexto de un proceso y carga el contexto del siguiente.

Como existen instrucciones que no se pueden ejecutar sin permisos de administrador, los programas deben hacer peticiones al SO mediante una **trap o interrupción software**. Estas interrupciones son eventos síncronos que hacen una petición al SO para que realice una acción en modo kernel, que más tarde se devuelve de forma asíncrona como una interrupción hardware, que se describen en el tema anterior.

### 1.3 - MODELO DE CINCO ESTADOS DE LOS PROCESOS

El modelo de cinco estados representa las actividades que el SO lleva a cabo sobre los procesos (creación, terminación y multiprogramación) mediante cinco estados mutuamente excluyentes en los que puede encontrarse el proceso en cada momento. 

Los cinco estados en los que puede clasificarse un proceso son:
- **Nuevo:** El PCB está creado y el proceso está disponible en memoria
- **Preparado:** El proceso está listo para ejecutarse
- **Ejecutándose:** El procesador está trabajando con el programa
- **Bloqueado:** El proceso solicita algo al SO que requiere
- **Finalizado:** El proceso ha ejecutado su última orden

![img](https://i.imgur.com/rQSK69A.png)

Existe un caso excepcional en el que el proceso puede pasar de preparado o bloqueado a finalizado a causa de que sea terminado por otro proceso. Esto es algo que, por razones de seguridad, no se permite en la mayoría de sistemas operativos modernos

## 2 - DESCRIPCIÓN Y CONTROL DE PROCESOS

### 2.1 - CREACIÓN DE UN PROCESO

A la hora de crear un proceso y (e inicializar un PCB) el SO sigue los siguientes pasos:
- Asigna un identificador único al proceso
- Asigna un nuevo `PCB` al proceso
- Asigna un fragmento de memoria para el programa asociado
- Inicializa el `PCB` con los siguientes datos
  - **PC:** Dirección inicial de comienzo del programa
  - **SP:** Dirección de la pila de sistema
  - **Memoria:** Direcciones en las que reside el programa
  - **Otras entradas:** Inicializadas a `0` por defecto

### 2.2 - CONTROL DE PROCESOS

Por razones de seguridad, los programas se ejecutan en dos modos mutuamente excluyentes:
- **Modo usuario:** Da acceso limitado a los recursos del sistema
  - Un subconjunto de los registros del procesador
  - Un subconjunto del repertorio de instrucciones máquina
  - Un área de la memoria
- **Modo kernel:** El programa que se ejecuta (el SO) tiene acceso a todos los recursos software y hardware del sistema y se activa automáticamente cuando se produce
  - Una interrupción
  - Una excepción
  - Una llamada al sistema

### 2.3 - OPERACIÓN DE CAMBIO DE MODO

Tras producirse un cambio a modo kernel se ejecuta la rutina del SO correspondiente al evento producido y, cuando se concluye, se restaura automáticamente el hardware a modo usuario. Durante este tiempo, el proceso se sigue encontrando en modo ejecutándose, a pesar de que sea el SO el que esté gestionando la ejecución de sus órdenes.

En una operación de cambio de modo se siguen los siguientes pasos:
- El hardware salva el PC y el PSW (como mínimo)
- El hardware cambia el bit de modo a modo kernel
- Se determina la rutina del SO que debe ejecutarse y se carga en el PC
- Se ejecuta la rutina, que puede comenzar salvando el resto de registros y concluir restaurándolos
- El hardware restaura la información salvada y se vuelve a la rutina original

### 2.3 - OPERACIÓN DE CAMBIO DE CONTEXTO

Cuando se cambia de un proceso a otro, se cambian los procesos implicados de estado y, consecuentemente, de contexto. Los procesos ejecutándose pasan a bloqueado, preparado o finalizado y los procesos preparado que tengan la prioridad en ese mismo momento pasan a ejecutándose. Debido a la naturaleza de los cambios de proceso, sólo pueden ocurrir en los casos en los que se pasa de modo usuario a modo kernel.

En una operación de cambio de contexto se siguen los siguientes pasos:
- Salvar los registros del procesador en el PCB del proceso ejecutándose
- Actualizar el estado del proceso e insertar el PCB en la cola correspondiente.
- Seleccionar un nuevo proceso del conjunto de los que se encuentran preparados (Scheduler o Planificador de CPU).
- Actualizar el estado del proceso seleccionado a ejecutándose y sacarlo de la cola de preparados.
- Cargar los registros del procesador con la información de los registros almacenada en el PCB del proceso seleccionado.

## 3 - HEBRAS (HILOS)

Las **hebras** son estructuras de datos encargadas de ejecutar procesos que permiten ejecutar diferentes partes del mismo proceso entre varias de ellas. Debido a que sirven para ejecutar procesos, trabajan con el mismo modelo de cinco estados explicado anteriormente.

Las hebras poseen una serie de **ventajas** frente al trabajo directamente con procesos:
- Menor tiempo de creación de una hebra en un proceso ya creado
- Menor tiempo de finalización de una hebra que de un proceso
- Menor tiempo de cambio de contexto entre hebras del mismo proceso
- Facilitan la comunicación entre hebras del mismo proceso
- Permiten aprovechar las técnicas de programación concurrente y multiprocesamiento simétrico

## 4 - GESTIÓN BÁSICA DE MEMORIA

### 4.1 - ESPACIO PARA LAS DIRECCIONES DE MEMORIA

Distinguimos entre cuatro tipos de formas de concebir las direcciones de memoria:
- **Espacio de direcciones lógico:** Conjunto de direcciones relativas (también llamadas lógicas) que utiliza un programa ejecutable
- **Espacio de direcciones físico:** Conjunto de direcciones físicas de memoria principal correspondientes a las direcciones lógicas en un instante
- **Mapa de memoria de un ordenador:** Todo el espacio de memoria direccionable por el ordenador, dependiente del tamaño del bus de direcciones
- **Mapa de memoria de un proceso:** Se almacena en una estructura de datos donde se guarda el tamaño total de direcciones lógico y la correspondencia entre las direcciones lógicas y las físicas

### 4.2 - CARGA ABSOLUTA Y REUBICACIÓN

A la hora de cargar un programa, éste debe colocarse en algún punto de la memoria principal. Podemos hacer esto de dos formas:
- **Carga absoluta:** Se asignan direcciones físicas en tiempo de compilación, impidiendo reubicar el programa más adelante
- **Reubicación:** Se carga y ejecuta el programa en un lugar arbitrario, pudiendo trasladarse a otras direcciones físicas

![img](https://i.imgur.com/kQG5AYG.png)

En un sistema que cargue los programas de forma no absoluta el compilador genera direcciones lógicas, que generalmente se expresan como un vector de dos componentes (dirección inicial (0), dirección final (n). A la hora de reubicar el programa en memoria principal podemos distinguir dos tipos de protocolos:

- **Reubicación estática:** Se decide el espacio físico que va a ocupar el programa en tiempo de carga, por lo que el cargador sólo tiene que añadir la dirección base de carga a todas las referencias relativas (dirección inicial (m) + dirección relativa (x))
- **Reubicación dinámica:** El programa está siempre cargado con direcciones relativas, por lo que la traducción de direcciones lógicas a físicas se realiza en tiempo de ejecución, requiriendo apoyo hardware (se carga el programa donde sea y la dirección inicial se almacena en un registro que se va consultando en cada momento)

### 4.3 - FRAGMENTACIÓN DE MEMORIA

A la hora de cargar varios procesos en memoria principal se busca la dirección física final de los procesos cargados y se carga en la siguiente posición. Si no hubiese espacio suficiente, se buscan los procesos que ya no están en uso, se borran todos sus datos y se coloca el proceso nuevo en la dirección física en la que empezaba el proceso eliminado.

![img](https://i.imgur.com/IZxfm2g.png)

Para solventar este problema se utilizan dos sistemas de división del espacio físico en subsecciones de tamaño fijo (páginas) o variables (segmentos).

### 4.4 - PAGINACIÓN

Se divide la memoria física en bloques de tamaño fijo llamados marcos de página cuyo tamaño es siempre potencia de 2, de 512B a 8KB. El espacio lógico del proceso se divide en bloques del mismo tamaño llamados páginas, que se incluyen en el contexto del mismo y se albergan en los marcos de páginas de la memoria principal al cargarse.

Las **direcciones lógicas** tienen dos componentes:
- **Número de página:** La página a la que se refiere la dirección
- **Desplazamiento:** El elemento al que se apunta dentro de la página

Las **direcciones físicas** tienen dos componentes
- **Número de marco:** Marco donde está almacenada la página
- **Desplazamiento:** El elemento al que se apunta dentro del marco de página

Cuando el procesador genera una dirección lógica, se necesita traducirla a una dirección física para cargarla en memoria. De esto se encarga la tabla de páginas (existe una por cada contexto y su localización viene indicada por el Registro Base de Tablas de Página o PTBR), que tiene la información necesaria para realizar dicha traducción. Por otro lado el SO usa la tabla de marcos de página para gestionar la información de cada marco de página.

```c
Dirección física = nº marco * tamaño de página + desplazamiento
```

![img](https://i.imgur.com/3BqQdWA.png)

Como el acceso a la tabla de páginas requiere de varias instrucciones máquina, existe el Búfer de Traducción Adelantada (TLB, Translation Look-aside Buffer), que apunta a una serie de direcciones de la tabla de páginas para ser usadas de forma recurrente. Si la dirección buscada no existe en el TLB, se actualiza con la nueva entrada.

![img](https://i.imgur.com/MIwnWgO.png)

### 4.5 - SEGMENTACIÓN

Mientras que las páginas tienen un tamaño fijo, los segmentos tienen un tamaño variable. Se organizan mediante una tabla de segmentos que tiene dos datos para cada uno:
- **Base:** Dirección física donde se inicia el segmento
- **Tamaño:** Longitud del segmento

Existen dos registros (almacenados en el PCB) que gestionan la tabla de segmentos:
- **Registro base de la tabla de segmentos (STBR):** Apunta a la tabla de segmentos
- **Registro longitud de la tabla de segmentos (STLR):** Indica el número de segmentos del proceso

Para poder acceder a una dirección de un segmento es necesario que, en la consulta de dirección virtual que se pasa a la tabla de segmentos, el desplazamiento del segmento sea menor del tamaño.

![img](https://i.imgur.com/kF03ISI.png)
