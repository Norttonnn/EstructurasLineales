/*Suponiendo que se tiene la clase cola que implementa las operaciones del TAD cola. 
Escribir una función que crea un clon (una copia idéntica) de una cola determinada. 
Las operaciones que se han de utilizar son únicamente las del TAD Cola.*/

#include <iostream> 
using namespace std;

template <typename T> class ColaPEL {
private:
    class Nodo {
    public:
        T elemento;
        Nodo *siguiente;

        Nodo(T x) {
            elemento = x;
            siguiente = 0;
        };
    };

    Nodo * primero;
    Nodo * ultimo;

public:
    ColaPEL() {
        primero = 0;
        ultimo = 0;
    };

    void insertar(T e){
        Nodo* nuevo = new Nodo(e);
        if (primero == 0){
            primero = nuevo;
            ultimo = primero;
        }else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

    }
    T extraer(){
        Nodo* aux = primero;
        T elemento = aux-> elemento;
        primero = primero->siguiente;
        delete aux;
        return elemento;
    }

    T recuperarPrimero(){
        return primero->elemento;
    }

    bool esVacia(){
        return primero == 0;
    }

    ColaPEL clonar(){
        ColaPEL clon;
        Nodo* aux = primero;
        while(aux != 0){
            clon.insertar(aux->elemento);
            aux = aux->siguiente;
        }
        return clon;
    }

    bool esIdentica(ColaPEL<T> cola, ColaPEL<T> colaClon){
        while(!cola.esVacia()){
            if(cola.extraer() != colaClon.extraer()){
                return false;
            }
        }
        return true;
    }


};

int main(){
    ColaPEL<int> cola;
    cola.insertar(1);
    cola.insertar(2);
    cola.insertar(3);
    cola.insertar(4);
    cola.insertar(5);
    ColaPEL<int> colaClon = cola.clonar();

    while(!cola.esVacia()){
        cout << cola.extraer() << endl;
    }
    
    while(!colaClon.esVacia()){
        cout << colaClon.extraer() << endl;
    }

    if(cola.esIdentica(cola, colaClon)){
        cout << "Son iguales" << endl;
    }else{
        cout << "No son iguales" << endl;
    }
    return 0;
}