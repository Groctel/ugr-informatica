HOME = .
BIN  = $(HOME)/bin
DAT  = $(HOME)/datos
DOC  = $(HOME)/doc
INC  = $(HOME)/include
LIB  = $(HOME)/lib
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXX  = g++ -g -Wall

all: main docs

main: diccionario bolsa letra $(SRC)/cifras_y_letras.cpp
	$(CXX) $(SRC)/cifras_y_letras.cpp -o $(BIN)/cifras_y_letras -I$(INC) \
	       $(OBJ)/diccionario.o $(OBJ)/bolsa.o $(OBJ)/letra.o

diccionario: $(INC)/diccionario.hpp $(SRC)/diccionario.cpp
	$(CXX) -c $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o -I$(INC)

bolsa: $(INC)/bolsa.hpp $(SRC)/bolsa.cpp
	$(CXX) -c $(SRC)/bolsa.cpp -o $(OBJ)/bolsa.o -I$(INC)

letra: $(INC)/letra.hpp $(SRC)/letra.cpp
	$(CXX) -c $(SRC)/letra.cpp -o $(OBJ)/letra.o -I$(INC)

docs:
	@rm -rf $(DOC)/*
	@doxygen

