all: saludo practicas relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "SISTEMAS OPERATIVOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "SO - Prácticas"
	@pdflatex "SO - Prácticas.tex" > /dev/null
	@pdflatex "SO - Prácticas.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@mv "SO - Prácticas.pdf" $(OUT)
