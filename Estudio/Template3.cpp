#include <iostream>
using namespace std;

template <typename T> class Pila {
    private:
        T datos[50];
        int elementos;
    public:
        Pila() {
            elementos = 0;
        }
        void insert(T elem) {
        if (elementos < 50) {
            datos[elementos] = elem;
            elementos ++;
        } else {
            cout << "Error: Pila llena";
        }
    }

    // Función de extracción de elemento de una pila;
    T extract() {
        if (elementos > 0) {
            elementos --;
            return datos[elementos];
        } else {
            cout << "Error: Pila vacía";
        }
    }

    int Numero() {
        return elementos;
    }
    bool es_vacia() {
        return elementos == 0;
    }
};


int main() {
    Pila p1;

    return 0;
}

