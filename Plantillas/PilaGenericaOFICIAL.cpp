#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class PilaGenerica {
    class NodoPila{
        public:
            NodoPila* siguiente;
            T elemento;
            NodoPila(T x){
                elemento = x;
                siguiente = NULL;
            }
    };

    NodoPila* cima; // Creamos un puntero de tipo NodoPila
    public:
        PilaGenerica(){ // CONSTRUCTOR DE UNA PILA VACÍA DONDE EL PUNTERO APUNTA A NULL,ES DECIR, EL COMIENZO
            cima = NULL;
        }

        // DECLARACIÓN DE MÉTODOS DE LA PILA
        void insertar(T elemento);
        T quitar();
        T cimaPila() const; 
        bool pilaVacia() const; 
        void limpiarPila();
        void mostrar();

        ~PilaGenerica() { // DESTRUCTOR DE LA PILA
            limpiarPila();
        }



    }; // AQUÍ SE ACABA NUESTRA CLASE PILA. LUEGO  PASAMOS A PROFUNDIZAR EN LAS FUNCIONES

    template <class T> bool PilaGenerica<T>::pilaVacia() const {
        return cima == NULL;
    }

    template <class T> void PilaGenerica<T>::insertar(T elemento) {
        NodoPila* nuevo;
        nuevo = new NodoPila(elemento); // Aquí la difrencia con respecto a mi código es el constructor del Nodo pero todo hace lo mismo
        nuevo->siguiente = cima;
        cima = nuevo;
    }

    template <class T> T PilaGenerica<T>::quitar() {
    if(pilaVacia())
        throw "Pila Vacía, no se puede extraer";
        T aux = cima -> elemento;
        cima = cima -> siguiente;
        return aux; //! PORQUE RETURN? PRUEBALO
    }

    template <class T> T PilaGenerica<T>::cimaPila() const {
        if (pilaVacia())
        throw "Pila Vacía";
        return cima -> elemento;
    }

    template <class T> void PilaGenerica<T>::limpiarPila(){
        NodoPila* n;
        while(!pilaVacia()){
            n = cima;
            cima = cima -> siguiente;   
            delete n;
        }
    }

    template <class T> void PilaGenerica<T>::mostrar() {
        NodoPila *aux;
  

    cout << endl;

    if(aux == NULL){
        cout<<"No hay datos en la pila"<<endl;
    }

    
    cout<<"Los datos de la pila son: "<<endl;

    while(aux != NULL){
        cout << aux->elemento << " - ";
        aux = aux->siguiente;
    }

    cout<<"FIN"<<endl;

    }

int main() {

    cout << "Hola mundo!";

    PilaGenerica<int>* pililla = new PilaGenerica<int>;

    pililla->insertar(3);
    pililla->insertar(2);
    pililla->insertar(1);

    pililla->mostrar();

    cout << "Esto quita algo: " << pililla->quitar() << endl;

    cout << "Volvemos a mostrar: " << endl;
    pililla->mostrar();

    return 0;
}