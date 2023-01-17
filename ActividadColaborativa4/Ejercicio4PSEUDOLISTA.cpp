/*
Realiza un programa para crear una lista de números aleatorios. Los nuevos
números deben insertarse en el centro de la lista (o el punto medio de los
elementos de la misma). Una vez creada se ha de recorrer mostrando
únicamente los números impares.
Detalles:
• Deben meterse los números aleatorios por el teclado del usuario.
• Para terminar de crear la lista, se introducirá el valor reservado -1.
*/

#include <iostream>
#include <vector>
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
    int contador = 0;

    while(existeEnlace == true) {
        if((pseudoLista->dameDatoNodo())%2 != 0) {
            cout << pseudoLista->dameDatoNodo() << endl;
        } 
            

        if(pseudoLista->dameEnlaceNodo() == NULL){ // Si la pseudo lista no tiene enlace a siguiente punto, es decir, vale null o lo que es igual 0 se dejan de mostrar datos porque no hay
            existeEnlace = false;
        }else{
            pseudoLista = pseudoLista->dameEnlaceNodo(); //! ESTA LÍNEA DE CÓDIGO NO LA ENTIENDO
        }
    }
}

template <typename T> int dameCantidad(Nodo<T> *pseudoLista) {

    bool existeEnlace = true;
    int contador = 0;

    while(existeEnlace == true) {
            contador++;

        if(pseudoLista->dameEnlaceNodo() == NULL){ 
            existeEnlace = false;
        }else{
            pseudoLista = pseudoLista->dameEnlaceNodo(); //! ESTA LÍNEA DE CÓDIGO NO LA ENTIENDO
        }
    }
    return contador;
}


template <typename T> void insertarPosicion(Nodo<T> *&datoNuevo, Nodo<T> *&pseudoLista,int pos) {
     int posicion = 0; // CONTADOR
     bool salidaBucle = false;
     Nodo<T>* aux = pseudoLista;

     while(salidaBucle == false) {
        if(pos == posicion) {
            datoNuevo->ponerEnlace(aux->dameEnlaceNodo()); 
            aux->ponerEnlace(datoNuevo);
            salidaBucle = true;
        } else {
            if(aux->dameEnlaceNodo() == NULL) {
                salidaBucle = true;
            } else {
                ++posicion;
                aux = aux->dameEnlaceNodo();
            }
        }
     }
}




int main() {

    Nodo<int> *n1 = new Nodo(23);
    Nodo<int> *n2 = new Nodo(71);
    Nodo<int> *n3 = new Nodo(2);
    Nodo<int> *n4 = new Nodo(4);
    Nodo<int> *n5 = new Nodo(5);
    

    n1->ponerEnlace(n2);
    n2->ponerEnlace(n3);
    n3->ponerEnlace(n4);
    n4->ponerEnlace(n5);

    Nodo<int> *lista = n1;

    int n = 0;
    int y;
    while(n != -1) {
        cout << "Introduce un número: "; cin >>  y;
        Nodo<int> *x = new Nodo(y);


        insertarPosicion(x, lista, dameCantidad(lista)/2);
        cout << "¿Salir? "; cin >> n;

    }

    reccorreLista(lista);

    return 0;
}