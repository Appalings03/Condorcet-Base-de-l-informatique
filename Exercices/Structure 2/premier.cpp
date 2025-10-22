#include <iostream>
#include <cmath>
#include <ciso646>
using namespace std;

int main() {
    int n;
    do {
        cout << "Entrez un entier n (>1) : ";
        cin >> n;
        if (n <= 1) {
            cout << "Erreur : n doit être strictement supérieur à 1." << endl;
        }
    } while (n <= 1);

    // Cas particulier : 2
    if (n == 2) {
        cout << n << " est premier." << endl;
        return 0;
    }

    // Si n est pair, il n'est pas premier
    if (n % 2 == 0) {
        cout << n << " n'est pas premier, car il est divisible par 2." << endl;
        return 0;
    }

    // Vérification des diviseurs impairs jusqu'à sqrt(n)
    bool premier = true;
    int diviseur;
    int limite = sqrt(n);

    for (int d = 3; d <= limite; d += 2) {
        if (n % d == 0) {
            premier = false;
            diviseur = d;
            break;
        }
    }
    // Alternative avec "and" 
    /*
    for (int i(3); (premier) and (i <= limite); i += 2){
        if (n % i == 0){
            premier = false;
            diviseur = i;
        }
    }
    */

    if (premier)
        cout << n << " est premier." << endl;
    else
        cout << n << " n'est pas premier, car il est divisible par " << diviseur << "." << endl;

    return 0;
}
