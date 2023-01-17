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

    void insertar(T e){//se inserta por la cola 
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