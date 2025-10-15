#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double g = 9.81; // accélération gravitationnelle (m/s²)
    double H0, eps, h_fin;

    // --- Saisie des données ---
    cout << "Hauteur initiale H0 (m) : ";
    cin >> H0;
    cout << "Coefficient de rebond eps (0 <= eps < 1) : ";
    cin >> eps;
    cout << "Hauteur finale h_fin (m) : ";
    cin >> h_fin;

    // --- Vérification des contraintes ---
    if (H0 <= 0 || eps < 0 || eps >= 1 || h_fin <= 0 || h_fin >= H0) {
        cout << "Erreur : valeurs incorrectes !" << endl;
        return 1;
    }

    // --- Simulation ---
    double h = H0;   // hauteur actuelle
    double v, v1, h1;
    int nbr = 0;     // compteur de rebonds

    do {
        v = sqrt(2 * g * h);      // vitesse avant rebond
        v1 = eps * v;             // vitesse après rebond
        h1 = (v1 * v1) / (2 * g); // hauteur atteinte après rebond

        nbr++;                    // un rebond de plus
        h = h1;                   // mise à jour de la hauteur

    } while (h > h_fin);

    cout << "\nNombre de rebonds avant d'atteindre " << h_fin << " m : " << nbr << endl;

    return 0;
}
