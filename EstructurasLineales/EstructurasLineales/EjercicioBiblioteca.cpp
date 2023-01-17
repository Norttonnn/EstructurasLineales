/*
B I B L I O T E C A
    - 3 libros (acción, aventuras, comedia...)
    - Tener control de los libros disponibles o no. Si no lo está, saber quien lo tiene
    - Usuario (ombre, apellido, dni, libro que tiene ahora, historial)

        **METODOS**
    - Comprobar libros disponibles
    - Historial de libros de una persona
    - Ver si una persona tiene un libro o no
    - Sacar / devolver libro
*/

// CLASES: USUARIO, LIBRO

#include<iostream>
using namespace std;

class Persona {
    private: // Atributos
        int edad;
        string nombre;
    public: // Métodos
        Persona(int, string);
        void leer();
        void correr();
}; // Por el planteamiento que hemos hecho, los únicos que pueden modificar los atributos son los métodos de este


class Libro {
    private: // Atributos
        string titulo;
        string genero;
        bool disponibilidad;
        string autor;
    public:
        Libro(string, string, string, bool);
        void verLibro();
        void verAutor();
        void verDispo();
        void verTitulo();
        void resumenDatos();
};

//Constructor de la clase libro
Libro::Libro(string titulo, string genero, string autor, bool disponibilidad) {
    this->titulo = titulo;
    this->genero = genero;
    this->autor = autor;
    this->disponibilidad = disponibilidad;
}

// Constructor. Nos sirve para inicializar los atributos de la clase
Persona::Persona(int _edad, string _nombre) {
    edad = _edad;
    nombre = _nombre;
}
// Metodo leer de la clase persona
void Persona::leer() {
    cout << "Soy " << nombre << " y estoy leyendo un libro" << endl;
}

//Metodo correr de la clase persona
void Persona::correr() {
    cout << "Soy " <<nombre << " y estoy corriendo una maratón. Tengo " << edad << " años" << endl;
}

int main () {
    //Constructor de libro es = TITUTLO / GENERO / AUTOR /DISPONIBILIDAD
    Libro L1 ("Crónicas marcianas", "Fantasía", "Don Luis", false);
    Libro L2 ("La sonsira Etrusca", "Historia", "Feliciana", false);
    Libro L3 ("El increible Spiderman", "Superheróes", "Alberto", true);


    Persona p1 = Persona(24, "Alberto");
    Persona p2(26, "María");
    Persona p3(21, "Juan");

    p1.leer();
    p2.correr();
    p3.leer();
    p3.correr();

    return 0;
}