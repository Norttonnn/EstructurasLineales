#include <iostream>
using namespace std;

// &variable = Dirección de memoria de la variable
// *variables = La variable cuya dirección esta almacenada en dicha variables 


int main() {
    int n;
    int j;
    int *dir;

    n = 20;
    j = 32;
    dir = &j; // Esto es lo que marca a donde apunta el puntero


    cout << "Número: " << *dir << endl;
    cout << "Dirección de memoria: "<< dir << endl;
    return 0;
}