/*
Un videoclub solicita a vuestra empresa realizar un proyecto por el cual, se puedan 
cargar nuevos discos en el sistema de alquileres. Para ello, es necesario almacenar 
la información correspondiente al titulo de la película, el precio del alquiler y si es 
un  DVD,  o  un  blu-ray.  El  sistema  además  tendrá  que  indicar  si  el  disco  está  o  no  
alquilado. 
Este  sistema  debe  permitir  buscar  los  discos  mediante  su  título.  Si  un  título  está  
alquilado,  no  estará  disponible  su  información,  pero  si  no  lo  está  se  mostrará  al  
usuario en pantalla.  
También  debe  haber  una  opción  de  alquilar,  que  cambie  el  estado  de  un  no  
alquilado  a  alquilado,  y  un  sistema  de  devolución,  que  cambie  el  estado  de  
alquilado a no alquilado.  

Título - Precio - (DVD | BLU-RAY - ¿Alquilado?)

Búsqueda por título. Si no está disponible no aparece y se dirá. 

Sistema de alguilado y devolución.


*/

#include<iostream>
#include<vector>

using namespace std;

struct Disco {
    string titulo;
    int precio;
    bool alquiler;
    string tipo;
};

vector<Disco> discos;

// DECLARACIÓN DE FUNCIONES
void Menu();
void Mostrar();
void BusquedaTitulo();
void CompruebaDispo();




int main() {

    // Menu();

    discos.push_back({"Avatar", 10, true, "DVD"});
    discos.push_back({"Titulo disco 2", 15, false, "Blu-ray"});
    discos.push_back({"Titulo disco 3", 20, false, "DVD"});

    Mostrar();
    BusquedaTitulo();
    CompruebaDispo();

    
    
    




    return 0;
}

void Menu() {
    cout << "(1) - Mostrar contenido total" << endl;
    cout << "(2) - Añadir disco"            << endl;
    cout << "(3) - Alquilar película"       << endl;
    cout << "(4) - Devolver película"       << endl;
    cout << "(5) - Salir"                   << endl;
}

void Mostrar() {
    for (int i = 0; i < discos.size(); i++) {
            cout << "Título: " << discos[i].titulo << endl;
            cout << "Precio: " << discos[i].precio << endl;
            cout << "Disponibilidad: " << discos[i].alquiler << endl;
            cout << "Formato: " << discos[i].tipo << endl;

            cout << endl;
        }
}

void BusquedaTitulo() {
    cout << "Introduce el título que desees: ";   string compruebaTitulo;   cin >> compruebaTitulo;
    for (int i = 0; i < discos.size(); i++) {
           if(compruebaTitulo == discos[i].titulo) {
            cout << "BÚSQUEDA EXITOSA!" << endl;
            cout << "Precio: " << discos[i].precio << endl;
            cout << "Disponibilidad: " << discos[i].alquiler << endl;
            cout << "Formato: " << discos[i].tipo << endl;

            i = discos.size()+1;
           } else {
            cout << "Libro no encontrado";
            i = discos.size()+1;
           }

            cout << endl;
        }
}

void CompruebaDispo() {
    cout << "Introduce el título que desees: ";   string compruebaTitulo;   cin >> compruebaTitulo;
    for (int i = 0; i < discos.size(); i++) {
           if((compruebaTitulo == discos[i].titulo) && discos[i].alquiler == 1) {
            cout << "Esta disponible"; 
            i = discos.size()+1;
           } else {
            cout << "No dispo";
            i = discos.size()+1;
           }

            cout << endl;
        }

}