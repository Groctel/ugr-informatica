HOME = .
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj
SRC  = $(HOME)/src

all: saludo directorios algoritmos clean despedida

algoritmos: condicionales factorial fibonacci

clean:
	@rm -f $(OBJ)/*

condicionales: $(SRC)/sentencias_condicionales.c
	gcc -g $(SRC)/sentencias_condicionales.c -o $(BIN)/sentencias_condicionales

despedida:
	@printf "\033[1;32m:: \033[0mCompilación completada con éxito\n"

directorios:
	@mkdir -p obj bin

factorial: $(SRC)/factorial.c
	gcc -g $(SRC)/factorial.c -o $(BIN)/factorial

fibonacci: $(SRC)/fibonacci.c
	gcc -g $(SRC)/fibonacci.c -o $(BIN)/fibonacci

saludo:
	@printf "\033[35;1m:: \033[0mComenzando compilación\n"
	@rm -rf $(BIN) > /dev/null || printf ""
