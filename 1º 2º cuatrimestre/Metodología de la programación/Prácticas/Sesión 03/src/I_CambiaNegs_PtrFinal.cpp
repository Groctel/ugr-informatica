/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: I_CambiaNegs_PtrFinal.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include <random>  // Necesario para la clase GeneradorAleatorioEnteros
#include <chrono>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{
private:

   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   /************************************************************************/
   long long Nanosec(){
      return (chrono::high_resolution_clock::now().
              time_since_epoch().count());
   }
   /************************************************************************/

public:

   /************************************************************************/
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }

   /************************************************************************/
   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006

      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }

   /************************************************************************/
   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
   /************************************************************************/
};
/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
// Muestra el contenido de un vector, con los datos alineados
// Recibe:
// 		p, direcci�n de memoria del inicio el vector
//		num_datos, n�mero de casillas ocupadas del vector
//		num_datos_linea, n�mero de valores que se muestran en  cada l�nea

void MuestraVector (int *p, int num_datos, int num_datos_linea)
{

	int *p_end = p+num_datos; // Apuntar a la casilla siguiente a la ultima
	int *actual = p;	// Apuntar al inicio del vector

	int cont = 0; // Contador de datos mosttrados

	while (actual < p_end) {

		int pos = p_end-p;

		char separador = (((cont+1)%num_datos_linea)==0) ? '\n':' ';

		cout <<setw(4)<< *actual << separador;

		actual++;
		cont++;
	}
}

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int TOPE = 1000;			// Num. de casillas del vector
	const int MAX_LINE = 10;		// Num. maximo de enteros por linea

	int v[TOPE];

	GeneradorAleatorioEnteros generador (-50, 50);


	// Iniciar el vector aleatoriamente
	for (int i=0; i<TOPE; i++)
      v[i] = generador.Siguiente();

	// Mostrar el vector original
	cout << "Vector original: " << endl;
	MuestraVector (v, TOPE, MAX_LINE);

	int *p;		 // puntero para acceder a las componentes del vector
	int *p_end;  // puntero al final del vector

	p_end = v+TOPE; // Apuntar a la casilla siguiente a la ultima
	p = v; // Apuntar a la casilla 0

	while (p < p_end) {
		if (*p < 0) *p = -(*p); // Cambiar a valor positivo
		p++;
	}


	// Mostrar el vector modificado
	cout << "Vector modificado: " << endl;
	MuestraVector (v, TOPE, MAX_LINE);

	return (0);
}

/*********************************************************************/
/*********************************************************************/
