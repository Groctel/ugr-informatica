all: saludo practicas trabajos relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "DESARROLLO DE SISTEMAS DISTRIBUIDOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas: p1 p2 p3 p4
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DSD - Prácticas"
	@pdflatex "DSD - Prácticas.tex" > /dev/null
	@pdflatex "DSD - Prácticas.tex" > /dev/null

p1:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 1"
	@cp -r "Prácticas/Práctica 1 - Calculadora RPC/" $(OUT)

p2:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 2"
	@cp -r "Prácticas/Práctica 2 - Calculadora Thrift/" $(OUT)

p3:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 3"
	@cp -r "Prácticas/Práctica 3 - Programación en RMI/" $(OUT)

p4:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 4"
	@cp -r "Prácticas/Práctica 4 - Node.js/" $(OUT)

trabajos: mmorpgs russo middleware

mmorpgs:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DSD Tema 1 - Sistemas distribuidos en mmorpgs"
	@pdflatex "DSD Tema 1 - Sistemas distribuidos en mmorpgs.tex" > /dev/null
	@pdflatex "DSD Tema 1 - Sistemas distribuidos en mmorpgs.tex" > /dev/null

russo:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DSD Temas 4 y 6 - Modelos middleware y arquitecturas en sistemas distribuidos"
	@pdflatex "DSD Temas 4 y 6 - Modelos middleware y arquitecturas en sistemas distribuidos.tex" > /dev/null
	@pdflatex "DSD Temas 4 y 6 - Modelos middleware y arquitecturas en sistemas distribuidos.tex" > /dev/null

middleware:
	@printf "\033[1;33m-> \033[34mCompilando\033[0m \"%s.pdf\"...\n" \
	        "DSD Temas 4 y 6 - Tecnologías middleware: socket.io"
	@pdflatex "DSD Temas 4 y 6 - Tecnologías middleware: socket.io.tex" > /dev/null
	@pdflatex "DSD Temas 4 y 6 - Tecnologías middleware: socket.io.tex" > /dev/null

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando fichero de salida\033[0m...\n"
	@mv "DSD - Prácticas.pdf" $(OUT)
	@mv "DSD Tema 1 - Sistemas distribuidos en mmorpgs.pdf" $(OUT)
	@mv "DSD Temas 4 y 6 - Modelos middleware y arquitecturas en sistemas distribuidos.pdf" $(OUT)
	@mv "DSD Temas 4 y 6 - Tecnologías middleware: socket.io.pdf" $(OUT)
