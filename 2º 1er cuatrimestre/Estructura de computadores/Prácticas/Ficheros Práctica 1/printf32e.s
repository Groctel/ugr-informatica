#################################################
# printf32e.s
# gcc -m32 -nostartfiles printf32e.s -o printf32e
#################################################

.data
i:      .int 12345         # variable entera
f:      .string "i = %d\n" # cadena de formato

#################################################

.text
        .extern exit       # exit en otro sitio
        .extern printf     # printf en otro sitio
        .globl _start      # función principal

_start: push (i)           # apila i
        push $f            # apila f
        call printf        # llamada a función
        add  $8, %esp      # restaura pila

        push $0            # 0
        call exit          # llamada a función

#################################################
