# ==============================================================================
# INTERNAL USE VARIABLES
# ==============================================================================

# Directories
# ------------------------------------------------------------------------------

makedir = .
bin     = $(makedir)/bin
doc     = $(makedir)/doc
lgh     = $(makedir)/luces
lig     = $(makedir)/libig
mdl     = $(makedir)/modelo-jerarquico
msh     = $(makedir)/mallas
src     = $(makedir)/src
tst     = $(makedir)/tests

# Operating system ID
# ------------------------------------------------------------------------------

uname = $(shell uname -s)
linux = $(findstring Linux, $(uname))
macos = $(findstring Darwin, $(uname))

# OpenGL options
# ------------------------------------------------------------------------------

glumacos    = /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLU.dylib
libscommon  = -ljpeg
libslinux   = -lGLEW -lGLU -lglut -lGL
libsmacos   = -framework OpenGL -framework GLUT $(glumacos)
libs        = $(libscommon) $(if $(linux), $(libslinux), $(libsmacos))

# Compiler options
# ------------------------------------------------------------------------------

includelist = -I$(makedir) -I$(lig)
cxxcommon   = -std=c++17 -g -Wall -Wextra -Wpedantic -Wfloat-equal $(includelist) $(libs)
cxxlinux    = -DLINUX
cxxmacos    = -DMACOS
CXXFLAGS    = $(cxxcommon) $(if $(linux), $(cxxlinux), $(cxxmacos))

# Test options
# ------------------------------------------------------------------------------

gtest      = /usr/include/gtest/
gtestlibs  = /usr/lib/libgtest.so
gtestflags = $(CXXFLAGS) -I$(gtest) $(gtestlibs)

# ==============================================================================
# BUILDING INSTRUCTIONS
# ==============================================================================

# Non-file-dependant recipes
# ------------------------------------------------------------------------------

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
	-@find . -name "*.o" -exec rm {} +
	-@rm -r $(doc)/html
	-@rm -r $(doc)/latex

cleanbuild: clean all

directories:
	@mkdir -p $(bin)

doc:
	@mkdir -p $(doc)
	@doxygen

full: all test run

run: all
	@$(bin)/practicas

test: all $(bin)/tests
	@$(bin)/tests

# Binaries
# ------------------------------------------------------------------------------

$(bin)/practicas: $(src)/practicas.cpp \
		$(lgh)/luz.o \
		$(lgh)/luz_direccional.o \
		$(lgh)/luz_posicional.o \
		$(lig)/globals.o \
		$(lig)/ply.o \
		$(mdl)/cabeza.o \
		$(mdl)/jirafa.o \
		$(mdl)/patas_jirafa.o \
		$(mdl)/tronco_superior.o \
		$(msh)/cilindro.o \
		$(msh)/cono.o \
		$(msh)/cubo.o \
		$(msh)/esfera.o \
		$(msh)/malla.o \
		$(msh)/obj_revolucion.o \
		$(msh)/tetraedro.o \
		$(src)/ejes.o \
		$(src)/escena.o \
		$(src)/material.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(bin)/tests: $(tst)/tests.cpp \
		$(lgh)/luz.o \
		$(lgh)/luz_direccional.o \
		$(lgh)/luz_posicional.o \
		$(lig)/globals.o \
		$(lig)/ply.o \
		$(mdl)/cabeza.o \
		$(mdl)/jirafa.o \
		$(mdl)/patas_jirafa.o \
		$(mdl)/tronco_superior.o \
		$(msh)/cilindro.o \
		$(msh)/cono.o \
		$(msh)/cubo.o \
		$(msh)/esfera.o \
		$(msh)/malla.o \
		$(msh)/obj_revolucion.o \
		$(msh)/tetraedro.o \
		$(src)/ejes.o \
		$(src)/escena.o \
		$(src)/material.o
	$(CXX) $(gtestflags) -o $@ $^

# LibIG
# ------------------------------------------------------------------------------

$(lig)/globals.o: $(lig)/globals.cpp $(lig)/globals.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/ply.o: $(lig)/ply.cpp $(lig)/ply.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Luces
# ------------------------------------------------------------------------------

$(lgh)/luz.o: $(lgh)/luz.cpp $(lgh)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lgh)/luz_direccional.o: $(lgh)/luz_direccional.cpp $(lgh)/luz_direccional.hpp \
		$(lgh)/luz.cpp $(lgh)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lgh)/luz_posicional.o: $(lgh)/luz_posicional.cpp $(lgh)/luz_posicional.hpp \
		$(lgh)/luz.cpp $(lgh)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Mallas
# ------------------------------------------------------------------------------

$(msh)/cilindro.o: $(msh)/cilindro.cpp $(msh)/cilindro.hpp \
		$(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/cono.o: $(msh)/cono.cpp $(msh)/cono.hpp \
		$(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/cubo.o: $(msh)/cubo.cpp $(msh)/cubo.hpp \
		$(msh)/malla.cpp    $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/esfera.o: $(msh)/esfera.cpp $(msh)/esfera.hpp \
		$(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/malla.o: $(msh)/malla.cpp $(msh)/malla.hpp \
		$(lig)/ply.cpp $(lig)/ply.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/obj_revolucion.o: $(msh)/obj_revolucion.cpp $(msh)/obj_revolucion.hpp \
		$(lig)/globals.cpp $(lig)/globals.hpp \
		$(msh)/malla.cpp   $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/tetraedro.o: $(msh)/tetraedro.cpp $(msh)/tetraedro.hpp \
		$(msh)/malla.cpp $(msh)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Modelo jerárquico
# ------------------------------------------------------------------------------

$(mdl)/cabeza.o: $(mdl)/cabeza.cpp $(mdl)/cabeza.hpp \
		$(msh)/cubo.cpp $(msh)/cubo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/jirafa.o: $(mdl)/jirafa.cpp $(mdl)/jirafa.hpp \
		$(mdl)/patas_jirafa.cpp    $(mdl)/patas_jirafa.hpp \
		$(mdl)/tronco_superior.cpp $(mdl)/tronco_superior.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/patas_jirafa.o: $(mdl)/patas_jirafa.cpp $(mdl)/patas_jirafa.hpp \
		$(msh)/cubo.cpp $(msh)/cubo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/tronco_superior.o: $(mdl)/tronco_superior.cpp $(mdl)/tronco_superior.hpp \
		$(mdl)/cabeza.cpp $(mdl)/cabeza.hpp \
		$(msh)/cubo.cpp $(msh)/cubo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Src
# ------------------------------------------------------------------------------

$(src)/ejes.o: $(src)/ejes.cpp $(src)/ejes.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(src)/escena.o: $(src)/escena.cpp $(src)/escena.hpp \
		$(lgh)/luz_direccional.cpp $(lgh)/luz_direccional.hpp \
		$(lgh)/luz_posicional.cpp  $(lgh)/luz_posicional.hpp \
		$(mdl)/jirafa.cpp          $(mdl)/jirafa.hpp \
		$(msh)/cilindro.cpp        $(msh)/cilindro.hpp \
		$(msh)/cono.cpp            $(msh)/cono.hpp \
		$(msh)/cubo.cpp            $(msh)/cubo.hpp \
		$(msh)/esfera.cpp          $(msh)/esfera.hpp \
		$(msh)/malla.cpp           $(msh)/malla.hpp \
		$(msh)/obj_revolucion.cpp  $(msh)/obj_revolucion.hpp \
		$(msh)/tetraedro.cpp       $(msh)/tetraedro.hpp \
		$(src)/ejes.cpp            $(src)/ejes.hpp \
		$(src)/material.cpp        $(src)/material.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(src)/material.o: $(src)/material.cpp $(src)/material.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	$(CXX) $(CXXFLAGS) -c $< -o $@
