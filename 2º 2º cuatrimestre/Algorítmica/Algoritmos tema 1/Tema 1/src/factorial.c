#include <stdio.h>

unsigned long Factorial (int n) {
	unsigned long resultado;

	if (n<=1)
		resultado = 1;
	else
		resultado =  n * Factorial(n-1);

	return resultado;
}


int main () {
	int num;

	do {
		printf("%s ", "Introduzca un número natural:");
		scanf("%d", &num);
	} while (num<0);

	printf("%d! = %ld\n", num, Factorial(num));

	return 0;
}
