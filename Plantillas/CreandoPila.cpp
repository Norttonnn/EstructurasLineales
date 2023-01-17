#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T> class Pila {
    class Nodo {
        public: 
            T dato;
            Nodo* enlace; // También podemos llamarlo siguiente

            Nodo(T d) { // CONSTRUCTOR DE LA CLASE NODO
                dato = d;
                enlace = NULL;
            }
    }; //! Aquí finaliza la clase Nodo - Ahora pasamos a Pila

    Nodo* cima; //todo ESTO ES LO QUE ESTAMOS MODIFICANDO TODO EL RATO (CREO)
    public: 
        Pila() { // CONSTRUCTOR DE LA CLASE PILA
            Nodo* cima = NULL;
        }
        // ~PilaGenerica() {} // DESTRUCTOR DE LA PILA

        // FUNCIONES QUE QUEREMOS QUE TENGA NUESTRA PILA 
        void insertarDato(T);
        void eliminarDato();
        void vaciarPila(T);
        int size(); // cantidad de elementos en la pila
        bool pilaVacia(); // comprueba si la pila esta vacía
        void mostrar();   
};

template <class T> void Pila<T>::insertarDato(T d) { // Si no se pone que es de la clase pila no puede llamar de manera correcta a la cima y peta
        Nodo* nuevo_nodo = new Nodo(d); // Aquí la difrencia con respecto a mi código es el constructor del Nodo pero todo hace lo mismo
        // Lo de arriba es lo mismo que poner nuevo_nodo.dato = elemento; simplemente estas cargando el dato en el nodo
        nuevo_nodo->enlace = cima;
        cima = nuevo_nodo;

        cout << d << " Insertado correctamente";
    }

template <class T> void Pila<T>::eliminarDato() {
    Nodo* nodo_auxiliar = cima;
    T d = nodo_auxiliar->dato;
    cima = nodo_auxiliar->enlace;
    delete nodo_auxiliar;

    cout << "Dato: "<< d << " eliminado correctamente " << endl;
}

template<class T> int Pila<T>::size() {
    int contador = 0;
    bool existe_enlace = true;
    Nodo* nodo_auxiliar = cima;

    while(existe_enlace == true) {
        if(nodo_auxiliar->enlace != NULL) {
            nodo_auxiliar = nodo_auxiliar->enlace;
            contador++;
        } else {
            existe_enlace = false;
        }
    }

    return (contador+1);

}

template <class T> bool Pila<T>::pilaVacia() {
    bool vacio = true;
    if(cima == NULL) {
        return vacio;
    } else {
        vacio = false;
        return vacio;
    }
}

template<class T> void Pila<T>::mostrar() {
    bool existe_enlace = true;
    Nodo* nodo_auxiliar = cima;

    while(existe_enlace == true) {
        if(nodo_auxiliar->enlace != NULL) {
            cout << nodo_auxiliar->dato << " , ";
            nodo_auxiliar = nodo_auxiliar->enlace;
        } else {
            cout << nodo_auxiliar->dato << ".";
            existe_enlace = false;
        }
    }
    

}

// template<class T> void Pila<T>::vaciarPila(T d) {
//     Nodo* nodo_auxiliar = cima;
//     while (cima != NULL) {
//         d = nodo_auxiliar->dato;
//         cima = nodo_auxiliar->enlace;
//         delete nodo_auxiliar;
//         cout << "Nodo eliminado " << endl;
//     }

//     cout << "\nPILA VACÍA" << endl;
// }


int main() {
    cout << "Buenos días princesa!! -   VAMOS A COMENZAR CON EL CÓDIGO PUTA" << endl;

    Pila<int>* pililla = new Pila<int>;
    pililla->insertarDato(4); cout << endl; pililla->insertarDato(3); cout << endl; pililla->insertarDato(2);
    cout << endl;

    pililla->size();

    int contador = pililla->size();

    cout << endl;
    cout << true << endl; // 1 es verdadero
    cout << false << endl; // 0 es falso
    
    cout << "El estado de la pila es: " << endl;
    cout << pililla->pilaVacia() << endl;

    pililla->mostrar(); cout << endl;

    do {
        pililla->eliminarDato();
        contador--;
    } while (contador > 0);

    if(contador == 0) {
        cout << "Pila vacía";
    }

    cout << "\n" <<  pililla->pilaVacia() << endl;

    Pila<string>*pilaString = new Pila<string>;

    pilaString->insertarDato("Hola"); cout << endl; pilaString->insertarDato("Adios"); cout << endl; ;pilaString->insertarDato("Hola");
    
    
    


    

    return 0;
}