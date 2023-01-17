#include <iostream>
using namespace std;

int main() {

    int n, *dir;
    n = 7;
    dir = &n;

    cout << "Variable 'n' -> " << n << endl;
    cout << "La variable dir lleva a la dirección de memoria de 'n' -> " << dir << endl;
    cout << "El puntero *dir lleva al espacio de memoria donde esta 'n' y muestra lo que hay en ella -> " << *dir << endl;

    return 0;
}