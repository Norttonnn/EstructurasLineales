/*
Ejercicio 1. Implementar en C++ un programa, simulando la pila de usuario 
(y declarando sus valores en la misma) tenga las siguientes funciones: 
• Solicite al usuario por consola un valor que almacenar en la pila de usuario.  
• Permita ver que valores se almacenan en la pila del usuario en las diferentes 
posiciones.  
• Debe poder eliminarse el valor de cualquier posición de la pila de usuario.  
El  código  generado  debe  ser  a  prueba  de  errores.  Para  ello  implementa  los 
métodos necesarios para poder mantener el proceso de ejecución. 
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

//PROTOTIPO DE FUNCION
void Menu();
void InsertarLista(Nodo *&,int);
void MostrarLista(Nodo *);
void BuscarLista(Nodo *, int);
void EliminarNodo(Nodo *&,int);

Nodo *lista = NULL;
int dato;


int main() {

    Menu();


return 0;
}


void Menu() {
    int opcion;
    do {
        cout << "\t**MENÚ**" << endl;
        cout << "1 - Insertar elementos en la lista" << endl;
        cout << "2 - Mostrar elementos de la lista" << endl;
        cout << "3 - Buscar un elemento en la lista" << endl;
        cout << "4 - Eliminar un elemento de la lista" << endl;
        cout << "5 - Salir" << endl;
        cout << "\nElige opción: "; cin >> opcion;

        switch (opcion) {
        case 1: cout << "\nDame un número: ";
                cin >> dato;
                InsertarLista(lista,dato);
                cout << endl;
            break;
        case 2: MostrarLista(lista);
                cout << endl;
            break;
        case 3: cout << "\nDame el número que quieras buscar: ";
                cin >> dato;
                BuscarLista(lista,dato);
                cout << endl;
            break;
        case 4: cout << "\nDame el número que queiras eliminar: ";
                cin >> dato;
                EliminarNodo(lista,dato);
                cout << endl;
            break;
        }

    
    } while (opcion != 5);
    
}


void InsertarLista(Nodo *&lista, int n) {
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->dato = n;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1){
        lista = nuevoNodo;
    } else {
        aux2->siguiente = nuevoNodo;
    }

    cout << "\tElemento " << n << " insertado a la lista de manera correcta" << endl;
    
    
}

void MostrarLista(Nodo *lista) {
    Nodo *actual = new Nodo();
    actual = lista;

    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    
}


void BuscarLista(Nodo *lista, int n) {
    
    bool band = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n)){
        if(actual->dato == n) {
            band = true;
        }
        actual = actual->siguiente;
    }

    if(band == true) {
        cout << "Elemento " << n << " SI ha sido encontrado en la lista\n";
    } else {
        cout << "Elemento " << n << " NO ha sido encontrado en la lista\n";
    }
}

void EliminarNodo(Nodo *&lista, int n) {
    // Preguntar si la lisra no esta vacia
    if(lista != NULL) {
        Nodo *auxBorrar;
        Nodo *anterior = NULL;

        auxBorrar = lista;

        // Recorremos la lista
        while ((auxBorrar != NULL) && (auxBorrar->dato != n)) {
            anterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;
        }

        //El elemento no ha sido encontrado
        if(auxBorrar == NULL) {
            cout << "El elemento no ha sido encontrado";
        } else if(anterior == NULL) { // El primer elemento es el que vamos a borrar
            lista = lista->siguiente;
            delete auxBorrar;
        } else { // El elemento esta en la lista pero no es el primer nodo
            anterior->siguiente = auxBorrar->siguiente;
            delete auxBorrar;
        }
        
    }

}
