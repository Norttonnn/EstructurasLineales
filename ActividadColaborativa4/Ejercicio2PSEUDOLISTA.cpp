#include <iostream>
using namespace std;

template <typename T> class Nodo {
    private:
        T dato;             // Dato
        Nodo<T> *enlace;    // Puntero llamado enlace que nos va a conectar los nodos para poder reccorer la lista. CONECTA LOS PUNTOS
    public:

        //! PRIMERO DECLARAMOS LOS CONSTRUCTORES Y DESTRUCTORES

        Nodo (T d) {    // Constructor para cuando solo quieres meter un dato
            dato = d;
            enlace = 0;
        }

        Nodo(T d, Nodo<T> *e) { // Constructor para cuando quieras meter un nodo con un enlace
            dato = d;
            enlace = e;
        }

        //! AHORA DEFINIMOS LOS GETTERS Y SETTERS

        T dameDatoNodo() { // Nos retorna el dato
            return dato;
        }

        Nodo *dameEnlaceNodo() { // Nos devuelve el enlace
            return enlace;
        }

        void ponerEnlace(Nodo<T> *siguienteNodo) { // Le pasamos por parametro la posición a la que queremos que apunte el enlace y se asigna
            enlace = siguienteNodo;
        }
};

template <typename T> void reccorreLista(Nodo<T> *pseudoLista) {

    bool existeEnlace = true;

    while(existeEnlace == true) {
        cout << pseudoLista->dameDatoNodo() << endl;

        if(pseudoLista->dameEnlaceNodo() == NULL){ // Si la pseudo lista no tiene enlace a siguiente punto, es decir, vale null o lo que es igual 0 se dejan de mostrar datos porque no hay
            existeEnlace = false;
        }else{
            pseudoLista = pseudoLista->dameEnlaceNodo(); //! ESTA LÍNEA DE CÓDIGO NO LA ENTIENDO
        }
    }
}


int main() {

    Nodo<int> *n1 = new Nodo(23);
    Nodo<int> *n2 = new Nodo(71);
    Nodo<int> *n3 = new Nodo(20);
    Nodo<int> *n4 = new Nodo(32);
    Nodo<int> *n5 = new Nodo(44);
    

    n1->ponerEnlace(n2);
    n2->ponerEnlace(n3);
    n3->ponerEnlace(n4);
    n4->ponerEnlace(n5);

    Nodo<int> *lista = n1;
    
   

    reccorreLista(lista);

    


    return 0;
}