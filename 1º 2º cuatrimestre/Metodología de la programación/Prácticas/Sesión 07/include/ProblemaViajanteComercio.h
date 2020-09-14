#ifndef PROBLEMA_VIAJANTE_COMERCIO
#define PROBLEMA_VIAJANTE_COMERCIO


typedef struct {
               int ** ciudades;
               int fils;
               int cols;
               } Matriz2D;


void PrintAyuda();
Matriz2D CreaMatriz2D(int, int);
Matriz2D CreaYRellenaMatriz2D(int, int);
void EliminaMatriz2D(Matriz2D &);
void MuestraMatriz2D(const Matriz2D &);
int ElementoMatriz2D(const Matriz2D &, int, int);
void ModificaElementoMatriz2D(const Matriz2D &, int, int, int);
Matriz2D EliminaFilMatriz2D(Matriz2D &, int);
void Resolucion(Matriz2D);


#endif
