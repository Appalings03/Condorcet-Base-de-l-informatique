#include <iostream>
using namespace std;

void ispair(int n)
{
    if( n%2 == 0) // Correction: vérifier si le nombre est pair
    {
        cout << "Le nombre est pair" << endl;
    }
    else // Sinon, le nombre est impair
    {
        cout << "Le nombre est impair." << endl;
    }
}

int main() {
    int n;
    cout << "Entrez un réel : ";
    cin >> n;
    ispair(n);
    return 0;
}
