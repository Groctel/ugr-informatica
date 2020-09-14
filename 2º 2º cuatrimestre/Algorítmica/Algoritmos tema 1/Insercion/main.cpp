#include <iostream>

using namespace std;

// Algoritmo para ordenar el vector v ascendentemente desde v[posini] hasta v[posfin]
void Insercion(double *v, int posini, int posfin) {

    double aux;
    int currentpos;

    for (int i= posini+1; i<=posfin; i++) {

        currentpos= i;
        while (currentpos>posini && v[currentpos]<v[currentpos-1]) {

            aux= v[currentpos];
            v[currentpos]= v[currentpos-1];
            v[currentpos-1]= aux;

            currentpos--;
        }
    }

}


int main()
{
    const int TAM= 10;
    double vect[TAM];

    for (int i= 0; i<TAM; i++) // Ejemplo: Vector al revés
        vect[i]= TAM-i;

    Insercion(vect, 0, TAM-1);

    for (int i= 0; i<TAM; i++)
        cout<<vect[i]<<" ";
    cout<<endl;

    return 0;
}
