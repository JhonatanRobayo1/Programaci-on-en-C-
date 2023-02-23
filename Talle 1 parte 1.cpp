#include <iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int alea();
int main() {
cout << "Hello World!\n";
// se inicializa el vector con 10 componentes
vector<int> vector1 ={1,2,3,4,5,6,7,8,9,10};
  // se inicializa en iterador
vector<int>::iterator a;
  int b;
// se crea un bucle para llenar los espacios del vector con numeros aleatorios del 0 al 25
  for(a=vector1.begin();a<vector1.end();a++){
    *a=rand() %26;
    }
//se muestran los valores de a y sus direcciones
    for(a=vector1.begin();a<vector1.end();a++){
    cout<<" "<< *a;
  cout<<" "<< &a;
    }


}
/*Ejercicio 01:
1.- Crear un array con 10 elementos
2.- Crear una función para generar números aleatorios entre 0 y 25
3.- Llenar el array con 10 números aleatorios
4.- Crear un puntero
5.- Imprimir el contenido del array usando el puntero
6.- Imprimir las direcciones del contenido del array usando el puntero.
*/




