// ajout de la librairie iostream (Utiliser pour le terminal)
#include <iostream>

// indique qu'on utilise la librairie standard
using namespace std;

// Définition de la fonction "main"
int main()
{
    // Cree une variable
    string nom;
    // Demande d'introduire une suite de char (Suite de "char" correspond a un "string", "char" correspond à un caractère)
    cout << "Entrez votre nom:" << endl;
    // regarde l'input de l'user
    cin >> nom;
    // display l'input de l'user
    cout << "Votre nom: " << nom << endl;
    // fin de programme
    return 0;   
}

