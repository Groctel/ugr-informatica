makedir = .
bin     = $(makedir)/bin
doc     = $(makedir)/doc
inc     = $(makedir)/include
obj     = $(makedir)/obj
src     = $(makedir)/src
tst     = $(makedir)/tests

uname = $(shell uname -s)
linux = $(findstring Linux, $(uname))
macos = $(findstring Darwin, $(uname))

glumacos   = /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLU.dylib
libscommon = -ljpeg
libslinux  = -lGLEW -lGLU -lglut -lGL
libsmacos  = -framework OpenGL -framework GLUT $(glumacos)
libs       = $(libscommon) $(if $(linux), $(libslinux), $(libsmacos))

cxxcommon = -std=c++17 -g -Wall -Wextra -Wpedantic -Wfloat-equal -I$(inc) $(libs)
cxxlinux  = -DLINUX
cxxmacos  = -DMACOS
CXXFLAGS  = $(cxxcommon) $(if $(linux), $(cxxlinux), $(cxxmacos))

gtest      = /usr/include/gtest/
gtestlibs  = /usr/lib/libgtest.so
gtestflags = $(CXXFLAGS) -I$(gtest) $(gtestlibs)

.PHONY: \
	all \
	clean \
	cleanbuild \
	directories \
	doc \
	full \
	run \
	test

all: directories $(bin)/practicas

clean:
	-@rm $(bin)/*
	-@rm $(obj)/*
	-@rm -r $(doc)/html
	-@rm -r $(doc)/latex

cleanbuild: clean all

directories:
	@mkdir -p $(obj)
	@mkdir -p $(bin)

doc:
	@mkdir -p $(doc)
	@doxygen

full: all test run

run: all
	@$(bin)/practicas

test: all $(bin)/tests
	@$(bin)/tests

$(bin)/practicas: $(src)/practicas.cpp \
		$(obj)/cilindro.o \
		$(obj)/cono.o \
		$(obj)/cubo.o \
		$(obj)/ejes.o \
		$(obj)/escena.o \
		$(obj)/esfera.o \
		$(obj)/globals.o \
		$(obj)/malla.o \
		$(obj)/objeto.o \
		$(obj)/objrevolucion.o \
		$(obj)/ply.o \
		$(obj)/tetraedro.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(bin)/tests: $(tst)/tests.cpp \
		$(obj)/cubo.o \
		$(obj)/globals.o \
		$(obj)/malla.o \
		$(obj)/objrevolucion.o \
		$(obj)/ply.o
	$(CXX) $(gtestflags) -o $@ $^

$(obj)/cilindro.o: $(src)/cilindro.cpp $(inc)/cilindro.hpp \
		$(obj)/objrevolucion.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/cono.o: $(src)/cono.cpp $(inc)/cono.hpp \
		$(obj)/objrevolucion.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/cubo.o: $(src)/cubo.cpp $(inc)/cubo.hpp \
		$(obj)/malla.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/ejes.o: $(src)/ejes.cpp $(inc)/ejes.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/escena.o: $(src)/escena.cpp $(inc)/escena.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/esfera.o: $(src)/esfera.cpp $(inc)/esfera.hpp \
		$(obj)/objrevolucion.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/globals.o: $(src)/globals.cpp $(inc)/globals.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/malla.o: $(src)/malla.cpp $(inc)/malla.hpp \
		$(obj)/ply.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/objeto.o: $(src)/objeto.cpp $(inc)/objeto.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/ply.o: $(src)/ply.cpp $(inc)/ply.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/objrevolucion.o: $(src)/objrevolucion.cpp $(inc)/objrevolucion.hpp \
		$(obj)/globals.o \
		$(obj)/malla.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/tetraedro.o: $(src)/tetraedro.cpp $(inc)/tetraedro.hpp \
		$(obj)/malla.o
	$(CXX) $(CXXFLAGS) -c $< -o $@
