#ifndef ALGORITMOS_DE_ORDENACION
#define ALGORITMOS_DE_ORDENACION

const int TAMANIO_PREDET = 20;

typedef int TipoBase;

class Secuencia {
private:
   TipoBase vector[];
   int tamanio;
public:
   Secuencia();
   Secuencia(int tamanio_elegido);
   void RellenaSecuencia();
   ~Secuencia();

   void Vector();
   int Tamanio();
   TipoBase Elemento(int indice);

   void Modifica(int indice, TipoBase candidato);

   void Insertion();
   void Bubble();
   void Quick();
   void Shell();
}

#endif
