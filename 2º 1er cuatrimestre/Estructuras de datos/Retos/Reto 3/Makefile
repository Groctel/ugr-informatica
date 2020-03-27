HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC)

instrucciones:
	@printf "%s\
	        \n\033[1;34m%s \033[0m%s\
	        \n\033[1;34m%s \033[0m%s\
	        \n\033[1;34m%s \033[0m%s\n" \
	        "Elija el método de compilación:" \
	        "▸ all  " "Ejecutar todos los métodos secuencialmente" \
	        "▸ build" "Compilar el proyecto" \
	        "▸ docs " "Generar la documentación con doxygen"

all: build docs

build:
	$(CXX) $(CXXFLAGS) $(SRC)/test.cpp -o $(BIN)/test

docs:
	@mkdir -p $(DOC)
	@rm -rf $(DOC)/*
	@doxygen
