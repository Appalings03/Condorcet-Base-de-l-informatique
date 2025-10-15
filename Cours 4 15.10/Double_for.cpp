#include <iostream>

using namespace std;

int main()
{
    // Affiche 10 lignes de 10 chiffres (de 0 à 10)
    int sizei(10);
    int sizej(10);
    
    for (int i = 0; i <= sizei; i++)
    {
        cout << "Ligne " << i << " : ";
        for (int j = 0; j <= sizej; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
}