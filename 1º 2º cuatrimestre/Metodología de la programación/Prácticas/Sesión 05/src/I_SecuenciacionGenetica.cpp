#include<iostream>
#include<iomanip>
#include<cstring>
#include "Funcs_SecuenciacionGenetica.h"
using namespace std;


int main() {
   int total_secuencias_1, long_secuencia_1;
   int total_secuencias_2, long_secuencia_2;
   // PRE: 0<=longitud_2<MAXLONGITUD

   char motifs1 [CAPACIDAD][MAXLONGITUD] = {
               {'T','C','G','G','G','G','G','T','T','T','T','T','\0'},
               {'C','C','G','G','T','G','A','C','T','T','A','C','\0'},
               {'A','C','G','G','G','G','G','T','T','T','T','C','\0'},
               {'T','T','G','G','G','G','A','C','T','T','T','T','\0'},
               {'A','A','G','G','G','G','A','C','T','T','C','C','\0'},
               {'T','T','G','G','G','G','A','C','T','T','C','C','\0'},
               {'T','C','G','G','G','G','A','T','T','C','A','T','\0'},
               {'T','C','G','G','G','G','A','T','T','C','C','T','\0'},
               {'T','A','G','G','G','G','A','A','C','T','A','C','\0'},
               {'T','C','G','G','G','T','A','T','A','A','C','C','\0'}
               };
   total_secuencias_1 = 10;
   long_secuencia_1 = LONG_SECUENCIA;

   char motifs2 [CAPACIDAD][MAXLONGITUD] = {
               {'A','C','G','G','G','G','G','T','T','T','T','C','\0'},
               {'T','T','G','G','G','G','A','C','T','T','T','T','\0'},
               {'T','A','G','G','G','G','A','A','C','T','A','C','\0'},
               {'C','C','G','G','T','G','A','C','T','T','A','C','\0'},
               {'T','T','G','G','G','G','A','C','T','T','C','C','\0'},
               {'T','C','G','G','G','G','A','T','T','C','A','T','\0'},
               {'T','C','G','G','G','G','G','T','T','T','T','T','\0'},
               {'A','A','G','G','G','G','A','C','T','T','C','C','\0'},
               {'T','C','G','G','G','G','A','T','T','C','C','T','\0'},
               {'T','C','G','G','G','T','A','T','A','A','C','C','\0'}
               };
   total_secuencias_2 = 10;
   long_secuencia_2 = LONG_SECUENCIA;

   ......

   return 0;
}
