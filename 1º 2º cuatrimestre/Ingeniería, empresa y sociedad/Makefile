all: saludo practicas

saludo:
	@printf "\033[1;32m%s\n" "INGENIERÍA, EMPRESA Y SOCIEDAD"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Prácticas"
	@cp -r "Prácticas/" $(OUT)
