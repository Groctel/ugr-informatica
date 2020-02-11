OUT = ../../bin/Arquitectura\ de\ computadores

all: teoria

teoria:
	@printf "\033[1;32m%s\n" "ARQUITECTURA DE COMPUTADORES"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "AC - Teoría"
	@xelatex AC\ -\ Teoría.tex > /dev/null
	@xelatex AC\ -\ Teoría.tex > /dev/null
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv AC\ -\ Teoría.pdf $(OUT)
