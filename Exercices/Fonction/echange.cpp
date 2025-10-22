#include <iostream>
using namespace std;

// passer par référence pour échanger les valeurs
void echange(int a, int b) {
    int temp(a);
    a = b;
    b = temp;
}

int main() {
    int i = 10, j = 55;
    cout << "Avant: i=" << i << " et j=" << j << endl;
    echange(i,j);
    cout << "Après: i=" << i << " et j=" << j << endl;
    return 0;
}
