#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include<fstream>
#include <ctime>
#include <stdio.h>

using namespace std;

/*Ejercicios 02:
Se desea capturar los datos de los clientes para ser impreso en la factura. Se requiere 
crear una estructura de datos, que encapsule los datos de los usuarios. Se requiere que 
el uso de la estructura sea a través de punteros. Se requiere imprimir las facturas en 
un fichero de texto. 
Recomendaciones: 
1.- Hacer funciones por separado
2.- Anunciar/Documentar acciones
3.- Identificar su fichero fuente .cpp
4.- Subir el fichero fuente a un repositorio*/
// se crea una estructura para guardar los datos
struct cliente{
        string nombre;
        int cedula;
        int edad;
        string sexo;
        int telefono;
        string correo;
        int movil;
        string direccion;
};

//ptototipo de funciones
void llenar_datos(struct cliente *, int cant);
void guare(cliente cliente1[], int cant);
void presentar_datos(struct cliente *, int cant);
int menu();

//funcion principal

int main() {
  int op, cant,op1,p;
  
  cout << "Por favor ingrese la cantidad de clientes \n";
  cin>>cant;
struct cliente std[cant];
  do{
    //menu de opciones
  op = menu();
  switch(op){
    case 0:
       
      
      llenar_datos(std,cant);
        
    break;
    case 1:
      guare(std,cant);
      // guardar datos
    break;
    case 2:
      presentar_datos(std,cant);
    break;
    
    default:
    cout<<"valor ingresdo no valido";
    break;

    };
    
    }while(op!=3);
  }
        
int menu(){
  //funcion del menu
  int a=-1;
 
  cout<<"0. llenar los datos del cliente \n";
  cout<<"1. guardar los datos de los clientes \n";
  cout<<"2.mostrar los datos de  los clientes \n";
  cout<<"3. salir del programa \n";
  cin>>a;
  return a;
};
void llenar_datos(struct cliente *ptr, int cant){
  // funcion para llenar datos usando apuntadores
  int a;
  for(int i=0;i<cant;i++){
  fflush(stdin);
  fflush(stdin); 
  cout<<"Por favor ingrese el nombre de la persona\n";
  cin>>ptr->nombre;
    fflush(stdin);
  cout<<"Por favor ingrese la cedula de la persona\n";
  cin>>ptr->cedula;
    fflush(stdin);
  cout<<"Por favor ingrese el sexo de la persona\n";
  cin>>ptr->sexo;
    fflush(stdin);
  cout<<"Por favor ingrese el telefono de la persona\n";
  cin>>ptr->telefono;
    fflush(stdin);
  cout<<"Por favor ingrese el correo de la persona\n";
  cin>>ptr->correo;
    fflush(stdin);
  cout<<"Por favor ingrese la direccion de la persona\n";
  cin>>ptr->direccion;
    fflush(stdin);
  cout<<"se ha registrado con exito la persona "<<i+1<<" \n";
  cout<<ptr->nombre<<"\n";
    fflush(stdin);
    cout<<"si desea finalizar marque 0";
    cin>>a;
    
    if (a==0)
      i=cant;
      }
  ptr++;
};
void guare(cliente cliente1[], int cant){
// creacion archivo de texto y gurda de informacion
  ofstream f("archivo.txt");
 if(f.is_open()){
     for(int i=0;i<cant;i++)
       f.write((char*)&cliente1[i],sizeof(cant));
       cout<<"datos de los clientes guardados exitosamente"<<endl;
        f.close();
 }
 else cout<<"Ha ocurrido un error en la apertura del archivo."<<endl;
  
  
};
void presentar_datos(struct cliente *ptr, int cant){
  //impresion de datos en pantallad del arreglo
  for(int i=0;i<cant;i++){
  cout<<"los datos del usuraio "<<i+1<<" son : \n";
  cout<<"\n el nombre es"<<ptr->nombre;
  cout<<"'n la cedula es'"<<ptr->cedula;
  cout<<"\n el sexo es"<<ptr->sexo;
  cout<<"\n el telefono es"<<ptr->telefono;
  cout<<"\n el correo es"<<ptr->correo;
  cout<<"\n la direccion es "<<ptr->direccion;
    }
  ptr++;
};
