MAKEDIR  = $${PWD}
BIN      = $(MAKEDIR)/bin

C11      = $(MAKEDIR)/1º\ 1er\ cuatrimestre
C12      = $(MAKEDIR)/1º\ 2º\ cuatrimestre
C21      = $(MAKEDIR)/2º\ 1er\ cuatrimestre
C22      = $(MAKEDIR)/2º\ 2º\ cuatrimestre
C31      = $(MAKEDIR)/3º\ 1er\ cuatrimestre
C32      = $(MAKEDIR)/3º\ 2º\ cuatrimestre

AC       = $(C22)/Arquitectura\ de\ computadores
ALG      = $(C22)/Algorítmica
CA       = $(C11)/Cálculo
DS       = $(C32)/Desarrollo\ de\ software
DSD      = $(C32)/Desarrollo\ de\ sistemas\ distribuidos
ED       = $(C21)/Estructuras\ de\ datos
FBD      = $(C22)/Fundamentos\ de\ bases\ de\ datos
FIS      = $(C22)/Fundamentos\ de\ la\ ingeniería\ del\ software
IA       = $(C22)/Inteligencia\ artificial
IES      = $(C12)/Ingeniería,\ empresa\ y\ sociedad
IG       = $(C31)/Informática\ gráfica
MC       = $(C31)/Modelos\ de\ computación
SG       = $(C32)/Sistemas\ gráficos
SIBW     = $(C32)/Sistemas\ de\ información\ basados\ en\ web
SO       = $(C21)/Sistemas\ operativos

AC_OUT   = $(BIN)/"Arquitectura\ de\ computadores"
ALG_OUT  = $(BIN)/"Algorítmica"
CA_OUT   = $(BIN)/"Cálculo"
DS_OUT   = $(BIN)/"Desarrollo\ de\ software"
DSD_OUT  = $(BIN)/"Desarrollo\ de\ sistemas\ distribuidos"
ED_OUT   = $(BIN)/"Estructuras\ de\ datos"
FBD_OUT  = $(BIN)/"Fundamentos\ de\ bases\ de\ datos"
FIS_OUT  = $(BIN)/"Fundamentos\ de\ la\ ingeniería\ del\ software"
IA_OUT   = $(BIN)/"Inteligencia\ artificial"
IES_OUT  = $(BIN)/"Ingeniería,\ empresa\ y\ sociedad"
IG_OUT   = $(BIN)/"Informática\ gráfica"
MC_OUT   = $(BIN)/"Modelos\ de\ computación"
SG_OUT   = $(BIN)/"Sistemas\ gráficos"
SIBW_OUT = $(BIN)/"Sistemas\ de\ información\ basados\ en\ web"
SO_OUT   = $(BIN)/"Sistemas\ operativos"

AQADEMIA_ROOT = /usr/share/texmf-dist/tex/latex/aqademia/
AQADEMIA_USER = $${HOME}/texmf/tex/latex/aqademia/

# ==============================================================================
# Creación de directorios
# ------------------------------------------------------------------------------
# $(1) -> Nombre del directorio, se imprime en pantalla
# $(2) -> Ruta del directorio a crear (con macros)
# ==============================================================================

define creadir
	@printf "\033[1;32mCreando directorio\033[0m \"%s\"...\n", $(1)
	@mkdir -p $(2)
endef

# ==============================================================================
# Compilación de ficheros Markdown a pdf mediante pandoc
# ------------------------------------------------------------------------------
# $(1) -> Nombre del fichero de salida (entrecomillado)
# $(2) -> Ruta del directorio en el que se encuentran los ficheros de origen
#         (con macros)
# $(3) -> Ruta del fichero de salida (con macros)
# ==============================================================================

define limpiatex
	@printf "\033[1;33m-> \033[1;31mLimpiando ficheros auxliares:\033[0m"
	@printf " .cache"
	@rm -rf $(1)/.cache 2> /dev/null || printf ""
	@printf " *.aux"
	@rm $(1)/*.aux 2> /dev/null || printf ""
	@printf " *.fdb_latexmk"
	@rm $(1)/*.fdb_latexmk 2> /dev/null || printf ""
	@printf " *.fls"
	@rm $(1)/*.fls 2> /dev/null || printf ""
	@printf " *.log"
	@rm $(1)/*.log 2> /dev/null || printf ""
	@printf " *.out"
	@rm $(1)/*.out 2> /dev/null || printf ""
	@printf " *.toc"
	@rm $(1)/*.toc 2> /dev/null || printf ""
	@printf "\n"
endef

.PHONY: aqademia

all: aqademia build

build: saludo c11 c12 c21 c22 c31 c32 despedida

aqademia:
	@printf "\033[35;1m:: \033[0mActualizando aqademia...\n"
	@(find $(AQADEMIA_ROOT)) 1>/dev/null 2>&1 || \
		(find $(AQADEMIA_USER) && git -C $(AQADEMIA_USER) pull) 1>/dev/null 2>&1 \
		|| (mkdir -p ~/texmf/tex/latex \
				&& git clone https://github.com/Groctel/aqademia $(AQADEMIA_USER) \
			) \
		1>/dev/null 2>&1

saludo:
	@printf "\033[35;1m:: \033[0mComenzando compilación\n"
	@rm -rf $(BIN) > /dev/null || printf ""

despedida:
	@printf "\033[1;32m:: \033[0mCompilación completada con éxito\n"

c11: ca
c12: ies
c21: ed so
c22: ac alg fbd fis ia
c31: mc
c32: ds dsd sg sibw

ac:
	@$(MAKE) -s -C $(AC) OUT=$(AC_OUT)
	$(call limpiatex, $(AC))

alg:
	@$(MAKE) -s -C $(ALG) OUT=$(ALG_OUT)
	$(call limpiatex, $(ALG))

ca:
	@$(MAKE) -s -C $(CA) OUT=$(CA_OUT)
	$(call limpiatex, $(CA))
ds:
	@$(MAKE) -s -C $(DS) OUT=$(DS_OUT)
	$(call limpiatex, $(DS))

dsd:
	@$(MAKE) -s -C $(DSD) OUT=$(DSD_OUT)
	$(call limpiatex, $(DSD))

ed:
	@$(MAKE) -s -C $(ED) OUT=$(ED_OUT)
	$(call limpiatex, $(ED))

fbd:
	@$(MAKE) -s -C $(FBD) OUT=$(FBD_OUT)
	$(call limpiatex, $(FBD))

fis:
	@$(MAKE) -s -C $(FIS) OUT=$(FIS_OUT)
	$(call limpiatex, $(FIS))

ia:
	@$(MAKE) -s -C $(IA) OUT=$(IA_OUT)
	$(call limpiatex, $(IA))

ies:
	@$(MAKE) -s -C $(IES) OUT=$(IES_OUT)
	$(call limpiatex, $(IES))

ig:
	@$(MAKE) -s -C $(IG) OUT=$(IG_OUT)
	$(call limpiatex, $(IG))

mc:
	@$(MAKE) -s -C $(MC) OUT=$(MC_OUT)
	$(call limpiatex, $(MC))

sg:
	@$(MAKE) -s -C $(SG) OUT=$(SG_OUT)
	$(call limpiatex, $(SG))

sibw:
	@$(MAKE) -s -C $(SIBW) OUT=$(SIBW_OUT)
	$(call limpiatex, $(SIBW))

so:
	@$(MAKE) -s -C $(SO) OUT=$(SO_OUT)
	$(call limpiatex, $(SO))
