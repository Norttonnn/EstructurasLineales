#include <iostream>
using namespace std;

int main() {

    int *puntero;
    puntero = new int[3];
    puntero[0] = 1;
    puntero[1] = 2;
    puntero[2] = 3;

    // RECORREMOS LAS POSICIONES
    for (int i = 0; i < 3; i++) {
        cout << *puntero++ << " ";
    }

    // RECORREMOS LOS ESPACIOS DE MEMORIA
    for (int i = 0; i < 3; i++) {
        cout << "\n" << puntero++;
    }
    
    

    return 0;
}