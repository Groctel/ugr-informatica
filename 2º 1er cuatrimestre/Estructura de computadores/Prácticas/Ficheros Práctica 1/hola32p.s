.text                     # sección de código
        .globl _start     # punto de entrada

write:  pushl $0x2020200a # "  \n"
        pushl $0x216f646e # "!odn"
        pushl $0x756d202c # "um ,"
        pushl $0x616c6f68 # "aloh"
        movl  $4, %eax    # write
        movl  $1, %ebx    # salida estándar
        movl  %esp, %ecx  # cadena
        movl  $13, %edx   # longitud
        int   $0x80       # llamada al sistema
        addl  $16, %esp   # restaura pila
        ret               # retorno a _start

exit:   movl  $1, %eax    # exit
        xorl  %ebx, %ebx  # 0
        int   $0x80       # llamada al sistema

_start: call  write       # llamada a función
        call  exit        # llamada a función

