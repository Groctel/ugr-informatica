# PUNTEROS

## 1 - EL TIPO DE DATO PUNTERO

Un puntero `*` es un dato que ***apunta* a una dirección de memoria** en la que se encuentra un dato del tipo del puntero. Más específicamente, apunta a la dirección de memoria donde *empieza* el dato referenciado. Si no se encuentra incializado, el puntero apunta a la dirección nula `0`.

### 1.1 - DECLARACIÓN Y DIRECCIÓN

Declaramos un puntero indicando el tipo de dato (**dato base**) al que queremos apuntar. Este tipo de dato es fijo y el puntero no puede apuntar a otros datos.

```c++
int *ptrint; // dato_base *nombre
char *ptrchar;
int *ptr1, *ptr2, entero;
```

Al declarar un puntero sólo indicamos su tipo de dato. Para indicar a qué dirección apunta debemos usar el operador direccional `&` en la sentencia de asignación correspondiente:

```c++
int numero = 5, *ptr;
ptr = &numero; // puntero = &variable

// TODO: Ver qué tipo de error se produce al apuntar a datos incorrectos
```

Decimos que `ptr` *apunta a* `numero` tras esta asignación, que también puede hacerse en una sola línea:

```c++
int numero = 5, *ptr = &numero;
```

Con un puntero también podemos apuntar a posiciones de un vector:

```c++
int primos[5] = {2, 3, 5, 7, 11}, *ptr = &primos[0];
```

Debemos tener en cuenta que las siguientes afirmaciones para que la asignación sean correctas:
- El puntero está ligado al mismo tipo de dato que el vector.
  - En casos más complejos (vectores de vectores), la dirección de memoria referenciada dentro del vector es del tipo de dato del puntero.
- La posición del vector a la que se apunta se es inferior al tamaño total del vector.

La dirección de memoria a la que apunta un puntero puede cambiarse en cualquier momento:

```c++
int primos[5] = {2, 3, 5, 7, 11}, *ptr = &primos[0]; // ptr -> 2
ptr = &primos[2]; // ptr -> 5
```

Como un puntero es un dato que se aloja en una dirección de memoria, podemos hacer que un puntero apunte a otro. **TODO: Ver si un puntero a `dato *` está ligado a `dato` y a `*`.**

```c++
int numero = 5;
int *ptr = &numero; // ptr -> numero = 5
int **p_ptr = &ptr; // p_ptr -> ptr -> numero = 5
```

###### UN PUNTERO DEBE REFERENCIAR SIEMPRE A UN DATO YA INICIALIZADO

### 1.2 - ESCRITURA Y LECTURA DE UN PUNTERO (INDIRECCIÓN)

Mediante un puntero podemos asignar valores a la variable asociada a él o leer sus datos. Es muy importante tener en cuenta que para direccionar, escribir o leer datos del puntero debemos llamarlo con el prefijo `*`.

```c++
char c, *ptr = &c; // c = BASURA, ptr -> c
*ptr = 'A'; // ptr -> c, por tanto, c = 'A'
cout << *ptrc << " " << c << endl; // A A

int numero = 5, cuadrado, *ptr = &numero; // numero = 5, ptr -> 5
cuadrado = pow(*ptr, 2); // ptr -> 5, por tanto, cuadrado = 5^2
cout << resultado << endl; // 25
```

Estas operaciones de lectura-escritura nos permiten realizar operaciones aritmético-lógicas complejas usando punteros. Por ejemplo, podemos intercambiar el valor de dos variables:

```c++
int a = 1, b = 2, cambio;
cout << a << " " << b; // 1 2

cambio = *p1;
*p1 = *p2;
*p2 = cambio;
cout << "\n" << a << " " << b; // 2 1
```



```c++
void intercambia(int *p1, int *p2) {
   int tmp; // almacenamiento temporal
   tmp = *p1;
   *p1 = *p2;
   *p2 = tmp;
}

int main() {
   int a = 1, b = 2, cambio;

   cout << a << " " << b; // 1 2
   intercambia (&a, &b); // Usamos & porque los parámetros formales son punteros
   cout << "\n" << a << " " << b; // 2 1
}
```

## 2 - STRUCT Y PUNTEROS

## 3 - VECTORES Y PUNTEROS

## 4 - MATRICES Y PUNTEROS

## 5 - CADENAS Y PUNTEROS

## 6 - MATRICES BIDIMENSIONALES Y VECTORES DE PUNTEROS

## 7 - PUNTEROS A FUNCIONES