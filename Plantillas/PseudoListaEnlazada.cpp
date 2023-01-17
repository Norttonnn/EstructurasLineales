#include <iostream>
using namespace std;

template <typename T> class Nodo {
    private:
        T dato;             // Dato
        Nodo<T>* enlace;    // Puntero llamado enlace que nos va a conectar los nodos para poder reccorer la lista. CONECTA LOS PUNTOS
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

template <typename T> void insertarCabeza(Nodo<T> *&datoNuevo, Nodo<T> *&pseudoLista) {
    datoNuevo->ponerEnlace(pseudoLista); // Al dato que queremos introducir le ponemos un enlace que será por donde empezaba la lista anterior
    pseudoLista = datoNuevo; // Ahora pseudolista ya no empieza por el antiguo n1 , ahora empieza por el nuevo dato introducido
}

template <typename T> void insertarCola(Nodo<T> *&datoNuevo, Nodo<T> *&pseudoLista) {

    bool hayNodo = true;
    Nodo<T> *aux = pseudoLista;

    while (hayNodo == true) {
        if(aux->dameEnlaceNodo() == NULL) {
            aux->ponerEnlace(datoNuevo);
            hayNodo = false;
        } else {
            aux = aux->dameEnlaceNodo();
        }
    }
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

    
    

    n1->ponerEnlace(n2);

    Nodo<int> *lista = n1;
    
   

    reccorreLista(lista);

    Nodo<int> *nodoNuevo = new Nodo(43);
    insertarCabeza(nodoNuevo,lista);

    cout << "SEGUNDA vuelta a la lista: " << endl;
    reccorreLista(lista);

    Nodo<int> *nodoNuevoFinal = new Nodo(24);
    insertarCola(nodoNuevoFinal,lista);

    cout << "TERCERA vuelta a la lista: " << endl;
    reccorreLista(lista);

    Nodo<int> *nodoNuevoIntermedio = new Nodo(55);
    insertarPosicion(nodoNuevoIntermedio,lista,1);

    cout << "CUARTA vuelta a la lista: " << endl;
    reccorreLista(lista);
    


    return 0;
}