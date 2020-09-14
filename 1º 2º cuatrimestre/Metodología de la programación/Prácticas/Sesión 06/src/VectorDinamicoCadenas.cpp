#include <iostream>
#include <cstring>
#include <cctype>
#include "VectorDinamicoCadenas.h"
using namespace std;

char ** SepararCadena(string cadena, int & lineas){
   int tam_cadena;
   int j = 0;

   tam_cadena = cadena.size();

   for (int i = 0; i < tam_cadena; i++){
      if (cadena[i] == '\n')
         lineas++;
   }

   char ** cadenas = new char * [lineas];

   for (int i = 0; i < lineas; i++){
      string fila = "";

      while (cadena[j] != '\n'){
         fila = fila + cadena[j];
         j++;
      }
      j++;

      char * linea = new char [fila.size()];

      strcpy(linea, fila.c_str());

      cadenas[i] = linea;
   }

   return cadenas;
}


int NumLineasVacias(char ** documento, const int lineas){
   int lineas_vacias;
   for (int i = 0; i < lineas;i++){
      if (documento[i][0] == '\0')
         lineas_vacias++;
   }

   return lineas_vacias;
}


int NumParrafos (char ** documento,const int lineas){
   int parrafos = 0;
   bool mismo_parrafo = !LineaEnBlanco(documento, 0);


   for(int i = 0; i < lineas - 1 ; i++){
      if (mismo_parrafo){
         if ( LineaEnBlanco(documento, i + 1) ){
            parrafos++;
            mismo_parrafo = false;
         }
      }
      else{
         mismo_parrafo = !LineaEnBlanco(documento, i + 1);
      }
   }

   if(mismo_parrafo)
      parrafos++;

   return parrafos;
}


bool LineaEnBlanco(char ** documento, const int NUM_LINEA){
   char * linea = documento[NUM_LINEA];

   bool linea_blanco = true;
   while ( *linea && linea_blanco){
      if ( !isspace ( *linea ) ){
         linea_blanco = false;
      }
      linea++;
   }

   return linea_blanco;
}
