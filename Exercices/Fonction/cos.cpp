#include <iostream>
#include <cmath>

using namespace std;

double factorielle(int k);
double somme_partielle(double x, int N);

int main() {
    int N;
    double x;
    cout << "Entrez le nombre de termes N (<=85) : ";
    cin >> N;
    cout << "Entrez x : ";
    cin >> x;
    cout.precision(12);
    cout << "cos(" << x << ") ≈ " << somme_partielle(x,N) << endl;
}

double somme_partielle(double x, int N) {
    double somme = 0.0;
    for(int n=0; n<=N; ++n)
        somme += pow(-1,n) * pow(x,2*n) / factorielle(2*n);
    return somme;
}

double factorielle(int k) {
    double f = 1.0;
    for(int i = 1; i <= k; ++i)
        f *= i;
    return f;
}
