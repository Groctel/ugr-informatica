// gcc -Og -o prog main.c mstore.c [-no-pie]; objdump -d prog

#include <stdio.h>

void multstore(long x, long y, long *dest);

int main() {
    long d;
    multstore(2, 3, &d);
    printf("2 * 3 --> %ld\n", d);
    return 0;
}

long mult2(long a, long b) {
    long s = a * b;
    return s;
}
