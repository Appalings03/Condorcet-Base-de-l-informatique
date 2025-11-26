#include <iostream>
using namespace std;

void signe(int n)
{
    if( n == 0) // Correction: vérifier si le nombre est nul
    {
        cout << "Le nombre est nul." << endl;
    }
    else if ( n > 0) // Correction: vérifier si le nombre est positif
    {
        cout << "Le nombre est positif." << endl;
    }
    else // Sinon, le nombre est négatif
    {
        cout << "Le nombre est négatif." << endl;
    }
}

int main() {
    int n;
    cout << "Entrez un réel : ";
    cin >> n;
    signe(n);
    return 0;
}
