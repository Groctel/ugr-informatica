HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++17 -g -Wall -I$(INC)

all: directorios grafo
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(BIN)/grafo \
	                   $(OBJ)/grafo.o

directorios:
	@mkdir -p $(BIN)
	@mkdir -p $(OBJ)

grafo:
	$(CXX) $(CXXFLAGS) -c $(SRC)/grafo.cpp -o $(OBJ)/grafo.o
