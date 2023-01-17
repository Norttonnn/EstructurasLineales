#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

char nombreUsuario[30];

void PedirNombre();
void MostrarNombre();
int ContarVocales(char *);


int main() {

    PedirNombre();
    MostrarNombre();
    cout << "El número de vocales es : " << ContarVocales(nombreUsuario);

    return 0;
}

void PedirNombre() {

    cout << "Dame tu nombre: ";
    cin.getline(nombreUsuario,30,'\n');
}

void MostrarNombre() {

    cout << endl;


    for (int i = 0; i < 30; i++)    {
        nombreUsuario[i] = toupper(nombreUsuario[i]);
        cout << nombreUsuario[i];
    }
    
    cout << endl;
}

int ContarVocales(char *nombre) {
    int contador = 0;
    while (*nombre) { // Mientras nombre no sea nulo
         switch (*nombre) {
            case 'A': case 'E': case 'I': case 'O': case 'U': contador++;
            }
        nombre++;
    }
    

    return contador;
}

