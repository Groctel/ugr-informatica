
sum3:     formato del fichero elf64-x86-64


Desensamblado de la sección .init:

00000000004003b8 <_init>:
  4003b8:	48 83 ec 08          	sub    $0x8,%rsp
  4003bc:	48 8b 05 2d 0c 20 00 	mov    0x200c2d(%rip),%rax        # 600ff0 <__gmon_start__>
  4003c3:	48 85 c0             	test   %rax,%rax
  4003c6:	74 02                	je     4003ca <_init+0x12>
  4003c8:	ff d0                	callq  *%rax
  4003ca:	48 83 c4 08          	add    $0x8,%rsp
  4003ce:	c3                   	retq   

Desensamblado de la sección .text:

00000000004003d0 <main>:
  4003d0:	b8 2d 00 00 00       	mov    $0x2d,%eax
  4003d5:	c3                   	retq   
  4003d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4003dd:	00 00 00 

00000000004003e0 <_start>:
  4003e0:	31 ed                	xor    %ebp,%ebp
  4003e2:	49 89 d1             	mov    %rdx,%r9
  4003e5:	5e                   	pop    %rsi
  4003e6:	48 89 e2             	mov    %rsp,%rdx
  4003e9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4003ed:	50                   	push   %rax
  4003ee:	54                   	push   %rsp
  4003ef:	49 c7 c0 30 05 40 00 	mov    $0x400530,%r8
  4003f6:	48 c7 c1 c0 04 40 00 	mov    $0x4004c0,%rcx
  4003fd:	48 c7 c7 d0 03 40 00 	mov    $0x4003d0,%rdi
  400404:	ff 15 ee 0b 20 00    	callq  *0x200bee(%rip)        # 600ff8 <__libc_start_main@GLIBC_2.2.5>
  40040a:	f4                   	hlt    
  40040b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000400410 <deregister_tm_clones>:
  400410:	55                   	push   %rbp
  400411:	b8 20 10 60 00       	mov    $0x601020,%eax
  400416:	48 3d 20 10 60 00    	cmp    $0x601020,%rax
  40041c:	48 89 e5             	mov    %rsp,%rbp
  40041f:	74 17                	je     400438 <deregister_tm_clones+0x28>
  400421:	b8 00 00 00 00       	mov    $0x0,%eax
  400426:	48 85 c0             	test   %rax,%rax
  400429:	74 0d                	je     400438 <deregister_tm_clones+0x28>
  40042b:	5d                   	pop    %rbp
  40042c:	bf 20 10 60 00       	mov    $0x601020,%edi
  400431:	ff e0                	jmpq   *%rax
  400433:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400438:	5d                   	pop    %rbp
  400439:	c3                   	retq   
  40043a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400440 <register_tm_clones>:
  400440:	be 20 10 60 00       	mov    $0x601020,%esi
  400445:	55                   	push   %rbp
  400446:	48 81 ee 20 10 60 00 	sub    $0x601020,%rsi
  40044d:	48 89 e5             	mov    %rsp,%rbp
  400450:	48 c1 fe 03          	sar    $0x3,%rsi
  400454:	48 89 f0             	mov    %rsi,%rax
  400457:	48 c1 e8 3f          	shr    $0x3f,%rax
  40045b:	48 01 c6             	add    %rax,%rsi
  40045e:	48 d1 fe             	sar    %rsi
  400461:	74 15                	je     400478 <register_tm_clones+0x38>
  400463:	b8 00 00 00 00       	mov    $0x0,%eax
  400468:	48 85 c0             	test   %rax,%rax
  40046b:	74 0b                	je     400478 <register_tm_clones+0x38>
  40046d:	5d                   	pop    %rbp
  40046e:	bf 20 10 60 00       	mov    $0x601020,%edi
  400473:	ff e0                	jmpq   *%rax
  400475:	0f 1f 00             	nopl   (%rax)
  400478:	5d                   	pop    %rbp
  400479:	c3                   	retq   
  40047a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400480 <__do_global_dtors_aux>:
  400480:	80 3d 95 0b 20 00 00 	cmpb   $0x0,0x200b95(%rip)        # 60101c <_edata>
  400487:	75 17                	jne    4004a0 <__do_global_dtors_aux+0x20>
  400489:	55                   	push   %rbp
  40048a:	48 89 e5             	mov    %rsp,%rbp
  40048d:	e8 7e ff ff ff       	callq  400410 <deregister_tm_clones>
  400492:	c6 05 83 0b 20 00 01 	movb   $0x1,0x200b83(%rip)        # 60101c <_edata>
  400499:	5d                   	pop    %rbp
  40049a:	c3                   	retq   
  40049b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4004a0:	f3 c3                	repz retq 
  4004a2:	0f 1f 40 00          	nopl   0x0(%rax)
  4004a6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004ad:	00 00 00 

00000000004004b0 <frame_dummy>:
  4004b0:	55                   	push   %rbp
  4004b1:	48 89 e5             	mov    %rsp,%rbp
  4004b4:	5d                   	pop    %rbp
  4004b5:	eb 89                	jmp    400440 <register_tm_clones>
  4004b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4004be:	00 00 

00000000004004c0 <__libc_csu_init>:
  4004c0:	41 57                	push   %r15
  4004c2:	41 56                	push   %r14
  4004c4:	49 89 d7             	mov    %rdx,%r15
  4004c7:	41 55                	push   %r13
  4004c9:	41 54                	push   %r12
  4004cb:	4c 8d 25 4e 09 20 00 	lea    0x20094e(%rip),%r12        # 600e20 <__frame_dummy_init_array_entry>
  4004d2:	55                   	push   %rbp
  4004d3:	48 8d 2d 4e 09 20 00 	lea    0x20094e(%rip),%rbp        # 600e28 <__init_array_end>
  4004da:	53                   	push   %rbx
  4004db:	41 89 fd             	mov    %edi,%r13d
  4004de:	49 89 f6             	mov    %rsi,%r14
  4004e1:	4c 29 e5             	sub    %r12,%rbp
  4004e4:	48 83 ec 08          	sub    $0x8,%rsp
  4004e8:	48 c1 fd 03          	sar    $0x3,%rbp
  4004ec:	e8 c7 fe ff ff       	callq  4003b8 <_init>
  4004f1:	48 85 ed             	test   %rbp,%rbp
  4004f4:	74 20                	je     400516 <__libc_csu_init+0x56>
  4004f6:	31 db                	xor    %ebx,%ebx
  4004f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4004ff:	00 
  400500:	4c 89 fa             	mov    %r15,%rdx
  400503:	4c 89 f6             	mov    %r14,%rsi
  400506:	44 89 ef             	mov    %r13d,%edi
  400509:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40050d:	48 83 c3 01          	add    $0x1,%rbx
  400511:	48 39 dd             	cmp    %rbx,%rbp
  400514:	75 ea                	jne    400500 <__libc_csu_init+0x40>
  400516:	48 83 c4 08          	add    $0x8,%rsp
  40051a:	5b                   	pop    %rbx
  40051b:	5d                   	pop    %rbp
  40051c:	41 5c                	pop    %r12
  40051e:	41 5d                	pop    %r13
  400520:	41 5e                	pop    %r14
  400522:	41 5f                	pop    %r15
  400524:	c3                   	retq   
  400525:	90                   	nop
  400526:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40052d:	00 00 00 

0000000000400530 <__libc_csu_fini>:
  400530:	f3 c3                	repz retq 

Desensamblado de la sección .fini:

0000000000400534 <_fini>:
  400534:	48 83 ec 08          	sub    $0x8,%rsp
  400538:	48 83 c4 08          	add    $0x8,%rsp
  40053c:	c3                   	retq   
