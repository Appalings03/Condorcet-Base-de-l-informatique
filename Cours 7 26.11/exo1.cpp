#include <iostream>
#include <cmath>
#include <ciso646>

const double PI = acos(-1.0);

using namespace std;

int demander_nombre(int a = 2, int b = 85);
double factorielle(int k);
double somme_partielle(double x, int N);

int main()
{
    int N(demander_nombre());
 
    double x;
    cout.precision(16);
    do {
        cout << "entrez une valeur x pour le calcul de cos(x) : ";
        cin >> x;
        x=fmod(fabs(x), 2.0 * PI); // optionnel : garantit que x est dans [0; 2pi]
        cout << "cos(" << x << ") ~ " << somme_partielle(x, N) << endl;
    } while (x != 0.0);
    return 0;
}

double somme_partielle(double x, int N)
{
    double current_approx(0.0);  // approximation courante
    double powerx(1.0);          // puissance de x (initialisé à x^0=1)
 
    for (int i(0); i <= N; ++i) {
        if (i%2 != 0) {
            current_approx -= powerx / factorielle(i*2);
        } else {
            current_approx += powerx / factorielle(i*2);
        }
        powerx *= x*x; // powerx représente x^0, x^2, x^4, x^6, ..., x^2n
    }
    return current_approx;
}

double factorielle(int k)
{
    double fact(1.0);
    // k! = 1*2*..*k
    for (int i(2); i <= k; ++i) {
        fact *= i;
    }
    return fact;
}

int demander_nombre(int a, int b)
{
    int res;
 
    do {
      cout << "Entrez un nombre entier ";
      if (a >= b)
        cout << "supérieur ou égal à " << a;
      else
        cout << "compris entre " << a << " et " << b;
      cout << " : ";
      cin >> res;
    } while ((res < a) or ((a < b) and (res > b)));
 
   return res;
}
 
