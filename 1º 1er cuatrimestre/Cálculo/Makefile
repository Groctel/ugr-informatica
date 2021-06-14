all: saludo practicas teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "CÁLCULO"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Prácticas"
	@cp -r "Prácticas/" $(OUT)

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "CA - Teoría"
	@pdflatex "CA - Teoría.tex" > /dev/null
	@pdflatex "CA - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@mv "CA - Teoría.pdf" $(OUT)
