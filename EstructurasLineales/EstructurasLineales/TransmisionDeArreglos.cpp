/* Transmisión de arreglos

Ejemplos: Hallar el máximo elemento de un arreglo. */

#include <iostream>
using namespace std;

int hallarMax(int *,int); // Prototipo de Función

int main() {

    const int nElementos = 5;
    int numeros[nElementos] = {3,5,2,8,1};

    cout << "El mayor elemento del Array es: " << hallarMax(numeros, nElementos);

    return 0;
}

int hallarMax(int *dirVec, int nElementos) {
    int max = 0;

    for(int i = 0; i < nElementos; i++) {
        if(*(dirVec+i)>max) {
            max = *(dirVec+i);
        }
    }
    return max;
}