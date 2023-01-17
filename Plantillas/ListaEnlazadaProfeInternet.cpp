#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente; // enlace
};



// ELABORACIÓN DE METODOS
void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo(); // reserva espacio en memoria para poder almacenar luego 
}

void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo(); 
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1) {
        lista = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

}

int main() {

    Nodo *lista = NULL;
    
    



    return 0;
}