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
			  \n\033[1;34m%s \033[0m%s\
			  \n\033[1;34m%s \033[0m%s\n" \
	        "Elija el método de compilación:" \
			  "▸ all " "Ejecutar todos los métodos secuencialmente" \
			  "▸ cola" "Compilar el proyecto con una cola" \
			  "▸ vd  " "Compilar el proyecto con un vector dinámico" \
			  "▸ docs" "Generar la documentación con Doxygen"

all: cola vd docs

cola:
	@mkdir -p $(BIN)
	@sed -i 's/CONTENEDOR [12]/CONTENEDOR 2/g' $(INC)/pila_max.tpp
	$(CXX) $(CXXFLAGS) $(SRC)/test.cpp -o $(BIN)/test_cola

vd:
	@mkdir -p $(BIN)
	@sed -i 's/CONTENEDOR [12]/CONTENEDOR 1/g' $(INC)/pila_max.tpp
	$(CXX) $(CXXFLAGS) $(SRC)/test.cpp -o $(BIN)/test_vd

docs:
	@mkdir -p $(DOC)
	@rm -rf $(DOC)/*
	@doxygen
