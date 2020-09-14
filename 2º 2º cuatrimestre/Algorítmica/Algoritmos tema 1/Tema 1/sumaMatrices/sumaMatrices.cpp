// Ejemplo de la suma de matrices reales
#include <iostream>
#include <cstdlib> // Para usar srand y rand
#include <cstdlib> // Para usar clock
#include <fstream> // Para usar ficheros
using namespace std;

void SumaMatrices(double **A, double **B, double **C, int filas, int columnas);


int main(int argc, char *argv[]) {
  
  double **A, **B, **C; // Matrices a sumar
  int n, m, i, j, argumento, argumento2;
  unsigned long int tini, tfin; // Tiempos de ejecucion inicial y final
  unsigned long int tejecucion; // tiempo de ejecucion del algoritmo
  ofstream fsalida;

  if (argc <= 2) {
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
        cerr<<argv[0]<<" NombreFicheroSalida tamCaso1 tamCaso2 ... tamCasoN\n\n";
        return 0;
  }

  // Abrimos fichero de salida 
  fsalida.open(argv[1]);
  if (!fsalida.is_open()) {
        cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
        return 0;
  }

  // Inicializamos generador de no. aleatorios
  srand(time(NULL));
  
  // Pasamos por cada tamaño de caso
  for (argumento= 2; argumento<argc; argumento++) {
  	for (argumento2= 2; argumento2<argc; argumento2++) {    
      
      // Cogemos el tamanio del caso
      n= atoi(argv[argumento]);
      m= atoi(argv[argumento2]);
      
      // Reservamos memoria para las matrices
      A= new double *[n];
      B= new double *[n];
      C= new double *[n];
      for (i= 0; i<n; i++) {
      	A[i]= new double[m];
      	B[i]= new double[m];
      	C[i]= new double[m];
      }
      
      // Generamos matrices A y B aleatorio de prueba, con componentes entre 0 y 1
      for (i= 0; i<n; i++)
        for (j= 0; j<m; j++) {
          A[i][j]= rand()/RAND_MAX;
          B[i][j]= rand()/RAND_MAX;
        }

      tini= clock(); // Cogemos el tiempo en que comienza la ejecución del algoritmo
      SumaMatrices(A, B, C, n, m); // Ejecutamos el algoritmo para tamaño de caso tam
      tfin= clock(); // Cogemos el tiempo en que finaliza la ejecución del algoritmo

      tejecucion= tfin-tini;
      
      // Guardamos tam. de caso y t_ejecucion a fichero de salida
      fsalida<<n<<" "<<m<<" "<<tejecucion<<"\n";
      
      // Lo mostramos tambien por pantalla
      cerr<<"Tam. Caso: "<<n<<"*"<<m<<" T. Ejecucion: "<<tejecucion<<endl;

      // Liberamos memoria de las matrices
      for (i= 0; i<n; i++) {
      	delete [] A[i];
      	delete [] B[i];
      	delete [] C[i];
      }
      delete [] A;
      delete [] B;
      delete [] C;
    }
  }

  // Cerramos fichero de salida
  fsalida.close();  
  
  return 0;
}


void SumaMatrices(double **A, double **B, double **C, int filas, int columnas) {

	int i, j;
	
	for (i= 0; i<filas; i++)
		for (j= 0; j<columnas; j++)
			C[i][j]= A[i][j]+B[i][j];	
}
