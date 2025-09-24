// ajout de la librairie iostream (Utiliser pour le terminal)
#include <iostream>

// indique qu'on utilise la librairie standard
using namespace std;

// Définition de la fonction "main"
int main()
{
    // Cree une variable
    int n1(1);
    double n2(2.0);
    cout << n1/n2;
    /*
        int / int = division entière, donc pas de virgule
        int / double = division normale
    */
    // fin de programme
    return 0;   
}

