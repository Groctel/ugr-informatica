MAKEDIR = .
BIN     = $(MAKEDIR)/bin
INC     = $(MAKEDIR)/include
LIB     = $(MAKEDIR)/lib
OBJ     = $(MAKEDIR)/obj
SRC     = $(MAKEDIR)/src

CXXFLAGS = -std=c++11 -g -I$(INC) -L$(LIB) \
           -Wall -Wextra -Wfloat-equal -Wpedantic

.PHONY: all clean dir

all: dir \
     $(BIN)/demo-cadena-clasica \
     $(BIN)/mezcla-sencilla-vectores \
     $(BIN)/reorganiza-vector

clean:
	-rm $(LIB)/*
	-rm $(OBJ)/*

dir:
	@mkdir -p $(BIN) $(LIB) $(OBJ)

$(BIN)/demo-cadena-clasica: $(LIB)/libmi-cadena-clasica \
                            $(SRC)/demo-cadena-clasica.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/demo-cadena-clasica.cpp \
	                -o $(BIN)/demo-cadena-clasica -L$(LIB) -lmi-cadena-clasica


$(BIN)/mezcla-sencilla-vectores: $(SRC)/mezcla-sencilla-vectores.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/mezcla-sencilla-vectores.cpp \
	                -o $(BIN)/mezcla-sencilla-vectores

$(BIN)/reorganiza-vector: $(SRC)/reorganiza-vector.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/reorganiza-vector.cpp -o $(BIN)/reorganiza-vector

$(LIB)/libmi-cadena-clasica: $(OBJ)/mi-cadena-clasica.o
	ar -rvs $(LIB)/libmi-cadena-clasica.a $(OBJ)/mi-cadena-clasica.o

$(OBJ)/mi-cadena-clasica.o: $(SRC)/mi-cadena-clasica.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/mi-cadena-clasica.cpp \
	                   -o $(OBJ)/mi-cadena-clasica.o
