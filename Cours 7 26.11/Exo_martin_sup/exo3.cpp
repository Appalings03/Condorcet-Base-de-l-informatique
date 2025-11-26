#include <iostream>
using namespace std;

double moyenne(int n1, int n2, int n3)
{
    return (n1 + n2 + n3) / 3.0; // Division par 3.0 pour obtenir un résultat en double
}

int main() {
    int a, b, c;
    cout << "Entrez trois entiers : ";
    cin >> a >> b >> c;
    double m = moyenne(a, b, c);
    cout << "La moyenne est : " << m << endl;

    if (m >= 16) // Moyenne supérieure ou égale à 16
    {
        cout << "Excellent!" << endl;
    }
    else if (m >= 12 && m < 16) // Moyenne entre 12 et 16
    {
        cout << "Très bien!" << endl;
    }
    else if (m >= 10 && m < 12) // Moyenne entre 10 et 12
    {
        cout << "Bien!" << endl;
    }
    else // Moyenne inférieure à 10
    {
        cout << "Echec!" << endl;
    }
    
    return 0;
}
