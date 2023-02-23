#include <iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
//Crear una función con memoria dinámica que llene una matriz, cuya dimensión es pedida por consola. El llenado debe ser con valores aleatorios y la matriz debe ser matriz cuadrada (NxN). La matriz deberá ser almacenada en un fichero binario. Se recomienda hacer una función que permita la lectura de la matriz desde el fichero binario.
// inicializacion de funciones con punteros
void imprimirmatriz(int **matriz, int rows, int cols);
void llenarmatriz(int **matriz, int rows, int cols);
void guardar(int **matriz, int fil,int colu);
void cargar(int **matriz, int fil,int colu);

int main() {
  int a=0,colu=0,fil=0 ;
  cout<<"por favor ingrese la dimension de la matriz NxN";
  cin>>a;
  colu=fil=a;

  // creacion de la matriz con uso de apuntadores

  int** matriz = new int*[fil];
    for (int i = 0; i < fil; ++i)
        matriz[i] = new int[colu];
   llenarmatriz(matriz, fil, colu);   
 
  guardar(matriz, fil, colu);
  cargar(matriz, fil, colu);
  imprimirmatriz(matriz, fil, colu);
  
    return 0;
  
  

}
//funcion impresion de la matriz
void imprimirmatriz(int **matriz, int fil, int colu){
    for(int i=0;i< fil;i++){
        for(int j=0;j< colu;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
}
// funcion llenado de la matriz
void llenarmatriz(int **matriz, int fil, int colu){
    
    for(int i=0;i<fil;i++){
        for(int j=0;j<colu;j++){
            matriz[i][j]=rand()%99+1;
        }
    }
}
//Funcion para guardar en un archivo bin
void guardar(int **matriz, int fil, int colu){
  FILE *file = fopen("archivo", "wb"); 
for (int i=0; i<fil; ++i) {
            
    fwrite(matriz[i], sizeof(long double), colu, file); 
  }
fclose(file);

}
// funcion para cargar el archivo bin
void cargar(int **matriz, int fil, int colu){
 FILE *file = fopen("archivo", "rb");
for (int i=0; i<fil; ++i)  
    fread(matriz[i], sizeof(long double), colu, file); 
    fclose(file);
}