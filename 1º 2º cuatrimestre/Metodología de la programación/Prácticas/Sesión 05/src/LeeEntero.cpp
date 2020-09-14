#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>
#include "LeeEntero.h"
using namespace std;


//Comprobar si todos los elementos del array son dígitos
bool EsEntero(char * cadena){
	const char * p_cad = cadena;
	const char * p_final = cadena + strlen(cadena);
	bool son_digitos = true;

	//Ignorar los espacios en blanco al principio
	while (isspace(*p_cad)){
		p_cad++;
	}

	while (isspace(*p_final)) {
		p_final--;
	}

	if ( *p_cad == '+' || *p_cad == '-')
		p_cad++;

   //Recorremos la cadena para ver si los elementos están entre el 0 y el 9
   //de la tabla ASCII
	while(*p_cad && son_digitos && p_cad < p_final){
		if(*p_cad < '0' || *p_cad > '9') {
			son_digitos = false;
      }
		p_cad++;
	}

	return son_digitos;
}

//Pasar una cadena a un entero si sus elementos son dígitos.
int CadenaAEntero(const char * cadena) {
   const char CERO = '0';
   const char * p_cad = cadena;
   int entero = 0;
   int posicion = pow(10, strlen(cadena) - 1);

	//Si el primer elemento es el signo se avanza el puntero y se divide la posición
	// entre 10 para hacer bien la descomposición del número.
   if(*p_cad == '+' || *p_cad == '-'){
      p_cad++;
      posicion = posicion / 10;
   }

	//Mientras el elemento no sea un separador final (un espacio en blanco)
	// se avanza el puntero y se resta el valor ASCII del caracter '0' y se
	//multiplica por la posición
   if(EsEntero(cadena)){
      while(* p_cad != ' '){
         entero += (*p_cad - CERO) * posicion;
         posicion = posicion / 10;
         p_cad++;
      }
   }

   return entero;
}


int LeeEntero(char * cadena, const int MAX) {
	cin.getline(cadena, MAX);
	int entero;

	//Mientras la cadena no sea un entero válido se vuelve a pedir introducirla
	while(!EsEntero(cadena)) {
		cout << "Introduce una cadena válida: " << endl;
		cin.getline(cadena, MAX);
	}

	entero = CadenaAEntero(cadena);

	return entero;
}

bool PerteneceIntervalo(int maximo, int entero) {
	bool pertenece;
	const int minimo = 0;

 	while (maximo < 0 || maximo > 9) {
		cout << "El máximo debe estar entre 0 y 9: " << endl;
		cin >> maximo;
	}

	if (minimo < entero && entero < maximo) {
		pertenece = true;
	}
	else {
		pertenece = false;
	}

	return pertenece;
}


bool PerteneceIntervalo(int minimo, int maximo, int entero) {
	bool pertenece;

	while (maximo < minimo) {
		cout << "Introduce un máximo válido: " << endl;
		cin >> maximo;
	}

	if (minimo < entero && entero < maximo) {
		pertenece = true;
	}
	else {
		pertenece = false;
	}

	return pertenece;
}

/*#include <cmath>
#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
#include "LeeEntero.h"
using namespace std;


////////Clase para generar enteros aleatorios.
class GeneradorAleatorioEnteros {
private:
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   long long Nanosec(){
      return (chrono::high_resolution_clock::now().time_since_epoch().count());
   }

public:
   GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1)
   { }

   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006
      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }

   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
};


int longitud_cadena(const char *cadena) {
   int tamanio = 0;

   while (*cadena != '\0') {
      tamanio++;
      cadena++;
   }

   return tamanio;
}


char * elimina_blancos_iniciales(const char *origen) {
   char *destino[longitud_cadena(origen)];

   while (*origen == BLANCO) {
      origen++;
   }

   for (; *origen != '\0'; origen++, destino++) {
      *destino = *origen;
   }

   *destino = '\0';

   return destino;
}


char * elimina_blancos_finales(const char *origen) {
   char *destino[longitud_cadena(origen)];

   const char *fin_texto = origen + longitud_cadena(origen) - 1;

   while (*fin_texto == BLANCO) {
      fin_texto--;;
   }

   for (; origen <= fin_texto; origen++, destino++) {
      *destino = *origen;
   }

   *(destino) = '\0';

   return destino;
}


char * elimina_blancos_extremos(const char *origen) {
   char *intermedio[longitud_cadena(origen)], destino[longitud_cadena(origen)];
   char *destino = elimina_blancos_finales(elimina_blancos_iniciales(origen));
}


bool es_entero(const char *origen) {
   const char *p = origen;
   bool es_entero = true;

   if (*p == '-') {
      p++;
   }

   while (*p != '\0' && es_entero) {
      es_entero = ('0' <= *p && *p <= '9');
      p++;
   }

   return es_entero;
}


int lee_entero(const char *origen) {
   char arreglado[longitud_cadena(origen)];
   arreglado = elimina_blancos_extremos(origen);

   const char *p = origen;
   int numero = 0, longitud = 0;

   if (*p == '-') {
      p++;
   }

   while (*p != '\0') {
      longitud++;
      p++;
   }

   p = origen;
   if (*p == '-') {
      p++;
   }

   while (*p != '\0') {
      numero += (*p - '0') * pow(10, longitud - 1);
      p++;
      longitud--;
   }

   p = origen;
   if (*p == '-') {
      numero *= -1;
   }

   return numero;
}


int entero_intervalo(int cota_inferior, int cota_superior) {
   GeneradorAleatorioEnteros generador(cota_inferior, cota_superior);
   return generador.Siguiente();
}*/
