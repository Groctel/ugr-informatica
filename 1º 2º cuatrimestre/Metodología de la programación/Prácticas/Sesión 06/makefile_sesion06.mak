all: saludo mrproper Ej1 Ej2 Ej6 clean fin

# Herramientas en tiempo de ejecución
mrproper: clean
	-rm -f bin/*

clean:
	-rm -f lib/*
	-rm -f obj/*

saludo:
	@echo -e "\n          ################################################"
	@echo      "          #           ATANASIO JOSÉ  RUBIO GIL           #"
	@echo      "          #  METODOLOGÍA DE LA PROGRAMACIÓN - SESIÓN 06  #"
	@echo      "          #            UNIVERSIDAD DE GRANADA            #"
	@echo -e   "          ################################################\n"

fin:
	@echo -e "\n          ################################################"
	@echo      "          #     COMPILACIÓN COMPLETADA CORRECTAMENTE     #"
	@echo -e   "          ################################################\n"

# Órdenes de compilación
Ej1: libVectorDinamico-1 src/II_Demo-VectorDinamico-1.cpp
	g++ -std=c++11 -o bin/II_Demo-VectorDinamico-1 src/II_Demo-VectorDinamico-1.cpp -Iinclude -Llib -lVectorDinamico-1
libVectorDinamico-1: VectorDinamico-1.o
	ar -rvs lib/libVectorDinamico-1.a obj/VectorDinamico-1.o
VectorDinamico-1.o:
	g++ -std=c++11 -c -o obj/VectorDinamico-1.o src/VectorDinamico-1.cpp -Iinclude


Ej2: libVectorDinamico src/II_Demo-VectorDinamico.cpp
	g++ -std=c++11 -o bin/II_Demo-VectorDinamico src/II_Demo-VectorDinamico.cpp -Iinclude -Llib -lVectorDinamico
libVectorDinamico: VectorDinamico.o
	ar -rvs lib/libVectorDinamico.a obj/VectorDinamico.o
VectorDinamico.o:
	g++ -std=c++11 -c -o obj/VectorDinamico.o src/VectorDinamico.cpp -Iinclude


Ej3: libMultiConjunto src/II_Demo-MultiConjunto.cpp
	g++ -std=c++11 -o bin/II_Demo-MultiConjunto src/II_Demo-MultiConjunto.cpp -Iinclude -Llib -lMultiConjunto
libMultiConjunto: MultiConjunto.o
	ar -rvs lib/libMultiConjunto.a obj/MultiConjunto.o
MultiConjunto.o:
	g++ -std=c++11 -c -o obj/MultiConjunto.o src/MultiConjunto.cpp -Iinclude


Ej6: libVectorDinamicoCadenas src/II_Demo-VectorDinamicoCadenas.cpp
	g++ -std=c++11 -o bin/II_Demo-VectorDinamicoCadenas src/II_Demo-VectorDinamicoCadenas.cpp -Iinclude -Llib -lVectorDinamicoCadenas
libVectorDinamicoCadenas: VectorDinamicoCadenas.o
	ar -rvs lib/libVectorDinamicoCadenas.a obj/VectorDinamicoCadenas.o
VectorDinamicoCadenas.o:
	g++ -std=c++11 -c -o obj/VectorDinamicoCadenas.o src/VectorDinamicoCadenas.cpp -Iinclude
