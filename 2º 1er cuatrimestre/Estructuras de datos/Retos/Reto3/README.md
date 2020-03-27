# Reto 3 - T.D.A. lineales

## Enunciado

El reto 3 tiene un planteamiento muy sencillo.
Se trata de implementar la clase `Cola` a partir de la clase `Pila`.
La idea es que disponéis de la clase `Pila` con toda la implementación ya hecha y tenéis que construir la clase `Cola` a partir de esa implementación sin tener que implementar nuevo código, es decir que la implementación de las funciones se hará simplemente llamando a funciones ya implementadas de las pilas.

P.ej. la función `quitar` de la cola se podría construir a partir de la función `quitar` de las pilas.
Para la función `poner` de las colas, probablemente uséis alguna pila auxiliar.

Hay dos niveles en la solución:

**a)** Solución simple, en que solo habríais de indicar cómo y con qué llamadas a las funciones de las pilas se construirían las funciones de las colas.

**b)** Solución compleja, en que habreis de construir la clase `Cola`, compilarla y que funcione.

Podéis optar por resolver el reto usando la STL, de forma que el reto se convierte en hacer funcionar el tipo `queue` a partir del tipo `stack`.
