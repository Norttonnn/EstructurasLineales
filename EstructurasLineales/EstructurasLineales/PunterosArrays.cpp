#include <iostream>
using namespace std;

int main() {
    int numeros[] = {1, 3, 5, 7, 9};
    int *dirNumeros; // Creamos un puntero que señala al primer elemento del array

    dirNumeros = numeros; // Creamos una variables que almacena el espacio en memoria de los elementos del array

    //Recorremos el array
    for(int i = 0; i < 5; i++) {
        cout << "Elemento del vector [" << i << "]: " << *dirNumeros++ << endl;
    }

    cout << endl;

    // Recorremos los espacios de memoria del array
    for(int i = 0; i < 5; i++) {
        cout << "Posición de memoria " << numeros[i] << " es: " << dirNumeros++ << endl;
    }


    return 0;
}