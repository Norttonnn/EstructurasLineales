#include <iostream>
using namespace std;

template <class T> T GetMax(T a, T b) {
    T result;
    result = (a>b)? a : b;
    return result;
}

int main() {

    int x = 5, y = 10, z;
    long a = 1, b = 3, c;

    z = GetMax<int>(x,y);   cout << "El mayor es: " << z << endl;
    c = GetMax<long>(a,b);  cout << "El mayor es: " << c << endl;

    

   

    return 0;
}