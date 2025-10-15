#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double g = 9.81; // accélération gravitationnelle (m/s²)
    double H0, eps;
    int nbr;

    // --- Saisie des données ---
    cout << "Hauteur initiale H0 (m) : ";
    cin >> H0;
    cout << "Coefficient de rebond eps (0 <= eps < 1) : ";
    cin >> eps;
    cout << "Nombre de rebonds nbr (>= 0) : ";
    cin >> nbr;

    // --- Vérification des contraintes ---
    if (H0 <= 0 || eps < 0 || eps >= 1 || nbr < 0) {
        cout << "Erreur : valeurs incorrectes !" << endl;
        return 1;
    }

    double h = H0;  // hauteur de départ
    double v, v1, h1;

    // --- Simulation des rebonds ---
    for (int i = 1; i <= nbr; ++i) {
        v = sqrt(2 * g * h);      // vitesse avant rebond
        v1 = eps * v;             // vitesse après rebond
        h1 = (v1 * v1) / (2 * g); // nouvelle hauteur
        h = h1;                   // mise à jour pour le prochain rebond
    }

    cout << "\nHauteur après " << nbr << " rebonds : " << h << " m" << endl;
    return 0;
}