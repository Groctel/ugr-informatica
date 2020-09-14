SRC= src
INCLUDE = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

all : mr.proper Examen clean

Examen: Examen.o Persona.o GeneradorAleatorioEnteros.o
	g++ -o $(BIN)/Examen \
          $(OBJ)/Examen.o $(OBJ)/Persona.o $(OBJ)/GeneradorAleatorioEnteros.o \
          -I$(INCLUDE) -std=c++11

Examen.o:
	g++ -c -g -Wall -o $(OBJ)/Examen.o \
             $(SRC)/Examen.cpp \
             -I$(INCLUDE) -std=c++11

Persona.o:
	g++ -c -g -Wall -o $(OBJ)/Persona.o \
             $(SRC)/Persona.cpp \
             -I$(INCLUDE) -std=c++11

GeneradorAleatorioEnteros.o:
	g++ -c -g -Wall -o $(OBJ)/GeneradorAleatorioEnteros.o \
             $(SRC)/GeneradorAleatorioEnteros.cpp \
             -I$(INCLUDE)/ -std=c++11

clean:
	@-rm obj/*

mr.proper: clean
	@-rm bin/*
