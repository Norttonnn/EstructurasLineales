#include <iostream>
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
            NodoPila* nuevo;
            nuevo = new NodoPila(elemento);
            nuevo -> siguiente = cima;
            cima = nuevo;
        }

        T quitar(){
            if(pilaVacia()) {
                throw "Pila Vacía, no se puede extraer";
            }
            T aux = cima -> elemento;
            cima = cima -> siguiente;
            return aux;
        }

        T cipaPila() const{
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
