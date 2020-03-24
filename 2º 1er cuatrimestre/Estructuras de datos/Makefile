OUT = ../../bin/Estructuras\ de\ datos

all: saludo reto2 reto3 relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "ESTRUCTURAS DE DATOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

reto2:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "ED - Reto 2"
	@xelatex ED\ -\ Reto\ 2.tex > /dev/null
	@xelatex ED\ -\ Reto\ 2.tex > /dev/null

reto3:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Reto 3"
	@cp -r Retos/Reto3 $(OUT)

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@mv ED\ -\ Reto\ 2.pdf $(OUT)
