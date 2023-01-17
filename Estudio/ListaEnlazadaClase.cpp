#include <iostream>
using namespace std;

template <typename T> class Nodo {
 private:
    T dato;
    Nodo<T>* enlace;
 
 public:
    Nodo(T d){
        Nodo::dato = d;
        Nodo::enlace = 0;
    }
 public:
    Nodo(T p, Nodo<T>* n) {
    Nodo::dato = p;
    Nodo::enlace = n;
    }


    T datoNodo() const {
        return dato;
    }

    Nodo* enlaceNodo() const {
        return enlace;
    }

    void ponerEnlace(Nodo<T>* sgte) {
        enlace = sgte;
    }
};

template <typename T> void recorremeEsta(Nodo<T>* pseudoLista) {
    bool existe_enlace = true;
    while(existe_enlace == true){
        cout << pseudoLista->datoNodo() << endl;

        if(pseudoLista->enlaceNodo() == NULL){
            existe_enlace = false;
        }else{
            pseudoLista = pseudoLista->enlaceNodo();
        }
    }
}

// FUNCIONES DE INSERCIÓN DE DATOS
template<typename T> void insercion_cabeza(Nodo<T>* &dato_nuevo, Nodo<T>* &pseudolista) { //entiendo que pseudolisra es el puntero que lleva a la primera posición
    dato_nuevo->ponerEnlace(pseudolista);
    pseudolista = dato_nuevo;
}

template <typename T> void inercion_cola(Nodo<T>* &dato_nuevo, Nodo<T>* &pseudolista) {
    bool nodo_terminal = false;
    Nodo<T>* aux = pseudolista;
    while(nodo_terminal == false) {
        if (aux->enlaceNodo() == NULL) {
            aux->ponerEnlace(dato_nuevo);
            nodo_terminal = true;
        } else {
            aux = aux->enlaceNodo();
        } 
    }
}

template <typename T> void insertar_posicion(Nodo<T>* &dato_nuevo,int pos, Nodo<T>* &pseudolista) {
     int posicion = 0; // CONTADOR
     bool salida_bucle = false;
     Nodo<T>* aux = pseudolista;

     while(salida_bucle == false) {
        if(pos == posicion) {
            dato_nuevo->ponerEnlace(aux->enlaceNodo()); 
            aux->ponerEnlace(dato_nuevo);
            salida_bucle = true;
        } else {
            if(aux->enlaceNodo() == NULL) {
                salida_bucle = true;
            } else {
                ++posicion;
                aux = aux->enlaceNodo();
            }
        }
     }
}

int main(int, char**) {
   
    Nodo <int>* n1 = new Nodo(1);
    Nodo <int>* n2 = new Nodo(2);
    Nodo <int>* n3 = new Nodo(3);


    n1->ponerEnlace(n2);
    n2->ponerEnlace(n3);

    Nodo <int>* pseudolista = n1; // CREAMOS LISTA ENLAZADA QUE EMPIEZA EN N1 con los enlaces ya puesto todo va rodao
    Nodo<int>* n4 = new Nodo<int>(0);





    recorremeEsta(pseudolista);
    //inercion_cola(n4,pseudolista);
    //insertar_posicion(n4,1,pseudolista);
    insercion_cabeza(n4,pseudolista);
    cout << "\nOtra lista" << endl; recorremeEsta(pseudolista);

   

};