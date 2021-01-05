makedir = .
bin     = $(makedir)/bin
doc     = $(makedir)/doc
lgh     = $(makedir)/luces
lig     = $(makedir)/libig
mdl     = $(makedir)/modelo-jerarquico
msh     = $(makedir)/mallas
obj     = $(makedir)/obj
src     = $(makedir)/src
tst     = $(makedir)/tests

uname = $(shell uname -s)
linux = $(findstring Linux, $(uname))
macos = $(findstring Darwin, $(uname))

glumacos    = /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLU.dylib
libscommon  = -ljpeg
libslinux   = -lGLEW -lGLU -lglut -lGL
libsmacos   = -framework OpenGL -framework GLUT $(glumacos)
libs        = $(libscommon) $(if $(linux), $(libslinux), $(libsmacos))

includelist = -I$(makedir) -I$(lig)
cxxcommon   = -std=c++17 -g -Wall -Wextra -Wpedantic -Wfloat-equal $(includelist) $(libs)
cxxlinux    = -DLINUX
cxxmacos    = -DMACOS
CXXFLAGS    = $(cxxcommon) $(if $(linux), $(cxxlinux), $(cxxmacos))

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
		$(obj)/jirafa.o \
		$(obj)/luz.o \
		$(obj)/luz_direccional.o \
		$(obj)/luz_posicional.o \
		$(obj)/malla.o \
		$(obj)/material.o \
		$(obj)/obj_revolucion.o \
		$(obj)/patas_jirafa.o \
		$(obj)/ply.o \
		$(obj)/tetraedro.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(bin)/tests: $(tst)/tests.cpp \
		$(obj)/cubo.o \
		$(obj)/globals.o \
		$(obj)/malla.o \
		$(obj)/obj_revolucion.o \
		$(obj)/ply.o
	$(CXX) $(gtestflags) -o $@ $^

$(obj)/cilindro.o: $(msh)/cilindro.cpp $(msh)/cilindro.hpp \
		$(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/cono.o: $(msh)/cono.cpp $(msh)/cono.hpp \
		$(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/cubo.o: $(msh)/cubo.cpp $(msh)/cubo.hpp \
		$(msh)/malla.cpp $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/ejes.o: $(src)/ejes.cpp $(src)/ejes.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/escena.o: $(src)/escena.cpp $(src)/escena.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/esfera.o: $(msh)/esfera.cpp $(msh)/esfera.hpp \
		$(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/globals.o: $(lig)/globals.cpp $(lig)/globals.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/jirafa.o: $(mdl)/jirafa.cpp $(mdl)/jirafa.hpp \
		$(msh)/cubo.cpp $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/luz.o: $(lgh)/luz.cpp $(lgh)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/luz_direccional.o: $(lgh)/luz_direccional.cpp $(lgh)/luz_direccional.hpp \
		$(lgh)/luz.cpp $(lgh)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/luz_posicional.o: $(lgh)/luz_posicional.cpp $(lgh)/luz_posicional.hpp \
		$(lgh)/luz.cpp $(lgh)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/malla.o: $(msh)/malla.cpp $(msh)/malla.hpp \
		$(lig)/ply.cpp $(lig)/ply.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/material.o: $(src)/material.cpp $(src)/material.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/ply.o: $(lig)/ply.cpp $(lig)/ply.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/patas_jirafa.o: $(mdl)/patas_jirafa.cpp $(mdl)/patas_jirafa.hpp \
		$(msh)/cubo.cpp $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/obj_revolucion.o: $(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp \
		$(lig)/globals.cpp $(lig)/globals.hpp \
		$(msh)/malla.cpp $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj)/tetraedro.o: $(msh)/tetraedro.cpp $(msh)/tetraedro.hpp \
		$(msh)/malla.cpp $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
