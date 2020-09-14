#################################################
# printf32.s
# gcc -m32 -nostartfiles printf32.s -o printf32
#################################################

.data
i:      .int 12345         # variable entera
f:      .string "i = %d\n" # cadena de formato

#################################################

.text
        .extern printf     # printf en otro sitio
        .globl _start      # función principal

_start: push (i)           # apila i
        push $f            # apila f
        call printf        # llamada a printf
        add  $8, %esp      # restaura pila

        movl  $1, %eax    # exit
        xorl  %ebx, %ebx  # 0
        int   $0x80       # llamada a exit

#################################################
