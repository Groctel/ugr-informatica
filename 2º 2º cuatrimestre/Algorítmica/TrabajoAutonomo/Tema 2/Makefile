HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC) -lncursesw

instrucciones:
	@printf "%s\
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\n" \
	        "Elija el método de compilación:" \
			  "▸ all  " "Ejecutar todos los métodos secuencialmente" \
			  "▸ build" "Compilar el proyecto" \
			  "▸ docs " "Generar la documentación con Doxygen"

all: build docs

build: directorios rectangulo
	$(CXX) $(CXXFLAGS) $(SRC)/test.cpp -o $(BIN)/test \
	                   $(OBJ)/rectangulo.o

directorios:
	@mkdir -p $(BIN) $(OBJ)

rectangulo:
	$(CXX) $(CXXFLAGS) -c $(SRC)/rectangulo.cpp -o $(OBJ)/rectangulo.o

docs:
	@mkdir -p $(DOC)
	@rm -rf $(DOC)/*
	@doxygen
