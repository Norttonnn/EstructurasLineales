/*
Una discográfica, recientemente ha decidido actualizar sus sistemas informáticos, 
pasando  a  almacenar  todos  los  álbumes  con  la  información  correspondiente  al  
titulo del álbum, grupo al que pertenece y género musical que los representa.  
Dicho programa, debe tener un sistema de búsquedas, que muestre por consola 
los  resultados  de  buscar,  ya  sea  el  grupo,  el  título  o  el  género.  En  caso  de  no  
encontrarlo se mostrará un mensaje por pantalla que indique que no se ha podido 
encontrar el álbum. 
Para  realizar  dicho  proyecto,  los  álbumes  se  almacenarán  en  un  vector,  y  debe  
manejarse las búsquedas mediante estos.  */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Struct de nombre ALBUM el cual almacenará datos de tipo string en las variables título, grupo y género.
struct Album {
    string titulo;
    string grupo;
    string genero;
}; 

vector<Album> albums;


int main() {

    cout << "(1) VER ALBUMS"


    albums.push_back({"Feo" , "Fuerte" , "Formal"});
    albums.push_back({"Guapo" , "Gordo" , "Gamba"});
    albums.push_back({"Tonto" , "Tarao" , "Tortelini"});

    for(int i = 0 ; i < albums.size() ; i++) {
        cout << "ALBUM " << i << endl;
        cout << "Titulo: " << albums[i].titulo << endl;
        cout << "Grupo: " << albums[i].grupo << endl;
        cout << "Genero: " << albums[i].genero << endl;

        cout << endl; 
    }








    return 0;
}






/*
vector<int> vectorcillo = { 1, 2, 3 }; //! El vector no especifica nunca cuanto tienes que añadir. Puedes añadir todo lo que quieras
    
    cout << "BEFORE PUSHBACK" << endl;
    cout << "El tamaño es: " << vectorcillo.size() << endl;
    cout << vectorcillo[3] << endl; //? Si lanzamos un cout de una posición que no existe sale 0
    vectorcillo.push_back(123); //! Con el push back lo que hacemos es añadir cosillas detras
    cout << "El tamaño es: " << vectorcillo.size() << endl;
    cout << "AFTER PUSHBACK" << endl;

    cout << vectorcillo[0] << endl;
    cout << vectorcillo[1] << endl;
    cout << vectorcillo[2] << endl;
    cout << vectorcillo[3] << endl;
*/