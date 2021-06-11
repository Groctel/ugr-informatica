all: saludo practicas

saludo:
	@printf "\033[1;32m%s\n" "SISTEMAS GRÁFICOS"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 1 - Ejercicios"
	@cp -r "Práctica 1 - Ejercicios/" $(OUT)
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Práctica 2 - CGPN"
	@cp -r "Práctica 2 - CGPN/" $(OUT)
