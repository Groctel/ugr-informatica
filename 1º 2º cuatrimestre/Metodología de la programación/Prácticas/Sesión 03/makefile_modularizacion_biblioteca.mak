#######################################################
# Fichero makefile para el proyecto de modularizacion
# Incluye la biblioteca libGeneradorAleatorioEnteros.a
#######################################################

SRC= ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
LIB = ./lib
DOC = ./doc

#............................................................

all : clean $(BIN)/I_CambiaNegs $(BIN)/I_CambiaNegs_PtrFinal

#............................................................


$(BIN)/I_CambiaNegs : $(OBJ)/I_CambiaNegs.o \
                      $(LIB)/libGeneradorAleatorioEnteros.a
	g++ -o $(BIN)/I_CambiaNegs $(OBJ)/I_CambiaNegs.o  \
           -lGeneradorAleatorioEnteros -L$(LIB)

$(BIN)/I_CambiaNegs_PtrFinal: $(OBJ)/I_CambiaNegs_PtrFinal.o  \
                          $(LIB)/libGeneradorAleatorioEnteros.a
	g++ -o $(BIN)/I_CambiaNegs_PtrFinal \
           $(OBJ)/I_CambiaNegs_PtrFinal.o \
           -lGeneradorAleatorioEnteros -L$(LIB)

$(OBJ)/I_CambiaNegs.o : $(SRC)/I_CambiaNegs.cpp \
                        $(INCLUDE)/GeneradorAleatorioEnteros.h	
	g++ -c -o $(OBJ)/I_CambiaNegs.o \
              $(SRC)/I_CambiaNegs.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/I_CambiaNegs_PtrFinal.o: \
               $(SRC)/I_CambiaNegs_PtrFinal.cpp \
               $(INCLUDE)/GeneradorAleatorioEnteros.h	
	g++ -c -o $(OBJ)/I_CambiaNegs_PtrFinal.o \
                $(SRC)/I_CambiaNegs_PtrFinal.cpp \
               -I$(INCLUDE) -std=c++11

#............................................................
# CLASE GeneradorAleatorioEnteros

$(OBJ)/GeneradorAleatorioEnteros.o: \
               $(SRC)/GeneradorAleatorioEnteros.cpp \
               $(INCLUDE)/GeneradorAleatorioEnteros.h
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
                $(SRC)/GeneradorAleatorioEnteros.cpp\
               -I$(INCLUDE) -std=c++11

$(LIB)/libGeneradorAleatorioEnteros.a: \
               $(OBJ)/GeneradorAleatorioEnteros.o
	ar rvs $(LIB)/libGeneradorAleatorioEnteros.a \
           $(OBJ)/GeneradorAleatorioEnteros.o

#............................................................

clean: 
	-rm obj/*

mr.proper: 
	-rm bin/*
