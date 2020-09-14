#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int BusquedaBinaria(double *v, int posini, int posfin, double aBuscar) {

   int centro= (posini+posfin)/2;
   if (posini>posfin) return -1;
   else if (v[centro] == aBuscar) return centro;
   else if (aBuscar < v[centro])
      return BusquedaBinaria(v, posini, centro-1, aBuscar);
   else
      return BusquedaBinaria(v, centro+1, posfin, aBuscar);
}




void Burbuja(double *v, int posini, int posfin) {

    int i, j;
    double aux;
    bool haycambios= true;

    i= posini;
    while (haycambios) {

        haycambios=false; // Suponemos vector ya ordenado

        // Recorremos vector de final a i
        for (j= posfin; j>i; j--) {

            // Dos elementos consecutivos mal ordenados
            if (v[j-1]>v[j]) {
                aux= v[j]; // Los intercambiamos
                v[j]= v[j-1];
                v[j-1]= aux;

                // Al intercambiar, hay cambio
                haycambios= true;
            }
        }

        i++;
	}
}


int main()
{
    const int MAX= 100;
    double vect[MAX];
    int num;
    double aBuscar;
    int idx;

    srand(time(NULL));

    do {
        cout<<"Dime un número entre 10 y 100: ";
        cin>>num;
    } while (num<10 || num>100);



    for (int i= 0; i<num; i++)
        vect[i]= rand()%num;

    Burbuja(vect, 0, num-1);

    cout<<"Dime el número a buscar: ";
    cin>>aBuscar;

    idx= BusquedaBinaria(vect, 0, num-1, aBuscar);
    if (idx<0)
        cout<<"No se encuentra en el vector\n";
    else
        cout<<"Se encuentra en la posición "<<idx<<endl;

    cout<<endl;
    for (int i= 0; i<num; i++) {
        cout<<i<<" "<<vect[i]<<endl;
    }

    return 0;
}
