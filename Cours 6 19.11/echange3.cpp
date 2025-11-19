#include <iostream>
using namespace std;

void echange(int a, int b);

int main() {
    int i, j;
    char qt;

    do {
        cout << "Entrez deux entiers à échanger : ";
        cin >> i >> j;
        cout << "Avant : i = " << i << " et j = " << j << endl;
        echange(i, j);
        cout << "Avant : i = " << i << " et j = " << j << endl;         

        cout << "Continuer ? (q pour quitter) ";
        cin >> qt;
    } while (qt != 'q' && qt != 'Q');

    return 0;
}

void echange(int a, int b) {
    cout << "Avant : i = " << a << " et j = " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Après : i = " << a << " et j = " << b << endl;
}