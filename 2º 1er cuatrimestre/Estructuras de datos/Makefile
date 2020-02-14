OUT = ../../bin/Estructuras\ de\ datos

all: reto2

reto2:
	@printf "\033[1;32m%s\n" "ESTRUCTURAS DE DATOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "ED - Reto 2"
	@xelatex ED\ -\ Reto\ 2.tex > /dev/null
	@xelatex ED\ -\ Reto\ 2.tex > /dev/null
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv ED\ -\ Reto\ 2.pdf $(OUT)
