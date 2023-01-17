#include <iostream>
#include <stdlib.h>
using namespace std;


struct Nodo {   
    int dato;
    Nodo *siguiente;
};






// DECLARACIÓN DE LAS FUNCIÓNES A UTILIZAR 
void agregar_A_La_Pila(int, Nodo *&);
void quitar_De_La_Pila(int &, Nodo *&);
void mostrar_Contenido_Pila(Nodo *&);
void buscar_Elemento_Pila(int, Nodo *&);



int main() {

    Nodo *pila = NULL;

    int n = 1; // Para salir del bucle sin más
    int dato;

    while(n != 0) {
        cout << "Dame número: "; cin >> dato;
        agregar_A_La_Pila(dato, pila);
        cout << "¿Sigues? ";    cin >> n;
    }

    cout << "Mostrando elementos de la pila " << endl;
    mostrar_Contenido_Pila(pila);
    buscar_Elemento_Pila(3, pila);

    cout << "Sacando elementos de la pila" << endl;
    while (pila != NULL) {
        quitar_De_La_Pila(dato, pila);
        if(pila != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << ".";
        }
    }
    return 0;
}


void mostrar_Contenido_Pila(Nodo *&pila) {
    Nodo *aux = pila;
    int d;

    cout << endl;

    if(pila == NULL){
        cout<<"No hay datos en la pila"<<endl;
    }

    
    cout<<"Los datos de la pila son: "<<endl;

    while(aux != NULL){
        cout << aux->dato << " - ";
        aux = aux->siguiente;
    }

    cout<<"FIN"<<endl;
}

void buscar_Elemento_Pila(int dato, Nodo *&pila) {

    Nodo *aux = pila;
    int contador = 0;

    if(pila == NULL){
        cout<<"No hay datos en la pila"<<endl;
    }


    while(aux != NULL){
        contador++;

        if(aux->dato == dato) {
            cout << aux->dato << " ha sido encontrado en la pila en la posición: " << contador << endl;
        } 
        aux = aux->siguiente;
    }
    cout<<"FIN"<<endl;
}

void agregar_A_La_Pila(int d, Nodo *&pila) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = d;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo; // Si pila apunta a nuevo_nodo quiere decir que apunta al nuevo elemento

    cout << nuevo_nodo->dato << " Se ha incorporado de manera correcta" << endl;
}

void quitar_De_La_Pila(int &d, Nodo *&pila) {
    Nodo *aux = pila;
    d = aux->dato;
    pila = aux->siguiente;
    delete aux;
}