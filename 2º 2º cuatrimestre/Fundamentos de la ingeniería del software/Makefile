OUT = ../../bin/Fundamentos\ de\ la\ ingeniería\ del\ software

all: teoria

teoria:
	@printf "\033[1;32m%s\n" "FUNDAMENTOS DE LA INGENIERÍA DEL SOFTWARE"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "FIS - Teoría"
	@xelatex FIS\ -\ Teoría.tex > /dev/null
	@xelatex FIS\ -\ Teoría.tex > /dev/null
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv FIS\ -\ Teoría.pdf $(OUT)
