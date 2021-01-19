all: saludo problemas practicas teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "MODELOS DE COMPUTACIÓN"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

problemas:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "MC - Problemas"
	@pdflatex "MC - Problemas.tex" > /dev/null
	@pdflatex "MC - Problemas.tex" > /dev/null

practicas:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "AC - Prácticas"
	@pdflatex "MC - Prácticas.tex" > /dev/null
	@pdflatex "MC - Prácticas.tex" > /dev/null

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "AC - Teoría"
	@pdflatex "MC - Teoría.tex" > /dev/null
	@pdflatex "MC - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@mv "MC - Problemas.pdf" $(OUT)
	@mv "MC - Prácticas.pdf" $(OUT)
	@mv "MC - Teoría.pdf"    $(OUT)
