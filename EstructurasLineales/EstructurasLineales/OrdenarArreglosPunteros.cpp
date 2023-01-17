#include <iostream>
using namespace std;

void pedirDatos();
void mostrarDatos();
void ordenarDatos(int, int *);

int nElementos;
int *elementos; // Este es el puntero que va a apuntar al primer elemento del array que vamos a crear

int main() {

    pedirDatos();
    mostrarDatos();
    ordenarDatos(nElementos, elementos);
    cout << "\nDatos ordenados\n";
    mostrarDatos();

    return 0;
}

void pedirDatos() {

    cout << "Dime cuantos números tiene tu array: ";
    cin >> nElementos;

    elementos = new int [nElementos]; // Creación del array dínamico

    for (int i = 0; i < nElementos; i++) {
        cout << "Cita el elemento " << i << ": ";
        cin >> *(elementos+i); // Esto es como elementos[i] 
    }
}

void mostrarDatos() {
     for (int i = 0; i < nElementos; i++) {
        cout << *(elementos+i) << " " ;
    }
}

void ordenarDatos(int nElementos, int *elemento) {
    int aux;

    for (int i = 0; i < nElementos; i++) {
        for (int j = 0; j < nElementos-1; j++) {
            if (*(elementos+j) > *(elementos+j+1)) { // elemento[j] > elemento[j+1]
                aux = *(elemento+j);
                *(elemento+j) = *(elemento+j+1);
                *(elemento+j+1) = aux;
            }
        }  
    }
}