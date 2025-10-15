#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Entrez le nombre de lignes : ";
    cin >> n;

    for (int ligne = 1; ligne <= n; ++ligne) {
        // espaces avant les étoiles
        for (int espace = 1; espace <= n - ligne; ++espace) {
            cout << " ";
        }
        // étoiles : 2*ligne - 1 pour former un triangle isocèle
        for (int etoile = 1; etoile <= 2 * ligne - 1; ++etoile) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
