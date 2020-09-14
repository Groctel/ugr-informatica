#ifndef VECTORDINAMICO
#define VECTORDINAMICO


const int TAM_INICIAL = 10;
const int TAM_BLOQUE = 5;
const int TERMINADOR = -1; // < 0.


enum class TipoRedimension {
                           EnBloques,
                           DeUnoEnUno,
                           Duplicando
                           };


typedef int TipoBase;
typedef struct {
               TipoBase * datos;
               int usados;
               int capacidad;
               TipoRedimension tipo_redimension;
               } VectorDinamico;


void PrintError(int);
void PrintAviso(int);
VectorDinamico CreaVectorDinamico (int, TipoRedimension);
void LiberaVectorDinamico(VectorDinamico &);
int UsadosVectorDinamico(const VectorDinamico);
int CapacidadVectorDinamico(const VectorDinamico);
TipoBase ElementoVectorDinamico(const VectorDinamico, int);
void MuestraVectorDinamico(const VectorDinamico);
void AniadeVectorDinamico(VectorDinamico &, const TipoBase);
void RedimensionaVectorDinamico(VectorDinamico &);
void ReajustaVectorDinamico(VectorDinamico &);


#endif
