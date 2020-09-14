all: saludo mrproper Ej18 clean fin

# Herramientas en tiempo de ejecución
mrproper: clean
	-rm -f bin/*

clean:
	-rm -f lib/*
	-rm -f obj/*

saludo:
	@echo -e "\n          ################################################"
	@echo      "          #           ATANASIO JOSÉ  RUBIO GIL           #"
	@echo      "          #  METODOLOGÍA DE LA PROGRAMACIÓN - SESIÓN 05  #"
	@echo      "          #            UNIVERSIDAD DE GRANADA            #"
	@echo -e   "          ################################################\n"

fin:
	@echo -e "\n          ################################################"
	@echo      "          #     COMPILACIÓN COMPLETADA CORRECTAMENTE     #"
	@echo -e   "          ################################################\n"

# Órdenes de compilación
Ej18: libLeeEntero src/I_LeeEntero.cpp
	g++ -o bin/I_LeeEntero src/I_LeeEntero.cpp -Iinclude -Llib -lLeeEntero

libLeeEntero: LeeEntero.o
	ar -rvs lib/libLeeEntero.a obj/LeeEntero.o

LeeEntero.o:
	g++ -c -o obj/LeeEntero.o src/LeeEntero.cpp -Iinclude

Ej22: libMezclaArrays src/I_MezclaArrays.cpp
	g++ -o bin/I_MezclaArrays src/I_MezclaArrays.cpp -Iinclude -Llib -lMezclaArrays

libMezclaArrays: MezclaArrays.o
	ar -rvs lib/libMezclaArrays.a obj/MezclaArrays.o

MezclaArrays.o:
	g++ -c -o obj/MezclaArrays.o src/MezclaArrays.cpp -Iinclude

Ej25: libSecuenciacionGenetica src/I_SecuenciacionGenetica.cpp
	g++ -o bin/I_SecuenciacionGenetica src/I_SecuenciacionGenetica.cpp -Iinclude -Llib -lSecuenciacionGenetica

libSecuenciacionGenetica: SecuenciacionGenetica.o
	ar -rvs lib/SecuenciacionGenetica.a obj/SecuenciacionGenetica.o

SecuenciacionGenetica.o:
	g++ -c -o obj/SecuenciacionGenetica.o src/SecuenciacionGenetica.cpp -Iinclude

Ej26: libNuevoOrdenEnteros src/I_NuevoOrdenEnteros.cpp
	g++ -o bin/I_NuevoOrdenEnteros src/I_NuevoOrdenEnteros.cpp -Iinclude -Llib -lNuevoOrdenEnteros

libNuevoOrdenEnteros: NuevoOrdenEnteros.o
	ar -rvs lib/libNuevoOrdenEnteros.a obj/NuevoOrdenEnteros.o

NuevoOrdenEnteros.o:
	g++ -c -o obj/NuevoOrdenEnteros.o src/NuevoOrdenEnteros.cpp -Iinclude

Ej27:
	@echo -e "Compilación del ejercicio 27 no incluída en el makefile."
