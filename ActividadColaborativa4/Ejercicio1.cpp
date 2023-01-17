/*
Declara una clase “punto” que represente un punto dentro de un plano
(coordenadas x e y), y genera una clase Nodo cuyo campo de valor sea
“punto”.
*/

#include <iostream>
using namespace std;

class Punto {
    private:
    double x;
    double y;

    public:
    //Constructor vacío
    Punto() {
        Punto::x=0;
        Punto::y=0;
    }
    //Constructor con parámetros
    Punto(double x, double y) {
        Punto::x=x;
        Punto::y=y;
    }

    void imprimir() {
        cout << "( " << x << " , " << y << " )" << endl;
    }

};

template <typename T> class Nodo{
    protected:
    T dato;
    Nodo<T>* enlace;

    public:
    Nodo(T d) {
        Nodo::dato = d;
        Nodo::enlace = 0;
    };
    Nodo(T d, Nodo <T> e){
        Nodo::dato = d;
        Nodo::enlace = 0;
    };
    //da informacion de en que bloque de memoria está el siguiente dato de la lista
    Nodo<T>* enlaceNodo() {
        return enlace; 
    };
    //enlazar
    void ponerEnlace(Nodo<T>* e){
        Nodo::enlace = e;
    };
    void getPunto(){
        cout << Punto::x << Punto::y;
    }

    void imprimirDato() {
        dato.imprimir();
    }
};

template <typename T> void reccorreLista(Nodo<T> *pseudoLista) {

    bool existeEnlace = true;

    while(existeEnlace == true) {
        pseudoLista->imprimirDato();
        if(pseudoLista->enlaceNodo() == NULL){ // Si la pseudo lista no tiene enlace a siguiente punto, es decir, vale null o lo que es igual 0 se dejan de mostrar datos porque no hay
            existeEnlace = false;
        }else{
            pseudoLista = pseudoLista->enlaceNodo(); //! ESTA LÍNEA DE CÓDIGO NO LA ENTIENDO
        }
    }
}

int main(int argc, char const *argv[]) {
    Punto* p = new Punto(1,2);
    Punto* p2 = new Punto(3,4);


    Nodo<Punto>* n1 = new Nodo<Punto>(*p);
     Nodo<Punto>* n2 = new Nodo<Punto>(*p2);


    n1->ponerEnlace(n2);

    reccorreLista(n1);


    
    return 0;
}