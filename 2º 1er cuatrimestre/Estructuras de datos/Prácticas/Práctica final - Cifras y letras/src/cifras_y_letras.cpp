/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file src/cifras_y_letras.cpp
  */

#include <cstdio>
#include <fstream>
#include "diccionario.hpp"
#include "letra.hpp"

int main (int argc, char ** argv) {
/*
 *	Abrimos el fichero diccionario y, si fracasamos, cerramos el programa con un
 *	mensaje de error.
 */
	std::ifstream fi(argv[1]);

	if (!fi) {
		printf ("\033[1;31m:: \033[33m%s \033[31m%s\n\033[0m",
		        "No se pudo abrir el fichero", argv[1]);
		exit(1);
	}
/*
 *	Declaración de variables.
 */
	bool coincide = false;     // Indicador de palabra cotejada correctamente
	unsigned max_long,         // Longitud de la palabra más larga de todas
	         tam_bolsa,        // Tamaño de la bolsa de letras
	         total_letras = 0, // Total de letras a lo largo del diccionario
	         random,           // Generador aleatorio de letras para la bolsa
	         valor_max = 0;    // Valor de la palabra más valiosa de todas
	Diccionario dic;           // Diccionario de palabras con el que se juega
	Bolsa bolsa;               // Bolsa de letras con la que se juega
	std::vector<Letra> puntuacion;  // Puntos de cada letra
	std::set<std::string> palabras; // Palabras encontradas con la bolsa
	std::string mas_larga,          // Palabra más larga de las encontradas
	            mas_valiosa;        // Palabra con más puntos de las encontradas
/*
 *	Inicializamos el generador aletaorio de caracteres con el que se crea la
 *	bolsa de letras.
 */
	printf ("\033[1;34m==> \033[0m%s\n",
	        "Inicializando generador aleatorio de caracteres...");

	srand(time(NULL));
/*
 *	Introducimos todas las palabras del fichero de palabras en el diccionario.
 */
	fi >> dic;
/*
 *	Calculamos las puntuaciones de cada letra, la longitud de la palabra más
 *	larga del diccionario y el total de letras a lo largo del diccionario.
 */
	printf ("\033[1;34m==> \033[0m%s\n",
	        "Calculando la distribución de caracteres en su diccionario...");

	puntuacion = dic.CuentaLetras();
	max_long   = dic.MaximaLongitud();

	for (std::vector<Letra>::const_iterator
	     it=puntuacion.cbegin(); it!=puntuacion.cend();
		  ++it, total_letras += (*it).Frecuencia());
/*
 *	Pedimos al usuario del tamaño de su bolsa de letras, que no puede tener más
 *	letras que la palabra más larga del diccionario, ya que sería absurdo.
 */
	printf ("\033[1;32m::  \033[0m%s%d%s",
	        "Indique el tamaño de su bolsa de letras (0-", max_long, "): ");
	scanf ("%d", &tam_bolsa);

	if (tam_bolsa > max_long)
		tam_bolsa = max_long;

	bolsa.NuevoMax(tam_bolsa);
/*
 *	Generamos aleatoriamente la bolsa de letras, generando un número entre 0 y el
 *	número total de letras y asignándolo a la letra con esa frecuencia absoluta
 *	acumulada (si tuviéramos 100 'a' y 100 'b', el 50 iría a la 'a' y el 150, a
 *	la 'b').
 */
	printf ("\033[1;34m==> \033[0m%s \033[1;36m[\033[0m",
	        "Introduciendo letras en la bolsa...");

	for (unsigned i=0; i<bolsa.Max(); i++) {
		std::vector<Letra> ::const_iterator it = puntuacion.cbegin();

		random = rand() % total_letras + 0; // [minimo - maximo)

		for (unsigned i=0; i<random && it!=puntuacion.cend(); ++it) {
			i+=(*it).Frecuencia();
		}

		--it;

		bolsa.Aniade((*it).Grafema());
		printf ("%c, ", (*it).Grafema());
	}
/*
 *	Ajustamos la puntuación de las letras en función de su frecuencia absoluta,
 *	restando ésta al total de letras del diccionario, de forma que las letras más
 *	escasas son las más valiosas.
 */
	for (std::vector<Letra>::iterator it=puntuacion.begin();
	     it!=puntuacion.end();
		  ++it, (*it).NuevaFrecuencia(total_letras - (*it).Frecuencia()));
/*
 *	Buscamos todas las palabras construíbles con la bolsa de letras e
 *	inicializamos la palabra más larga y la más valiosa a la primera de éstas.
 */
	printf ("\b\b\033[1;36m]\033[0m\n"
	        "\033[1;34m==> \033[0m%s\n",
			  "Buscando coincidencias...");

	palabras = dic.BuscaPalabras(bolsa);
	mas_larga = mas_valiosa = *palabras.cbegin();
/*
 *	Buscamos la palabra más larga comparando la longitud de ésta y cada una del
 *	conjunto de palabras coincidentes y la mostramos.
 */
	for (std::set<std::string>::const_iterator it=palabras.cbegin();
	     it!=palabras.cend(); ++it) {
		if ((*it).length() > mas_larga.length())
			mas_larga = *it;
	}

	printf ("\033[1;34m==> \033[0mLa palabra más larga es \"%s\"\n",
			  mas_larga.c_str());
/*
 *	Buscamos la palabra más valiosa, calculando primer el valor de la palabra más
 *	valiosa por defecto y luego comparándola con cada una del conjunto de
 *	palabras conincidentes, y la mostramos.
 */
	for (std::string::const_iterator jt=mas_valiosa.cbegin();
	     jt!=mas_valiosa.cend(); ++jt, coincide = false) {

		for (std::vector<Letra>::const_iterator kt =
		     puntuacion.cbegin(); kt!=puntuacion.cend() && !coincide; ++kt) {
			if (*jt == (*kt).Grafema())
				coincide = valor_max += (*kt).Frecuencia();
		}
	}

	coincide = false;

	for (std::set<std::string>::const_iterator it=palabras.cbegin();
	     it!=palabras.cend(); ++it) {
		unsigned valor_actual = 0;

		for (std::string::const_iterator jt=(*it).cbegin();
		     jt!=(*it).cend(); ++jt, coincide = false) {

			for (std::vector<Letra>::const_iterator kt =
			     puntuacion.cbegin(); kt!=puntuacion.cend() && !coincide; ++kt) {
				if (*jt == (*kt).Grafema())
					coincide = valor_actual += (*kt).Frecuencia();
			}
		}

		if (valor_actual > valor_max) {
			valor_max   = valor_actual;
			mas_valiosa = (*it);
		}
	}

	printf ("\033[1;34m==> \033[0mLa palabra más valiosa es \"%s\"\n",
			  mas_valiosa.c_str());

	/*
	for (std::set<std::string>::const_iterator it=palabras.cbegin();
	     it!=palabras.cend(); ++it)
		printf("%s ", (*it).c_str());

	printf("\n");
	*/
}
