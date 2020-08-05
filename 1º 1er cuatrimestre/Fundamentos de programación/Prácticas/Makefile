HOME = .
BIN  = $(HOME)/bin
R1   = $(HOME)/Relacion1

CXXFLAGS = -std=c++11 -O2 -Wall -I$(INC)

all: salida $(R1)/%.cpp

salida:
	@rm -rf $(BIN)
	@mkdir -p $(BIN)

$(R1)/%.cpp:
	$(CXX) $(CXXFLAGS) $< -o $(BIN)/$@
