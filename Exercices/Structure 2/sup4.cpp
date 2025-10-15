#include <iostream>
using namespace std;

int main() {
    for (int ligne = 1; ligne <= 9; ++ligne) {
        // espaces avant les chiffres
        for (int espace = 1; espace <= 9 - ligne; ++espace) {
            cout << " ";
        }
        // affichage des chiffres
        for (int i = 1; i <= ligne; ++i) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
