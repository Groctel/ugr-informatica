# SISTEMAS DE ARCHIVOS, INTRODUCCIÓN A LA BASE DE DATOS

## 1 - ARCHIVOS

### 1.1 - CONCEPTO DE ARCHIVO

Un **archivo** es un conjunto de información sobre un mismo tema, que es tratada como una unidad de almacenamiento en memoria secundaria y está organizada de forma estructurada para la búsqueda de datos individuales. Es una estructura de datos externa al programa que lo usa.

Los archivos están compuestos por **registros**, estructuras que contienen información sobre elementos individuales de dicho archivo, cuya forma es homogénea. Dichos registros pueden dividirse a su vez en **campos**, que son datos que representan una información independiente.

### 1.2 - OPERACIONES SOBRE ARCHIVOS

Todos los archivos tienen asociados una serie de **atributos** como:
- Nombre.
- Tipo de archivo.
- Tamaño.
- Fecha de creación, acceso y última modificación.
- Propietario y grupo al que pertenece.
- Permisos de acceso.

El SO proporciona servicios para operar sobre los archivos como:
- Crearlos, borrarlos, copiarlos o renombrarlos.
- Establecer y obtener sus atributos.
- Abrirlos o cerrarlos para procesar su contenido en función de los permisos de acceso.
- Leer o escribir registros dentro de los mismos.

### 1.3 - GESTIÓN DE ARCHIVOS

Cada vez qe se accede al dispositivo, el SO transporta una cantidad fija de información llamada **bloque o registro físico** que dependede las caractecterísticas físicas del dispositivo y cuyo tamaño es distintoal del registro lógico. Tras dicho acceso, el SO transforma la dirección lógica usada por el programa en la dirección física usada por el dispositivo.

![img](https://i.imgur.com/Reb3dCh.png)

En las operaciones de lectura/escritora, la información se transfiere a través deunbuffer en memoria principal asociado a las operaciones de E/S sobre el archivo.

### 1.4 - CLASIFICACIÓN DE ARCHIVOS SEGÚN EL TIPO DE REGISTROS

- **Longitud fija.**
- **Longitud variable:**
  - **Con delimitador:** Un carácter delimitador o TERMINADOR, como puede ser un retorno de carro o un carácter de valor nulo (`00000000`), marca el fin de un registro.
  - **Con cabecera:** Cada registro contiene un campo inicial que almacena el número de bytes que contiene.
- **Longitud indefinida:** El SO no realiza ninguna gestión sobre lalongitud de los registros, ya que el archivo no tiene ninguna estructura interna, por lo que es el programa de usuario el encargado de indicar al SO el principio y final del registro al que debe acceder en cada operación.

También puede disponerse de un **campo clave** que permita localizar rápidamente un registro.

## 2 - CONCEPTO DE DIRECTORIO

Un **directorio** es un archivo que permite agrupar archivos según las necesidades de los usuarios. Los directorios crean una estructura jerárquica donde se localizan todos los archivos de los distintos usuarios que usan el dispositivo.

Desde la perspectiava del usuario se utilizan los siguientes conceptos, para los cuales el SO proporciona operaciones de administración:
- Directorio de trabajo o actual, accesible desde la orden `pwd`.
- Directorio inicialo o HOME, accesible desde la orden `cd ~`.
- Rutas (*paths*) absolutas (`/home/groctel/Documents/UGR/FS/Tema4.md`) y relativas (`./FS/Tema4.md` si nos encontráramos ya en `~/Documents/UGR`).
- Lista de búsqueda.
- Enlaces duros y simbólicos.

## 3 - ORGANIZACIÓNDE ARCHIVOS

### 3.1 - ORGANIZACIÓN SECUENCIAL

![img](https://i.imgur.com/p0fIZaf.png)

En este tipo de organización, **los registros están almacenados físicamente de forma contigua**. Esta organización es adecuada cuando se quiere leer los registros en la misma secuencia en que están almacenados o cuando se necesita leer la mayoría de los registros del archivo. Tiene la ventaja de que se aprovecha bienel espacio, es sencilla de utilizar y se puede utilizar con dispositivos secuenciales, que son de bajo coste.

#### 3.1.1 - Operaciones sobre archivos de organización secuencial

- **Añadir:** Sólo es posible escribir al final del archivo, después del último registro escrito.
- **Consulta o recuperación:** Se realiza en orden secuencial, para leer el registro en la posición `n`, hay que leer todos los `n-1` registros previos a él.
- **Inserción, modificación y eliminación:** Existen dificultades a la hora de realizar estas operaciones sobreun archivo secuencial.
  - La **modificación** de un registro sólo es posible si no se aumenta su longitud.
  - La **eliminación** de un registro no es posible, pero se puede hacer un borrado lógico, identificándolo como no válido.
  - En otros casos es necesario crear un archivo nuevo con las actualizaciones que se quieren realizar.

### 3.2 - ORGANIZACIÓN SECUENCIAL ENCADENADA

![img](https://i.imgur.com/T6HzALr.png)

En este tipo de organización **se almacena junto a cada registro un puntero con la dirección física del registro siguiente**, dando lugar a una cadena de registros en direcciones físicas no secuenciales. El último registro contiene una marca especial en el puntero que indica que no hay más registros a partir de ése.

Este sistema tiene la ventaja de que facilita la inserción y borrado de registros, pero tiene el inconveniente de que limita las consultas de forma secuencia, ya que hay que realizar muchos cambios entre direcciones físicas.

#### 3.2.1 - Operaciones sobre archivos de organización secuencial encadenada

- **Consulta o recuperación:** La consulta es secuencial, en el sentido de que cada vez que se lee un registro se lee la posición del siguiente, aunque la dirección sea lógica y no física.
- **Inserción:** Deben seguirse los siguientes pasos:
  - **Localizar la posición** donde se desea insertar (entre qué dos registros debe estar el nuevo).
  - **Escribir el registro** en una zona de memoria libre.
  - **Asignar los punteros** del nuevo registro al anterior y del registro siguiente al nuevo para que la secuencia siga teniendo sentido.
- **Borrado:** Basta con asignar el puntero del registro a borrar al anterior y así omitirlo en la secuencia.
- **Modificación:** Si el cambio no implica un cambio de longitud del registro se puede sobreescribir en el mismo espacio. En caso contrario, se debe insertar el registro con la modificación y borrar el anterior.

### 3.3 - ORGANIZACIÓN SECUENCIAL INDEXADA

![img](https://i.imgur.com/FS9A7z3.png)

En este tipo de organización **se utilizan dos estructuras:**
- **Zona de registros:** En ella se direccionan los registros del archivo. Está dividida en **tramos**, que son conjuntos de registros consecutivos. Los registros están ordenados según el valor de una clave.
- **Zona de índices:** En ella hay un registro por cada tramo en la zona de registros que contiene:
  - El mayor valor de la clave del tramo.
  - La dirección del primer registro del tramo.

La gestión de esta estructura la realiza el SO o un software especial, por lo que el usuario no necesita conocer la existencia de ambas zonas para poder utilizar esta organización.

#### 3.3.1 - Operaciones sobre archivos de organización secuencial indexada

- **Consulta:** Se localiza un registro conocida su clave sin necesidad de leer los registros que no se encuentranen su mismo tramo. Dicha consulta sigue este procedimiento:
  - **Lectura secuencial de las claves** en la zona de índices hasta encontrar una mayor o igual a la del registro buscado.
  - **Obtención de la dirección de comienzo del tramo** en el que se encuentra el registro.
  - **Lectura secuencial del tramo** de la zona de registros hasta en contrar el registro buscado o uno con valor de clave mayor que el buscado en caso de que el archivo consultado no se encuentre.
- **Inserción:** Al ser ambas zonas secuenciales no es posible insertar registros con esta organización. En algunos casos se permite la escritura de nuevos registros al final de la zona de registros, pero éstos no podrán ser consultados por clave.
- **Borrado:** Al ser secuencial la zona de registros, no es posible borrarlos. La única forma de hacerlo es mediante un borrado lógico.
- **Modificación:** Sólo son posibles si el registro no modifica su longitud y no se altera su valor de clave.

### 3.4 - ORGANIZACIÓN DIRECTA O ALEATORIA

En este tipo de organización **los registros están escritos sobre un soporte de acceso directo para el cual se asocia la dirección física con una dirección lógica mediante una llave**. Se llama *aleatoria* a este tipo de organización porque normalmente no existe una correlacón entre el orden físico y lógico de los registros.

Esta organización es útil para archivos donde los accesos deben realizarse por llave, pues se accede siempre a registros completos. Sin embargo, si se quiere procesar la información en conjunto puede ser más rentable una organización secuencial indexada.

#### 3.4.1 - Problemas de sinónimos en la organización directa o aleatoria

Para este tipo de organización **es necesario elegir adecuadamente la función de transformación o método de direccionamiento** que va a utilizarse, pues pueden darse las siguientes situaciones no deseadas:
- **Existencia de direcciones sin clave correspondiente**, lo que conlleva a que haya zonas de disco sin utilizar.
- **Existencia de direcciones que se correspondancon más deuna clave**, en cuyo caso se dice que son sinónimas o que se produce una colisión.

Existen dos formas de resolver el problema de la sinonimia o colisión:
- Al asociar a una clave una dirección ya ocupada por otro registro **se busca en el archivo hasta encontrar una posición libre** donde escribir el nuevo registro.
- **Se reserva una zona de desbordamiento** en la que se escribirán los registros que no se puedan escribir en la posición que les corresponde según la transformación. Dicha zona puede gestionarse secuencialmente o encadenada ala zona principal de registros.

Es importante notar que ambas soluciones contribuyen a complicar la estructura del archivo.

#### 3.4.2 - Métodos de direccionamiento en la organización directa o aleatoria

- **Direccionamiento directo:** Se utiliza como dirección la propia clave y sólo es factible si dicha clave es numérica y su rango de valores no es mayor que el rango de direcciones en el archivo (sacar 20 bollos del horno y ponerle a cada uno una banderita con un número del 1 al 20). Esto tiene el inconveniente de que pueden quedar lagunas de direcciones sin utilizar (tengo 20 banderitas pero sólo he hecho 15 bollos) en lugares conocidos de antemano. Esto se soluciona desplazando los registros ocupados a la zona superior y dejando todo el espacio libre al final.
- **Direccioamiento asociado:** Se puede utilizar cualquier tipo de clave, pero debe construirse una tabla que almacene la dirección de registro que corresponde a cada una. Dicha tabla debe guardarse mientras exista el archivo.
- **Direccionamiento calculado o *hashing***: La dirección de cada registro se utiliza realizandouna transformación sobre la llave. Se utiliza en los siguientes casos:
  - **La clave no es numérica**, por lo que se necesita una conversión previa para obtener un número a partir de ella.
  - **La clave es numérica pero su valor está en un rango inadecuado**, por lo que debe transformarse en un valor dentro del rango admitido por el sistema.

#### 3.4.3 - Operaciones sobre archivos en la organización directa o aleatoria

- **Consulta:** Se realiza por clave. Para leer un registro debe aplicarse a la clave el algoritmo de transformación, que devuelve un número que es la dirección del registro que se quiere leer. Si el registro no se encontrara allí, se procederá según se haya resuelto la gestión de sinónimos o colisiones.
- **Borrado:** Siempre se realiza un borrado lógico, pudiéndose reutilizar el espacio del registro elimiado.
- **Modificación e inserción:** Siempre se puede modificar o insertar un nuevo registro, realizando la transformación de la clave correspondiente.

## 4 - BASES DE DATOS

## 4.1 - PROBLEMAS DE APLICACIONES CONVENCIONALES CON ARCHIVOS

- **Dificultad de mantenimiento:** Si la información está duplicada, es necesario actualizar varios archivos con diferentes organizaciones atendiendo a sus pautas o la información quedará completamente incoherente.
- **Redundancia:** Existen dados deducible a partir de otros datos.
- **Rigidez de búsqueda** El archivo se concibe para acceder a los datos de un modo determinado. Sin embargo, en la mayoría de los casos se busca combunar acceso secuencial y directo por varias claves.
- **Dependencia con los programas** En un archivo no están reflejadas las relaciones entre campos y registros, por lo que el programa que trabaja con él debe encargarse de determinarlas. Si se desea modificar dichas relaciones se obliga a modificar todos los programas que lo usen y si la modificación es ajena al programa (como es el caso de aumentar la longitud de un campo) se ha de modificar incluso los programas que no lo usan.
- **Seguridad** El control de seguridad debe realizarlo el propio programa, por lo que es muy deficitario en los sistemas de archivos.

## 4.2 - CONCEPTO DE BASE DE DATOS

Las bases de datos son una alternativa a los sistemas de archivos que intenta eliminar o reducir los probemas anteriormente descritos.

Una base de datos es un **sistema formado por un conjunto de datos y un paquete de softeare para la gestión de dicho conjunto** de tal modo que:
- Se controla el almacenamiento de datos redundantes.
- Los datos resultan independientes de los programas que lo usan..
- Las relaciones entre los dato se almacenan junto a ellos.
- Se puede acceder a los datos de diversas formas.

La independencia de los programas de aplicación se consigue a partir de la forma en la que se almacenan las relaciones entre datos y el uso del campo y el registro como unidad de almacenamiento de los mismos.

## 4.3 - REQUISITOS QUE DEBEN CUMPLIR LAS BASES DE DATOS

- **Acceso múltiple:** Diversos usuarios deben poder acceder a la base de datos sin que se produzcanconflictos ni visiones incoherentes.
- **Utilización múltiple:** Cada usuario debe poder tener una imagenpo visión porticular de la estructura de la base de dtos.
- **Flexibilidad:** Deben poder utilizarse diferentes métodos de acceso con tiempos de respuesta razonablemente bajos.
- **Seguridad:** Debe controlarse el acceso a los datos a nivel de campo, impidiéndoselo a los usuarios no autorizados.
- **Protección contra fallos:** Deben existir mecaniscos de recuperacion en caso de fallo del sistema.
- **Independencia física:** Debe poder cambiarse el soporte físico de la base de datos sin que esto repercuta en su estructura o en los programas que la utilizan.
- **Independencia lógica:** Deben poder modificarse los datos contenido en la base de datos y sus relaciones o incluir nuevos datos sin afectar a los programas que la utilizan.
- **Redundancia controlada:** Debe almacenarse cada dato una sola vez.
- **Interfaz de alto nivel:** Debe existir una forma sencilla y cómoda de usar la base de datos desde al menos un lenguaje de alto nivel.
- **Consulta (*query*) directa:** Debe existir una utilidad que permita el aceso a los datos de forma interactiva o conversacional.

## 4.4 - ESTRUCTURA DE UNA BASE DE DATOS

Se dice que **un atributo de una entidad es su clave primaria** si su valor determina de forma unívoca cada uno de los elementos de dicha entidad y no existe ningún subconjunto de dicho atributo que permita identificar a la identidad de la misma manera.

Además de las entidades, en una base de datos **se almacenan las relaciones** entre ellas. En su implementación, estas relaciones se almacenan con punteros insertados automáticamete por el software que la maneja de forma "transparente" al usuario.

## 4.5 - NIVELES DE ABSTRACCIÓN DE LA INFORMACIÓN: VISTAS Y ESQUEMAS

![img](https://i.imgur.com/pDetrME.png)

- **Nivel de vista:** Permite describir diferentes **vistas o subesquemas**, cada una de las cuales se corresponde con la parte de la base de datos que interesa a un determinado grupo de usuarios, limitando así el acceso sólo a la información de la vista (cada departamento tiene acceso a sus archivos).
- **Nivel conceptual:** Describe el **esquema de la base de datos**, en el que se especifica qué información se guarda en ella, incluyendo los datos almacenados y sus relaciones. Este nivel se utilia en la administración de la base de datos.
- **Nivel físico:** Describe cómo se almacenan los datos y las estructuras de datos necesarias para ello.

## 4.6 - MODELOS DE DATOS

Los modelos de datos son **herramientas conceptuales que permiten describir los datos, sus relaciones, su semántica y sus limitaciones** y ayudan a describir la estructura de una base de datos. Distinguimos entre tres modelos de dados:
- **Modelos lógicos basados en objetos:** Describen los datos a nivel conceptual y a nivel de vista, permitiendo una estructuración flexible y una especificación de sus limitaciones. Este es el caso del *Modelo entidad - relación*.
- **Modelos lógicos basados en registros:** Describen los datos a nivel conceptual y a nivel de vista, permitiendo especificr su estructura jerárquica pero no sus limitaciones. Este es el caso del *Modelo jerárquico*, el *Modelo en red* y el *Modelo relacional*.
- **Modelos físicos de los datos:** Describen los datos en el nivel de implementación de los sistemas de base de datos.

### 4.6.1 - MODELO ENTIDAD - RELACIÓN

#### 4.6.1.1 - Conceptos básicos del Modelo entidad - relación

- **Entidad:** Objeto que tiene existencia propia y puede distinguirse de otro y del cual se quiere almacenar información de ciertas características.
- **Conjunto de entidades:** Grupo de entidades del mismo tipo que representa la estructura genérica de una entidad de interés. Las entidades pueden pertenecer a más de un conjunto de entidades.
- **Relación:** Asociación entre varias entidades.
- **Conjunto de relaciones:** Grupo de relaciones del mismo tipo que representa la estructura genérica de las relaciones entre conjuntos de entidades.
- **Grado de una relación:** Números de tipos de entidad que intervienen en un tipo de relación.
- **Atributo:** Unidad básica de información sobre un tipo de entidad o un tipo de relación.

#### 4.6.1.2 - Tipos de correspondencia (cardinalidad) del Modelo entidad - relación

La cardinalidad expresa el **número de entidades con las que puede asociarse o corresponderse una entidad mediante una relación**. Distinguimos entre cuatro tipos de cardinalidades entre dos conjuntos *A* y *B*:
- **Uno a uno `(1:1)`:** A cada entidad de *A* sólo le puede corresponder una única entidad de *B* y viceversa.
- **Uno a muchos `(1:N)`:** A cada entidad de *A* le pueden corresponder varias entidades de *B*, pero a cada entidad de *B* sólo le puede corresponder una única entidad de *A*.
- **Muchos a uno `(N:1)`:** A cada entidad de *A* le pueden una única entidad de *B*, pero a cada entidad de *B* le pueden corresponder varias entidades de *A*.
- **Muchos a muchos `(N:M)`:** A cada entidad de *A* le pueden corresponder varias entidades de *B* y vicecersa.

#### 4.6.1.2 - Diagrama del Modelo entidad - relación

![img](https://i.imgur.com/edSakur.png)

El diagrama entidad - relación **representa gráficamente la estructura de una base de datos** según el Modelo entidad relación. Consta de cuatro componentes:
- **Rectángulos:** Representanconjuntos de entidades.
- **Rombos:** Representan conjuntos de relaciones.
- **Elipses** Representan atributos tanto de las entidades como de las relaciones.
- **Representación de la cardinalidad:** Puede hacerse de dos maneras:
  - **Mediante una etiqueta asociada al conjunto de relaciones:** Sólo para relaciones binarias.
  - **Mediante líneas** que contengan una punta de flecha señalando al conjunto que participa unariamente y sin punta partiendo del conjunto que participa mútiplemente.

### 4.6.2 - MODELOS LÓGICOS BASADOS EN REGISTROS: TIPOS DE BASES DE DATOS

- **Modelos de datos jerárquico:** Establece una relación de jerarquía entre los datos en forma de árbol en la que no es posible definir relaciones `N:M`.
- **Modelo de datos en red:** Permite relaciones binarias de cualquier cardinalidad y no es necesario que la estructura tenga forma de árbol.
- **Modelo de datos relacional:** Está formada por tablas, que son estructuras bidimensionales formadas por una sucesión de registros del mismo tipo. Dichas tablas deben cumplir las siguientes condiciones:
  - Todos los registros deben ser del mismo tipo. Se usan tablas distintas para distintos registros.
  - No pueden contener campos repetidos.
  - No pueden contener registros duplicados.
  - El orden de los registros es indiferente, por lo que se debe poder recuperar los registros en un orden particular en cada momento.
  - Deben contener una clave formada por uno o varios campos.

## 4.7 - TRANSFORMACIÓN DEL MODELO ENTIDAD - RELACIÓN AL MODELO DE DATOS RELACIONAL

![img](https://i.imgur.com/TkEzbKV.png)

La transformación de un diagrama de Modelo entidad - relación a un Modelo relacional basado en tablas requiere de los siguientes pasos para cada uno de sus conjuntos:
- **Conjuntos de entidades:**
  - Se define una tabla para cada conjunto de entidades.
  - Se define una columna de la tabla para cada atributo de las entidades.
- **Conjuntos de relaciones sin atributos propios:**
  - **Cardinalidad `1:1`:** Se añaden las columnas necesarias para albergar los atributos que forman la clave del otro conjunto de entidades en la tabla del conjunto de entidades que se considere principal.
  - **Cardinalidad `1:N` o `N:1`:** En la tabla del conjunto de entidades `N` se añaden las columnas necesarias para albergar los atributos que formanla clave del otro conjunto de entidades.
  - **Cardinalidad `N:M:`:** Se define una tabla propia para el conjunto de relaciones y se definen en ella las columnas necesarias para albergar los atributos que forman la clave de cada uno de los conjuntos de entidades que relaciona ese conjunto de relaciones.
- **Conjuntos de relaciones con atributos propios:**
  - **Cardinalidad `1:1`, `1:N` o `N:1`:**  Se puede seguir el mismo enfoque dado para los conjuntos de relaciones sin atributos propios, pero añadiendo tambiñen las columnas para albergar los atributos del conjunto de relaciones en la misma abla del conjunto de entidades donde se añada la clae del otro conjunto de entidades.
  - **Cardinalidad `N:M`:** Se define una tabla propia para el conjunto de relaciones y en ella se definen las coumnas necesarias para albergar los atributos que forman la clave de cada uno de los conjuntos de entidades que relaciona ese conjunto de relaciones. En esa misma tabla también se definen las columnas necesarias para albergar los atributos propios del conjunto de relaciones.

## 5 - SISTEMA DE GESTIÓN DE BASES DE DATOS

Un sistema de gestión de bases de datos o *DBMS* (*Data Base Management System*) es un **conjunto de software destinado a la creación, control y manipulación de la información de una base de datos** y debe cumplir las siguientes tareas:
- **Definición del esquema** de la base de datos y de los distintos subesquemas.
- **Acceso a los datos** desde algún lenguaje de alto nivel.
- **Consulta directa** en modo conversacional.
- **Organización física** de la base de datos y recuperación tras fallos del sistema.

### 5.1 - LENGUAJES ESPECÍFICOS EN UN DBMS

Las tres primeras tareas definidas en el punto anterior se realizan mediante dos lenguajes específicos:
- **Lenguaje de descripción de datos:** También llamado *DDL* (*Data Description Language*), se usa para la descripción del esquema y de los subesquemas.
- **Lenguaje de manipulación de datos:** También llamado *DML* (*Data Manipulation Language*), se utiliza para el acceso a la base de datos desde lenguajes de altonivel o en modo conversacional.

El DBMS actúa como intermediario entre los programas de aplicación y el SO, lo que permite que los programas seanindependientes de la estructura física de los datos.

## INFORMACIÓN COMPLEMENTARIA O RELACIONADA

- [Sobre los registros de longitud variable](https://www.youtube.com/watch?v=0fw5Cyh21TE)