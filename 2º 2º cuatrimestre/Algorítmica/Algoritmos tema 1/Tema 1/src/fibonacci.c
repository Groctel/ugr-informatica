#include <stdio.h>

unsigned long Fibonacci (int n) {
	unsigned long resultado;

	if (n<=1)
		resultado = n;
	else
		resultado = Fibonacci(n-1) + Fibonacci(n-2);

	return resultado;
}


int main () {
	int num;

	do {
		printf("%s", "Introduzca un número natural: ");
		scanf("%d", &num);
	} while (num<0);

	printf("El valor de orden %d en la sucesión de Fibonacci es %ld\n",
	      num, Fibonacci(num));

	return 0;
}
