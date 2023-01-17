#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Tablero{
private:
    string tablero[3][3];
public:
    Tablero();
    ~Tablero();
    void RellenaTablero();
    void MostrarTablero();
    void JugadaP1();
    void JugadaP2();
    int Comprueba();
};

Tablero::Tablero(){} // CONSTRUCTOR
Tablero::~Tablero(){} // DESTRUCTOR

void Tablero::RellenaTablero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ".";
        }   
    }
}

void Tablero::MostrarTablero() {

    for(int i = 0 ; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            if(j != 2) {
                cout << " " <<  tablero[i][j] << " |"; 
            } else {
                cout << " " << tablero[i][j];
            }
        }
        if (i != 2) {
            cout << endl;
            cout << "--- --- ---"<<endl;
        }
    }
}

void Tablero::JugadaP1() {

    int fil,col;
    cout << "\nTurno del JUGADOR 1" << endl;
    cout << "Dame fila: "; cin >> fil;
    cout << "Dame columna: "; cin >> col;

   while((tablero[fil][col] == "x" || tablero[fil][col] == "o") || ( (fil < 0 || fil > 2) || (col < 0 || col > 2) )) {
        cout << "LA POSICIÓN NO ES VÁLIDA" << endl;
        
            cout << "Dame fila: "; cin >> fil;
            cout << "Dame columna: "; cin >> col;
    }

    tablero[fil][col] = "x";
    MostrarTablero();
}

void Tablero::JugadaP2() {

    int fil,col;
    cout << "\nTurno del JUGADOR 2" << endl;
    cout << "Dame fila: "; cin >> fil;
    cout << "Dame columna: "; cin >> col;
    while((tablero[fil][col] == "x" || tablero[fil][col] == "o") || ( (fil < 0 || fil > 2) || (col < 0 || col > 2) )) {
        cout << "LA POSICIÓN NO ES VÁLIDA" << endl;
        
            cout << "Dame fila: "; cin >> fil;
            cout << "Dame columna: "; cin >> col;
    }
    tablero[fil][col] = "o";
    MostrarTablero();
}

int Tablero::Comprueba() {

    int valor = 0;

    // COMPROBACIÓN DE JUGADAS HORIZONTALES
    if(tablero[0][0] == "x" && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]) {
        valor = 1;
    } else if(tablero[0][0] == "o" && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]) {
        valor = 2;
    }

    if(tablero[1][0] == "x" && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]) {
        valor = 1;
    } else if(tablero[1][0] == "o" && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]) {
        valor = 2;
    }

    if(tablero[2][0] == "x" && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]) {
        valor = 1;
    } else if(tablero[2][0] == "o" && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]) {
        valor = 2;
    }

    // COMPROBACIÓN DE JUGADAS VERTICALES
    if(tablero[0][0] == "x" && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]) {
        valor = 1;
    } else if(tablero[0][0] == "o" && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]) {
        valor = 2;
    }

    if(tablero[0][1] == "x" && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]) {
        valor = 1;
    } else if(tablero[0][1] == "o" && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]) {
        valor = 2;
    }

    if(tablero[0][2] == "x" && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]) {
        valor = 1;
    } else if(tablero[0][2] == "o" && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]) {
        valor = 2;
    }

    // COMPROBACIÓN DE JUGADA DIAGONAL
    if(tablero[0][0] == "x" && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) {
        valor = 1;
    } else if(tablero[0][0] == "o" && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) {
        valor = 2;
    }

    if(tablero[0][2] == "x" && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]) {
        valor = 1;
    } else if(tablero[0][2] == "o" && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]) {
        valor = 2;
    }

    return valor;

}





/**
 * Manual de juego TRES EN RAYA
 * Para poner una piece tienes que introducir la posición de la fila y de la columna siendo estas las siguientes:
 * 
 * ?     00 01 02     [fila][columna] [fila][columna] [fila][columna]
 * ?    10 11 12     [fila][columna] [fila][columna] [fila][columna]
 * ?    20 21 22     [fila][columna] [fila][columna] [fila][columna]
*/


int main() {
   Tablero t;
    t.RellenaTablero();
    t.MostrarTablero();
    for (int i = 0; i < 9; i++) {
        if(i%2 != 0) 
            t.JugadaP1();
        else 
            t.JugadaP2();

        if (t.Comprueba() == 1) {
            cout << "\nHa ganado el jugador 1" << endl;
            i = 10;
        } else if(t.Comprueba() == 2) {
            cout << "\nHa ganado el jugador 2" << endl;
            i = 10;
        }

        if(i == 8 && (t.Comprueba() >2 || t.Comprueba() < 1)) {
            cout << "\nEmpate!!!";
        }
    }
    return 0;
}