# TEMA 1 - INTRODUCCIÓN A LA PROGRAMACIÓN ORIENTADA A OBJETOS

## 1.1 - CONCEPTOS BÁSICOS

### 1.1.1 - OBJETO

> Un objeto es una entidad perfectamente delimitada que encapsula estado y funcionamiento y posee una identidad (OMG 2001).

> Un objeto es un elemento, unidad o entidad individual e identificable, real o abstracta, con un papel definido en el dominio del problema (Dictionary of Object Technology 1995).

Esto quiere decir que un objeto es una manifestación manipulable de una idea en un programa informático.
Lo que diferencia al objeto de su idea asociada es que cada objeto procedente de la misma idea tiene propiedades únicas (no necesariamente diferentes) y realiza acciones que la idea le impone.

### 1.1.2 - CLASE

Siguiendo con la definición platónica anterior, una clase es la idea sobre la cual se contruye un objeto.
La clase actúa de molde o plantilla para la creación de objetos, o **instancias** de ella misma.
Definir una clase implica definir un tipo de dato, pudiéndose declarar variables de esa clase si el lenguaje lo permite.

Tomemos, por ejemplo, la clase `Taburete`, que tiene el atributo `int patas`.
Para crear un objeto de la clase `Taburete` debemos llamar a su constructor, acepta un argumento `int` para definir el número de `patas`:

```java
Taburete miTaburete = new Taburete(3);
Taburete tuTaburete = new Taburete(4);
```

En algunos lenguajes de programación las clases son también objetos a todos los efectos.

### 1.1.3 - IDENTIDAD

Cada instancia de una clase tiene su propia identidad que la diferencia del resto de instancias.
Esta identidad queda definida por la posición de memoria que ocupa la instancia, ya que cada objeto debe alojarse en una dirección de memoria distinta aunque tengan las mismas propiedades.

Por ejemplo, si tenemos varios `Taburete` con el mismo número de `patas`, podemos encontrarnos con la situación de que tenemos varios objetos iguales.
Sin embargo, no lo son, ya que podemos ampliar el número de `patas` de uno de ellos sin tener que modificarlos todos.

### 1.1.4 - ESTADO

El estado de un objeto viene definido por los valores que toman sus atributos en cada momento de la ejecución del programa.

### 1.1.5 - COMPORTAMIENTO

Los objetos tienen un comportamiento determinado por los métodos de la clase a partir de la cual se han creado.
Estos métodos pueden llamarse desde otras funciones o métodos para hcer que los objetos interactúen con el programa o entre ellos.

```java
Persona taxo = new Persona("Taxo");
taxo.saluda(); // "Hola, me llamo Taxo."
```

#### Comportamiento externo:

Incluye los métodos accesibles públicamente (`public`) por cualquier otro método del programa.

#### Comportamiento interno:

Incluye los métodos accesibles únicamente de forma interna (`private`).
Es decir, sólo pueden ser llamados desde métodos de su misma instancia.

## 1.2 - PARADIGMA DE LA PROGRAMACIÓN ORIENTADA A OBJETOS

### 1.2.1 - DEFINICIONES

- **Paradigma:** Teoría o conjunto de teorías cuyo núcleo central se acepta sin cuestionar y que suministra la base y modelo para resolver problemas y avanzar en el conocimiento (R.A.E).
- **Paradigma de programación:** Conjunto de reglas que indican cómo desarrollar software.

### 1.2.2 - PROGRAMACIÓN ORIENTADA A OBJETOS (POO)

La POO tiene como base la **unión de los datos y el procesamiento** en entidades llamadas objetos, que son los datos con los que trabaja el software.
Programar en POO consiste en modelar el problema mediante un **universo dinámico de objetos**, cada uno perteneciente a una clase y con una **responsabilidad** dentro del programa.

La funcionalidad del programa se obtiene haciendo que cada objeto le pida a otros (**envío de mensajes**) que haga una tarea (**ejecución de métodos**).
Es importante programar los métodos de forma que cada objeto haga su propia tarea, nunca la de otros objetos.

La cúspide de la POO es un programa en el que la cohesión entre los objetos es máxima y el acoplamiento entre ellos es mínimo.

El paradigma de la POO se basa en los siguientes conceptos:
- Clase
- Objeto o instancia
- Estado
- Identidad
- Mensaje
- Herencia
- Polimorfismo

## 1.3 - EJEMPLOS  DE LA CLASE PERSONA

### 1.3.1 - JAVA

```java
package basico;

enum ColorPelo {
                moreno,
					 castaño,
					 rubio,
					 pelirrojo
					 }

public class Persona {
	private String nombre;
	private int edad;
	private ColorPelo pelo;

	public Persona(String n, int e, ColorPelo p) {
		nombre = n;
		edad = e;
		pelo = p;
	}

	void saluda() {
		System.out.println("Hola, me llamo " + nombre);
	}
}

public class Basico {
	public static void main(String[] args) {
		Persona taxo = new Persona(Taxo, 23, ColorPelo.moreno);
		taxo.saluda();
	}
}
```

### 1.3.2 - RUBY

```ruby
#enconding: UTF-8

module Basico
	module ColorPelo
		moreno= :moreno
		castaño= :castaño
		rubio= :rubio
		pelirrojo= :pelirrojo
	end

	class Persona
		def initialize(n, e, p)
			@nombre=n
			@edad=e
			@pelo=p
		end
	
		public
		def saluda
			puts "Hola, me llamo "+@nombre
		end
	end

	taxo=Perona.new("Taxo", 23, ColorPelo::moreno)
	taxo.saluda
end
```

## 1.4 - PRINCIPIO DE DISEÑO CLASES

Las clases que creemos en POO deben seguir los siguientes principios:
- **Tener una responsabilidad muy concreta:** Si una clase se ocupa de muchas cosas a la vez es muy probable que se pueda dividir en varias clases más pequeñas.
- **Ser autónomas:** Si una clase se ve afectada por cambios realizados en otras es muy probable que tenga responsabilidades que no le corresponden.
- **Ser introvertidas y no altruistas:** El estado de una clase sólo puede modificarse desde ella misma y la clase no puede hacer el trabajo de otras.
