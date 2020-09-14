##########################################################################
# makefile
##########################################################################

A32 = $(wildcard *32*.s)
E32 = $(basename $(A32))

A64 = $(wildcard *64*.s)
E64 = $(basename $(A64))

ASM = $(A32) $(A64) $(wildcard *.s)
SRC = $(wildcard *.c *.cc)
EXE = $(E32) $(E64) $(basename $(SRC))
ATT = $(EXE:=.att)

##########################################################################

CFLAGS = -g -std=c11 -Wall
CXXFLAGS = $(CFLAGS:c11=c++11)

##########################################################################

all: $(EXE) $(ATT)

clean:
	-rm -fv $(ATT) $(EXE) *~

.PHONY: all clean

##########################################################################

$(E32): CFLAGS+=-m32
$(E64): CFLAGS+=-m64

addable: CXXFLAGS+=-fconcepts -std=c++14
sum0: CXXFLAGS+=-O0
sum1: CXXFLAGS+=-O1
sum2: CXXFLAGS+=-O2
sum3: CXXFLAGS+=-O3
sums: CXXFLAGS+=-Os
sumg: CXXFLAGS+=-Og

##########################################################################

%: %.s
	$(CC) $(CFLAGS) -fno-pie -no-pie -nostartfiles $< -o $@

%: %.c
	$(CC) $(CFLAGS) $< -o $@

%: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

%.att: %
	objdump -C -d $< > $@

##########################################################################
