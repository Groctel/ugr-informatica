HOME  = .
BIN   = $(HOME)/bin

C21   = $(HOME)/2º\ 1er\ cuatrimestre
C22   = $(HOME)/2º\ 2º\ cuatrimestre

AC    = $(C22)/Arquitectura\ de\ computadores
ALG   = $(C22)/Algorítmica
ED    = $(C21)/Estructuras\ de\ datos
FBD   = $(C22)/Fundamentos\ de\ bases\ de\ datos
FIS   = $(C22)/Fundamentos\ de\ la\ ingeniería\ del\ software
IA    = $(C22)/Inteligencia\ artificial
SO    = $(C21)/Sistemas\ operativos

# =======================
# Creación de directorios
# -----------------------------------------------------
# $(1) -> Nombre del directorio, se imprime en pantalla
# $(2) -> Ruta del directorio a crear (con macros)
# ================================================

define creadir
	@printf "\033[1;32mCreando directorio\033[0m \"%s\"...\n", $(1)
	@mkdir -p $(2)
endef

# ======================================================
# Compilación de ficheros Markdown a pdf mediante pandoc
# -----------------------------------------------------
# $(1) -> Nombre del fichero de salida (entrecomillado)
# $(2) -> Ruta del directorio en el que se encuentran los ficheros de origen
#         (con macros)
# $(3) -> Ruta del fichero de salida (con macros)
# ===============================================

define limpiatex
	@printf "\033[1;33m-> \033[1;31mLimpiando ficheros auxliares:\033[0m"
	@printf " .cache"
	@rm -rf $(1)/.cache 2> /dev/null || printf ""
	@printf " *.aux"
	@rm $(1)/*.aux 2> /dev/null || printf ""
	@printf " *.log"
	@rm $(1)/*.log 2> /dev/null || printf ""
	@printf " *.out"
	@rm $(1)/*.out 2> /dev/null || printf ""
	@printf " *.toc"
	@rm $(1)/*.toc 2> /dev/null || printf ""
	@printf "\n"
endef

all: saludo c21 c22 despedida

saludo:
	@printf "\033[35;1m:: \033[0mComenzando compilación\n"
	@rm -rf $(OUT) > /dev/null || printf ""

despedida:
	@printf "\033[1;32m:: \033[0mCompilación completada con éxito\n"

c21: ed so
c22: ac alg fbd fis ia

ac:
	@$(MAKE) -s -C $(AC)
	$(call limpiatex, $(AC))

alg:
	@$(MAKE) -s -C $(ALG)
	$(call limpiatex, $(ALG))

ed:
	@$(MAKE) -s -C $(ED)
	$(call limpiatex, $(ED))

fbd:
	@$(MAKE) -s -C $(FBD)
	$(call limpiatex, $(FBD))

fis:
	@$(MAKE) -s -C $(FIS)
	$(call limpiatex, $(FIS))

ia:
	@$(MAKE) -s -C $(IA)
	$(call limpiatex, $(IA))

so:
	@$(MAKE) -s -C $(SO)
	$(call limpiatex, $(SO))

