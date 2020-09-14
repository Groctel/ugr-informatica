# TEMA 1 - INTRODUCCIÓN

## 1.1 - SISTEMAS CONCURRENTES

Los sistemas concurrentes son aquellos en los que existen varios programas ejecutándose independientemente a la vez.
Son ejemplos de sistemas concurrentes los entornos de ventanas, saltear el arroz mientras se hornea el bizcocho...
Los sistemas operativos son el tipo de sistema concurrente que cubren estos apuntes.

## 1.2 - HISTORIA DE LOS SSOO

Inicialmente, el SO funcionaba como una biblioteca en tiempo de ejecución.
Se cargaba en memoria junto con el programa al que iba enlazado.
Esto tenía el problema de que se hacía un uso ineficiente de recursos caros, ya que el tiempo de preparación de una tarea era alto.

Los sistemas por lotes o *batch* fueron el primer modelo de sistema operativo similar al actual.
Se caracterizaban porque el monitor, que estaba almacenado en memoria, cargaba trabajos y los ejecutaba en secuencia.
Las instrucciones sobre los trabajos venían dadas por tarjeas de control, por lo que se proudcía una larga espera entre lotes de trabajo.

La segunda generación de computadores introdujo un hardware separado para gestionar la E/S mediante interrupciones, de forma que un programa podía seguir ejecutándose mientras se escribían o leían datos desde el hardware.
La concurrencia traída por este sistema se gestionó a través de sistemas multiprogramados, que permiten mantener varios trabajos ejecutables cargados en memoria y elegir qué instrucciones deben ejecutarse cada vez de forma que la E/S de un trabajo pueda solaparse con el cómputo de otro.
Esto se consigue a través de DMA (*Direct Memory Access*).
Para que sea posible la multiprogramación el SO debe saber gestionar la memoria y la CPU para poder realizar la asignación de los distintos dispositivos a su trabajo correspondiente en cada momento.

Los sistemas de tiempo compartido permiten usar el sistema de forma interactiva, de forma que cada usuario puede disfrutar de su sesión como si estuviera disfrutando de todo el sistema.
Esto se consigue mediante una optimización del tiempo de respuesta basada en la asignación equitativa del tiempo de CPU para cada proceso.

Los sistemas de tiempo real son sistemas utilizados en aplicaciones muy especiales para garantizar una respuesta a sucesos físicos en un intervalo de tiempo fijo.
Esto trae consigo el problema de tener que poder ejecutar el resto de actividades del sistema que satisfacen los requisitos mínimos de uso del mismo.
Los programas de reproducción de audio y vídeo tienen requisitos de tiempo real.

Los sistemas distribuidos son sistemas multicomputador sin memoria ni reloj común.
Se basan en compartir recursos hardware, como impresoras y discos, y software, como servicios web, entre todos los computadores.
Tienen la ventaja de que, si uno de los computadores falla, el resto puede seguir ejecutándose aunque no sea de forma completa.

Los SSOO paralelos son sistemas diseñados para sistemas multiprocesador.
Estos sistemas permiten ejecutar paralelamente varios programas para conseguir un aumento de la velocidad de las tareas computacionalmente complejas.
El multiprocesamiento simétrico (SMP) permite que todos los procesadores puedan ejecutar código del SO y de los programas.

Los SSOO de internet se basan en que el computador que maneja el usuario no es más que una interfaz conectada a un servidor que realiza las computaciones complejas, de forma que el hardware que se distribuye a los usuarios es más barato y no se desaprovecha.

## 1.3 - ESTRUCTURAS DE SSOO

### 1.3.1 - SERVICIOS

Son servicios suministrados por el SO:

- La ejecución de diferentes actividades.
- El acceso a información permanente.
- El acceso a dispositivos.
- El siministro de memoria para la ejecución de programas.
- El uso seguro de recursos.
- La interfaz de acceso a los servicios del SO.

### 1.3.3 - COMPONENTES UNIX

Los sistemas *nix[^nix] se basan en cinco elementos:

#### Intérprete de órdenes:

Es un programa que maneja la entrada de órdenes por parte del usuario desde una terminal al sistema y su correspondiente salida.
Los intérpretes pueden ser una parte estándar del SO (como en MS-DOS) o un proceso de usuario sin privilegios que carga una *shell* para que ésta actúe como interfaz.

#### Gestor de archivos:

Los archivos son colecciones de información identificadas por un nombre.
Los sistemas de archivos permiten al usuario mani

#### Gestor de memoria:

#### Gestor de dispositivos:

#### Gestor de procesos: 

Estos cinco componentes actúan de forma separada y protegida pero sincronizada.

[^nix]: Sistemas operativos basados en Unix.
[^nix]: Sistemas operativos basados en Unix.
