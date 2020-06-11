HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++17 -g -Wall -I$(INC)

all: directorios
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(BIN)/platos

directorios:
	@mkdir -p $(BIN)
