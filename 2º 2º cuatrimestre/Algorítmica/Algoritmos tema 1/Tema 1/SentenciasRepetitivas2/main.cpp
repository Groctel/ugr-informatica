#include <iostream>

using namespace std;

int main()
{
    int n;

    cout<<"Dime un número: ";
    cin>>n;

    while (n>0) {
        for (int i= 1; i<=n; i*=2)
            cout<<i;
        n--;
    }

    return 0;
}
