/*
New: reserva el número de bytes
Delete: libera un bloque de bytes reservado con anterioridad
*/


#include <iostream>
#include <stdlib.h> // Funciona new y delete

using namespace std;

void MostrarNotas();
void PedirNotas();
int notas, *calificacion;




int main() {

    PedirNotas();
    MostrarNotas();

    delete[] calificacion; // Eliminando el espacio en bytes utilizado anteriormente

    return 0;
}

void PedirNotas() {

    cout << "Digite el número de notas: ";
    cin >> notas;

    calificacion = new int [notas];

    for(int i = 0; i < notas; i++) {
        cout << "Ingresa la nota: ";
        cin >> calificacion[i];
    }
    

}

void MostrarNotas() {
    cout << "\n\nMostrando las notas del usuario \n\n";
    for (int i = 0; i < notas; i++) {
        cout << calificacion[i] << endl;
    }
    
    
}