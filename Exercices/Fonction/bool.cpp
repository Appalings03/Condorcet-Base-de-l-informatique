#include <iostream>
using namespace std;

bool non_et(bool A, bool B){
    return !(A && B);
}

bool non(bool A){
    return non_et(A, A);
}

bool et(bool A, bool B){
    return non(non_et(A,B));
}

bool ou(bool A, bool B){
    return non(et(non(A), non(B)));
}

int main()
{
    cout << boolalpha;

    cout << "Tests de la fonction non_et :" << endl;
    cout << "non_et(true, true) = " << non_et(true, true) << endl;
    cout << "non_et(true, false) = " << non_et(true, false) << endl;
    cout << "non_et(false, true) = " << non_et(false, true) << endl;
    cout << "non_et(false, false) = " << non_et(false, false) << endl;

    cout << "\nTests de la fonction non :" << endl;
    cout << "non(true) = " << non(true) << endl;
    cout << "non(false) = " << non(false) << endl;

    cout << "\nTests de la fonction et :" << endl;
    cout << "et(true, true) = " << et(true, true) << endl;
    cout << "et(true, false) = " << et(true, false) << endl;
    cout << "et(false, true) = " << et(false, true) << endl;
    cout << "et(false, false) = " << et(false, false) << endl;

    cout << "\nTests de la fonction ou :" << endl;
    cout << "ou(true, true) = " << ou(true, true) << endl;
    cout << "ou(true, false) = " << ou(true, false) << endl;
    cout << "ou(false, true) = " << ou(false, true) << endl;
    cout << "ou(false, false) = " << ou(false, false) << endl;

    return 0;
}   