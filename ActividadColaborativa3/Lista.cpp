#include <iostream>
using namespace std;

template <typename T> class listaPEL {

protected:
    class Nodo{
    public:
        T elemento;
        Nodo *siguiente;
        Nodo(T e) {
            elemento = e;
            siguiente = NULL;
        }
        Nodo *primero;
    public:
        listaPEL() {
            primero = 0;
        }
        void insertar_cabeza() {
            Nodo *nuevo = new Nodo(e);
            primero = nuevo;
        }

    };
};