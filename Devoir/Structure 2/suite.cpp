#include <iostream>
using namespace std;

int main()
{
    int debut(0);
    do {
        cout << "de (>= 1) ? ";
        cin >> debut;
    } while (debut < 1);

    int fin(0);
    do {
        cout << "a (>= " << debut << ") ? ";
        cin >> fin;
    } while (fin < debut);

    /*******************************************
     * Completez le programme a partir d'ici.
     *******************************************/
    // Pour chaque entier i de l'intervalle [debut, fin]
    for (int i = debut; i <= fin; ++i) {
        int n = i;
        int steps = 0;
        while (n != 0) {// Tant que n n'est pas nul
            if (n % 3 == 0) { // Si n est un multiple de 3
                n += 4; // on ajoute 4 a n
            } else if (n % 4 == 0) { // Sinon, si n est un multiple de 4
                n /= 2; // on divise n par 2
            } else { // Sinon (n n'est ni un multiple de 3 ni un multiple de 4) 
                --n; // on decremente n de 1
            }
            ++steps; // On incremente le compteur de pas
        }
        cout << i << " -> " << steps << endl;
    }
    /*******************************************
     * Ne rien modifier apres cette ligne.
     *******************************************/

    return 0;
}
