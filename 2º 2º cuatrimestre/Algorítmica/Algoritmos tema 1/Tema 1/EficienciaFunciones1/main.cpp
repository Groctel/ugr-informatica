#include <iostream>
#include<cmath>
using namespace std;


bool esPrimo(int valor) {

    double tope= sqrt(valor);
    for (int i= 2; i<=tope; i++) {

        if (valor%i == 0)
            return false;
    }

    return true;
}


int main()
{

    int n;

    cout<<"Dime un número: ";
    cin>>n;

    for (int i= 1; i<n; i++)
        if (esPrimo(i))
            cout<<i;

    for (int i= 1; i<n; i++)
        if (esPrimo(1234567))
            cout<<i;

    for (int i= 1; i<2000; i++)
        if (esPrimo(i))
            cout<<i;

    for (int i= n; i>0; i/=2)
        if (esPrimo(i))
            cout<<i;


    return 0;
}
