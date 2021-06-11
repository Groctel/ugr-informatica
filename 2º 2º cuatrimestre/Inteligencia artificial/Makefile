all: saludo practicas teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "INTELIGENCIA ARTIFICIAL"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Prácticas"
	@cp -r "Prácticas/" $(OUT)

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "IA - Teoría"
	@pdflatex "IA - Teoría.tex" > /dev/null
	@pdflatex "IA - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv "IA - Teoría.pdf" $(OUT)
