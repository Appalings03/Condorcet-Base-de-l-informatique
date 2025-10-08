#include <iostream>
using namespace std;

int main()
{
    cout << "Donnez l'heure de début de la location (un entier) : ";
    int debut;
    cin >> debut;

    cout << "Donnez l'heure de fin de la location (un entier) : ";
    int fin;
    cin >> fin;

    /*****************************************************
     * Compléter le code à partir d'ici
     *****************************************************/
    if (debut < 0 || debut > 24 || fin < 0 || fin >24)
        cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    else if (debut == fin)
        cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    else if (debut > fin)
        cout << "Bizarre, le début de la location est après la fin ..." << endl;
    else
    {
        int heures_tarif1 = 0;
        int heures_tarif2 = 0;
        
        for (int h = debut; h < fin; h++) 
        {
            if ((h >= 0 && h < 7) || (h >= 17 && h < 24)) {
                heures_tarif1++;
            } else {
                heures_tarif2++;
            }
        }

        cout << "Vous avez loué votre vélo pendant" << endl;
        
        if (heures_tarif1 > 0 && heures_tarif2 > 0) {
            cout << heures_tarif1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
            cout << heures_tarif2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
        } else if (heures_tarif1 > 0) {
            cout << heures_tarif1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
        } else {
            cout << heures_tarif2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
        }

        int total = heures_tarif1 + (heures_tarif2 * 2);
        cout << "Le montant total à payer est de " << total << " franc(s)." << endl;
    }
    /*******************************************
     * Ne rien modifier après cette ligne.
     *******************************************/
return 0;
}
