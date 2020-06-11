HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++17 -g -Wall -I$(INC)

all: directorios pieza tablero
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(BIN)/maleta \
	                   $(OBJ)/pieza.o \
	                   $(OBJ)/tablero.o

directorios:
	@mkdir -p $(BIN)
	@mkdir -p $(OBJ)

pieza:
	$(CXX) $(CXXFLAGS) -c $(SRC)/pieza.cpp -o $(OBJ)/pieza.o

tablero: pieza
	$(CXX) $(CXXFLAGS) -c $(SRC)/tablero.cpp -o $(OBJ)/tablero.o
