// ajout de la librairie iostream (Utiliser pour le terminal)
#include <iostream>

// indique qu'on utilise la librairie standard
using namespace std;

// Définition de la fonction "main"
int main()
{
    // Cree une variable
    int note1, note2;
    cout << "Entrez 2 notes : "<<endl;
    cin >> note1  >> note2; 
    int moyenne = note1 + note2;
    moyenne /=2;
    cout << "La moyenne entière est de " << moyenne << endl;

    double moyenneR = note1 + note2;
    moyenneR /= 2;

    cout << "La moyenne réel est de " << moyenneR << endl;

    // fin de programme
    return 0;   
}
