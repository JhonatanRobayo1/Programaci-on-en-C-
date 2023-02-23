#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


struct resultados{
int max_valor;
int size_array;
int *int_array;
};
//Prototipo funciones 
resultados generarVectorAleatorio(int r[], int i);
void generarHistograma(resultados arg_generar);
int menu();
//Función principal
int main(){
//declaración de variables
resultados valores_principal; //valores a pasar entre func.
int op, i, j,k;
  cout<<"Ingrese una cantidad \n";
  cin>>i;
do{  
//cuerpo del programa


int re[i];
op = menu();
switch(op){
case 0:
 valores_principal = generarVectorAleatorio(re,i);
 cout << "\nMax:" << valores_principal.max_valor << endl;
 cout << "Size: "<< valores_principal.size_array << endl;
 break;
case 1:
 generarHistograma(valores_principal);
 break;
case 2: //Salir_del_Programa
 break;
default:
 //Opción de reserva en caso de entrada de datos errónea
 cout <<"Ingrese opción valida"<<endl;
 break;
}}while(op!=2);
return 0;

}
//funcion de valores aleatorios
resultados generarVectorAleatorio(int r[], int n){
  int max=0;
  for(int c=0;c<n;c++){
    r[c]=rand() %20;    
  }
  //Funcion resultados
  struct resultados resultado1;
  // encontrar el mayor valor
  for(int c=0;c<n;c++){
   if(max<r[c])
     max=r[c];
    }
  for(int ri=0;ri<n;ri++){
    cout<<" "<<r[ri]<<" ";
  }
  //asignar valores al la estrcutura
  resultado1.size_array=n;
  resultado1.max_valor=max;
  resultado1.int_array=r;  //son el mismo tipo de dato con el apuntador
  return resultado1;
  
}
void generarHistograma(resultados arg_generar){
  int m [arg_generar.size_array];
  int ptr=arg_generar.size_array,as,b,cont1=0;
  int val[arg_generar.size_array];
  
  // sacar los valores unicos
  for(int a=0; a<ptr; a++){
    b=arg_generar.int_array[a]; //como el apuntador es el mismo arreglo se puede tratar como el vector    
  for(int j=0;j<ptr;j++){ // se debe sacar los valores unicos
    int temp=arg_generar.int_array[j];
        if(b==temp){
          if(j==a){
            // se necesita sacar lacantidad de valores unicos que hay en el array
            val[cont1]=b;
            cont1++;}
            else{j=ptr;}          
          }
      }
  }// se mira cuantas veces se repite y se guarda en un vector
  int repeticion[cont1];
  
  for(int t=0;t<cont1;t++){
      repeticion[t]=0;    
  }
  
  for(int j=0;j<cont1;j++){ // se debe contar cuantas veces se repite
        as=val[j];
    for(int a=0; a<ptr; a++){
      int temp=arg_generar.int_array[a];
         if(as==temp){
          repeticion[j]++; 
         } 
        }
      }
  // Se imprime las repeticiones
  cout<<setw(5)<<"Posicion"<<setw(5)<<"Numero"<<setw(5)<<"repeticion\n";
  for(int t=0;t<cont1;t++){
  cout<<setw(5)<<t<<setw(5)<<val[t]<<setw(5)<<repeticion[t]<<"\n";
}
  
  
};
//creacion funcion menu
int menu(){
  int a=-1;
 
  cout<<"0. crear vector aleatorio con numeros del 1 al 20 \n";
  cout<<"1. generar matriz de histograma \n";
  cout<<"2. salir del programa \n";
  cin>>a;
  return a;
};