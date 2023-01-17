// Cambiar el valor de 2 variables

#include <iostream>
using namespace std;

void Intercambio(float *,float *); // Prototipo

int main() {

    float n1 = 20.8;
    float n2 = 6.78;

    cout << "Primer número: " << n1 << endl;
    cout << "Segundo número: " << n2 << endl;

    Intercambio(&n1, &n2); // Hay que poner la dirección de memoria

    cout << "\n\nDespues del intercambio\n\n";
    cout << "Primer número: " << n1 << endl;
    cout << "Segundo número: " << n2 << endl;

    return 0;
}

void Intercambio(float *dirNum1, float *dirNum2) {
    float auxiliar;

    // INTERCAMBIAMOS LOS VALORES DE LAS VARIABLES
    auxiliar = *dirNum1;
    *dirNum1 = *dirNum2;
    *dirNum2 = auxiliar;

}