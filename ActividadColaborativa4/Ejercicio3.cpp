/*
Utilizando la lista de números enteros desarrollada en el apartado anterior, inserta
tres nuevos elementos. Uno en la cabeza, otro en la cola y otro entre dos nodos.
*/

#include <iostream>
using namespace std;

template <typename T> class listaPEL{    
    class Nodo{
        public: 
            T elemento;
            Nodo* siguiente;//direccion de memoria donde esta el siguiente objeto
            Nodo(T e){
                elemento = e;
                siguiente = 0;
            }
    };
    Nodo* primero;
    public:
    listaPEL(){
        primero = 0;
    }
    void insertar_cabeza(T e){
        Nodo* nuevoNodo = new Nodo(e);
        nuevoNodo -> siguiente = primero;// ahora el valor del puntero del nuevo nodo es el valor que tenia el enlace del puntero inicial(primero)
        primero = nuevoNodo;
    }

    void insertar_cola(T e){
        Nodo* nuevoNodo = new Nodo(e);
        bool existe_enlace = true; // si hay un enlace(puntero) significa que hay un nuevo elemetno cuando llegue al momento en el que no existe 
                                   //ahi es donde hay q añadir el nuevo elemetno por lo tanto hay que salir de bucle
        Nodo* aux = primero;       
        while(existe_enlace == true){
            if(aux-> siguiente != NULL){
                aux = aux->siguiente;//el valor de aux es el varlor del puntero
            }else{
                aux-> siguiente= nuevoNodo;
                existe_enlace = false;
            }
        }
    }

    int size(){
        if(listaPEL::es_vacia()){
            return 0;
        }else{
            int cont = 0;
            bool existe_enlace = true; // si hay un enlace(puntero) significa que hay un nuevo elemetno cuando llegue al moento en el que no existe 
                                    //ahi es donde hay q añadir el nuevo elemetno por lo tanto hay que salir de bucle
            Nodo* aux = primero;       
            while(existe_enlace == true){
                if(aux-> siguiente != NULL){
                    aux = aux->siguiente;//el valor de aux es el varlor del puntero
                    ++cont;
                }else{   
                    existe_enlace = false;
                }
            }
            if(cont != 0){
                return cont+1;
            }
            return cont+1;
        }
    }
        
        
        
    
    void insertar_pos(T e, int pos){
        
        if(pos > size()){
            cout << "No se puede insertar en dicha posicion";
        }else{
            Nodo* aux = primero;
            for (int i = 0; i < pos -1; ++i){
                aux = aux->siguiente;//el nodo de la posicion que queremos insertar es decir si qwueremos insertar en la pos 5 guarda el nodo 4 que referencia al nodo5
                cout<<"posicion bucle : " <<  aux->elemento<<endl;
            }
            Nodo* nuevoNodo = new Nodo(e);
            nuevoNodo->siguiente = aux->siguiente;//el puntero del nuevo elemento  sera al que apunte el puntero actual
            aux->siguiente = nuevoNodo;// el puntero actual ahora debe apuntar al nuevo elemento   
        }
    }

    bool es_vacia(){
        return primero == 0;
    }

    void eliminar_cabeza(){//el dato primero es un puntero (NO NODO) que indica el comienzo de la lista
        Nodo* aux = primero;// creamos un puntero cuyo valor es el dato del objeto lista que apunta al primer elemto de la lista
        primero = aux-> siguiente;//el puntero principal ahora tiene el puntero al que apunta el primero de la lista es decir el segundo nodo 
        delete aux;// elimina el objeto al que apunta el puntero principal que estaba almacenado en la variable de tipo puntero aux 

    }

    void eliminar_cola(){
        Nodo* aux = primero;
        for(int i = 0; i<size()-1; ++i){
            aux = aux->siguiente;
        }
        delete aux->siguiente;
        aux->siguiente = 0;
    }

    void eliminar_pos(int pos){
        if(pos > size()){
            std::cout << "No se puede eleiminar dicha posicion";
        }else{
            Nodo* aux = primero;
            for(int i = 0; i<pos-1; ++i){//llegamos hasta el nodo anterior al que queremos eliminar
                aux = aux->siguiente;//guardamos en aux el nodo anterior al que queremos eliminar que señala al nodo que queremos eliminar
            }
            Nodo* aux2 = aux->siguiente;//guarda el puntero que apunta al nodo que queremos eliminar
            aux->siguiente = aux2->siguiente;//el nodo anterior pasa a apuntar al nodo que hay despues del nodo que queremos eliminar 
            delete aux2;//elimina el objeto al que apunta el puntero aux2
        }
    }

    void mostrar_pos(int pos){
        if(pos > size()){
            std::cout << "No se puede eleiminar dicha posicion";
        }else{
            Nodo* aux = primero;
            for(int i = 0; i<pos; i++){//llegamos hasta el nodo anterior al que queremos eliminar
                aux = aux->siguiente;//guardamos en aux el nodo anterior al que queremos eliminar que señala al nodo que queremos eliminar
            }
            cout << aux->elemento << endl;
        }
    }

    void recorrerLista(){
        for(int i = 0; i<size()+1; ++i){
            mostrar_pos(i);
        }
    }
};

int main() {

    listaPEL<int>* lista = new listaPEL<int>;

    lista->insertar_cabeza(3);
    lista->insertar_cabeza(4);
    lista->insertar_cabeza(5);
    lista->insertar_cabeza(6);
    lista->insertar_cola(2);
    lista->insertar_pos(0,0);

    lista->recorrerLista();



    return 0;
}