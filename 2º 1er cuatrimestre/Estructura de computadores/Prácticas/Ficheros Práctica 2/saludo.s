.section .data
saludo:		.ascii	"Hola a todos!\nHello, World!\n"
longsaludo:	.quad	.-saludo

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

