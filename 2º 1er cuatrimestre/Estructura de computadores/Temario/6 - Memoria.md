# TEMA 6 - MEMORIA

## §6.1 - Jerarquía de memoria, concepto del localidad

### Introducción

Las prestaciones que puede ofrecer un computador dependen de su capacidad y velocidad de acceso a memoria y de la organización de la misma.
Dicha memoria debe ofrecer, aparte de una capacidad de almacenamiento y velocidad de acceso satisfactorias, un coste por bit reducido y la exención de responsabilidad de los programadores que la utilicen de realizar explícitamente tareas de gestión de la misma.
Al hablar de memoria nos referimos, en sentido amplio, a cualquier dispositivo de almacenamiento de datos:

- **Memoria interna:** Registros. No hay diferencia de velocidad con la CPU.
- **Memoria caché.**
- **Memoria principal:** La CPU no puede ejecutar directamente programas que estén más allá de ésta.
- **Memoria secundaria o masiva:** Discos, cintas magnénicas, almacenamiento óptico... Más lenta que las anteriores.

LLamamos **tiempo de acceso** al tiempo requerido para leer o escribir una palabra en memoria.

Según su método de acceso, podemos clasificar las memoria en tres grupos:

- **Acceso aleatorio (RAM):** El tiempo de acceso es independiente de la posición de memoria accedida (*random access memory*).
- **Acceso secuencial (SAM):** El tiempo de acceso depende de la posición de los datos, como es el caso de las cintas magnéticas (*sequential access memory*).
- **Acceso semialeatorio o directo (DASD):** Discos duros, en los que se accede a las pistas de forma aleatoria y a los datos de las mismas secuencialmente (*direct access storage device*).

En las memorias SAM y DADS, el tiempo de acceso a un bloque de $n$ palabras no es $n\cdot t_i$ siendo $t_i$ el tiempo de acceso a una única palabra, sino $t_i+t_b$, siendo $t_b$ el tiempo de bloque.

### Aumento del ancho de banda

Definimos el ancho de banda de memoria de un ordenador como el número de palabras a las que puede acceder el procesador en una sola unidad de tiempo.
Esto plantea un problema, que es la diferencia entre el rendimiento del procesador y el ancho de banda de la memoria (*processor-memory gap*)[^moore].
Existen varios métodos para aumentar este ancho de banda:

- Usar tecnología de alta velocidad.
- Organizar jerárquicamente la memoria, incluyendo la caché.
- Incrementar el ancho (número de palabras accedidas simultáneamente) de la memoria.
- Dividir la memoria principal en un conjunto de módulos direccionables simultáneamente (**memoria entrelazada**).
- Emplear **memorias asociativas** (direccionables por contenido) cuando sea posible.

Disponer de memoria de la máxima capacidad posible con el menor tiempo de acceso y sin mejoras en la arquitectura es prohibitivo e inviable.

### Localidad de las referencias

Podemos aprovechar el principio de Pareto, que nos dice que un programa pasa el 80% de su tiempo ejecutando sólo el 20% de su código, para predecir con una precisión razonable qué instrucciones y datos se utilizarán en el futuro.
Con esto, definimos tres localidades de las referencias:

- **Espacial:** Si se referencia un elemento, los elementos cercanos a él serán referenciados prontos ($d(t+n)=d(t)+k$ con $n$,$k$ pequeños), ya que los datos relacionados se almacenan juntos.
- **Secuencial:** Las direcciones de memoria utilizadas suelen ser contiguas ($d(t+1)=d(t)+1$), ya que las instrucciones se ejecutan secuencialmente.
- **Temporal:** Si se referencia un elemento, volverá a referenciarse pronto, es decir, la información que se usará en un futuro próximo es aproximadamente la misma que se está usando actualmente ($d(t+n)=d(t)$ con $n$ pequeño).

### Jerarquía de memoria

Teniendo en cuenta las limitaciones tecnológicas y aprovechando el principio de localidad mencionado anteriormente, podemos conseguir un sistema de memoria eficaz estableciendo una jerarquía de niveles:

- **0 - Registros:** Gestionados por el compilador y el procesador.
- **1 - Caché (sRAMs):** Gestionada por el hardware en la unidad de gestión de memoria (MMU).
- **2 - Memoria principal (dRAMs):** Gestionada por la MMU y el sistema operativo.
- **3 - Almacenamiento en disco:** Gestionada por la MMU y el sistema operativo.
- **4 - Unidades externas:** Discos y cintas gestionadas por el sistema operativo con intervención limitada del usuario.

Cada nivel está caracterizado por una serie de parámetros:

- **Tiempo de acceso ($t_i$):** Tiempo desde que se inicia una lectura hasta que se llega a la palabra deseada.
- **Tamaño de la memoria ($s_i$):** Número de bytes, palabras, sectores... que se pueden almacenar en el dispositivo.
- **Coste por bit o por byte ($c_i$).**
- **Ancho de banda ($b_i$):** Velocidad a la que se transfiere información desde un dispositivo.
- **Unidad de transferencia ($x_i$):** Tamaño de la unidad de información que se transfiere entre los niveles $i$ e $i+1$.

Para todos los niveles se verifican las siguientes propiedades:

\begin{center}
$t_i<t_{i+1}$
$s_i<s_{i+1}$
$c_i>c_{i+1}$
$b_i>b_{i+1}$
$x_i<x_{i+1}$
\end{center}

También se verifica la **propiedad de inclusión**:

\begin{center}
$$M_0\in M_1\in M_2\in\cdots\in M_n$$
\end{center}

Si una palabra se encuentra en $M_i$, copias de esta palabra también se encuentran en subsiguientes $M_{i+k}$.
Sin embargo, una palabra almacenada en $M_{i+1}$ puede no estar en $M_i$.
Si éste fuera el caso, se garantiza que tampoco estará en subsiguientes $M_{i-k}$.
Por ejemplo, una palabra almacenada en un registro se habrá tomado de memoria principal, que la habrá tomado de memoria masiva, sin embargo, esa palabra en memoria masiva podría no estar cargada en memoria principal y, consecuentemente, no encontrarse en ningún registro.

A la hora de leer una palabra, la CPU no la encontrará siempre en $M_1$, por lo que deberá intentar localizarla en niveles inferiores, sufriendo una penalización en el tiempo de acceso.
Aprovechando el principio de localidad, transferimos bloques completos en lugar de palabras aisladas para reducir dicha penalización.

A la hora de escribirla se da un problema de coherencia de datos entre los niveles, ya que la modificación de una palabra en un nivel supone que, en algún momento, tendrá que escribirse en niveles inferiores.
Existen dos estrategias para mantener esta coherencia:

- **Escritura directa (write-through):** Si se modifica una palabra en $M_i$ se modifica inmediatamente en $M_{i+1}$.
- **Post-escritura (write-back):** Se retrasa la actualización de la palabra en $M_{i+i}$ hasta que la palabra modificada en $M_i$ sea reemplazada o borrada de ese nivel, evitando escrituras innecesarias.

### Modelo de evaluación de la jerarquía

En 1974, C. K. Chow publica su modelo de evaluación del rendimiento de una jerarquía de memoria en *On optimization of storage hierarchies".
Este modelo considera que la política de administración de una memoria se caracteriza por una función de éxito (o tasa de aciertos) $A$.

La tasa de aciertos (*hit ratio*) $A_i$ mide la razón de información buscasa en un ciclo de memoria que se encuentra presente en el nivel $i$, garantizando que en una jerarquía de $n$ niveles, la tasa de aciertos en $A_0$ es $0$ y en $A_n$, $1$.
El valor de $A_i$ depende de $s_i$, la granularidad de la transferencia de información y la estrategia de administración de memoria.
Por su parte, la tasa de fallos (*miss ratio*), mide el complementario a la tasa de aciertos ($1-A_i$).

La frecuencia de accesos $a_i$ mide la probabilidad de acceder con éxito a una información en el nivel $i$ y que dicha información no se encuentre en niveles inferiores.
Debido a que la información de $M_i$ está presente en $M_{i+k}$, se tiene que $a_1=A_1$ y, recursivamente, que $a_n=1-A_{n-1}$.

A la hora de diseñar una memoria con $n$ niveles tenemos como objetivos obtener un rendimiento cercano al de $M_1$ y un coste por bit cercano al de $M_n$.

En cuanto al rendimiento, podemos medir el tiempo de acceso efectivo al nivel i-ésimo de la jerarquía mediante dos recurrencias, donde $t_k$ es el tiempo de acceso medio individual de un nivel $k$:

\begin{center}
$$T_i=\sum_{j=1}^{i}t_k$$
$$\overline{T}=\sum_{i+1}^{n}a_iT_i$$
\end{center}

El coste por bit promedio ($c(n)$) de un sistema de $n$ niveles se calcula de la siguiente manera:

\begin{center}
$$c(n)=\frac{\sum_{i=1}^{n}c_i\cdot s_i}{\sum_{i=1}{n}s_i}+c_0$$
\end{center}

### Problemas a resolver

En cualquier jerarquía de memoria existen cuatro problemas a resolver:

- **Ubicación de bloques:** ¿Dónde se ubicará un bloque en el nivel $i$ cuando se transfiere desde $i+1$?
- **Identificación de bloques:** ¿Cómo se encuentra un bloque en el nivel $i$?
- **Reemplazo de bloques:** Si se produce un fallo en el nivel $i$ y hay que traer un nuevo bloque desde $M_{i+1}$ y suponiendo que $M_i$ está llena, ¿qué bloque del nivel $i$ se reemplaza?
- **Estrategia de escritura:** ¿Qué acciones hay que llevar a cabo si una escritura modifica un bloque en el nivel superior?

## §6.2 - Memorias RAM semiconductoras, memoria de sólo lectura, prestaciones

## §6.3 - Configuración y diseño de memorias utilizando varios chips

## §6.4 - Memorias asociativas

## §6.5 - Memoria caché, influencia en las prestaciones

[^moore]: Según Gordon Moore, "las prestaciones de los procesadores se duplican cada dos años".
En 1994, el DEC Alpha 21164 procesaba una instrucción cada 0,833ns y tardaba en acceder a memoria 60ns.
En 2009, el Intel Core 2 Quad Q9650 tardaba 0,02083ns en procesar una instrucción y 0,75ns en realizar una acceso a memoria.
