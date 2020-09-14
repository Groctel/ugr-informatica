#ifndef SECUENCIA_ENTEROS
#define SECUENCIA_ENTEROS


class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   long vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      long intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }

public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }

   int TotalUtil(){
      return total_utilizados;
   }

   int Capacidad(){
      return TAMANIO;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Aniade(long nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   long Elemento(int indice){
      return vector_privado[indice];
   }
};


#endif
