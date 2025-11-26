#include <iostream>
#include <cmath>
using namespace std;

// Constante pour l'approximation de la dérivée
const double epsilon = 1e-6;

// Fonction à résoudre f(x) = 0
double f(double x) {
    return (x - 1.0) * (x - 1.5) * (x - 2.0);
}

// Dérivée approximative de f
double df(double x) {
    return (f(x + epsilon) - f(x)) / epsilon;
}

int main() {
    double x;   // point de départ
    cout << "Point de depart ? ";
    cin >> x;

    double xn = x;
    double xn1;  // nouveau point
    double tol = 1e-8; // tolérance pour arrêter l'itération

    int iter = 0;
    do {
        double fx = f(xn);
        double dfx = df(xn);
        xn1 = xn - fx / dfx;  // méthode de Newton

        cout.precision(8);
        cout << "Au point " << xn << " :" << endl;
        cout << "f(x) = " << fx << endl;
        cout << "f'(x) = " << dfx << endl;
        cout << "nouveau point = " << xn1 << endl << endl;

        if (fabs(xn1 - xn) < tol) break; // condition d'arrêt

        xn = xn1;
        iter++;
        if(iter > 1000){ // sécurité pour éviter boucle infinie
            cout << "La méthode ne converge pas." << endl;
            return 1;
        }

    } while (true);

    cout << "Solution : " << xn1 << endl;
    return 0;
}
