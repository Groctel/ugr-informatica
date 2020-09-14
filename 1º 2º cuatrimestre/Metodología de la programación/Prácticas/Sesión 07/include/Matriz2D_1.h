#ifndef MATRIZ2D_1
#define MATRIZ2D_1


const int MAX_TAMANIO = 65535;


typedef int TipoBase;
typedef struct {
               TipoBase ** datos;
               int fils;
               int cols;
            } Matriz2D;


void PrintError(int);
void PrintAviso(int);
Matriz2D CreaMatriz2D(int, int);
Matriz2D CreaYRellenaMatriz2D(int, int);
void EliminaMatriz2D(Matriz2D &);
void MuestraMatriz2D(const Matriz2D &);
TipoBase ElementoMatriz2D(const Matriz2D &, int, int);
void ModificaElementoMatriz2D(const Matriz2D &, int, int, TipoBase);
Matriz2D CopiaMatriz2D(const Matriz2D &);
Matriz2D ExtraeSubmatriz2D(const Matriz2D &, int, int, int, int);
Matriz2D EliminaFilMatriz2D(Matriz2D &, int);
Matriz2D EliminaColMatriz2D(Matriz2D &, int);
Matriz2D TraspuestaMatriz2D(const Matriz2D &);
Matriz2D InvierteMatriz2D(const Matriz2D &);


#endif
