HOME = .
BIN  = $(HOME)/bin
DOC  = $(HOME)/doc
INC  = $(HOME)/include
SRC  = $(HOME)/src

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
	g++ -g $(SRC)/test.cpp -o $(BIN)/test -I$(INC)

docs:
	@rm -rf $(DOC) 1>/dev/null 2>&1 || printf ""
	@mkdir -p $(DOC)
	@doxygen
