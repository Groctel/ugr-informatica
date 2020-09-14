/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN 
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Clase "SecuenciaEnteros"
// Versión mínima operativa.
//
// Fichero: SecuenciaEnteros.h 
//
/***************************************************************************/

#ifndef SECUENCIA_ENTEROS
#define SECUENCIA_ENTEROS

#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros {

private:

    static const int TAMANIO = 50; // Núm.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros (void);
	
    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void);

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void);

    /***********************************************************************/
    // "Vacía" completamente la secuencia

	void EliminaTodos();

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (int nuevo);
    
    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    int Elemento (int indice);

    /***********************************************************************/
    // Cambia el contenido de la casilla "indice" por el valor "nuevo"
    // PRE: 0 <= indice < total_utilizados

   void Modifica (int indice, int nuevo);

    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice);

    /***********************************************************************/
    // Inserta el carácter "nuevo" en la posición dada por "indice".
    // Desplaza todos los enteros una posición a la derecha antes de 
	// copiar en "indice" en valor "nuevo".
	// PRE: 0 <= indice < total_utilizados

	void Inserta (int indice, int valor_nuevo);
	   
    /***********************************************************************/
    // Compone un string con todos los caracteres que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

	/*****************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

#endif
