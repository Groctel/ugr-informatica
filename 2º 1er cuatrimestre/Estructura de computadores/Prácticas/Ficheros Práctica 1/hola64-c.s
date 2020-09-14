.data
msg:    .string "¡hola, mundo!"

.text
        .extern exit
        .extern puts
        .global _start

_start:
        push %rbp         # preserva ebp
        mov  %rsp, %rbp   # copia pila

        mov $msg, %rdi    # apila msg
        call puts         # llamada a puts

        xor %rdi, %rdi    # valor de retorno
        call exit         # llamada a exit
