# APÉNDICE A - INSTRUCCIONES MÁQUINA

Todas las instrucciones ensamblador sobre valores enteros vienen sucedidas de uno de estos cuatro caracteres:

- **`b`:** La operación se realiza sobre un *byte*, los ocho bits menos significativos.
- **`w`:** La operación se realiza sobre una palabra (*word*), los dos bytes menos significativos.
- **`l`:** La operación se realiza sobre una palabra larga (*long*), los cuatro bytes menos significativos.
- **`q`:** La operación se realiza sobre una palabra cuádruple (*quad*), los ocho bytes menos significativos.

Por ejemplo, no es lo mismo `movb` que `movq`, ya que el primero mueve un byte y el segundo, ocho.

En caso de que se trabaje sobre valores de coma flotante, vienen sucedidas de unos de estos tres caracteres:

- **`s`:** La operación se realiza sobre un *single* (*float*), los cuatro bytes menos significativos.
- **`l`:** La operación se realiza sobre un *double* (*long float*), los ocho bytes menos significativos.
- **`t`.** La operación se realiza sobre un *extended* (*long double*), los diez, doce o dieciséis bytes menos significativos.

## `add`

**Sinopsis:** `add src, dst`

Almacena el resultado de sumar `src` y `dst` en `dst`.

## `and`

**Sinopsis:** `and src, dst`

Almacena el resultado de realizar un `and` bit a bit entre `src` y `dst` en `dst`.

+:---------------+:-----------------------------------+
| `src`          | `01010101001001010101011011010101` |
+:---------------+:-----------------------------------+
| `dst`          | `10101001010101010010101010100100` |
+:---------------+:-----------------------------------+
| `xor src, dst` | `00000001000001010000001010000100` |
+:---------------+:-----------------------------------+

## `call`

**Sinopsis:** `call lbl`

Salta a la etiqueta `lbl`, actualizando la pila mediante `push`.

## `cmp`

**Sinopsis:** `cmp src2, src1`

Realiza la operación $src1-src2$ sin ajustar el destino, guardando el estado de la misma en los flags correspondientes.

## `dec`

**Sinopsis:** `dec dst`

Decrementa el valor de `dst` en `1`.

## `imul`

**Sinopsis:** `imul src, dst`

Almacena el resultado de multiplicar `src` y `dst` en `dst`.

## `inc`

**Sinopsis:** `inc dst`

Incrementa el valor de `dst` en `1`.

## `j`

**Sinopsis:** `jop rtn`

Salta a una rutina `rtn` si la operación `op` sobre diferentes flags de estado devuelve `1`.

| `jtop` | Operación      | Descripción              |
| :----: | :------------- | :----------------------- |
| `jmp`  | `1`            | Salto incondicional      |
|  `je`  | `ZF`           | Equal / Zero             |
| `jne`  | `~ZF`          | Not equal / Not zero     |
|  `js`  | `SF`           | Sign (negativo)          |
| `jns`  | `~SF`          | Not sign                 |
|  `jg`  | `~(SF^OF)&~ZF` | Greater (signo)          |
| `jge`  | `~(SF^OF)`     | Greater or equal (signo) |
|  `jl`  | `(SF^OF)`      | Less (signo)             |
| `jle`  | `(SF^OF)|ZF`   | Less or equal (signo)    |
|  `ja`  | `~CF&~ZF`      | Above (sin singno)       |
|  `jb`  | `CF`           | Below (sin signo)        |

## `lea`

**Sinopsis:** `lea src, dst`

Calcula, sin activar ninguna flag, la dirección de memoria (*load effective address*) `src` y la almacena en `dst`.
Dicha dirección de memoria está expresada en modo de direccionamiento completo.
También se usa para calcular operaciones con menos coste, por ejemplo `var*12`:

```asm
leaq (%rdi, %rdi, 2), %rax # x+x*2 = x*3
salq $2,              %rax # x<<2  = x*4
```

## `mov`

**Sinopsis:** `mov src, dst`

Almacena el valor `src` en la ubicación de destino `dst`.
Estos datos pueden ser literales inmediatos (`$0xf` ó `$-38`), registros enteros (`%rax` o `%r12`) y direcciones de memoria (`(%rax)` o `(%rdx)`).

| `src`    | `dst`    | Instrucción        | Análogo C      |
| :------- | :------- | :----------------- | :------------- |
| Literal  | Registro | `mov $0xa, %rax`   | `var = 0xa;`   |
| Literal  | Memoria  | `mov $0xa, (%rax)` | `*ptr = 0xa;`  |
| Registro | Registro | `mov %rax, %rdx`   | `var2 = var1;` |
| Registro | Memoria  | `mov %rax, (%rdx)` | `*ptr = var;`  |
| Memoria  | Registro | `mov (%rax), %rdx` | `var = ptr;`   |

No se puede transferir de memoria a memoria con una sola instrucción `mov`.

## `neg`

**Sinopsis:** `neg dst`

Transforma `dst` en su opuesto ($-1$ contra $1$).

## `not`

**Sinopsis:** `not dst`

Transforma todos los bits de `dst` en su correspondiente opuesto.

+:----------+:-----------------------------------+
| `dst`     | `10101001010101010010101010100100` |
+:----------+:-----------------------------------+
| `not dst` | `01010110101010101101010101011011` |
+:----------+:-----------------------------------+

## `or`

**Sinopsis:** `or src, dst`

Almacena el resultado de realizar un `or` bit a bit entre `src` y `dst` en `dst`.

+:---------------+:-----------------------------------+
| `src`          | `01010101001001010101011011010101` |
+:---------------+:-----------------------------------+
| `dst`          | `10101001010101010010101010100100` |
+:---------------+:-----------------------------------+
| `xor src, dst` | `11111101011101010111111011110101` |
+:---------------+:-----------------------------------+

## `pop`

**Sinopsis:** `pop dst`

Lee el valor almacenado en el tope de la pila (`(%rsp)`), lo escribe en `dst` y incrementa `%rsp` en `8`.

## `push`

**Sinopsis:** `push src`

Decrementa el puntero de pila (`%rsp`) en `8` y escribe `src` en `(%rsp)`.

## `rep` (no escrito)

**Sinopsis:** `rep`

## `ret`

**Sinopsis:** `ret`

Finaliza una rutina y devuelve el programa al estado de la rutina anterior en la pila, sobre la que se hace `pop`.

## `sal` (no escrito)

## `sar` (no escrito)

## `set`

**Sinopsis:** `setop dst`

Ajusta el LSByte del registro `dst` en función de la operación `op` indicada:

| `setop` | Operación      | Descripción              |
| :-----: | :------------- | :----------------------- |
| `sete`  | `ZF`           | Equal / Zero             |
| `setne` | `~ZF`          | Not equal / Not zero     |
| `sets`  | `SF`           | Sign (negativo)          |
| `setns` | `~SF`          | Not sign                 |
| `setg`  | `~(SF^OF)&~ZF` | Greater (signo)          |
| `setge` | `~(SF^OF)`     | Greater or equal (signo) |
| `setl`  | `(SF^OF)`      | Less (signo)             |
| `setle` | `(SF^OF)|ZF`   | Less or equal (signo)    |
| `seta`  | `~CF&~ZF`      | Above (sin singno)       |
| `setb`  | `CF`           | Below (sin signo)        |

## `shr` (no escrito)

## `sub`

**Sinopsis:** `sub src, dst`

Almacena el resultado de restar `src` a `dst` en `dst`.

## `test`

**Sinopsis:** `test src2, src1`

Realiza la operación `src1&src2` sin ajustar el destino, guardando el estado de la misma en los flags correspondientes.
Es una oepración útil cuando uno de los operandos es una máscara.

## `xor`

**Sinopsis:** `xor src, dst`

Almacena el resultado de realizar un `xor` bit a bit entre `src` y `dst` en `dst`.

+:---------------+:-----------------------------------+
| `src`          | `01010101001001010101011011010101` |
+:---------------+:-----------------------------------+
| `dst`          | `10101001010101010010101010100100` |
+:---------------+:-----------------------------------+
| `xor src, dst` | `11111100011100000111110001110001` |
+:---------------+:-----------------------------------+

