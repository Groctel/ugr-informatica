// gcc -Og -S sum.c [-fno-asynchronous-unwind-tables]
// gcc -Og -c sum.c ; objdump -d sum.o

long plus(long, long);

void sumstore(long x, long y, long *dest) {
  long t = plus(x, y);
  *dest = t;
}
