#include <iostream>
using namespace std;

// CLASE TEMPLATE (T)
template <class T> {
private:
    T num1, num2;
public:
    Calculador(T n1, T n2); // METODO CONSTRUCTOR
};

T::T(T n1, T n2) { // DECLARACIÓN DEL CONSTRUCTOR
    num1 = n1;
    num2 = n2;
}

// DECLARACIÓN DE FUNCIONES
T Suma(Calculador());


int main() {





    return 0;
}

T Suma(Calculador()) {
    return num1 + num2;
}