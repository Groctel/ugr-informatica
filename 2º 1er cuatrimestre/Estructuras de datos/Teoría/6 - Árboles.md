# 6 - ÁRBOLES

## §6.1 - DEFINICIONES

- **Nodo:** Cada uno de los elementos de un árbol.
- **Hermanos:** Nodos que se encuentran en el mismo nivel.
- **Hijo:** Nodo que parte de otro nodo, llamado padre.
- **Padre:** Nodo del cual parten otros nodos, llamados hijos.
- **Raíz:** Único nodo del que parten el resto de nodos.

## §6.2 - CONCEPTOS GENERALES

Decimos que un árbol está **etiquetado** si todos sus nodos contienen una etiqueta, por ejemplo, una letra que los identifique unívocamente.

Todos los nodos tienen un **grado**, definido como el número de hijos que tiene dicho nodo.
Llamamos **hojas o nodos terminales** a los nodos de grado 0 y *nodos interiores o no terminales** al resto. El grado de un árbol es el máximo de los grados de sus nodos.

Definimos el **camino** entre dos nodos $n_i$ y $n_j$ como la secuencia más corta de nodos necesaria para alcanzar el nodo $n_j$ partiendo desde $n_i$.
Este camino comienza con el nodo $n_i$ y acaba con el nodo $n_j$, sin excluir ninguno de los dos.
La **longitud** de este camino cuenta el número de *saltos* que se dan en el mismo, por lo que es equivalente al número de nodos que conforman el camino menos $1$.

Definimos el **nivel** de un nodos como la longitud del camino entre él mismo y la raíz del árbol.
Por tanto, el nivel de la raíz es $0$ y el nivel de todos los hijos de un nodo de nivel $i$ es $i+1$.
Igualmente, el nivel del padre de un nodo de nivel $i$ es $i-1$. La **profundidad** de un árbol es el máximo de los niveles de los nodos de dicho árbol.

## §6.3 - ÁRBOLES N-ARIOS

Los árboles n-arios se basan en que cada nodo del árbol es un árbol n-ario.
Si el árbol tiene un único nodo, entonces éste es el nodo raíz, del cuál parten el resto de árboles-nodo.
Recurrentemente, si $n$ es un nodo y $T_1,T_2,\cdots,T_k$, árboles con raíces $n_1,n_2,\cdots,n_k$ respectivamente, podemos construir un nuevo árbol que tenga como raíz el nodo $n$ del cual parten los subárboles $T_1,T_2,\cdots,T_k$.

### §6.3.1 - RECORRIDO

Podemos recorrer árboles n-arios en profundidad de tres formas diferentes:

- **Preorden:** Empezando por la raíz, se recorre el árbol por los nodos más a la izquierda hasta llegar a una hoja, tras la cual se sube de nivel y se recorren los hijos que se han obviado en los nodos padres hasta llegar a la hoja más a la derecha del árbol. Este proceso se sigue para todos los subárboles, que se recorren de izquierda a derecha.
- **Inorden:** Empezando por la hoja más a la izquierda del subárbol más a la izquierda, se recorre hacia arriba hasta encontrar un nodo con más subárboles, con los que se repite la misma operación. Al llegar a la raíz, se repite este mismo proceso con el subárbol inmediatamente a la derecha del que se acaba de recorrer.
- **Postorden:**

También podemos recorrerlo en anchura por niveles.
Este recorrido comienza en el nodo raíz y va pasando por cada uno de los niveles de izquierda a derecha.

## §6.4 - ÁRBOLES BINARIOS

Los árboles binarios se basan en que cada nodo tiene, como mucho, dos hijos que se identifican como $T_{izq}$ y $T_{der}$.
La diferencia de un árbol binario con un árbol n-ario de grado 2 es que la posición de los hijos es imprescindible en su definición.
Un árbol vacío es un árbol binario y, recurrentemente, podemos crear un nuevo árbol de la misma forma que con los n-arios siempre que respetemos la posición de los subárboles.

Un **árbol binario homogéneo** es aquél cuyos nodos tienen grado $0$ ó $2$, pero nunca $1$.
Un **árbol binario completo** es aquél cuyos niveles están todos completos excepto, quizá, el último, en cuyo caso los huecos deben quedar a la derecha del árbol.
En este último tipo de árbol, el camino más largo de la raíz a las hojas no atraviesa más de $log_2n$ nodos.

El número máximo de nodos que puede haber en un nivel $i$ de un árbol binario es $2^i$ y el número máximo de nodos en un árbol binario completo de altura $k$ es $2^{k+1}-1$.
