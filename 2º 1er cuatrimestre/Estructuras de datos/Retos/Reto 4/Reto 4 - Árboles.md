# §1 - ENUNCIADO

Dar un procedimiento para guardar un árbol binario en disco de forma que se recupere la estructura jerárquica de forma unívoca usando el mínimo número de centinelas que veais posible.
Es una competición para conseguir dar la mejor solución, que será la que use un menor número de datos para el proceso de salvado a disco del árbol binario.

\pagebreak

# §2 - AXIOMAS SOBRE LA ESTRUCTURA

Para la resolución de este ejercicio tomamos como axiomáticas las siguientes propiedades de los árboles binarios:

- **1:** Cada nodo de un árbol binario tiene, como mucho, dos hijos identificados por su posición ($T_{izq}$ y $T_{der}$).
- **2:** En cada nivel de un árbol binario hay un máximo de $2^i$ nodos.

# §3 - IDENTIFICACIÓN UNÍVOCA

Como consecuencia del primer axioma, podemos identificar cada hijo de un nodo como un valor binario que, en lugar de ser $T_{izq}$ y $T_{der}$, puede adoptar otros valores.
Para reducir el consumo de espacio en disco lo identificaremos como bits, siendo $T_{izq}=0$ y $T_{der}=1$.

Recursivamente, podemos identificar unívocamente cada nodo mediante una secuencia de bits que indica el camino más corto para llegar al mismo.
De esta manera, el nodo raíz no necesita identificarse mediante ningún valor, ya que no hay que dar ningún salto para llegar a él.

Ésta sería la estructura de un árbol binario representado como secuencia de bits:

\begin{center}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			[.$[1,1]$
				$[1,1,1]$
				$[1,1,0]$
			]
			[.$[1,0]$
				$[1,0,1]$
				$[1,0,0]$
			]
		]
		[.$[0]$
			[.$[0,1]$
				$[0,1,1]$
				$[0,1,0]$
			]
			[.$[0,0]$
				$[0,0,1]$
				$[0,0,0]$
			]
		]
	]
\end{tikzpicture}
\end{center}

\pagebreak

# §4 - RECORRIDO POR NIVELES DE UN ÁRBOL IDENTIFICADO UNÍVOCAMENTE

Para recorrer un árbol identificado unívocamente utilizando el mínimo número de datos auxiliares posibles (cero, como se demuestra al final del ejercicio) utilizamos el recorrido por niveles.

Basándonos en el segundo axioma e identificando cada nodo de un nivel $i$ como un número binario de $i$ bits, podemos ordenar los identificadores unívocos de los nodos de izquierda a derecha para crear una tabla de número binarios ordenados desde $0_00_10_2\cdots0_{i-2}0_{i-1})_2$ a $1_01_11_2\cdots1_{i-2}1_{i-1})_2$.
Por ejemplo, en el tercer nivel de un árbol binario tendríamos estos identificadores unívocos expresados como número binarios de tres cifras:

| $k_0$ | $k_1$ | $k_2$ |
| :---: | :---: | :---: |
|  $0$  |  $0$  |  $0$  |
|  $0$  |  $0$  |  $1$  |
|  $0$  |  $1$  |  $0$  |
|  $0$  |  $1$  |  $1$  |
|  $1$  |  $0$  |  $0$  |
|  $1$  |  $0$  |  $1$  |
|  $1$  |  $1$  |  $0$  |
|  $1$  |  $1$  |  $1$  |

Conocida esta estructura, podemos establecer un orden numérico de menor a mayor que se corresponda con el orden de derecha a izquierda dentro del nivel[^ordennivel].
Utilizaremos esta propiedad para el algoritmo de recuperación de árboles desde fichero en §8.

\pagebreak

# §5 - ALMACENAMIENTO DEL ÁRBOL EN MEMORIA

Para almacenar el árbol utilizamos dos vectores: uno que almacene las posiciones de los nodos y otro que almacene el valor de cada nodo.

## §5.1 - VECTOR DE POSICIONES

Declaramos el vector de posiciones como un vector que almacena vectores de bits.
Para rellenar este vector se recorre el árbol por niveles, aprovechando la propiedad presentada en §4, de forma que los nodos que se representan en él quedan ordenados de izquierda a derecha en cada uno de los niveles.
La clase `vector` de la STL nos garantiza que no tendremos que preocuparnos por el tamaño del vector ni ninguno de sus subvectores a la hora de recuperar la información del mismo.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			\edge[blank]; $\ $
			[.$[1,0]$
				$[1,0,1]$
				\edge[blank]; $\ $
			]
		]
		[.$[0]$
			$[0,1]$
			[.$[0,0]$
				$[0,0,1]$
				$[0,0,0]$
			]
		]
	]
\end{tikzpicture}

$\Big[[\ ],[0],[1],[0,0],[0,1],[1,0],[0,0,0],[0,0,1],[1,0,1]\Big]$
\end{center}

## §5.2 - VECTOR DE VALORES

Este vector no es más que un vector del tipo de dato que se guarda en el árbol.
Se rellena a la vez que el vector de posiciones, almacenando cada uno de los valores en la misma posición del vector que la de su posición correspondiente en el árbol.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$A$
		[.$C$
			\edge[blank]; $\ $
			[.$F$
				$I$
				\edge[blank]; $\ $
			]
		]
		[.$B$
			$E$
			[.$D$
				$H$
				$G$
			]
		]
	]
\end{tikzpicture}

$\Big[A,B,C,D,E,F,G,H,I\Big]$
\end{center}

# §6 - RECUPERACIÓN DESDE MEMORIA

A la hora de recuperar la información del árbol binario a partir de estos dos vectores simplemente necesitamos iterar por el vector de posiciones (y por cada una de las posiciones) a la vez que por el vector de valores, asignando a cada posición $n$ su correspondiente valor $n$ del vector de valores.

Si únicamente queremos guardar el árbol en memoria principal, podemos simplificar el vector de posiciones a las hojas del árbol, ya que de éstas se infiere el resto de la estructura del mismo:

\begin{center}
$\Big[[\ ],[0],[1],[0,0],[0,1],[1,0],[0,0,0],[0,0,1],[1,0,1]\Big]$
$\rightarrow$
$\Big[[0,1],[0,0,0],[0,0,1],[1,0,1]\Big]$
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$x$
		\edge[blank]; [.$\ $
			\edge[blank]; $\ $
			\edge[blank]; [.$\ $
				\edge[blank]; $\ $
				\edge[blank]; $\ $
			]
		]
		[.$x$
			$x$
			\edge[blank]; [.$\ $
				\edge[blank]; $\ $
				\edge[blank]; $\ $
			]
		]
	]
\end{tikzpicture}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$x$
		\edge[blank]; [.$\ $
			\edge[blank]; $\ $
			\edge[blank]; [.$\ $
				\edge[blank]; $\ $
				\edge[blank]; $\ $
			]
		]
		[.$x$
			$\ $
			[.$x$
				\edge[blank]; $\ $
				$x$
			]
		]
	]
\end{tikzpicture}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$x$
		\edge[blank]; [.$\ $
			\edge[blank]; $\ $
			\edge[blank]; [.$\ $
				\edge[blank]; $\ $
				\edge[blank]; $\ $
			]
		]
		[.$x$
			$\ $
			[.$x$
				$x$
				$\ $
			]
		]
	]
\end{tikzpicture}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$x$
		[.$x$
			\edge[blank]; $\ $
			[.$x$
				$x$
				\edge[blank]; $\ $
			]
		]
		[.$\ $
			$\ $
			[.$\ $
				$\ $
				$\ $
			]
		]
	]
\end{tikzpicture}

$[0,1]\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ [0,0,0]\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ [0,0,1]\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ [1,0,1]$
\end{center}

# §7 - ALMACENAMIENTO EN FICHEROS

Para desperdiciar el mínimo número de bits en la escritura a disco del árbol, lo almacenamos en un fichero binario que iremos leyendo bit a bit en §8.
Seguimos los siguientes pasos para almacenarlo:

Primero almacenamos el vector de posiciones bit a bit sin ningún tipo de separadores:

\begin{center}
$\Big[[\ ],[0],[1],[0,0],[0,1],[1,0],[0,0,0],[0,0,1],[1,0,1]\Big]$

\texttt{01000110000001101}
\end{center}

Para indicar el final del vector, buscamos el primer nodo que no se ha incluido en el vector ($[1,1]$ en este caso) y lo añadimos al final del mismo:

\begin{center}
\texttt{0100011000000110111}
\end{center}

Por último, añadimos los ceros necesarios a la derecha para completar los bytes.

\begin{center}
\texttt{01000110 00000110 11100000}\ \rightarrow\ \texttt{4606e0}
\end{center}

\pagebreak

Debemos tener en cuenta que, en un árbol binario completo, el siguiente nodo no incluido es el siguiente nodo en el orden por niveles que estamos utilizando.
Para subsanar esto, a costa de perder eficiencia de guardado en casos extremos, distinguimos dos tipos de árboles completos:

- **Árboles cuyos niveles están todos completos menos el último[^completo]:** Añadimos artificialmente un nodo en el siguiente nivel y a la izquierda (compuesto únicamente por ceros) y añadimos el que sería el siguiente nodo no incluido.
- **Árboles cuyos niveles están todos completos:** Añadimos artificialmente un nodo en el siguiente nivel y a la izquierda y otro nodo inferior y a la izquierda del mismo. Luego añadimos como primer nodo no incluido el que se encontraría a la izquierda del que hemos incluido.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		$[1]$
		[.$[0]$
			$[0,1]$
			[.$[0,0]$
				\edge[blank]; $\ $
				\edge[blank]; $\ $
			]
		]
	]
\end{tikzpicture}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		$[1]$
		[.$[0]$
			$[0,1]$
			[.$[0,0]$
				\edge[blank]; $\ $
				$[0,0,0]$
			]
		]
	]
\end{tikzpicture}

Árbol de primer tipo con cadena de bits \texttt{01000100010} (\texttt{4440})

\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			$[1,1]$
			$[1,0]$
		]
		[.$[0]$
			$[0,1]$
			[.$[0,0]$
				\edge[blank]; $\ $
				\edge[blank]; [.$\ $
					\edge[blank]; $\ $
					\edge[blank]; $\ $
				]
			]
		]
	]
\end{tikzpicture}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			$[1,1]$
			$[1,0]$
		]
		[.$[0]$
			$[0,1]$
			[.$[0,0]$
				\edge[blank]; $\ $
				[.$[0,0,0]$
					\edge[blank]; $\ $
					$[0,0,0,0]$
				]
			]
		]
	]
\end{tikzpicture}

Árbol de segundo tipo con cadena de bits \texttt{01000110110000000001} (\texttt{46c010})
\end{center}

Abordaremos la recreación de este tipo de árboles en §8.

Tras esto, introducimos cada uno de los elementos del vector de valores en el formato deseado, por ejemplo, en `char` de $8$ bits.
Hecho esto, tenemos el fichero guardado con el mínimo número de bits desperdiciados posible.

# §8 - RECUPERACIÓN DESDE FICHEROS

Conocida la propiedad secuencial de los nodos de un mismo nivel (§4), podemos crear un algoritmo que reconstruya el árbol con las siguientes normas:

- El primer elemento del árbol es redundante y no se representa en el vector de posiciones.
- Cada vez que se lee una nueva posición se debe tener en cuenta:
  - **El nivel en el que nos encontramos:** Indica el número de bits que se van a leer.
  - **El siguiente nodo si el árbol fuera completo:** Se busca el nodo con el valor binario inmediatamente superior (`0110` tras `0101`).
  - **Nodos inexistentes:** No es necesario iterar por nodos descendencia de nodos inexistentes.
- La lectura de la siguiente posición busca el nodo inmeditamente superior y lo compara los el valor obtenido:
  - **Si se ha leído un valor superior:** Se marcan como inexistentes todos los nodos entre el inmediatamente superior (inclusive) y el leído (no inclusive).
  - **Si se ha leído un valor inferior:** Se añade un nuevo bit a la dirección, registrando un salto de nivel y marcando los nodos restantes en el nivel anterior como inexistentes si los hubiese.
  - **Si la lectura llega a un nodo inexistente:** Se descartan los bits leídos hasta el primer nodo inexistente y tantos bits como fueran necesarios para que todos los bits leídos hasta el momento fuesen multiplo de $8$ (es necesario llevar la cuenta).

Tras leer el árbol, podemos encontrarnos con que tenga la estructura de árbol completo expuesta en §7. Esto se comprueba fácilmente porque el número de elementos de todos los niveles $i\in\{0\cdots n-3\}$ de sus $n$ niveles vale $2^i$.
Si, hecho esto, nos encontrásemos con que el número de elementos de su nivel nivel $n-2$ valiese $2^i$ y el número de elementos de su nivel $n-1$ valiese $1$, estaríamos ante un árbol binario completo de primer tipo.
Si, en otro caso, el número de elementos de sus niveles $n-2$ y $n-1$ valiese $1$, estaríamos ante un árbol binario completo de segundo tipo.
Debemos tener en cuenta que es posible que simplemente estemos recuperando un árbol con una de estas dos estructuras, que será la opción por la que optaremos para rellenarlo.
Debido a esto, consideraremos la posibilidad de que nos falte un elemento a la hora de rellenar un árbol binario completo de primer tipo o exactamente dos elementos a la hora de rellenar un árbol binario completo de segundo tipo.
En caso de que nos faltaran, eliminaríamos los nodos sobrantes y tendríamos el árbol perfectamente reconstruido.

Para rellenar el árbol, simplemente leeremos los elementos del mismo y los introduciremos por niveles, teniendo en cuenta las especificidades de los posibles árboles binarios completos descritas.

# §9 - EJEMPLO PRÁCTICO

## §9.1 - ÁRBOL BINARIO NO COMPLETO[^arbolejemplo]

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$*$
		[.$+$
			$h$
			$g$
		]
		[.$+$
			[.$+$
				$f$
				[.$*$
					[.$+$
						$e$
						$d$
					]
					$c$
				]
			]
			[.$+$
				$b$
				$a$
			]
		]
	]
\end{tikzpicture}
\end{center}

### §9.1.1 - ALMACENAMIENTO

Antes de empezar, comprobamos que el nivel $3$, que es el nivel $n-3$ es el primero en no tener $2^i$ nodos, por lo que no nos encontramos ante una estructura de árbol binario completo.

Creamos el vector de posiciones y lo codificamos:

\begin{center}
$\Big[[\ ],[0],[1],[0,0],[0,1],[1,0],[1,1],[0,0,0],[0,0,1],[0,1,0],[0,1,1],[0,1,0,0],[0,1,0,1],$

$[0,1,0,1,0],[0,1,0,1,1]\Big]$

\texttt{01000110 11000001 01001101 00010101 01001011 10000000}\ \rightarrow\ \texttt{46c14d154b80}
\end{center}

Almacenamos uno a uno todos los caracteres teniendo en cuenta que son `char`:

| **CHAR** | **HEX** | **CHAR** | **HEX** |
| :------: | :-----: | :------: | :-----: |
|   `*`    |  `0x2a` |   `d`    |  `0x64` |
|   `+`    |  `0x2b` |   `e`    |  `0x65` |
|   `a`    |  `0x61` |   `f`    |  `0x66` |
|   `b`    |  `0x62` |   `g`    |  `0x67` |
|   `c`    |  `0x63` |   `h`    |  `0x68` |

\begin{center}
\texttt{2a2b2b2b2b676861622a66632b6465}
\end{center}

Creamos un fichero binario con todos estos valores en secuencia:

```
46 c1 4d 15 4b 80 2a 2b 2b 2b 2b 67 68 61 62 2a 66 63 2b 64 65
```

Hemos almacenado el árbol en un fichero binario de $21$ bytes.

### §9.1.2 - RECUPERACIÓN

Nuestro algoritmo comienza añadiendo la raíz del árbol y leyendo el primer byte:

`0x46 = 01000110`

El primer bit es `0`, por lo que añadimos un hijo $[0]$ a la raíz.
Lo mismo con el siguiente bit, que es `1`.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		$[1]$
		$[0]$
	]
\end{tikzpicture}
\end{center}

Finalizado el primer nivel, pasamos el segundo, por lo que leemos de dos en dos bits.
Buscamos el `00` y lo encontramos.
Lo mismo ocurre con el `01` y el `10`.
Leemos el siguiente byte (`11000001`) buscando en sus dos primeros bits el `11` y, en efecto, los encontramos.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			$[1,1]$
			$[1,0]$
		]
		[.$[0]$
			$[0,1]$
			$[0,0]$
		]
	]
\end{tikzpicture}
\end{center}

Pasamos ahora al tercer nivel, leyendo de tres en tres bits.
Buscamos el `000` y lo encontramos.
También encontramos el `001` y en el siguiente bit (`01001101`) encontramos el `010` y el `011`.
Sin embargo, cuando esperamos encontrar el `100`, nos encontramos con que el bit más significativo del siguiente es `0`, por lo que es menor que el valor que estamos buscando.
Anotamos el `100` como el primer nodo no incluido y leemos cuatro bits, es decir, los dos que nos quedan de este byte y los dos del siguiente (`00010101`).
Encontramos así el `0100`, por lo que no existen nodos `0000`, `0001`, `0010` ni `0011`.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			$[1,1]$
			$[1,0]$
		]
		[.$[0]$
			[.$[0,1]$
				$[0,1,1]$
				[.$[0,1,0]$
					\edge[blank]; $\ $
					$[0,1,0,0]$
				]
			]
			[.$[0,0]$
				$[0,0,1]$
				$[0,0,0]$
			]
		]
	]
\end{tikzpicture}
\end{center}

Siguiendo el algoritmo, encontramos el nodo `0101` y, en el siguiente nivel y contando con el siguiente byte (`01001011`), los nodos `01010` y `01011`.

En el siguiente byte (`10000000`) nos encontramos con el nodo `100000`, que contiene el primer nodo no incluido (`100`) y una secuencia de ceros hasta rellenar el byte.
Encontrado el primer nodo no incluido, damos por finalizada la construcción del árbol.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		[.$[1]$
			$[1,1]$
			$[1,0]$
		]
		[.$[0]$
			[.$[0,1]$
				$[0,1,1]$
				[.$[0,1,0]$
					[.$[0,1,0,1]$
						$[0,1,0,1,1]$
						$[0,1,0,1,0]$
					]
					$[0,1,0,0]$
				]
			]
			[.$[0,0]$
				$[0,0,1]$
				$[0,0,0]$
			]
		]
	]
\end{tikzpicture}
\end{center}

Hecho esto, comprobamos que el nivel $3$, que es el nivel $n-3$ es el primero en no tener $2^i$ nodos.
Sin embargo, los dos niveles siguientes no tienen ni $2^i$ para $n-2$ ni $1$ para $n-1$, por lo que no nos encontramos ante una posible estructura de árbol completo.
Por último, iteramos por el resto de bytes, que sabemos que son de tipo `char` y rellenamos el árbol por niveles.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$*$
		[.$+$
			$h$
			$g$
		]
		[.$+$
			[.$+$
				$f$
				[.$*$
					[.$+$
						$e$
						$d$
					]
					$c$
				]
			]
			[.$+$
				$b$
				$a$
			]
		]
	]
\end{tikzpicture}
\end{center}

## §9.2 - ÁRBOL BINARIO COMPLETO

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$a$
		$c$
		[.$b$
			$e$
			$d$
		]
	]
\end{tikzpicture}
\end{center}

### §9.2.1 - ALMACENAMIENTO

Antes de empezar, identificamos que todos los niveles tienen $2^i$ nodos excepto el último, por lo que debemos añadir un nuevo nodo para crear la estructura de árbol completo.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$a$
		$c$
		[.$b$
			$e$
			[.$d$
				\edge[blank]; $\ $
				$\ $
			]
		]
	]
\end{tikzpicture}
\end{center}

Creamos el vector de nodos y lo codificamos:

\begin{center}
$\Big[[],[0],[1],[0,0],[0,1],[0,0,0]\Big]$

\texttt{01000100 010000000}\ \rightarrow\ \texttt{4440}
\end{center}

Almacenamos uno a uno los datos, de tipo `char`.
Tenemos en cuenta que no almacenamos el dato del nodo auxiliar, ya que no existe.

\begin{center}
\texttt{61 62 63 64 65}
\end{center}

Creamos un fichero binario con todos estos valores en secuencia:

```
44 40 61 62 63 64 65
```

Hemos almacenado el árbol en un fichero binario de $7$ bytes.

### §9.2.2 - RECUPERACIÓN

Haciendo uso del algoritmo ya desarrollado en §9.1.2, recuperamos la estructura del árbol:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		$[1]$
		[.$[0]$
			$[0,1]$
			[.$[0,0]$
				\edge[blank]; $\ $
				$[0,0,0]$
			]
		]
	]
\end{tikzpicture}
\end{center}

Identificamos que el primer nivel en no tener $2^i$ nodos es el $n-2$ y que el siguiente nivel, $n-1$ tiene exactamente un nodo, por lo que debemos tener en cuenta que, si nos faltase un dato, estaríamos ante un árbol de tipo completo.
Rellenamos secuencialmente el árbol.

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$a$
		$c$
		[.$b$
			$e$
			[.$d$
				\edge[blank]; $\ $
				$\ $
			]
		]
	]
\end{tikzpicture}
\end{center}

Como observamos que, efectivamente, nos falta un dato para un nodo, eliminamos dicho nodo y recuperamos totalmente la estructura del árbol:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$a$
		$c$
		[.$b$
			$e$
			$d$
		]
	]
\end{tikzpicture}
\end{center}

## §9.3 - ÁRBOL VACÍO

### §9.3.1 - ALMACENAMIENTO

Un árbol vacío es un árbol binario completo de segundo tipo.
Para almacenarlo, creamos dos nodos auxiliares:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$[\ ]$
		\edge[blank]; $\ $
		[.$[0]$
			\edge[blank]; $\ $
			$[0,0]$
		]
	]
\end{tikzpicture}
\end{center}

Creamos el vector de posiciones y lo codificamos:

\begin{center}
\Big[[],[0],[0,0]\Big]

\texttt{00010000}\ \rightarrow\ \texttt{00}
\end{center}

Como no tenemos datos, creamos el fichero binario con el único byte que tenemos.

```
10
```

Hemos almacenado el árbol en un fichero de un byte.

### §9.3.2 - RECUPERACIÓN

El algoritmo recupera los nodos `0` y `00`.
Tras esto, sólo queda asumir que tenemos un árbol de tres nodos sin datos.
Como no estamos utilizando ningún centinela en el algoritmo, esta situación sólo puede darse si el árbol no tiene ningún nodo.
Se elimina el trabajo realizado y el árbol queda perfectamente recuperado.

\pagebreak

# §10 - EPÍLOGO: UN BIT POR NODO

> "¿Es éste el final? ¿Es el final un crecimiento del tamaño ocupado por cada nodo y un cómputo dependiente de un algoritmo que debe lidiar con casos potenciales para ciertos tipos de árboles? ¿Es el final una solución no generalizada?"
>
> Cuestiones inquisitivas y punzantes rondaban mi mente, turbando mis infructuosos intentos de sueño.
>
> "No." Le susurré a la oscuridad.

Según el primer axioma, podemos determinar el número máximo de nodos que puede tener el siguiente nivel de nuestro árbol binario, que es $2\cdot k$, donde $k$ es el número de nodos que tiene el nivel actual.
Sabiendo esto, podemos asignar **individualmente** un bit a cada nodo que indique su estado: `1` si existe, `0` si no.
Aislados los nodos existentes, limitamos la progresión del árbol a ellos, asignando en cada nivel un bit por nodo existente.
El árbol §9.1 quedaría así:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$*$
		[.$+$
			$h$
			$g$
		]
		[.$+$
			[.$+$
				$f$
				[.$*$
					[.$+$
						[.$e$
							\edge[blank]; $\ $
						]
						$d$
					]
					$c$
				]
			]
			[.$+$
				$b$
				$a$
			]
		]
	]
\end{tikzpicture}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			[.$1$
				$0$
				$0$
			]
			[.$1$
				$0$
				$0$
			]
		]
		[.$1$
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					[.$1$
						[.$1$
							$0$
							$0$
						]
						[.$1$
							$0$
							$0$
						]
					]
					[.$1$
						$0$
						$0$
					]
				]
			]
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					$0$
					$0$
				]
			]
		]
	]
\end{tikzpicture}
\end{center}

De nuevo, el almacenamiento del árbol se haría por niveles, guardando la siguiente cadena de bits sin necesidad de generar un vector de posiciones:

\begin{center}
\texttt{11111111 11000000 00110000 11000000}\ \rightarrow\ \texttt{ff c0 30 c0}
\end{center}

En comparación con el sistema de identificación unívoca, este modelo de guardado de árboles se presenta superior en tamaño de escritura de datos para árboles completos:

| NIVELES | IDENTIFICACIÓN UNÍVOCA       | UN BIT POR NODO     |
| :-----: | :--------------------------: | :-----------------: |
|   $0$   | `00010000`                   | `00000000`          |
|   $1$   | `01000010`                   | `11000000`          |
|   $2$   | `01000110 11000000 00000000` | `11111100 00000000` |
|   $3$   | `01000110 11000001 01001110 01011101 11000000 00000010` | `11111111 11111100 00000000 00000000` |

Observamos que la mejora en eficiencia es aplastante ya en un árbol completo de tres niveles.
También se mejora la eficiencia en árboles no completos, como es el caso del árbol §9.1.
Es más, es muy probable que sea matemáticamente imposible reducir más la estructura de un árbol binario.

Una grandísima ventaja de almacenar un bit por nodo es que no debemos preocuparnos por posibles árboles completos, ya que éstos se reconstruyen en al igual que el resto de árboles: asignando los nodos existentes y obviando el resto.

## §10.1 - RECONSTRUCCIÓN BIT A BIT DE UN ÁRBOL BINARIO

Reconstruyamos el árbol §9.1:

\begin{center}
\texttt{11111111 11000000 00110000 11000000}
\end{center}

Partimos de la raíz (que por ahora suponemos que existe) y sus dos hijos potenciales:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		$\ $
		$\ $
	]
\end{tikzpicture}
\end{center}

Como tenemos dos posibles hijos, leemos dos bits y asignamos a cada uno su bit correspondiente de izquierda a derecha:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		$1$
		$1$
	]
\end{tikzpicture}
\end{center}

\pagebreak

Dado que al menos uno de los bits leídos es $1$, sabemos que existela raíz y no nos encontramos ante un árbol vacío.
Asignamos dos hijos potenciales a cada nodo:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			$\ $
			$\ $
		]
		[.$1$
			$\ $
			$\ $
		]
	]
\end{tikzpicture}
\end{center}

Leemos cuatro bits y asignamos hijos potenciales:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			[.$1$
				$\ $
				$\ $
			]
			[.$1$
				$\ $
				$\ $
			]
		]
		[.$1$
			[.$1$
				$\ $
				$\ $
			]
			[.$1$
				$\ $
				$\ $
			]
		]
	]
\end{tikzpicture}
\end{center}

Leemos ocho bits y asignamos hijos potenciales:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			[.$1$
				$0$
				$0$
			]
			[.$1$
				$0$
				$0$
			]
		]
		[.$1$
			[.$1$
				[.$1$
					$\ $
					$\ $
				]
				[.$1$
					$\ $
					$\ $
				]
			]
			[.$1$
				[.$1$
					$\ $
					$\ $
				]
				[.$1$
					$\ $
					$\ $
				]
			]
		]
	]
\end{tikzpicture}
\end{center}

Leemos ocho bits y asignamos hijos potenciales:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			[.$1$
				$0$
				$0$
			]
			[.$1$
				$0$
				$0$
			]
		]
		[.$1$
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					[.$1$
						$\ $
						$\ $
					]
					[.$1$
						$\ $
						$\ $
					]
				]
			]
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					$0$
					$0$
				]
			]
		]
	]
\end{tikzpicture}
\end{center}

Leemos cuatro bis y asignamos hijos potenciales:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			[.$1$
				$0$
				$0$
			]
			[.$1$
				$0$
				$0$
			]
		]
		[.$1$
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					[.$1$
						[.$1$
							$\ $
							$\ $
						]
						[.$1$
							$\ $
							$\ $
						]
					]
					[.$1$
						$0$
						$0$
					]
				]
			]
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					$0$
					$0$
				]
			]
		]
	]
\end{tikzpicture}
\end{center}

Leemos cuatro bits y asignamos hijos potenciales:

\begin{center}
\tikzset{blank/.style={draw=none}}
\begin{tikzpicture}[grow'=down]
\Tree
	[.$\ $
		[.$1$
			[.$1$
				$0$
				$0$
			]
			[.$1$
				$0$
				$0$
			]
		]
		[.$1$
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					[.$1$
						[.$1$
							$0$
							$0$
						]
						[.$1$
							$0$
							$0$
						]
					]
					[.$1$
						$0$
						$0$
					]
				]
			]
			[.$1$
				[.$1$
					$0$
					$0$
				]
				[.$1$
					$0$
					$0$
				]
			]
		]
	]
\end{tikzpicture}
\end{center}

Al no poder asignar más hijos potenciales al árbol, damos por finalizada su reconstrucción.
Este método no requiere crear nodos potenciales para evitar colisiones con referencias a nodos no utilizados, como ocurre en con la identificación unívoca.
También tiene la ventaja de que se puede conocer la estructura del árbol de forma más intuitiva, ya que un árbol vacío es simplemente `0x00` y no `0x10`.

Dando esta estructura de almacenamiento y recuperación, podemos afirmar con total certeza que estamos guardando árboles binarios sin centinelas, sin ayuda de algoritmos complejos o que deban considerar casos límite y, muy probablemente, de la forma más reducida matemáticamente posible.

[^ordennivel]: También podríamos identificarlos convirtiendo la secuencia de bits que los identifica a un número decimal, de forma que la secuencia $[0,0,1,0]$ pasaría a ser el nodo $2$ del nivel $4$.
No optamos por esta solución porque habría que tener en cuenta el número de nodos por nivel y realizar diferentes estructuras acorde con estas limitaciones, además de que se desperdiciaría espacio en todos los niveles que no fuesen el $1$ o potencia de $2$ inferiores a $8$, que, al menos en C++, no implementan un tipo de dato para tales números de bits.

[^arbolejemplo]: Este árbol se encuentra ilustrado como ejemplo de árboles de expresión en la transparencia 25 del material de clase.

[^completo]: Si le faltan más nodos que el posicionado más a la derecha, pero todos a la derecha del último nodo, no se trata de un árbol binario completo estrcictamente hablando, pero presenta el mismo problema que uno que cumpla dicha propiedad.

