# PRÁCTICA 2 - PROGRAMACIÓN ENSAMBLADOR x86-64 LINUX

## §2.1 - gcc

Partiendo de los ficheros `sum.c` y `msum.c`, vamos a compilarlos con gcc:

```bash
# Compilación normal
gcc sum.c msum.c -o sum
# Compilación sin ejecutable independientes de posición (pie)
gcc -no-pie sum.c msum.c -o sum_nopie
```

Vamos a definir dos variables para ahorrarnos escribir opciones excesivamente largas y compilar pasando por código ensamblador y módulos objeto:

```bash
# Declaramos las variables
FNSP="-fno-stack-protector"
FNAUT="-fno-asynchronous-unwind-tables"
# Traducimos los ficheros C a ficheros ensamblador
gcc -Og -S sum.c $FNAUT
gcc -Og -S msum.c $FNAUT $FNSP
# Creamos los módulos objeto
gcc -c sum.s msum.s
# Enlazamos ambos módulos y creamos el ejecutable
gcc -no-pie sum.o msum.o -o sum
```

## §2.2 - as y ld

Vamos a introducir a mano las instrucciones de ensamblado y enlace con `as` y `ld` respectivamente:

```bash
# Creamos los ficheros en ensamblador
gcc -Og -S sum.c msum.c $FNAUT $FNSP
# Ensamblamos cada fichero en su correspondiende móulo objeto
as sum.s -o sum.o
as msum.s -o msum.o
# Enlazamos ambos módulos objeto
ld sum.o msum -o sum
# WARNING: Cannot find entry symbol _start;
# Para subsanar esto, llamamos al enlazador dinámico de /lib64
# También usamos crt?.o (crt1.o y otros) para enlazar
# Estos últimos se encuentra en /usr/lib en la mayoría de sistemas
ld sum.o msum.o -o sum -dynamic-linker /lib64/ld-linux-x86-64.so.2 \
                                       /usr/lib/crt?.o -lc
```

## §2.3 - Código ensamblador y código máquina

Tengamos el siguiente fragmento de código C de `sum.c`:

```c
long plus (long x, long y) {
	// ...
}

void sumstore (long x, long y, long *dest) {
	long t = plus(x, y);
	*dest = t;
}
```

Traduciéndolo a lenguaje ensamblados mediante las órdenes de §2.2, obtenemos un fichero similar a éste:

```asm
	.file  "sum.c"
	.text
	.globl sumstore
	.type sumstore, @function
sumstore:
	pushq %rbx
	movq  %rdx, %rbx
	call  plus@PLT
	movq  %rax, (%rbx)
	popq  %rbx
	ret
	.size     sumstore, .-sumstore
	.ident    "GCC: (GNU) 9.2.0"
	.senction .note.GNU-stack,"",@progbits
```

Ésta es una versión legible del código máquina en el que después se convertirá el ejecutable.
Esta transformación se hace paso a paso, volcando cada instrucción de código ensamblador en el ejecutable traducida a código máquina.
Dentro del código ensamblador podemos ver el nombre del fichero (`.file`), el inicio del texto (`.text`), que son las instrucciones, la declaración de la rutina `sumstore` (`.globl` y `.type`) junto con sus instrucciones y el tamaño de la misma (`.size`), que se calcula en tiempo de ensamblado como la diferencia entre el tamaño total del ejecutable justo al acabar de escribir dicha rutina, referenciado por el puntero de posiciones (`.`) y la posición en la que comienza el texto de la rutina.

## §2.4 - objdump y nm

Al ensamblar un fichero de código nos quedamos con un módulo objeto que no es legible, ya que contiene código máquina, pero el programa `objdump -d` nos permite desensamblarlo y leer sus instrucciones.
Sin argumentos, `objdump` nos muestra todas las posibles opciones de ejecución con las que permite trabajar.

Con `nm` podemos ver todos los símbolos que forman el fichero, por ejemplo `sum.o` contiene el súmbolo `sumstore` y `msum.o`, `main` y `plus`.
Ninguno de los dos tiene `_start`, que es por lo que tuvimos que llamar a las bibliotecas del sistema con el enlazador en §2.2.

## §2.5 - Llamadas al sistema en ensamblador

Tengamos el siguiente programa en código ensamblador:

```asm
.section .data
saludo:		.ascii "Hola a todos."
longsaludo:	.quad	 .-saludo

.section .text
.global _start
_start:
	mov $1,         %rax
	mov $1,         %rdi
	mov $saludo,    %rsi
	mov longsaludo, %rdx
	syscall

	mov $60, %rax
	mov $0,  %rdi
	syscall
```

Lo compilamos con las siguiente órdenes:

```bash
as saludo.s -o saludo.o
ld saludo.o -o saludo
```

La primera sección, `.data`, almacena los datos conocidos en tiempo de compilación, que son el `saludo` y su longitud.
La segunda contiene el código para realizar la llamada del sistema `WRITE`, consultable mediante la orden `man 2 write`[^mansyscall].

`WRITE` tiene la siguiente sintaxis:

```
ssize_t write(int fd, const void *buf, size_t count);
```

Para llamar a `write`, cargamos el valor `$1` en `%rax`.
Como argumentos, cargamos el descriptor de fichero (`$1`) en `%rdi`, el buffer (`$saludo`), en `%rsi`, y la longitud del mismo (`longsaludo`), en `%rdx`.
Definida la llamada y cargados los argumentos, la realizamos con `syscall`, que transfiere el control del programa al kernel para que la ejecute.

Devuelto el control del kernel a la rutina, cargamos la llamada del sistema `return` (`$60`) con valor de retono `0` y la enviamos para cerrar el programa informando de su correcto funcionamiento.

## §2.6 - Llamadas a subrutinas en ensamblador

Tengamos el siguiente programa en código ensamblador:

```asm
.section .data
lista:     .int 1,2,10,1,2,0b10,1,2,0x10
longlista: .int (.-lista)/4
resutlado: .int 0
formato:   .asciz "suma = %u = 0x%x hex\n"

.section .text
_start: .global _start
	call trabajar
	call acabar

trabajar:
	mov  $lista,     %rbx
	mov  longlistsa, %ecx
	call suma
	mov  %eax,       resultado
	ret

suma:
	push %rdx
	mov  $0, %eax
	mov  $0, %rdx

	bucle:
		add  (%rdb,%rdx,4), %eax
		inc  %edx
		comp %edx,          %ecx
		jne  bucle

	pop  %rdx
	ret

acabar:
	mov $60,       %rax
	mov resultado, %edi
	syscall
	ret
```

Lo compilamos con las siguiente órdenes:

```bash
as suma.s -o suma.o
ld suma.o -o suma -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
```

Este programa empieza llamando a la subrutina `trabajar`, que carga la `$lista` en `%rbx` y su longitud en `%rcx` y llama a `suma`.
Por su parte, `suma` almacena el valor que hubiese en `%rdx` en la pila para poder modificarlo libremente sin sobreescribirlo e iguala `%eax` (que será el resultado de la suma) y `%edx` (el índice del bucle que se va a ejecutar) a cero.
Dentro del bucle, añadimos a `%eax` el valor del elemento `%rdx` de la lista e incrementamos `%edx` hasta que sea igual que `%ecx` (como un bucle `for` en C).
Por último, llamamos a `return` y devolvemos el valor de la suma (debería ser `37`).

Los valores `0b10` y `0x10` representan los valores decimales `2` en octal y `16` en hexadecimal respectivamente.

## §2.7 -

[^mansyscall]: La sintaxis general de llamadas al sistema puede consultarse con `man 2 syscall`.
