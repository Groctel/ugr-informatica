all: teoria

teoria:
	@printf "\033[1;32m%s\n" "FUNDAMENTOS DE BASES DE DATOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "FBD - Teoría"
	@xelatex FBD\ -\ Teoría.tex > /dev/null
	@xelatex FBD\ -\ Teoría.tex > /dev/null
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv FBD\ -\ Teoría.pdf $(OUT)
