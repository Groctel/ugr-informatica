#ifndef VECTORDINAMICO
#define VECTORDINAMICO


enum class TipoRedimension {
                           DeUnoEnUno,
                           EnBloques,
                           Duplicando
                           };


void PrintError(int);
void PrintAviso(int);
int * Redimensiona(int *, TipoRedimension, int &);


const int TAM_INICIAL = 5;
const int TAM_BLOQUE = 5;
const int TERMINADOR = -1; // < 0.


#endif
