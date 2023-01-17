#include <iostream>
using namespace std;

class Persona {
    private: // DECLARACIÓN DE ATRIBUTOS
        string nombre;
        int edad;
    public: // DECLARACIÓN DE METODOS
        Persona(string, int);
        void Mostrar();
};

// ELABORACIÓN DE METODOS
Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::Mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad;
}



// MÉTODO MAIN
int main() {
    Persona p1("Alberto", 24);
    p1.Mostrar();

    return 0;
}