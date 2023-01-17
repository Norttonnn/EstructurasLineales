#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T> class PilaGenerica{

    class NodoPila{
        public:
            NodoPila* siguiente;
            T elemento;
        
            NodoPila(T x){
                elemento = x;
                siguiente = NULL;
            }
    };

    NodoPila* cima;

    public:
        PilaGenerica(){
            cima = NULL;
        }

        void insertar(T elemento){
            NodoPila* nuevo = new NodoPila(elemento);
            nuevo -> siguiente = cima;
            cima = nuevo;

            cout << "Letra: " << nuevo->elemento << " insertado correctamente" << endl;
        }

        T quitar(){
            if(pilaVacia()) {
                throw "Pila Vacía, no se puede extraer";
            }
            T aux = cima -> elemento;
            cima = cima -> siguiente;
            return aux;
        }

        T cimaPila() const{
            if(pilaVacia()){
                throw "Pila Vacía";
                return cima -> elemento;
            }
        }

        bool pilaVacia() const{
            return cima == NULL;
        }

        void limpiarPila(){
            NodoPila* n;
            while(!pilaVacia()){
                n = cima;
                cima = cima -> siguiente;
                delete n;
            }
        }

        ~PilaGenerica(){
            limpiarPila();
        }
};

int main() {

    PilaGenerica<int>* n = new PilaGenerica<int>;

    

    // PilaGenerica<int>* pila1;

    // int x = 3;
    // int y = 4;

    // pila1->insertar(x);
    // pila1->insertar(y);
    // pila1->insertar(5);

    PilaGenerica<char>* pila2 = new PilaGenerica<char>;
    string p, pEnPila;

    cout << "Introduce una palabra: " << endl; cin >> p;

    for (int i = 0; i < p.length(); i++) {
        pila2->insertar(p[i]); // INSERTAMOS LAS LETRAS EN LA PILA
    }

    for(int i = 0; i < p.length(); i++){
        cout << pEnPila << endl;
        pEnPila = pEnPila + pila2 -> quitar();
    }

    cout << "\n" << pEnPila << endl;
    cout << p << endl;

    if(p == pEnPila){
        cout << "PALINDROMO";
    } else{
        cout << " NOOOO es un palindormo";
    }
    







    return 0;
}