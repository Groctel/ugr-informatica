all: saludo practicas seminario

saludo:
	@printf "\033[1;32m%s\n" "SISTEMAS DE INFORMACIÓN BASADOS EN WEB"
	@printf "\033[1;33m-> \033[33mCreando directorio de salida\033[0m...\n"
	@mkdir -p $(OUT)

practicas:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Prácticas"
	@cp -r "Prácticas/" $(OUT)
	@cp "open_workshop.sql" $(OUT)

seminario:
	@printf "\033[1;33m-> \033[34mCopiando\033[0m \"%s\"...\n" \
	        "Seminario jQuery"
	@cp -r "Seminario jQuery/" $(OUT)
