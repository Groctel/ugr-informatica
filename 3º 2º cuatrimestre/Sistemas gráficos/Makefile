all: saludo relocalizacion

saludo:
	@printf "\033[1;32m%s\n" "MODELOS DE COMPUTACIÓN"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

relocalizacion:
	@printf "\033[1;33m-> \033[33mRelocalizando ficheros de salida\033[0m...\n"
	@cp -r "Práctica 1 - Ejercicios/" $(OUT)
	@cp -r "Práctica 2 - CGPN/" $(OUT)
