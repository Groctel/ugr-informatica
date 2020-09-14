// gcc -Og -o sum msum.c sum.c [-no-pie] [-g]; objdump -d sum
// ./sum; echo $?

void sumstore(long x, long y, long *dest);

int main() {
    long d;
    sumstore(2, 3, &d);
    return d;
}

long plus(long a, long b) {
    long s = a + b;
    return s;
}
