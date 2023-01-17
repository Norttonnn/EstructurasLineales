#include <iostream>
using namespace std;

struct X {
    int i;
    X(int ii) : i{ii} { cout << "Construct X object #" << i << "\n"; }
     ~X() { cout << "Destruct X objetc #" << i << "\n" ;}
};


auto main() -> int {
    auto a = X{1};
    auto b = X{2};
    X* p = new X{3};
    static auto c = X{4};
    // . . .
    delete p;
    cout << "Exiting main function \n";
} //(F)