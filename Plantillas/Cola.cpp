#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* enlace;
};

// DECLARACIÓN DE FUNCIONES
void agregarElementoCola(int d, Nodo *&, Nodo *&);
void sacarElementoCola(int &, Nodo *&, Nodo *&);
bool cola_vacia(Nodo *);


int main() {

    Nodo *frente = NULL;
    Nodo *final = NULL;

    int dato;
    int n = 1;
    while (n != 0) {
      cout << "Digite un número: "; cin >> dato; 
      cout << "¿Segyur? "; cin >> n;
      agregarElementoCola(dato, frente, final);
    }

    while (final != NULL) {
        sacarElementoCola(dato, frente, final);
        if (final != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << ".";
        }
    }
    
    
    



    return 0;
}


void agregarElementoCola(int d, Nodo *&frente, Nodo *&final) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = d;
    nuevo_nodo->enlace = NULL;
    
    if(cola_vacia(frente)) {
        frente = nuevo_nodo;
    } else {
        final->enlace = nuevo_nodo;
    }

    final = nuevo_nodo;

    cout << "Elemento " << d << " insertado a cola correctamente" << endl;
}

void sacarElementoCola(int &d, Nodo *&frente, Nodo *&cola) {
    d = frente->dato;
    Nodo *aux = frente;

    if(frente == cola) {
        frente == NULL;
        cola = NULL;
    } else {
        frente = frente->enlace;
    }
    delete aux;

    // cout << "Elemento " << d << " eliminado correctamente" << endl;

}

bool cola_vacia(Nodo *frente) { // FUNCIÓN PARA DETERMINAR SI LA COLA ESTA VACÍA O NO
    return (frente == NULL) ? true : false;
}