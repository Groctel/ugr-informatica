HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src
CXX  = @g++ -g -Wall

instrucciones:
	@printf "%s\
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\n" \
	        "Elija el método de compilación:" \
			  "▸ all        " "Ejecutar todos los métodos secuencialmente" \
			  "▸ diccionario" "Compilar el diccionario" \
			  "▸ guia_tlf   " "Compilar la guía telefónica" \
			  "▸ docs       " "Generar la documentación con Doxygen"

all: diccionario guia_tlf docs

diccionario: obj_diccionario obj_termino
	@g++ -g $(SRC)/test_diccionario.cpp -o $(BIN)/test_diccionario -I$(INC)

guia_tlf: obj_guia obj_testguia
	$(CXX) -o $(BIN)/test_guiatlf $(OBJ)/guiatlf.o $(OBJ)/test_guiatlf.o

obj_diccionario:
	@g++ -g $(SRC)/diccionario.cpp -c -o $(OBJ)/diccionario.o -Iinclude

obj_termino:

obj_guia:
	$(CXX) -I$(INC) -c $(SRC)/guiatlf.cpp -o $(OBJ)/guiatlf.o

obj_testguia:
	$(CXX) -I$(INC) -c $(SRC)/test_guiatlf.cpp -o $(OBJ)/test_guiatlf.o

docs:
	@rm -rf $(DOC)/*
	@doxygen
