#include <iostream>
using namespace std;

int hallarMax(int *, int);

int main() {

    int nElementos = 3;
    int arreglo1[nElementos] = {2,23,3};


    // IMPRIMIMOS LOS ARRAYS
    for (int i = 0; i < nElementos; i++) {
        cout << arreglo1[i] << "  ";
    }    

    cout << "\nEl número más grande del array es: " << hallarMax(arreglo1, nElementos);

    return 0;
}

int hallarMax(int *arreglo, int n) {
    int top = 0;

    for (int i = 0; i < n; i++) {
        if(*(arreglo+i) > top) {
            top = *(arreglo+i);
        }
    }
    return top;
}