/*
Autor: Jhonatan Robayo
Fecha: 10 de Marzo 2023
Tema:Proyecto Programación Avanzada
Objetivo:
Hacer un programa para la gestion de empleados, hacer uso de estructuras, se debe tener la funcion de añadir empleado, la de registrar que es la misma de guardar, la de despedir empleado y que se genere una carta de despido, donde se debe tener que generar un archivo de texto con la carta de despido, 
adicionalmente se debe ser capaz de guardar los datos en un archivo binario.
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#define C 4

using namespace std;
//creacion estructura empleado
struct Empleado{
int codigo;
char nombre [50];
char apellidos [50];
int numero;
};
// Nombramiento de Funciones, son varias a utilizar
void mostrar_emp(vector<Empleado> v);
void anadir_empleado(vector<Empleado>& v);
bool cambiarNumero(vector<Empleado>& v);
void despedirEmpleado(vector<Empleado>& empleado, vector<Empleado>& desempleado);
void guardar_empleados(vector<Empleado> v);
void guardar_desempleados(vector<Empleado> v);
void generarCartaDespido(const char* nombreArchivo, const char* nombreCompleto);
void cargar_empleados(vector<Empleado>& empleado);
void cargar_desempleados(vector<Empleado>& desempleado);
int menu();

// La función principal
int main() {
  int op;
   
  // Declarando el vetor empleados y desempleados, además cargandolos del archivo Bin
    vector<Empleado> empleado;
    cargar_empleados(empleado);
    vector<Empleado> desempleado;
    cargar_desempleados(desempleado);

  
  
do{   
  op=menu();
//Habiendo llamado previamente el menu se usa un swict case para generar el menu.
switch (op){
  case 0:
  cout << "gracias \n Hasta Luego" << endl;
  break;
  case 1://como su nombre indica en cada case se hace la tarea llamadno a la función
  anadir_empleado(empleado);
  break;
  case 2://guardar en el archivo bin a los empleados y desempleados
      guardar_empleados(empleado);
    break;
  case 3:  
  if (cambiarNumero(empleado)){
    cout<<"Se ha cambiado el numero con exito\n";
  }else
    cout<<"No se ha relizado ningun cambio\n";
    break;
  case 4:
    mostrar_emp(empleado);
    break;
  case 5:
  despedirEmpleado(empleado,desempleado);
  break;
  case 6:
  mostrar_emp(desempleado);
    break;
  default:
  cout<<"valor ingresado no valido\n";
 }
  }while (op!=0);
}


void mostrar_emp(vector<Empleado> v){
  //Se debe ordenar primero el vector por orden alfabetico para eso se debe usar la funcion sort pero tambien incluir la funcion strcmp
  sort(v.begin(), v.end(), [](const Empleado& a, const Empleado& b) {
    return strcmp(a.apellidos, b.apellidos) < 0;
  });
  //se debe mostar el vector ya ordenado usando setw con 50, por le posible tamaño de algun nombre que pueda ser muy largo
  cout <<setw(50)<<"Nombre"<<setw(50)<< "Apellido"<< setw(50)<< "Codigo"<< setw(50)<< "Telefono"<< "          \n";
  //Se comienza a mostar el vector y cada estructura
  for (auto& a : v) {

    cout << setw(50)<<a.nombre<<setw(50)<<a.apellidos << setw(50)<< a.codigo<< setw(50)<< a.numero<< "          \n";
  }
}
void anadir_empleado(vector<Empleado>& v){
  // se cre una estructura, se llena y luego se anade al vector
  fflush( stdin ); // para limpiar el buffer
  Empleado nuevo_empleado;
  cout << "Por favor Ingrese el codigo del Empleado \n ";
  fflush( stdin );
  cin >> nuevo_empleado.codigo;
  cout << "Por favor Ingrese el Nombre del Empleado \n";
   fflush( stdin );
  cin.ignore(); 
  cin.getline(nuevo_empleado.nombre, 50); // Leer la cadena de caracteres
  cout << "Por favor Ingrese los Apellidos del Empleado\n ";
   fflush( stdin );
  cin.getline(nuevo_empleado.apellidos, 50); 
  cout << "Por favor Ingrese el Numero de Telefono del Empleado\n";
  cin >> nuevo_empleado.numero;
  v.push_back(nuevo_empleado);
}

bool cambiarNumero(vector<Empleado>& v) {
  // debemos pedir el codigo para buscar al empleado
  int codigo, nuevoNumero;
  cout<<"Por favor ingrese el codigo del empleado\n";
  cin>>codigo;
  for (auto& empleado : v) {
    // se recorre el vector buscando al empleado
    if (empleado.codigo == codigo) {
      cout<<"Ingrese el Numero Nuevo\n";
      cin>>nuevoNumero;
      empleado.numero = nuevoNumero;
      return true; // Se pudo realizar el cambio
    }
  }//si no se encuentra el codigo en las estructuras se da aviso
  cout << "No se encontró al empleado con el código proporcionado.\n";
  return false; // No se encontró al empleado con el código proporcionado
}
void despedirEmpleado(vector<Empleado>& empleado, vector<Empleado>& desempleado) {
  //la idea fue la de crear un vector adicional para no perder la información
    int codigo;
    cout << "Por favor ingrese el codigo del empleado a despedir: ";
    cin >> codigo;
// se pide el codigo del empleaod a despedir
    for (auto it = empleado.begin(); it != empleado.end(); it++) {
        if (it->codigo == codigo) {
            Empleado emp = *it;// se hace una copia con el aputandor it
            empleado.erase(it);// se elimina del vector de empleados
            desempleado.push_back(emp);// se agrega al vector desempleados

            char nombreCompleto[100];
            snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s", emp.nombre, emp.apellidos);// se debe extrae el nombre completo para el archivo, usands snprintf se logra unir nombres y apellido en una sola variable tipo cha
            char nombreArchivo[100];
            snprintf(nombreArchivo, sizeof(nombreArchivo), "carta_despido_%s.txt", nombreCompleto);// usar snpritf para anadir mas palabras al dato tipo char
            generarCartaDespido(nombreArchivo, nombreCompleto);

            cout << "El empleado " << nombreCompleto << " ha sido despedido." << endl;
            return;
        }
    }

    cout << "No se encontró un empleado con el código " << codigo << "." << endl;
}
void generarCartaDespido(const char* nombreArchivo, const char* nombreCompleto) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }//se podria pedir mas información al usuario sobre la causa de despido
    archivo << "Estimado(a) " << nombreCompleto << ", se le informa que ha sido despedido(a).\n Agradecemos su colaboración con la compañia y le deseamos existos en el futuro" << endl;
    archivo.close();
    cout << "Se ha generado la carta de despido en el archivo " << nombreArchivo << endl;
}

// Generación del menu de entrada, se pide el valor para continuar en el programa
int menu(){
  int valor;
  cout<<"Bienvenido a la Plataforma de Manejo de Empleados, por favor ingrese la opción indicada \n 1. Agregar un Empleado Nuevo \n 2. Registrar Empleados en el Archivo \n 3. Cambiar Numero de Telefono de Algún Empleado \n 4.Mostrar los Empleados \n 5. Despedir un empleado \n 6.Mostrar Emplados Despedidos\n 0. Finalizar el programa\n ";
  cin>>valor;
    return valor;
}
void guardar_empleados(vector<Empleado> v) {
  ofstream file("empleados.bin", ios::binary | ios::trunc);
  if (file) {
    for (auto& empleado : v) {
      file.write(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
    }
    cout << "Los empleados se han guardado en el archivo empleados.bin\n";
  } else {
    cout << "No se pudo abrir el archivo empleados.bin para escritura.\n";
  }
  file.close();
}

void cargar_empleados(vector<Empleado>& empleado) {
  ifstream file("empleados.bin", ios::binary);
  if (file) {
    empleado.clear();
    Empleado empleado_leido;
    while (file.read(reinterpret_cast<char*>(&empleado_leido), sizeof(Empleado))) {
      empleado.push_back(empleado_leido);
    }
    cout << "Se han cargado " << empleado.size() << " empleados desde el archivo empleados.bin\n";
  } else {
    cout << "No se pudo abrir el archivo empleados.bin para lectura.\n";
  }
  file.close();
}

void guardar_desempleados(vector<Empleado> v) {
  ofstream file("desempleados.bin", ios::binary | ios::trunc);
  if (file) {
    for (auto& empleado : v) {
      file.write(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
    }
    cout << "Los desempleados se han guardado en el archivo desempleados.bin\n";
  } else {
    cout << "No se pudo abrir el archivo desempleados.bin para escritura.\n";
  }
  file.close();
}

void cargar_desempleados(vector<Empleado>& desempleado) {
  ifstream file("desempleados.bin", ios::binary);
  if (file) {
    desempleado.clear();
    Empleado empleado_leido;
    while (file.read(reinterpret_cast<char*>(&empleado_leido), sizeof(Empleado))) {
      desempleado.push_back(empleado_leido);
    }
    cout << "Se han cargado " << desempleado.size() << " desempleados desde el archivo desempleados.bin\n";
  } else {
    cout << "No se pudo abrir el archivo desempleados.bin para lectura.\n";
  }
  file.close();
}
