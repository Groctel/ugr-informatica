#include <iostream>
#include <cstring>

using namespace std;



void fusionaMS(double *v, int posIni, int centro, int posFin, double *vaux) {

    int i= posIni;
    int j= centro;
    int k= 0;

    while (i<centro && j<=posFin) {


        if (v[i]<=v[j]) {
            vaux[k]= v[i];
            i++;
        } else {
            vaux[k]= v[j];
            j++;
        }
        k++;
    }

    while (i<centro) {
        vaux[k]= v[i];
        i++, k++;
    }
    while (j<=posFin) {
        vaux[k]= v[j];
        j++, k++;
    }

    memcpy(v+posIni, vaux, k*sizeof(double));
}


void MergeSort(double *v, int posIni, int posFin, double *vaux) {

    if (posIni>=posFin) return;

    int centro= (posIni+posFin)/2;

    MergeSort(v, posIni, centro, vaux);
    MergeSort(v, centro+1, posFin, vaux);
    fusionaMS(v, posIni, centro+1, posFin, vaux);
}



int main()
{
    const int SIZE= 10000;
    double vect[SIZE];
    double vaux[SIZE];
    unsigned long tini, tfin;

    for (int TAM= 1000; TAM<=SIZE; TAM+= 1000) {

        // Ejemplo: Vector al revés
        for (int i= 0; i<TAM; i++)
            vect[i]= TAM-i;

        tini= clock(); // Tiempo inicial
        MergeSort(vect, 0, TAM-1, vaux);
        tfin= clock(); // Tiempo final

        cout<<"N: "<<TAM<<" T (ms.): "<<1000.0*(tfin-tini)/(double)CLOCKS_PER_SEC<<endl;
    }

    return 0;
}
