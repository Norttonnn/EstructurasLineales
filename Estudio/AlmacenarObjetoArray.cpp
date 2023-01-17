#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string, int);
    Persona();
    
    ~Persona();

    void Mostrar();
};

Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

Persona::Persona() {}

Persona::~Persona() {
    cout << "El objeto ha sido eliminado" << endl;
}

void Persona::Mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad " << edad << endl;
}


int main() {

    Persona p1("Alberto", 24);
    Persona p2("Marta", 22);

    Persona arreglo[2];
    arreglo[0] = p1;
    arreglo[1] = p2;

    p1.Mostrar();
    p2.Mostrar();

    cout << endl;

    for (int i = 0; i < 2; i++) {
        arreglo[i].Mostrar();
    }
    
    return 0;
}