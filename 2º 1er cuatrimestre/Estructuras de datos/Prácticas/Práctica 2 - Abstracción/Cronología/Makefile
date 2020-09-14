INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g

# Directorios de recursos para make
MAKEDIR = .make
EISVOGEL = $(MAKEDIR)/eisvogel


# ==============================================================================
# FUNCIONES
# ==============================================================================

# Creación de directorios
# ------------------------------------------------------------------------------
#  $(1) -> Nombre del directorio, se imprime en pantalla
#  $(2) -> Ruta del directorio a crear (con macros)
define creadir
	@printf "\033[1;32mCreando directorio\033[0m %s\n" $(1)
	@mkdir -p $(2)
endef

# Compilación de ficheros Markdown a pdf mediante pandoc
# ------------------------------------------------------------------------------
#  $(1) -> Nombre del fichero de salida (entrecomillado)
#  $(2) -> Ruta del directorio en el que se encuentran los ficheros de origen
#          (con macros)
#  $(3) -> Ruta del fichero de salida (con macros)
define md-pdf
	@printf " \033[1;33m- \033[35mCreando\033[0m    %s.md...\n" $(1)
	@cp $(2)/.yaml $(3)/$(strip $(1))
	@printf "\n\n" >> $(3)/$(strip $(1))
	@for file in $(2)/*.md;\
	 do\
	 cat "$$file";\
	 printf "\n\n\\pagebreak\n\n";\
	 done >> $(3)/$(strip $(1))
	@mv $(3)/$(strip $(1)) $(3)/$(strip $(1)).md
	@printf " \033[1;33m- \033[34mCompilando\033[0m %s.pdf..." $(1)
	@pandoc --standalone\
	        --template=$(EISVOGEL)/eisvogel.tex\
	        --resource-path=$(strip $(2))\
	        --from markdown+implicit_figures\
	        --pdf-engine=xelatex\
	        --listings\
	        --table-of-contents\
	        $(3)/$(strip $(1)).md -o $(3)/$(strip $(1)).pdf
	@printf "\n \033[1;33m- Eliminando\033[0m %s.md...\n" $(strip $(1))
	@rm $(3)/$(strip $(1)).md
endef


# ==============================================================================
# INSTRUCCIONES MAKE
# ==============================================================================

ALL: saludo documentacion $(BIN)/DemoCronologia despedida


saludo:
	@printf    "\n   \033[1;34m=================================================\n"
	@printf      "   #                                               #\n"
	@printf      "   #  \033[1;33mC O M E N Z A N D O   C O M P I L A C I Ó N  \033[1;34m#\n"
	@printf      "   #                                               #\n"
	@printf      "   =================================================\033[0m\n"
	@printf    "\nEliminando compilación anterior\n"
	@rm -rf  $(BIN)
	@printf    "Creando raíz de archivos compilados\n\n"

documentacion:
	$(call creadir, "bin", $(BIN))
	$(call md-pdf, \
	"Documentación", \
	doc, \
	$(BIN))

$(BIN)/DemoCronologia : $(OBJ)/DemoCronologia.o $(OBJ)/Evento.o $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o
	$(CXX) -o $(BIN)/DemoCronologia $(OBJ)/DemoCronologia.o $(OBJ)/Evento.o $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o -g

$(OBJ)/DemoCronologia.o : $(INC)/Cronologia.h $(INC)/FechaHistorica.h $(SRC)/DemoCronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/DemoCronologia.o $(SRC)/DemoCronologia.cpp

$(OBJ)/Cronologia.o : $(INC)/Cronologia.h $(INC)/FechaHistorica.h $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp

$(OBJ)/FechaHistorica.o : $(INC)/FechaHistorica.h $(SRC)/FechaHistorica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/FechaHistorica.o $(SRC)/FechaHistorica.cpp

$(OBJ)/Evento.o : $(INC)/Evento.h $(SRC)/Evento.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Evento.o $(SRC)/Evento.cpp

despedida:
	@rm -rf .cache
	@rm -f $(OBJ)/*.o
	@printf "\n   \033[1;34m=================================================\n"
	@printf "   #                                               #\n"
	@printf "   #       \033[1;32mCOMPILACIÓN COMPLETADA CON ÉXITO        \033[1;34m#\n"
	@printf "   #                                               #\n"
	@printf "   =================================================\n\033[0m"

