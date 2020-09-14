#include <iostream>

using namespace std;

int main()
{

    int n;

    cout<<"Dime un número: ";
    cin>>n;


   if (n%2 == 1)
      cout<<"Es impar";
   else {
      for (int i= 1; i<=n; i++)
         cout<<i;
   }
}
