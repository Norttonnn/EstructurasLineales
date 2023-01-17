#include <iostream>
using namespace std;


// ESTRUCTURAD DE DATOS
struct Direccion {
    string calle;
    int numero;
};

struct Persona {
    string nombre;
    int edad;
    Direccion direccion;
};



// PROTOTIPO DE FUNCIONES
void pedirDatos();

int main () {

Direccion d1{"Arboleda", 45};

Persona p1{"Alberto", 24, {"Hospital de San jose", 32}};
Persona p2{"Juanchotagorda", 32, {"",32}};
Persona p3{"Ana Bobueles", 25, d1};



cout << p1.nombre << " " << p1.edad << endl;
cout << "\tCalle: " << p1.direccion.calle << endl;
cout << "\tNumero:  " << p1.direccion.numero << endl;

cout << endl;

cout << p2.nombre << " " << p2.edad << endl;
cout << "\tCalle: " << p2.direccion.calle << endl;
cout << "\tNumero:  " << p2.direccion.numero << endl;

cout << endl;

cout << p3.nombre << " " << p3.edad << endl;
cout << "\tCalle: " << p3.direccion.calle << endl;
cout << "\tNumero:  " << p3.direccion.numero << endl;



    return 0;
}

