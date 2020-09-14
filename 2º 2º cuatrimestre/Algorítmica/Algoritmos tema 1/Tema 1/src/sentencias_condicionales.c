#include <stdio.h>

int main() {
	int n;

	printf("%s: ", "Introduzca un número");
	scanf("%d", &n);

	if (n%2)
		printf("%d es un número impar.\n", n);
	else {
		for (int i=0; i<n; i++)
			printf("%d, ", n);

		printf("\n");
	}
}
