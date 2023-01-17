/**
 *? Para INSERTAR elementos en la pila, solo hay que seguir 4 pasos:

        1) Crear el espacio en memoria para almacenar un //!nodo
        2) Cargar el valor dentro del nodo(//!dato).
        3) Cargar el puntero pila dentro del nodo (//! *siguiente).
        4) Asignar el nuevo nodo a la pila
*/

/**
 *? Para QUITAR elementos en la pila, solo hay que seguir 4 pasos:

        1) Crear una variable //! *aux de tipo nodo.
        2) //! Igualar el n a aux->dato.
        3) Pasar pila a siguiente nodo.
        4) Eliminar aux.
*/

#include <iostream> 
#include <stdlib.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

//PROTOTITPO DE FUNCIÓN
void AgregarPila(Nodo *&, int);
void SacarPila(Nodo *&, int &n); // Insertarmos el dato n por referencia porque este va a variar

int main() {

    Nodo *pila = NULL;
    int dato;
    
    // AGREGANDO DATOS A LA PILA
    cout << "Dame dato: ";      cin >> dato;        AgregarPila(pila, dato);
    cout << "Dame dato: ";      cin >> dato;        AgregarPila(pila, dato);


    // SACANDO DATOS DE LA PILA
    cout << "Sacando elementos de la pila" << endl;
    while (pila != NULL) {
        SacarPila(pila,dato);
        if(pila != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato <<".";
        }
    }
    
    

    return 0;
}

void AgregarPila(Nodo *&pila, int n) { // n va a ser el número que el usuario va a añadir a la pila
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

void SacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}
