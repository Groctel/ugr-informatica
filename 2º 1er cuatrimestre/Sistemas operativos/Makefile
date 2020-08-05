all: practicas

practicas:
	@printf "\033[1;32m%s\n" "SISTEMAS OPERATIVOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "SO - Prácticas"
	@xelatex SO\ -\ Prácticas.tex > /dev/null
	@xelatex SO\ -\ Prácticas.tex > /dev/null
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv SO\ -\ Prácticas.pdf $(OUT)
