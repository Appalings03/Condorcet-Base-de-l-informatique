#include <iostream>
using namespace std;

void etoiles(int nb_etoiles){
    for(int i=0; i<nb_etoiles; ++i)
        cout << '*';
}

void espaces(int nb_espaces){
    for(int i=0; i<nb_espaces; ++i)
        cout << ' ';
}

// Affiche un triangle de "niveau" lignes, centré sur "base"
void triangle(int niveau, int base) {
    for (int i = 1; i <= niveau; ++i) {
        espaces(base - i);
        etoiles(2 * i - 1);
        cout << endl;
    }
}

void tronc(int n, string caractere=" *") {
    espaces(n - 2);
    cout << caractere << endl;
}

void sapin_simple(int sections) {
    int base_max = 2 * sections + 1; // largeur maximale pour le dernier triangle

    for (int s = 1; s <= sections; ++s) {

        // Puis un triangle de taille s+1 (section tronquée)
        triangle(s + 1, base_max);
    }
    tronc(base_max);
}

// Affiche un triangle de "lignes" avec largeur initiale "start"
// Chaque ligne ajoute 2 étoiles, centré sur base_max
void triangle_custom(int start, int lignes, int base_max) {
    int nb_etoiles = start;
    for (int i = 0; i < lignes; ++i) {
        espaces(base_max - nb_etoiles / 2 - 1);
        etoiles(nb_etoiles);
        cout << endl;
        nb_etoiles += 2;
    }
}

// Affiche le sapin exact pour n sections
void sapin_exact(int n) {
    // Largeur maximale du sapin = dernière ligne du dernier triangle
    int base_max = 2 * (2 * n - 1) + 1;

    for (int s = 0; s < n; ++s) {
        int start = 1 + 2 * s;    // largeur de départ du premier triangle de la section
        triangle_custom(start, 3, base_max);
    }

    tronc(base_max, "|||");
}

int main() {
    int n;
    cout << "Entrez la hauteur du sapin : ";
    cin >> n;

    sapin_simple(n);
    cout <<"========================================="<< endl;
    sapin_exact(n);

    return 0;
}
