#include <iostream>
using namespace std;

struct Mochila { 
    string objeto;
    int cantidad;
};

int main() {

    // Creamos un array y lo rellenamos con lo que queramos
    Mochila *mochila = new Mochila[10];
    mochila[0] = {"Boligrafo", 3};
    mochila[1] = {"Estuche", 1};
    mochila[2] = {"Cascos", 1};

    int maxID; // Esta variable nos va a decir cuantos elementos tenemos en nuestra mochila

    for (int i = 0; i < 10; i++) {
        if(mochila[i].objeto.empty()) {
            i = 11;
        } else {
            cout << mochila[i].objeto << endl;
            maxID = i;
        }
    }

    int opcion;
    cout << "\n(1) METER OBJETOS EN LA MOCHILA\n(2) SACAR OBJETO DE LA MOCHILA\n(3) VER MOCHILA\n(4) Salir del programa " << endl; cin >> opcion;
    cout << endl;

    while (opcion >0 && opcion <4) {
         if (opcion == 1) {

            cout << "En la mochila tienes: " << endl;
            for (int i = 0; i < (maxID+1); i++) {
                cout << "\t" << mochila[i].objeto << endl;
            }
            int elige = 1;

            while (elige == 1) {
                cout << "¿Que quieres añadir? "; cin >> mochila[maxID+1].objeto;
                cout << "¿Cantidad? "; cin >> mochila[maxID+1].cantidad;
                maxID++;
                cout << "Te quedan " << (10-(maxID+1)) << " espacios" << endl;
                cout <<(10-(maxID+1)) << endl;

                if ((10-(maxID+1)) == 0) {
                    cout << "Se termina el programa" << endl; elige = 23;
                } else {
                    cout << "Si quieres seguir pulsa (1) | Si quieres parar pulsa (0) "; cin >> elige;
                }
            }
            
            cout << "\n(1) METER OBJETOS EN LA MOCHILA\n(2) SACAR OBJETO DE LA MOCHILA\n(3) VER MOCHILA\n(4) Salir del programa " << endl; cin >> opcion;




    } else if (opcion == 2) {

        string guardaObjeto;
        string almacen[10];
        int posDelete;
        int elige = 1;
        int contador = maxID;

        while (elige == 1){
            cout << "***EN TU MOCHILA TIENES***" << endl;
            for (int i = 0; i < 10; i++) {
                    if(mochila[i].objeto.empty()) {
                        i = 11;
                    } else {
                        cout << "\t" << mochila[i].objeto;
                        cout << " (" << mochila[i].cantidad << ")" <<endl;
                    }
                }

            cout << "Que objeto quieres eliminar "; cin >> guardaObjeto;
            for (int i = 0; i < maxID+1; i++) {
                if (guardaObjeto == mochila[i].objeto) {
                    posDelete = i;
                }   
            }

            for (int i = posDelete; i < maxID+1; i++) {
                    almacen[i] = mochila[i+1].objeto;
                    mochila[i].objeto = mochila[i+1].objeto;
                    mochila[i+1].objeto = almacen[i];
            }
            

            mochila[maxID].objeto = "";

            for (int i = 0; i < 10; i++) {
                if(mochila[i].objeto.empty()) {
                    i = 11;
                } else {
                    cout << mochila[i].objeto << endl;
                    maxID = i;
                }
            }

            
            cout << "CONTADOR: " <<contador << endl;
            

            if (contador == 0) {
                cout << "Mochila vacia" << endl; elige = 23;
                opcion = 4;
            } else {
                cout << "Si quieres seguir pulsa (1) | Si quieres parar pulsa (0) "; cin >> elige;
                contador--;
            }
        }

         cout << "\n(1) METER OBJETOS EN LA MOCHILA\n(2) SACAR OBJETO DE LA MOCHILA\n(3) VER MOCHILA\n(4) Salir del programa " << endl; cin >> opcion;

        } else if(opcion == 3) {

            cout << "***EN TU MOCHILA TIENES***" << endl;
        
            for (int i = 0; i < 10; i++) {
                    if(mochila[i].objeto.empty()) {
                        i = 11;
                    } else {
                        cout << "\t" << mochila[i].objeto;
                        cout << " (" << mochila[i].cantidad << ")" <<endl;
                    }
                }
            cout << "\n(1) METER OBJETOS EN LA MOCHILA\n(2) SACAR OBJETO DE LA MOCHILA\n(3) VER MOCHILA\n(4) Salir del programa " << endl; cin >> opcion;
        }
    } 
    

       
    
    
    
    
        


    return 0;
}