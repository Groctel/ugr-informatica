all: saludo practicas teoria relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "ARQUITECTURA DE COMPUTADORES"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

cuadernos:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "AC - Cuaderno de prácticas"
	@pdflatex "AC - Cuaderno de prácticas.tex" > /dev/null
	@pdflatex "AC - Cuaderno de prácticas.tex" > /dev/null

practicas:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "AC - Prácticas"
	@pdflatex "AC - Prácticas.tex" > /dev/null
	@pdflatex "AC - Prácticas.tex" > /dev/null

teoria:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "AC - Teoría"
	@pdflatex "AC - Teoría.tex" > /dev/null
	@pdflatex "AC - Teoría.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@mv "AC - Prácticas.pdf" $(OUT)
	@mv "AC - Teoría.pdf" $(OUT)
	@mkdir -p $(OUT)/"Cuaderno de prácticas"
	@find CuadernoDePracticas/* -maxdepth 2 -type d \
	      -exec cp -r -t $(OUT)/"Cuaderno de prácticas" {} +
