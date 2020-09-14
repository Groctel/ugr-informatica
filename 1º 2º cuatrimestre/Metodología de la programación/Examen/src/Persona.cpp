#include "GeneradorAleatorioEnteros.h"
#include "Persona.h"

#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

Persona :: Persona()
{
   Creador();
}


Persona :: Persona(char* nuevodni)
   : dni(nuevodni)
{
   Creador();
}


Persona :: Persona(const Persona &otra)
{ }


void Persona :: Creador() {
   char* entrada = new char[255];

   cout << "--------------------------------------------------\n"
        << "||    INTRODUCCIÓN DE DATOS DE NUEVA PERSONA    ||\n"
        << "--------------------------------------------------\n\n"
        << "Nombre:                  ";
   do {
      cin.getline(entrada, 255);

      if (!strcmp(entrada, ""))
         cout << "No puede estar vacío:    ";
   } while (!strcmp(entrada, ""));

   AsignaDato(nombre, entrada);

   cout << "Apellidos:               ";
   do {
      cin.getline(entrada, 255);

      if (!strcmp(entrada, ""))
         cout << "No puede estar vacío:    ";
   } while (!strcmp(entrada, ""));

   AsignaDato(apellidos, entrada);

   cout << "Mote (opcional):         ";
   cin.getline(entrada, 255);

   AsignaDato(mote, entrada);

   cout << "País de nacimiento:      ";
   do {
      cin.getline(entrada, 255);

      if (!strcmp(entrada, ""))
         cout << "No puede estar vacío:    ";
   } while (!strcmp(entrada, ""));

   AsignaDato(pais_nacimiento, entrada);

   cout << "Ciudad de nacimiento:    ";
   do {
      cin.getline(entrada, 255);

      if (!strcmp(entrada, ""))
         cout << "No puede estar vacío:    ";
   } while (!strcmp(entrada, ""));

   AsignaDato(ciudad_nacimiento, entrada);

   cout << "País de residencia:      ";
   do {
      cin.getline(entrada, 255);

      if (!strcmp(entrada, ""))
         cout << "No puede estar vacío:    ";
   } while (!strcmp(entrada, ""));

   AsignaDato(pais_residencia, entrada);

   cout << "Ciudad de residencia:    ";
   do {
      cin.getline(entrada, 255);

      if (!strcmp(entrada, ""))
         cout << "No puede estar vacío:    ";
   } while (!strcmp(entrada, ""));

   AsignaDato(ciudad_residencia, entrada);

   cout << "Edad (años):             ";
   do {
      cin >> edad;

      if (edad <= 0)
         cout << "Debe ser mayor que 0:     ";
   } while (edad < 0);

   cout << "Altura (metros):         ";
   do {
      cin >> altura;

      if (altura <= 0)
         cout << "Debe ser mayor que 0:     ";
   } while (altura <= 0);

   cout << "Peso (kg):               ";
   do {
      cin >> peso;

      if (peso <= 0)
         cout << "Debe ser mayor que 0:     ";
   } while (peso <= 0);
/*
   cout << "Grupo sanguíneo:         ";
   cin.flush();
   cin.getline(entrada, 255);
   AsignaDato(grupo_sanguineo, entrada);
*/
   cout << "--------------------------------------------------\n"
        << "||       INTRODUCCIÓN DE DATOS FINALIZADA       ||\n"
        << "--------------------------------------------------" << endl;
}


void Persona :: AsignaDato(char* &destino, const char* origen) {
   destino = new char[strlen(origen) + 1];
   strcpy(destino, origen);
}


void Persona :: AsignaDNI() {
   GeneradorAleatorioEnteros generador(0, 9);
   dni = new char[LONGDNI + 1];
   int dnint;

   for (int i = 0; i < strlen(dni); i++) {
      dni[i] = generador.Siguiente();
   }
}


void Persona :: LiberaMemoria() {
   EliminaDato(dni);
   EliminaDato(nombre);
   EliminaDato(apellidos);
   EliminaDato(mote);
   EliminaDato(pais_nacimiento);
   EliminaDato(ciudad_nacimiento);
   EliminaDato(pais_residencia);
   EliminaDato(ciudad_residencia);
}


void Persona :: EliminaDato(char *dato) {
   delete []dato;
}


char* Persona :: Dni() const {
   return dni;
}


char* Persona :: Nombre() const {
   cout << endl << "hola" << endl << endl;
   return nombre;
}


char* Persona :: Apellidos() const {
   return apellidos;
}


char* Persona :: Mote() const {
   return mote;
}


char* Persona :: Pais_Nacimiento() const {
   return pais_nacimiento;
}


char* Persona :: Ciudad_Nacimiento() const {
   return ciudad_nacimiento;
}


char* Persona :: Pais_Residencia() const {
   return pais_residencia;
}


char* Persona :: Ciudad_Residencia() const {
   return ciudad_residencia;
}


int Persona :: Edad() const {
   return edad;
}


double Persona :: Altura() const {
   return altura;
}


double Persona :: Peso() const {
   return peso;
}

/*
char* Persona :: Grupo_Sanguineo() {
   return grupo_sanguineo;
}
*/

Persona & Persona :: operator = (const Persona &otra) {

}


bool Persona :: operator == (const Persona &otra) const {
   return Dni() == otra.Dni();
}


bool Persona :: operator != (const Persona &otra) const {
   return !(*this == otra);
}


bool Persona :: operator < (const Persona &otra) const {
   return Edad() < otra.Edad();
}


bool Persona :: operator > (const Persona &otra) const {
   return Edad() < otra.Edad();
}


bool Persona :: operator <= (const Persona &otra) const {
   return !(*this > otra);
}


bool Persona :: operator >= (const Persona &otra) const {
   return !(*this < otra);
}


ostream & operator << (ostream &os, const Persona &p) {

   if (!p.EstaVacio()) {
      int espacios_linea;

      os << "--------------------------------------------------" << endl
         << "||  =CARTILLA DE IDENTIFICACIÓN DE CIUDADANOS=  ||" << endl
         << "||                                              ||" << endl;

      os << "|| " << p.nombre << " " << p.apellidos;
      if (p.mote) os << " \"" << p.mote << "\"";
      os << ":";

      espacios_linea = strlen(p.nombre) + strlen(p.apellidos);
      if (p.mote) espacios_linea += strlen(p.mote) + 3;
      for (int i = 0; i < 50 - 7 - espacios_linea; i++) os << " ";

      /*<< "DNI: " << p.dni << endl */

      os << "||" << endl
         << "||                                              ||" << endl
         << "|| Lugar de nacimiento: " << p.ciudad_nacimiento << ", "
         << p.pais_nacimiento;

      espacios_linea = strlen(p.ciudad_nacimiento) + strlen(p.pais_nacimiento);
      for (int i = 0; i < 50 - 28 - espacios_linea; i++) os << " ";

      os << "||" << endl << "|| Lugar de residencia: " << p.ciudad_residencia
      << ", " << p.pais_residencia;

      espacios_linea = strlen(p.ciudad_residencia) + strlen(p.pais_residencia);
      for (int i = 0; i < 50 - 28 - espacios_linea; i++) os << " ";

      os << "||" << endl
         << "||                                  Edad: "
         << setw(5) << p.edad << " ||" << endl
         << "||                                Altura: "
         << setw(5) << p.altura << " ||" << endl
         << "||                                  Peso: "
         << setw(5) << p.peso << " ||" << endl
         << "--------------------------------------------------" << endl;
   }

   return os;
}


istream & operator >> (istream &is, Persona &p) {

}


bool Persona :: EstaVacio() const {
   return !(nombre);
}
