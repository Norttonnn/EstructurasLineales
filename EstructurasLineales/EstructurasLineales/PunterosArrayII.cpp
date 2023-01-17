// Ejercicio: Rellena un array de 10 números y determina con punteros cuales son pares e impares además de indicar su posición de memoria. 



#include <iostream>
using namespace std;

int main() {
   
   int arreglo[10], *dirArreglo;

   for(int i = 0; i < 10; i++) {
    cout << "Introduce un número para la posición " << i << ": ";
    cin >> arreglo[i];
   }

   dirArreglo = arreglo; // le decimos que nuestra variable dirArreglo sea igual a la primera posicion de la variable arreglo que es un array

   
   for(int i = 0; i < 10; i++) {
        if(*dirArreglo%2 == 0) {
            cout << *dirArreglo++ << " Es par" <<  ".Su posición es: "<< dirArreglo << endl;
        } else {
            cout << *dirArreglo++ << " Es impar" << ".Su posición es: "<< dirArreglo << endl;
        }
    }   
    

    return 0;
}