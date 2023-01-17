#include <iostream>
using namespace std;

// DECLARACIÓN DE LO QUE VAMOS A NECESITAR
int fA,cA,fB,cB;

// DECLARACIÓN DE FUNCIONES
void menu();
int PideDimensiones();
void RellenaMatriz(int **M, int fil, int col); 
void ImprimeMatriz(int **M, int fil, int col);
void Sumar(int **A, int **B, int fil, int col);
void Restar(int **A, int **B, int fil, int col);
void Multiplicar(int **A, int **B, int fA, int cA,int cB);
void matrizTranspuesta(int **M, int fil, int col);




//MÉTODO PRINCIPAL DEL PROGRAMA 
int main() {

    // Dimensión de las matrices
    PideDimensiones();


    // Ahora queremos crear las matrices 
    int **A = new int *[fA];
    for( int i = 0; i < fA; i++ )
        A[i] = new int[cA];

    int** B = new int*[fB];
    for( int i = 0; i < fB; i++ )
        B[i] = new int[cB];

    // Ahora queremos rellenarla
    RellenaMatriz(A,fA, cA);
    RellenaMatriz(B,fB, cB);

    // LAS MOSTRAMOS
    cout << "\n***MATRIZ A***" << endl;
    ImprimeMatriz(A, fA, cA);
    cout << "\n***MATRIZ B***" << endl;
    ImprimeMatriz(B, fB, cB);


    // MENÚ CON EL QUE PODREMOS REALIZAR LAS OPERACIONES
    int opcion;
    do{
        menu();
        cin >> opcion;
        if( cin.fail() || cin.bad() ){
            opcion = 0;
            cin.clear();
            cin.ignore( '\n', 80 );
        }
 
        switch( opcion ){
            case 1: Sumar(A,B,fA,cA);
                break;
 
            case 2: Restar(A,B,fA,cA);
                break;
 
            case 3: 
                if (cA == fB) {
                    Multiplicar(A,B,fA,cA, cB);
                } else
                    cout << "\nCon estas dimensiones no se puede realizar. *REINICIA EL PROGRAMA Y ESCOGE LAS DIMENSIONES APROPIADAS\n";
                break;
 
            case 4: 
                int eleccion;
                while (eleccion <= 0 || eleccion > 3) {
                    cout << "(1) TRRANSPUESTA DE A | (2) TRANSPUESTA DE B | (3) TRANSPUESTA DE A Y TRANSPUESTA DE B "; cin >> eleccion;
                }
                
                if(eleccion == 1) {
                    matrizTranspuesta(A,fA,cA);
                } else if(eleccion == 2) {
                    matrizTranspuesta(B,fA,cA);
                }else {
                    cout << "\n***MATRIZ A***" << endl;
                    matrizTranspuesta(A,fA,cA);
                    cout << "\n***MATRIZ B***" << endl;
                    matrizTranspuesta(B,fB,cB);
                }

                eleccion = 5;

                break;
 
            case 5:
                cout << "\n\nFIN DEL PROGRAMA\n\n";
                break;
 
            default:
                cout << "\n\nOPCION NO VALIDA\n\n";
                break;
        }
 
    }while( opcion != 5 );

    return 0;
}




// MÉTODOS QUE FACILITAN LA REALIZACIÓN DE LAS OPERACIONES
int PideDimensiones() {

    int opcion;
    cout << "Dimensiones para sumar o restar (1) | Dimensiones para multiplicar (2) "; cin >> opcion;
    while (opcion <= 0 || opcion > 2) {
        cout << "Si quieres sumar o restar (1) | Si quieres multiplicar (2) "; cin >> opcion;
    }
    switch (opcion) {
        case 1:
            cout << "Dame FILA: "; cin >> fA;
            cout << "Dame COLUMNA: "; cin >> cA;

            // COMO LA SUMA Y LA RESTA SOLO SE PUEDE CON MATRICES DE IGUAL ORDEN
            fB = fA;
            cB = cA;

            break;
        case 2:
            cout << "Dame FILA A: "; cin >> fA;
            cout << "Dame COLUMNA A: "; cin >> cA;
            cout << "Dame COLUMNA B: "; cin >> cB;

            // PARA QUE SE PUEDA MULTIPLICAR LAS DIMENSIONES DELA COLUMNA DE LA MATRIZ 1 TIENE QUE SER IGUAL A LAS FILAS DE LA MATRIZ 2
            fB = cA;

            break;
    }

    return fA,cA,fB,cB;
}




void RellenaMatriz(int ** M, int fil, int col) {

    cout << "\nRellenar la matriz:\n";
    for( int i = 0; i < fil; i++ ){
        for( int j = 0; j < col; j++ ){
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
}




void ImprimeMatriz(int **M, int fil, int col) {
    for( int i = 0; i < fil; i++ ){
        cout << "\n| ";
        for( int j = 0; j < col; j++ )
            cout << M[i][j] << " ";
 
        cout << "|";
    }
    cout << endl;
}




void Sumar(int **A, int **B, int fil, int col) {

    int** C = new int*[fil];
    for( int i = 0; i < fil; i++ )
        C[i] = new int[col];

    for( int i = 0; i < fil; i++ )
        for( int j = 0; j < col; j++ )
            C[i][j] = A[i][j] + B[i][j];


    cout << "La suma de matrices da como resultado una matriz *C*: " << endl;
    ImprimeMatriz(C, fil, col);  
}




void Restar(int **A, int **B, int fil, int col) {

    int** C = new int*[fil];
    for( int i = 0; i < fil; i++ )
        C[i] = new int[col];

   for( int i = 0; i < fil; i++ )
        for( int j = 0; j < col; j++ )
            C[i][j] = A[i][j] - B[i][j];
    
    cout << "La resta de matrices da como resultado una matriz *C*: " << endl;
    ImprimeMatriz(C, fil, col);  

}




void Multiplicar(int **A, int **B, int fA, int cA,int cB) {

    int** C = new int*[fA];
    for( int i = 0; i < fA; i++ )
        C[i] = new int[cB];

        for( int i = 0; i < fA; ++i ){
            for( int j = 0; j < cB; ++j ){
                C[i][j] = 0;
                for( int z = 0; z < cA; ++z )
                    C[i][j] += A[i][z] * B[z][j];
            }
        }
    cout << "La multiplicación de matrices da como resultado una matriz *C*: " << endl;
    ImprimeMatriz(C, fA, cB);
}




void matrizTranspuesta(int **M,int fil, int col) {

    if (fil == col) {
        for( int i = 0; i < fil; i++ ) {
            cout << "\n| ";
            for( int j = 0; j < col; j++ ) {
                cout << M[j][i] << " ";
            }
            cout << " |";     
        }
              
    }

    if (fil != col) {
          for( int i = 0; i < col; i++ ) {
            cout << "\n| ";
            for( int j = 0; j < fil; j++ ) {
                cout << M[j][i];
            }
            cout << " |";    
        }
    }
}




void menu() {
    cout << "\n         CALCULADORA DE MATRICES"
         << "\n============================================"
         << "\n1.- Suma de Matrices ............. (Pulsa 1)"
         << "\n2.- Resta de Matrices ............ (Pulsa 2)"
         << "\n3.- Multiplicacion de Matrices ... (Pulsa 3)"
         << "\n4.- Matriz Transpuesta ........... (Pulsa 4)"
         << "\n5.- Terminar ..................... (Pulsa 5)"
         << "\n============================================"
         << "\nSELECCIONA UNA OPCION (1 - 5): ";
 
}










