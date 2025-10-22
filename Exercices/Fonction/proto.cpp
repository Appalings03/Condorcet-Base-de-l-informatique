#include <iostream>
using namespace std;

int demander_nombre() {
    int n;
    cout << "Entrez un nombre : ";
    cin >> n;
    return n;
}

int main() {
    int x = demander_nombre();
    cout << "Vous avez entré : " << x << endl;
    return 0;
}
