#include <iostream>
using namespace std;

void Secuencia::ComparacionValores(int &valor_this, int &valor_other) {
   for (int i = 0; i < this.Ocupados(); i++) {
      valor_this += Elemento(i);
   }
   for (int i = 0; i < other.Ocupados(); i++) {
      valor_other += Elemento(i);
   }
}

Secuencia::Secuencia() {
   cout << "Iniciando creación de secuencia predeterminada..." << endl;

   vector_secuencia = new TipoBase[TAMANIO];
   capacidad = TAMANIO;
   ocupados = 0;

   cout << "Secuencia predeterminada creada con éxito:" << endl
        << " - Capacidad inicial: " << capacidad << endl
        << " - Casillas ocupadas: " << ocupadas << endl;
}

Secuencia::Secuencia(int capacidad_elegida) {
   cout << "Iniciando creación de secuencia personalizada..." << endl;

   vector_secuencia = new TipoBase[capacidad_elegida];
   capacidad = capacidad_elegida;
   ocupados = 0;

   cout << "Secuencia personalizada creada con éxito:" << endl
        << " - Capacidad inicial: " << capacidad << endl
        << " - Casillas ocupadas: " << ocupadas << endl;
}

Secuencia::Secuencia(const Secuencia &origen) {
   cout << "Iniciando copia profunda de la secuencia..." << endl;

   vector_secuencia = new TipoBase[origen.Capacidad()];
   capacidad = origen.Capacidad();
   ocupados = origen.Ocupados();

   for (int i = 0; i < Capacidad(); i++) {
      ModificaElemento(i, origen.Elemento(i));
   }

   cout << "Secuencia copiada con éxito:" << endl
        << " - Capacidad inicial: " << capacidad << endl
        << " - Casillas ocupadas: " << ocupadas << endl;
}

Secuencia::~Secuencia() {
   delete vector_secuencia[];

   cout << "Secuencia destruida con éxito";
}

Secuencia &Secuencia::operator == (const Secuencia &other) {
   bool iguales = true;

   if (this.Ocupados() == other.Ocupados()) {
      for (int i = 0; i < this.Ocupados() && iguales; i++) {
         if (this.Elemento(i) != other.Elemento(i))
            iguales = false;
      }
   }
   else {
      iguales = false;
   }

   return iguales;
}

Secuencia &Secuencia::operator == (const Secuencia &other) {
   return !(*this == other);
}

Secuencia &Secuencia::operator < (const Secuencia &other) {
   int valor_this = 0, valor_other = 0;

   ComparacionValores(valor_this, valor_other);

   return valor_this < valor_other;
}

Secuencia &Secuencia::operator > (const Secuencia &other) {
   int valor_this = 0, valor_other = 0;

   ComparacionValores(valor_this, valor_other);

   return valor_this > valor_other;
}

Secuencia &Secuencia::operator <= (const Secuencia &other) {
   int valor_this = 0, valor_other = 0;

   ComparacionValores(valor_this, valor_other);

   return valor_this <= valor_other;
}

Secuencia &Secuencia::operator >= (const Secuencia &other) {
   int valor_this = 0, valor_other = 0;

   ComparacionValores(valor_this, valor_other);

   return valor_this >= valor_other;
}

void Secuencia::VectorSecuencia() {
   cout << "[";

   for (int i = 0; i < Ocupados(); i++) {
      cout << Elemento(i);
      if (i < Ocupados() - 1)
         cout << ", ";
   }

   cout << "]" << endl;
}

TipoBase Secuencia::Elemento(int indice) {
   return vector_secuencia[indice];
}

int Secuencia::Capacidad() {
   return capacidad;
}

int Secuencia::Ocupados() {
   return ocupados;
}

bool EstaVacia() {
   return !Ocupados();
}

void Secuencia::ModificaElemento(int indice, TipoBase nuevo) {
   vector_secuencia[indice] = nuevo;
}

void Secuencia::Redimensiona(int nuevo_tamanio) {
   if (Ocupados() == Capacidad()) {
      tmp = new vector_secuencia[Capacidad() * 2];
      capacidad *= 2;

      for (int i = 0; i < nuevo_tamanio; i++) {
         tmp[i] = Elemento(i);
      }

      delete vector_secuencia;
      vector_secuencia = tmp;
   }
}

void Secuencia::ModificaElemento(int indice, TipoBase nuevo) {
   vector_secuencia[indice] = nuevo;
}

void Secuencia::AniadeElemento(TipoBase nuevo) {
   Redimensiona();

   vector_secuencia[Ocupados() + 1]  = nuevo;

   ocupados++;
}

void Secuencia::Inserta(int indice, TipoBase nuevo) {
   Redimensiona();

   for (int i = indice; i <= Ocupados(); i++) {
      vector_secuencia[i + 1] = Elemento(i);
   }

   vector_secuencia[indice] = nuevo;
}

void Elimina (int indice) {
   for (int i = indice; i < Ocupados() - 1; i++) {
      vector_secuencia[i] = Elemento(i + i)
   }

   ocupados--;
}

void EliminaTodos() {
   tmp = new vector_secuencia[Capacidad()];
   delete vector_secuencia;
   vector_secuencia = tmp;
}
