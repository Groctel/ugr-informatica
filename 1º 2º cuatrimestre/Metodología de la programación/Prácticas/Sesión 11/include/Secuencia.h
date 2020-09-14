#ifndef CLASE_SECUENCIA
#define CLASE_SECUENCIA

const int TAMANIO = 20;

typedef int TipoBase;

class Secuencia {
private:
   TipoBase vector_secuencia[TAMANIO];
   int capacidad;
   int ocupados;

   void ComparacionValores(int &valor_this, int &valor_other);
public:
   Secuencia(void);
   Secuencia(int capacidad_elegida);
   Secuencia(const Secuencia &origen);
   ~Secuencia();

   void VectorSecuencia();
   TipoBase Elemento(int indice);
   int Capacidad();
   int Ocupados();
   bool EstaVacia();

   bool operator == (const Secuencia &other) const;
   bool operator != (const Secuencia &other) const;
   bool operator < (const Secuencia &other) const;
   bool operator > (const Secuencia &other) const;
   bool operator <= (const Secuencia &other) const;
   bool operator >= (const Secuencia &other) const;

   void Redimensiona();
   void ModificaElemento(int indice, TipoBase nuevo);
   void AniadeElemento(TipoBase nuevo);
   void Inserta (int indice, TipoBase nuevo);
   void Elimina(int indice);
   void EliminaTodos();

};

#endif
