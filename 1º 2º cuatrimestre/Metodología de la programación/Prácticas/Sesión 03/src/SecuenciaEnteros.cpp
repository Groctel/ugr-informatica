/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN 
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Clase "SecuenciaEnteros"
// Versión mínima operativa.
//
// Fichero: SecuenciaEnteros.cpp 
//
/***************************************************************************/

#include <string>
#include "SecuenciaEnteros.h"

using namespace std;

/***************************************************************************/
// Constructor sin argumentos
    
SecuenciaEnteros :: SecuenciaEnteros (void) : total_utilizados (0) 
{}

/***************************************************************************/
// Devuelve el número de casillas ocupadas

int SecuenciaEnteros :: TotalUtilizados (void)
{
    return (total_utilizados);
}

/***************************************************************************/
// Devuelve el número de casillas disponibles

int SecuenciaEnteros :: Capacidad (void)
{
    return (TAMANIO);
}

/***************************************************************************/
// "Vacía" completamente la secuencia

void SecuenciaEnteros :: EliminaTodos(void)
{
	total_utilizados = 0;
}

/***************************************************************************/
// Añade un elemento ("nuevo") al vector.
// PRE: total_utilizados < TAMANIO
// 		La adición se realiza si hay alguna casilla disponible.
// 		El nuevo elemento se coloca al final del vector.
// 		Si no hay espacio, no se hace nada.

void SecuenciaEnteros :: Aniade (int nuevo)
{
    if (total_utilizados < TAMANIO){
        vector_privado[total_utilizados] = nuevo;
        total_utilizados++;
    }
}

/***************************************************************************/
// Devuelve el elemento de la casilla "indice"
// PRE: 0 <= indice < total_utilizados

int SecuenciaEnteros :: Elemento (int indice)
{
    return (vector_privado[indice]);
}

/***************************************************************************/
// Cambia el contenido de la casilla "indice" por el valor "nuevo"
// PRE: 0 <= indice < total_utilizados

void SecuenciaEnteros :: Modifica (int indice, int nuevo)
{
    if ((indice >= 0) && (indice < total_utilizados)) {
		vector_privado[indice] = nuevo;
	}
}

/***************************************************************************/
// Eliminar el carácter de la posición dada por "indice".
// Realiza un borrado físico (desplazamiento y sustitución).
// PRE: 0 <= indice < total_utilizados

void SecuenciaEnteros :: Elimina (int indice)
{
    if ((indice >= 0) && (indice < total_utilizados)) {

        int tope = total_utilizados-1; // posic. del último

        for (int i = indice ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

        total_utilizados--;
    }
}

/***************************************************************************/
// Inserta el carácter "nuevo" en la posición dada por "indice".
// Desplaza todos los caracteres una posición a la derecha antes de 
// copiar en "indice" en valor "nuevo".
// PRE: 0 <= indice < total_utilizados

void SecuenciaEnteros :: Inserta (int indice, int valor_nuevo)
{
    if ((total_utilizados < TAMANIO) && (indice >= 0) 
	    && (indice < total_utilizados)) {
	
		for (int i = total_utilizados ; i > indice ; i--)
			vector_privado[i] = vector_privado[i-1];
		
		vector_privado[indice] = valor_nuevo;
		total_utilizados++;		
	}
}

/***************************************************************************/
// Compone un string con todos los enteros que están
// almacenados en la secuencia y lo devuelve.

string SecuenciaEnteros :: ToString()
{
    string cadena;

	cadena = "[ ";
    for (int i=0; i<total_utilizados; i++)
        cadena = cadena + "  " + to_string(vector_privado[i]);

	cadena = cadena + "]";

    return (cadena);
}

/***************************************************************************/
