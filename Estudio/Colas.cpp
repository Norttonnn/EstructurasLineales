/*
Una cola es una estructura de datos caracterizada por ser una secuencia de elementos en la que la operación de inserción 
se realiza por un extremo y la extracción por el otro.

! El primero en llegar es el primero en salir (FIFO)

                                        (final) x x x x x x x x x x x x (frente)

?Si queremos INSERTAR X Y Z el resultado sería tal que: Z Y X
?Si queremos QUITAR estos elementos sería tal que: Z Y X -> O Z Y -> O O Z -> O O O
*/

/*
? Para INSERTAR elementos en una cola, sólo hay que seguir 3 pasos:
    1. Crear espacio en memoria para almacenar un nodo.
    2. Asignar ese nuevo nodo al dato que queremos insertar.
    3. Asignar los punteros frente y fin hacia el nuevo nodo.
*/

/*
? Para ELIMINAR elementos en una cola, sólo hay que seguir 3 pasos:
    1. Obtener el valor del nodo.
    2. Crear un nodo aux y asignarle el frente de la cola.
    3. Eliminar el nodo del frente de la cola.
*/



#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

// PROTOTIPO DE FUNCIÓN
void InsertarCola(Nodo *&, Nodo *&, int);
bool ColaVacia(Nodo *);
void EliminarCola(Nodo *&, Nodo *&, int &); // El dato se introduce por referencia aquí

int main() {
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;

    // INSERTANDO
    cout << "Dame un número: ";     cin >> dato;        InsertarCola (frente,fin, dato);
    cout << "Dame un número: ";     cin >> dato;        InsertarCola (frente,fin, dato);
    cout << "Dame un número: ";     cin >> dato;        InsertarCola (frente,fin, dato);

    // ELIMINANDO
    cout << "Quitando los nodos de la cola: ";
    while (frente != NULL) {
        EliminarCola(frente, fin, dato);
        if(frente != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << ".";
        }
    }
    



    return 0;
}

void InsertarCola(Nodo *&frente, Nodo *&fin, int n) {
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;

    if (ColaVacia(frente)) {
        frente = nuevoNodo;
    } else {
        fin->siguiente = nuevoNodo;
    }

    fin = nuevoNodo;

    cout <<"\tElemento " << n << " insertado a cola correctamente." << endl;    
}

void EliminarCola(Nodo *&frente, Nodo *&fin, int &n) {
    n = frente->dato;
    Nodo *aux = frente;

    if(frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}

bool ColaVacia(Nodo *frente) {
    return (frente == NULL)? true : false;

}