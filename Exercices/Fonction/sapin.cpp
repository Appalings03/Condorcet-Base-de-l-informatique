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

void triangle(int n) {
    for(int i=1; i<=n; ++i) {
        espaces(n-i);
        etoiles(2*i-1);
        cout << endl;
    }
}

void sapin_simple(int n) {
    for(int i=1; i<=n; ++i) {
        triangle(i);
    }
}

void tronc(int n){
    espaces(n-1);
    cout << "|||" << endl;
}
