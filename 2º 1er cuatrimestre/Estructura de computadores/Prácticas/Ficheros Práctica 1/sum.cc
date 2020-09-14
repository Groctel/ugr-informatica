int main()
{
  int sum = 0;

  for (int i = 0; i < 10; ++i)
    sum += i;

  return sum;
}

//g++     sum.cc   -o sum
//objdump -d sum
//00000000004005b0 <main>:
//  4005b0:	55                   	push   %rbp
//  4005b1:	48 89 e5             	mov    %rsp,%rbp
//  4005b4:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
//  4005bb:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
//  4005c2:	eb 0a                	jmp    4005ce <main+0x1e>
//  4005c4:	8b 45 f8             	mov    -0x8(%rbp),%eax
//  4005c7:	01 45 fc             	add    %eax,-0x4(%rbp)
//  4005ca:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
//  4005ce:	83 7d f8 09          	cmpl   $0x9,-0x8(%rbp)
//  4005d2:	7e f0                	jle    4005c4 <main+0x14>
//  4005d4:	8b 45 fc             	mov    -0x4(%rbp),%eax
//  4005d7:	5d                   	pop    %rbp
//  4005d8:	c3                   	retq   

//g++ -O3 sum.cc -o sum
//objdump -d sum
//00000000004004c0 <main>:
//  4004c0:       b8 2d 00 00 00          mov    $0x2d,%eax
//  4004c5:       c3                      retq   

