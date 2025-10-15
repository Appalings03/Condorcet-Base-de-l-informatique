#include <iostream>
#include <iomanip>  // pour setw()
using namespace std;

int main() {
    int a, b;

    // 1️ Saisie et vérification
    do {
        cout << "Entrez un entier a (>0) : ";
        cin >> a;
    } while (a <= 0);

    do {
        cout << "Entrez un entier b (>0) : ";
        cin >> b;
    } while (b <= 0);

    cout << "\nCalcul du PGDC de " << a << " et " << b << endl;
    cout << setw(10) << "x" << setw(10) << "y" << setw(10) << "u" << setw(10) << "v" << endl;

    // 2️ Initialisation
    int x = a, y = b;
    int prev_u = 1, u = 0;
    int prev_v = 0, v = 1;

    // 3️ Boucle principale (algorithme d’Euclide étendu)
    while (y != 0) {
        int q = x / y;   // quotient
        int r = x % y;   // reste

        int new_u = prev_u - q * u;
        int new_v = prev_v - q * v;

        // affichage des valeurs de l'étape courante
        cout << setw(10) << y << setw(10) << r << setw(10) << new_u << setw(10) << new_v << endl;

        // mise à jour pour l’itération suivante
        x = y;
        y = r;
        prev_u = u;
        u = new_u;
        prev_v = v;
        v = new_v;
    }

    int pgdc = x; // le dernier x non nul
    cout << "\nPGDC(" << a << ", " << b << ") = " << pgdc << endl;

    // 4️ Vérification de l'identité de Bézout
    cout << "Equation de Bezout : "
         << prev_u << " * " << a << " + "
         << prev_v << " * " << b << " = "
         << pgdc << endl;

    return 0;
}
