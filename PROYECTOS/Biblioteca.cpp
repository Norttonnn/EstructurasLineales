/*
• Nombre, apellidos, DNI....
• Libro que tiene ahora
Historial...
*/

/*
Todo ese software pretende facilitarle la vida a los bibliotecarios que hacen las
gestiones de reservas de libros y les tiene que permitir realizar las siguientes acciones:
• Comprobar qué libros hay disponibles [V]
• Ver el historial de libros de una persona [V]
• Ver si una persona tiene un libro o no [V]
• Sacar un libro (asignárselo a una persona)
• Devolver un libro (desasignárselo a dicha persona)
*/

#include<iostream>
#include<list>

using namespace std;


struct Usuario {
    string nombre;
    int edad;
    string historial [4];
}user[3];

// Estructuras de datos
struct Libro {
    string titulo;
    string autor;
    string genero;
    bool dispo;
    struct Usuario nombreUsuario;
}libro[4];


// DECLARACIÓN DE FUNCIONES
void mostrarLibrosDisponibles();
void mostrarHistorialLibros();
void mostrarUsuarios();
void mostrarLibroActual();
void mostrarHistorialPersona(Usuario);
void comprobarLibro(Libro);





int main() {

// CREAMOS USUARIOS
user[0] = {"Ana Bobueles", 29,{"El barco", "El internado"}};
user[1] = {"Jaunchota Gorda", 32};
user[2] = {"Vergota Larga", 24, {"El internado"}};

// CREAMOS LIBROS
libro[0] = {"Los hombres de Paco", "Juan Palomo","Novela negra", true};
libro[1] = {"Los protegidos", "Alberto Catetas","Fantasía", true};
libro[2] = {"El internado", "Nazi Chan","Novela negra", false, user[2].nombre};
libro[3] = {"El barco", "Mario Houses","Fantasía",false, user[0].nombre};

// EJECUCIÓN DEL PROGRAMA
mostrarLibrosDisponibles();
cout << endl;
mostrarHistorialLibros();
cout << endl;
mostrarUsuarios();
cout << endl;
mostrarLibroActual();
cout << endl;
mostrarHistorialPersona(user[0]);
cout << endl;
comprobarLibro(libro[2]);

    return 0;
}

// FUNCIONES
void mostrarLibrosDisponibles() {
    for(int i = 0; i < 4; i++) {
        if(libro[i].dispo == false) {
            cout << "El libro es: " << libro[i].titulo << endl;
            cout << "El libro lo tiene: " << libro[i].nombreUsuario.nombre << endl;
        }
    }
}

void mostrarHistorialLibros() {

   for (int i = 0; i < 3; i++) { // ESTE FOR RECORRE LOS USUARIOS
        cout << user[i].nombre << endl;
        for (int j = 0; j < 4; j++) {
            if (user[i].historial[j].empty()) {
                if (j != 0) {
                    j = 5;
                } else {
                    cout << "\tSu historial esta vacio" << endl;
                    j = 5;
                }
            } else {
                cout << "\tTítulo: " << user[i].historial[j] << endl;
            } 
        }
   }   
}

void mostrarUsuarios() {
    for (int i = 0; i < 4; i++) {
        cout << "Usuario " << i+1 << endl; 
        cout << "\tNombre: " << user[i].nombre << endl;
        cout << "\tEdad: " << user[i].edad << endl;
    }   
}

void mostrarLibroActual() {
    for (int i = 0; i < 4; i++) {
        if (libro[i].dispo == false) {
            cout << "El libro: '" << libro[i].titulo << "' lo tiene: " << endl;
            cout << "\t" <<libro[i].nombreUsuario.nombre << endl;
        }
        
    }
}

void mostrarHistorialPersona(Usuario y) {
    
    cout << "El historial de " << y.nombre << " esta formado por: " << endl;

    for (int i = 0; i < 4; i++) {
        cout << y.historial[i] << endl;
    }
}

void comprobarLibro(Libro z) {
    if (z.dispo == true) {
        cout << "El libro esta disponible";
    } else {
        cout << "No disponible. Lo tiene: " << z.nombreUsuario.nombre;
    }
    
}



