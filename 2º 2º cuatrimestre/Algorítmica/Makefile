OUT = ../../bin/Algorítmica

all: saludo practicas teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "ALGORÍTMICA"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "ALG - Prácticas"
	@xelatex "ALG - Prácticas.tex" > /dev/null
	@xelatex "ALG - Prácticas.tex" > /dev/null

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "ALG - Teoría"
	@xelatex "ALG - Teoría.tex" > /dev/null
	@xelatex "ALG - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv "ALG - Teoría.pdf" $(OUT)
	@mv "ALG - Prácticas.pdf" $(OUT)
