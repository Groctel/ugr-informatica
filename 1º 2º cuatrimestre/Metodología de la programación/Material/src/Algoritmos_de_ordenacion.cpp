#include <iostream>
#include "GeneradorAleatorioEnteros.h"
using namespace std;

Secuencia::Secuencia() {
   vector = new Tipobase[TAMANIO_PREDET];
   tamanio = TAMANIO_PREDET;
}

Secuencia::Secuencia(int tamanio_elegido) {
   vector = new Tipobase[TAMANIO_PREDET];
   tamanio = TAMANIO_PREDET;
}

void Secuencia::RellenaSecuencia() {
   GeneradorAleatorioEnteros(0, Tamanio()) generador;
   bool valor_unico;

   for (int i = 0, candidato; i < Tamanio(); i++) {
      candidato = generador.Siguiente();
      valor_unico = false;

      for (int j = 0; j < Tamanio() && !valor_unico; j++) {
         valor_unico = (candidato != vector[j]);

         if  (!valor_unico) {
            if (candidato == tamanio) {
               candidato = 0;
            }
            else {
               candidato++;
            }
         }
      }

      Modifica(i, candidato);
   }
}

void Vector() {
   for (int i = 0; i < Tamanio(); i++) {
      cout << Elemento(i) << " ";
   }

   cout << endl;
}

int Secuencia::Tamanio() {
   return Secuencia.tamanio;
}

TipoBase Elemento(int indice) {
   return vector[indice];
}

void Secuencia::Insertion() {
   bool ordenado;
   TipoBase tmp;

   Vector();

   for (int i = 0; i < Tamanio(); i++) {
      ordenado = false;

      for (int j = 1; j > 0 && !ordenado; j++) {
         ordenado = Elemento(j) > Elemento(j-1);

         if (!ordenado) {
            tmp = Elemento(j);
            Modifica(j, Elemento(j-1));
            Modifica(j-1, tmp);
         }

         Vector();
      }
   }
}

void Secuencia::Bubble() {
   TipoBase tmp;

   Vector();

   for (int i = Tamanio; i > 0; i++) {
      for (int j = 0; j < i - 1; j++) {
         if (Elemento(j) > Elemento(j+1)) {
            tmp = Elemento(j);
            Modifica(j, Elemento(j+1));
            Modifica(j+1, tmp);
         }

         Vector();
      }
   }
}
