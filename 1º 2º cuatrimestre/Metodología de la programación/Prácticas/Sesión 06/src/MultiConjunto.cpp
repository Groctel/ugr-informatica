#include <iostream>
#include "SecuenciaEnteros.h"
#include "MultiConjunto.h"
using namespace std;

//*************************************************************************//
//  GESTIÓN DE ERRORES
//*************************************************************************//

void PrintError(int error) {
if (error == 0) {
   cerr << "Este aviso no debería salir en el programa. Frenando ejecución."
        << endl;
}
else if (error == 1) {
   cerr << "Argumento inválido. Introduzca uno de estos tres argumentos:\n"
        << " - 1:   Redimensión unitaria.\n"
        << " - 2:   Redimensión en bloques.\n"
        << " - 3:   Redimensión duplicada.\n"
        << "Introduzca el argumento \"-h\" para más información" << endl;
}
else if (error == 2) {
   cerr << "Introduzca sólo un argumento." << endl;
   PrintError(1);
}
}

//*************************************************************************//
//  GESTIÓN DE AVISOS
//*************************************************************************//

void PrintAviso(int aviso) {
if (aviso == 0) {
   cerr << "Este aviso no debería salir en el programa, pero no es lo "
        << "suficientemente grave como para frenar su ejecución." << endl;
}
else if (aviso == 1) {
   cerr << "Demasiados argumentos. Sólo se tendrá en cuenta el primero."
        << endl;
}
}

   //*************************************************************************//
   //  CREA UN MULTICONJUNTO
   //*************************************************************************//

MultiConjunto CreaMultiConjunto(int cap_inic, TipoRedimension tipo) {
   MultiConjunto nuevo_mc;

   nuevo_mc.datos = new TipoBase[cap_inic];
   nuevo_mc.multiplicidad = new int[cap_inic];
   nuevo_mc.usados = 0;
   nuevo_mc.capacidad = cap_inic;
   nuevo_mc.tipo_redimension = tipo;

   return nuevo_mc;
}

   //*************************************************************************//
   //  ELIMINA UN MULTICONJUNTO DEL HEAP
   //*************************************************************************//

void LiberaMultiConjunto(MultiConjunto &multiconjunto) {
   delete []multiconjunto.datos;
   delete []multiconjunto.multiplicidad;
}

   //*************************************************************************//
   //  MUESTRA LA MULTIPLICIDAD DE LOS ELEMENTOS DE UN MULTICONJUNTO
   //*************************************************************************//

int Multiplicidad(MultiConjunto &multiconjunto, const TipoBase elemento) {
   int posicion = -1, multiplicidad = 0;
   bool encontrado = false;

   for (int i = 0; i < multiconjunto.usados && !encontrado; i++) {
      encontrado = multiconjunto.datos[i] == elemento;

      if (encontrado)
         posicion = i;
   }

   if (posicion > -1)
      multiplicidad = multiconjunto.multiplicidad[posicion];

   return multiplicidad;
}

   //*************************************************************************//
   //  MUESTRA LOS ELEMENTOS USADOS DE UN MULTICONJUNTO
   //*************************************************************************//

int Usados(MultiConjunto &multiconjunto) {
   return multiconjunto.usados;
}

   //*************************************************************************//
   //  MUESTRA LA CAPACIDAD DE UN MULTICONJUNTO
   //*************************************************************************//

int Capacidad(MultiConjunto &multiconjunto) {
   return multiconjunto.capacidad;
}

   //*************************************************************************//
   //  AÑADE UN ELEMENTO CON CIERTA MULTIPLICIDAD AL MULTICONJUNTO
   //*************************************************************************//

void Aniade(MultiConjunto &multiconjunto, const TipoBase elemento, int multiplicidad) {
   if (Multiplicidad(multiconjunto, elemento) > 0) {
      bool encontrado = false;

      for (int i = 0; i < multiconjunto.usados && !encontrado; i++) {
         encontrado = multiconjunto.datos[i] == elemento;

         if (encontrado)
            multiconjunto.multiplicidad[i] += multiplicidad;
      }
   }
   else {
      if (Usados(multiconjunto) == Capacidad(multiconjunto))
         RedimensionaMultiConjunto(multiconjunto);

      multiconjunto.datos[multiconjunto.usados] = elemento;
      multiconjunto.multiplicidad[multiconjunto.usados] = multiplicidad;
      multiconjunto.usados++;
   }
}

   //*************************************************************************//
   //  MUESTRA TODOS LOS ELEMENTOS DEL MULTICONJUNTO
   //*************************************************************************//

SecuenciaEnteros Soporte(MultiConjunto &multiconjunto){
   SecuenciaEnteros soporte;

   for (int i = 0; i < multiconjunto.usados; i++) {
      for (int j = 0; j < multiconjunto.multiplicidad[i]; j++) {
         soporte.Aniade(multiconjunto.datos[i]);
      }
   }

   return soporte;
}

   //*************************************************************************//
   //  MUESTRA SI UN MULTICONJUNTO ESTÁ INCLUIDO EN OTRO
   //*************************************************************************//

bool Inclusion (MultiConjunto &multiconjuntoA, MultiConjunto &multiconjuntoB){
   bool incluido = true;

   for (int i = 0; i < multiconjuntoA.usados && incluido; i++) {
      int multiplicidadA = Multiplicidad(multiconjuntoA, multiconjuntoA.datos[i]),
          multiplicidadB = Multiplicidad(multiconjuntoB, multiconjuntoA.datos[i]);

      incluido = multiplicidadA <= multiplicidadB;
   }

	return incluido;
}

   //*************************************************************************//
   //  MUESTRA LA INTERSECCIÓN DE DOS MULTICONJUNTOS
   //*************************************************************************//

MultiConjunto Interseccion(MultiConjunto &multiconjuntoA, MultiConjunto &multiconjuntoB) {
   MultiConjunto interseccion;

   for (int i = 0; i < multiconjuntoA.usados; i++) {
      int multA = Multiplicidad(multiconjuntoA, multiconjuntoA.datos[i]),
          multB = Multiplicidad(multiconjuntoB, multiconjuntoA.datos[i]);

      if (multA > multB)
         multA = multB;

      for (int j = 0; j < multA; j++) {
         Aniade(interseccion, multiconjuntoA.datos[i], 1);
      }
   }

   return interseccion;
}

   //*************************************************************************//
   //  MUESTRA LA UNIÓN DE DOS MULTICONJUNTOS
   //*************************************************************************//

MultiConjunto Union (MultiConjunto &multiconjuntoA, MultiConjunto &multiconjuntoB) {
   MultiConjunto union_mc;

   for (int i = 0; i < multiconjuntoA.usados; i++) {
      int multA = Multiplicidad(multiconjuntoA, multiconjuntoA.datos[i]),
          multB = Multiplicidad(multiconjuntoB, multiconjuntoA.datos[i]);

      if (multA < multB)
         multA = multB;

      for (int j = 0; j < multA; j++) {
         Aniade(union_mc, multiconjuntoA.datos[i], 1);
      }
   }

   for (int i = 0; i < multiconjuntoB.usados; i++) {
      int multB = Multiplicidad(multiconjuntoB, multiconjuntoB.datos[i]),
          multA = Multiplicidad(multiconjuntoA, multiconjuntoB.datos[i]);

      if (multA == 0) {
         for (int j = 0; j < multB; j++) {
            Aniade(union_mc, multiconjuntoB.datos[i], 1);
         }
      }
   }

   return union_mc;
}

   //*************************************************************************//
   //  LO MISMO QUE EL SOPORTE
   //*************************************************************************//

SecuenciaEnteros Todos(MultiConjunto &multiconjunto) {
	return Soporte(multiconjunto);
}

   //*************************************************************************//
   //  REDIMENSIONA UN MULTICONJUNTO EN FUNCIÓN DE SU TIPO DE REDIMENSIÓN
   //*************************************************************************//

void RedimensionaMultiConjunto(MultiConjunto &multiconjunto) {
   int redimension;

   if (multiconjunto.tipo_redimension == TipoRedimension::DeUnoEnUno) {
      redimension = multiconjunto.capacidad + 1;
   }
   else if (multiconjunto.tipo_redimension == TipoRedimension::EnBloques) {
      redimension = multiconjunto.capacidad + TAM_BLOQUE;
   }
   else if (multiconjunto.tipo_redimension == TipoRedimension::Duplicando) {
      redimension = 2 * multiconjunto.capacidad;
   }

   TipoBase * nuevo_mc = new TipoBase[redimension];
   int * nueva_multiplicidad = new int[redimension];

   for (int i = 0; i < multiconjunto.usados; i++) {
      nuevo_mc[i] = multiconjunto.datos[i];
      nueva_multiplicidad[i] = multiconjunto.multiplicidad[i];
   }

   multiconjunto.capacidad = redimension;
   delete []multiconjunto.datos;
   delete []multiconjunto.multiplicidad;
   multiconjunto.datos = nuevo_mc;
   multiconjunto.multiplicidad = nueva_multiplicidad;
}

   //*************************************************************************//
   //  MODIFICA EL TAMAÑO DE UN MULTICONJUNTO PARA QUE SU CAPACIDAD SEA IGUAL AL
   //  NÚMERO DE ELEMENTOS QUE CONTIENE
   //*************************************************************************//

void ReajustaMulticonjunto(MultiConjunto &multiconjunto) {
   TipoBase * nuevo_mc = new TipoBase[multiconjunto.usados];
   int * nueva_multiplicidad = new int[multiconjunto.usados];

   for (int i = 0; i < multiconjunto.usados; i++) {
      nuevo_mc[i] = multiconjunto.datos[i];
      nueva_multiplicidad[i] = multiconjunto.multiplicidad[i];
   }

   multiconjunto.capacidad = multiconjunto.usados;
   delete []multiconjunto.datos;
   delete []multiconjunto.multiplicidad;
   multiconjunto.datos = nuevo_mc;
   multiconjunto.multiplicidad = nueva_multiplicidad;
}
