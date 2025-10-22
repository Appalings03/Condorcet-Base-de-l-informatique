#include <iostream>
#include <cmath>
using namespace std;

// Fonction à intégrer
double f(double x){
    return x*x;  // exemple : x^2
}

// Intégrale approchée
double integre(double a, double b, int n){
    double h = (b-a)/n;
    double somme = 0.0;
    for(int i=0; i<n; ++i){
        somme += f(a + i*h) * h;
    }
    return somme;
}

// Demande d’un réel
double demander_reel(string msg){
    double x;
    cout << msg;
    cin >> x;
    return x;
}

int main(){
    double a = demander_reel("Entrez borne a : ");
    double b = demander_reel("Entrez borne b : ");
    int n = 1000; // subdivisions
    cout << "Approximation de l'integrale : " << integre(a,b,n) << endl;
}
