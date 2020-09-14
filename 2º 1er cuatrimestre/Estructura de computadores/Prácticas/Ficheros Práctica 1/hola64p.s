.text
        .global _start

write:  movq  $0x2020200a216f646e, %rax # "  \n!odn"
        push  %rax                      # apilar
        movq  $0x756d202c616c6f68, %rax # "um ,aloh"
        push  %rax                      # apilar
        mov   $1, %rax                  # write
        mov   $1, %rdi                  # stdout
        mov   %rsp, %rsi                # texto
        mov   $13,  %rdx                # tamaño
        syscall                         # sistema
        add    $16, %rsp                # pila intacta
        ret                             # retorno

exit:   mov   $60,  %rax                # exit
        xor   %rdi, %rdi                # 0
        syscall                         # sistema

_start: call  write                     # llamada a función
        call  exit                      # llamada a función
