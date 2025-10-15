#include <iostream>

using namespace std;

int main()
{
    /*
        Programme qui demande a l'utilisateur combien de valeurs il veut saisir
        puis qui lui demande de saisir ces valeurs et qui affiche la valeur maximale
        parmi celles saisies
    */
    int size(0);
    int value(0), maxim, minim;
    // boucle do-while pour s'assurer que l'utilisateur entre un nombre positif
    do 
    {
        cout << "Entrez un nombre positif pour indiquer le nombre de valeur a saisir : ";
        cin >> size;
    }
    while (size < 0);
    
    // affiche le nombre de valeur que l'utilisateur va devoir saisir
    cout << size << " valeurs a saisir" << endl;

    for (int i(0); i < size; i++)
    {
        cout << "Entrez une valeur : ";
        cin >> value;
        if (i == 0) // pour la premiere valeur saisie
        {
            maxim = minim = value; // initialise le maxet le min a cette premiere valeur
        }

        if (maxim < value) // si la valeur introduite est plus grande que le maximum actuel
        {
            maxim = value; // on met a jour le maximum
        }

        if (minim > value) // si la valeur introduite est plus petite que le minimun actuel
        {
            minim = value; // on met a jour le minimum
        }
        
    }
    cout << "Max = " << maxim << endl;
    cout << "Min = " << minim << endl;
    return 0;
}