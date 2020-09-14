# PRÁCTICA 1 - ENTORNO DE DESARROLLO GNU

## §1.1 - Flags de 80x86

Los sistemas de arquitectua 80x86 tienen una serie de banderas (flags[^flagswiki]) que son bits de un registro (`eflags`) que se activan en función del resultado de la última operación realizada.

| BIT  | Flag   | Significado    | BIT  | Flag  | Significado               |
| :--: | :----- | :------------- | :--: | :---- | :------------------------ |
| `0`  | `CF`   | Carry flag     | `16` | `RF`  | Resume flag               |
| `1`  | `1`    | `1` lógico     | `17` | `VM`  | Virtual mode              |
| `2`  | `PF`   | Parity flag    | `18` | `AC`  | Alignment check           |
| `3`  | `0`    | `0` lógico     | `19` | `VIF` | Virtual interrupt flag    |
| `4`  | `AF`   | Adjust flag    | `20` | `VIP` | Virtual interrupt pending |
| `5`  | `0`    | `0` logico     | `21` | `ID`  | CPUID instructions        |
| `6`  | `ZF`   | Zero flag      | `22` | `0`   | `0` lógico                |
| `7`  | `SF`   | Sign flag      | `23` | `0`   | `0` lógico                |
| `8`  | `TF`   | Trap flag      | `24` | `0`   | `0` lógico                |
| `9`  | `IF`   | Interrupt flag | `25` | `0`   | `0` lógico                |
| `10` | `DF`   | Direction flag | `26` | `0`   | `0` lógico                |
| `11` | `OF`   | Overflow       | `27` | `0`   | `0` lógico                |
| `12` | `IOPL` | Privilegio E/S | `28` | `0`   | `0` lógico                |
| `13` | `IOPL` | Privilegio E/S | `29` | `0`   | `0` lógico                |
| `14` | `NT`   | Nested task    | `30` | `0`   | `0` lógico                |
| `15` | `0`    | `0` lógico     | `31` | `0`   | `0` lógico                |

Estos flags no se ven afectados por la instrucción `lea`.

## §1.2 - Programa mínimo en C

Tengamos un programa en C que no realiza ninguna operación.
Podemos escribirlo de varias formas equivalentes:

**minimo1.c**

```c
int main() { }
```

**minimo2.c**

```c
int main() {
	return 0;
}
```

**minimo3.c**

```c
#include <stdlib.h>

int main() {
	exit(0);
}
```

Podemos compilarlos haciendo uso de `gcc`:

```bash
gcc minimo1.c -o minimo1
```

Analizamos con `file` el ejecutable creado:

```bash
file minimo1
```

Analizamos sus símbolos con `nm`:

```bash
nm minimo1
```

Al ejecutarlo no se produce ninguna salida, pero eso no significa que no contenga nada.
Podemos desensamblarlo con `objdump`:

```bash
objdump -d minimo1
```

Vemos las llamadas al sistema que produce su ejecución con `strace`:

```bash
strace ./minimo1
```

Vemos las llamadas de biblioteca que produce el programa con `ltrace`:

```bash
ltrace ./minimo1
```

Vemos las bibliotecas que utiliza el programa durante su ejecución con `ldd`:

```bash
ldd minimo1
```

La segunda línea muestra la biblioteca de C a la que llama el proceso al ejecutarse.
Su valor cambiará en función de la distribución de Linux utilizada.
Por ejemplo, en Ubuntu se encuentra en `/lib64/` por herencia de Debian mientras que en Arch se encuentra en `/usr/lib/`.
Podemos ejecutar `objdump` sobre esta biblioteca para examinarla.

## §1.3 - Secciones básicas de un programa en ensamblador

Un programa escrito en ensamblador tiene dos secciones claramente diferenciadas: los datos y las instrucciones.

Los **datos** se referencian con una línea de texto `.data`.
Tras ella se encuentran todos los datos constantes y variables declarados en tiempo de compilación.
Las **instrucciones** se referencian con una línea de texto `.text`.
Tras ella se encuentran definidas todas las rutinas utilizadas por el programa y las instrucciones ensamblador que las conforman.

```asm
.data
msg:    .string "Hola, mundo\n"
tam:    .quad . - msg

.text
        .global _start

write:  mov  $1,   %rax
        mov  $1,   %rdi
        mov  $msg, %rsi
        mov  tam,  %rdx
        syscall
        ret

exit:   mov  $60,  %rax
        xor  %rdi, %rdi
        syscall
        ret

_start: call write
        call exit
```

En este programa podemos ver que se han creado en tiempo de compilación la cadena de caracteres `msg` y el entero `tam`, que almacena el tamaño de `msg`.
Las instrucciones comienzan con `_start`, que llama a `write`.
En esta rutina, primero se mueve el valor `$1` a `%rax` para llamar al sistema con dicho valor y así ejecutar la orden `write` en él.
Para decirle al sistema qué queremos escribir, cargamos sus argumentos en los registros correspondientes[^dsdc89] (pueden referenciarse en `man 2 write`).
Cargamos `$1` en `%rdi` para indicar que el `fd` usado es `stdout`, `$msg` como búfer de salida en `%rsi` y `tam` como tamaño del búfer.
Luego, llamamos a `syscall` para que el sistema procese esta información y volvemos a la rutina anterior con `ret`.
En `exit`, preparamos la llamada al sistema `60` y le asignamos como primer argumento el valor `0`, que calculamos de forma óptima haciendo `xor` bit a bit en `%rdi`.
Volvemos a la rutina anterior y cerramos el programa.

[^flagswiki]: Más información en la [wikipedia](https://en.wikipedia.org/wiki/FLAGS_register)

[^dsdc89]: El orden en que se cargan los argumentos es siempre `%rdi`, `%rsi`, `%rdx`, `%r8` y `%r9`, que responde a la regla mnemotécnica *Diane's silk dress costs 89\$*.
