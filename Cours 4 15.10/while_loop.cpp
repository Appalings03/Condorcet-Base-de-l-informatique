#include <iostream>

using namespace std;

int main()
{
    /*
    Exercice : Ecrire un programme qui demande à l'utilisateur de saisir un nombre de pompes à faire (entre 10 et 20).
    */  
    int pompe = 0; // Initialisation de la variable pompe
    // demande un nombre de pompe entre 10 et 20
    while (pompe < 10 || pompe > 20)
    {
        cout << "Entrez un nombre de pompe a faire (|e| 10 et 20) : ";
        cin >> pompe;
    }
    cout << pompe << " Pompes a faire" << endl;
    return 0;
}