# ==============================================================================
# INTERNAL USE VARIABLES
# ==============================================================================

# Directories
# ------------------------------------------------------------------------------

makedir = .
bin     = $(makedir)/bin
doc     = $(makedir)/doc
glb     = $(makedir)/global
jpg     = $(makedir)/libjpg
lgh     = $(makedir)/luces
lig     = $(makedir)/libig
mdl     = $(makedir)/modelos
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
cxxcommon   = -std=c++17 -g -Wall -Wextra -Wpedantic -Wfloat-equal $(includelist)
cxxlinux    = -DLINUX
cxxmacos    = -DMACOS
CXXFLAGS    = $(cxxcommon) $(if $(linux), $(cxxlinux), $(cxxmacos))

# Test options
# ------------------------------------------------------------------------------

gtest      = /usr/include/gtest/
gtestlibs  = /usr/lib/libgtest.so
gtestflags = -I$(gtest) $(gtestlibs)

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
		$(jpg)/jpg_imagen.o \
		$(jpg)/jpg_memsrc.o \
		$(jpg)/jpg_readwrite.o \
		$(lgh)/luz_direccional.o \
		$(lgh)/luz_posicional.o \
		$(lig)/camara.o \
		$(lig)/luz.o \
		$(lig)/malla.o \
		$(lig)/material.o \
		$(lig)/objply.o \
		$(lig)/obj_revolucion.o \
		$(lig)/ply.o \
		$(lig)/textura.o \
		$(mdl)/araxxor.o \
		$(mdl)/araxxor/cabeza.o \
		$(mdl)/araxxor/colmillo.o \
		$(mdl)/araxxor/abdomen.o \
		$(mdl)/araxxor/pata.o \
		$(mdl)/flor.o \
		$(mdl)/flor/petalos.o \
		$(mdl)/flor/tallo.o \
		$(msh)/cilindro.o \
		$(msh)/cono.o \
		$(msh)/cuadro.o \
		$(msh)/cubo.o \
		$(msh)/esfera.o \
		$(msh)/tetraedro.o \
		$(src)/ejes.o \
		$(src)/escena.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(libs)

$(bin)/tests: $(tst)/tests.cpp \
		$(jpg)/jpg_imagen.o \
		$(jpg)/jpg_memsrc.o \
		$(jpg)/jpg_readwrite.o \
		$(lgh)/luz_direccional.o \
		$(lgh)/luz_posicional.o \
		$(lig)/camara.o \
		$(lig)/luz.o \
		$(lig)/malla.o \
		$(lig)/material.o \
		$(lig)/objply.o \
		$(lig)/obj_revolucion.o \
		$(lig)/ply.o \
		$(lig)/textura.o \
		$(mdl)/cabeza.o \
		$(mdl)/tronco_superior.o \
		$(msh)/cilindro.o \
		$(msh)/cono.o \
		$(msh)/cuadro.o \
		$(msh)/cubo.o \
		$(msh)/esfera.o \
		$(msh)/tetraedro.o \
		$(src)/ejes.o \
		$(src)/escena.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(gtestflags)

# LibIG
# ------------------------------------------------------------------------------

$(lig)/camara.o: $(lig)/camara.cpp $(lig)/camara.hpp \
		$(glb)/tuplasg.hpp \
		$(lig)/enum.hpp \
		$(lig)/malla.o \
		$(lig)/motor.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/luz.o: $(lig)/luz.cpp $(lig)/luz.hpp \
		$(glb)/tuplasg.hpp \
		$(lig)/motor.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/malla.o: $(lig)/malla.cpp $(lig)/malla.hpp \
		$(glb)/colores.hpp \
		$(glb)/globals.hpp \
		$(glb)/tuplasg.hpp \
		$(lig)/enum.hpp \
		$(lig)/material.o \
		$(lig)/motor.hpp \
		$(lig)/textura.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/material.o: $(lig)/material.cpp $(lig)/material.hpp \
		$(glb)/tuplasg.hpp \
		$(lig)/motor.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/obj_revolucion.o: $(lig)/obj_revolucion.cpp $(lig)/obj_revolucion.hpp \
		$(lig)/enum.hpp \
		$(glb)/globals.hpp \
		$(glb)/tuplasg.hpp \
		$(lig)/malla.o \
		$(lig)/ply.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/objply.o: $(lig)/objply.cpp $(lig)/objply.hpp \
		$(lig)/malla.o \
		$(lig)/ply.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/ply.o: $(lig)/ply.cpp $(lig)/ply.hpp \
		$(lig)/enum.hpp \
		$(glb)/tuplasg.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lig)/textura.o: $(lig)/textura.cpp $(lig)/textura.hpp \
		$(lig)/enum.hpp \
		$(lig)/motor.hpp \
		$(jpg)/jpg_imagen.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# LibJPG
# ------------------------------------------------------------------------------

$(jpg)/jpg_imagen.o: $(jpg)/jpg_imagen.cpp $(jpg)/jpg_imagen.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -ljpeg

$(jpg)/jpg_memsrc.o: $(jpg)/jpg_memsrc.cpp $(jpg)/jpg_memsrc.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -ljpeg

$(jpg)/jpg_readwrite.o: $(jpg)/jpg_readwrite.cpp $(jpg)/jpg_readwrite.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -ljpeg

# Luces
# ------------------------------------------------------------------------------

$(lgh)/luz_direccional.o: $(lgh)/luz_direccional.cpp $(lgh)/luz_direccional.hpp \
		$(lig)/luz.cpp $(lig)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(lgh)/luz_posicional.o: $(lgh)/luz_posicional.cpp $(lgh)/luz_posicional.hpp \
		$(lig)/luz.cpp $(lig)/luz.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Mallas
# ------------------------------------------------------------------------------

$(msh)/cilindro.o: $(msh)/cilindro.cpp $(msh)/cilindro.hpp \
		$(lig)/obj_revolucion.cpp $(lig)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/cono.o: $(msh)/cono.cpp $(msh)/cono.hpp \
		$(lig)/obj_revolucion.cpp $(lig)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/cuadro.o: $(msh)/cuadro.cpp $(msh)/cuadro.hpp \
		$(lig)/malla.cpp $(lig)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/cubo.o: $(msh)/cubo.cpp $(msh)/cubo.hpp \
		$(lig)/malla.cpp $(lig)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/esfera.o: $(msh)/esfera.cpp $(msh)/esfera.hpp \
		$(lig)/obj_revolucion.cpp $(lig)/obj_revolucion.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(msh)/tetraedro.o: $(msh)/tetraedro.cpp $(msh)/tetraedro.hpp \
		$(lig)/malla.cpp $(lig)/malla.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Modelos jerárquicos
# ------------------------------------------------------------------------------

$(mdl)/araxxor.o: $(mdl)/araxxor.cpp $(mdl)/araxxor.hpp \
		$(mdl)/araxxor/cabeza.cpp    $(mdl)/araxxor/cabeza.hpp \
		$(mdl)/araxxor/abdomen.cpp    $(mdl)/araxxor/abdomen.hpp \
		$(mdl)/araxxor/pata.cpp    $(mdl)/araxxor/pata.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/araxxor/cabeza.o: $(mdl)/araxxor/cabeza.cpp $(mdl)/araxxor/cabeza.hpp \
		$(mdl)/araxxor/colmillo.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/araxxor/colmillo.o: $(mdl)/araxxor/colmillo.cpp $(mdl)/araxxor/colmillo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/araxxor/abdomen.o: $(mdl)/araxxor/abdomen.cpp $(mdl)/araxxor/abdomen.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/araxxor/pata.o: $(mdl)/araxxor/pata.cpp $(mdl)/araxxor/pata.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/flor.o: $(mdl)/flor.cpp $(mdl)/flor.hpp \
		$(mdl)/flor/petalos.cpp $(mdl)/flor/petalos.hpp \
		$(mdl)/flor/tallo.cpp $(mdl)/flor/tallo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/flor/petalos.o: $(mdl)/flor/petalos.cpp $(mdl)/flor/petalos.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(mdl)/flor/tallo.o: $(mdl)/flor/tallo.cpp $(mdl)/flor/tallo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Src
# ------------------------------------------------------------------------------

$(src)/ejes.o: $(src)/ejes.cpp $(src)/ejes.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(src)/escena.o: $(src)/escena.cpp $(src)/escena.hpp \
		$(lgh)/luz_direccional.cpp $(lgh)/luz_direccional.hpp \
		$(lgh)/luz_posicional.cpp  $(lgh)/luz_posicional.hpp \
		$(msh)/cilindro.cpp        $(msh)/cilindro.hpp \
		$(msh)/cono.cpp            $(msh)/cono.hpp \
		$(msh)/cuadro.cpp          $(msh)/cuadro.hpp \
		$(msh)/cubo.cpp            $(msh)/cubo.hpp \
		$(msh)/esfera.cpp          $(msh)/esfera.hpp \
		$(lig)/malla.cpp           $(lig)/malla.hpp \
		$(lig)/obj_revolucion.cpp  $(lig)/obj_revolucion.hpp \
		$(msh)/tetraedro.cpp       $(msh)/tetraedro.hpp \
		$(src)/ejes.cpp            $(src)/ejes.hpp \
		$(lig)/material.cpp        $(lig)/material.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

