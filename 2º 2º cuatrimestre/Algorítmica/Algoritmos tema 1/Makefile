HOME = .
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

all: saludo directorios demo clean despedida

saludo:
	@printf "\033[35;1m:: \033[0mComenzando compilación\n"
	@rm -rf $(BIN) > /dev/null || printf ""

despedida:
	@printf "\033[1;32m:: \033[0mCompilación completada con éxito\n"

directorios:
	@mkdir -p obj bin

clean:
	@rm -f $(OBJ)/*

demo: algoritmos $(SRC)/demo-algoritmos.cpp
	@g++ -g $(SRC)/demo-algoritmos.cpp -o $(BIN)/demo-algoritmos -I$(INC) \
	        $(OBJ)/algoritmos.o

algoritmos: $(SRC)/algoritmos.cpp
	@g++ -g -c $(SRC)/algoritmos.cpp -o $(OBJ)/algoritmos.o -I$(INC)

