#include <iostream>
using namespace std;


struct Usuario {
   string nombre;
    int id;
}; 


int main() {
    
    Usuario *user = new Usuario[10];
    int maxID;

        user[0] = {"Alberto"};
        user[1] = {"Juan"};
        user[2] = {"Pepito"};
        user[3] = {"Damian"};
        user[4] = {"David"};
        user[5] = {"Jiale"};
        user[6] = {"Jaime"};

        for (int i = 0; i < 10; i++) {
            user[i].id = i;
            if (user[i].nombre.empty()) {
                i = 11;
            } else {
            cout << "Nombre: " << user[i].nombre << endl;
            cout << "ID: " << user[i].id << endl;
            maxID = user[i].id;
            }
        }

        
        cout << "El último ID es: " << maxID << endl;
        
       
        string name;
        int n;
        int posDelete;

        cout << "1 - Añadir usuario\n2 - Eliminar usuario";
        cin >> n;

        switch (n) {
        case 1: cout << "Has elegido 'Añadir usuario'\nIntroduce el nombre del usuario: ";
                cin >> name;
                cout << endl;
            break;
        
        case 2: cout << "\nHas elegido borrar 'Borrar usuario'\ntLista de usuarios: ";
                for (int i = 0; i < maxID+1; i++) {
                    cout << "("<< user[i].id << ")"<< user[i].nombre << " ";
                }

                cout << endl;
                
                cout << "Introduce el ID del usuario que quieras borrar: ";
                cin >> posDelete;

                Usuario almacen[10];

                 for (int i = posDelete; i < 9; i++) {
                    almacen[i] = user[i+1];
                    user[i] = user[i+1];
                    user[i+1] = almacen[i];
                }
            break;
        }


        user[maxID+1] = {name};

          for (int i = 0; i < 10; i++) {
            user[i].id = i;
            if (user[i].nombre.empty()) {
                i = 11;
            } else {
            cout << "Nombre: " << user[i].nombre << endl;
            cout << "ID: " << user[i].id << endl;
            }
        }

    delete [] user;


    return 0;
}