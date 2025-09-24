// ajout de la librairie iostream (Utiliser pour le terminal)
#include <iostream>

// indique qu'on utilise la librairie standard
using namespace std;

// Définition de la fonction "main"
int main()
{
    // Cree une variable
    int age;
    // Demande d'introduire une valeur
    cout << "Entrez votre age:" << endl;
    // regarde l'input de l'user
    cin >> age;
    // display l'input de l'user
    cout << "Votre age: " << age << endl;
    // fin de programme
    return 0;   
}

