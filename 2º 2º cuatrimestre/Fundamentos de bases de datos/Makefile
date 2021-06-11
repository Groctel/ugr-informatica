all: saludo teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "FUNDAMENTOS DE BASES DE DATOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "FBD - Teoría"
	@pdflatex "FBD - Teoría.tex" > /dev/null
	@pdflatex "FBD - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@mv "FBD - Teoría.pdf" $(OUT)
