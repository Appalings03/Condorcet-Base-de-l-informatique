#include <iostream>
#include <iomanip> // pour setprecision()
#include <cmath>   // pour fabs() et round()
using namespace std;

int main()
{
    // Réduire le format d'affichage
    cout << setprecision(4);

    // Paramètres
    double taux_croissance_lapins(0.3);
    double taux_attaque(0.01);
    double taux_croissance_renards(0.008);
    double taux_mortalite(0.1);
    int duree(50);

    double renards_i(0.0);
    double lapins_i(0.0);

    /*****************************************************
     * Compléter le code à partir d'ici
     *****************************************************/

    // ===== PARTIE 1 =====
    // Saisie des populations initiales

    do {
        cout << "Combien de renards au départ (>= 2) ? ";
        cin >> renards_i;
    } while (renards_i < 2);

    do {
        cout << "Combien de lapins au départ  (>= 5) ? ";
        cin >> lapins_i;
    } while (lapins_i < 5);

    // ===== PARTIE 2 =====
    // Première simulation
    // initialiser les populations avec les valeurs saisies
    double renards(renards_i);
    double lapins(lapins_i);

    cout << endl
         << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;

    for (int mois = 1; mois <= duree; ++mois) {
        // calculs selon les formules données
        double lapins_suiv = lapins * (1.0 + taux_croissance_lapins - taux_attaque * renards);
        double renards_suiv = renards * (1.0 + taux_attaque * lapins * taux_croissance_renards - taux_mortalite);

        // empêcher les populations d'être négatives
        if (lapins_suiv < 0.0) lapins_suiv = 0.0;
        if (renards_suiv < 0.0) renards_suiv = 0.0;

        // mise à jour des populations
        lapins = lapins_suiv;
        renards = renards_suiv;

        // affichage du résultat du mois courant
        cout << "Après " << mois << " mois, il y a " << lapins << " lapins et " << renards << " renards" << endl;
    }

    // ===== PARTIE 3 =====
    // Variation du taux d'attaque
    cout << endl;

    // Demander taux d'attaque initial (en %)
    double taux_deb_percent;
    do {
        cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
        cin >> taux_deb_percent;
    } while (taux_deb_percent < 0.5 || taux_deb_percent > 6.0);

    // Demander taux d'attaque final (en %), strictement supérieur au départ et <= 6
    double taux_fin_percent;
    do {
        cout << "taux d'attaque à la fin en % (entre " << taux_deb_percent << " et 6) ? ";
        cin >> taux_fin_percent;
    } while (taux_fin_percent <= taux_deb_percent || taux_fin_percent > 6.0);

    // Boucle sur les taux d'attaque (en %), pas inclus le taux final, incrément de 1%
    for (double taux_p = taux_deb_percent; taux_p < taux_fin_percent; taux_p += 1.0) {
        // affichage du taux (sans décimales si entier)
        cout << endl;
        cout << "***** Le taux d'attaque vaut ";
        if (fabs(taux_p - round(taux_p)) < 1e-9)
            cout << static_cast<int>(round(taux_p));
        else
            cout << taux_p;
        cout << "%" << endl;

        double taux_attaque_iter = taux_p / 100.0;

        // initialiser les populations avec les valeurs saisies
        double renards(renards_i);
        double lapins(lapins_i);

        // flags pour événements
        bool renards_danger = false;
        bool renards_recovered = false;
        bool renards_disappeared = false;

        bool lapins_danger = false;
        bool lapins_recovered = false;
        bool lapins_disappeared = false;

        int mois_ecoules = 0;

        for (int mois = 1; mois <= duree; ++mois) {
            // calculs selon les formules données
            double lapins_suiv = lapins * (1.0 + taux_croissance_lapins - taux_attaque_iter * renards);
            double renards_suiv = renards * (1.0 + taux_attaque_iter * lapins * taux_croissance_renards - taux_mortalite);

            // empêcher les populations d'être négatives
            if (lapins_suiv < 0.0) lapins_suiv = 0.0;
            if (renards_suiv < 0.0) renards_suiv = 0.0;

            // vérifier danger (< 5)
            if (lapins_suiv < 5.0) lapins_danger = true;
            if (renards_suiv < 5.0) renards_danger = true;

            // vérifier remontée (> 5) si auparavant en danger
            if (lapins_danger && lapins_suiv > 5.0) lapins_recovered = true;
            if (renards_danger && renards_suiv > 5.0) renards_recovered = true;

            // disparition si passe en dessous de 2 -> mis à zéro immédiatement
            if (lapins_suiv < 2.0) {
                lapins_suiv = 0.0;
                lapins_disappeared = true;
            }
            if (renards_suiv < 2.0) {
                renards_suiv = 0.0;
                renards_disappeared = true;
            }

            // mise à jour
            lapins = lapins_suiv;
            renards = renards_suiv;

            mois_ecoules = mois;

            // arrêter si les deux sont nuls
            if (lapins == 0.0 && renards == 0.0) break;
        }

        // affichage du résultat final pour ce taux
        cout << "Après " << mois_ecoules << " mois, il y a " << lapins << " lapins et " << renards << " renards" << endl;

        // messages d'alerte
        // ordre : renards puis lapins (conforme aux exemples)
        if (renards_danger) {
            cout << "Les renards ont été en voie d'extinction" << endl;
            if (renards_recovered) cout << "mais la population est remontée ! Ouf !" << endl;
            if (renards_disappeared) cout << "et les renards ont disparu :-(" << endl;
        }

        if (lapins_danger) {
            cout << "Les lapins ont été en voie d'extinction" << endl;
            if (lapins_recovered) cout << "mais la population est remontée ! Ouf !" << endl;
            if (lapins_disappeared) cout << "et les lapins ont disparu :-(" << endl;
        }

        // si aucun événement pour les deux espèces
        if (!renards_danger && !lapins_danger) {
            cout << "Les lapins et les renards ont des populations stables." << endl;
        }
    }

    /*******************************************
     * Ne rien modifier après cette ligne.
    *******************************************/

    return 0;
}
