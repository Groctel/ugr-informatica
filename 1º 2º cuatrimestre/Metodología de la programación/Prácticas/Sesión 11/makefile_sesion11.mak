HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include


all: saludo mrproper Ej1 clean fin


# Herramientas en tiempo de ejecución
mrproper: clean
	-rm -f bin/*


clean:
	-rm -f lib/*
	-rm -f obj/*


saludo:
	@echo -e "\n          ################################################"
	@echo      "          #           ATANASIO JOSÉ  RUBIO GIL           #"
	@echo      "          #  METODOLOGÍA DE LA PROGRAMACIÓN - SESIÓN 11  #"
	@echo      "          #            UNIVERSIDAD DE GRANADA            #"
	@echo -e   "          ################################################\n"


fin:
	@echo -e "\n          ################################################"
	@echo      "          #     COMPILACIÓN COMPLETADA CORRECTAMENTE     #"
	@echo -e   "          ################################################\n"


# Órdenes de compilación
Ej1: $(OBJ)/Secuencia.o \
     $(OBJ)/II_Demo-Matriz2D_1.cpp
	g++ -std=c++11 -o bin/II_Demo-Matriz2D_1 src/II_Demo-Matriz2D_1.cpp -Iinclude -Llib -lMatriz2D_1
libMatriz2D_1: Matriz2D_1.o
	ar -rvs lib/libMatriz2D_1.a obj/Matriz2D_1.o
Matriz2D_1.o:
	g++ -std=c++11 -c -o obj/Matriz2D_1.o src/Matriz2D_1.cpp -Iinclude

Ej11: libProblemaViajanteComercio src/II_ProblemaViajanteComercio.cpp
	g++ -std=c++11 -o bin/II_ProblemaViajanteComercio src/II_ProblemaViajanteComercio.cpp -Iinclude -Llib -lProblemaViajanteComercio
libProblemaViajanteComercio: ProblemaViajanteComercio.o
	ar -rvs lib/libProblemaViajanteComercio.a obj/ProblemaViajanteComercio.o
ProblemaViajanteComercio.o:
	g++ -std=c++11 -c -o obj/ProblemaViajanteComercio.o src/ProblemaViajanteComercio.cpp -Iinclude
