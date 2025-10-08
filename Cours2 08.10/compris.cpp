#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Entrez un entier a : ";
    cin >> a;
    cout << "Entrez un entier b : ";
    cin >> b;
    if (a>=1 && a <=10  && b>=1  && b<=10)
        cout << "a et b sont compris entre 1 et 10" << endl;
    else if (a>=1 && a<=10)
        cout << "a est compris entre 1 et 10" << endl;
    else if (b>=1  && b<=10)
        cout << "b est compris entre 1 et 10" << endl;
    else
        cout << "a et b ne sont pas compris entre 1 et 10" << endl;
    return 0;
}