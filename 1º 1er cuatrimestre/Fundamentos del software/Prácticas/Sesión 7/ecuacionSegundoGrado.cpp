/*Este programa resuelve ecuaciones de segundo grado usando
una funcion denominada ecuacionator*/

#include <iostream>
#include <math.h>

using namespace std;

float discrim;	/*El discriminante es el numero que queda dentro de la raiz */

/*La funcion ecuacionator devuelve 0 si laa ecuacion no tiene solucion*/
float ecuacionator(float a, float b, float c)
{	
	discrim=((b*b)-(4*a*c));
	if (discrim<0) return 0;
	else return discrim;
}
		
int main ()
{
	float a=0, b=0, c=0;
	cout << endl << "Vamos a resolver una ecuacion del tipo ax2+bx+c=0" << endl;
	cout << endl << "Introduce el valor de a: ";
	cin >> a ;
	cout << endl << "Introduce el valor de b: ";
	cin >> b ;
	cout << endl << "Introduce el valor de c: ";
	cin >> c ;
	if (ecuacionator(a, b, c)<0)
		cout << endl << "La ecuacion no tiene solucion" << endl << endl ;
	else
	{
		float num1, num2; 		/*Los dos numeradores*/
		float den;			/*El denominador*/
		float solucion1, solucion2;	/*Las 2 soluciones*/	
		
		num1= (-b + sqrt(discrim));
		num2= (-b - sqrt(discrim));
		
		den=2*a;
				
		solucion1=num1/den;
		solucion2=num2/den;
		
		cout << endl << "La primera solucion es: " << solucion1 ;
		cout << endl << "La segunda solucion es: " << solucion2 ;
                cout << endl ;
	}
	return 0;	
}

/*
Con este ejemplo se puede comprobar que funciona:

Introduce el valor de a: 2

Introduce el valor de b: 8

Introduce el valor de c: 1

La primera solucion es: -0.129171
La segunda solucion es: -3.870829
-------------------------------------------------------
Con los siguientes valores no funciona el programa:
Introduce el valor de a: 32

Introduce el valor de b: 24

Introduce el valor de c: 11

La primera solucion es: -nan
La segunda solucion es: -nan

Aqui deberia indicar que "La ecuacion no tiene solucion" y, sin embargo, no lo hace
*/

