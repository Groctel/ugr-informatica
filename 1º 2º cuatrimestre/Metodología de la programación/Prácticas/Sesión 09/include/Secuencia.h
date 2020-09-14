#ifndef SECUENCIA
#define SECUENCIA

typedef int TipoBase;

class Secuencia {
private:
   const int MAX = 255;
   Tipobase vector[MAX];
public:
   Secuencia();
   Secuencia(int capacidad);
   Secuencia(const Secuencia &otra);
   ~Secuencia();

   bool EstaVacia();
   int TotalUtilizados();
   int Capacidad();
   void EliminaTodos();
   TipoBase Elemento();
   void Modifica();
   void Aniade();
   void Inserta();
   void Elimina();
};

#endif
