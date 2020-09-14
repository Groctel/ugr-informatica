#include <iostream>
using namespace std;

const int Terminador = 0; // >=

typedef int TipoBase;
struct Nodo {
            TipoBase dato;
            Nodo * siguiente;
            };
typedef Nodo * Lista;
typedef Nodo * PNodo;

Lista CreaLista() {
   TipoBase valor;
   Lista lista;
   PNodo nuevo, ultimo;
   char *mensaje = "Introduzca un valor positivo: ";

   cout << mensaje;
   cin >> valor;

   if (valor >= TERMINADOR) {
      lista = new Nodo;
      lista->dato = valor;
      lista->siguiente = 0;
      ultimo = lista;

      cout << mensaje;
      cin >> valor;

      while (valor >= TERMINADOR) {
         nuevo = new Nodo;
         ultimo->siguiente = nuevo;
         ultimo = nuevo;
         ultimo->dato = valor;

         cout << mensaje;
         cin >> valor;
      }
   }

   return lista;
}

PNodo &ElementoLista(const Lista &lista, int indice) {
   PNodo lector = lista;

   for (int i = 0; i < indice; lector = lector->siguiente, i++);

   return lector;
}

TipoBase DatoNodoLista(const Lista &lista, int indice) {
   PNodo lector = lista;

   return ElementoLista(lector, indice)->dato;
}

void AniadeElementoLista(const Lista &lista, int indice_pre) {
   int indice;

   for (PNodo lector = lista;
        indice < indice_pre && lector != 0;
        lector = lector->siguiente, indice++);

   if 
}

void ImprimeLista(const Lista &lista) {
   if (!EsListaVacia(lista)) {
      PNodo lector = lista

      for (int i = 0; lector != 0; lector = lector->siguiente, i++) {
         cout << "Elemento " << i << ": " << DatoNodoLista(lista, i) << endl;
      }
   }
   else {
      cout << "La lista está vacía.";
   }
}

bool EsListaVacia(const Lista &lista) {
   return (lista->siguiente == 0);
}

int CuentaElementosLista(const Lista &lista) {
   int i = 0;

   for (Pnodo lector = lista; lector != 0; lector = lector->siguiente, i++);

   return i;
}

int MediaAritmeticaLista(const Lista &lista) {
   int elementos = CuentaElementosLista(lista);
   double media = 0.0;

   for (Pnodo lector = lista; lector != 0; lector = lector->siguiente) {
      media += lector->dato / elementos;
   }

   return media;
}

int main() {
   Lista lista = CreaLista();

   return 0;
}
