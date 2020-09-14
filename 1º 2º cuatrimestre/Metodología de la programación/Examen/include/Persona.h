#ifndef PERSONA
#define PERSONA

#include <iostream>

using namespace std;



class Persona {
private:
   const int LONGDNI = 9;
   const char LETRADNI[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D',
                              'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L',
                              'C', 'K', 'E'};
   //enum GrupoSanguineo {cn, cp, an, ap, bn, bp, abn, abp};

   char* dni;

   char* nombre;
   char* apellidos;
   char* mote;

   char* pais_nacimiento;
   char* ciudad_nacimiento;
   char* pais_residencia;
   char* ciudad_residencia;

   int edad;
   double altura;
   double peso;
   //GrupoSanguineo grupo_sanguineo;

   void Creador();
   void AsignaDNI();
   void AsignaDato(char*  &destino , const char* origen);
   void CopiaDatos(const Persona &otra);
   void LiberaMemoria();
   void EliminaDato(char* dato);

public:
   Persona();
   Persona(char* dni);
   Persona(const Persona &otra);

   char*  Dni() const;
   char*  Nombre() const;
   char*  Apellidos() const;
   char*  Mote() const;
   char*  Pais_Nacimiento() const;
   char*  Pais_Residencia() const;
   char*  Ciudad_Nacimiento() const;
   char*  Ciudad_Residencia() const;
   int Edad() const;
   double Altura() const;
   double Peso() const;
   //GrupoSanguineo Grupo_Sanguineo();

   Persona & operator = (const Persona &otra);
   bool operator == (const Persona &otra) const;
   bool operator != (const Persona &otra) const;
   bool operator < (const Persona &otra) const;
   bool operator > (const Persona &otra) const;
   bool operator <= (const Persona &otra) const;
   bool operator >= (const Persona &otra) const;
   friend ostream & operator << (ostream &os, const Persona &p);
	friend istream & operator >> (istream &is, Persona &p);

   bool EstaVacio() const;
};

#endif
