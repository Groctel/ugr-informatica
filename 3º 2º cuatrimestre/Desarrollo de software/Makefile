all: saludo github practicas teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "DESARROLLO DE SOFTWARE"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

github:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DS - GitHub"
	@pdflatex "DS - GitHub.tex" > /dev/null
	@pdflatex "DS - GitHub.tex" > /dev/null

practicas:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 1"
	@cp -r "Prácticas/Práctica 1/" $(OUT)
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DS - Prácticas"
	@pdflatex "DS - Prácticas.tex" > /dev/null
	@pdflatex "DS - Prácticas.tex" > /dev/null

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DS - Teoría"
	@pdflatex "DS - Teoría.tex" > /dev/null
	@pdflatex "DS - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv "DS - GitHub.pdf" $(OUT)
	@mv "DS - Prácticas.pdf" $(OUT)
	@mv "DS - Teoría.pdf" $(OUT)
	@cp "Prácticas/Acorn Clicker.pdf" $(OUT)
	@cp -r "Prácticas/Práctica 1/" $(OUT)
