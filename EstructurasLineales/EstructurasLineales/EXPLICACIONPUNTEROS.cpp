#include<iostream>
using namespace std;



int main() {

    int n = 28;
    int *puntero;

    puntero = &n;

    cout << "El número n: " << n << endl;
    cout << "Puntero apunta a la dirección de memoria: " << puntero << endl;
    cout << "También podemos llamar a través de: " << *puntero <<  endl;

    int numeros[3] = {2,3,7};
    int *punteroNumeros;
    punteroNumeros = numeros;


    for (int i = 0; i < 3; i++) {
        cout << "Vamos a mostrar los números: " << *(punteroNumeros+i) << endl;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Vamos a mostrar los espacios de memoria que ocupan: " << punteroNumeros+i << endl;
    }

    return 0;
}