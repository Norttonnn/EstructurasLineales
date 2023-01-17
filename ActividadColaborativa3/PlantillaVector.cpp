#include <iostream>
using namespace std;

template<typename T> class VectorPEL
    {
        public:
        T   *v_,        // Puntero que apunta al inicio del vector
            *space_,    // Puntero que apunta al siguiente del ultimo elemento almacenado
            *last_;     // Puntero que apunta al siguiente bloque del ultimo elemento del vector
        public:
            //! CONSTRUCTORES
             VectorPEL(): v_{new T[0]}, space_{v_}, last_{v_} {} // Inicializar el constructor del vector a 0
             VectorPEL(VectorPEL<T> const& v): v_{new T[v.capacity()]}, space_{v_+ v.size()}, last_{v_ + v.capacity()} // Constructor copia
             { 
                try {
                    for(auto i = size_t{0}; i < v.size(); i++) { // El auto es decir que reconozca el tipo al que se iguala, es decir, es como poner size_t = size_t
                        v_[i] = v[i];
                    } 
                } catch(...) {
                    delete[] v_;
                    throw;
                }
             } 
             

             //! DESTRUCTOR
            ~VectorPEL() {delete[] v_;}

            //! MÉTODOS A DECLARAR
                //todo *** Size(); Capacity(); Begin(); End(); Empty(); ***
            
            //MÉTODOS DE ACCESO
            auto begin()    const -> T const*{return v_;}
            auto end()      const -> T const*{return space_;}


            //MÉTODOS DE CAPACIDAD
            auto size()     const -> size_t {return space_ - v_;}   //   MEJOR MANERA DE DECLARARLO
            auto capacity() const -> size_t {return last_ - v_;}
            auto empty()    const -> bool {return v_ == space_;}

            // MÉTODO PUSH_BACK
            
            void push_back(T const& valor) {
                if(space_ == last_) {
                    size_t cap = capacity(), new_cap = (cap == 0)?  2 : 2*cap; 

                    /* 
                        !Esto es lo mismo que lo de arriba pero en largo
                        size_t new_cap = size_t{0};
                        if(cap == 0) {
                            new_cap = 2;
                        } else {
                            new_cap = 2*cap;
                        }
                    */

                   T *new_block = new T[new_cap]; // Puntero auxiliar para apuntar al nuevo espacio de memoria

                    try {
                        for (auto i = size_t{0}; i < cap; ++i) {
                        new_block[i] = v_[i];
                        }
                        new_block[cap] = valor;
                    } catch (...) {
                        delete[] new_block;
                        throw;
                    }
                    delete[] v_;
                    v_ = new_block;
                    space_ = new_block + cap + 1;
                    last_ = new_block + new_cap;  
                } else {
                    *space_ = valor;
                    space_++;
                }
            }
    };

int main() {

    VectorPEL<int>* j = new VectorPEL<int>;
        j->push_back(3);
        j->push_back(7);
        // v->push_back(23);
        // v->push_back(32);
        // v->push_back(54);

        for(int elemento : *j) {
            cout << "Posición " << j << " : "<< elemento << endl;
        }
       
        cout << "El primer elemento del vector es: " << *j->begin() << endl;
        cout << "El último elemento del vector es: " << *j->end() << endl;


    
    cout << "El puntero v_ apunta a: " << j->v_ << endl;
    cout << "El puntero space_ apunta a: " << j->space_<< endl;
    cout << "El puntero last_ apunta a: " << j->last_ << endl;
    


    


        
    
    


    return 0;
}