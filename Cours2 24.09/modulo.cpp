// ajout de la librairie iostream (Utiliser pour le terminal)
#include <iostream>

// indique qu'on utilise la librairie standard
using namespace std;

// Définition de la fonction "main"
int main()
{
    // Cree une variable
    int n1, n2;
    //cout << n1%n2;
    cout << "Entrez 2 nombres: " << endl;
    cin >> n1 >> n2;
    /*
        11 % 4
        <=>
        11 = 4*2 +3
        Avec 3 étant le restant
    */
    // fin de programme
    cout << n1%n2;
    return 0;   
}
