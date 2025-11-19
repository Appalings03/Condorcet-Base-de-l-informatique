#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S0, r, ir;

    // --- Saisie des données ---
    cout << "Montant du prêt initial S0 (en euros) : ";
    cin >> S0;
    cout << "Remboursement mensuel r (en euros) : ";
    cin >> r;
    cout << "Taux d'intérêt mensuel ir (entre 0 et 1) : ";
    cin >> ir;

    // --- Vérification de validité ---
    if (S0 <= 0 || r <= 0 || ir <= 0 || ir >= 1) {
        cout << "Erreur : valeurs incorrectes !" << endl;
        return 1;
    }

    double S = S0;        // montant restant à rembourser
    double interets = 0;  // somme totale des intérêts
    int mois = 0;         // compteur de mois
    cout << "mois" << "\t\t" << "pret" << "\t\t" << "interets" << endl;
    // --- Remboursement ---
    while (S > 0) {
        double i = ir * S;     // intérêt du mois
        interets += i;         // ajout à la somme totale
        S = S - r;             // nouveau solde après paiement
        mois++;

        if (S < 0) S = 0; // éviter une valeur négative finale
        cout << mois << "\t\t" << S << "\t\t" << interets << endl;
    }

    cout << "\nDurée du remboursement : " << mois << " mois" << endl;
    cout << "Somme totale des intérêts encaissés : " << interets << " euros" << endl;

    return 0;
}
