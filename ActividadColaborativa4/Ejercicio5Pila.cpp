#include <iostream>
using namespace std;



// Archivo PilaGenerica.h
template <class T>

class PilaGenerica
{
    
    class NodoPila
    {
    public:
        NodoPila *siguiente;
        T elemento;
        NodoPila(T x)
        {
            elemento = x;
            siguiente = NULL;
        }
    };

    NodoPila *cima;

public:
    PilaGenerica()
    {
        cima = NULL;
    }

    void insertar(T elemento);
    T quitar();
    T cimaPila() const;
    bool pilaVacia() const;
    void limpiarPila();
    void imprimirPila();

    ~PilaGenerica()
    {
        limpiarPila();
    }
};

template <class T>
bool PilaGenerica<T>::pilaVacia() const
{
    return cima == NULL;
}

template <class T> void PilaGenerica<T>::insertar(T elemento)
{
    NodoPila *nuevo;
    nuevo = new NodoPila(elemento);
    nuevo->siguiente = cima;
    cima = nuevo;
}

template <class T> T PilaGenerica<T>::quitar()
{
    if (pilaVacia())
        throw  std::range_error("Pila esta vacía");
    T aux = cima->elemento;
    cima = cima->siguiente;
    return aux;
}

template <class T>void PilaGenerica<T>::imprimirPila(){
    if(pilaVacia()){
        cout<<"No hay datos que imprimir!"<<endl;
    }else{
    cout << "Imprimiento contenido de la pila:"<<endl;
    while(!pilaVacia()){
        T aux = cima->elemento;
        cout << "- " << aux << endl;
        cima = cima -> siguiente;
        
    }}

}

template <class T>
T PilaGenerica<T>::cimaPila() const
{
    if (pilaVacia())
        throw std::range_error("Pila esta vacía, no se puede extraer ningun elemento");
    return cima->elemento;
}

template <class T>
void PilaGenerica<T>::limpiarPila()
{
    NodoPila *n;
    while (!pilaVacia())
    {
        n = cima;
        cima = cima->siguiente;
        delete n;
    }
}

int main(int, char **)
{

    PilaGenerica<int> pila1;
    PilaGenerica<int> pila2;
    PilaGenerica<int> pila3;
    PilaGenerica<int> pila4;
    PilaGenerica<int> pila5;
    
    int x = 1;
    int y = 0;
    int z;

    
    while (x != 0){
    
    cout << "Introduce un par de numero comprendidos entre 0 y 5" << endl;
    cout << "Valor 1:" << endl;
    cin >> x;

    
    cout << "Valor 2:" << endl;
    cin >> y;
    
    while (y > 5){
        cout<< "Lo sentimos, el valor 2 tiene que ser menor a 5."<<endl;
        cout<< "intentalo de nuevo. \n Valor 2: "<<endl;
        cout << "->" << endl;
        cin >> y;
    }

    cout << "Valor 3:" <<endl;
    cin >> z;

    if (z!=-1 || z !=0){
        cout<< "Lo sentimos, el valor 3 tiene que ser igual a 0 o -1"<<endl;
        cout<< "intentalo de nuevo. \n Valor 3: "<<endl;
        cin >> z;
    }
    if (z == -1){
        cout << "Borrando todo el contenido de todas las PILAS."<<endl;
        pila1.limpiarPila();
        pila2.limpiarPila();
        pila3.limpiarPila();
        pila4.limpiarPila();
        pila5.limpiarPila();
        cout << "Todo ha sido borrado exitosamente. "<<endl;
    
    }else{
    if (x > 0){
        if (y == 1){
            pila1.insertar(x);
            cout<< "\tIntroduciendo elemento " << x << " en pila 1." <<endl;
        }else if(y == 2){
            pila2.insertar(x);
            cout<< "\tIntroduciendo elemento " << x << " en pila 2." <<endl;
        }else if(y == 3){
            pila3.insertar(x);
            cout<< "\tIntroduciendo elemento " << x << " en pila 3." <<endl;

        }else if(y == 4){
            pila4.insertar(x);
            cout<< "\tIntroduciendo elemento " << x << " en pila 4." <<endl;

        }else if(y == 5){
            pila5.insertar(x);
            cout<< "\tIntroduciendo elemento " << x << " en pila 5." <<endl;

        }

    }else if(x < 0){
        if (y == 1){
            pila1.quitar();
            cout<<"Se ha eliminado el 1er elemento."<<endl;

        }else if(y == 2){
            for(int t = 1; t <= 2; ++t){
                pila2.quitar();
            }
            cout<<"Se ha eliminado el 2do elemento."<<endl;

        }else if(y == 3){
            for(int t = 1; t <= 3; ++t){
                pila3.quitar();
            }
    	    cout<<"Se ha eliminado el 3er elemento."<<endl;
        }else if(y == 4){
             for(int t = 1; t <= 4; ++t){
                pila4.quitar();
            }
    	    cout<<"Se ha eliminado el 4to elemento."<<endl;

        }else if(y == 5){
            for(int t = 1; t <= 5; ++t){
                pila5.quitar();
            }
    	    cout<<"Se ha eliminado el 5to elemento."<<endl;
            
        }
    }
    }
    }
    cout << "__________"<<endl;
    cout << "IMPRIMIENDO DATOS DE PILAS\n"<<endl;
    cout << "Pila1: "<< endl;
    pila1.imprimirPila();
    cout << "Pila 2: "<< endl;
    pila2.imprimirPila();
    cout << "Pila 3: "<< endl;
    pila3.imprimirPila();
    cout << "Pila 4: "<< endl;
    pila4.imprimirPila();
    cout << "Pila 5: "<< endl;
    pila5.imprimirPila();

    cout << "Fin del proceso"<< endl;
    

    
}