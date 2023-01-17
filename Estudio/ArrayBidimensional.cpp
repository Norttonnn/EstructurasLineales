#include <iostream>
using namespace std;

int main() {

    int filas, columnas;
    filas = 3;
    columnas = 3;

    int** A = new int*[filas]; // Creas dos punteros. Uno que apunta a las filas y otro a las columnas
    for(int i = 0; i < filas; i++ )
        A[i] = new int[columnas];


    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Posición: [" << i << "][" << j << "] "; 
        }  
        cout << endl;
    }
    return 0;
}