// 01 - DESCRIBIR LA SALIDA DE LOS SIGUIENTES PROGRAMAS

/* PROGRAMA 1 

#include <iostream>
using namespace std;

int main() {
   int a = 5, *p;

   a = *p * a;
   if (a == *p)
      cout << "a es igual a *p" << endl;
   else
      cout << "a es diferente a *p" << endl;
   
   return 0;
}

// Este programa no hace nada porque el vector está inicializado en la dirección
   nula 0. Al intentar multiplicar algo por un dato que no está en ninguna
   dirección de memoria se produce un error de segmentación y se cierra.
*/

/* PROGRAMA 2

#include <iostream>
using namespace std;

int main() {
   int a = 5, *p;

   *p = *p * a;
   if (a == *p)
      cout << "a es igual a *p" << endl;
   else
      cout << "a es diferente a *p" << endl;
   
   return 0;
}

// Este programa no hace nada porque se le asigna al vector una dirección basada
   en el producto de a = 5 y *p = 0, por tanto la dirección a la que apunta el
   vector sigue siendo nula y se produce un error de segmentación.
*/

/* PROGRAMA 3

#include <iostream>
using namespace std;

int main() {
   int a = 5, *p = &a;

   *p = *p * a;
   if (a == *p)
      cout << "a es igual a *p" << endl;
   else
      cout << "a es diferente a *p" << endl;
   
   return 0;
}

// Se da que "a es igual a *p" ya que al modificar *p, que apunta a a, se
   modifica a colateralmente. Por tanto, cualquier modificación que se haga a *p
   tomando como variación de su valor únicamente el valor de a va a dar siempre
   esta salida.
*/

/* PROGRAMA 3

#include <iostream>
using namespace std;

int main() {
   int a = 5, *p = &a, **p2 = &p;

   **p2 = *p + (**p2 / a);
   *p = a + 1;
   a = **p2 / 2;

   cout << "a es igual a " << a << endl;
   
   return 0;
}

// En la asignación se tiene que a = 5, *p -> a = 5 y **p2 -> *p -> a = 5. La
   primera operación opera con (**p2 / a), que es 5 / 5 = 1. Por tanto se toma
   **p2 / a y se tiene que **p2 = **p2 / a = 1. El resto de operaciones sólo
   toman el valor de a a partir de *p y **p2 y le suman 1 dos veces, por lo que
   da como resultado 3.
*/