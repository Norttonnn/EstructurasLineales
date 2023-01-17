#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class PilaGenerica {
    class Nodo {
        public:
            T elemento;
            Nodo* siguiente; // enlace

            Nodo() { // constructor vacio ma g

            }

            Nodo(T elemento) {
                this->elemento = elemento;
                siguiente = NULL;
            }
    };

    Nodo* cima = NULL;
    public:
        void agregaElemento(T);
        void mostrar();
        void quitarElemento();
        void vaciarPila();
        
};

template <class T> void PilaGenerica<T>::agregaElemento(T d) {
    Nodo* aux = new Nodo();
    aux->elemento = d;
    aux->siguiente = cima;
    cima = aux;

    cout << "Dato: " << aux->elemento << " insertado correctamente" << endl;
}

template <class T> void PilaGenerica<T>::quitarElemento() {
    Nodo* aux = cima;
    T d;
    d = aux->elemento;
    cima = aux->siguiente;
    delete aux;

    cout << "Dato (" << d << ") eliminador correctamente" << endl;
}

template <class T> void PilaGenerica<T>::vaciarPila() {
    // Nodo* aux = cima;
    bool existeElemento = true;
    T d;

    while (cima != NULL) {
        Nodo* aux = cima; // tienes que crear el aux todo el rato porque no paras de borrarlo
    
        d = aux->elemento;
        cima = aux->siguiente;
        delete aux;
    }

    cout << "PILA VACIADA CORRECTAMENTE" << endl;

    
}

template <class T> void PilaGenerica<T>::mostrar() {
    bool existeSiguiente = true;
    Nodo* aux = cima;

    if(cima == NULL) {
        cout << "Pila vacia";
        existeSiguiente = false;
    }

    while (existeSiguiente == true) {
        if (aux->siguiente != NULL) {
            cout << aux->elemento << " , ";
            aux = aux->siguiente;
        } else {
            cout << aux->elemento << "." << endl;
            existeSiguiente = false;
        }
        
        
 
    }
    

}



int main() {

    cout << "P I L A" << endl;
    cout << "-------------------------" << endl;

    PilaGenerica<int> *pila = new PilaGenerica<int>;
    pila->agregaElemento(3);
    pila->agregaElemento(5);

    pila->mostrar();

    //pila->vaciarPila();
    // pila->mostrar();

    return 0;
}