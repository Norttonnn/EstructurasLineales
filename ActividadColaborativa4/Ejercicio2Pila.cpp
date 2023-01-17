#include <iostream>
using namespace std;

template <class T>
class colaGenerica{
protected:
    class nodoCola{

    public:
        nodoCola* siguiente;
        T elemento;
        nodoCola(T x){
            elemento = x;
            siguiente = NULL;
        }
    };
    nodoCola* frente;
    nodoCola* final;

public:
    colaGenerica(){
        frente = final = NULL;
    }

    void insertar(T elemento){
        nodoCola* nuevo;
        nuevo = new nodoCola(elemento);
        if(colaVacia()){
           frente = nuevo;
        } else{
            final -> siguiente = nuevo;
        }
        final = nuevo;
    }

    T quitar(){
        if(colaVacia()){
            throw "Cola vacía, no se puede extraer";
        }
        T aux = frente -> elemento;
        nodoCola* a = frente;
        frente = frente -> siguiente;
        delete a;
        return aux;
    }

    /*void borrarCola(){
        for(frente != NULL){
            nodoCola* a;
            a = frente;
            frente = frente -> siguiente;
            delete a;
        }
        final = NULL;
    }*/

    T frenteCola() const{
        if(colaVacia()){
            throw "Cola vacía";
        }
        return frente -> elemento;
    }

    bool colaVacia() const{
        return frente == NULL;
    }

    void compararColas(colaGenerica<T>* cola1, colaGenerica<T>* cola2){
        string cola1String, cola2String;

        while(!cola1 -> colaVacia()){
            cola1String = cola1String + to_string(cola1 -> quitar());
        }

        while(!cola2 -> colaVacia()){
            cola2String = cola2String + to_string(cola2 -> quitar());
        }

        if(cola1String == cola2String){
            cout << "Las colas son igualues";
        }
        else{
            cout << "Las colas no son igualues";
        }
    }

    /*~colaGenerica(){
        borrarCola();
    }*/
};

int main() {
    colaGenerica<int>* ejemplo1 = new colaGenerica<int>;
    colaGenerica<int>* ejemplo2 = new colaGenerica<int>;

    ejemplo1 ->insertar(1);
    ejemplo1 ->insertar(2);
    ejemplo1 ->insertar(3);

    ejemplo2 ->insertar(1);
    ejemplo2 ->insertar(2);
    ejemplo2 ->insertar(3);

    ejemplo2 ->compararColas(ejemplo1, ejemplo2);
}