# Nombre archivo: makefile
# Uso: make 
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

LIB_DIR=./

programa2: main2.o factorial.o hello.o libmates.a
	g++ -L$(LIB_DIR) -o $@ $^

main2.o: main2.cpp functions.h mates.h 
	g++ -c main2.cpp

factorial.o: factorial.cpp functions.h
	g++ -c factorial.cpp

hello.o: hello.cpp functions.h
	g++ -c hello.cpp

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o

sin.o: sin.cpp mates.h
	g++ -c sin.cpp

cos.o: cos.cpp mates.h
	g++ -c cos.cpp

tan.o: tan.cpp mates.h
	g++ -c tan.cpp

cleanAll: cleanObj cleanLib
	rm programa2

cleanObj:
	rm main2.o factorial.o hello.o

cleanLib:
	rm sin.o cos.o tan.o libmates.a
