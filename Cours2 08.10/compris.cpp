#include <iostream>
#include <ciso646>

using namespace std;

int main()
{
    int a, b;
    cout << "Entrez un entier a : ";
    cin >> a;
    cout << "Entrez un entier b : ";
    cin >> b;
    /*
        Visualiser les différentes signe conditionnels
        Tels que <, >, <=, >=, ==, !=
        ainsi que les opérateurs logiques
        Tels que && (et), || (ou), ! (non)
        /!\ n'arrive pas à compiler avec "and", "or", "not", ...  /!\
        nécessite la librairie #include <ciso646> pas pour Code::Blocks
    */
    if (a>=1 && a <=10 && b>=1 && b<=10)
        cout << "a et b sont compris entre 1 et 10" << endl;
    else if (a>=1 && a<=10)
        cout << "a est compris entre 1 et 10" << endl;
    else if (b>=1  && b<=10)
        cout << "b est compris entre 1 et 10" << endl;
    else
        cout << "a et b ne sont pas compris entre 1 et 10" << endl;
    return 0;
}