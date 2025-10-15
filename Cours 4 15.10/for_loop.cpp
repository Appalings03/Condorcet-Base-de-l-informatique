#include <iostream>

using namespace std;

int main()
{
    // itérations avec les for loops
    /*
    d'abord mot réservé for
    puis entre parenthèses:
    - initialisation d'une variable de comptage (int i = 0)
    - condition d'arrêt (i < 10)
    - incrémentation de la variable de comptage (i++)
    /!\i++ est équivalent à i = i + 1 ou i += 1 peut aussi apparaitre i--, i = i - 1, i -= 1 ou ++i
    l'incrémenation peut aussi être différenet de 1 (i += 2, i = i + 2, i *= 2, i = i * 2, etc)
    puis entre accolades le code à répéter
    /!\ ne pas oublier les points-virgules entre chaque partie
    /!\ pas de point-virgule après la parenthèse de fin du for etc for(...); { ... } est une erreur
                                                                          /\
    */
    // exemple afficher les nombres de 0 à 9
    /*
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }
    */

    // exemple afficher les nombres paires de 0 à 100   
    // 1 sans condition
    for (int i = 0; i <= 100; i+= 2) {
        cout << i << " ";
    }
    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
    // 2 avec condition utilisant le modulo pour savoir si un nombre est pair(0) ou impair(1) reste de la division par 2 
    for (int i = 0; i <= 100; i++) {
        if (i % 2 == 0)  // % est l'opérateur modulo (reste de la division entière)
            cout << i << " ";
    }
    // exemple afficher les nombres impaires de 100 à 0
    // 1 avec condition
    cout << endl;
    cout << "----------------" << endl;
    cout << endl;
    for (int i = 100; i >= 0; i--) {
        if (i % 2 != 0)  // != signifie différent de
            cout << i << " ";
    }
    return 0;
}