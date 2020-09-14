/************************************************************
	Práctica 6
	Fichero: MultiConjunto.h

	Inés Nieto Sánchez


/************************************************************/

#ifndef MULTICONJUNTO
#define MULTICONJUNTO


const int TAM_INICIAL = 10;
const int TAM_BLOQUE = 5;
const int TOPE_INFERIOR = 1;
const int TOPE_SUPERIOR = 1000;


enum class TipoRedimension {
                           DeUnoEnUno,
                           EnBloques,
                           Duplicando
                           };


typedef int TipoBase;
typedef struct {
               TipoBase * datos;
               int * multiplicidad;
               int usados;
               int capacidad;
               TipoRedimension tipo_redimension;
               } MultiConjunto;

void PrintError(int);
void PrintAviso(int);
MultiConjunto CreaMultiConjunto (int, TipoRedimension);
void EliminaMultiConjunto(MultiConjunto &);
void RedimensionaMultiConjunto(MultiConjunto &);
void ReajustamultiConjunto(MultiConjunto &);
int Multiplicidad (MultiConjunto &, const TipoBase);
int Usados(MultiConjunto &);
int Capacidad(MultiConjunto &);
void Aniade(MultiConjunto &, const TipoBase, int);
SecuenciaEnteros Soporte(MultiConjunto &);
bool Inclusion(MultiConjunto &, MultiConjunto &);
MultiConjunto Interseccion(MultiConjunto &, MultiConjunto &);
MultiConjunto Union(MultiConjunto &, MultiConjunto &);
SecuenciaEnteros Todos(MultiConjunto &);


#endif
