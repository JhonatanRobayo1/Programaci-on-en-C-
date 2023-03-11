#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iomanip>
/*
Cositas para el proyecto
*/
using namespace std;
//creacion estructura empleado
struct Empleado{
int codigo;
char nombre [50];
char apellidos [50];
string valor;
int numero;
};
// Nombramiento de Funciones
void mostrar_emp(vector<Empleado> v);
void anadir_empleado(vector<Empleado>& v);
bool registro_emp(vector<Empleado>& empleado);
bool cambiarNumero(vector<Empleado>& v);
void despedirEmpleado(vector<Empleado>& empleado, vector<Empleado>& desempleado);
void generarCartaDespido(const char* nombreArchivo, const char* nombreCompleto);
int menu();


/*

*/
// La función principal
int main() {
  int op;
   
// Declarando el vetor empleados y desempleados
    vector<Empleado> empleado;//
    vector<Empleado> desempleado;

  //llamado del menu y eleccion y ejecución de la opción
do{
  op=menu();
switch (op){
  case 1:
  anadir_empleado(empleado);
  break;
  case 2:
      if (registro_emp(empleado)){
    cout<<"Se ha hecho el registro con exito\n";
  }else
    cout<<"No se pudo realizar el registro \n";
   
    break;
  case 3:
  
  if (cambiarNumero(empleado)){
    cout<<"Se ha cambiado el numero con exito\n";
  }else
    cout<<"No se ha relizado ningun cambio\n";
  
    return 0;
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
  //se debe mostar el vector ya ordenado
  cout <<setw(5)<<"Nombre"<<setw(5)<< "Apellido"<< setw(5)<< "Codigo"<< setw(5)<< "Telefono"<< "          \n";
  for (auto& a : v) {

    cout << setw(5)<<a.nombre<<setw(5)<<a.apellidos << setw(5)<< a.codigo<< setw(5)<< a.numero<< "          \n";
  }
};
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
};

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
  }
  cout << "No se encontró al empleado con el código proporcionado.\n";
  return false; // No se encontró al empleado con el código proporcionado
}
void despedirEmpleado(vector<Empleado>& empleado, vector<Empleado>& desempleado) {
    int codigo;
    cout << "Por favor ingrese el codigo del empleado a despedir: ";
    cin >> codigo;

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
    }
    archivo << "Estimado(a) " << nombreCompleto << ", se le informa que ha sido despedido(a).\n Agradecemos su colaboración con la compañia y le deseamos existos en el futuro" << endl;
    archivo.close();
    cout << "Se ha generado la carta de despido en el archivo " << nombreArchivo << endl;
}
bool registro_emp(vector<Empleado>& empleado) {
        ofstream archivo("Empleados.bin", ios::binary);
    if (!archivo) {
        return false; // No se pudo abrir el archivo
    }
    int tam = empleado.size();
    archivo.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Guardar la cantidad de elementos en el vector
    archivo.write(reinterpret_cast<char*>(&empleado[0]), tam * sizeof(Empleado)); // Guardar el vector completo
    archivo.close();
    return true; // Se pudo realizar la operación
}

int menu(){
  int valor;
  cout<<"Bienvenido a la Plataforma de Manejo de Empleados, por favor ingrese la opción indicada \n 1. Agregar un Empleado Nuevo \n 2. Registrar Empleados en el Archivo \n 3. Cambiar Numero de Telefono de Algún Empleado \n 4.Mostrar los Empleados \n 5. Despedir un empleado \n 6.Mostrar Emplados Despedidos\n 0. Finalizar el programa\n";
  cin>>valor;
    return valor;
}
